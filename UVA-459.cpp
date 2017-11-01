#include <bits/stdc++.h>
using namespace std;

bool visited[30], rec[30];
vector<int> vec[30];
void init(){
    for(int i=0; i<30; ++i){
        visited[i] = rec[i] = 0;
        vec[i].clear();
    }
}
void bfs(int x){

    queue<int> que; que.push(x);
    while(!que.empty()){
        int cur = que.front();
        visited[cur] = true;
        que.pop();

        for(int i=0; i<vec[cur].size(); ++i){
            int nxt = vec[cur][i];
            if(!visited[nxt]){
                que.push(nxt);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();getchar();

    char a[5], b[5];
    while(n--){
        init();

        fgets(a, 5, stdin);

        while(fgets(b, 5, stdin)){
            if(strlen(b) == 1)  break;
            vec[b[0]-'A'].push_back(b[1]-'A');
            vec[b[1]-'A'].push_back(b[0]-'A');
        }

        int ans = 0;
        for(int i=0; i<=a[0]-'A'; ++i){
            if(!visited[i]){
                ++ans;
                bfs(i);
            }
        }

        printf("%d\n", ans);
        if(n) puts("");
    }
    return 0;
}
