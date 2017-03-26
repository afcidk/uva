#include<stdio.h>
#include<string.h>
#define max(a, b) (a>b?a:b)
#define min(a, b) (a<b?a:b)
#define MAX 10000

int p[MAX][MAX], ori[MAX][MAX];
int n, m;
int limr, liml;
int search(int);
int search2(int, int);
int fit(int, int, int, int);
int check_mi, check_ma;

int main() {
	while(scanf("%d%d", &n, &m)==2 && (n||m)){
		int i, j;
		check_mi=0xffffff;
		check_ma=-1;
		for(i=0; i<n; ++i)
			for(j=0; j<m; ++j){
				scanf("%d", &ori[i][j]);
				check_mi=min(ori[i][j], check_mi);
				check_ma=max(ori[i][j], check_ma);
			}
		int count;
		scanf("%d", &count);
		while(count--){
			scanf("%d%d", &liml, &limr);

			int ma=0;
			for(i=0; i<n; ++i){
				int left=search(i);
				if(left!=-1){
	
					int right=search2(i, left);
					int now=right;
					ma=max(now, ma);
				}
			}
			if(check_ma < liml || check_mi > limr)	printf("0\n");
			else	printf("%d\n", ma);
		}
		printf("-\n");
	}
	return 0;
}

int search(int ind){
	int l=0, r=m;
	int mid;
	while(l<r){
		mid=(l+r)/2;
		if(ori[ind][mid]>=liml)	r=mid;
		else l=mid+1;
	}
	if(ori[ind][l]>limr || ori[ind][l]<liml)	return -1;
	return l;
}

int search2(int x, int y){
	int tx=x, ty=y;
	int dif=min(n-x-1, m-y-1);
	int fx=x,fy=y, nx=dif+fx, ny=dif+fy;
	int midx, midy;

	while(fx<nx && fy<ny && fit(fx, fy, nx, ny)){
		midx=(fx+nx)/2;
		midy=(fy+ny)/2;
		if(ori[midx][midy]>limr)	nx=midx,ny=midy;
		else fx=midx+1, fy=midy+1;
	}

	if(ori[fx][fy]>limr){
		while(fx>=tx && fy>=ty && ori[fx][fy]>limr){
			fx--;fy--;
		}
	}
	else if(ori[fx][fy]<liml){
		while(fx<n && fy<m && ori[fx][fy]<=limr){
			fx++;fy++;
		}
	}
	return fx-tx+1;
}

int fit(int fx, int fy, int nx, int ny){
	return fx<n&&fy<m&&nx>=0&&ny>=0;
}
