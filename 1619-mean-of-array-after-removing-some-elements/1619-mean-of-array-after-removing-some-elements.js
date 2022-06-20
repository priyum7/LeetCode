/**
 * @param {number[]} arr
 * @return {number}
 */
var trimMean = function(arr) {
    
    let removeLength = arr.length * 0.05;
    let temparr = arr.sort((a,b)=>a-b).slice(removeLength, arr.length-removeLength)
    return temparr.reduce((acc, curr) => acc+curr, 0)/temparr.length
    
};