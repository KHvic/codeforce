#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    // idea: in an odd sized chess game, second player can definitely win by playing symmetrical move
    // in even sized game, first player can reduce the game such that he is the second player in an odd sized game
    if(n%2 == 0) {
        cout << "white\n1 2";
    } else cout << "black";
}
