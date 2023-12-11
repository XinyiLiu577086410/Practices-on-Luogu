#include <cstdio>
#include <limits.h>
#define MAX(x,y) ((x)>(y)?(x):(y))
int n,x,ans=INT_MIN,tmp=INT_MIN;
int main(void){
  scanf("%d",&n);
  for( int i=0; i<n; ++i ){
    scanf("%d",&x);
    if(x+tmp>=x) tmp+=x;
    else tmp=x;
    ans=MAX(ans,tmp);
  }     
  printf("%d",ans);
}
