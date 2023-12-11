#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using std::sort; using std::min; using std::find; using std::binary_search;
typedef long long llong;
const int maxn = 200000+100;
const llong inf = 0x7f7f7f7f7f7f7f7f;
struct point{
	llong x, y; 
	bool operator==(point operand) {return x==operand.x && y==operand.y;}
}P[maxn], Q[maxn];
struct cmpx{bool operator()(point a, point b){return a.x<b.x;}}cmpx;
struct cmpy{bool operator()(point a, point b){return a.y<b.y;}}cmpy;
llong dis(point a, point b) {
	#ifdef DEBUG
	// printf("dis(%lf,%lf,%lf,%lf)=%lf\n",a.x,a.y,b.x,b.y,sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
	#endif
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

llong find_nearest(int l, int r) {
	if(  l > r ) exit(-1);
	if ( l == r ) return inf; // only one point
	if ( l + 1 == r ) {
		#ifdef DEBUG
		printf("dis(%lf,%lf,%lf,%lf)=%lf\n",P[l].x,P[l].y,P[r].x,P[r].y,dis(P[l], P[r]));
		#endif
		return dis(P[l], P[r]);
	}
    else {
		int div = (l+r)>>1;
		llong xm = P[div].x;
		llong lmin, rmin, delta;
		lmin = find_nearest(l, div);
		rmin = find_nearest(div+1, r);
		delta = min(lmin, rmin);
		int cnt = 0;
		for(int i=l; i<=r; ++i){
			if( abs( P[i].x - xm ) < delta ) {
				Q[cnt++] = P[i];
			} 
			else break;
		}
		llong btw = inf;
		for(int i=0; i<cnt; ++i) {
			for(int j=0; j<cnt; ++j) {
				if( i == j ) continue;
				if( abs(Q[i].y-Q[j].y) < delta ){
					btw = min(btw, dis(Q[i], Q[j]));
				}
			}
		}
		return min(btw, delta);
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; ++i) { scanf("%lld%lld",&P[i].x,&P[i].y);}
	sort(P,P+n,cmpx);
	printf("%lld\n",find_nearest(0,n-1)); 
}