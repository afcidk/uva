#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 100005
using namespace std;

inline void fail(char*, int*);

int main() {
	char s[MAX];
	while(scanf("%s", s) == 1){
		
		char rev[MAX];
		int pi[MAX];
		int i, j, len=strlen(s);
		for(i=0, j=len-1; i<len; ++i, --j)	rev[i]=s[j];

		fail(rev, pi);
		
		/**match**/
		int cur_pos=-1;
		for(i=0; i<len; ++i){
			
			while(~cur_pos && s[i]!=rev[cur_pos+1])	cur_pos = pi[cur_pos];
			if(s[i] == rev[cur_pos+1])	cur_pos++;
		}
		printf("%s", s);
		for(i=cur_pos+1; i<len; ++i)	printf("%c", rev[i]);
		printf("\n");

	}
	return 0;
}

inline void fail(char *s, int *pi){
	int len = strlen(s);

	int i, cur_pos=-1;
	pi[0]=-1;
	for(i=1; i<len; ++i){

		while(~cur_pos && s[i]!=s[cur_pos+1])
			cur_pos = pi[cur_pos];
		if(s[i]==s[cur_pos+1])	cur_pos++;
		pi[i] = cur_pos;
	}
}

