#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int deg[200];
string ans;
vector<int> vec[200];
bool visited[200];
void dfs(int cur);

int main() {
    string back, front;
    cin>>back;

    while(cin>>front && front!="#"){
        int lenb=back.length(), lenf=front.length();

        for(int i=0; i<lenb&&i<lenf; ++i){
            if(deg[back[i]]==0) deg[back[i]]=1;
            if(deg[front[i]]==0)    deg[front[i]]=1;
            if(back[i] != front[i]){
                deg[front[i]] = 2;
                vec[back[i]].push_back(front[i]);
                break;
            }
        }
        back=front;
    }

    for(int i='A'; i<='Z'; ++i){
        if(deg[i] == 1){
            dfs(i);
            break;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}

void dfs(int cur){

    visited[cur]=1;
    for(int i=0; i<vec[cur].size(); ++i){
        int now=vec[cur][i];
        if(!visited[now])
            dfs(now);
    }

    ans = char(cur) + ans;
}
