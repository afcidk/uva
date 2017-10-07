/*floyd-warshall*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int edge[105][105];
int flow[105][105];

int main() {
    int C, S, Q, count=0;
    bool first=true;
    while(scanf("%d %d %d", &C, &S, &Q)==3 && (C||S||Q)){
        if(!first)   puts("");
        first=false;
        memset(edge, 0, sizeof(edge));
        memset(flow, 0, sizeof(flow));

        int a, b, c;
        for(int i=0; i<S; ++i){
            scanf("%d %d %d", &a, &b, &c);
            edge[a][b]=c;
            edge[b][a]=c;
            if(flow[a][b]!=0){
                flow[a][b]=min(c, flow[a][b]);
                flow[b][a]=min(c, flow[b][a]);
            }
            else{
                flow[a][b]=c;
                flow[b][a]=c;
            }
        }
        for(int k=1; k<=C; ++k){
            for(int i=1; i<=C; ++i) {
                for(int j=1; j<=C; ++j){
                    if(i!=j){
                        if(edge[i][k]*edge[k][j]){
                            if(edge[i][j]==0)   edge[i][j]=edge[i][k]+edge[k][j];
                            else   edge[i][j]=min(edge[i][k]+edge[k][j], edge[i][j]);
                            int bigger=max(flow[i][k], flow[k][j]);
                            if(flow[i][j]==0)   flow[i][j]=bigger;
                            else flow[i][j]=min(bigger, flow[i][j]);
                        }
                    }
                }
            }
        }

        printf("Case #%d\n", ++count);
        int start, end;
        for(int i=0; i<Q; ++i){
            scanf("%d %d", &start, &end);
            if(edge[start][end]==0) puts("no path");
            else    printf("%d\n", flow[start][end]);
        }
    }
    return 0;
}

