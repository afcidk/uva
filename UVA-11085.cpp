#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<unistd.h>
using namespace std;

int board[8][8], mi;
int now_queen[8];
int origin[8];
int first=1;
vector<int> vec[8];
int success();
void print_board();
void backtrack(int, int);

int main() {
	int x;
	int count=0;
	board[0][0]=board[0][1]=board[0][2]=board[0][3]=board[0][4]=board[0][5]=board[0][6]=board[0][7]=1;
	backtrack(0, 0);

	while(scanf("%d", &x)==1){
		mi = 0xffffff;
		origin[0]=x-1;

		int i, j;
		for(i=1; i<8; ++i)	{
			scanf("%d", &x);
			origin[i]=x-1;
		}

		for(j=0; j<vec[0].size(); ++j){
			int now=0;
			for(i=0; i<8; ++i){
				if(origin[i]!=vec[i][j])	now++;
			}
			mi=min(mi, now);
		}

		printf("Case %d: %d\n", ++count, mi);
	}
	return 0;
}

void backtrack(int i_ind, int step){

	if(success()){
		int i;
		for(i=0; i<8; ++i){
			vec[i].push_back(now_queen[i]);
		}
		return ;
	}
	if(i_ind==8)	return ;

	int i;
	board[origin[i_ind]][i_ind]=0;
	for(i=0; i<8; ++i){
		int add_step;
		if(i == origin[i_ind])	add_step=0;
		else add_step=1;

		board[i][i_ind]=1;
		now_queen[i_ind]=i;

		backtrack(i_ind+1, step+add_step);
		board[i][i_ind]=0;
	}
	board[origin[i_ind]][i_ind]=1;
}

void print_board(){
	int i, j;
	for(i=0; i<8; ++i){
		for(j=0; j<8 ;++j){
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int success() {
	int i, j;
	for(i=0; i<8; ++i){
		int x=now_queen[i], y=i;

		for(j=0; j<8 ;++j){
			if(j!=i && board[x][j]!=0)	return 0;
		}

		int startx=x-min(x, y), starty=y-min(x, y);
		while(startx<8 && starty<8){
			if(startx!=x && starty!=y && board[startx][starty]!=0)	return 0;
			startx++;starty++;
		}

		startx=x+min(7-x, y), starty=y-min(7-x, y);
		while(startx>=0 && starty<8){
			if(startx!=x && starty!=y && board[startx][starty]!=0)	return 0;
			startx--;starty++;
		}
	}
	return 1;
}
