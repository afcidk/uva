#include<iostream>
#include<cstdio>
#define MAX 600
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	while(n--){
		int book[MAX];
		int num, divide;
		scanf("%d%d", &num, &divide);
		
		int i;
		long long int left=0, right=0;
		for(i=0; i<num; ++i){
			scanf("%d", &book[i]);
			left=left>book[i]?left:book[i];
			right+=book[i];
		}

		while(left<right){

			int mid=(left+right)/2;
			long long int count=0, sum=0;
			for(i=0; i<num; ++i){
				sum+=book[i];

				if(sum>mid){
					sum=book[i];
					count++;
				}
				else if(sum == mid){
					sum=0;
					count++;
				}
			}
			if(sum>0)	count++;

			if(count>divide)	left=mid+1;
			else right=mid;
		}

		int rec[MAX], pos=-1, tn=num;
		long long int now=0;
		for(i=num-1; i>=0; --i){
			now+=book[i];
			tn--;
			if(now > left){
				now = book[i];
				divide--;
				rec[++pos] = i+1;
			}
			
			if(tn+1 == divide){
				rec[++pos] = i;
				break;
			}

		}

		int next=pos;
		for(i=0; i<tn; ++i){
			printf("%d / ", book[i]);
			next=pos-1;
		}
		for(i=tn; i<num-1; ++i){
			if(i == rec[next]){
				if(rec[next]!=0)	printf("/ ");
				next--;
			}
			printf("%d ", book[i]);
		}
		if(num-1 == rec[next] && rec[next]!=0)	printf("/ ");
		printf("%d\n", book[num-1]);

	}
	return 0;
}
