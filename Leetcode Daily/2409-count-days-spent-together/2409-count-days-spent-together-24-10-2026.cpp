class Solution {
public:
    int help(vector<int> &prefix,int mm,int dd){
        int previousSum=prefix[mm-1];
        return previousSum+dd;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        // timestamp thing would work fine
        // create prefix sum to get the value of exact mm-dd and then check for overlapping


        vector<int> prefix={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        for(int i=1;i<13;i++) prefix[i]+=prefix[i-1];

        int aliceStart=help(prefix,stoi(arriveAlice.substr(0, 2)),stoi(arriveAlice.substr(3)));
        int aliceEnd=help(prefix,stoi(leaveAlice.substr(0, 2)),stoi(leaveAlice.substr(3)));
        int bobStart=help(prefix,stoi(arriveBob.substr(0, 2)),stoi(arriveBob.substr(3)));
        int bobEnd=help(prefix,stoi(leaveBob.substr(0, 2)),stoi(leaveBob.substr(3)));

        
        // now the problem is like given two ranges find common elements

    //     a       b
    // A       B
    //         A      B
    //        A  B
    // A               B

        return max(0,min(aliceEnd,bobEnd)-max(aliceStart,bobStart)+1);

    }
};
