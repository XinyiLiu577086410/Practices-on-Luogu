#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))

int a[200000+10];
int pfx[200000+10];
int n;
/*sum of a[l,r]*/
// inline
// int subsum(int l, int r) {
//     return pfx[r]-pfx[l-1];
// } 
int max_sub(int l, int r) {
    if(l==r) return a[l];
    
    int mid = (l+r)>>1;
    int min_pfx_l = INT_MAX;
    for(int i=l-1; i<=mid-1; i++) { //    for(int i=l; i<=mid-1; i++) { //output: 2147476458
        min_pfx_l = MIN(min_pfx_l, pfx[i]);
    }
    int max_pfx_r = INT_MIN;
    for(int i=mid; i<=r; i++) {
        max_pfx_r = MAX(max_pfx_r, pfx[i]);
    }
    int x = max_pfx_r - min_pfx_l;
    int l_max = max_sub(l,mid); // in [l,mid]
    int r_max = max_sub(mid+1,r); // in [mid,r]

    int lr_min = MAX(l_max,r_max);
    // printf("\n%d %d", x, lr_min);
    return MAX(x, lr_min);
}

int main(void) {
    scanf("%d", &n);
    for( int i=1; i<=n; i++ ){
        scanf("%d", &a[i]);
        pfx[i] = a[i]+pfx[i-1];
    }
    int ans = max_sub(1,n);
    printf("%d",ans);
    return 0;
}