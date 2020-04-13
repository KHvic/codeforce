#include <bits/stdc++.h>
using namespace std;

struct node {
    int x, y;
    node(int x, int y):x(x),y(y){}
};

void dfs(node* n, map<int, vector<node*>>& xCoord, map<int, vector<node*>>& yCoord, set<node*>& visited) {
    if(visited.count(n)) return;
    visited.insert(n);
    vector<node*> neighX = xCoord[n->x];
    vector<node*> neighY = yCoord[n->y];
    xCoord.erase(n->x); yCoord.erase(n->y);
    for(auto neigh : neighX) dfs(neigh, xCoord, yCoord, visited);
    for(auto neigh : neighY) dfs(neigh, xCoord, yCoord, visited);
}

int main() {
    int n,x,y;
    scanf("%d",&n);
    map<int, vector<node*>> xCoord;
    map<int, vector<node*>> yCoord;
    set<node*> visited;
    vector<node*> nodes;
    while(n--) {
        scanf("%d %d", &x, &y);
        nodes.push_back(new node(x,y));
        xCoord[x].push_back(nodes.back());
        yCoord[y].push_back(nodes.back());
    }
    int res = 0;
    for(auto& node : nodes) {
        if(!visited.count(node)) {
            res++;
            dfs(node, xCoord, yCoord, visited);
        }
    }
    printf("%d\n", res-1);
}
