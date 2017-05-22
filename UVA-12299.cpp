#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAX 100005
#define INF 0x7fffffff
using namespace std;

struct Node{

	Node *l, *r;
	int minNum;

	void update(int x){
		minNum = x;
	}

	void pull(){
		minNum = min(l->minNum, r->minNum);
	}
};

int num[MAX];
void toName(const char *src, char *des);
int getList(const char *src, int *des);
int findMin(Node *node, int x, int y, int L, int R);
void modify(Node *node, int x, int L, int R, int change);
Node *build(int l, int r);

int main() {

	int n, q;
	while(scanf("%d%d", &n, &q) == 2){
		
		Node *node;
		for(int i=0; i<n; ++i)	scanf("%d", &num[i]);

		node = build(0,n-1);

		char s[MAX], *name;
		name = (char*)malloc(10*sizeof(char*));
		for(int i=0; i<q; ++i){
			scanf("%s", s);
			toName(s, name);

			if(strcmp(name, "query") == 0){

				int list[2];
				getList(s, list);

				printf("%d\n",findMin(node, min(list[0]-1,list[1]-1), max(list[0]-1, list[1]-1), 0, n-1));
			}
			else if(strcmp(name, "shift") == 0){
				int list[MAX], size, rec[MAX];
				size = getList(s, list);
				list[size] = list[0];
				for(int j=0; j<size+1; ++j)	rec[j] = findMin(node, list[j]-1, list[j]-1, 0, n-1);

				for(int j=0; j<size; ++j){
					modify(node, list[j]-1, 0, n-1, rec[j+1]);
				}
			}
		}
	}
	return 0;
}

void toName(const char *src, char *des){

	int len = strlen(src);
	for(int i=0; i<len; ++i){
		if(src[i] == '('){
			des[i] = '\0';
			return;
		}
		des[i] = src[i];
	}
}

int getList(const char *src, int *des){

	int len = strlen(src), i;
	int listSize=0, rec=0;

	for(i=0; i<len && src[i]!='('; ++i);
	++i;

	for(; i<len; ++i){
		if(src[i] == ',' || src[i] == ')'){
			des[listSize++] = rec;
			rec=0;
			++i;
		}

		rec = rec*10+src[i]-'0';
	}
	return listSize;
}

Node *build(int l, int r){

	Node *now = new Node();
	if(l == r){
		now->update(num[l]);
		return now;
	}

	int mid = (l+r)/2;
	now->l = build(l, mid);
	now->r = build(mid+1, r);
	now->pull();

	return now;
}

int findMin(Node *node, int x, int y, int L, int R){

	if(x>R || y<L)	return INF;
	if(x<=L && y>=R)	return node->minNum;

	int mid = (L+R)/2;
	return min(findMin(node->l, x, y, L, mid), findMin(node->r, x, y, mid+1, R));
}

void modify(Node *node, int x, int L, int R, int change){

	if(L==R){
		node->update(change);
		return;
	}

	int mid = (L+R)/2;
	if(x<=mid)	modify(node->l, x, L, mid, change);
	else modify(node->r, x, mid+1, R, change);

	node->pull();
}
