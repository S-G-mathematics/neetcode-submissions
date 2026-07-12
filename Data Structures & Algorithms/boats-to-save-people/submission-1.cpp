class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        int l=0;
        int r=n-1;
        int ans=0;
        int g=n;
        while(g>0){
            if(people[l]+people[r]<=limit){
                l++;
                r--;
                ans++;
                g=g-2;
            }
            else if(people[l]+people[r]>limit){
                r--;
                ans++;
                g=g-1;
            }
        }
        return ans;
    }
};