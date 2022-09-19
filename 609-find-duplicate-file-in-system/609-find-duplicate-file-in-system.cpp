class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string> &paths) {
        map <string, int> m; 
        vector <vector <string>> ans, alpha;
        for(auto x: paths){
            string path, file, content;
            bool flag1 = 1, flag2 = 1; 
            for(auto y: x){
                if(y == ' ') flag1 = 0;
                if(flag1) path.push_back(y);
                else if(flag2) {
                    if(y == '(') flag2 = 0;
                    else if(y != ' ') file.push_back(y);
                } else {
                    if(y == ')') {
                        if(m.count(content)) {
                            int index = m[content];
                            ans[index].push_back(path + "/" + file);
                        } else {
                            m[content] = ans.size();
                            vector <string> temp;
                            temp.push_back(path + "/" + file);
                            ans.push_back(temp);
                        }
                        flag2 = 1; file.clear(); content.clear();
                    } else content.push_back(y);
                }
            } 
        }
        
        for(auto x: ans){
            if(x.size() > 1) alpha.push_back(x);
        }
        
        return alpha;
    }
};