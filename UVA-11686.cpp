#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define MAX 1000000
using namespace std;

int deg[MAX], visited[MAX];
vector<int> vec[MAX];
int ans[MAX], len;
bool cycle;
void init();
void dfs(int cur);

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m)==2 && (n||m)){
       init(); 

       int a, b;
       for(int i=0; i<m; ++i){
            scanf("%d%d", &a, &b);
            vec[a].push_back(b);
            deg[b]=1;
       }

       for(int i=1; i<=n; ++i){
           if(deg[i]==0){
               cycle=false;
               dfs(i);
           }
       }

       if(cycle)    puts("IMPOSSIBLE");
       else
            for(int i=len-1; i>=0; --i) printf("%d\n", ans[i]);
    }
    return 0;
}

void init(){
    cycle=true;
    len=0;
    memset(deg, 0, sizeof(deg));
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<MAX; ++i)    vec[i].clear();
}

void dfs(int cur){

    if(visited[cur]==1){    cycle=true; return;}
    visited[cur]=1;
    for(int i=0; i<vec[cur].size(); ++i){

        int now=vec[cur][i];
        if(visited[now]!=2){
            dfs(now);
        }
    }
    visited[cur]=2;

    ans[len++]=cur;
}

