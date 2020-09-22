#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

bool check(vector<int>& moods, int len) {
    for(int i=0;i<len;i++) {
        bool ok = true;
        for(int j=0;j<moods.size()/len && ok;j++) {
            int idx = i+j*len;
            ok &= moods[idx];
        }
        if(ok) return true;
    }
    return false;
}

int main()
{
    fastio
    int n;
    cin >> n;
    vector<int> moods(n);
    for(int i=0;i<n;i++) cin >> moods[i];
    for(int i=1;i<(n+1)/2;i++) {
        if(n%i==0 && check(moods, i)) {
            cout << "YES"; return 0;
        }
    }
    cout << "NO";
}
