class Solution {
  public:
    int maxOccured(vector<int>& L, const vector<int>& R) {
        int n = L.size();
        int maxi = *max_element(R.begin(), R.end());
        vector<int> diff(maxi+2, 0);
        
        for(int i = 0; i<n; i++){
            diff[L[i]]++;
            diff[R[i] + 1]--;
        }
        int mx = diff[0];
        int ans = 0;

        for(int i = 1; i <= maxi; i++)
        {
            diff[i] += diff[i - 1];

            if(diff[i] > mx)
            {
                mx = diff[i];
                ans = i;
            }
        }

        return ans;
    }
};