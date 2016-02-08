#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
#define fi first
#define se second
#define inf 1000000000

class UnionFind {
private: vi p,rank,sz;
public:
    UnionFind(int n) {
        p.assign(n,0); rank.assign(n,0); sz.assign(n,1);
        rep(i,0,n) p[i]=i;
    }
    int findSet(int i) { return (p[i]==i)?i:p[i]=findSet(p[i]); }
    int getSize(int i) {return sz[findSet(i)]; }
    bool isSameSet(int i,int j) { return findSet(i)==findSet(j); }
    void unionSet(int i,int j) {
        if(!isSameSet(i,j)) {
            int x=findSet(i),y=findSet(j);
            if(rank[x]<rank[y]) {
                p[x]=y;
                sz[y]+=sz[x];
            }
            else {
                p[y]=x;
                sz[x]+=sz[y];
                if(rank[x]==rank[y]) rank[y]++;
            }
        }
    }
};

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,q; scanf("%d %d",&n,&q);
    UnionFind uf(n);
    while(q--) {
        char c; scanf(" %c",&c);
        if(c=='M') {
            int i,j; scanf("%d %d",&i,&j); i--; j--;
            uf.unionSet(i,j);
        }
        else {
            int i; scanf("%d",&i); i--;
            printf("%d\n",uf.getSize(i));
        }
    }
    exit(0);
}
