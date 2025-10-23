#!/usr/bin/env python3
import requests
import pandas as pd
import argparse
import sys
from datetime import datetime
from typing import Optional

class CodeforcesInteractiveAnalyzer:
    BASE_URL = "https://codeforces.com/api"
    
    def __init__(self, contest_id: int):
        self.contest_id = contest_id
        self.submissions_df = None
        self.standings_df = None
        self.problems_df = None
        self.hacks_df = None
        self.rating_changes_df = None
        
    def fetch_all_data(self):
        """Fetch all available contest data into DataFrames"""
        print(f"Fetching data for contest {self.contest_id}...")
        
        # Fetch submissions
        print("  → Fetching submissions...")
        self.submissions_df = self._fetch_submissions()
        if self.submissions_df is not None:
            print(f"    ✓ Loaded {len(self.submissions_df)} submissions")
        
        # Fetch standings
        print("  → Fetching standings...")
        self.standings_df = self._fetch_standings()
        if self.standings_df is not None:
            print(f"    ✓ Loaded {len(self.standings_df)} participants")
        
        # Fetch problems
        print("  → Fetching problems...")
        self.problems_df = self._fetch_problems()
        if self.problems_df is not None:
            print(f"    ✓ Loaded {len(self.problems_df)} problems")
        
        # Fetch hacks
        print("  → Fetching hacks...")
        self.hacks_df = self._fetch_hacks()
        if self.hacks_df is not None:
            print(f"    ✓ Loaded {len(self.hacks_df)} hacks")
        
        # Fetch rating changes
        print("  → Fetching rating changes...")
        self.rating_changes_df = self._fetch_rating_changes()
        if self.rating_changes_df is not None:
            print(f"    ✓ Loaded {len(self.rating_changes_df)} rating changes")
        
        print("\n✓ All data loaded successfully!\n")
    
    def _fetch_submissions(self) -> Optional[pd.DataFrame]:
        """Fetch submissions and return as DataFrame"""
        try:
            url = f"{self.BASE_URL}/contest.status"
            params = {"contestId": self.contest_id, "from": 1, "count": 10000}
            response = requests.get(url, params=params)
            data = response.json()
            
            if data["status"] != "OK":
                print(f"    ✗ Error: {data.get('comment', 'Unknown error')}")
                return None
            
            submissions = data["result"]
            
            # Flatten nested structures
            df_data = []
            for s in submissions:
                row = {
                    'id': s['id'],
                    'problem_index': s['problem']['index'],
                    'problem_name': s['problem']['name'],
                    'problem_rating': s['problem'].get('rating', None),
                    'author': s['author']['members'][0]['handle'],
                    'verdict': s.get('verdict', 'TESTING'),
                    'time_ms': s.get('timeConsumedMillis', 0),
                    'memory_bytes': s.get('memoryConsumedBytes', 0),
                    'language': s['programmingLanguage'],
                    'creation_time': datetime.fromtimestamp(s['creationTimeSeconds']),
                    'relative_time_seconds': s['relativeTimeSeconds'],
                    'relative_time_minutes': s['relativeTimeSeconds'] / 60,
                }
                df_data.append(row)
            
            return pd.DataFrame(df_data)
        except Exception as e:
            print(f"    ✗ Error fetching submissions: {e}")
            return None
    
    def _fetch_standings(self) -> Optional[pd.DataFrame]:
        """Fetch standings and return as DataFrame"""
        try:
            url = f"{self.BASE_URL}/contest.standings"
            params = {"contestId": self.contest_id, "from": 1, "count": 10000}
            response = requests.get(url, params=params)
            data = response.json()
            
            if data["status"] != "OK":
                return None
            
            rows = data["result"]["rows"]
            
            df_data = []
            for row in rows:
                party = row['party']
                handle = party['members'][0]['handle']
                
                record = {
                    'rank': row['rank'],
                    'handle': handle,
                    'points': row['points'],
                    'penalty': row['penalty'],
                    'successful_hacks': row['successfulHackCount'],
                    'unsuccessful_hacks': row['unsuccessfulHackCount'],
                }
                
                # Add problem results
                for i, problem_result in enumerate(row['problemResults']):
                    record[f'problem_{chr(65+i)}_points'] = problem_result['points']
                    record[f'problem_{chr(65+i)}_penalty'] = problem_result.get('rejectedAttemptCount', 0)
                    record[f'problem_{chr(65+i)}_time'] = problem_result.get('bestSubmissionTimeSeconds', None)
                
                df_data.append(record)
            
            return pd.DataFrame(df_data)
        except Exception as e:
            print(f"    ✗ Error fetching standings: {e}")
            return None
    
    def _fetch_problems(self) -> Optional[pd.DataFrame]:
        """Fetch problems and return as DataFrame"""
        try:
            url = f"{self.BASE_URL}/contest.standings"
            params = {"contestId": self.contest_id, "from": 1, "count": 1}
            response = requests.get(url, params=params)
            data = response.json()
            
            if data["status"] != "OK":
                return None
            
            problems = data["result"]["problems"]
            
            df_data = []
            for p in problems:
                df_data.append({
                    'index': p['index'],
                    'name': p['name'],
                    'type': p['type'],
                    'points': p.get('points', None),
                    'rating': p.get('rating', None),
                    'tags': ', '.join(p.get('tags', [])),
                })
            
            return pd.DataFrame(df_data)
        except Exception as e:
            print(f"    ✗ Error fetching problems: {e}")
            return None
    
    def _fetch_hacks(self) -> Optional[pd.DataFrame]:
        """Fetch hacks and return as DataFrame"""
        try:
            url = f"{self.BASE_URL}/contest.hacks"
            params = {"contestId": self.contest_id}
            response = requests.get(url, params=params)
            data = response.json()
            
            if data["status"] != "OK":
                return None
            
            hacks = data["result"]
            
            df_data = []
            for h in hacks:
                df_data.append({
                    'id': h['id'],
                    'creation_time': datetime.fromtimestamp(h['creationTimeSeconds']),
                    'hacker': h['hacker']['members'][0]['handle'],
                    'defender': h['defender']['members'][0]['handle'],
                    'verdict': h['verdict'],
                    'problem_index': h['problem']['index'],
                    'problem_name': h['problem']['name'],
                    'test': h.get('test', None),
                })
            
            return pd.DataFrame(df_data)
        except Exception as e:
            # Hacks might not be available for all contests
            return None
    
    def _fetch_rating_changes(self) -> Optional[pd.DataFrame]:
        """Fetch rating changes and return as DataFrame"""
        try:
            url = f"{self.BASE_URL}/contest.ratingChanges"
            params = {"contestId": self.contest_id}
            response = requests.get(url, params=params)
            data = response.json()
            
            if data["status"] != "OK":
                return None
            
            changes = data["result"]
            
            df_data = []
            for c in changes:
                df_data.append({
                    'handle': c['handle'],
                    'rank': c['rank'],
                    'old_rating': c['oldRating'],
                    'new_rating': c['newRating'],
                    'rating_change': c['newRating'] - c['oldRating'],
                })
            
            return pd.DataFrame(df_data)
        except Exception as e:
            # Rating changes might not be available yet
            return None
    
    def run_interactive(self):
        """Run interactive REPL for querying data"""
        print("="*70)
        print("CODEFORCES CONTEST ANALYZER - INTERACTIVE MODE")
        print("="*70)
        print("\nAvailable DataFrames:")
        print("  • submissions_df  - All submissions")
        print("  • standings_df    - Contest standings")
        print("  • problems_df     - Problem information")
        print("  • hacks_df        - Hack attempts")
        print("  • rating_df       - Rating changes")
        print("\nCommands:")
        print("  • help              - Show this help message")
        print("  • info <df>         - Show DataFrame info")
        print("  • head <df> [n]     - Show first n rows (default: 5)")
        print("  • tail <df> [n]     - Show last n rows (default: 5)")
        print("  • describe <df>     - Show statistics")
        print("  • columns <df>      - List all columns")
        print("  • query <code>      - Execute pandas query")
        print("  • save <df> <file>  - Save DataFrame to CSV")
        print("  • exit/quit         - Exit interactive mode")
        print("\nExamples:")
        print("  query submissions_df[submissions_df['verdict'] == 'OK'].head()")
        print("  query submissions_df.groupby('problem_index')['verdict'].value_counts()")
        print("  query standings_df.sort_values('points', ascending=False).head(10)")
        print("="*70)
        print()
        
        # Create namespace with DataFrames
        namespace = {
            'submissions_df': self.submissions_df,
            'standings_df': self.standings_df,
            'problems_df': self.problems_df,
            'hacks_df': self.hacks_df,
            'rating_df': self.rating_changes_df,
            'pd': pd,
        }
        
        while True:
            try:
                command = input(">>> ").strip()
                
                if not command:
                    continue
                
                if command.lower() in ['exit', 'quit', 'q']:
                    print("Goodbye!")
                    break
                
                elif command.lower() == 'help':
                    self._show_help()
                
                elif command.startswith('info '):
                    df_name = command.split()[1]
                    self._show_info(namespace, df_name)
                
                elif command.startswith('head '):
                    parts = command.split()
                    df_name = parts[1]
                    n = int(parts[2]) if len(parts) > 2 else 5
                    self._show_head(namespace, df_name, n)
                
                elif command.startswith('tail '):
                    parts = command.split()
                    df_name = parts[1]
                    n = int(parts[2]) if len(parts) > 2 else 5
                    self._show_tail(namespace, df_name, n)
                
                elif command.startswith('describe '):
                    df_name = command.split()[1]
                    self._show_describe(namespace, df_name)
                
                elif command.startswith('columns '):
                    df_name = command.split()[1]
                    self._show_columns(namespace, df_name)
                
                elif command.startswith('query '):
                    query_code = command[6:]
                    self._execute_query(namespace, query_code)
                
                elif command.startswith('save '):
                    parts = command.split()
                    if len(parts) < 3:
                        print("Usage: save <dataframe> <filename.csv>")
                        continue
                    df_name, filename = parts[1], parts[2]
                    self._save_df(namespace, df_name, filename)
                
                else:
                    # Try to execute as pandas query
                    self._execute_query(namespace, command)
            
            except KeyboardInterrupt:
                print("\nUse 'exit' or 'quit' to leave.")
            except Exception as e:
                print(f"Error: {e}")
    
    def _show_help(self):
        """Show help message"""
        print("\n" + "="*70)
        print("QUICK REFERENCE")
        print("="*70)
        print("\nPre-defined queries:")
        print("  • Accepted submissions only:")
        print("    query submissions_df[submissions_df['verdict'] == 'OK']")
        print("\n  • Fastest solve times by problem:")
        print("    query submissions_df[submissions_df['verdict'] == 'OK'].groupby('problem_index')['relative_time_minutes'].min()")
        print("\n  • Top 10 by points:")
        print("    query standings_df.sort_values('points', ascending=False).head(10)")
        print("\n  • Submissions by language:")
        print("    query submissions_df['language'].value_counts()")
        print("\n  • Average runtime by problem:")
        print("    query submissions_df[submissions_df['verdict'] == 'OK'].groupby('problem_index')['time_ms'].mean()")
        print("="*70 + "\n")
    
    def _show_info(self, namespace, df_name):
        """Show DataFrame info"""
        df = namespace.get(df_name)
        if df is None:
            print(f"DataFrame '{df_name}' not available or not loaded.")
            return
        print(f"\n{df_name} info:")
        print(df.info())
        print()
    
    def _show_head(self, namespace, df_name, n):
        """Show first n rows"""
        df = namespace.get(df_name)
        if df is None:
            print(f"DataFrame '{df_name}' not available or not loaded.")
            return
        print(f"\n{df_name}.head({n}):")
        print(df.head(n))
        print()
    
    def _show_tail(self, namespace, df_name, n):
        """Show last n rows"""
        df = namespace.get(df_name)
        if df is None:
            print(f"DataFrame '{df_name}' not available or not loaded.")
            return
        print(f"\n{df_name}.tail({n}):")
        print(df.tail(n))
        print()
    
    def _show_describe(self, namespace, df_name):
        """Show DataFrame statistics"""
        df = namespace.get(df_name)
        if df is None:
            print(f"DataFrame '{df_name}' not available or not loaded.")
            return
        print(f"\n{df_name}.describe():")
        print(df.describe())
        print()
    
    def _show_columns(self, namespace, df_name):
        """Show DataFrame columns"""
        df = namespace.get(df_name)
        if df is None:
            print(f"DataFrame '{df_name}' not available or not loaded.")
            return
        print(f"\n{df_name} columns:")
        for col in df.columns:
            print(f"  • {col}")
        print()
    
    def _execute_query(self, namespace, query_code):
        """Execute pandas query"""
        try:
            result = eval(query_code, namespace)
            print()
            if isinstance(result, pd.DataFrame) or isinstance(result, pd.Series):
                print(result)
            else:
                print(f"Result: {result}")
            print()
        except Exception as e:
            print(f"Query error: {e}")
    
    def _save_df(self, namespace, df_name, filename):
        """Save DataFrame to CSV"""
        df = namespace.get(df_name)
        if df is None:
            print(f"DataFrame '{df_name}' not available or not loaded.")
            return
        try:
            df.to_csv(filename, index=False)
            print(f"✓ Saved {df_name} to {filename}")
        except Exception as e:
            print(f"Error saving: {e}")

def main():
    parser = argparse.ArgumentParser(
        description="Codeforces Contest Analyzer - Interactive Data Explorer"
    )
    parser.add_argument("contest_id", type=int, help="Contest ID to analyze")
    parser.add_argument(
        "--no-interactive", 
        action="store_true",
        help="Fetch data only without interactive mode"
    )
    
    args = parser.parse_args()
    
    analyzer = CodeforcesInteractiveAnalyzer(args.contest_id)
    analyzer.fetch_all_data()
    
    if not args.no_interactive:
        analyzer.run_interactive()

if __name__ == "__main__":
    main()
