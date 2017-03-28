#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<unistd.h>
#include<algorithm>
#define MAX 1000000
using namespace std;

int num[MAX], visited[MAX];
int req, n;
int fail;
vector<vector<int>> rec_dup[MAX];
vector<int> rec;
void backtrack(int, int);
bool same(vector<int>, vector<int>);
void print_rec();

int main() {
	while(scanf("%d%d", &req, &n)==2 && (req||n)){
		fail=1;
		rec.clear();
		memset(visited, 0, sizeof(visited));
		
		int i, j;
		for(i=0; i<n; ++i){
			rec_dup[i].clear();
			scanf("%d", &num[i]);
		}

		printf("Sums of %d:\n", req);
		backtrack(0, 0);
		if(fail)	printf("NONE\n");

		int printed=0;
	}
	return 0;
}

void backtrack(int pos, int now){
	if(now == req){
		int now_len = rec.size();
		if(rec_dup[now_len].empty()){ //catch duplicate
			rec_dup[now_len].push_back(rec);
			print_rec();
		}
		else{
			int i;
			int duplicate=0;
			for(i=0; i<rec_dup[now_len].size(); ++i){
				if(same(rec, rec_dup[now_len][i])){
					duplicate=1;
					return ;
				}
			}
			if(!duplicate){
				rec_dup[now_len].push_back(rec);
				print_rec();
			}
		}
		return ;
	}

	int i;
	for(i=pos; i<n; ++i){
		if(!visited[i]){
			visited[i]=1;

			rec.push_back(num[i]);
			backtrack(i, now+num[i]);
			rec.pop_back();

			visited[i]=0;
		}
	}
}

void print_rec(){
	fail=0;
	int i;
	printf("%d", rec[0]);
	for(i=1; i<rec.size(); ++i)	printf("+%d", rec[i]);
	printf("\n");
}

bool same(vector<int> a, vector<int> b){
	int i;
	for(i=0; i<a.size(); ++i){
		if(a[i]!=b[i])	return false;
	}
	return true;
}
