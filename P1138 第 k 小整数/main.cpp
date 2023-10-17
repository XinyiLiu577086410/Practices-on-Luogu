// 2023/10/17 23:21:45 AC, time : 55min
#include <bits/stdc++.h> 
int n, k;
using namespace std;
struct monotonous_linked_list_node {
private:
    int data;
    monotonous_linked_list_node * next;
public:
    monotonous_linked_list_node() {next = nullptr;}
    monotonous_linked_list_node(int d, monotonous_linked_list_node* n){
        data = d;
        next = n;
    }
    void push(int x) {
        monotonous_linked_list_node * p = this;
        while (p->next && p->next->data < x)  {
            p = p->next;
            // cout<<"1";
        }
        if(p->next == nullptr){
            p->next = new monotonous_linked_list_node(x, nullptr);
            // cout<<"2 " << x << endl;
        }
        else if(p->next->data == x) {            
            // cout<<"3" << x<< endl;
        }
        else {
            p->next = new monotonous_linked_list_node(x, p->next);
            // cout<<"4" << x<< endl;
        }
    }
    void get(int k) { 
        monotonous_linked_list_node* p = this->next;
        for(int i = 1; i < k; i++, p = p->next) {
           if(p == nullptr)  {
                cout<<"NO RESULT";
                return;
           }
        }
        if(p == nullptr)  {
            cout<<"NO RESULT";
            return;
        }
        cout << p->data;
        return;
    }
};

int main(){
    cin >> n >> k;
    int tmp;
    monotonous_linked_list_node array;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        array.push(tmp);
    }
    array.get(k);
    // cout << array.get(k);
    return 0;
}

//