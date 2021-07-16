#include "bits/stdc++.h"

using namespace std;

vector<int> lis(vector<int> const& a){
	int n=a.size();
	vector<int> d(n,1),p(n,-1);
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[j]<a[i]&&d[i]<d[j]+1){
				d[i]=d[j]+1;
				p[i]=j;
			}
		}
	}

	//encontra a posição do ultimo elem
	//da maior subseq
	int ans=d[0],pos=0;
	for(int i=0;i<n;i++){
		if(d[i]>ans){
			pos=i;
			ans=d[i];
		}
	}

	vector<int> subseq;
	while(pos!=-1){
		subseq.push_back(a[pos]);
		pos=p[pos];
	}
	reverse(subseq.begin(),subseq.end());
	return subseq;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	
	int i,n,c;cin>>n>>c;	
	vector<int> v,subseq;
	while(n--){
		cin>>i;v.push_back(i);
	}
	subseq=lis(v);
	cout<<subseq[subseq.size()-1]-subseq[0]-c;

	return 0;
}