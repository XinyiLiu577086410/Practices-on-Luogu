#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    node * father = nullptr; 
    vector<node *> child; 
public:
    node(){}
    node(int x, node* t) {data = x; father = t;}

    // bool find(node* x) {
    //     if(this->father == x) return true; 
    //     auto sibling = this->father->child;
    //     // auto it = std::find(sibling.begin(), sibling.end(), x); // was int type parameter
    //     /*error: ISO C++ forbids comparison between pointer and integer [-fpermissive]*/
    //     auto it = std::find(sibling.begin(), sibling.end(), x);
    //     return  it != sibling.end();
    // }

    bool eq(node * q) {
        return q->father == this->father;
    }

    void merge(node * q) {
        if(eq(q)) return; // last change, segfault && WA disappleared then AC
        node * const my_father = this->father;
        node * const their_father = q->father;
        // my_father->child.push_back(their_father->father); // was in
        my_father->child.push_back(their_father);
        their_father->father = my_father;                 // reverse order
        for(auto & qfc : their_father->child){
            qfc->father = my_father;
            my_father->child.push_back(qfc);
        }
        their_father->child.clear();
    }
} node;

int N, M;
int Z, X, Y;
int main() {
    scanf("%d%d", &N, &M);
    node tbl[N+10];
    for (int i = 0; i <= N+9; i++) {
        tbl[i] = node(i, &tbl[i]);
    }
    
    for(int i = 0; i < M; i++) {
        scanf("%d%d%d", &Z, &X, &Y);
        if(Z==2){
            if(tbl[X].eq(&tbl[Y]))
                printf("Y\n");
            else
                printf("N\n");
        }
        else{
            tbl[X].merge(&tbl[Y]);
        }
    }
    return 0;

}