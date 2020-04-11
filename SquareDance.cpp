#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m;
vector<vector<int>> s, l, r, u, d;
set<ar<int, 2>> tr;


bool chk(int i, int j) {
	int nc=0, sc=0;
	if(~l[i][j]) {
		++nc;
		sc+=s[i][l[i][j]];
	}
	if(~r[i][j]) {
		++nc;
		sc+=s[i][r[i][j]];
	}
	if(~u[i][j]) {
		++nc;
		sc+=s[u[i][j]][j];
	}
	if(~d[i][j]) {
		++nc;
		sc+=s[d[i][j]][j];
	}
	return s[i][j]*nc<sc;
}


void chk2(int i, int j) {
	if(chk(i, j))
		tr.insert({i, j});
	else
		tr.erase({i, j});
}

void solve() {
	
	cin >> n >> m;
	s=vector<vector<int>>(n, vector<int>(m));
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			cin >> s[i][j];
	
	
	l=r=u=d=vector<vector<int>>(n, vector<int>(m));
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			l[i][j]=j-1;
			r[i][j]=j<m-1?j+1:-1;
			u[i][j]=i-1;
			d[i][j]=i<n-1?i+1:-1;
		}
	}

	
	ll sa=0;
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			sa+=s[i][j];
	
	
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			chk2(i, j);

	
	ll ans=0;
	for(bool ch=1; ch; ) {
		ch=0;
		ans+=sa;
		
		set<ar<int, 2>> tr2=tr;
		tr={};
		for(ar<int, 2> a : tr2) {
			
			ch=1;
			int i=a[0], j=a[1];
			
			sa-=s[i][j];
			
			if(~l[i][j]) {
				r[i][l[i][j]]=r[i][j];
				chk2(i, l[i][j]);
			}
			if(~r[i][j]) {
				l[i][r[i][j]]=l[i][j];
				chk2(i, r[i][j]);
			}
			if(~u[i][j]) {
				d[u[i][j]][j]=d[i][j];
				chk2(u[i][j], j);
			}
			if(~d[i][j]) {
				u[d[i][j]][j]=u[i][j];
				chk2(d[i][j], j);
			}
			tr.erase({i, j});
		}
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for(int i=1; i<=t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
}
