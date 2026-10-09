class Solution {
public:
    int minInsertions(string s) {

        // One important thing to note

        // (()))) cant match without any steps

        // (()))())) can this also match without any addition?? 
        // we can think like
        
        // ()()))
        // ())
        // "" no add needed


        // but the question says consecutive

        // so after the first step if I reach at

        // () ( this is a loner paranthese I have to add a ')' then continue further )  ()))



        // Lets test that balance approach again

        int bal=0;
        int insertions=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                bal+=2;

                // When we encounter (, we add 2 to the balance because it requires )).
                // But before this new opening bracket, we might already have an odd balance because a previous ) consumed one of the required closing brackets.
                // So after adding 2, if the balance is still odd, we insert one ) to fix that outstanding requirement.
                // Remember the two rules:
                // - Encounter (: Add 2; if balance is odd, insert one ) and decrement balance.
                // - Encounter ): Decrement balance; if it becomes negative, insert an opening ( and set balance = 1

                if(bal%2==1){ // our pairing should be even if it is odd then I have to add ) to make it even
                    insertions++; // add )
                    bal--; // ) will decrease the count -1
                }
            }else{
                bal--;
                if(bal<0){
                    // we have an extra ) we have to insert one ( before
                    insertions++; // inserting (
                    bal=1; // +2 -1 = 1

                    // if the next is ) it will automatically balance itself
                }
            }
        }


        return insertions+bal;
    }
};
