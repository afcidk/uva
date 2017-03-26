#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct S{
	int x, y, z;

	bool operator< (const struct S &t) const{
		if(x==t.x &&y==t.y)	return z>t.z;
		else if(x==t.x)		return y>t.y;
		return x>t.x;
	}
}tower[200];
bool smaller(int, int);

int main() {
	int n, count=0;
	while(scanf("%d", &n)==1 && n){
		int i, j;
		int a, b, c;
		int len=n*6;
		for(i=0; i<len; i+=6){
			scanf("%d%d%d", &a, &b, &c);
			tower[i].x=a; tower[i].y=b; tower[i].z=c;
			tower[i+1].x=a; tower[i+1].y=c; tower[i+1].z=b;
			tower[i+2].x=b; tower[i+2].y=a; tower[i+2].z=c;
			tower[i+3].x=b; tower[i+3].y=c; tower[i+3].z=a;
			tower[i+4].x=c; tower[i+4].y=b; tower[i+4].z=a;
			tower[i+5].x=c; tower[i+5].y=a; tower[i+5].z=b;
		}
		sort(tower, tower+len);

		int p[200], ma=-1;
		for(i=0; i<len; ++i){
			p[i]=tower[i].z;
			for(j=0; j<i; ++j){
				if(smaller(i, j)){ //a & b smaller(i,j)
					p[i] = max(p[i], tower[i].z+p[j]);
					ma = max(ma, p[i]);
				}
			}
		}
		printf("Case %d: maximum height = %d\n", ++count, ma);
	}
	return 0;
}

bool smaller(int i, int j){
	return tower[i].x<tower[j].x && tower[i].y<tower[j].y;
}
