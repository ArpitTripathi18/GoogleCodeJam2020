#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	
	if(n<30) {
		for(int i=0; i<n; ++i)
			cout << i+1 << " 1\n";
		return;
	}
	
	n-=30;
	int m=0;
	bool left=1;
	for(int i=0; i<30; ++i) {
		
		cout << i+1 << " " << (left?1:i+1) << "\n";
		if(n>>i&1) {
			
			if(left)
				for(int j=1; j<=i; ++j)
					cout << i+1 << " " << j+1 << "\n";
			else
				for(int j=i-1; j>=0; --j)
					cout << i+1 << " " << j+1 << "\n";
			left=!left;
			
			++m;
		}
	}
	
	for(int i=30; m; --m, ++i) {
		
		cout << i+1 << " " << (left?1:i+1) << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for(int i=1; i<=t; ++i) {
		cout << "Case #" << i << ":\n";
		solve();
	}
}
