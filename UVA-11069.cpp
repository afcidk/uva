#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n;
	while(scanf("%d", &n)==1){

		int dp[100]={1,1,2};
		for(int i=3; i<=n; ++i){
			dp[i]=dp[i-2]+dp[i-3];
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}
