class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        // Not my logic had to lookup on the internet :)

        // so basically what we are doing

        // nums=[1,2,3]

        // Few questions to get the intuition


        //Since I am allowed to increment n-1 elements, what ekement should we leave??

        // min , max any one in the middle??

        // for min -> you are unneseraily increasing the moves
        // for mid -> wont give you the correct answer as well as you wont be able to track
        // for max -> yes leaving it would work ( beause greedily you would want to bring all the elements closer to it, if you increase this in 1st and 2nd case the difference would increase and then more moves would be needed to reach it)

        // So we can leave max and then do what???
        // Whatever the question is saying

        // Algo

        // 1. check if array equal??  (O(n))
        // 2. leave max element
        // 3. increment the other (n-1) elements by 1 (O(n))
        // 4. go to step 1

        // O(n2) solution

    //     Example of what the above algo is doing

    //     [1,2,3] 

    // Iterations

    //     1.  False
    //     2.  3
    //     3.  2 , 3 , 3

    //     1.  False
    //     2.  3
    //     3.  3, 4, 3

    //     1.  False
    //     2.  4
    //     3.  4, 4 ,4 

    //     so basically

    //                     [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

    // Gap(min and max)       2            1            1            0

    // So we are essentially making the all elements to max until they are equal ( why focus of min?? because it will take the most moves )


    // Can we think of reverse


    // Instead of increasing all elements and make them equal to greatest can we make the max element to minimum??

    // WHy this might work because tracking all n-1 is tedious but tracking only one element that is max is O(1) ( so we would be able to remove that extra O(n) time)

    // So we pick max element and decrement it

    //                      [1,2,3]  =>  [1,2,2]  =>  [1,2,1]  =>  [1,1,1]

    // Gap(min and max)       2            1            1            0


    // See both gaps are same


    // So what are we doing

    // So what are we doing for any potential candidate we are trying to make it equal to minimum

    // It becomes a problem to make array equal by subtracting any element by 1  ( so we can do this by makin all elements equal to min and how much operation it will take for any element (element - minEle ) total moves would be Summation ( nums[i] - minEle))


    // So its like

    // nums[i]-minEle + nums[i+1]-minEle + nums[i+2]-minEle + ... nums[n-1]-minEle;

    // Sum of all elements -  n*(minEle)

        int sum=0;
        int minEle=INT_MAX;
        int n=nums.size();

        for(int i=0;i<n;i++){
            sum+=nums[i];
            minEle=min(minEle,nums[i]);
        }

        return sum-n*minEle;
    }
};