#include<iostream>
#include<algorithm>
using namespace std;
#define maxnum 20000
struct post{
	int order;
	int pos;
}poster[maxnum];

struct{
	int l,r;
	bool vis;
}node[maxnum<<2];

bool flag;

bool cmp1(const post &p1,const post &p2){
	return p1.pos<p2.pos;
}
bool cmp2(const post &p1,const post &p2){
	if(p1.order>p2.order){
		return true;
	}else if(p1.order==p2.order){
		return p1.pos<p2.pos;
	}
	return false;
}

void buildTree(int left,int right,int rt){
	node[rt].l=left;
	node[rt].r=right;
	node[rt].vis=false;
	if(left==right)return;
	int mid=(left+right)>>1;
	buildTree(left,mid,rt<<1);
	buildTree(mid+1,right,rt<<1|1);
}

void query(int left,int right,int rt){
	if(node[rt].vis) return;
	if(node[rt].l==left&&node[rt].r==right){
		node[rt].vis=true;
		flag=true;
		return;
	}
	if(right<=node[rt<<1].r){
		query(left,right,rt<<1);
	}else if(left>=node[rt<<1|1].l){
		query(left,right,rt<<1|1);
	}else{
		query(left,node[rt<<1].r,rt<<1);
		query(node[rt<<1|1].l,right,rt<<1|1);
	}
	node[rt].vis=node[rt<<1].vis&node[rt<<1|1].vis;
}

int main(){
	int n,m,sum;
	cin>>n;
	while(n--){
		sum=0;
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>poster[2*i].pos>>poster[2*i+1].pos;
			poster[2*i].order=poster[2*i+1].order=i;
		}
		sort(poster,poster+2*m,cmp1);
		int index=0,pre=-1;
		for(int i=0;i<2*m;i++){
			if(poster[i].pos !=pre && poster[i].pos !=pre+1)
			{
			pre=poster[i].pos;
			++index;
			poster[i].pos =++index;
			}else if(poster[i].pos!=pre){
				pre=poster[i].pos;
				poster[i].pos=++index;
			}else
				poster[i].pos=index;
	}
		sort(poster,poster+2*m,cmp2);
		buildTree(1,index,1);
		for (int i=0;i<2*m;i+=2)
		{
			flag=false;
			query(poster[i].pos,poster[i+1].pos,1);
			if(flag) sum++;
		}
		cout<<sum<<endl;
	}
}





