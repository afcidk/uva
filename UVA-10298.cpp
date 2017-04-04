#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 1000005
using namespace std;

bool match(char*, int);

int main() {
	char s[MAX];
	while(scanf("%s", s)==1){
		if(strcmp(s, ".") == 0)	break;
		int i, len=strlen(s);
		
		for(i=0; i<len; ++i){
			if(len%(i+1)==0){
				if(match(s, i+1))	break;
			}
		}
		printf("%d\n", len/(i+1));
	}
}


bool match(char *s, int sub){
	int len = strlen(s);

	int i, substep = 0;
	for(i=0; i<len; ++i){

		if(s[i]!=s[substep])	return 0;
		substep++;
		if(substep == sub)	substep = 0;
	}
	return 1;
}
