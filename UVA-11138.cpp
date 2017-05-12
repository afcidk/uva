#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define MAX 505
using namespace std;

vector<int> edge[MAX];
int llink[MAX],rlink[MAX];
int visited[MAX];

int solve(int nL, int nR);
bool DFS(int now);
void init(){
    for(int i=0; i<MAX; ++i)    edge[i].clear();
    memset(llink, 0, sizeof(llink));
    memset(rlink, 0, sizeof(rlink));
}

int main() {

    int n, cc=0;
    scanf("%d", &n);
    while(n--){
        init();

        int a, b;
        int x;
        scanf("%d%d", &a, &b);
        for(int i=1; i<=a; ++i){
            for(int j=1; j<=b; ++j){
                scanf("%d", &x);
                if(x==1){
                    edge[i].push_back(j);
                }
            }
        }

        printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", ++cc,solve(a, b));
    }
    return 0;
}

int solve(int nL, int nR){

    int ret=0;
    for(int i=1; i<=nL; ++i){

        memset(visited, 0, sizeof(visited));
        if(DFS(i)) ++ret;
    }
    return ret;
}

bool DFS(int now){

    for(int i=0; i<edge[now].size(); ++i){

        int nxt = edge[now][i];
        if(!visited[nxt]){

            visited[nxt]=1;
            if(!rlink[nxt] || DFS(rlink[nxt])){

                llink[now]=nxt;
                rlink[nxt]=now;
                return true;
            }
        }
    }
    return false;
}
