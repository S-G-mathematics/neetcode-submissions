class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int mx=0;
        int curr1=0;
        int curr2=0;
        int n=arr.size();
        if(n==1)return 1;
        for(int k=0;k<n-1;k++){
            if((k%2==0 && arr[k]< arr[k+1]) || (k%2==1 && arr[k]>arr[k+1])){
                curr1++;
            }else{
                mx=max(mx,curr1);
                curr1=0;
            }
            if((k%2==1 && arr[k]< arr[k+1]) || (k%2==0 && arr[k]>arr[k+1])){
                curr2++;
            }else{
                mx=max(mx,curr2);
                curr2=0;
            }            

        }
        mx=max(mx,curr1);
        mx=max(mx,curr2);
        return mx+1;
    }
};