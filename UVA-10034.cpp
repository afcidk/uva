#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAX 105
using namespace std;

struct S{
	int now, nxt;
	double dis;

	bool operator< (const struct S &t) const{
		return dis<t.dis;
	}
}road[MAX*MAX];
int p[MAX], road_num;
double x[MAX], y[MAX];

int find(int x);
void init(){
	int road_num=0;
	for(int i=0; i<MAX; ++i)	p[i]=i;
	for(int i=0; i<MAX*MAX; ++i)	road[i].now=road[i].nxt=road[i].dis=0;
}

int main() {

	int n;
	int start=1;
	scanf("%d", &n);
	while(n--){
		init();

		int m;
		scanf("%d", &m);
		double a, b;
		for(int i=0; i<m; ++i){
			scanf("%lf%lf", &x[i], &y[i]);
			for(int j=i-1; j>=0; --j){
				road[road_num].now = i;
				road[road_num].nxt = j;
				road[road_num].dis = sqrt(pow(x[i]-x[j], 2)+pow(y[i]-y[j], 2));
				++road_num;
			}
		}

		sort(road, road+road_num);

		double ans=0;
		for(int i=0; i<road_num; ++i){

			int xx = find(road[i].now);
			int yy = find(road[i].nxt);
			if(xx!=yy){
				p[xx] = yy;
				ans+=road[i].dis;
			}
		}
		if(!start)	puts("");
		start=0;
		printf("%.2lf\n", ans);
	}
}

int find(int x){
	if(x == p[x])	return x;
	return  p[x] = find(p[x]);
}
