#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string in;
    cin >> in;
    ll cntOdd[2];
    ll cntEven[2];
    ll ansEven = 0, ansOdd = 0;
    memset(cntEven, 0, sizeof cntEven);
    memset(cntOdd, 0, sizeof cntOdd);
    for(int i=0;i<in.size();i++) {
        int idx = in[i] - 'a';
        if(i%2) {
            // odd to odd is odd len
            ansOdd += cntOdd[idx];
            // odd to even is even len
            ansEven += cntEven[idx];
            cntOdd[idx]++;
        } else {
            // even to even is odd len
            ansOdd += cntEven[idx];
            // even to odd is even len
            ansEven += cntOdd[idx];
            cntEven[idx]++;
        }
    }
    ansOdd += in.size(); // single char palin
    cout << ansEven << " " << ansOdd;
}
