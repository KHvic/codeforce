#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);


int main()
{
    fastio
    int n;
    cin >> n;
    vector<int> vals(n);
    for(int i=0;i<n;i++) cin >> vals[i];
    sort(vals.begin(), vals.end());
    for(int i=0;i<n;i++) cout << vals[i] << " \n"[i==n-1];
}
