#include<iostream>
#include<cstdio>
#define MAX 3000
#define INF 0x7fffffff
using namespace std;

struct S{
	int x, y;
	int val;
}dots[MAX];

int main() {
	int x;
	scanf("%d", &x);
	while(x--){
		int n, m;
		int i, j;
		int p[MAX];

		scanf("%d%d", &n, &m);
		int a, b, c;
		for(i=0; i<m; ++i){
			scanf("%d%d%d", &a, &b, &c);
			dots[i].x=a; dots[i].y=b; dots[i].val=c;
		}
		for(i=0; i<n; ++i)	p[i]=INF;

		p[0]=0;
		for(i=0; i<n-1; ++i){
			for(j=0; j<m; ++j){
				int na=dots[j].x, nb=dots[j].y, nval=dots[j].val;
				if(p[na]==INF)	continue;
				else{
					if(p[na]+nval < p[nb])	p[nb] = p[na]+nval;
				}
			}
		}

		int inf=0;
		for(j=0; j<m; ++j){
			int na=dots[j].x, nb=dots[j].y, nval=dots[j].val;
			if(p[na]==INF)	continue;
			else{
				if(p[na]+nval < p[nb]){
					inf=1;
					break;
				}
			}
		}
		if(inf)	puts("possible");
		else puts("not possible");
	}
	return 0;
}
