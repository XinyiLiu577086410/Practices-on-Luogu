#include <bits/stdc++.h>
int N, M;
typedef struct node
{
    int data;
    node * next = nullptr; 
    node * prior = nullptr; 

    // node(us x): data(x), next(nullptr) {}
    bool find(int x) {
        auto p = head();
        while(p){
            if(p->data == x) return true;
            p = p->next;
        }
        return false;
    }
    node * head() {
        auto q = this;
        while (q->prior){
            q = q->prior;
        }
        return q;
    }
    node * tail() {
        auto q = this;
        while (q->next){
            q = q->next;
        }
        return q;
    }
    void merge(node * q) {
        if(head() == (q=q->head())) return;
        node *p = tail();
        q->prior = p;
        p->next = q;
        return;
    }
} node;
int Z, X, Y;
using namespace std;
int main() {
    cin >> N >> M;
    node tbl[N+10];
    for (int i = 0; i <= N+9; i++) {
        tbl[i] = {i, nullptr, nullptr};
    }
    
    for(int i = 0; i < M; i++) {
        // cin >> Z >> X >> Y;
        scanf("%d %d %d", &Z, &X, &Y);
        if(Z==2){
            if(tbl[X].find(Y))
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