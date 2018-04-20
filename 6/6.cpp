#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
int main(){
	int m;
	cin>>m;
	int n;
	double temp;
	vector<double> ris;
	int result;
	double len;
	while(m--){
		result=0;
		len=20;
		cin>>n;
		ris.clear();
		ris.reserve(n);
		while(n--){
			cin>>temp;
			ris.push_back(temp);
		}
		std::sort(ris.begin(),ris.end());
		double maxRi;
		while(len>0){
			result++;
			maxRi=ris.back();
			ris.pop_back();
			len-=2*std::sqrt(maxRi*maxRi-1);
		}
		cout<<result<<endl;


	}
}
