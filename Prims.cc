#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define FORD(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define clr(x) memset((x),0,sizeof(x))
#define fi first
#define se second
const int INF=1<<29;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n,m,s,weight=0;
vvii AdjList;

void input() {
    scanf("%d %d",&n,&m);
    AdjList.assign(n,vii(0));
    REP(i,m) {
        int u,v,w; scanf("%d %d %d",&u,&v,&w); u--; v--;
        AdjList[u].pb(ii(v,w));
        AdjList[v].pb(ii(u,w));
    }
    scanf("%d",&s); s--;
}

void solve() {
    vector<bool> taken(n);
    priority_queue< ii,vii,greater<ii> > pq;
    pq.push(ii(0,s));
    while(!pq.empty()) {
        ii state=pq.top(); pq.pop();
        int u=state.se,d=state.fi;
        if(taken[u]) continue;
        taken[u]=true;
        weight+=d;
        REP(j,sz(AdjList[u])) {
            ii e=AdjList[u][j];
            int v=e.fi,w=e.se;
            pq.push(ii(w,v));
        }
    }
}

void output() {
    printf("%d\n",weight);
}

int main() {
    input();
    solve();
    output();
    return 0;
}

