#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc,n,v;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &n);
        vector<int> init;
        for(int i=0;i<n;i++) {
            scanf("%d",&v);
            init.push_back(v);
        }
        bool hasMinusOne = false, hasPlusOne = false;
        bool valid = true;
        for(int i=0;i<n;i++) {
            scanf("%d",&v);
            int diff = v-init[i];
            if(diff > 0) valid &= hasPlusOne;
            else if(diff < 0) valid &= hasMinusOne;

            if(init[i] == 1) hasPlusOne = true;
            else if(init[i] == -1) hasMinusOne = true;
        }
        cout << (valid ? "YES" : "NO") << endl;
    }
}
