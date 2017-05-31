#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct S{
	double x, y;

	bool operator< (const struct S &t) const{
		if(x==t.x)	return y<t.y;
		return x<t.x;
	}
};

double cross(double x0,double y0,double x1,double y1,double x2,double y2){
	return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}

int main() {

	int n;
	int cc=0;
	while(scanf("%d", &n)==1 && n){

		vector<struct S> vec;
		vector<int> edgeDown, edgeUp;
		double a, b;
		for(int i=0;i<n; ++i){
			scanf("%lf%lf", &a, &b);
			vec.push_back({a,b});
		}

		sort(vec.begin(), vec.end());

		edgeDown.push_back(0);
		edgeUp.push_back(n-1);
		if(n>=2){
			edgeDown.push_back(1);
			for(int i=2; i<n; ++i){
	
				int past=edgeDown[edgeDown.size()-1], ppast=edgeDown[edgeDown.size()-2];
				
				double cr=cross(vec[past].x,vec[past].y,vec[ppast].x,vec[ppast].y,vec[i].x,vec[i].y);
				while(cr<0 && edgeDown.size()>=2){
					edgeDown.pop_back();
					past=edgeDown[edgeDown.size()-1], ppast=edgeDown[edgeDown.size()-2];
					cr=cross(vec[past].x,vec[past].y,vec[ppast].x,vec[ppast].y,vec[i].x,vec[i].y);
	
				}
	
				edgeDown.push_back(i);
			}

			edgeUp.push_back(n-2);
			for(int i=n-3;i>=0; --i){
	
					int past=edgeUp[edgeUp.size()-1], ppast=edgeUp[edgeUp.size()-2];
					
					double cr=cross(vec[past].x,vec[past].y,vec[ppast].x,vec[ppast].y,vec[i].x,vec[i].y);
					while(cr<0 && edgeUp.size()>=2){
						edgeUp.pop_back();
						past=edgeUp[edgeUp.size()-1], ppast=edgeUp[edgeUp.size()-2];
						cr=cross(vec[past].x,vec[past].y,vec[ppast].x,vec[ppast].y,vec[i].x,vec[i].y);
		
					}
		
					edgeUp.push_back(i);
			}
		}
		else	edgeUp.push_back(n-1);

		if(cc)	puts("");
		double ans=0;
		for(int i=1; i<edgeDown.size(); ++i){
			ans += sqrt(pow(vec[edgeDown[i]].x-vec[edgeDown[i-1]].x,2)+ pow(vec[edgeDown[i]].y-vec[edgeDown[i-1]].y,2));
		}
		for(int i=1; i<edgeUp.size(); ++i){
			ans += sqrt(pow(vec[edgeUp[i]].x-vec[edgeUp[i-1]].x,2)+ pow(vec[edgeUp[i]].y-vec[edgeUp[i-1]].y,2));
		}
		printf("Region #%d:\n", ++cc);
		printf("(%.1lf,%.1lf)", vec[edgeDown[0]].x, vec[edgeDown[0]].y);
		for(int i=1; i<edgeDown.size(); ++i){
			printf("-(%.1lf,%.1lf)", vec[edgeDown[i]].x, vec[edgeDown[i]].y);
		}
		for(int i=1; i<edgeUp.size(); ++i){
			printf("-(%.1lf,%.1lf)", vec[edgeUp[i]].x, vec[edgeUp[i]].y);
		}
		puts("");
		printf("Perimeter length = %.2lf\n", ans);
	}
	return 0;
}
