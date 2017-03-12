#include<iostream>
#include<cstdio>
#define MAX 1005
using namespace std;

int num[MAX], buf[MAX];
int count;
void divide(int, int);
void merge(int, int, int);

int main() {
	int n;
	while(scanf("%d", &n)==1){
		count=0;
		int i;
		for(i=0; i<n; i++)	scanf("%d", &num[i]);

		divide(0, n-1);
		printf("Minimum exchange operations : %d\n", count);
	}
}

void divide(int left, int right){
	if(left==right)	return ;
	
	int middle=(left+right)/2;
	divide(left, middle);
	divide(middle+1, right);
	merge(left, middle, right);
}

void merge(int left, int middle, int right){
	int l=left, r=middle+1, pos=-1;
	while(l<=middle&&r<=right){
		if(num[l]<=num[r])	buf[++pos]=num[l++];
		if(num[r]<num[l]){
			buf[++pos]=num[r++];
			count += middle-l+1;
		}
	}

	while(l<=middle)	buf[++pos]=num[l++];
	while(r<=right){
		buf[++pos]=num[r++];
		count += middle-l+1;
	}

	int i;
	for(i=left; i<=right; i++){
		num[i]=buf[i-left];
	}
}
