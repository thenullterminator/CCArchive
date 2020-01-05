#include <bits/stdc++.h>
using namespace std;

int main(void){

	int tc;
	cin>>tc;

	while(tc--){

		int n;
		cin>>n;
		long long ans=0;
		vector<int> mid;

		for(int i=0;i<n;i++){

			int c;
			cin>>c;

			for(int j=1;j<=c;j++){

				int x;
				cin>>x;

				if(j<=c/2) ans+=x;				
				else if(j==((c/2)+1) && (c&1)) mid.push_back(x);
			}
		}
		sort(mid.rbegin(),mid.rend());

		for(int i=0;i<mid.size();i++){
			if(i%2==0) ans+=mid[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}