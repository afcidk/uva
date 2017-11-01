#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int T[6];
vector<int> node[6], path[105];
long long int dis[105];
void init(){
    for(int i=0; i<105; ++i){
        path[i].clear();
        dis[i]=0x7ffffffff;
    }
    for(int i=0; i<6; ++i)  node[i].clear();
}

int main() {
    int n, k;
    while(scanf("%d%d", &n, &k)==2){
        init();

        int x; char c;
        for(int i=1; i<=n; ++i) scanf("%d", &T[i]);
        for(int i=1; i<=n; ++i){
            while(scanf("%d%c", &x, &c)){
                node[i].push_back(x);
                path[x].push_back(i);
                if(c == '\n')   break;
            }
        }

        bool inQueue[105]={0};
        queue<int> que;
        que.push(0);    dis[0]=0;   inQueue[0]=true;
        while(!que.empty()){
            int cur=que.front(); que.pop(); inQueue[cur]=false;

            for(int i=0; i<path[cur].size(); ++i){
                int nxtNode = path[cur][i];
                for(int j=0; j<node[nxtNode].size(); ++j){
                    int nxtPath = node[nxtNode][j];

                    if(dis[nxtPath] > dis[cur]+T[nxtNode]*abs(nxtPath-cur)+60){
                        dis[nxtPath] = dis[cur]+T[nxtNode]*abs(nxtPath-cur)+60;
                        
                        if(!inQueue[nxtPath]){
                            que.push(nxtPath);
                            inQueue[nxtPath]=true;
                        }
                    }
                }
            }
        }
        if(dis[k] == 0x7ffffffff) puts("IMPOSSIBLE");
        // distance will be 0 if sink is the same as source
        else if(dis[k]-60 < 0)  puts("0");
        // distance won't be a negative number!
        else  printf("%lld\n", dis[k]-60);
    }
    return 0;
}

