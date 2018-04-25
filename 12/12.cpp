#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using std::sqrt;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
struct range{
	double l,r;
};
bool cmp(const range& r1,const range& r2){
	return r1.l<r2.l;
}
int main()
{
	int count;
	cin>>count;
	int n,w,h;
	vector<range> rangeVec;
	while(count--){
		cin>>n>>w>>h;
		rangeVec.clear();
		rangeVec.reserve(n);
		int x,r;
		double sp;
		range rg;
		while(n--){
			cin>>x>>r;
			if(r<=h/2)
				continue;
			sp=sqrt(r*r-h*h/4);
			rg.l=x-sp;
			rg.r=x+sp;
			rangeVec.push_back(rg);
		}
		std::sort(rangeVec.begin(),rangeVec.end(),cmp);
		int result=0;
		double nowR=0;
		double referPoint=0;
		int i=0;
		while(i<rangeVec.size()){
			if(rangeVec[i].l>referPoint||nowR>=w)
				break;
			while(i<rangeVec.size()&&rangeVec[i].l<=referPoint){
				if(rangeVec[i].r>nowR){
					nowR=rangeVec[i].r;
				}
				i++;
			}
			referPoint=nowR;
			result++;
		}
		if(nowR<w)
			result=0;
		cout<<result<<endl;
	}
}
