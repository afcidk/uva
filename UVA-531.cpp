#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#define MAX 110
using namespace std;

int xx[MAX][MAX];
int front[MAX][MAX];

int main() {
	string s;
	while(cin>>s){
		memset(xx, 0, sizeof(xx));
		memset(front, 0, sizeof(front));
		string a[MAX], b[MAX];
		vector<int> vec;
		int lena=0, lenb=0;
		a[++lena]=s;
		while(cin>>s){
			if(s=="#")	break;
			a[++lena]=s;
		}
		while(cin>>s){
			if(s=="#")	break;
			b[++lenb]=s;
		}

		int i, j;
		for(i=1; i<=lena; ++i){
			for(j=1; j<=lenb; ++j){
				if(a[i]==b[j]){
					xx[i][j]=xx[i-1][j-1]+1;
					front[i][j]=(i-1)*100000+(j-1);
				}

				else{
					if(xx[i][j-1]>xx[i-1][j]){
						xx[i][j]=xx[i][j-1];
						front[i][j]=i*100000+j-1;
					}
					else{
						xx[i][j]=xx[i-1][j];
						front[i][j]=(i-1)*100000+j;
					}
				}
			}
		}

		i=lena;j=lenb;
		while(i!=0 && j!=0){
			int ti=i,tj=j;
			i=front[ti][tj]/100000;
			j=front[ti][tj]%100000;
			if(i==ti-1 && j==tj-1)	vec.push_back(ti);
		}
		cout<<a[vec[vec.size()-1]];
		for(i=vec.size()-2; i>=0; --i)	cout<<" "<<a[vec[i]];
		cout<<endl;
	}
	return 0;
}
