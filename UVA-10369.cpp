#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

struct S{
	double dis;
	int now, nxt;
	bool operator< (const struct S &t) const{
		return dis<t.dis;
	}
}path[505*505];
int num_path, p[505];
double x[505], y[505];

int find(int x);
void init(){
	num_path = 0;
	for(int i=0; i<505; ++i){
		x[i]=y[i]=0;
		p[i] = i;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--){
		init();

		int s, t;
		scanf("%d%d", &s, &t);

		for(int i=0; i<t; ++i){
			scanf("%lf%lf", &x[i], &y[i]);
			for(int j=i-1; j>=0; --j){
				path[num_path].dis = sqrt(pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2));
				path[num_path].now = i;
				path[num_path].nxt = j;
				++num_path;
			}
		}

		sort(path, path+num_path);

		int add_path=0;
		double sum_dis=0;
		for(int i=0; i<num_path; ++i){

			int xx = find(path[i].now);
			int yy = find(path[i].nxt);

			if(xx!=yy){
				++add_path;
				p[xx]=yy;
				sum_dis = path[i].dis;
				if(add_path == t-s)	break;
			}
		}
		
		printf("%.2lf\n", sum_dis);
	}
	return 0;
}

int find(int x){
	if(x == p[x])	return x;
	return p[x] = find(p[x]);
}
