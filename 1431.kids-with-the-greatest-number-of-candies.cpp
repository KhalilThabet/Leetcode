class Solution {
	public:
		    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
			            int max=0;int n=candies.size();
				            for(auto e:candies) if(e>max) max=e;
					            vector<bool> v(n);
						            vector<bool>::iterator it=v.begin();
							            for(int i=0;i<n;i++,it++){
									                if(candies[i]+extraCandies>=max) *it=true;
											            else *it=false;
												            }
								            return v;
									        }
};
