#include <bits/stdc++.h>
#define DBG
#undef DBG
using namespace std;

typedef struct edge {
    int u, v, w;
} eg;

class cmp{
public:
    bool operator() (eg a, eg b){
        return a.w > b.w;
    }
};

int n,m;
vector<int> to, nxt, wgt, head; 
priority_queue<eg, vector<eg>, cmp> srtd_eg;
vector<eg> reserved;
set<int> vis;

// union-find set
vector<int> ufs_tag;
vector<set<int> > ufs_child;

bool ufs_find(int x, int y){
    if(x==y) return true;
    return ufs_tag[x] && ufs_tag[x]==ufs_tag[y];
}

void ufs_merge(int x, int y){
    if(ufs_find(x,y)) return;
    if(!ufs_tag[x]){
        ufs_tag[x]=x;
        ufs_child[x].insert(x);
    }
    if(!ufs_tag[y]){
        ufs_tag[y]=y;
        ufs_child[y].insert(y);
    }

    x=ufs_tag[x];
    y=ufs_tag[y];
    for(auto p : ufs_child[y]){
        ufs_child[x].insert(p);
        // 少了一句
        ufs_tag[p] = x;
    }
    ufs_child[y].clear();
}

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


void dfs(int u = 1){
    vis.insert(u);
    // cout<<u<<endl;
    for(int i = head[u]; ~i; i = nxt[i]){
        if(vis.find(to[i]) == vis.end()) dfs(to[i]);
    }
}

 
bool find_crcl(eg e_to_add){
    return ufs_find(e_to_add.u, e_to_add.v);
}

int main(void){
    cin>>n>>m;
    head.resize(n+1,-1);
    ufs_tag.resize(n+1,0);
    ufs_child.resize(n+1);
    int x,y,z;
    for(int i=0; i<m; i++){
        // cin>>x>>y>>z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
        srtd_eg.push({x,y,z});
    }
    #ifdef DBG
        printf("%lu edges.\n", srtd_eg.size());
    #endif
    dfs();
    if(vis.size() != n) {
        cout<<"orz";
        return 0;
    }
    while(!srtd_eg.empty()) {
        auto m = srtd_eg.top();
        srtd_eg.pop();
        #ifdef DBG
            printf("poped (%d, %d, %d)\n", m.u,m.v,m.w);
        #endif 
        if(ufs_find(m.u, m.v)){
            #ifdef DBG
                printf("discarded (%d, %d, %d)\n", m.u,m.v,m.w);
            #endif
            continue;
        }
        else{
            ufs_merge(m.u, m.v);
            reserved.push_back(m);
        }
    }
    int sum = 0;
    for(auto p : reserved){
        sum = sum + p.w;
    }
    cout << sum;
    return 0;
}

/*
log
g++ prime.cc -std=c++17 -Wall   
prime.cc:43:14: warning: unused variable 'p' [-Wunused-variable]
    for(auto p : ufs_child[y]){
             ^
prime.cc:89:27: warning: format specifies type 'int' but the argument has type 'size_type' (aka 'unsigned long') [-Wformat]
    printf("%d edges.\n", srtd_eg.size());
            ~~            ^~~~~~~~~~~~~~
            %zu
2 warnings generated.
*/