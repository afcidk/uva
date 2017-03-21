#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

struct S{
	int depth;
	int value;
	int found;
}treasure[50];

int main() {
	int limit, c;
	int first=1;
	while(scanf("%d%d", &limit, &c)==2){
		vector<struct S> vec[1005];
		int p[1005]={1};
		int num;
		int i, j;
		scanf("%d", &num);
		for(i=0; i<num; i++){
			scanf("%d%d", &treasure[i].depth, &treasure[i].value);
			treasure[i].depth*=3*c;
		}

		for(j=0; j<num; j++){
			for(i=limit; i>=treasure[j].depth; i--){
					if(p[i] < p[i-treasure[j].depth]+treasure[j].value)	{ // if add becomes bigger, then add. else skip
						struct S temp;
						p[i] = p[i-treasure[j].depth]+treasure[j].value;
						vec[i].clear();
						int k;
						for(k=0; k<vec[i-treasure[j].depth].size(); k++){ // renew the list
							temp=vec[i-treasure[j].depth][k];
							vec[i].push_back(temp);
						}
						temp=treasure[j];
						vec[i].push_back(temp);
					}
			}
		}

		if(!first)	printf("\n");
		first=0;
	  	for(i=limit; i>=0&&!p[i]; i--);
		printf("%d\n%d\n", p[i], vec[i].size());
		for(j=0; j<vec[i].size(); j++)	printf("%d %d\n", vec[i][j].depth/(3*c), vec[i][j].value);

	}
}
