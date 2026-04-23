#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void generateSums(int start, int end, vector<int>& arr, vector<long long>& sums) {
        int n = end - start;
        for (int i = 0; i < (1 << n); ++i) {
            long long currentSum = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    currentSum += arr[start + j];
                }
            }
            sums.push_back(currentSum);
        }
    }

    int countSubset(vector<int>& arr, int k) {
        int n = arr.size();
        
        int mid = n / 2;
        vector<long long> leftSums, rightSums;
        
        generateSums(0, mid, arr, leftSums);
        generateSums(mid, n, arr, rightSums);
        
        sort(rightSums.begin(), rightSums.end());
        
        int count = 0;
        
        for (long long leftSum : leftSums) {
            long long target = (long long)k - leftSum;
            auto range = equal_range(rightSums.begin(), rightSums.end(), target);
            count += (range.second - range.first);
        }
        
        return count;
    }
};