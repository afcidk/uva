#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<int> road[30];
vector<int> reversed[30];
vector<int> collect[30];
int visit_init[30][30];
int visited[30];
int topo[30], topo_size;
int collect_size;

int find(const string s,const vector<string> vec);
void init();
void dfs(int now);
void dfs2(int now);

int main()
{
    //SCC
    int n, m;
    int cc=0;
    while(scanf("%d%d", &n, &m)==2 && (n||m)){
        vector<string> names;
        init();

        getchar();
        string na, nb;
        for(int i=0; i<m; ++i){
            cin>>na>>nb;
            int posa, posb;
            if((posa=find(na, names))==-1){
                names.push_back(na);
                posa = names.size()-1;
            }
            if((posb=find(nb, names))==-1){
                names.push_back(nb);
                posb = names.size()-1;
            }
            if(!visit_init[posa][posb]){
                road[posa].push_back(posb);
                reversed[posb].push_back(posa);
                visit_init[posa][posb] = 1;
            }
        }

        for(int i=0; i<n; ++i){
            if(!visited[i]) dfs(i);
        }


        memset(visited, 0, sizeof(visited));
        for(int i=topo_size; i>=0; --i){
            if(!visited[topo[i]]){
                dfs2(topo[i]);
                ++collect_size;
            }
        }
        if(cc) puts("");
        printf("Calling circles for data set %d:\n", ++cc);
        for(int i=0; i<collect_size; ++i){
            if(collect[i].size()!=0)    cout<<names[collect[i][0]];
            for(int j=1; j<collect[i].size(); ++j){
                cout<<", "<<names[collect[i][j]];
            }
            puts("");
        }
    }
    return 0;
}

int find(const string s,const vector<string> vec){
    for(int i=0; i<vec.size(); ++i){
        if(vec[i] == s)   return i;
    }
    return -1;
}

void dfs(int now){
    visited[now] = 1;
    for(int i=0; i<road[now].size(); ++i){
        if(!visited[road[now][i]]){
            dfs(road[now][i]);
        }
    }
    topo[++topo_size] = now;
}

void dfs2(int now){
    collect[collect_size].push_back(now);
    visited[now] = 1;
    for(int i=0; i<reversed[now].size(); ++i){
        if(!visited[reversed[now][i]]){
            dfs2(reversed[now][i]);
        }
    }
}
void init(){
    memset(topo, 0, sizeof(topo));
    memset(visit_init, 0, sizeof(visit_init));
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<30; ++i) {
        road[i].clear();
        reversed[i].clear();
        collect[i].clear();
    }
    topo_size=-1;
    collect_size = 0;
}
