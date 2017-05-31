#include <iostream>
#include <cstdio>
#define swap(a,b) {int t;t=a;a=b;b=t;}
using namespace std;

struct Dot{
	int x, y;
}dot[6]; //line, then rectangle

struct Line{
	int x0,x1;
	int y0,y1;
}line[5];

int cross(int x0,int y0,int x1,int y1,int x2,int y2){
	return (x1-x0)*(y2-y0) - (x2-x0)*(y1-y0);
}
bool inside(int a,int x,int y,int b){
	int ma=max(a,b);
	int mi=min(a,b);
	if((mi<=x&&x<=ma)||(mi<=y&&y<=ma))	return true;
	return false;
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--){
		int n[4];
		int success=0;
		scanf("%d%d%d%d", &line[0].x0, &line[0].y0, &line[0].x1, &line[0].y1);

		for(int i=0; i<4; ++i)	scanf("%d", &n[i]);
		line[1].x0=n[0];line[1].y0=n[1];line[1].x1=n[2];line[1].y1=n[1];
		line[2].x0=n[0];line[2].y0=n[1];line[2].x1=n[0];line[2].y1=n[3];
		line[3].x0=n[2];line[3].y0=n[1];line[3].x1=n[2];line[3].y1=n[3];
		line[4].x0=n[0];line[4].y0=n[3];line[4].x1=n[2];line[4].y1=n[3];

		for(int i=1; i<5; ++i){ //line[i]
			int crossLeft=cross(line[i].x0,line[i].y0,line[i].x1,line[i].y1,line[0].x0,line[0].y0);
			int crossRight=cross(line[i].x0,line[i].y0,line[i].x1,line[i].y1,line[0].x1,line[0].y1);

			int fcrossLeft=cross(line[0].x0,line[0].y0,line[0].x1,line[0].y1,line[i].x0,line[i].y0);
			int fcrossRight=cross(line[0].x0,line[0].y0,line[0].x1,line[0].y1,line[i].x1,line[i].y1);

			if(crossLeft*crossRight<0 && fcrossLeft*fcrossRight<0){
				success=1;
				break;
			}
			if((fcrossRight==0||fcrossLeft==0) && inside(line[0].x0,line[i].x1,line[i].x0,line[0].x1) && inside(line[0].y0,line[i].y0,line[i].y1,line[0].y1)){
				success=1;
				break;
			}
		}

		if(n[0]>n[2])	swap(n[0],n[2]);
		if(n[3]>n[1])	swap(n[3],n[1]);

		int x=line[0].x0, y=line[0].y0;
		int xx=line[0].x1, yy=line[0].y1;
		if(n[0]<=x && x<=n[2] && n[3]<=y && y<=n[1])	success=1;
		if(n[0]<=xx && xx<=n[2] && n[3]<=yy && yy<=n[1])	success=1;

		if(success)	puts("T");
		else puts("F");

	}
}
