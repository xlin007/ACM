#include<iostream>
#include<vector>
#include<cmath>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
int main(){
	int n;
	cin>>n;
	int m;
	vector<int> xVec,yVec;

	while(n--){
		cin>>m;
		xVec.clear();
		yVec.clear();
		xVec.reserve(m);
		yVec.reserve(m);
		int x,y;
		int xMin,xMax,yMin,yMax;
		xMin=yMin=100;
		xMax=yMax=0;
		while(m--){
			cin>>x>>y;
			if(x<xMin){
				xMin=x;
			}
			if(y<yMin){
				yMin=y;
			}
			if (x>xMax)
			{
				xMax=x;
			}
			if(y>yMax){
				yMax=y;
			}
			xVec.push_back(x);
			yVec.push_back(y);
		}
		int xMinSum,yMinSum;
		xMinSum=yMinSum=0;
		for(int j=0;j<xVec.size();j++){
				xMinSum+=std::abs(xVec[j]-xMin);
		}
		for(int i=xMin+1;i<=xMax;i++){
			int xMinSumTemp=0;
			for(int j=0;j<xVec.size();j++){
				xMinSumTemp+=std::abs(xVec[j]-i);
			}
			if(xMinSumTemp<xMinSum){
				xMinSum=xMinSumTemp;
			}
		}
		for(int j=0;j<yVec.size();j++){
				yMinSum+=std::abs(yVec[j]-yMin);
		}
		for(int i=yMin+1;i<=yMax;i++){
			int yMinSumTemp=0;
			for(int j=0;j<yVec.size();j++){
				yMinSumTemp+=std::abs(yVec[j]-i);
			}
			if(yMinSumTemp<yMinSum){
				yMinSum=yMinSumTemp;
			}
		}

		cout<<xMinSum+yMinSum<<endl;


	}
}
