/*
   topological sort:
    find a node to begin(degree==1)
    dfs
    backtrack
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int deg[200];
bool visited[200];
vector<int> vec[200];
int num[200], len;
void dfs(int cur);
void init(){
   memset(visited, 0, sizeof(visited));
   memset(deg, 0, sizeof(deg));
   for(int i=0; i<200; ++i)    vec[i].clear();
}

int main() {

    int m, n;
    while(scanf("%d%d", &n, &m) == 2 && (n||m)){
        init();
        len=n;

        int a, b;
        for(int i=0; i<m; ++i){
            scanf("%d%d", &a, &b);
            deg[b]=1;
            vec[a].push_back(b);
        }

        for(int i=1; i<=n; ++i){
            if(deg[i]==0)
                dfs(i);
        }
        cout<<num[0];
        for(int i=1; i<n; ++i)   cout<<" "<<num[i];
        puts("");
    }
    return 0;
}

void dfs(int cur){

    visited[cur]=1;
    for(int i=0; i<vec[cur].size(); ++i){

        int now=vec[cur][i];
        if(!visited[now])
            dfs(now);
    }

    num[--len]=cur;
}
