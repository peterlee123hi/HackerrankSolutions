#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define sz(x) ((int)(x).size())

int n,k;
int a[2000];
int ans;

void input() {
    scanf("%d %d",&n,&k);
    rep(i,0,n) scanf("%d",&a[i]);
    ans=-1;
}

void backtrack(int i,int sum) {
    if(sum>k||i>=n) return;
    ans=max(ans,sum);
    backtrack(i,sum+a[i]);
    backtrack(i+1,sum);
}

void solve() {
    backtrack(0,0);
}

void output() {
    printf("%d\n",ans);
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T; scanf("%d",&T);
    while(T--) {
        input();
        solve();
        output();
    } exit(0);
}
