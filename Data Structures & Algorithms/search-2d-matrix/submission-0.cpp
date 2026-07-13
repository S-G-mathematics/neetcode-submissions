class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        int ur=0;
        int dr=r-1;
        int l=0;
        int ro=c-1;
        while(ur<=dr){
            int mid=ur+(dr-ur)/2;
            if(target>matrix[mid][c-1]) ur=mid+1;
            else if(target<matrix[mid][0])dr=mid-1;
            else{
                while(l<=ro){
                int cid=l+(ro-l)/2;
                if(matrix[mid][cid]==target)return true;
                else if(matrix[mid][cid]<target)l=cid+1;
                else ro=cid-1;
                }
                return false;
            }
        }
    return false;
    }
};
