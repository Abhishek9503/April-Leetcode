class Solution {
public:
    string truncateSentence(string s, int k) {
        string output="" ;
        int cnt=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]==' '){
                cnt++;
            }
            if(cnt==k){
                break;
            }
            output.push_back(s[i]);
        }
        return output;
    }
};