#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct S{
    int ori;
    int weight, IQ;

    bool operator< (const struct S &t)  const{
        if(weight == t.weight)  return IQ>t.IQ;
        return weight<t.weight;
    }

}item[1005];
inline bool success(const struct S &back, const struct S &front){
    return back.weight>front.weight && back.IQ<front.IQ;
}

void print(int cur, int *last){
    if(cur == last[cur])    return ;
    print(last[cur], last);
    printf("%d\n", item[cur].ori);
}

int main() {
    int size=0;
    while(scanf("%d%d", &item[size].weight, &item[size].IQ) == 2){
        item[size].ori = size+1;
        ++size;
    }

    int last[size]={0};
    int max_len=1, len[size], end=0;
    for(int i=0; i<size; ++i)   len[i]=1;
    sort(item, item+size);
    for(int i=0; i<size; ++i){
        for(int j=0; j<i; ++j){
            if(success(item[i], item[j]) && len[i]<len[j]+1){
                 len[i] = len[j]+1;
                 last[i]=j;
                 if(max_len <= len[i]){
                     max_len = len[i];
                     end = i;
                 }
            }
        }
    }
    printf("%d\n", len[end]);
    print(end, last);
}

