#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    fastio
    int a,b,c;
    cin >> a >> b >> c;
    int res = a+b+c;
    res = max(res, (a + b) * c);
    res = max(res, a * (b + c));
    res = max(res, a * b * c);

    cout<<res<< endl;
}
