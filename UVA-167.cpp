#include<iostream>
#include<unistd.h>
#include<cstdio>
using namespace std;

int board[8][8];
int visited[8][8];
int max_sum;
const int vx[]={1,1,1,0,0,-1,-1,-1};
const int vy[]={1,0,-1,1,-1,1,0,-1};

void backtrack(int, int, int);
void set_visited(int, int);
int in_border(int, int);
void print_map();

int main() {
	int n;
	scanf("%d", &n);
	while(n--){
		max_sum=0;
		int i, j;
		for(i=0; i<8; i++)
			for(j=0; j<8; j++)
				scanf("%d", &board[i][j]);

		backtrack(0, 0, 0);
		printf("%5d\n", max_sum);
	}
	return 0;
}

void backtrack(int now, int queen, int sum){
	if(queen == 8){
		if(max_sum < sum)	max_sum=sum;
		return ;
	}

	int x, y;
	int i;
	for(i=now; i<64; i++){
		x=i/8;y=i%8;
		if(!visited[x][y]){
			set_visited(i, 1);
			backtrack(i, queen+1, sum+board[x][y]);
			set_visited(i, -1);
		}
	}
}

void set_visited(int now, int order){
	int x=now/8, y=now%8;
	int i;

	visited[x][y]+=order;
	for(i=0; i<8; i++){
		int tx=x, ty=y;
		while(in_border(tx, vx[i]) && in_border(ty, vy[i])){
			visited[tx+vx[i]][ty+vy[i]]+=order;
			tx+=vx[i];
			ty+=vy[i];
		}
	}
}

int in_border(int a, int x){
	return (a+x<8) && (a+x>=0);
}

void print_map(){
	int i, j;
	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
