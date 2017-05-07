#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <unistd.h>
#define MAX 300
#define INF 0x7fffffff
using namespace std;

int N;
int cap[MAX][MAX], flow[MAX][MAX];
int visited[MAX], past[MAX];

int solve();

int main()
{
    //N*2+1 = end   N*2+2 = start
    while(scanf("%d", &N)==1){
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));

        int x;
        for(int i=1; i<=N; ++i){
            scanf("%d", &x);
            cap[i][N+i]+=x;
        }

        int m, n;
        scanf("%d", &m);
        int a, b, c;
        for(int i=0; i<m; ++i){
            scanf("%d%d%d", &a, &b, &c);
            cap[a+N][b]=c;
        }


        scanf("%d%d", &m, &n);
        for(int i=0; i<m; ++i){
            scanf("%d", &a);
            cap[N*2+2][a]=INF;
        }
        for(int i=0; i<n; ++i){
            scanf("%d", &a);
            cap[a+N][N*2+1]=INF;
        }

        printf("%d\n",solve());
    }
    return 0;
}

int solve(){

    int ret=0;
    while(true){

        memset(visited, 0, sizeof(visited));
        queue<int> que;
        que.push(N*2+2);
        while(!que.empty()){

            int cur = que.front();
            que.pop();
            visited[cur]=1;
            if(cur == 2*N+1) break;

            for(int i=1; i<=N*2+2; ++i){

                if(!visited[i]){

                    if(cap[cur][i]-flow[cur][i]>0 || flow[i][cur]>0){

                        past[i]=cur;
                        que.push(i);
                    }
                }
            }
        }

        if(!visited[2*N+1]) break;
        else{

            int f=INF;
            for(int i=2*N+1;i!=N*2+2; i=past[i]){

                int pre = past[i];
                if(cap[pre][i]-flow[pre][i]>0){
                    f = min(f, cap[pre][i]-flow[pre][i]);
                }
                else f = min(f, flow[i][pre]);
            }

            for(int i=2*N+1;i!=N*2+2; i=past[i]){

                int pre = past[i];
                if(cap[pre][i]-flow[pre][i]>0){
                    flow[pre][i]+=f;
                }
                else flow[i][pre]-=f;

            }
            ret+=f;
        }
    }
    return ret;
}
