#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int connect[6][6];
int visited[6][6];
int len, num[10];
void solve(int cur);

int main() {
    memset(visited, 0, sizeof(visited));
    memset(connect, 0, sizeof(connect));
    memset(num, 0, sizeof(num));
    len=0;
    connect[1][2]=1;
    connect[1][3]=1;
    connect[1][5]=1;
    connect[2][1]=1;
    connect[2][3]=1;
    connect[2][5]=1;
    connect[3][1]=1;
    connect[3][2]=1;
    connect[3][4]=1;
    connect[3][5]=1;
    connect[4][5]=1;
    connect[4][3]=1;
    connect[5][1]=1;
    connect[5][2]=1;
    connect[5][3]=1;
    connect[5][4]=1;
    num[len++]=1;
    solve(1);
}

void solve(int cur) {
    if(len == 9){
        for(int i=0; i<9; ++i)  printf("%d", num[i]);
        puts("");
        return;
    }
    for(int i=1; i<=5; ++i){
        if(!visited[cur][i] && connect[cur][i]){
            visited[cur][i]=visited[i][cur]=1;
            num[len++] = i;
            solve(i);
            visited[cur][i]=visited[i][cur]=0;
            --len;
        }
    }
}
