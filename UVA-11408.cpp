#include<iostream>
#include<cstdio>
#include<vector>
#include<unistd.h>
#define MAX 5000005
using namespace std;

bool p[MAX];
int de[MAX], c[MAX];
vector<int> vec;
void build();
void deprime();

int main() {
	int a, b;
	build();
	while(scanf("%d", &a)==1 && a){
		scanf("%d", &b);
		int i, count=0;
		printf("%d\n", c[b]-c[a-1]);
	}
	return 0;
}

void build(){
	int i, j;
	for(i=0; i<MAX; ++i)	p[i]=1, de[i]=0, c[i]=0;
	p[0]=p[1]=0;
	for(i=2; i*2<MAX; ++i){
		if(p[i]){
			de[i]=i;
			for(j=i+i; j<MAX; j+=i){
				de[j]+=i;
				p[j]=0;
			}
		}
	}
	int count=0;
	for(i=2; i<MAX; ++i){
		if(p[de[i]] || p[i])	count++;
		c[i]=count;
	}
}
