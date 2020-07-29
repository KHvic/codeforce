#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int mod = 1e9+7;
 
int longest(string& s, char a, char b) {
    bool isa = 1;
    int res = 0;
    for(char c : s) {
        if(isa && c == a) {
            isa = !isa;
        } else if(!isa && c == b) {
            isa = !isa;
            res+=2;
        }
    }
    return res;
}
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    string s;
    cin >> t;
    while(t--) {
        cin >> s;
        vector<int> cnt(10,0);
        for(char c : s) {
            cnt[c-'0']++;
        }
        int res = s.size();
        for(int i=0;i<10;i++) res = min(res, (int)s.size() - cnt[i]);
        for(char a='0';a<='9';a++) {
            for(char b='0';b<='9';b++) {
                if(a==b) continue;
                int cost = s.size() - longest(s, a, b);
                res = min(res, cost);
            }
        }
        cout << res << "\n";
    }
}
