#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)

int n,k,q;
int a[100000];

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d %d %d",&n,&k,&q);
	rep(i,0,n) scanf("%d",&a[i]);
	rep(i,0,q) {
		int index; scanf("%d",&index);
		index=(n-k%n+index%n)%n;
		printf("%d\n",a[index]);
	}
	exit(0);
}
