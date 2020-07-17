#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,k,v;
    cin >> n >> k;
    int sum = 0;
    int mn = INT_MAX, best = 0;
    queue<int> q;
    for(int i=0;i<n;i++) {
        cin >> v;
        q.push(v);
        sum += v;
        if(i>=k-1) {
            if(sum < mn) {
                mn = sum;
                best = i-(k-1);
            }
            sum -= q.front(); q.pop();
        }
    }
    cout << best+1;
}
