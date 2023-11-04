#include <bits/stdc++.h>
#define MIN(x, y) ((x)<(y)?(x):(y))
std::map<std::string, int> my_map;
int n,m;
char s[20];
const int maxn = int(1e5+10);
int vis[maxn];
int tmp_vis[maxn];
int article[maxn];
int cnt;
int main(){

    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%s", s);
        my_map[s] = i;
    }
    scanf("%d", &m);
    for(int i=1; i<=m; i++) { 
        scanf("%s", s);
        article[i] = my_map[s];
        if(article[i]) {
            if(vis[article[i]]==0)
                cnt++;       
            vis[article[i]]++;
        }
    }

    int len = 0xffffff, r, l;
    for( r=m; r>=1; --r ) {
        
        memcpy(tmp_vis, vis, (m+1)*sizeof(int));
        for( l=1; l<=r; ++l ) {
            if(article[l]) {
                if(tmp_vis[article[l]]==1) break;
                tmp_vis[article[l]]--;
            }
        }

        len = MIN(r - l + 1, len); 
        if(len == cnt) break;
        if(article[r]){
            if(vis[article[r]]==1) break;
            else --vis[article[r]];
        }
    }

    printf("%d\n%d", cnt, len);
}

/*
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<map>
using namespace std;
const int maxn=100000+10;
int n,m,h,t;
int tot,num,ans=0x7f7f7f7f;
map<string,int>mapp;
char s[maxn];
int a[maxn],b[maxn],q[maxn];
bool vis[maxn];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s);
        mapp[s]=i;
    }scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%s",s);a[i]=mapp[s];//printf("%d ",a[i]);
        if(a[i]==0)continue;
        if(!vis[a[i]])tot++,vis[a[i]]=true;
    }h=1;t=0;
    for(int i=1;i<=m;i++)
    {
        if(b[a[i]]==0 && a[i]!=0)
        {
            num++;
        }b[a[i]]=i;q[++t]=i;
        while(h<=t && q[h]<b[a[q[h]]])h++;
        if(num==tot)ans=min(ans,i-q[h]+1);
    }
    if(num==0)printf("0\n0\n");
    else printf("%d\n%d\n",tot,ans);
}*/