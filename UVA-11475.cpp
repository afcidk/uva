#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 300005
using namespace std;

void fail(char*, int*);
void revcpy(char*, const char*, int, int);
void match(char*, char*, int*);

int main() {
	char s[MAX], temp[MAX];
	int pi[MAX];
	while(scanf("%s", s)==1){

		int len=strlen(s), i;
		revcpy(temp, s, len-1, len-1);
		fail(temp, pi);
		match(s, temp, pi);
	}
	return 0;
}

void revcpy(char *des, const char *src, int begin, int size){

	int i, j;
	for(i=begin, j=0; i>=begin-size; --i, ++j)	des[j]=src[i];
	des[j]='\0';
}

void fail(char *s, int *pi){
	
	int i, cur_pos=-1;
	int len=strlen(s);
	pi[0]=-1;
	for(i=1; i<len; ++i){

		while(~cur_pos && s[i]!=s[cur_pos+1])	cur_pos=pi[cur_pos];
		if(s[i]==s[cur_pos+1])	++cur_pos;
		pi[i]=cur_pos;
	}
}

void match(char *s, char *temp, int *pi){
	
	int i, cur_pos=-1;
	int len=strlen(s);
	for(i=0; i<len; ++i){
		while(~cur_pos && s[i]!=temp[cur_pos+1]){
			cur_pos=pi[cur_pos];
		}
		if(s[i]==temp[cur_pos+1])	++cur_pos;
	}
	printf("%s", s);
	for(i=cur_pos+1; i<len; ++i)	printf("%c", temp[i]);
	printf("\n");
}
