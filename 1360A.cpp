#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n,a,b;
    scanf("%d",&n);
    while(n--) {
        scanf("%d %d",&a,&b);
        int res = max(min(a,b) *2, max(a,b));
        printf("%d\n",res*res);
    }
}
