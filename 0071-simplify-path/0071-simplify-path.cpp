class Solution {
public:
    string simplifyPath(string path) {
        string token = "";
        
        stringstream ss(path);
        vector<string> st;
        
        while(getline(ss, token, '/')) {

            if(token == "" || token == ".") continue;
            
            if (token != "..") 
                st.push_back(token);
            else if (!st.empty()) 
                st.pop_back();
        }
        
        string result = "";
        
        for(auto &token : st) {
            result += "/" + token;
        }
        
        return result.empty() ? "/" : result;
    }
};