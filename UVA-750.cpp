/*
   presentation!
   */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int map[9][9], skip;
const int dirX[]={-1,-1,1,1};
const int dirY[]={-1,1,-1,1};
int ans[8], len, cc;
void place(int y, int x);
void take(int y, int x);
bool inRange(int x){   return x>=1 && x<=8;}
void solve(int col);

int main() {
    int n;
    scanf("%d", &n);
    bool first=true;
    while(n--){
        cc=0;
        memset(map, 0, sizeof(map));
        len=0;

        int a, b;
        scanf("%d%d", &a, &b);
        place(a,b);
        ans[b-1]=a;
        skip=b;
        if(!first)  puts("");
        first=false;
        puts("SOLN       COLUMN");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        solve(1);
    }
    return 0;
}

void place(int y, int x){

    for(int i=1; i<9; ++i){
        ++map[y][i];
        ++map[i][x];
    }
    --map[y][x];
    for(int i=0; i<4; ++i){
        int nx=x, ny=y;
        while(inRange(nx+dirX[i]) && inRange(ny+dirY[i])){
            nx += dirX[i];
            ny += dirY[i];
            ++map[ny][nx];
        }
    }
}

void take(int y, int x){
    
    for(int i=1; i<9; ++i){
        --map[y][i];
        --map[i][x];
    }
    ++map[y][x];
    for(int i=0; i<4; ++i){
        int nx=x, ny=y;
        while(inRange(nx+dirX[i]) && inRange(ny+dirY[i])){
            nx += dirX[i];
            ny += dirY[i];
            --map[ny][nx];
        }
    }
}

void solve(int col){

    if(col == skip){
        ++len;
        solve(col+1);
        --len;
    }
    if(col == 9){
        printf("%2d      ", ++cc);
        printf("%d", ans[0]);
        for(int i=1; i<8; ++i) printf(" %d", ans[i]);
        puts("");
        return ;
    }
    for(int i=1; i<9; ++i){
        if(!map[i][col]){
            place(i, col);
            ans[len++]=i;
            solve(col+1);
            take(i, col);
            --len;
        }
    }
}
