#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int cap[105][105], flow[105][105];
int visited[105], past[105];
queue<int> que;

int solve(int s, int t, int n);

int main()
{
    int n;
    int s, t, c;
    int cc=0;
    while(scanf("%d", &n)==1 && n){
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));

        scanf("%d%d%d", &s, &t, &c);
        int x, y, z;
        for(int i=0; i<c; ++i){
            scanf("%d%d%d", &x, &y, &z);
            cap[x][y]+=z;
            cap[y][x]+=z;
        }


        printf("Network %d\n", ++cc);
        printf("The bandwidth is %d.\n", solve(s, t, n));
        puts("");
    }
    return 0;
}

int solve(int s, int t, int n){

    int ret=0;
    while(true){

        memset(visited, 0, sizeof(visited));
        memset(past, 0, sizeof(past));
        while(!que.empty()) que.pop();
        que.push(s);
        int success=0;
        int bottleneck=0x7fffffff;
        while(!que.empty()){

            int now = que.front();
            que.pop();
            visited[now]=1;
            if(now == t){
                success=1;
                break;
            }

            for(int i=1; i<=n; ++i){

                if(!visited[i]){

                    if(cap[now][i]-flow[now][i]>0){
                        past[i] = now;
                        que.push(i);
                        bottleneck = min(bottleneck, cap[now][i] - flow[now][i]);
                    }
                    else if(flow[i][now]>0){
                        past[i] = now;
                        que.push(i);
                        bottleneck = min(bottleneck, flow[i][now]);
                    }
                }
            }
        }
        if(success){

            for(int i=t; i!=s; i=past[i]){

                int pre = past[i];
                if(cap[pre][i]-flow[pre][i]>0){
                    flow[pre][i]+=bottleneck;
                }
                else flow[i][pre]-=bottleneck;
            }
            ret+=bottleneck;
        }
        else break;
    }
    return ret;
}
