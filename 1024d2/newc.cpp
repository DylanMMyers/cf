#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(n, -1));
        int c = 0;

        if (n % 2 == 1) {
            // Odd n: start at the true center
            int mid = n / 2;
            v[mid][mid] = c++;

            // Build outward rings
            for (int layer = 1; layer <= mid; ++layer) {
                int top    = mid - layer;
                int bottom = mid + layer;
                int left   = mid - layer;
                int right  = mid + layer;

                // Top edge: left→right
                for (int j = left; j <= right; ++j) 
                    v[top][j] = c++;

                // Right edge: top+1→bottom
                for (int i = top + 1; i <= bottom; ++i) 
                    v[i][right] = c++;

                // Bottom edge: right-1→left
                for (int j = right - 1; j >= left; --j) 
                    v[bottom][j] = c++;

                // Left edge: bottom-1→top+1
                for (int i = bottom - 1; i > top; --i) 
                    v[i][left] = c++;
            }
        } else {
            // Even n: initialize the central 2×2 in spiral order
            int half = n / 2;
            v[half - 1][half - 1] = c++;
            v[half - 1][half]     = c++;
            v[half][half]         = c++;
            v[half][half - 1]     = c++;

            // Expand rings around that 2×2
            for (int layer = 2; layer <= half; ++layer) {
                int top    = half - 1 - layer;
                int bottom = half - 1 + layer;
                int left   = half - 1 - layer;
                int right  = half - 1 + layer;

                // Top edge
                for (int j = left; j <= right; ++j) 
                    v[top][j] = c++;

                // Right edge
                for (int i = top + 1; i <= bottom; ++i) 
                    v[i][right] = c++;

                // Bottom edge
                for (int j = right - 1; j >= left; --j) 
                    v[bottom][j] = c++;

                // Left edge
                for (int i = bottom - 1; i > top; --i) 
                    v[i][left] = c++;
            }
        }

        // Output the completed grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << v[i][j] << (j + 1 == n ? '\n' : ' ');
            }
        }
    }
    return 0;
}
