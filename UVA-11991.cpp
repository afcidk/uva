#include <iostream>
#include <cstdio>
#include <vector>
#define MAX 1000005
using namespace std;

vector<int> vec[MAX];

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) == 2){
		int x;
		for(int i=1; i<=n; ++i){
			scanf("%d", &x);
			vec[x].push_back(i);
		}
		int a, b;
		while(m--){
			scanf("%d%d", &a, &b);
			if(vec[b].size() < a)	puts("0");
			else printf("%d\n", vec[b][a-1]);
		}
	}
	return 0;
}
