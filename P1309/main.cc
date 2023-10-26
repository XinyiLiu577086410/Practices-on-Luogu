/*

AC: 2023/10/26 20:45:08
洛谷的测评机挂了。Subtask#0 一直waiting
Subtask#1 all AC
*/
#include <bits/stdc++.h>
// #define DBG
int w[200000+10] = {0};
int s[200000+10] = {0};
int order[200000+10] = {0};
int n,r,q;
struct cmp{
    // 从大到小排序
    bool operator()(int a, int b) {
        return s[a] != s[b] ? s[a] > s[b] :  a < b ;
    }
} cmp;
int main(){
    scanf("%d%d%d",&n,&r,&q);
    for(int i = 0; i < 2*n; i++){
        scanf("%d",s+i);
    }
    for(int i = 0; i < 2*n; i++){
        scanf("%d",w+i);
    }
    for(int i = 0; i < 2*n; i++){
        order[i] = i;
    }
    for(int i = 0; i < r; i++){
        /*这里要用stable sort*/
        std::stable_sort(order, order + 2*n, cmp);
        #ifdef DBG
            printf("\n");
            for(int i = 0; i < 2*n; i++) 
                printf("\ts[%d]=%d", i+1, s[i]);
        #endif
        for(int j = 0; j < n; j++){
            int player1 = order[2*j], player2 = order[2*j + 1];
            #ifdef DBG
                printf("\n%d vs %d, %d won",player1+1,player2+1,w[player1]>w[player2]?player1+1:player2+1);
            #endif
            if(w[player1] > w[player2]){
                s[player1]++;
            }
            else{
                s[player2]++;
            }
        }
    } 
    std::stable_sort(order, order + 2*n, cmp);
    #ifdef DBG
        printf("\n");        
        for(int i = 0; i < 2*n; i++) 
            printf("\ts[%d]=%d", i+1, s[i]);
        printf("\n");
    #endif
    printf("%d", order[q-1]+1);
    
}