class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        for(char c:tasks){
            count[c-'A']++;
        }
        priority_queue<int> pq;
        queue<pair<int,int>> q;
        for(int num:count){
            if(num>0)pq.push(num);
        }
        int t=0;
        while(!q.empty() || !pq.empty()){
            t++;
            if(pq.empty()){
                t=q.front().second;
            }else{
                int cnt=pq.top()-1;
                pq.pop();
                if(cnt>0)q.push({cnt,t+n});
            }

            if(!q.empty() && q.front().second==t){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return t;
    }
};
