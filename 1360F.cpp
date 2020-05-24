#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<string> strs;

vector<int> posDiff(string& a, string& b) {
    vector<int> res;
    for(int i=0;i<a.size();i++)
        if(a[i] != b[i])
            res.push_back(i);
    return res;
}

int main() {
    int t,n,k;
    scanf("%d",&t);
    string in;
    while(t--) {
        scanf("%d %d",&n,&k);
        strs.clear();
        for(int i=0;i<n;i++){
            cin >> in;
            strs.push_back(in);
        }
        bool valid = false;
        for(int i=0;i<k &&!valid;i++) {
            string str = strs[0];
            for(char c='a';c<='z' &&!valid;c++){
                str[i] = c;
                valid = true;
                for(string& s : strs) if(posDiff(s, str).size() > 1) {
                    valid = false;
                    break;
                }
                if(valid) in = str;
            }
        }
        if(!valid) cout << "-1" << endl;
        else cout << in << endl;
    }
}
