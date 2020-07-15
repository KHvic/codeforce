#include <bits/stdc++.h>
using namespace std;

vector<int> colors;
map<int, unordered_set<int>> neighbors;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    if(a.size() != b.size()) {
        cout << "NO";
        return 0;
    }
    int cntone = count(a.begin(), a.end(), '1');
    int cntone2 = count(b.begin(), b.end(), '1');
    if(cntone == 0 && cntone2 == 0) cout << "YES";
    else if(cntone == 0 || cntone2 == 0) cout << "NO";
    else cout << "YES";
}
