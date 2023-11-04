#include <bits/stdc++.h>

int data[int(5e5)];
int tmp[int(5e5)];
int n;
unsigned long long ans = 0;

#define PRINT for(int i = 1; i <= n; i++){ printf("%d ", data[i]);}

void read(){
    scanf("%d", &n);
    /* store data in [1,n] */
    for(int i = 1; i <= n; i++) { 
        scanf("%d", &data[i]);
    }
}
/*  merge sort data[l,r], algorithm extended:*/
/* at the same time calculate ans           */
void msort(int l, int r) {
    int mid = (l+r)/2;
    if(l == r) return;
    else {
        msort(l, mid);
        msort(mid+1, r);
    }
    /* merge */
    int i1 = l, i2 = mid + 1; 
    // i1,i2 associate with a[] (sorted data inside);
    int j = l;                  
    // j assoiciate with tmp[] (data inside will be write back)
    int tag_i2 = 0;
    while(i1 <= mid && i2 <= r) {
        if(data[i1] <= data[i2]) {
            tmp[j] = data[i1];
            i1++;
            j++;
        }
        else{
            ans += mid + 1 - i1;
            tmp[j] = data[i2];
            i2++;
            j++;
        }
    }
    int len_right = r - mid;
    while(i1 <= mid)
    { 
        tmp[j] = data[i1];
        i1++;
        j++;
    }
    while(i2 <= r)
    {
        tmp[j] = data[i2];
        i2++;
        j++;
    }

    for(int i = l; i <= r; i++) {
        data[i] = tmp[i];
    }
    return;
}

void doit(){
    msort(1,n);
    // PRINT
}

int main(void) {
    read(); // O(n)
    doit(); // O()
    printf("%llu", ans);
    return 0;
}