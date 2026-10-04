class Solution {
    public boolean isPalindrome(int x) {
        
       if(x<0) return false;
       int rev=0,s=x,rem;
       while(x!=0){
           rem=x%10;rev=rev*10+rem;x/=10;
       }
        return rev==s;
    }
}