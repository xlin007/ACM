#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main(){
	int n,maxValue;
	cin>>n;
	while(n--){
		cin>>maxValue;
		for(int i=1;i<=maxValue;i=i+2){
			cout<<i<<" ";
		}
		cout<<endl;
		for(int i=2;i<=maxValue;i=i+2){
			cout<<i<<" ";
		}
		cout<<endl;
	}
}
