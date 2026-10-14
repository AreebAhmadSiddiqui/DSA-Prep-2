class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // keep dividing sum/9 to get the max individual squares

        // when the answer becomes less than 9 then add that as a remainder

        int times=sum/9;
        int rem=sum%9;

        int digitsRequired=times+(rem!=0);

        if(digitsRequired>num) return "";

        int remDigits=num; // times<=remDigits

        string ans="";

        while(remDigits!=0 && times!=0){
            ans+='9';
            times--;
            remDigits--;
        }

        if(remDigits && rem!=0){
            ans+=rem+'0';
            remDigits--;
        }

        while(remDigits--){
            ans+='0';
        }

        return ans;
    }
};