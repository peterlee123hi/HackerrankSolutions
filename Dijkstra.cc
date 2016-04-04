#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

int n,m,s;
int dist[3000];
vector<vii> AdjList;

void read() {
    scanf("%d %d",&n,&m);
    AdjList.assign(n,vii(0));
    rep(i,0,n)
        dist[i]=-1;
    rep(i,0,m) {
        int u,v,w; scanf("%d %d %d",&u,&v,&w);
        u--; v--;
        AdjList[u].pb(ii(v,w));
        AdjList[v].pb(ii(u,w));
    }
    scanf("%d",&s);
    s--;
}

void sssp() {
    dist[s]=0;
    priority_queue< ii,vii,greater<ii> > pq;
    pq.push(ii(s,0));
    while(!pq.empty()) {
        ii state=pq.top(); pq.pop();
        int u=state.fi,d=state.se;
        if(d>dist[u]) continue;
        rep(j,0,sz(AdjList[u])) {
            ii e=AdjList[u][j];
            int v=e.fi,w=e.se;
            if(dist[v]==-1||dist[u]+w<dist[v])
                dist[v]=dist[u]+w,pq.push(ii(v,dist[v]));
        }
    }
}

void output() {
    bool first=true;
    rep(u,0,n) {
        if(u==s) continue;
        if(first) first=false;
        else printf(" ");
        printf("%d",dist[u]);
    } printf("\n");
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        read();
        sssp();
        output();
    } exit(0);
}
