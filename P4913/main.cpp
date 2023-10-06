#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

typedef struct foo{
    ull l, r;
}node;

int deepth = 0;

void d_dfs(node tree[], ull root, int ddeepth) {
    if(ddeepth > deepth) deepth = ddeepth;
    if(tree[root].l) d_dfs(tree, tree[root].l, ddeepth + 1);
    if(tree[root].r) d_dfs(tree, tree[root].r, ddeepth + 1);
    return;
}


int main(void) {
    ull n; // number of node
    cin >> n;
    node tree[n+10];
    for(ull i = 1; i <= n; i++){
        cin >> tree[i].l >> tree[i].r;
    }
    d_dfs(tree, 1, 1);
    cout << deepth;
    return 0;
}

 