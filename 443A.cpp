#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    fastio
    string s;
    getline(cin, s);
    unordered_set<char> ss;
    for(char c : s)
        if(isalpha(c))
            ss.insert(c);
    cout << ss.size();
}
