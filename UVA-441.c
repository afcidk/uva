#include<stdio.h>
#include<string.h>

int num[15], rec[15];
int visited[15];
int len;

void backtrack(int, int);

int main() {
	int n, first=1;
	while(scanf("%d", &n)==1 && n){
		memset(visited, 0 ,sizeof(visited));
		len=n;
		int i;
		for(i=0; i<n; i++)	scanf("%d", &num[i]);

		if(!first)	printf("\n");
		first=0;
		backtrack(0, 0);
	}
	return 0;
}

void backtrack(int now, int step){
	if(step == 6){
		int i;
		printf("%d", rec[0]);
		for(i=1; i<6; i++)	printf(" %d", rec[i]);
		printf("\n");
		return ;
	}

	int i;
	for(i=now; i<len; i++){
		if(!visited[i]){
			visited[i]=1;
			rec[step]=num[i];
			backtrack(i, step+1);
			visited[i]=0;
		}
	}
}
