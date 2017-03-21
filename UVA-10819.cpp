#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	int m, n;
	while(scanf("%d%d", &m ,&n)==2){
		m+=200;
		int cost[100], val[100]={};
		int rec[10205]={0}, money[10205]={0};
		int ma, marec;
		int i, j;
		for(i=0; i<n; i++){
			scanf("%d", &cost[i]);
			scanf("%d", &val[i]);
		}
		ma=-1;
		marec=-1;

		for(j=0; j<n; j++){
			for(i=m; i>=cost[j]; i--){
				if(i-cost[j]==0 || money[i-cost[j]]){
					if(money[i-cost[j]]+val[j]>money[i]){
						money[i]=money[i-cost[j]]+val[j];
						if(ma<money[i]){
							ma = money[i];
							marec = i;
						}
					}
				}
			}
		}
		if(marec<=2000){
			ma=-1;
			for(i=2001; i<=m; i++)	ma = max(ma, money[i]);
			for(i=m-200; i>=0; i--)	ma=max(ma, money[i]);
		}
		printf("%d\n", ma);

	}
	return 0;
}
