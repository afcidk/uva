#include <iostream>
#include <cstdio>
#define MAX 3000
using namespace std;

int ans[1005];

void build(){
	int rec[MAX+1]={1};
	ans[0]=0;
	for(int i=1; i<=1000; ++i){
		for(int j=0; j<MAX; ++j)	rec[j]*=i;
		for(int j=0; j<MAX; ++j){
			rec[j+1] += rec[j]/10;
			rec[j] %= 10;
			ans[i] += rec[j];
		}
	}
}

int main() {
	build();
	int n;
	while(scanf("%d", &n)==1){
		printf("%d\n", ans[n]);
	}
	return 0;
}
