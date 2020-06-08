#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool chessboard[8][8]={0};

int c=0;

struct position{
	int x, y;
};

typedef struct position point;

vector <point> v(64);

void findpath(int i,int j){
	point p;
	p.x=i+1;
	p.y=j+1;
	v[c++]=p;
	//delete p;
	chessboard[i][j]=1;

	if((i+1)<8 && (j-1)>-1 && chessboard[i+1][j-1]!=1){
		findpath(i+1,j-1);
		point p1;
	p1.x=i+1;
	p1.y=j+1;
	v[c++]=p1;
	}
	
	if((i-1)>-1 && (j-1)>-1 && chessboard[i-1][j-1]!=1){
		findpath(i-1,j-1);
	point p1;
	p1.x=i+1;
	p1.y=j+1;
	v[c++]=p1;
	}
	if((i-1)>-1 && (j+1)<8 && chessboard[i-1][j+1]!=1){
		findpath(i-1,j+1);
		point p1;
	p1.x=i+1;
	p1.y=j+1;
	v[c++]=p1;
	}

	if((i+1)<8 && (j+1)<8 && chessboard[i+1][j+1]!=1){
		findpath(i+1,j+1);
		point p1;
	p1.x=i+1;
	p1.y=j+1;
	v[c++]=p1;
	}

	return;
}

int main(){
	int tcs;
	cin>>tcs;
	while(tcs-->0){
		memset(chessboard,0,sizeof(chessboard));
		c=0;
		v.clear();
		int n,m;
		cin>>n>>m;
		n=n-1;
		m=m-1;
		chessboard[m][n]=1;
	findpath(m,n);
	for(int i=0; i<8; i++){	for(int j=0; j<8; j++){
		cout<<chessboard[i][j]<<" ";
	}
	cout<<endl;
	}

	cout<<c-1<<endl;
	for(int i=1; i<c;i++){
		cout<<v[i].y<<" "<<v[i].x<<endl;
	}
	//cout<<v[i].y<<" "<<v[i].x;
	}

	return 0;
}