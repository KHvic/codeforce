#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    fastio
    int n;
    cin >> n;
    int first = (n+1)/2;
    int second = n/2;
    cout << (first*first+second*second) << "\n";
    for(int i=1;i<=n;i++) {
        for(int j=0;j<n;j++) {
            cout << ((i^j)&1 ? 'C' : '.');
        }
        cout << "\n";
    }
}
