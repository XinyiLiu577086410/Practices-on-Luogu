//P4779, derived from : P3371
//begin: 2023/10/20 22:32:18
//end: 2023/10/21 10:09:00
//time: about 5 hours
#define DBG
#undef DBG
#include <bits/stdc++.h>
using namespace std;
vector<int> to, wgt, nxt; // max size: 2e5; 
//their 3 sizes are the same at all time
vector<int> head;
int cnt = 0;

// you must write clear processes.
int int_max = INT_MAX;
inline int & find_edge(int u, int v){
    for(int i = head[u]; ~i; i = nxt[i]){
        if(to[i] == v) return wgt[i];
    }
    return ::int_max;
}

// dijstra 算法适合使用链式前向星，因为要遍历一个点的每一条边
// 链式前向星写错了。用size获取to.head必须在**相应**的to.push之前.
// head[u] = nxt.size():这里根本不能用nxt.size()，因为有依赖
// add and replace
void inline add_rpls(int u, int v, int w) {
    // int & last_edge_w = find_edge(u, v); // 忘记 &
    // if(last_edge_w == ::int_max) {
        nxt.push_back(head[u]); // the init operation pushes -1.
        head[u] = to.size();    
        to.push_back(v);        
        wgt.push_back(w);       
    // }
    // else if(last_edge_w > w) {
    //     last_edge_w = w;
    // }
    // else/*pass*/;
    // 不需要在这里考虑平行边
}

int n, m, s;
int u, v, w;
vector<int> dis;
int main(void){
    scanf("%d%d%d",&n,&m,&s);
    head.resize(n+10,-1);
    dis.resize(n+10,::int_max);
    dis[--s] = 0; // fine, operator[]() of std::vector doesn't check ranges
    /*
        -1 value used as the mark of the end of the linked list.
    */
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d",&u,&v,&w);
        add_rpls(u-1,v-1,w);
    }
    auto cmp = [&](int a,int b)->bool {return dis[a] > dis[b];};
    std::priority_queue<int,vector<int>, decltype(cmp)> s1(cmp);
    s1.emplace(s);
    int min;
    bool unused[int(1e5)+10]={false,};
    /* 
    这里数组大小没有写，导致min一直为0；
    */
    unused[s]=true;
    while(!s1.empty()){
        while (!s1.empty()) {
            min = s1.top();
            s1.pop();
            if(unused[min]) {
                unused[min] = false;
                break;
            }
            else continue;
        }
        #ifdef DBG
            printf("min == %d\n",min);
        #endif
        for(int i = head[min]; ~i; i=nxt[i]){
            int v = to[i];
            #ifdef DBG
                printf("to[%d] == %d\n",i,v);
            #endif
            int dis_new = dis[min] + wgt[i];
            if((dis_new >= 0) && dis[v] > dis_new) { /*not >, caused WA in #6.*/
                dis[v] = dis_new;
                s1.push(v);
                #ifdef DBG
                    printf("s1.push(%d), s1.size() == %lu\n",v,s1.size());
                #endif
                unused[v] = true;
            }
            else /*do nothing*/;
        }
    }
    for(int i = 0; i < n; i++) {
        #ifdef DBG
            printf("dis[%d]=",i+1);
        #endif
        printf("%d",dis[i]);
        if(i<n-1) printf(" ");
    }
    return 0;
}