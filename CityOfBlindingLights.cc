#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define inf 1000000000

int n,m,q;
int AdjMat[500][500];

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d %d",&n,&m);
	rep(i,0,n) rep(j,0,n) AdjMat[i][j]=(i==j)?0:inf;
	rep(i,0,m) {
		int u,v,w; scanf("%d %d %d",&u,&v,&w); u--,v--;
		AdjMat[u][v]=w;
	}
	rep(k,0,n) rep(i,0,n) rep(j,0,n)
		AdjMat[i][j]=min(AdjMat[i][j],AdjMat[i][k]+AdjMat[k][j]);
	//rep(i,0,n) { rep(j,0,n) printf("%s%d",(j==0)?"":" ",AdjMat[i][j]); printf("\n"); }
	scanf("%d",&q);
	while(q--) {
		int u,v; scanf("%d %d",&u,&v); u--,v--;
		printf("%d\n",(AdjMat[u][v]==inf)?-1:AdjMat[u][v]);
	}
	exit(0);
}
