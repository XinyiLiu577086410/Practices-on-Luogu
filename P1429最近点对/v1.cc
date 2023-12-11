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
}P[maxn], Q_lstripe[maxn], Q_rstripe[maxn];
struct cmpx{bool operator()(point a, point b){return a.x<b.x;}}cmpx;
struct cmpy{bool operator()(point a, point b){return a.y<b.y;}}cmpy;
double dis(point a, point b) {return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}

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
		int cntl=0,cntr=0;
		// here I created a scoped variable, in fact the outer cntl and cntr are not initialzed, mistake!
		for(int i=div/*, cntl=0*/; i>=l; --i/*, ++cntl*/){
			if( abs( P[i].x - xm ) < delta ) {
				Q_lstripe[cntl++] = P[i];
			} 
			else break;
		}
		sort(&Q_lstripe[0], &Q_lstripe[cntl], cmpy);
		
		for(int i=div+1/*,cntr=0*/; i<=r; ++i/*, ++cntr*/){
			if( abs( P[i].x-xm ) < delta ) {
				Q_rstripe[cntr++] = P[i]; 
			} 
			else break;
		}
		sort(&Q_rstripe[0], &Q_rstripe[cntr], cmpy);
		
		int start=0;
		double btw = inf;
		for(int i=0; i<cntl; ++i) {
			bool flag=1;
			for(int j=start; j<cntr; j++){
				if( abs(Q_lstripe[i].y-Q_rstripe[j].y) < delta ){
					btw = min(btw, dis(Q_lstripe[i], Q_rstripe[j]));
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
	printf("%.4lf\n",find_nearest(0,2*n-1));
}