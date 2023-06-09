class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it = upper_bound(begin(letters), letters.end(), target);
        if(it == end(letters)) return letters[0];
        return *it;
    }
};