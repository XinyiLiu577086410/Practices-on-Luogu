#include <bits/stdc++.h>
using namespace std;
int n, m;
struct {
    struct ref_t{
        int val = 0;
        ref_t * next = nullptr;
    } * refers_to_sorted = new ref_t;
    // neighborhood stored in linked list
    // with empty head node
public:
    void add_ref(int tar) {
        ref_t * p = refers_to_sorted;
        while(p->next != nullptr && p->next->val < tar) p = p->next; 
        if(p->next == nullptr) 
            p->next = new ref_t({tar, nullptr});
        else
            p->next = new ref_t({tar, p->next}); // I love C++!! 
    }
} graph[int(1e5+10)];
bool visited[int(1e5)+10];

int main(void) {
    cin >> n >> m;
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < m; i++) {
        int src, tar;
        cin >> src >> tar; 
        graph[src].add_ref(tar);
    }
    
    auto dfs = [] (auto && f, int start) -> void {
        cout << start << " ";
        auto p = graph[start].refers_to_sorted->next;
        while (p) {
            if(!visited[p->val]){ 
                f(f, p->val);   // you should mark it as visited first

                visited[p->val] = true;
            }
            p = p->next;
        }
    };
    
    queue<int> next_to_visit;
    auto bfs = [&next_to_visit] (int start) -> void {
        next_to_visit.push(start);
        while(!next_to_visit.empty()) {
            int tmp = next_to_visit.front();
            next_to_visit.pop();
            cout << tmp << " ";
            auto p = graph[tmp].refers_to_sorted->next;
            while (p) {
                if(!visited[p->val]){ 
                    next_to_visit.push(p->val);
                    visited[p->val] = true;
                }
                p = p->next;
            }
        }
    };

    dfs(dfs, 1);
    cout << endl;
    memset(visited, false, sizeof(visited));
    bfs(1);
}