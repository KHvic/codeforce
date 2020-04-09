#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n,x,y,v;
    vector<int> days;
    scanf("%d %d %d",&n,&x,&y);
    for(int i=0;i<n;i++){
        scanf("%d",&v);
        days.push_back(v);
    }
    bool found = false;
    for(int i=0;i<n;i++){
        found = true;
        for(int j=i-x;j<=i+y && found;j++){
            if(j<0 || j >= n || j==i) continue;
            if(days[j] <= days[i]) found = false;
        }
        if(found){
            cout << i+1 << endl;
            break;
        }
    }
}
