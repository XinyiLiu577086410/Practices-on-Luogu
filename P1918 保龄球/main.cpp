#include <iostream>

typedef struct {
    int left = 0, right = 0;
    int num;
    bool enabled = true;
} node;

node tree[100000+10];
int n, Q;

using namespace std;

int main(int argc, char* argv[]) {
    auto insert = [&](auto && f, int root = 0, int insert_node) -> void {
        if(tree[insert_node].num < tree[root].num) {
            if(tree[root].left != 0)
                f(f, tree[root].left, insert_node);
            else {
                tree[root].left = insert_node;
            }
        }
        else {
            if(tree[root].right != 0)
                f(f, tree[root].right, insert_node);
            else {
                tree[root].right = insert_node;
            }
        }
    };

    auto find = [&](auto && f, int root, int tar) -> int {
        if(tree[root].num == tar){
            if(tree[root].enabled) {
                // tree[root].enabled = false;
                return root;
            }
            else 
                return 0; 
            
        }
        else if(tar < tree[root].num && tree[root].left != 0) 
            return f(f, tree[root].left, tar);
        else if(tree[root].right != 0)
            return f(f, tree[root].right, tar);
        return 0;
    };

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> tree[i].num; 
        insert(insert, 0, i);
    } 

    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        cout << find(find, 0, x) << endl;
    }
    return 0;
}

