#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    fastio
    int n, res = 0;
    string s;
    cin >> n >> s;
    for(int i=0,carry=1;i<n&&carry;i++) {
        res++;
        carry = (carry+s[i]-'0')/2;
    }
    cout << res;
}
