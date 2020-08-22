#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    string s;
    cin >> s;
    bool deleted = 0;
    for(int i=0;i<s.size();i++) {
        char c = s[i];
        if(!deleted && (i==s.size()-1 || c=='0')) {
            deleted = 1;
            continue;
        }
        cout << c;
    }
}
