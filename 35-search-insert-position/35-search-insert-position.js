/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    
    let result=0
    for(let i in nums)
    {
        if(nums[i]<target)
        {result = parseInt(i)+1}
        else if(target == nums[i]) {
            return i
        }
    }
    return result
};