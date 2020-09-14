#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    fastio
    int k;
    cin >> k;
    k*=2;
    int cnt[10];
    memset(cnt, 0, sizeof cnt);
    for(int i=0;i<4;i++) {
        string s;
        cin >> s;
        for(char c : s)
            if(c != '.') cnt[c-'0']++;
    }
    bool cant = count_if(cnt, cnt+10, [&](int x){return x>k;});
    cout << (cant ? "NO" : "YES");
}
