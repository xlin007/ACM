#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::size_t;
int main(){
	int n;
	cin>>n;
	string str;
	string subStr;
	int count;
	while(n--){
		count=0;
		cin>>subStr>>str;
		size_t pos=0;
		while((pos=str.find(subStr,pos)+1)){
			count++;
		}
		cout<<count<<endl;
	}
}