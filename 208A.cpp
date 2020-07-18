#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string in;
    cin >> in;
    vector<string> res;
    int prev = 0, cur;
    while(1) {
        cur = in.find("WUB", prev);
        if(cur != prev) {
            res.push_back(in.substr(prev, cur-prev));
            if(cur == in.npos) break;
        }
        prev = cur+3;
    }
    string print;
    for(auto& s : res) {
        if(print.size()) print += " ";
        print += s;
    }
    cout << print;
}
