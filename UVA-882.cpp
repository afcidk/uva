#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 0x7ffffff
using namespace std;

int dfs(int mail, int L, int R);
int dp[15][105][105];
int last;

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		memset(dp, 0, sizeof(dp));

		int a, b;
		scanf("%d%d", &a, &b);
		last=b;

		printf("%d\n",dfs(a,1,b));
	}
	return 0;
}

int dfs(int mail, int L, int R){

	if(R==last && L==R)	return R;
	if(L==R)	return 0;
	if(mail == 0|| L>R)	return INF;
	if(dp[mail][L][R])	return dp[mail][L][R];

	int ans=INF;
	for(int i=L; i<=R; ++i){
		int state=i+max(dfs(mail-1,L,i),dfs(mail,i+1,R));
		ans=min(ans,state);
		dp[mail][L][R]=ans;
	}
	return ans;
}


