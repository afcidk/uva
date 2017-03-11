#include<stdio.h>
#include<string.h>
#define MAX 2000000

int p[MAX];
int vec[MAX], size;
long long int n;
void build();

long long int get_num(){
	char ch;
	int neg = 1;
	long long int ret=0;
	while((ch=getchar())!='\n'){
		if(ch == '-')	neg = -1;
		else{
			ret = ret*10+ch-'0';
		}
	}
	return ret*neg;
}

int main() {
	build();
	while(1){
		n=get_num();
		if(n == -1)	break;

		int now = 0;
		while(n!=1){
			while(n%vec[now] == 0){
				printf("    %d\n", vec[now]);
				n/=vec[now];
			}
			now++;
			if(now>size)	break;
		}
		if(n!=1)	printf("    %lld\n", n);
		printf("\n");
	}
	return 0;
}

void build(){
	memset(p, 1, sizeof(p));
	memset(vec, 0, sizeof(vec));
	int i, j;
	p[0]=p[1]=0;
	for(i = 2; i*i<=MAX; i++){
		if(p[i]){
			for(j = i*i; j<MAX; j+=i){
				p[j] = 0;
			}
		}
	}

	size = -1;
	for(i = 2; i<MAX; i++){
		if(p[i])	vec[++size] = i;
	}
}
