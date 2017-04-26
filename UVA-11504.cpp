#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#define MAX 100005
using namespace std;

vector<int> road[MAX];
stack<int> st;
int dfn[MAX], low[MAX], clc;
int inStack[MAX], inside[MAX], comp[MAX];
int c_ele; //縮點完的個數

// ex: 1->2 2->3 3->1
// 縮完:  1->x 2->x 3->x

void dfs(int cur);
void init(){
    for(int i=0; i<MAX; ++i){
        road[i].clear();
        dfn[i]=low[i]=inStack[i]=0;
    }
    clc=0;
    c_ele=0;
    while(!st.empty())  st.pop();
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n--){
        init();
        int a, b;
        scanf("%d %d", &a, &b);

        int x, y;
        for(int i=0; i<b; ++i){
            scanf("%d %d", &x, &y);
            road[x].push_back(y);
        }

        for(int i=1; i<=a; ++i){

            if(!dfn[i]){
                dfs(i);
            }
        }

        for(int i=1; i<=a; ++i){
            for(int j=0; j<road[i].size(); ++j){//在原本的圖裡面找有否相異的comp值(不同代表不是同一個環)
                int now=road[i][j];
                if(comp[i]!=comp[now]){//因為縮過點了，所以可能不同的點有相同的comp值
                    ++inside[comp[now]];
                }
            }
        }

        int ans=0;

        for(int i=1; i<=c_ele; ++i){ //直接看換成DAG的就可以了
            if(inside[i]==0)    ++ans;
        }

        printf("%d\n", ans);

    }
    return 0;
}

void dfs(int cur){

    low[cur] = dfn[cur] = ++clc;
    st.push(cur);
    inStack[cur]=1;

    for(int i=0; i<road[cur].size(); ++i){

        int nxt = road[cur][i];
        if(!dfn[nxt]){

            dfs(nxt);
            low[cur] = min(low[cur], low[nxt]);
        }
        else if(inStack[nxt]){ //inStack=1 等於 visited[nxt]
            low[cur] = min(low[cur], dfn[nxt]);
        }
    }

    if(low[cur]==dfn[cur]){ //縮點(已經不能往上跑了)，把我下面的所有點(stack裡)的comp設成相同
        ++c_ele;
        inside[c_ele]=0;//一開始都先假設沒有連入的edge
        int t;
        do{
            t=st.top();
            st.pop();

            inStack[t]=0;
            comp[t]=c_ele;
        }while(t!=cur); //會從下面一直找到自己(一種現在是自己，然後往回走再找到自己的概念)
    }
    //else(low[cur]<dfn[cur])  代表可以連到上面去，會在上面處理
}
