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
int c_ele; //�Y�I�����Ӽ�

// ex: 1->2 2->3 3->1
// �Y��:  1->x 2->x 3->x

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
            for(int j=0; j<road[i].size(); ++j){//�b�쥻���ϸ̭��䦳�_�۲���comp��(���P�N���O�P�@����)
                int now=road[i][j];
                if(comp[i]!=comp[now]){//�]���Y�L�I�F�A�ҥH�i�ण�P���I���ۦP��comp��
                    ++inside[comp[now]];
                }
            }
        }

        int ans=0;

        for(int i=1; i<=c_ele; ++i){ //�����ݴ���DAG���N�i�H�F
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
        else if(inStack[nxt]){ //inStack=1 ���� visited[nxt]
            low[cur] = min(low[cur], dfn[nxt]);
        }
    }

    if(low[cur]==dfn[cur]){ //�Y�I(�w�g���੹�W�]�F)�A��ڤU�����Ҧ��I(stack��)��comp�]���ۦP
        ++c_ele;
        inside[c_ele]=0;//�@�}�l�������]�S���s�J��edge
        int t;
        do{
            t=st.top();
            st.pop();

            inStack[t]=0;
            comp[t]=c_ele;
        }while(t!=cur); //�|�q�U���@�����ۤv(�@�ز{�b�O�ۤv�A�M�᩹�^���A���ۤv������)
    }
    //else(low[cur]<dfn[cur])  �N��i�H�s��W���h�A�|�b�W���B�z
}
