#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int n,m;
    cin >> n >> m;

    int mn = (n+1)/2; // min number of steps to reach n
    int res = (mn + m - 1)/m * m; // smallest multiple of m >= mn
    cout << (res <= n ? res : -1); // doesn't exceed max steps
}
