#include <bits/stdc++.h>

using namespace std;

typedef struct {
    unsigned long long to,len;
} edge;

typedef struct nnode{
    vector<edge> edges;
    unsigned long long height = 0; // as root node, how tall i am.
    unsigned long long parent = 0;
} node;


// preorder traverse the tree from S
// to set the node.height fields
inline void mark_height(node data[], unsigned long long root) {
    data[root].height = 0;

    // if have children, do; else never.
    for(auto a_edge : data[root].edges) {
        // recursive call
        if(a_edge.to == data[root].parent) continue;
        data[a_edge.to].parent = root;
        mark_height(data, a_edge.to);
        unsigned long long child_height_plus_edge_len = data[a_edge.to].height + a_edge.len;
        if(data[root].height < child_height_plus_edge_len)
            data[root].height = child_height_plus_edge_len;
    }

    return;
}

unsigned long long align(node data[], unsigned long long root) {
    unsigned long long cnt = 0; // counter that this function returns

    for(auto a_edge : data[root].edges) {
        if(a_edge.to == data[root].parent) continue;
        cnt += data[root].height - (a_edge.len + data[a_edge.to].height);
        cnt += align(data, a_edge.to);
    }

    return cnt;
}


int main(void){
    unsigned long long N, S;
    cin >> N >> S;
    node nodes[N + 10]; // used : [1,N]

    for(unsigned long long i = 1; i <= N - 1; i++) {
        unsigned long long a, b, t;
        cin >> a >> b >> t;
        edge e = {b, t};
        nodes[a].edges.push_back(e);
        e = {a, t};
        nodes[b].edges.push_back(e);
    }

    mark_height(nodes, S);
    cout << align(nodes, S);
    return 0;  
}


// OI首先考虑算法正确性问题。
// 首先从宽使用数据类型：long long
// 正确估计变量取值
// 很少涉及访存，改数据类型的收效甚微
// 当然，编程时考虑复杂度也是必要的