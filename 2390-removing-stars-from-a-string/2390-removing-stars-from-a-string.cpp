// class Solution {
// public:
//     string removeStars(string s) {
//         vector<char> ch(s.size());
//         int j = 0;

//         for (int i = 0; i < s.length(); i++) {
//             if (s[i] == '*') {
//                 j--;
//             } else {
//                 ch[j++] = s[i];
//             }
//         }

//         string result = "";
//         for (int i = 0; i < j; i++) {
//             result.push_back(ch[i]);
//         }

//         return result;
//     }
// };



//Approach-2 (using string as stack)


class Solution {
public:
    string removeStars(string s) {
        string result = "";
        
        for(char &ch : s) {
            
            if(ch == '*') {
                result.pop_back();
            } else {
                result.push_back(ch);
            }
            
        }
        
        return result;
    }
};