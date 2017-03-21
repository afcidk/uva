#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int main() {
	int n, tracks;
	int cd[30];
	while(scanf("%d%d", &n, &tracks)==2){
		int i, j;
		int add[n+1];
		vector<int> vec[n+1];
		memset(add, 0, sizeof(add));
		add[0]=1;
		for(i=0; i<tracks; i++){
			scanf("%d", &cd[i]);
		}

		for(j=0; j<tracks; j++){
			for(i=n; i>=cd[j]; i--){
				if(add[i-cd[j]]==1 && !add[i]){
					add[i]=1;
					if(vec[i-cd[j]].size()+1>vec[i].size()){
						vec[i].clear();
						int k;
						for(k=0; k<vec[i-cd[j]].size(); k++)
							vec[i].push_back(vec[i-cd[j]][k]);
					}
					vec[i].push_back(cd[j]);
				}
			}
		}

		for(i=n; i>=0&&!add[i]; i--);
		for(j=0; j<vec[i].size(); j++)	printf("%d ", vec[i][j]);
		printf("sum:%d\n", i);
	}
	return 0;
}
