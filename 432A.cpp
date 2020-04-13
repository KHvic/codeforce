#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k,v;
    scanf("%d %d", &n, &k);
    int cnt = 0;
    while(n--) {
        scanf("%d", &v);
        int left = 5 - v;
        if(left >= k) cnt++;
    }
    printf("%d\n", cnt/3);
}
