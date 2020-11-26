#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int res1, res2;

    cout << "?";
    for(int i=1;i<=100;i++) cout << " " << i;
    cout << "\n";
    cout.flush();
    cin >> res1;

    cout << "?";
    for(int i=1;i<=100;i++) cout << " " << (i << 7);
    cout << "\n";
    cout.flush();
    cin >> res2;

    res1 &= ~((1<<7) - 1);
    res2 &= (1<<7) - 1;
    cout << "! " << (res1 | res2);
    cout.flush();
}
