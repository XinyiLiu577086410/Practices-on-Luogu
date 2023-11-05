// origin: https://www.luogu.com.cn/blog/user25365/solution-p1381
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
map<string,int>to_recite;
char s[maxn];
int arti[maxn],where[maxn],q[maxn];
bool vis[maxn];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s);
        to_recite[s]=i;
    }

    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%s",s);arti[i]=to_recite[s];//printf("%d ",arti[i]);
        if(arti[i]==0)continue;
        if(!vis[arti[i]])tot++,vis[arti[i]]=true;
    }
    h=1; t=0;
    for(int i=1;i<=m;i++)
    {
        if(where[arti[i]]==0 && arti[i]!=0)
        {
            num++;

        } where[arti[i]]=i; q[++t] = i;
        /* 记忆化策略 */
        while(h<=t && q[h]<where[arti[q[h]]]) h++;
        if(num==tot) ans=min(ans,i-q[h]+1);
    }
    if(num==0)printf("0\n0\n");
    else printf("%d\n%d\n",tot,ans);
}
