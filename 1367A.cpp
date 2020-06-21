#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    while(n--) {
        cin >> s;
        string res (1,s[0]);
        for(int i=1;i<s.size()-1;i+=2) res += s[i];
        res += s.back();
        cout << res << endl;
    }
}
