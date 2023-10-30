#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
/*
给定一张 T 条边的无向连通图，求从 S 到 E 恰经过 N 条边的最短路长度。
*/
int n,t,s,e,w,u,v;
struct graph{
    unsigned mat[200*200];
    unsigned V;
    graph() = delete;
    graph(unsigned V) : V(V) {}
    ~graph() {}
    graph operator* (graph const & B) const { 
        graph tmp(V);
        for(int i = 0; i < V*V; i++)
            tmp.mat[i] = INT_MAX;
        for(int k = 0; k < V; k++)  // ijk's order dosen't matter
            for(int i = 0; i < V; i++)
            {
                int iV = i*V;
                for(int j = 0; j < V; j++)
                    tmp.mat[iV+j] = std::min(tmp.mat[iV+j], mat[iV+k] + B.mat[k*V+j]);
            }
        return tmp;
    };
};

int ranks[1010]; // discretization area
graph base(0);
unsigned V;
int init() {
    /*
        n = cows
        t = edges
        s,e = start, end
    */
    scanf("%d%d%d%d",&n,&t,&s,&e);
    vector<int> vec_w, vec_u, vec_v;
    vec_w.reserve(t);
    vec_u.reserve(t);
    vec_v.reserve(t);
    for(int i = 0; i < 1010; i++)
        ranks[i] = -1;
    int cnt=0;
    for(int i = 0; i < t; i++) {
        scanf("%d%d%d",&w,&u,&v);
        // a valid rank[] is never 0.
        ranks[u] = ~ranks[u] ? ranks[u] : cnt++; // discretization
        ranks[v] = ~ranks[v] ? ranks[v] : cnt++; // discretization
        vec_w.push_back(w);
        vec_u.push_back(ranks[u]);
        vec_v.push_back(ranks[v]);        
    }
    V = cnt;
    unsigned VV = V*V;
    graph tmpbase(V);
    for(int i = 0; i < VV; i++)
        tmpbase.mat[i] = INT_MAX;
    for(int i =0; i < t; i++)
        tmpbase.mat[vec_u[i]*V + vec_v[i]] = tmpbase.mat[vec_v[i]*V + vec_u[i]] = vec_w[i];
    base = tmpbase;
    return 0;
}

int calculate(){
    graph res = base;
    --n;
    while(n) {
        if(n&1) res = res * base;
        base = base * base;  
        n = n >> 1;
    }
    printf("%u", res.mat[ranks[s]*V+ranks[e]]);
    return 0;
}

int main(){ 
    init();
    calculate();
    return 0;
}