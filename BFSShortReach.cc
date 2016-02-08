#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin,(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define inf 1000000000

int n,m,s;
vector<vii> AdjList;
vi dist;

void reset() {
	scanf("%d %d",&n,&m);
	AdjList.assign(n,vii(0));
	dist.assign(n,inf);
	rep(i,0,m) {
		int u,v; scanf("%d %d",&u,&v);
		u--,v--;
		AdjList[u].pb(ii(v,6));
		AdjList[v].pb(ii(u,6));
	}
	scanf("%d",&s); s--;
}

void bfs() {
	dist[s]=0;
	queue<ii> q; q.push(ii(s,0));
	while(!q.empty()) {
		ii node=q.front(); q.pop();
		int u=node.fi,d=node.se;
		if(d>dist[u]) continue;
		rep(j,0,sz(AdjList[u])) {
			ii e=AdjList[u][j];
			int v=e.fi,w=e.se;
			if(d+w<dist[v]) {
				dist[v]=d+w;
				q.push(ii(v,dist[v]));
			}
		}
	}
}

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int T; scanf("%d",&T);
	while(T--) {
		reset();
		bfs();
		int p=0;
		rep(i,0,n)
			if(i!=s) printf("%s%d",(p++==0)?"":" ",(dist[i]==inf)?-1:dist[i]);
		printf("\n");
	} exit(0);
}
