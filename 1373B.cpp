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
        int cnt = 0;
        stack<char> st;
        for(char c : s) {
            if(!st.empty() && c != st.top()) {
                st.pop(); cnt++;
            } else st.push(c);
        }
        // alternatively min(cnt0, cnt1) is the same answer
        cout << (cnt&1 ? "DA" : "NET") << "\n";
    }
}
