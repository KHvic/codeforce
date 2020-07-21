#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    string prev, cur;
    cin >> n;
    int res = 0;
    while(n--) {
        cin >> cur;
        if(prev.empty() || prev.back() == cur[0]) res++;
        prev = cur;
    }
    cout << res;
}
