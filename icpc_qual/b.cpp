#include <bits/stdc++.h>
#define ll long long
// Get-Content t.txt | ./b.exe
// g++ b.cpp -o b
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r; int c;

    cin >> r >> c;

    vector<vector<int>> dists(r);
    vector<vector<int>> dists2(r);

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            dists[i].push_back(-1);
            dists2[i].push_back(-1);
        }
    }

    queue<vector<int>> q;

    int i;
    int j;
    int towers;

    cin >> towers;

    for(int k = 1; k <= towers; k++){
        cin >> i >> j;

        i--;
        j--;

        q.push({i, j, k});
    }
    vector<vector<int>> changes = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while(!q.empty()){

        int u = q.front()[0];
        int v = q.front()[1];
        int t = q.front()[2];
        q.pop();

        // if (dists[u][v] == -1) dists[u][v] = t;
        // else if (dists2[u][v] == -1) {
        //     if(dists[u][v] != t){
        //         dists2[u][v] = t;
        //     }
        // }
        
        if (dists[u][v] != -1 && dists2[u][v] != -1) continue;
        for(int change = 0; change < changes.size(); change++){
            int dx = changes[change][0];
            int dy = changes[change][1];
            int new_x = u + dx;
            int new_y = v + dy;

            if(new_x < 0 || new_x >= r || new_y < 0 || new_y >= c){
                continue;
            }
            if(dists[new_x][new_y] != -1 && dists2[new_x][new_y] != -1){
                continue;
            }
            if(dists[new_x][new_y] != t && dists2[new_x][new_y] == -1){
                if(dists[new_x][new_y] == -1){
                    dists[new_x][new_y] = t;
                }
                else if (dists2[new_x][new_y] == -1){
                    dists2[new_x][new_y] = t;
                }
                q.push({new_x, new_y, t});
            }
        }
    }

    for(int k = 0; k < r; k++){
        for(int m = 0; m < c; m++){
            cout << dists[k][m] << " ";
        }
        cout << endl;
    }
    for(int k = 0; k < r; k++){
        for(int m = 0; m < c; m++){
            cout << dists2[k][m] << " ";
        }
        cout << endl;
    }

}