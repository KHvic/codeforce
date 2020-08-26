#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int n;
    cin >> n;
    vector<int> vals(n), time_death(n);
    for(int i=0;i<n;i++) cin >> vals[i];

    time_death[0] = -1;
    stack<int> st; st.push(0);
    for(int i=1;i<n;i++) {
        time_death[i] = 0; // default to die immediately
        // while larger than previous p
        // i will die one turn after p's death
        // p will not be able to kill anyone
        while(!st.empty() && vals[i] > vals[st.top()]) {
            time_death[i] = max(time_death[i], time_death[st.top()] + 1);
            st.pop();
        }
        if(st.empty()) time_death[i] = -1; // won't ever die, largest prefix
        st.push(i);
    }
    cout << *max_element(time_death.begin(), time_death.end()) + 1;
}
