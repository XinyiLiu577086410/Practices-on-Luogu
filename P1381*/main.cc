#include <bits/stdc++.h>
// using namespace std;

int n, m;
long long word[1001];

long long article[100001];
long long where[100001]; 
long long which[100001];
char s[11];
#define PRINT(p,n) for(int k = 1; k <= (n); ++k) printf("%lld\n", (p)[k]);
inline long long my_hash(char s[]){
    int l = strlen(s);
    long long sum = 0;
    long long mul = 1;
    for(int i = 0; i < l; i++) {
        sum += s[i]*i + 9907;
        mul *= s[i]-i + 9907;
    }
    return ((sum*mul) * 9901) % LLONG_MAX;
}
inline
int find_(long long val){
    int l = 1; int r = n;
    int mid = (l + r) / 2;
    while(1) 
    {
        if(l == r) {
            return word[l] == val ? l : 0;
        }

        if(word[mid] < val) 
        {
            l = mid + 1;
            mid = (l + r) / 2; 
        }
        else
        {
            r = mid;
            mid = (l + r) / 2; 
        }
    }
    return 0;
}

int cur;
// n + m * n * log(n)
inline
void read(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%s", s);
        word[i] = my_hash(s);
    }
    std::sort(word + 1, word + n + 1);
    scanf("%d", &m);
    cur = 0;
    for(int j = 1; j <= m; j++) {
        scanf("%s", s);
        article[j] = my_hash(s);
        int pos = 0;
        // find_ : log(n) 
        if((pos = find_(article[j])) != 0) {
            // printf("%s",s);
            where[++cur] = j;
            which[cur] = pos;
        }
    }
    #ifdef DBG
        PRINT(word, n)
        PRINT(article, m)
        PRINT(where, cur)
        PRINT(which, cur)
    #endif
}
/*
    枚举右端点， 贪心左端点
*/
int vis[1001]; 
int tmp[1001];
inline
void doit(){
    int cnt=0;
    for(int i = 1; i <= cur; i++)
    {
        if(!vis[which[i]]) cnt++;       
        vis[which[i]]++;
    }

    memcpy(tmp, vis, sizeof vis);
    int ans = where[cur] - where[1] + 1;
    if(cnt == 0) {
        printf("0\n0"); return;
    }
    int l, r;
    for( r = cur; r >= cnt; r--) {
        for( l = 1; l <= r - cnt; l++) {
            if(tmp[which[l]] <= 1) break;
            tmp[which[l]]--;
        }

        int len = where[r] - where[l] + 1;
        if(len < ans) ans = len;
        
        if(vis[which[r]]==1) break;
        vis[which[r]]--;
        memcpy(tmp, vis, sizeof vis);
    }
    printf("%d\n%d", cnt, ans);
}

int main(void) {
    read();
    doit();
    return 0;
}