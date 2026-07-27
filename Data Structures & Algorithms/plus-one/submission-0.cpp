class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        int n=digits.size();
        int temp;
        for(int i=n-1;i>=0;i--){
            if(i==n-1)temp=digits[i]+1;
            else temp=digits[i]+carry;
            if(temp<=9){
                digits[i]=temp;
                carry=0;
                }
            else{
                digits[i]=temp-10;
                carry=1;
            }
        }
        if(carry==1) digits.insert(digits.begin(),1);
        return digits;
    }
};
