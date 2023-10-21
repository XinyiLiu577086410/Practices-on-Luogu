//P4779, derived from : P3371
//begin: 2023/10/20 22:32:18
//end: 2023/10/21 10:09:00
//time: about 5 hours
/*
record: 
1:
    only the input + building graph part of P3371:
    #1:122ms
    #5:156ms
    #2,3,4,6: TLE(1.20s)
need faster D.S., and just rewrite the code.
*/
#define DBG
#undef DBG
#include <bits/stdc++.h>
using namespace std;
/*
    global variables used by functions.
    structs can be divide into several arrays. 
*/
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
    // 大部分样例没有平行边
}

/*
global variables used by main().
*/
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
    
    // typedef struct my_int
    // {
    //     int i;
    //     // my_int
    //     bool operator> (const my_int & y){ return dis[i]>dis[y.i]; }
    //     void operator++ (){i++;}
    //     const int & operator()() {return i;}
    //     operator int() const{return i;}
    // } my_int;
    // std::priority_queue<my_int,vector<my_int>,less<my_int>> s1;
    
    auto cmp = [&](int a,int b)->bool {return dis[a] > dis[b];};
    
    std::priority_queue<int,vector<int>, decltype(cmp)> s1(cmp);
    // for(int i=0; i<n; ++i){
        // s1.emplace(i);
    // }
    s1.emplace(s);
    int min;
    bool unused[int(1e5)+10]={false,};
    /* 这里数组大小没有写，导致min一直为0；
        4 6 1
        1 2 2
        2 3 2
        2 4 1
        1 3 5
        3 4 3
        1 4 4
        min == 0
        to[5] == 3
        s1.push(3), s1.size() == 1
        to[3] == 2
        s1.push(2), s1.size() == 2
        to[0] == 1
        s1.push(1), s1.size() == 3
        min == 0
        to[5] == 3
        to[3] == 2
        to[0] == 1
        min == 2
        to[4] == 3
        0 2 5 4%     
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
            // dis[v] = (dis_n > 0) && dis[v] > dis_n ? dis_n : dis[v];
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

/*
note: the correct process:
$./a.out
4 6 1
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4
min == 0
to[5] == 3
s1.push(3), s1.size() == 1
to[3] == 2
s1.push(2), s1.size() == 2
to[0] == 1
s1.push(1), s1.size() == 3
min == 1
to[2] == 3
s1.push(3), s1.size() == 3
to[1] == 2
s1.push(2), s1.size() == 4
min == 3
min == 2
to[4] == 3
min == 2
to[4] == 3
0 2 4 3%      
*/