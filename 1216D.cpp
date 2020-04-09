#include <bits/stdc++.h>
 
using namespace std;
 
int gcd(int a, int b){
    return a==0 ? b : gcd(b%a,a);
}
 
int main() {
    int n,v;
    cin >> n;
    vector<int> a;
    int m = 0;
    for(int i=0;i<n;i++){
        cin >> v;
        a.push_back(v);
        m = max(m,v);
    }
    int cd = 0;
    for(auto& e : a){
        cd = gcd(cd, m-e);
    }
    long long y = 0;
    for(auto& e : a){
        y += ((m-e)/cd);
    }
    cout << y << " "<< cd << endl;
}
