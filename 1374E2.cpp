#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    ll t,n,m,k,a,b,c;
    cin >> n >> m >> k;
    vector<vector<ll>> both, as, bs,cs;
    for(int i=0;i<n;i++) {
        cin >> a >> b >> c;
        if(b&c) both.push_back({a,i+1});
        else if(b) bs.push_back({a,i+1});
        else if(c) as.push_back({a,i+1});
        else cs.push_back({a,i+1});
    }
    sort(both.begin(), both.end());
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    sort(cs.begin(), cs.end());
    if(both.size() + as.size() < k || both.size() + bs.size() < k) {
        cout << -1 << endl;
    } else {
        ll res = 0;
        int i = 0, j = 0;
        while(k>0) {
            if(i>=both.size()) {
                res += as[j][0] + bs[j][0];
                j++;
                m-=2;
            } else if(j>=bs.size() || j>=as.size()) {
                res += both[i++][0];
                m--;
            } else {
                ll add = bs[j][0] + as[j][0];
                if(add < both[i][0]) {
                    j++;
                    res += add;
                    m-=2;
                } else {
                    res += both[i++][0];
                    m--;
                }
            }
            k--;
        }
        // book swapping phrase
        // need to maintain k = 0 while getting m up
        while(m<0) {
            j--;
            if(i>=both.size() || j<0) break;
            res -= (as[j][0] + bs[j][0] - both[i++][0]);
            m++;
        }
        if(m<0) {cout << -1 << endl; return 0;};
        int p1=i, p2=j, p3=j, p4=0;
        while(m>0) {
            // choice 1 swap one of both with 2 of as + bs
            int choice1 = 1e11;
            if(p1>0 && p2<as.size() && p3<bs.size()) {
                choice1 = -both[p1-1][0] + as[p2][0] + bs[p3][0];
            }
            int choice2 = p1<both.size() ? both[p1][0] : 1e11;
            int choice3 = p2<as.size() ? as[p2][0] : 1e11;
            int choice4 = p3<bs.size() ? bs[p3][0] : 1e11;
            int choice5 = p4<cs.size() ? cs[p4][0] : 1e11;
            vector<int> chs = {choice1,choice2,choice3,choice4,choice5};
            int best = min_element(chs.begin(),chs.end()) - chs.begin();
            if(best == 0) {
                res += choice1;
                p2++; p3++;
                p1--;
            } else if(best==1) {
                res += choice2;
                p1++;
            } else if(best==2) {
                res += choice3;
                p2++;
            } else if(best==3) {
                res += choice4;
                p3++;
            } else if(best==4) {
                res += choice5;
                p4++;
            }
            m--;
            if(res>=1e11) break;
        }
        if(res>=1e11) {cout << -1 << endl; return 0;}
        cout << res << endl;
        bool first = true;
        for(int x=0;x<p1;x++) {
            if(!first) cout << " ";
            first = false;
            cout << both[x][1];
        }
 
        for(int x=0;x<p2;x++) {
            if(!first) cout << " ";
            first = false;
            cout << as[x][1];
        }
 
        for(int x=0;x<p3;x++) {
            if(!first) cout << " ";
            first = false;
            cout << bs[x][1];
        }
 
 
        for(int x=0;x<p4;x++) {
            if(!first) cout << " ";
            first = false;
            cout << cs[x][1];
        }
    }
}
