#include<stdio.h>
#define MAX 500005

int num[MAX], buf[MAX];
long long int count;

void divide(int, int);
void merge(int, int, int);

int main() {
	int n;
	while(scanf("%d", &n)==1 && n){
		count=0;
		int i;
		for(i=0; i<n; i++)
			scanf("%d", &num[i]);
	
		divide(0, n-1);
		printf("%lld\n", count);
	}
	return 0;
}

void divide(int left, int right){
	if(left == right)	return ;

	int mid=(left+right)/2;
	divide(left, mid);
	divide(mid+1, right);
	merge(left, mid, right);
}

void merge(int left, int mid ,int right){
	int l=left, r=mid+1;
	int pos = -1;
	while(l<=mid && r<=right){
		if(num[l]<=num[r])	buf[++pos]=num[l++];
		if(num[r]<num[l]){
			buf[++pos]=num[r++];
			count+=mid-l+1;
		}
	}

	while(l<=mid)	buf[++pos]=num[l++];
	while(r<=right){
		buf[++pos]=num[r++];
		count+=mid-l+1;
	}

	int i;
	for(i=left; i<=right; i++)
		num[i]=buf[i-left];
}
