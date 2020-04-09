#include <bits/stdc++.h>
 
using namespace std;
unordered_map<int,list<int>::iterator> keyToIt;
list<int> keyList;
int cap;
 
// make recent
void update(int key){
    if(keyToIt.count(key)){
        auto it = keyToIt[key];
        keyList.erase(it);
    }
    keyList.push_front(key);
    keyToIt[key] = keyList.begin();
}
 
void evict(){
    int head = keyList.back();keyList.pop_back();
    keyToIt.erase(head);
}
 
 
void put(int key) {
    if(keyToIt.count(key)) return;
    update(key);
    if(keyList.size() > cap)
        evict();
}
 
int main() {
    int n,k,v;
    scanf("%d %d",&n,&k);
    cap = k;
    for(int i=0;i<n;i++) {
        scanf("%d",&v);
        put(v);
    }
    printf("%d\n", keyList.size());
    for(auto& key : keyList) {
        printf("%d",key);
        if(&key == &keyList.back()) printf("\n");
        else printf(" ");
    }
}