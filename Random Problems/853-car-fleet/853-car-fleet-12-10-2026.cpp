class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
    //                 0 3 5 8 10        12
    //                 1 3 1 4  2

    //  diff/speed     12 4 7 1 1


    // sort according to position and see from the right who can come in one fleet if curr car time taken is less than > = fleetsSlowest then add it to the fleet

        vector<pair<int,int>> temp;

        for(int i=0;i<position.size();i++){
            temp.push_back({position[i],speed[i]});
        }

        sort(temp.begin(),temp.end(), greater<pair<int, int>>() );

        double currFleetsMaxTime=0,fleets=0;
        for(int i=0;i<temp.size();i++){
            int currPos=temp[i].first;
            int speed=temp[i].second;
            int diff=target-currPos;
            double timeNeeded=1.0*diff/speed;

            if(timeNeeded>currFleetsMaxTime){
                fleets++;
                currFleetsMaxTime=timeNeeded;
            }
            currFleetsMaxTime=max(currFleetsMaxTime,timeNeeded);
        }

        return fleets;

        // [0,2,4]   
        // [4,2,1]
        // [100,98,96]
        // [25,49,96]


    }
};