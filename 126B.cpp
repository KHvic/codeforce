#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string in;
    cin >> in;
    int n = in.size();
    // compute KMP bactabke
    vector<int> backtable(n+1);
    backtable[0] = -1;
    int i=0, j=-1;
    while(i<n) {
        while(j>=0 && in[i] != in[j]) j = backtable[j];
        backtable[++i] = ++j;
    }
    // no prefix suffix
    int last = j;
    if(last <= 0) {
        cout << "Just a legend";
        return 0;
    }
    // check for middle
    for(int i=0;i<n;i++)
        if(backtable[i] == j) {
            cout << in.substr(0, j);
            return 0;
        }
    // 2nd best candidate is P[P[idx]], is a prefix, a suffix, and also 'middle'
    int last2 = backtable[last];
    if(last2 <= 0) {
        cout << "Just a legend";
    } else {
        cout << in.substr(0, last2);
    }
}
