#include <bits/stdc++.h>
 
using namespace std;
 
pair<long long,vector<long long>> intersect(vector<long long> &a, vector<long long> &b){
    long long minTop = min(a[3],b[3]);
    long long minRight = min(a[2],b[2]);
    long long maxBtm = max(a[1],b[1]);
    long long maxLeft = max(a[0],b[0]);
    vector<long long> coord = {maxLeft, maxBtm, minRight, minTop};
    if(maxLeft >= minRight || minTop <= maxBtm) return make_pair(0,coord);
    long long height = minTop - maxBtm;
    long long width = minRight - maxLeft;
    return make_pair(height*width, coord);
}
 
int main() {
    vector<long long> a(4);
    vector<long long> b(4);
    vector<long long> c(4);
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    cin >> b[0] >> b[1] >> b[2] >> b[3];
    cin >> c[0] >> c[1] >> c[2] >> c[3];
    long long area = intersect(a,a).first;
    area -= (intersect(a,b).first+intersect(a,c).first);
    pair<long long,vector<long long>> intersectBlack = intersect(b,c);
    if(intersectBlack.first != 0) {
        area += intersect(a,intersectBlack.second).first;
    }
    if(area > 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}
