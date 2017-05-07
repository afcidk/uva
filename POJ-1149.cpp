#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 1005
#define INF 0x7fffffff
using namespace std;

int cap[MAX][MAX], flow[MAX][MAX];
int visited[MAX];
int past[MAX];
int pig[MAX];

int solve(int s, int t);

int main()
{

    int m, n;
    while(scanf("%d%d", &m, &n)==2){
        memset(visited, 0, sizeof(visited));
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));
        memset(past, 0, sizeof(past));

        for(int i=1; i<=m; ++i){
            scanf("%d", &pig[i]);
        }

        //0=start, n+1=end
        int x, a;
        for(int i=1; i<=n; ++i){
            scanf("%d", &x);
            for(int j=1; j<=x; ++j){
                scanf("%d", &a);
                if(!past[a]){
                    past[a] = i;
                    cap[0][i]+=pig[a];
                }
                else{
                    cap[past[a]][i]=INF;
                }
            }
            scanf("%d", &x);
            cap[i][n+1]=x;
        }

        printf("%d\n", solve(0, n+1));
    }
    return 0;
}

int solve(int s, int t){

    int ret=0;
    while(true){

        memset(visited, 0, sizeof(visited));
        queue<int> que;
        que.push(s);
        while(!que.empty()){

            int cur = que.front();
            que.pop();
            visited[cur]=1;
            for(int i=0; i<=t; ++i){

                if(!visited[i]){
                    if(cap[cur][i]-flow[cur][i]>0 || flow[i][cur]>0){

                        past[i] = cur;
                        que.push(i);
                    }
                }
            }

        }
        if(!visited[t]) break;
        else{

            int f=INF;
            for(int i=t; i!=s; i=past[i]){

                int pre = past[i];
                if(cap[pre][i]-flow[pre][i]>0)  f = min(f, cap[pre][i]-flow[pre][i]);
                else f = min(f, flow[i][pre]);
            }

            for(int i=t; i!=s; i=past[i]){

                int pre = past[i];
                if(cap[pre][i]-flow[pre][i]>0)  flow[pre][i]+=f;
                else flow[i][pre]-=f;
            }

            ret+=f;
        }
    }
    return ret;
}

