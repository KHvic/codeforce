#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t,x,y,n;
    cin >> t;
    while(t--) {
        cin >> x >> y >> n;
        int res = 0;
        // a times of x
        // a*x + y <= n
        // a*x <= n-y
        int a = (n-y)/x;
        cout << a*x+y << endl;
    }
}
