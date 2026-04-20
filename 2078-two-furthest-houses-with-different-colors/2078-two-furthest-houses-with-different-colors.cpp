class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int i = 0, j = colors.size() - 1;
        int maxDis = INT_MIN;

        while(i < j){
            if(colors[i] != colors[j]){
                maxDis = max(maxDis, abs(i - j));
                break;
            }
            j--;
        }

        i = 0, j = colors.size() - 1;
        while(i < j){
            if(colors[i] != colors[j]){
                maxDis = max(maxDis, abs(i - j));
                break;
            }
            i++;
        }
        return maxDis;
    }
};