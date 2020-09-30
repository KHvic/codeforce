#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

void print(int x, char c) {
    for(int i=0;i<x;i++) cout << c;
}

void draw(int n, int k) {
    int side = (n-k)/2;
    print(side, '*');
    print(k, 'D');
    print(side, '*');
    cout << "\n";
}

int main()
{
    fastio
    int n;
    cin >> n;
    for(int i=1;i<=n;i+=2) draw(n, i);
    for(int i=n-2;i>=1;i-=2) draw(n, i);
}
