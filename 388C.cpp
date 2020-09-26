#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// idea: game theory
// say there are only even cards
// if it is better for ciel to pick more than n/2 cards from this pile
// jiro can always stop ciel by picking card from the same pile (worse for ciel is better for jiro)
// vice-vera, if it is better for jiro to pick more cards from some pile, ciel can play the same strategy
// thus, it reaches a balance of n/2 cards for each pile in the optimal play (each player can't get more)

// for odd case, only take into consideration of middle card

int main()
{
    fastio
    int n, s, v;
    cin >> n;
    int ciel = 0, jiro = 0;
    vector<int> remains;
    for(int i=0;i<n;i++) {
        cin >> s;
        vector<int> vals(s);
        for(int j=0;j<s;j++) cin >> vals[j];
        if(s%2) remains.push_back(vals[s/2]);
        jiro += accumulate(vals.begin()+s/2+(s%2), vals.end(), 0);
        ciel += accumulate(vals.begin(), vals.begin()+s/2, 0);
    }
    sort(remains.rbegin(), remains.rend());
    for(int i=0;i<remains.size();i++)
        if(i%2 == 0) ciel += remains[i];
        else jiro += remains[i];
    cout << ciel << " " << jiro;
}
