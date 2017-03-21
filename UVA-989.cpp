#include<iostream>
using namespace std;

int p[9][9];
int len;

void start(int, int);
bool full();
bool fit(int, int, int);
void print_map();

int main(){
	int first=1;
	while(scanf("%d", &len)==1){
		int i, j;
		for(i=0; i<len*len; ++i)
			for(j=0; j<len*len; ++j)
				scanf("%d", &p[i][j]);

		if(!first)	printf("\n");
		first=0;

		start(0,0);
		if(full())	print_map();
		else printf("NO SOLUTION\n");
	}		
}

void start(int a, int b){
	if(full())	return;

	if(p[a][b]!=0){
		if(b+1<len*len && b<len*len-1)	start(a, b+1);
		else if(a+1<len*len && b==len*len-1)	start(a+1, 0);
		if(full())	return;
	}
	else{
		int i;
		for(i=1; i<=len*len; ++i){
			if(fit(i, a, b)){
				p[a][b]=i;
				if(b+1<len*len && b<len*len-1)	start(a, b+1);
				else if(a+1<len*len && b==len*len-1)	start(a+1, 0);
				if(full())	return;
				p[a][b]=0;
			}
		}
	}
}

bool fit(int num, int a, int b){

	int i, j;
	for(i=0; i<len*len; ++i){
		if(p[a][i]==num)	return 0;
		if(p[i][b]==num)	return 0;
	}

	for(i=a/len*len; i<a/len*len+len; i++){
		for(j=b/len*len; j<b/len*len+len; j++){
			if(p[i][j]==num)	return 0;
		}
	}

	return 1;
}

bool full(){
	int i, j;
	for(i=0; i<len*len; ++i)
		for(j=0; j<len*len; ++j)
			if(!p[i][j])	return 0;
	return 1;
}

void print_map(){
	int i, j;
	for(i=0; i<len*len; ++i){
		printf("%d", p[i][0]);
		for(j=1; j<len*len; ++j){
			printf(" %d", p[i][j]);
		}
		printf("\n");
	}
}
