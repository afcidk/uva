/*using SSSP -0.12s*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define MAX 3000
using namespace std;

vector<int> path[MAX];
int cost[MAX][MAX];
int dis[MAX];

void init(){
    memset(cost, 0, sizeof(cost));
    for(int i=0; i<MAX; ++i)    path[i].clear();
    for(int i=0; i<MAX; ++i)    dis[i]=0x7fffff;
}

int main() {
    int c;
    scanf("%d", &c);
    while(c--){
        init();
        int n, m, x, y, t;
        scanf("%d %d", &n, &m);
        for(int i=0; i<m; ++i){
            scanf("%d %d %d", &x, &y, &t);
            path[x].push_back(y);
            cost[x][y] = t;
        }

        for(int i=0; i<m-1; ++i){
            for(int j=0; j<m; ++j){
                for(int k=0; k<path[j].size(); ++k){
                    int cur = path[j][k];
                    dis[cur] = min(dis[cur], dis[j]+cost[j][cur]);
                }
            }
        }

        bool fail=false;
        for(int j=0; j<m; ++j){
            for(int k=0; k<path[j].size(); ++k){
                int cur = path[j][k];
                if(dis[cur] > dis[j]+cost[j][cur]){
                    fail=true;
                    break;
                }
            }
            if(fail)    break;
        }
        if(fail) puts("possible");
        else puts("not possible");
    }
    return 0;
} 

