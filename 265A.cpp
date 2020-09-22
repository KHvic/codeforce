#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int n, k;

int main()
{
    fastio
    cin >> n >> k;
    string s;
    cin >> s;

    for(int i=n-1;i>=0;i--) {
        for(char c=s[i]+1;c<'a'+k;c++) {
            if(i-1>=0 && s[i-1] == c) continue;
            if(i-2>=0 && s[i-2] == c) continue;
            if((k==1 && n>1) || (k==2 && n>2)) {
                continue;
            }
            string res;
            for(int j=0;j<i;j++) {
                res += s[j];
            }
            res += c;
            for(int j=i+1;j<n;j++) {
                for(char c2='a';c2<'a'+k;c2++) {
                    if(j-1>=0 && res[j-1] == c2) continue;
                    if(j-2>=0 && res[j-2] == c2) continue;
                    res += c2;
                    break;
                }
            }
            cout << res;
            return 0;
        }
    }
    cout << "NO";
}
