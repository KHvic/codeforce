#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    fastio
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2;
    int dx = x1-x2, dy = y1-y2;

    if(dx==0) {
        x3 = x1+dy, y3 = y1;
        x4 = x3, y4 = y2;
    } else if(dy==0) {
        x3 = x1, y3 = y1+dx;
        x4 = x2, y4 = y3;
    } else if(abs(dx) == abs(dy)) {
        y3 = y1, y4 = y2;
        x3 = x2, x4 = x1;
    } else {
        cout << -1; return 0;
    }
    cout << x3 << " " << y3 << " " << x4 << " " << y4;
}
