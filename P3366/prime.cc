#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> to, nxt, wgt, head; 
typedef struct eg {
    int u, v, w;
    bool operator> (eg &other) {
        return w > other.w;
    }
}eg;
priority_queue<eg, vector<eg>, eg> sorted_e;
set<eg> reserved;
void add(int u, int v, int w){
    nxt.push_back(head[u]);
    head[u] = to.size();
    to.push_back(v);
    wgt.push_back(w);
}

int get_w(int u, int v){
    for(int i = head[u]; ~i; i = nxt[i]){
        if(to[i] == v) return wgt[i];
    }
    return INT_MAX;
}

set<int> vis;
void dfs(int u = 1){
    vis.insert(u);
    cout<<u<<endl;
    for(int i = head[u]; ~i; i = nxt[i]){
        if(vis.find(to[i]) == vis.end()) dfs(to[i]);
    }
}

vector<int> father;

 
bool find_loop(eg e_to_add){

}

int main(void){
    cin>>n>>m;
    head.resize(n+1,-1);
    father.resize(m+1,-1);
    int x,y,z;
    for(int i=0; i<m; i++){
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
        sorted_e.push({x,y,z});
    }
    dfs();
    if(vis.size() != n) {
        cout<<"orz";
        return 0;
    }
    while(!sorted_e.empty()) {
        auto m = sorted_e.top();
        sorted_e.pop();
        if(find_loop(m)) continue;
        else{
            reserved.insert(m);
        }
    }
    int sum = 0;
    for(auto p : reserved){
        sum = sum + p.w;
    }
    cout << sum;
    return 0;
}