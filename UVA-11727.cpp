#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int n, count = 0;
	scanf("%d", &n);
	while(n--){
		int num[3];
		scanf("%d%d%d", &num[0], &num[1], &num[2]);
		sort(num, num+3);
		printf("Case %d: %d\n", ++count, num[1]);
	}
	return 0;
}
