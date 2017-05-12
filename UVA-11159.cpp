#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define MAX 105
using namespace std;

int llink[MAX], rlink[MAX];
int visited[MAX];
vector<int> edge[MAX];

int solve(int nL, int nR);
bool DFS(int now);
void init(){
    memset(llink, 0, sizeof(llink));
    memset(rlink, 0, sizeof(rlink));
    for(int i=0; i<MAX; ++i)    edge[i].clear();
}

int main() {

    int n, cc=0;
    scanf("%d", &n);
    while(n--){
        init();

        int num[2][MAX]={0};
        int siz[2];
        for(int k=0; k<2; ++k){
            scanf("%d", &siz[k]);
            for(int i=1; i<=siz[k]; ++i) scanf("%d", &num[k][i]);
        }

        for(int i=1; i<=siz[0]; ++i){

            for(int j=1; j<=siz[1]; ++j){

                if(num[0][i] == 0){
                    if(num[1][j] == 0)  edge[i].push_back(j);
                }
                else if(num[1][j]%num[0][i]==0)    edge[i].push_back(j);
            }
        }

        printf("Case %d: %d\n", ++cc, solve(siz[0], siz[1]));
    }
    return 0;
}

int solve(int nL, int nR){

    int ret=0;
    for(int i=1; i<=nL; ++i){

        memset(visited, 0, sizeof(visited));
        if(DFS(i))  ++ret;
    }
    return ret;
}

bool DFS(int now){

    for(int i=0; i<edge[now].size(); ++i){

        int nxt = edge[now][i];
        if(!visited[nxt]){

            visited[nxt]=1;
            if(!rlink[nxt] || DFS(rlink[nxt])){

                rlink[nxt]=now;
                llink[now]=nxt;
                return true;
            }
        }
    }
    return false;
}
