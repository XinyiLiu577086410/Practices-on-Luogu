#define DBG
#undef DBG
#include <bits/stdc++.h>
using namespace std;
vector<int> to, wgt, nxt;
vector<int> head;
int cnt = 0;
int int_max = INT_MAX;

inline int & find_edge(int u, int v){
    for(int i = head[u]; ~i; i = nxt[i]){
        if(to[i] == v) return wgt[i];
    }
    return ::int_max;
}

void inline add_rpls(int u, int v, int w) {
    nxt.push_back(head[u]);
    head[u] = to.size();    
    to.push_back(v);        
    wgt.push_back(w);       
}

int n, m, s;
int u, v, w;
vector<int> dis;
int main(void){
    scanf("%d%d%d",&n,&m,&s);
    head.resize(n+10,-1);
    dis.resize(n+10,::int_max);
    dis[--s] = 0; 
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d",&u,&v,&w);
        add_rpls(u-1,v-1,w);
    }
    auto cmp = [&](int a,int b)->bool {return dis[a] > dis[b];};
    std::priority_queue<int,vector<int>, decltype(cmp)> s1(cmp);
    s1.emplace(s);
    int min;
    bool unused[int(1e5)+10]={false,};
    unused[s]=true;
    while(!s1.empty()) {
        while (!s1.empty()) {
            min = s1.top();
            s1.pop();
            if(unused[min]) {
                unused[min] = false;
                break;
            }
            else continue;
        }
        for(int i = head[min]; ~i; i=nxt[i]) {
            int v = to[i];
            int dis_new = dis[min] + wgt[i];
            if((dis_new >= 0) && dis[v] > dis_new) { 
                dis[v] = dis_new;
                s1.push(v);
                unused[v] = true;
            }
            else /*do nothing*/;
        }
    }
    for(int i = 0; i < n; i++) {
        printf("%d",dis[i]);
        if(i<n-1) printf(" ");
    }
    return 0;
}