#include <bits/stdc++.h>
using namespace std;

int n, m, s;
int u, v, w;
int max = INT_MAX;
#define DEBUG
#undef DEBUG
typedef struct edge{
    int v, w;
    edge(int v, int w): v(v), w(w) {}
} edge;
vector<edge> graph[int(1e4)+10];

int &len(int u, int v) {
    for(auto &p : graph[u]) {
        if(p.v == v) return p.w;
    }
    return ::max;
}

void insert(int u, int v, int w) {
    graph[u].push_back(edge(v, w));
}

int main() {
    scanf("%u%u%u",&n,&m,&s);
    s = s-1;
    for(int i = 0; i < m; i++) {
        scanf("%u%u%u",&u,&v,&w);
        if(len(u-1,v-1) == ::max){
            insert(u-1,v-1,w);
        } 
        else if(len(u-1,v-1) > w) {
            len(u-1,v-1) = w;
        }
        else /*do nothing*/;
    }
    // return 0;
    int dis[n];
    // memset(dis, 0xff, sizeof(dis));
    for(int i = 0; i < n; i++){
        dis[i] = INT32_MAX;
    }
    dis[s] = 0;
    std::set<int> s0, s1;    
    for(int i = 0; i < n;i++) {
        s1.insert(i);
    }
    //dijstra
    while(!s1.empty()) {
        // was "int mi = s;" -> infinite loop
        int mi= *s1.begin();
        for(auto p: s1) {
            mi = dis[mi] > dis[p] ? p : mi;
        }

        s1.erase(mi);
        s0.insert(mi);
        #ifdef DEBUG
            cout <<  "the min is " << mi+1 << ", dis == " << dis[mi] << ",";
            cout << "edge number == " << graph[mi].size() << endl;  
        #endif
        for(auto p : graph[mi]) {
            dis[p.v] = dis[p.v] > dis[mi] + p.w ? dis[mi] + p.w : dis[p.v];
        }
    }

    for(int i = 0; i < n; i++) {
        printf("%d", dis[i]);
        if(i<n-1) printf(" ");
    }

    return 0;
}