/*
note : huffman tree implenented with std::priority_queue.
        to build an calculate minimun weighted path length.
date : 2023/10/25
begin : about:15:20
AC at : 16:22     
*/
#include <bits/stdc++.h>
using namespace std;
#define DBG 
#undef DBG
int main(){
    int n;
    scanf("%d",&n);
    int cur;
    int tmp;
    struct cmp { bool operator()(int a, int b){return a>b;} } ;
    priority_queue<int, vector<int>, cmp> pq;
    for(cur=0; cur<n; cur++){
        scanf("%d",&tmp);
        pq.push(tmp);
    }
    int cost=0;
    int my_heap=0;
    while(!pq.empty()){
        my_heap += pq.top();
        pq.pop();
        if(pq.empty()) break; // 停机
        my_heap += pq.top();
        pq.pop();
        cost += my_heap;
        pq.push(my_heap);
        my_heap = 0;
    } 
    printf("%d",cost);
}