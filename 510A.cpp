#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);


int main()
{
    fastio
    int n, m;
    cin >> n >> m;
    for(int i=0,j=0;i<n;i++,j+=i%2) {
        if(i%2) {
            cout << (j%2 ? string(m-1, '.') : "#") << (j%2 ? "#" : string(m-1, '.')) << "\n";
        } else {
            cout << string(m, '#') << "\n";
        }
    }
}
