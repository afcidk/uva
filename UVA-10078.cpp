#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct S{
	int x,y;
	bool operator< (const struct S &t) const{
		if(x==t.x)	return y<t.y;
		return x<t.x;
	}
};

int cross(int x0,int y0,int x1,int y1,int x2,int y2){
	return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}

int main() {
	int n;
	while(scanf("%d", &n)==1 && n){
		vector<struct S> dot;
		int a, b;
		for(int i=0; i<n; ++i){
			scanf("%d%d", &a, &b);
			dot.push_back({a,b});
		}

		sort(dot.begin(), dot.end());
		vector<int> ans;
		int tmp;
		ans.push_back(0); ans.push_back(1);
		for(int i=2; i<n; ++i){
			int past=ans[ans.size()-1], ppast=ans[ans.size()-2];
			int cr=cross(dot[past].x,dot[past].y,dot[ppast].x,dot[ppast].y,dot[i].x,dot[i].y);

			while(cr<0 && ans.size()>=2){
				ans.pop_back();
				past=ans[ans.size()-1], ppast=ans[ans.size()-2];
				cr=cross(dot[past].x,dot[past].y,dot[ppast].x,dot[ppast].y,dot[i].x,dot[i].y);
			}
			ans.push_back(i);
		}
		tmp=ans.size();
		ans.push_back(n-2);
		for(int i=n-3; i>=0; --i){
			int past=ans[ans.size()-1], ppast=ans[ans.size()-2];
			int cr=cross(dot[past].x,dot[past].y,dot[ppast].x,dot[ppast].y,dot[i].x,dot[i].y);

			while(cr<0 && ans.size()>=tmp+1){
				ans.pop_back();
				past=ans[ans.size()-1], ppast=ans[ans.size()-2];
				cr=cross(dot[past].x,dot[past].y,dot[ppast].x,dot[ppast].y,dot[i].x,dot[i].y);
			}
			ans.push_back(i);
		}

		if(n+1-ans.size())	puts("Yes");
		else puts("No");
	}
	return 0;
}
