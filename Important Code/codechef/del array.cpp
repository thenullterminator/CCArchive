#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn = 2e5 + 10;
const int inf = 1e9 + 10;
 
bool dp[maxn], pd[maxn];
int a[maxn], t, n;
 
int main(){
	ios_base::sync_with_stdio (false);
	cin >> t;
	while (t--) {
		cin >> n;
		dp[0] = 1;
		a[0] = -inf;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			dp[i] = (dp[i - 1] & (a[i] > a[i - 1]));
		}
		pd[n + 1] = 1;
		a[n + 1] = inf;
		for (int i = n; i >= 1; i--)
			pd[i] = (pd[i + 1] & (a[i] < a[i + 1]));
		
		ll answer = 0;
		int lo = 0, hi = n + 1;
		while (hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if (pd[mid])
				hi = mid;
			else
				lo = mid;
		}
		answer = (n - lo);
		for (int i = 1; i <= n - 1; i++){
			if (dp[i] == 0)
				break;
			int lo = i + 1, hi = n + 1;
			while (hi - lo > 1){
				int mid = (lo + hi) >> 1;
				if (pd[mid] == 1 and a[mid] > a[i])
					hi = mid;
				else
					lo = mid;
			}
			answer += n - lo + 1;
		}
		cout << answer - dp[n] << endl;
	}
}
