#include <iostream>
#include <cstdio>
#define MAX 100005
using namespace std;

struct Line{
	double x0,y0;
	double x1,y1;
}line[MAX];

double cross(double x0,double y0,double x1,double y1,double x2,double y2);
//bool inside(int x,int a1,int a2,int y);

int main() {

	int n;
	while(scanf("%d", &n)==1 && n){

		int top[MAX]={0};
		for(int i=0; i<n; ++i){
			top[i]=1;
//			top.push_back(i);

			scanf("%lf%lf%lf%lf", &line[i].x0,&line[i].y0,&line[i].x1,&line[i].y1);
			for(int j=i-1; j>=0; --j){

				if(!top[j])	continue;
				double crossLeft=cross(line[i].x0,line[i].y0,line[i].x1,line[i].y1,line[j].x0,line[j].y0);
				double crossRight=cross(line[i].x0,line[i].y0,line[i].x1,line[i].y1,line[j].x1,line[j].y1);

				double fcrossLeft=cross(line[j].x0,line[j].y0,line[j].x1,line[j].y1,line[i].x0,line[i].y0);
				double fcrossRight=cross(line[j].x0,line[j].y0,line[j].x1,line[j].y1,line[i].x1,line[i].y1);

				if(crossLeft*crossRight<0 && fcrossLeft*fcrossRight<0){
					top[j]=0;
				}
/*				else if((fcrossLeft==0 || fcrossRight==0) && inside() && inside()){
					top.erase(top.find(j));
				}*/
			}
		}

		int i;
		for(i=0; i<n; ++i)	
			if(top[i]){
				printf("Top sticks: %d", i+1);
				break;
			}
		for(++i; i<=n; ++i){
			if(top[i]){
				printf(", %d", i+1);
			}
		}
		puts(".");
	}
	return 0;
}

double cross(double x0,double y0,double x1,double y1,double x2,double y2){
	return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}
