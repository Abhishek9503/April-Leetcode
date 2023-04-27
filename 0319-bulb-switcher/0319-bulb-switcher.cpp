class Solution {
public:
    int bulbSwitch(int n) {
                  // return sqrt(n);
        
     
        // ct_divisors(n);
        // int ans = 0;
        // int i = 1;
        // for(i = 1; i*i<=n; i++) if(divs[i]%2 != 0) ans++;
        // for(i; i<=n; i++) if(divs[i]%2 == 0) ans++;
        // return ans;

        //works
        int ans = 0;
        for(int i = 1; i*i<=n; i++){
            ans++;
        }
        return ans;
      

    }
};