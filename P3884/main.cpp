#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

typedef struct eedge{
    ull neighbor;
} edge;

typedef struct nnode{
    vector<edge> e;
    ull parent = 0;
} node;

int tree_deepth = 0;

void mark(node d[], int r) {
    // cout << "\nmark";
    for(auto p : d[r].e) {
        if(p.neighbor == d[r].parent) continue;
        d[p.neighbor].parent = r;
        mark(d, p.neighbor);
    }
    return;
}

ull deep(node d[], int r) {
    // cout << "\ndeep";
    ull max = 1; // 叶节点子树深 1
    for(auto p : d[r].e) {
        if(p.neighbor == d[r].parent) continue;
        ull dp = deep(d, p.neighbor);
        if(dp + 1 > max) max = dp + 1;
    }
    return max;
}

void w_dfs(node d[], int r, int res[], int deep) {
    for(auto p : d[r].e) {
        if(p.neighbor == d[r].parent) continue;
        w_dfs(d, p.neighbor, res, deep + 1);
    }
    res[deep]++;
    return;
}

ull wide(node d[], int r) {
    int res[1000] = {0, }, wide = 0;
    w_dfs(d, r, res, 1);
    for(int i = 1; i <= tree_deepth; i++) {
        if(wide < res[i]) wide = res[i];
    }
    return wide;
}


ull dis(node d[], int x, int y) {
    int route[1000], cur = 0;
    route[cur++] = x;
    while(x != 1) {
        x = d[x].parent;
        route[cur++] = x;
    }
    int cnt = 0;
    for(int i = 0; i < cur; i++) {
        if(route[i] == y) {
            cnt += 2 * i;
            return cnt; 
        }
    }
    while(y != 1) {
        y = d[y].parent;
        cnt++;
        for(int i = 0; i < cur; i++) {
            if(route[i] == y) {
                cnt += 2 * i;
                return cnt; 
            }
        }
    }
    return -1;
}

int main(void) {
    ull n, x, y;
    cin >> n;
    node d[n+10];
    for(ull i = 1; i <= n - 1; i++) {
        ull a, b;
        cin >> a >> b;
        d[a].e.push_back({b});
        d[b].e.push_back({a});
    }
    mark(d,1);
    cout << ( tree_deepth = deep(d, 1) ) << endl;
    cout << wide(d, 1) << endl;
    cin >> x >> y;
    cout << dis(d, x, y);
    return 0;
}
