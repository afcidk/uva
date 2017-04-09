#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#define INF 0x7ffffff
using namespace std;

struct S{
	int x, y;
	int lat;
}p[110000];

int main() {
	/** using SPFA **/
	int N, count=0;
	scanf("%d", &N);
	while(N--){

		int n, m, S, T;
		int i, j;
		int a, b, lat;
		queue<int> que;
		vector<int> vec[110000], val[110000];
		scanf("%d%d%d%d", &n, &m, &S, &T);

		for(i=0; i<m; ++i){
			scanf("%d%d%d", &a, &b, &lat);
			vec[a].push_back(b);vec[b].push_back(a);
			val[a].push_back(lat); val[b].push_back(lat);
		}

		int vertix[20005];
		for(i=0; i<n; ++i)	vertix[i]=INF;
		
		vertix[S]=0;
		que.push(S);
		while(!que.empty()){

			int now=que.front();
			que.pop();
			for(i=0; i<vec[now].size(); ++i){
				if(vertix[now]+val[now][i] < vertix[vec[now][i]]){
					que.push(vec[now][i]);
					vertix[vec[now][i]] = vertix[now]+val[now][i];
				}
			}
		}

		printf("Case #%d: ", ++count);
		if(vertix[T]==INF)	puts("unreachable");
		else printf("%d\n", vertix[T]);
	}
}
