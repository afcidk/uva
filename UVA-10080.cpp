#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#define MAX 105
using namespace std;

int rlink[MAX];
int visited[MAX];
vector<int> edge[MAX];
double ax[MAX], ay[MAX], bx[MAX], by[MAX];

int solve(int nL);
bool DFS(int now);
void init(){
    memset(rlink, 0, sizeof(rlink));
    for(int i=0; i<MAX; ++i)    edge[i].clear();
}

int main() {

    int n, m, s, v;
    while(scanf("%d%d%d%d", &n, &m, &s, &v)==4){
        init();


        for(int i=1; i<=n; ++i)  scanf("%lf%lf", &ax[i], &ay[i]);

        for(int i=1; i<=m; ++i)  scanf("%lf%lf", &bx[i], &by[i]);
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j){

                double len = sqrt(pow(ax[i]-bx[j], 2)+pow(ay[i]-by[j], 2));
                if(len <= s*v){
                    edge[i].push_back(j);
                }
            }

        printf("%d\n", n-solve(n));

    }
    return 0;
}

int solve(int nL){

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

                rlink[nxt] = now;
                return true;
            }
        }
    }
    return false;
}
