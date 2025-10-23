#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool can(int k, int n, vector<pair<int,int>>& btn) {
    vector<int> L(k, 0), R(k, 0), w(k, 0);
    int used = 0;
    unordered_map<int, vector<int>> leftF, rightF;
    for (auto &bp : btn) {
        int wt = bp.first, p = bp.second;
        bool placed = false;
        auto itL = leftF.find(p);
        if (itL != leftF.end()) {
            auto &v = itL->second;
            for (int idx = 0; idx < (int)v.size(); ++idx) {
                int i = v[idx];
                if (w[i] >= wt) {
                    L[i] = p;
                    w[i] = wt;
                    leftF[p-1].push_back(i);
                    rightF[R[i]+1].push_back(i);
                    v.erase(v.begin()+idx);
                    placed = true;
                    break;
                }
            }
            if (v.empty()) leftF.erase(itL);
            if (placed) continue;
        }
        auto itR = rightF.find(p);
        if (itR != rightF.end()) {
            auto &v = itR->second;
            for (int idx = 0; idx < (int)v.size(); ++idx) {
                int i = v[idx];
                if (w[i] >= wt) {
                    R[i] = p;
                    w[i] = wt;
                    rightF[p+1].push_back(i);
                    leftF[L[i]-1].push_back(i);
                    v.erase(v.begin()+idx);
                    placed = true;
                    break;
                }
            }
            if (v.empty()) rightF.erase(itR);
            if (placed) continue;
        }
        if (used < k) {
            int i = used++;
            L[i] = R[i] = p;
            w[i] = wt;
            leftF[p-1].push_back(i);
            rightF[p+1].push_back(i);
            placed = true;
        }
        if (!placed) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; 
    cin >> tt;
    while(tt--){
        int n; 
        cin >> n;
        vector<pair<int,int>> btn(n);
        for(int i = 0; i < n; i++){
            cin >> btn[i].first;
            btn[i].second = i;
        }
        sort(btn.begin(), btn.end(),
             [&](auto &a, auto &b){
                 return a.first > b.first;
             });

        int lo = 1, hi = n, ans = n;
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if (can(mid, n, btn)) {
                ans = mid;
                hi = mid - 1;
            } 
            else lo = mid + 1;
        }
        cout << ans << "\n";
    }
}
