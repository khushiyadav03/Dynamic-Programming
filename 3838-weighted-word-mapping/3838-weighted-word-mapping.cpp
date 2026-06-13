class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result;
        for (const string& word : words) {
            int sum = 0;
            for (char c : word) {
                sum += weights[c - 'a'];
            }
            int remainder = sum % 26;
            char mapped = 'z' - remainder; // 0 -> 'z', 1 -> 'y', ..., 25 -> 'a'
            result.push_back(mapped);
        }
        return result;
    }
};