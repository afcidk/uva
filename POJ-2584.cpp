#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#define MAX 50
#define INF 0x7fffffff
using namespace std;

int cap[MAX][MAX], flow[MAX][MAX];
int visited[MAX], past[MAX];
const string ts=".SMLXT";
int n;

int solve();

int main()
{
    string s;
    while(cin>>s && s!="ENDOFINPUT"){
        scanf("%d", &n);
        getchar();
        string xx;
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));

        for(int i=1; i<=n; ++i){
            cin>>xx;
            cap[0][i]=1;

            int pa = ts.find(xx[0]);
            int pb = ts.find(xx[1]);
            for(int j=pa; j<=pb; ++j){
                cap[i][20+j]=1;
            }
        }
        int x;
        for(int i=1; i<=5; ++i){
            scanf("%d", &x);
            cap[20+i][31]=x;
            cap[25+i][31]=1;  //0 start, 31 end
        }
        getchar();
        cin>>s;

        if(solve()==n) puts("T-shirts rock!");
        else puts("I'd rather not wear a shirt anyway...");
    }

    return 0;
}

int solve(){

    int ret=0;
    while(true){

        memset(visited, 0, sizeof(visited));
        queue<int> que;
        que.push(0);

        while(!que.empty()){

            int cur = que.front();
            que.pop();
            visited[cur]=1;

            for(int i=0; i<=31; ++i){

                if(!visited[i]){

                    if(cap[cur][i]-flow[cur][i]>0 || flow[i][cur]>0){
                        past[i]=cur;
                        que.push(i);
                    }
                }
            }
        }

        if(!visited[31])    break;
        else{

            for(int i=31; i!=0; i=past[i]){

                int pre = past[i];
                if(cap[pre][i]-flow[pre][i]>0) ++flow[pre][i];
                else --flow[i][pre];
            }
            ++ret;
        }
    }
    return ret;
}
