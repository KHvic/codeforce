#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t;
    string s;
    cin >> t;
    while(t--) {
        cin >> s;
        int n = s.size();
        vector<bool> valid(26);
        for(int i=0,cur=0;i<n;i++) {
            cur++;
            if(i==n-1 || s[i] != s[i+1]) {
                if(cur&1) valid[s[i]-'a'] = true;
                cur = 0;
            }
        }
        for(int i=0;i<26;i++)
            if(valid[i])
                cout << (char)(i+'a');
        cout << "\n";
    }
}
