#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int n;
	int num[10005], pos=-1;
	while(scanf("%d", &n)==1){
		num[++pos]=n;
		sort(num, num+pos+1);
		if((pos+1)%2==1)	printf("%d\n", num[pos/2]);
		else	printf("%d\n", (num[pos/2+1]+num[pos/2])/2);
	}
	return 0;
}
