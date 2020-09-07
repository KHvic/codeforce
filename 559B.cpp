#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

string smallest(string a) {
    int n = a.size();
    if(n%2) return a;
    string a1 = smallest(a.substr(0, n/2));
    string a2 = smallest(a.substr(n/2));
    if(a1 <= a2) return a1 + a2;
    return a2 + a1;
}

int main(){
    fastio
    string a, b;
    cin >> a >> b;
    cout << (smallest(a) == smallest(b) ? "YES" : "NO");
}
