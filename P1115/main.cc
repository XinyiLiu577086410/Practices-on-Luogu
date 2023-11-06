#include <cstdio>
#include <algorithm>
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))

int a[200000+10];
long long pfx[200000+10];
int n;
long long sum;
/*sum of a[l,r]*/
long long subsum(int l, int r) { return pfx[r]-pfx[l-1]; } 
long long min_pfx(int l, int r) {
    long long min = LLONG_MAX;
    for(int i=l; i<=r; i++) min = MIN(min,pfx[i]);
    return min;
}
long long max_pfx(int l, int r) {
    long long max = LLONG_MIN;
    for(int i=l; i<=r; i++) max = MAX(max,pfx[i]);
    return max;
}
long long max_sub(int l, int r) {
    if(l==r) return a[l];

    int mid = (l+r)>>2;
    long long x = max_pfx(mid,r) - min_pfx(0, mid-1);
    long long l_max = max_sub(l,mid); // in [l,mid]
    long long r_max = max_sub(mid+1,r); // in [mid+1,r]

    long long lr_min = MAX(l_max,r_max);
    return MAX(x, lr_min);
}

int main(void) {
    scanf("%d", &n);
    for( int i=1; i<=n; i++ ){
        scanf("%d", &a[i]);
    }
    for( int i=1; i<=n; i++ ){
        pfx[i] = a[i]+pfx[i-1];
    }
    long long ans = max_sub(1,n);
    printf("%lld",ans);
    return 0;
}