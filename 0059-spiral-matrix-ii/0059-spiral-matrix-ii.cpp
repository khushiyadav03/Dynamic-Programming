class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));

        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;
        int value = 1;

        while(top <= bottom && left <= right){
            // left -> right
            for(int i = left; i<= right; i++){
                res[top][i] = value++;
            }
            top++;

            // right -> bottom 
            for(int i = top; i<= bottom; i++){
                res[i][right] = value++;
            }
            right--;

            // right ->left
            if(top <= bottom){
                for(int i = right; i>= left; i--){
                    res[bottom][i] = value++;
                }
                bottom--;
            }

            // left -> top
            if(left <= right){
                for(int i = bottom; i>= top; i--){
                    res[i][left] = value++;
                }
                left++;
            }
        }

        return res;
    }
};