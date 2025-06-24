
var findMaxConsecutiveOnes = function(nums) {
   return nums.reduce(([cnt,max],curr,i)=>{
      if(curr===1) cnt++;
      else if(curr===0){
              max=Math.max(cnt,max);
              cnt=0;
      }
      if(i===nums.length-1) max=Math.max(cnt,max);
      return [cnt,max]; 
   },[0,0])[1];
};