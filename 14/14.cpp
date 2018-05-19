#include<iostream>
#include<algorithm>
using std::cin;
using std::cout;
using std::endl;
struct act{
	int begin,end;
};
bool cmp(const act& p1,const act& p2){
	return p1.end<p2.end;
}
int main(){
	int n,m;
	cin>>n;
	while(n--){
		cin>>m;
		act* Acts=new act[m];
		for(int i=0;i<m;i++){
			cin>>Acts[i].begin>>Acts[i].end;
		}
		std::sort(Acts,Acts+m,cmp);
		int count=1;
		int nowEnd=Acts[0].end;
		for(int i=1;i<m;i++){
			if(Acts[i].begin>nowEnd){
				nowEnd=Acts[i].end;
				count++;
			}
		}
		cout<<count<<endl;
		delete[] Acts;
	}
}

