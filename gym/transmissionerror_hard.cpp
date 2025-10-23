#include <iostream>
#include <vector>

int main() {
    int iters;
    std::cin >> iters;
    
    int curriter;
    std::vector<int> curr;
    int ans;

    for (int i = 0; i < iters; i++) {
        std::cin >> curriter;
        ans = 0;
        for (int j = 0; j < curriter; j++) {
            std::cin >> curr[j];
        }
        for (int j = 0; j < curriter; j++) {
            if (j % 2 == 0) ans += curr[j];
            else ans -= curr[j];
        }
        std::cout << ans << "\n";
    }

    return 0;
}