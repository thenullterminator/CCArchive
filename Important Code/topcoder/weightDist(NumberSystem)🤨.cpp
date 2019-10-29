#include <bits/stdc++.h>
using namespace std;
class Apothecary{
	public:
    vector <int> balance(int w);
};

vector <int> Apothecary::balance(int w)
    {
        vector<int> ans;
        
        int curr=1;
        while(w>0)
        {
            if(w%3==1)
            {
                ans.push_back(curr);
            }
            else if(w%3==2)
            {
                w+=1;
                ans.push_back(-1*curr);
            }
            w=w/3;
            curr*=3;
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }