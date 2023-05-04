class Solution {
public:

    bool removeSenator(string &senate, char ch, int idx) {
        bool loopAround = false;
        
        while(true) {
            
            if(idx == 0) {
                loopAround = true;
            }
            
            if(senate[idx] == ch) {
                senate.erase(begin(senate) + idx);
                break;
            }
            
            idx = (idx+1)%(senate.length());
            
        }
        
        return loopAround;
    }
    
    string predictPartyVictory(string senate) {
        
        int R_Count = count(begin(senate), end(senate), 'R');
        int D_Count = senate.length() - R_Count;
        
        
        int idx = 0;
        
        while(R_Count > 0 && D_Count > 0) {
            
            if(senate[idx] == 'R') {
                bool checkRemoval = removeSenator(senate, 'D', (idx+1)%(senate.length()));
                D_Count--;
                if(checkRemoval) {
                    idx--;
                }
            } else {
                bool checkRemoval = removeSenator(senate, 'R', (idx+1)%(senate.length()));
                R_Count--;
                if(checkRemoval) {
                    idx--;
                }
            }
            
            idx = (idx+1)%(senate.length());
            
        }
        
        return R_Count == 0 ? "Dire" : "Radiant";
        
    }
};