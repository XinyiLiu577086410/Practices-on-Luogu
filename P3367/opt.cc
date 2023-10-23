#include <bits/stdc++.h>
using namespace std;
vector<int> head;
vector<vector<int> > member;
int n,m;

// 查
bool find (int x, int y){
    if(x==y) return true;
    else return (head[x] && head[x] == head[y]);
}

// 并
void merge(int x, int y){
    if(find(x,y)) return;
    /*规约*/
    if(!head[x]){
        head[x] = x;
        member[x].push_back(x);
    }
    if(!head[y]){
        head[y] = y;
        member[y].push_back(y);
    } 

    x = head[x];
    y = head[y];
    for(auto p : member[y]){
        member[x].push_back(p);
        head[p] = x;
    }
    member[y].clear();
}


int main(void){
    scanf("%d%d",&n,&m);
    head.resize(n+1, 0);
    member.resize(n+1);
    int z,x,y; //不是xyz
    for(int i=0; i<m; i++){
        scanf("%d%d%d",&z,&x,&y);
        if(z==1){
            merge(x,y);
        }
        else{ /* z==2 */
            cout<<(find(x,y) ? "Y\n" : "N\n");
        }
    }
    return 0;
}