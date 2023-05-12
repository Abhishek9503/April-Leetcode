class Solution { // This question is asked by google and it is of dynamix programming i have solve the question from code story with mik
public:
    int n;
    long long solve(int i,vector<vector<int>>&q , vector<long long>&t )
    {
        if(i>=n) return 0;
        
        
            if(t[i]!=-1)
                return t[i];
        
        long long taken=q[i][0]+ solve(i+q[i][1]+1,q,t);
        
        long long not_taken =solve(i+1,q,t);
        
        return  t[i]= max(taken,not_taken);
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        n=questions.size();
        
        vector<long long> t(n+1,-1);
        
        return solve(0,questions,t);
    }
};