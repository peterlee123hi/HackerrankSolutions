#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define inf 1000000000

int n;
vi p,rnk;

int findSet(int i) { return (p[i]==i)?i:p[i]=findSet(p[i]); }
int findRank(int i) { return rnk[findSet(i)]; }

bool isSameSet(int i,int j) {
    return findSet(i)==findSet(j);
}

void unionSet(int i,int j) {
    if(!isSameSet(i,j)) {
        int x=findSet(i),y=findSet(j);
        if(rnk[x]<rnk[y]) {
            p[x]=y;
            rnk[y]+=rnk[x];
        } else {
            p[y]=x;
            rnk[x]+=rnk[y];
        }
    }
}

int main() {
    scanf("%d",&n);
    p.assign(2*n,0); rnk.assign(2*n,1);
    rep(i,0,2*n) p[i]=i;
    rep(i,0,n) {
        int g,b; scanf("%d %d",&g,&b); g--; b--;
        unionSet(g,b);
    }
    vi sizes(2*n);
    rep(i,0,2*n) sizes[i]=findRank(i);
    sort(all(sizes));
    int sI=0,bI=sz(sizes)-1;
    while(sI<sz(sizes)&&sizes[sI]<=1) sI++;
    if(sI==sz(sizes)) sI--;
    printf("%d %d\n",sizes[sI],sizes[bI]);
}
