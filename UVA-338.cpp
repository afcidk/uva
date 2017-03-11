#include<iostream>
#include<cstdio>
#include<cstring>
#include<sstream>
#define M 200
using namespace std;

int blocks[20];
int last_size;

int all_zero(int*);
int add_up(int*);
void print(int*, int, int);
void print_blank(int);

int main() {
	string t;
	while(getline(cin, t)){
		string a, b="t";
		stringstream ss(t);
		ss>>a>>b;
		if(a=="0" && b=="t")	break;
		int lena=a.length(), lenb=b.length();
		int ans[M];
		int rec[lenb][M];
		int mid_printed=0;
		memset(ans, 0, sizeof(ans));
		memset(rec, 0, sizeof(rec));
		memset(blocks, 0, sizeof(blocks));

		int i, j, k, l;
		for(j = 0, l=lenb-1; j<lenb; j++, l--){
			for(i = 0, k=lena-1; i<lena; i++, k--){
				ans[i+j] += (a.at(k)-'0')*(b.at(l)-'0');
				rec[j][i] += (a.at(k)-'0')*(b.at(l)-'0');
			}
			blocks[j+1] += blocks[j]+1;
		}

		last_size = add_up(ans);
		
		if(last_size == 0)	last_size = max(lena, lenb);
		print_blank(last_size-lena);cout<<a<<endl;
		print_blank(last_size-lenb);cout<<b<<endl;
		print_blank(last_size-max(lena, lenb)); for(i = 0; i<max(lena, lenb); i++)	printf("-");printf("\n");
		for(i = 0; i<lenb; i++)//look how many middle lines will be printed
			if(!all_zero(rec[i]))	mid_printed++;


		if(!all_zero(ans) && mid_printed>1){ // if middle output line >1 && the final answer is not zero(all 0 for the middle output)
			for(i = 0; i<lenb; i++){
				int len=add_up(rec[i]);
				if(!all_zero(rec[i])){ //ignore the line which is all zero
					print_blank(last_size-blocks[i]-len);	print(rec[i], i, mid_printed);
				}
			}
		}

		print(ans, -1, mid_printed);
		printf("\n");
	}
	return 0;
}

int add_up(int *s){
	int i, ret=-1;
	for(i = 0; i<M-1; i++){
		if(s[i]!=0)	ret=i;
		s[i+1] +=s[i]/10;
		s[i]%=10;
	}
	return ret+1;
}
void print(int *s, int mode, int mid){
	int i;
	for(i=M-1; i>0&&!s[i]; i--);
	if(mode == -1 && !all_zero(s) && mid>1){
		int j;
		for(j = 0; j<=i; j++)	printf("-");
		printf("\n");
	}

	if(i==0 && mode==-1)	print_blank(last_size-1);
	for(;i>=0; i--)	printf("%d", s[i]);

	printf("\n");
}
int all_zero(int *x){
	int i;
	for(i=M-1; i>=0; i--)
		if(x[i]!=0)	return 0;
	return 1;
}
void print_blank(int x){
	int i;
	for(i=0; i<x; i++)	printf(" ");
}
