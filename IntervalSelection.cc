#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
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

int memo[1010][1010];

int n;
vii intervals;
int after[1010];
bool overlap[1010][1010];

void reset() {
	memset(memo,-1,sizeof memo);

	scanf("%d",&n);
	intervals.clear();
	rep(i,0,n) {
		int a,b; scanf("%d %d",&a,&b);
		intervals.pb(ii(a,b));
	}
	sort(all(intervals));
	memset(after,-1,sizeof after);
	memset(overlap,false,sizeof overlap);
	rep(i,0,n) {
		rep(j,i+1,n) {
			if(after[i]==-1&&intervals[i].se<intervals[j].fi)
				after[i]=j;
			overlap[i][j]=overlap[j][i]=
				intervals[i].se>=intervals[j].fi;
		}
	}

	//DEBUG
	//rep(i,0,n) printf("(%d,%d) ",intervals[i].fi,intervals[i].se); printf("\n");
	//rep(i,0,n) printf("%d ",after[i]); printf("\n");
}

int backtrack(int last, int cur) {
	if(cur==n||cur==-1) return 0;

	int ans;
	bool m=false;
	if(last!=-1) {
		ans=memo[last][cur];
		m=true;
		if(ans!=-1) return ans;
	} else
		ans=0;

	if(last!=-1&&overlap[last][cur]) {
		int maxEnd=last;
		int minEnd=cur;
		if(intervals[cur].se>intervals[last].se) maxEnd=cur,minEnd=last;
		ans=max(ans,1+backtrack(maxEnd,after[minEnd]));
	}
	else
		ans=max(ans,1+backtrack(cur,cur+1));
	ans=max(ans,backtrack(last,cur+1));
	if(m) memo[last][cur]=ans;
	return ans;
}

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int T; scanf("%d",&T);
	while(T--) {
		reset();
		printf("%d\n",backtrack(-1,0));
	}
}
