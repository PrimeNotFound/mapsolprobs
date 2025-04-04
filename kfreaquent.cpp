class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k){
            unordered_map<int,int>m;
            unordered_map<int,int> :: iterator it;
            for(int i=0;i<nums.size();i++)
            {
                m[nums[i]]++;
            }
            vector<pair<int,int>>v;
            for(it=m.begin();it!=m.end();++it)
            {
                v.push_back({(*it).first,(*it).second});
            }
            sort(v.begin(),v.end(),[&](pair<int,int>a,pair<int,int>b){
                if(a.second!=b.second) return a.second>b.second;
                return a.first>b.first;
            });
            vector<int>v1;
            for(int i=0;i<k;i++)
            {
                v1.push_back(v[i].first);
            }
            return v1;
        }
    };
