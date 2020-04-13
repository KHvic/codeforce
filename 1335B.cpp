#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc,n,a,b;
    scanf("%d",&tc);

    while(tc--) {
        scanf("%d %d %d",&n,&a,&b);
        string res = "";
        for(int i=0;i<a;i++) {
            char j = ('a' + i%b);
            res += j;
        }
        while(res.size() < n) {
            res += res[res.size()-a];
        }
        cout << res << endl;
    }
}
