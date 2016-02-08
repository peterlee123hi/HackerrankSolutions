#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define inf 1000000000

ll nC2(ll n) {
	return n*(n-1)/2;
}

ll n,m;
ll ans;
vector<vi> AdjList;
vi land;
bool visited[100010];

void reset() {
	scanf("%lld %lld",&n,&m);
	ans=0;
	AdjList.assign(n,vi(0));
	land.clear();
	memset(visited,false,sizeof visited);
	rep(i,0,m) {
		int u,v; scanf("%d %d",&u,&v);
		AdjList[u].pb(v);
		AdjList[v].pb(u);
	}
}

int bfs(int s) {
	if(visited[s]) return 0;
	int l=0;
	queue<int> q; q.push(s);
	while(!q.empty()) {
		int u=q.front(); q.pop();
		if(visited[u]) continue;
		visited[u]=true;
		l++;
		rep(i,0,sz(AdjList[u]))
			if(!visited[AdjList[u][i]])
				q.push(AdjList[u][i]);
	} return l;
}

void solve() {
	rep(i,0,n)
		if(!visited[i]) {
			//rep(j,0,n) printf("%s%d",(j==0)?"":" ",visited[j]); printf("\n");
			int l=bfs(i);
			//rep(j,0,n) printf("%s%d",(j==0)?"":" ",visited[j]); printf("\n"); printf("\n");
			if(l>1)
				land.pb(l);
		}
	ans=nC2(n);
	//rep(i,0,sz(land))
	//	printf("%s%d",(i==0)?"":" ",land[i]);
	//printf("\n");
	rep(i,0,sz(land))
		ans-=nC2(land[i]);
}

void output() {
	printf("%lld\n",ans);
}

int main() {
	reset();
	solve();
	output();
	exit(0);
}