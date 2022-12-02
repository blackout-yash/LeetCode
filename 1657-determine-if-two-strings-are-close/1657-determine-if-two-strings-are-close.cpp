class Solution {
public:
    bool closeStrings(string word1, string word2) {
        set <char> s1, s2;
        map <char, int> m1, m2;
        for(auto x: word1) m1[x]++, s1.insert(x);
        for(auto x: word2) m2[x]++, s2.insert(x);
        
        if(s1 != s2) return false;
        
        vector <int> arr1, arr2;
        for(auto x: m1) arr1.push_back(x.second);
        for(auto x: m2) arr2.push_back(x.second);
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        
        return (arr1 == arr2);
    }
};