#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int fib(int v){
	if(v==1||v==2)
		return 1;
	return fib(v-1)+fib(v-2);
}
int main(){
	int n;
	cin>>n;
	while(n--){
		int v;
		cin>>v;
		cout<<fib(v)<<endl;
	}
}
