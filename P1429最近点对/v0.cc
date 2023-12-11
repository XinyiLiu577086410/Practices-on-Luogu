#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
struct point{
	double x, y; 
	bool operator==(point operand) {return x==operand.x && y==operand.y;}
};
using std::vector; using std::sort; using std::min; using std::find;
struct cmpx{bool operator()(point a, point b){return a.x<b.x;}}cmpx;
struct cmpy{bool operator()(point a, point b){return a.y<b.y;}}cmpy;
double dis(point a, point b) {return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
double find_nearest(vector<point>P, vector<point>Q) {
	if (P.empty()) return 0x7f7f7f7f7f;
	int div = P.size() >> 1;
	double xdiv = P[div].x; 
	vector<point> Ql, Qr, Pl, Pr;
	int lim = Q.size();
	for(int i = 0; i < lim; ++i) {
		point q = Q[i], p = P[i];
		if(q.x <= xdiv) Ql.push_back(q); else Qr.push_back(q);
		if(p.x <= xdiv) Pl.push_back(p); else Pr.push_back(p);
	}
	if(Ql.size() && Qr.size()){
		double ldis = find_nearest(Pl, Ql);
		double rdis = find_nearest(Pr, Qr);
		double delta = min(ldis, rdis);
		double acxdis = 0x7f7f7f7f7f;
		vector<point> subQr,subQl;
		int liml = Ql.size();
		int limr = Qr.size();
		for(std::vector<point>::iterator k = Ql.begin(); k != Ql.end(); ++k) {
			if(abs(xdiv-k->x)<delta) subQl.push_back(*k);
		}
		for(std::vector<point>::iterator k = Qr.begin(); k != Qr.end(); ++k) {
			if(abs(xdiv-k->x)<delta) subQr.push_back(*k);
		}
		std::vector<point>::iterator stat = subQr.begin();
		for(std::vector<point>::iterator k = subQl.begin(); k != subQl.end(); ++k) {
			std::vector<point>::iterator p = stat;
			bool flag = true;
			for ( ; p != subQr.end(); ++p) {
				if ( abs( p->y - k->y ) < delta ) {
					if(flag) {
						flag = false;
						stat = p;
					}
					double d = dis(*k, *p);
					if( acxdis > d )
						// if(p->tag != k->tag)
							acxdis = d;			
				}
				else {
					if(!flag) break;
				}
			}
		}	
		return min(acxdis, delta);
	}
	else {
		double ret = 0x7f7f7f7f7f;
		for (std::vector<point>::iterator i = Q.begin(); i < Q.end(); ++i) {
			for(std::vector<point>::iterator j = i + 1; j < Q.end(); ++j) {
				// if(i->tag != j->tag)
					ret = min(dis(*i, *j), ret);
			}	
		}
		return ret;
	}
}
int main(void) {
	vector<point> P,Q;
	int n;
	scanf("%d", &n); point p;
	for(int i=0; i<n; ++i) { scanf("%lf%lf",&p.x,&p.y);	P.push_back(p); }
	Q=P;
	sort(P.begin(),P.end(),cmpx);
	sort(Q.begin(),Q.end(),cmpy);
	printf("%.4lf\n",find_nearest(P,Q));
	return 0;
}