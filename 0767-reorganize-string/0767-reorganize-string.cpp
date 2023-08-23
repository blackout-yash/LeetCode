class Solution {
public:
    string reorganizeString(string s) {
        vector <int> freq(26);
        for(auto x: s) freq[x - 'a']++;
                
        priority_queue <pair <int, char>> pq;
        for(int i = 0; i < 26; i++) {
            if(freq[i]) pq.push({freq[i], char('a' + i)});
        }
        
        string ans;
        while(pq.size()) {
            int num = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            if(ans.empty() || ans.back() != ch) {
                num--;
                ans.push_back(ch);
            } else {
                int num = pq.top().first;
                char ch = pq.top().second;
                pq.pop();
                if(ans.back() != ch) {
                    ans.push_back(ch);
                    if(num > 1) pq.push({num - 1, ch});
                } else return "";
            }
            if(num) pq.push({num, ch});
        }
        return ans;
    }
};