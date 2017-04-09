#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

int main() {

	int n, count=0;
	while(scanf("%d", &n)==1 && n){
		int s;
		scanf("%d", &s);
		int a, b, i;
		vector<int> dot[105];
		queue<int>	que;
		while(true){
			scanf("%d%d", &a, &b);
			if(a==0 && b==0)	break;
			
			dot[a].push_back(b);
		}

		int vertix[1000000];
		int len=0;
		for(i=0; i<1000000; ++i)	vertix[i]=1;

		vertix[s]=0;
		que.push(s);
		while(!que.empty()){

			int now=que.front();
			que.pop();

			for(int i=0; i<dot[now].size(); ++i){
				if(vertix[now]-1 < vertix[dot[now][i]]){
					que.push(dot[now][i]);
					vertix[dot[now][i]]=vertix[now]-1;
					len=min(len, vertix[now]-1);
				}
			}
		}
		for(i=0; i<105; ++i)	if(vertix[i]==len)	break;
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++count, s, -len, i);
	}
}
