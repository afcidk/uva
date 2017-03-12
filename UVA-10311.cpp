#include<cstdio>
#include<vector>
#include<cstring>
#define MAX 100000000
using namespace std;

int	p[MAX+1];
vector<int> vec;
void build();
int find(int);
int isPrime(int);

int main() {
	int n;
	build();
	while(scanf("%d", &n)==1){
		if(n==2||n==3){
			printf("%d is not the sum of two primes!\n", n);
			continue;
		}
		if(n%2==1){
			if(!isPrime(n)){
				printf("%d is not the sum of two primes!\n", n);
			}
			else
				printf("%d is the sum of %d and %d.\n", n, 2, n-2);
		}
		else{
			int a, b, flag=0;
			int mid = find(n/2);
			while(mid>=0){
				a=vec[mid], b=n-vec[mid];
				if(p[a] && p[b] && a!=b){
					flag=1;
					break;
				}
				mid--;
			}
			if(flag)	printf("%d is the sum of %d and %d.\n", n, a, b);
			else printf("%d is not the sum of two primes!\n", n);
		}
	}
	return 0;
}

void build(){
	int i, j;
	for(i=0;i<MAX; i++)	p[i]=true;
	p[0]=p[1]=false;
	for(i=2; i*i<=MAX; i++){
		if(p[i]){
			for(j=i*i; j<MAX; j+=i)	p[j]=false;
		}
	}

	int count=-1;
	for(i=2; i<MAX; i++)	
		if(p[i]){
			vec.push_back(i);
			p[i]=++count;
		}
}

int isPrime(int x){
	if(x==3)	return 1;
	if(x>=3 && p[x-2]!=0)	return 1;
	return 0;
}

int find(int x){
	int lenl=0;
	while(x-lenl>0 && p[x-lenl]==0){
		lenl++;
	}
	return p[x-lenl];
}
