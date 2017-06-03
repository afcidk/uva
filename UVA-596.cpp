#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct S{
	int x, y;
	bool operator< (const struct S &t) const{
		if(x==t.x)	return y<t.y;
		return x<t.x;
	}
	bool operator== (const struct S &t) const{
		return x==t.x && y==t.y;
	}
};

int cross(int x0,int y0,int x1,int y1,int x2,int y2){
	return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}

int main() {

	char ch[100];
	char s[100];
	vector<struct S> dot;

	scanf("%s", ch);
	getchar();
	fgets(s, 100, stdin);
	s[strlen(s)-1]='\0';
	while(scanf("%s", ch)==1){

		if(ch[0]=='P'){

			int a, b, n;
			scanf("%d", &n);
			for(int i=0; i<n; ++i){
				scanf("%d%d", &a, &b);
				dot.push_back({a,b});
			}
		}
		else if(ch[0]=='S' || ch[0]=='E'){

			sort(dot.begin(), dot.end());

			vector<int> ans;

			ans.push_back(0);
			ans.push_back(1);
			for(int i=2; i<dot.size(); ++i){

				int past=ans[ans.size()-1], ppast=ans[ans.size()-2];
				if(dot[past]==dot[i])	continue;
				int	cr = cross(dot[past].x, dot[past].y, dot[i].x, dot[i].y, dot[ppast].x, dot[ppast].y);

				while(cr<0 && ans.size()>=2){
					ans.pop_back();
					past=ans[ans.size()-1], ppast=ans[ans.size()-2];
					cr = cross(dot[past].x, dot[past].y, dot[i].x, dot[i].y, dot[ppast].x, dot[ppast].y);
				}
				ans.push_back(i);
			}

			for(int i=dot.size()-1; i>=0; --i){

				int past=ans[ans.size()-1], ppast=ans[ans.size()-2];
				if(dot[past]==dot[i])	continue;
				int	cr = cross(dot[past].x, dot[past].y, dot[i].x, dot[i].y, dot[ppast].x, dot[ppast].y);

				while(cr<0){
					ans.pop_back();
					past=ans[ans.size()-1], ppast=ans[ans.size()-2];
					cr = cross(dot[past].x, dot[past].y, dot[i].x, dot[i].y, dot[ppast].x, dot[ppast].y);
				}
				ans.push_back(i);
			}
			ans.erase(ans.end()-1);

			int maX=-0x7fffffff,miY=0x7fffffff,ind;
			for(int i=0; i<ans.size(); ++i){
				if(dot[ans[i]].x > maX){
					maX = dot[ans[i]].x;
					ind=i;
				}
				else if(dot[ans[i]].x == maX && dot[ans[i]].y < miY){
					miY = dot[ans[i]].y;
					ind=i;
				}
			}
			--ind;
			if(ind==-1)	ind=ans.size()-1;

			cout<<s<<" convex hull:"<<endl;
			for(int i=ind; i<ans.size(); ++i)	printf(" (%d,%d)", dot[ans[i]].x, dot[ans[i]].y);
			for(int i=0; i<ind; ++i)	printf(" (%d,%d)", dot[ans[i]].x, dot[ans[i]].y);
			puts("");

			dot.clear();
			if(ch[0] == 'E')	break;
			getchar();
			fgets(s, 100, stdin);
			s[strlen(s)-1]='\0';
		}
	}
	return 0;
}
