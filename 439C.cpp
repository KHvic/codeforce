#include <bits/stdc++.h>
using namespace std;
#define ll long long

void print_queue(queue<vector<int>>& q) {
    while(!q.empty()) {
        auto top = q.front(); q.pop();
        cout << top.size();
        for(int x : top) {
            cout << " " << x;
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,k,p,v;
    queue<vector<int>> odd, even;
    cin >> n >> k >> p;
    for(int i=0;i<n;i++) {
        cin >> v;
        if(v%2) odd.push({v});
        else even.push({v});
    }
    bool valid = true;
    int odd_need = k-p;
    // convert odd to even until sufficient
    while(even.size()<p) {
        if(odd.size()<2) {
            valid = false;
            break;
        }
        vector<int> combine;
        combine.insert(combine.end(), odd.front().begin(), odd.front().end()); odd.pop();
        combine.insert(combine.end(), odd.front().begin(), odd.front().end()); odd.pop();
        even.push(combine);
    }
    // only can have surplus_odd of even count
    int surplus_odd = max((int)odd.size() - odd_need, 0);
    if(!valid || odd_need > odd.size() || surplus_odd % 2 == 1) {
        cout << "NO";
        return 0;
    }
    int surplus_even = even.size() - p;
    vector<int> addition;
    while(surplus_even--) {
        addition.insert(addition.end(), even.front().begin(), even.front().end());
        even.pop();
    }
    while(surplus_odd--) {
        addition.insert(addition.end(), odd.front().begin(), odd.front().end());
        odd.pop();
    }
    // insert all additional elements to any partition
    if(p) {
        even.front().insert(even.front().end(), addition.begin(), addition.end());
    } else {
        odd.front().insert(odd.front().end(), addition.begin(), addition.end());
    }
    cout << "YES" << "\n";
    print_queue(even); print_queue(odd);
}
