#include<iostream>
#include<set>
#include<iterator>
using std::set;
using std::cin;
using std::cout;
using std::endl;
struct Square{
	int data[3];//按编号、长、宽顺序存储；
	bool operator<(const struct Square &b)const {  
		bool result;
		if(this->data[0]!=b.data[0]){
			result=this->data[0]<b.data[0];
		}else{
			if(this->data[1]!=b.data[1]){
				result=this->data[1]<b.data[1];
			}else{
					result=this->data[2]<b.data[2];
			}
		}	
		return result;  
	}
}sq;
int main(){
	int n;
	cin>>n;
	int m;
	set<Square> squareSet;
	while(n--){
		squareSet.clear();
		cin>>m;
		while(m--){
			cin>>sq.data[0]>>sq.data[1]>>sq.data[2];
			if(sq.data[1]<sq.data[2]){
				int temp=sq.data[1];
				sq.data[1]=sq.data[2];
				sq.data[2]=temp;
			}
			squareSet.insert(sq);	
		}
		set<Square>::iterator it = squareSet.begin();
		while(it!=squareSet.end()){
			cout<<it->data[0]<<" "<<it->data[1]<<" "<<it->data[2]<<endl;
			it++;
		}
	}
}