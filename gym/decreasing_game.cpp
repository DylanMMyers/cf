#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\decreasing_game.exe

// what is the amount of ways to turn all the elements in to 0?
// normally, it will be one at a time unless the selected elements are the equal
// so from here, we need to determine if there is a way to force the parity of removed elements to be odd or even
// if we can force it to be odd, then choose first, otherwise second
// can one of these always be forced?

// i think yes, bias is always towards player 1 and in some cases player two can force some moves

// so we should choose player 1 if at every guess, we can choose some element such that when player 2 chooses any other element,
// they are not able to turn the element into another existing one
// or if we have to choose an element which would result in one that already exists, this must happen an even amount of times
// *depending parity of n as well

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        
    }
}

// 1 1 0 1 0 1 