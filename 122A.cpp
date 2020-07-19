#include<bits/stdc++.h>
using namespace std;

bool islucky(int x) {
    while(x) {
        int d = x%10;
        if(d!=4 && d!=7) return 0;
        x /= 10;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    bool found = 0;
    for(int i=1;i*i<=n && !found;i++) {
        if(n%i == 0) {
            int a = i, b = n/i;
            found = (islucky(a) || islucky(b));
        }
    }
    cout << (found ? "YES" : "NO") << "\n";
}
