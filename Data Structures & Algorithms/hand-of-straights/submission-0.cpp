class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)return false;
        int n=hand.size();
        sort(hand.begin(),hand.end());
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            freq[hand[i]]++;
        }
        for(int i=0;i<n;i++){
            if(freq[hand[i]]==0)continue;
            for(int j=hand[i];j<=hand[i]+groupSize-1;j++){
                if(freq[j]==0)return false;
                freq[j]--;
            }
        }
        return true;
    }
};
