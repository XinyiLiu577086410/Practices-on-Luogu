#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
typedef long long llong;
struct point{
	int x, y; 
	bool operator==(point operand) {return x==operand.x && y==operand.y;}
};
using std::vector; using std::sort; using std::min; using std::find;
struct cmpx{bool operator()(point a, point b){return a.x<b.x;}}cmpx;
struct cmpy{bool operator()(point a, point b){return a.y<b.y;}}cmpy;
inline llong dis(point a, point b) {return ((llong)a.x-(llong)b.x)*((llong)a.x-(llong)b.x)+((llong)a.y-(llong)b.y)*((llong)a.y-(llong)b.y);}
llong find_nearest(vector<point>P, vector<point>Q) {
	if (P.empty()) return 0x7f7f7f7f7f7f7f7f;
	int div = P.size() >> 1;
	llong xdiv = P[div].x; 
	vector<point> Ql, Qr, Pl, Pr;
	int lim = Q.size();
	for(int i = 0; i < lim; ++i) {
		point q = Q[i], p = P[i];
		if(q.x <= xdiv) Ql.push_back(q); else Qr.push_back(q);
		if(p.x <= xdiv) Pl.push_back(p); else Pr.push_back(p);
	}
	if(Ql.size() && Qr.size()){
		llong ldis = find_nearest(Pl, Ql);
		llong rdis = find_nearest(Pr, Qr);
		llong delta = min(ldis, rdis);
		llong local_dis = 0x7f7f7f7f7f7f7f7f;
		vector<point> subQr,subQl;
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
					llong d = dis(*k, *p);
					if( local_dis > d )
						// if(p->tag != k->tag)
							local_dis = d;			
				}
				else if(!flag) break;
			}
		}	
		return min(local_dis, delta);
	}
	else {
		llong ret = 0x7f7f7f7f7f7f7f7f;
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
	P.reserve(n);
	for(int i=0; i<n; ++i) { scanf("%d%d",&p.y,&p.x); P.push_back(p); }
	Q=P;
	sort(P.begin(),P.end(),cmpx);
	sort(Q.begin(),Q.end(),cmpy);
	printf("%lld\n", find_nearest(P,Q));
	return 0;
}

//错因：整型溢出
