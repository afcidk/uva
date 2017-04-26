#include <iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#define MAX 105
using namespace std;

string name[MAX];
int dfn[MAX], low[MAX], clc;
int s_num;
vector<int> road[MAX];
map<string, int> record;

void init(){
    for(int i=0; i<105; ++i){
        name[i] = "";
        dfn[i]=0;low[i]=0;
        road[i].clear();
    }
    record.clear();
    clc=0;
}
void dfs(int cur, int parent);
int find(string s);

int main()
{
    int n, m;
    int count=0;
    while(scanf("%d", &n)==1 && n){
        init();
        s_num=n;
        string s, t;
        getchar();
        for(int i=1; i<=n; ++i){
            cin>>s;
            name[i] = s;
        }

        scanf("%d", &m);
        getchar();
        for(int i=0; i<m; ++i){
            cin>>s>>t;
            int x = find(s);
            int y = find(t);
            road[x].push_back(y);
            road[y].push_back(x);
        }

        for(int i=1; i<=n; ++i){
            if(!dfn[i]) dfs(i, -1);
        }

        if(count)   puts("");
        printf("City map #%d: %d camera(s) found\n", ++count, record.size());

        for(auto iter=record.begin(); iter!=record.end(); ++iter){
            cout<<iter->first<<endl;
        }
    }
    return 0;
}

int find(string s){

    for(int i=1; i<=s_num; ++i){
        if(name[i]==s)  return i;
    }
    return -1;
}

void dfs(int cur, int parent){

    dfn[cur] = low[cur] = ++clc;
    int child=0;
    int flag=0;

    for(int i=0; i<road[cur].size(); ++i){

        int nxt = road[cur][i];
        if(!dfn[nxt]){

            ++child;
            dfs(nxt, cur);

            low[cur] = min(low[cur], low[nxt]);
            if(low[nxt]>=dfn[cur])  flag=1;
        }
        else if(nxt != parent){
            low[cur] = min(low[cur], dfn[nxt]);
        }
    }

    if((parent==-1 && child>=2) || (parent!=-1 && flag==1)){
        record[name[cur]]=1;
    }
}
