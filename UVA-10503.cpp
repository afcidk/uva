#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define MAX 2000
using namespace std;

int num[MAX][2];
vector<int> helpFind[MAX];
bool visited[MAX];
bool solve(int cur, int step);

int main() {
    int n, m;
    while(scanf("%d", &n) == 1 && n){
        scanf("%d", &m);
        memset(visited, 0, sizeof(visited));
        for(int i=0; i<MAX; ++i)    helpFind[i].clear();

        scanf("%d%d%d%d", &num[0][0], &num[0][1], &num[1][0], &num[1][1]);
        for(int i=2; i<m+2; ++i){
            scanf("%d%d", &num[i][0], &num[i][1]);
            helpFind[num[i][0]].push_back(i);
            helpFind[num[i][1]].push_back(i);
        }
        if(solve(num[0][1], n)){
            puts("YES");
        }
        else    puts("NO");
    }
    return 0;
}

bool solve(int cur, int step){
    
    if(step == 0){
        if(cur==num[1][0])  return true;
        else return false;
    }

    for(int i=0; i<helpFind[cur].size(); ++i){
        int now=helpFind[cur][i];
        int number=(num[now][0]==cur?num[now][1]:num[now][0]);
        if(!visited[now]){
            visited[now]=1;
            if(solve(number, step-1))   return true;
            visited[now]=0;
        }
    }
    return false;
}
