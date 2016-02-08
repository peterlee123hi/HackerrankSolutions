#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef vector<int> vi;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define LSOne(S) (S&-S)

class FenwickTree {
private: vi ft;
public:
	FenwickTree(int n) { ft.assign(n+1,0); }
	int rsq(int b) {
		int sum=0;
		while(b>0)
			sum+=ft[b],b-=LSOne(b); 
	}
	int rsq(int a,int b) { return rsq(b)-(a==1?0:rsq(a-1)); }
	void adjust(int k,int v) {
		while(k<SZ(ft))
			ft[k]+=v,k+=LSOne(k);
	}
};

struct candle {
	int h,c;
	candle(int h,int c) {
		this->h=h; this->c=c;
	}
};
bool operator<(const candle& a,const candle& b) { return a.h<b.h; }

int n,k;
vector<candle> candles;

int solve() {
	return 0;
}

int main() {
	scanf("%d %d",&n,&k);
	REP(i,0,n) {
		int h,w;
		scanf("%d %d",&h,&w);
		candles.PB(candle(h,w));
	} sort(ALL(candles));
	printf("%d\n",solve());
	exit(0);
}
