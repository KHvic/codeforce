#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t;
    cin >> t;
    string s;
    while(t--) {
        cin >> s;
        string odd, even;
        for(char c : s) {
            int v = c-'a';
            if(v&1) odd += c;
            else even += c;
        }
        string res;
        int i = 0, j = 0;
        int n = odd.size(), m = even.size();
        while(i<n || j<m) {
            bool takeodd;
            if(i>=n) takeodd = false;
            else if(j>=m) takeodd = true;
            else takeodd = odd[i] < even[j];
            
            if(takeodd) res += odd[i++];
            else res += even[j++];
        }
        cout << res << "\n";
    }
}
