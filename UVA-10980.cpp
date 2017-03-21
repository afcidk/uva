#include<iostream>
#include<cstdio>
#include<sstream>
#include<cstring>
using namespace std;

int vol[25];
double price[25];
double min_price[1011];

int main() {
	double unit;
	int types;
	int count=0;
	while(scanf("%lf %d", &unit, &types)==2){
		memset(min_price, 0, sizeof(min_price));
		int i, j, k;

		vol[1]=1;
		price[1]=unit;
		for(i=1; i<=1010; ++i)	min_price[i] = unit*i;

		for(i=2; i<=types+1; ++i){
			scanf("%d %lf", &vol[i], &price[i]);

			for(j=i-1; j>=1; --j){
				if(vol[i] >= vol[j] && price[i]<price[j])	price[j]=price[i];
			}

		}
		getchar();

		string s;
		int tar;
		getline(cin, s);
		stringstream ss(s);
		printf("Case %d:\n", ++count);
		while(ss>>tar){
			for(k=1; k<=types+1; ++k){
				for(j=vol[k]; j<=1010; ++j){
					min_price[j]=min(min_price[j],min_price[j-vol[k]]+price[k]);
				}
			}

			for(k=tar; k<=1010; ++k){
				min_price[tar]=min(min_price[tar], min_price[k]);
			}
			printf("Buy %d for $%.2lf\n", tar, min_price[tar]);
		}
	}
	return 0;
}
