//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/smallest-dividable-segment-82dc8519/description/

//partially correct

#include<bits/stdc++.h>
using namespace std;

#define ll int
#define l(n) 2*n+1
#define r(n) 2*n+2

const ll lim = 5*1e5+100;
const ll edgeVal = lim+10;
// ll sgtree[4*lim][2];
vector<pair<ll,ll>> sgtree(4*lim,make_pair(0,lim+10));
vector<pair<ll,ll>> sgRange(4*lim,make_pair(-1,-1));

ll getCount(ll l,ll r,ll start,ll end,ll node){
	if(start>end || start>r || end<l)
		return edgeVal;
	
	if(start>=l && end<=r){
		return sgtree[node].second;
	}

	ll mid = (start+end)/2;
	ll uu = getCount(l,r,start,mid,l(node));
	ll vv = getCount(l,r,mid+1,end,r(node));
	ll ans = min(uu,vv);

	// cout<<uu<< " "<<vv<<endl;
	// if(ans == edgeVal)	return edgeVal;
	return ans;//min(getCount(l,r,start,mid,l(node)),getCount(l,r,mid+1,end,r(node)));
}

pair<ll,ll> contructT(ll arr[],ll l,ll r,ll node,ll k){
	// cout<<l<<" "<<r<<endl;
	if(l == r){
		sgtree[node].first = arr[l]%k;
		sgtree[node].second = arr[l]%k==0?1:sgtree[node].second;
		sgRange[node] = make_pair(l,r);
		return sgtree[node];
	}

	ll mid = (l+r)/2;

	pair<ll,ll> p1 = contructT(arr,l,mid,l(node),k);
	pair<ll,ll> p2 = contructT(arr,mid+1,r,r(node),k);
	 
	vector<ll,pair<ll,ll>> discus;

	ll x = ((p1.first%k)*(p2.first%k))%k;
	discus.push_back({p1.second,make_pair(l,mid)});
	discus.push_back({p2.second,make_pair(mid+1,r)});
	// ll y = min(p1.second,p2.second);

	if(x==0){
		// y = min(y,r-l+1);
		discus.push_back({r-l+1,make_pair(l,r)});
	}

	if(r-l+1>2){
		// vector<pair<ll,ll>> extra;
		ll m1 = ((arr[mid]%k) * (p2.first%k))%k;
		ll r1 = r-mid+1+1;
		ll m2 = ((arr[mid]%k) * (arr[mid+1]%k))%k;
		ll r2 = 2;
		ll m3 = ((p1.first%k)* (arr[mid+1]%k))%k;
		ll r3 = mid-l+1+1;

		discus.push_back({r1,make_pair(l-1,r)});
		// extra.push_back(make_pair(m1,r1));
		// extra.push_back(make_pair(m2,r2));
		// extra.push_back(make_pair(m3,r3));

		// sort(extra.begin(),extra.end(),[](auto &left, auto &right) {
		// 	if(left.first == right.first)
		// 		return left.second < right.second;
		// 	return left.first < right.first;
		// });

		// if(extra[0].first == 0){
		// 	y = min(y,extra[0].second);
		// 	// cout<<"beech me :: "<<extra[0].first<<" "<<extra[0].second<<endl;
		// }
	}

	// if(l == 8 && r == 9)
	// 	cout<<"8,9 :: "<<x<<" "<<y<<endl;

	sgtree[node] = make_pair(x,y);

	return sgtree[node];
}

int main() {
	ll n,k,q;
	cin>>n>>k>>q;

	ll arr[n];
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}

	contructT(arr,0,n-1,0,k);

	for(ll i=0;i<4*n;i++)
		cout<<"i: "<<i<<" -> "<<sgtree[i].first<<" "<<sgtree[i].second<<endl;

	// for(ll i=0;i<q;i++){
	// 	ll l,r;
	// 	cin>>l>>r;
	// 	ll ans = getCount(l-1,r-1,0,n-1,0);
	// 	if(ans == edgeVal)
	// 		cout<<-1<<" ";
	// 	else cout<<ans<<" ";
	// }
	return 0;
}
