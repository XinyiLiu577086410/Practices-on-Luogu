#include <bits/stdc++.h>
#define MIN(x, y) ((x)<(y)?(x):(y))
std::map<std::string, int> my_map;
int n,m;
char s[20];
const int maxn = int(1e5+10);
int vis[maxn];
int article[maxn]; // store mapped value
int cnt;

int main(){

    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%s", s);
        if(!my_map[s]) my_map[s] = i;
    }
    scanf("%d", &m);

    // printf("size:%lu\n", my_map.size()); //3
    // printf("my_map[\"fafd\"]=%d", my_map["fafd"]); //0
    // printf("size:%lu\n", my_map.size());  //4

    for(int i=1; i<=m; i++) { 
        scanf("%s", s);
        article[i] = my_map[s];
        if(article[i]) {
            if(vis[article[i]]==0)
                cnt++;       
            vis[article[i]]++;
        }
    }
    int rightest[maxn]={0};
    int len = 0xf7f7ff;int r=0;int l=1;
    int c=0;
    memset(vis,0,sizeof vis); //reuse vis[]
    while(c != cnt){
        r++;
        if(article[r]){
            rightest[article[r]]=r;
            if(!vis[article[r]]) c++, vis[article[r]]=1;
        }            // putchar('%');
    }
    
    for(; r<=m; ++r/*,  putchar('%')*/) {
        if(article[r]) rightest[article[r]]=r;
        while (article[l]==0 || rightest[article[l]]!=l && l<r) ++l;
        // printf("\nrightest[article[l]]=%d\n",rightest[article[l]]);
        // printf("\nl=%d,r=%d\n",l,r);
        len = MIN(len, r-l+1);
    }
    // printf("\nl=%d,r=%d\n",l,r-1);
    printf("%d\n%d", cnt, len);
}

