#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);#include <bits/stdc++.h>

int main(){
    fastio
    int t,n;
    cin >> t;
    while(t--) {
        cin >> n;
        int digit = n%10;
        int len = to_string(n).size();
        int res = len*(len+1)/2 + 10*(digit-1);
        cout << res << "\n";
    }
}
