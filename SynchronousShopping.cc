#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORD(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define clr(x) memset((x),0,sizeof(x))
#define fi first
#define se second
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
/////////////////////////////////////////////////////////////////////

int n, m, k, ans;
vector<vii> AdjList;
int types[1050], dist[1050][1050];

void input() {
    cin >> n >> m >> k;
    AdjList.assign(n, vii(0));
    REP(i, n) {
        int num_types, type = 0;
        cin >> num_types;
        REP(j, num_types) {
            int x;
            cin >> x;
            x--;
            type |= (1 << x);
        }
        types[i] = type;
    }
    REP(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        AdjList[u].pb(mp(v, w));
        AdjList[v].pb(mp(u, w));
    }
}

void output() {
    cout << ans << endl;
}

/* BEGIN SOLUTION */

void solve() {
    REP(i, n) {
        REP(j, 1050) {
            dist[i][j] = INF;
        }
    }
    
    dist[0][types[0]] = 0;
    priority_queue< iii, vector< iii >, greater<iii> > pq;
    pq.push(mp(0, ii(0, types[0])));
    while(!pq.empty()) {
        iii state = pq.top(); pq.pop();
        int u = state.se.fi, collected = state.se.se, d = state.fi;
        if(d > dist[u][collected]) continue;
        REP(j, sz(AdjList[u])) {
            ii e = AdjList[u][j];
            int v = e.fi, w = e.se, collect = collected | types[v];
            if(dist[v][collect] > d + w) {
                dist[v][collect] = d + w;
                pq.push(mp(dist[v][collect], ii(v, collect)));
            }
        }
    }
    ans = INF;
    REP(i, 1 << k) {
        REP(j, 1 << k) {
            if((i | j) == ((1 << k) - 1)) {
                ans = min(ans, max(dist[n - 1][i], dist[n - 1][j]));
            }
        }
    }
}

/* END SOLUTION */

int main() {
    input();
    solve();
    output();
    return 0;
}

