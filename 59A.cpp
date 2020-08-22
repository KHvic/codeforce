#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int main(){
    fastio
    string s;
    cin >> s;
    int cntlower = count_if(s.begin(), s.end(), [](char c) {return islower(c);});
    int cntupper = s.size() - cntlower;
    transform(s.begin(), s.end(), s.begin(), cntupper > cntlower ? ::toupper : ::tolower);
    cout << s;
}
