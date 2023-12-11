#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using std::sort; using std::min; using std::find; using std::binary_search;
const int maxn = 200000+100;
const double inf = 0x7f7f7f7f7f7f7f7f;
struct point{
	double x, y; 
	bool operator==(point operand) {return x==operand.x && y==operand.y;}
}P[maxn], Q[maxn];
struct cmpx{bool operator()(point a, point b){return a.x<b.x;}}cmpx;
struct cmpy{bool operator()(point a, point b){return a.y<b.y;}}cmpy;
double dis(point a, point b) {
	#ifdef DEBUG
	// printf("dis(%lf,%lf,%lf,%lf)=%lf\n",a.x,a.y,b.x,b.y,sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
	#endif
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double find_nearest(int l, int r) {
	if ( l >= r ) return inf; // only one point
	if ( l == r-1 ) return dis(P[l], P[r]);
    else {
		int div = (l+r)>>1;
		int xm = P[div].x;
		double lmin, rmin, delta;
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
		sort(&Q[0], &Q[cnt], cmpy);
		double btw = inf;
		for(int i=0; i<cnt; ++i) {
			for(int j=i+1; j<cnt; ++j) {
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
	for(int i=0; i<n; ++i) { scanf("%lf%lf",&P[i].x,&P[i].y);}
	sort(P,P+n,cmpx);
	printf("%.4lf\n",find_nearest(0,2*n-1)); // this is why 0.0000
}