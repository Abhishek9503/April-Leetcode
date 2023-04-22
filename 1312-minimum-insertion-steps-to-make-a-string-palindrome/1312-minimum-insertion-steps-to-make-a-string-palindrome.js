
function dp(i, j, s, mem){
    if(i >= j) return 0
    if(mem[i][j] != -1) return mem[i][j]
    if(s[i] === s[j]) return mem[i][j] = dp(i+1, j-1, s, mem)
    else return mem[i][j] = 1 + Math.min(dp(i, j-1, s, mem), dp(i+1, j, s, mem))
}

var minInsertions = function(s) {
    const mem = Array.from({length: 501}, ()=> new Array(501).fill(-1))
    return dp(0, s.length-1, s, mem)
};