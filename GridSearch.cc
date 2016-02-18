#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)

int n1,m1,n2,m2;
bool found;
int g1[1000][1000],g2[1000][1000];

void reset() {
	scanf("%d %d",&n1,&m1);
	rep(i,0,n1) rep(j,0,m1) scanf("%1d",&g1[i][j]);
	scanf("%d %d",&n2,&m2);
	rep(i,0,n2) rep(j,0,m2) scanf("%1d",&g2[i][j]);
	found=false;
}

void solve() {
	if(n1<n2||m1<m2) return;
	rep(r,0,n1-n2+1) {
		if(found) break;
		rep(c,0,m1-m2+1) {
			if(!found) {
				found=true;
				rep(i,0,n2) {
					if(!found) break;
					rep(j,0,m2) {
						if(g1[r+i][c+j]!=g2[i][j]) {
							found=false; break;
						}
					}
				}
			} else break;
		}
	}
}

void output() {
	printf("%s\n",(found)?"YES":"NO");
}

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int T; scanf("%d",&T);
	while(T--) {
		reset();
		solve();
		output();
	} exit(0);
}
