#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

vector<int> vec[105];
int dfn[105], low[105], ans;
int clk;

void dfs(int cur, int past);

int main() {
	int n;
	while(scanf("%d", &n)==1 && n){
		char ch;
		int top, x;
		ans=0;
		clk=0;
		for(int i=0; i<=n; ++i){
			vec[i].clear();dfn[i]=low[i]=0;
		}

		while(true){
			scanf("%d%c", &top, &ch);
			if(top==0)	break;
			while(true){
				scanf("%d%c", &x, &ch);
				vec[x].push_back(top);
				vec[top].push_back(x);

				if(ch=='\n')	break;
			}
		}

		dfs(1,-1);
		printf("%d\n", ans);
	}
	return 0;
}

void dfs(int cur, int past){

	dfn[cur] = low[cur] = ++clk;
	int child=0;
	int flag=0;

	for(int i=0; i<vec[cur].size(); ++i){
		
		int nxt = vec[cur][i];
		if(!dfn[nxt]){

			++child;
			dfs(nxt, cur);

			low[cur] = min(low[cur], low[nxt]);
			if(low[nxt]>=dfn[cur])	flag=1;
		}
		else if(nxt!=past){
			low[cur] = min(low[cur], dfn[nxt]);
		}
	}

	if((past==-1 && child>=2) || (past!=-1 && flag))	++ans;
}
