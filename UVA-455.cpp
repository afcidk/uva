#include<iostream>
#include<cstdio>
#include<cstring>
#include<unistd.h>
#define MAX 100
using namespace std;

void subcopy(char*, const char*, int );
bool match(char*, char*);

int main() {
	int n;
	scanf("%d", &n);
	getchar();

	while(n--){
		getchar();
		char a[MAX], b[MAX];
		scanf("%s", a);
		int len = strlen(a), i;
		int half_len = len/2;
		for(i=0; i<len; ++i){
			if(len%(i+1)!=0)	continue;
			subcopy(b, a, i+1);
			if(match(a, b))	break;
		}
		printf("%d\n", i+1);
		if(n)	puts("");
	}
	return 0;
}

void subcopy(char *des, const char* src, int size){
	
	int i;
	for(i=0; i<size && src[i]!='\0'; ++i){
		des[i] = src[i];
	}
	des[i] = '\0';
}

bool match(char *a, char *b){

	int lena = strlen(a), lenb = strlen(b);
	int i, step=0;
	
	for(i=0; i<lena; ++i){
		
		if(b[step]!=a[i])	return 0;
		else{
			step++;
			if(step == lenb){
				step = 0;
			}
		}
	}
	return 1;
}
