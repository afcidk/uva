#include<iostream>
#include<cstdio>
#define MAX 1000005
using namespace std;

int main() {
	int n, m;
	int num[MAX];
	while(scanf("%d%d", &n, &m)==2){
		int i;
		int left=0, right=0;
		for(i=0; i<n; ++i){
			scanf("%d", &num[i]);
			left=max(left, num[i]);
			right+=num[i];
		}

		int mid;
		while(left<right){
			mid=(left+right)/2;

			int now=0, count=0;
			for(i=0; i<n; ++i){
				now+=num[i];

				if(now>mid){
					now=num[i];
					count++;
				}
				else if(now==mid){
					now=0;
					count++;
				}
			}

			if(now>0)	count++;
			if(count>m)	left=mid+1;
			else right=mid;
		}

		printf("%d\n", left);
	}
	return 0;
}
