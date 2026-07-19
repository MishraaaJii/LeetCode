class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int end = timeSeries[0] + duration - 1;
        int time = 0;
        for(int i = 1; i < timeSeries.size(); i++){
            if(timeSeries[i] > end){
                time += duration;
            } else {
                time += timeSeries[i] - timeSeries[i-1];
            }
            end = timeSeries[i] + duration - 1;
        }
        time += duration;
        return time;
    }
};