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
        int left1 = 0, left2 = 0, res = 0;
        for(char c : s) {
            if(c=='[') left1++;
            else if(c=='(') left2++;
            else if(c==']') {
                if(left1>0) {
                    left1--;
                    res++;
                }
            } else if(c==')') {
                if(left2>0) {
                    left2--;
                    res++;
                }
            }
        }
        cout << res << "\n";
    }
}
