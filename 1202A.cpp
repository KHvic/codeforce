#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// observation, we want to create as many prefix 0
// find first 1 of each reversed string to minimize prefix

int main(){
    fastio
    int t;
    cin >> t;
    string a, b;
    while(t--) {
        cin >> a >> b;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int pos = b.find('1');
        if(pos==b.npos) {
            cout << "0\n"; continue;
        }
        int pos2 = a.find('1', pos);
        cout << (pos2-pos) << "\n";
    }
}
