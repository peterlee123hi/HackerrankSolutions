#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)

int n,m;
char b[50][5];

int dr[]={0,-1,-1,-1,0};
int dc[]={-1,-1,0,1,1};
bool inbounds(int r,int c) { return 0<=r&&r<n&&0<=c&&c<m; }

void reset() {
	scanf("%d %d",&n,&m);
	rep(i,0,n) rep(j,0,m) scanf(" %c",&b[i][j]);
}

void printBoard() {
	rep(i,0,n) {
		rep(j,0,m) {
			printf("%s%c",(j==0)?"":" ",b[i][j]);
		} printf("\n");
	} printf("\n");
}

bool validMove(int r,int c) {
	bool blocked[5]; memset(blocked,false,sizeof blocked);
	bool valid=b[r][c]=='.';
	rep(d,1,max(r,5)) {
		if(!valid) break;
		rep(dir,0,6) {
			if(inbounds(r+dr[dir]*d,c+dc[dir]*d)&&
				!blocked[dir]&&
				b[r+dr[dir]*d][c+dc[dir]*d]=='*')
				valid=false;
			else if(inbounds(r+dr[dir]*d,c+dc[dir]*d)&&
				!blocked[dir]&&
				b[r+dr[dir]*d][c+dc[dir]*d]=='#')
				blocked[dir]=true;
		}
	} return valid;
}

int backtrack(int r,int c) {
	if(r==n) {
		return 0;
	}
	if(c==m) return backtrack(r+1,0);

	int ans=0;

	bool blocked[5]; memset(blocked,false,sizeof blocked);
	if(validMove(r,c)) {
		//printf("Move: (%d,%d)\n",r,c);
		//printBoard();
		char t=b[r][c];
		b[r][c]='*';
		ans+=1+backtrack(r,c+1); ans%=10000000;
		b[r][c]=t;
	}
	ans+=backtrack(r,c+1); ans%=10000000;
	return ans%10000000;
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T; scanf("%d",&T);
	while(T--) {
		reset();
		printf("%d\n",backtrack(0,0));
	}
}
