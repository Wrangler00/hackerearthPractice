//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1/description/


#include<bits/stdc++.h>
using namespace std;
#define ll int
#define l(n) 2*n+1
#define r(n) 2*n+2

const ll lim = 1e5+100;

ll sgtree[4*lim] = {0};
ll lazy[4*lim] = {0};

bool isEven(ll x){
	return (!(x & 1));  
}
void updateT(ll l,ll r,ll node,ll ind,ll diff){
	if(ind <l || ind>r)
		return;
	
	sgtree[node] += diff;
	if(l == r){
		return;
	}

	ll mid = (l+r)/2;

	updateT(l,mid,l(node),ind,diff);
	updateT(mid+1,r,r(node),ind,diff);

	return;
}

ll getOddEven(ll l,ll r,ll start,ll end,ll node){
	if(start>end || start>r || end<l)
		return 0;
	
	if(start>=l && end<=r){
		return sgtree[node];
	}

	ll mid = (start+end)/2;
	return getOddEven(l,r,start,mid,l(node))+getOddEven(l,r,mid+1,end,r(node));
}

ll contructTree(ll arr[],ll l,ll r,ll node){
	if(l == r){
		sgtree[node] = (arr[l]%2 == 0 ? 0 : 1);
		return sgtree[node];
	}

	ll mid = (l+r)/2;
	sgtree[node] = contructTree(arr,l, mid,l(node)) + contructTree(arr,mid+1,r,r(node));

	return sgtree[node];
}

int main() {
	ll n,q;
	cin >> n;

	ll arr[n];

	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}

	contructTree(arr,0,n-1,0);


	// for(ll i =0;i<4*n;i++)
	// 	cout<<sgtree[i]<<" ";

	// cout<<endl;

	cin>>q;

	for(ll i=0;i<q;i++){
		ll a,l,r;
		cin>>a>>l>>r;

		switch(a){
			case 0:{
					ll ind = l-1,new_val = r;
					ll diff = (isEven(arr[ind]) == isEven(new_val));
					arr[ind] = new_val;

					if(!diff){
						diff = isEven(new_val) ? -1: 1;
						updateT(0,n-1,0,ind,diff);
					}
				}
				break;
			case 1:
				//check even
				cout<< (r-l+1-getOddEven(l-1,r-1,0,n-1,0))<<endl;
				break;
			case 2:
				//check odd
				cout<< getOddEven(l-1,r-1,0,n-1,0)<<endl;
				break;
		}
	}
	return 0;
}


