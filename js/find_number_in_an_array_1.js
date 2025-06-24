//fail tests
function duplicateOrUnique(arr){
    arr.sort((a,b)=>a-b);
    let n=arr.length;
    if(arr[n-1]===n-1){
      for(let i=1;i<n;++i){
        if(arr[i]===arr[i-1]) return arr[i]; 
      }
    }else{
      for(let i=0;i<n;){
        if(i+1<n && arr[i]===arr[i+1]){
          i+=2;
        }else return arr[i]; 
      }
    }  
  }

////////////
const duplicateOrUnique = arr => {
    let i = arr.length-1, sum = 0;
    for ( ; i >= 0; i--) sum += arr[i];
    const lSum = ((arr.length-1) * arr.length)/2;
    
    if (sum > lSum) {
      return sum-lSum;
    } else {
      const n = (arr.length+1)/2;
      return (n * (n+1))-sum;
    }  
  }
  //////////
  function duplicateOrUnique(arr){ //sum version
    for(var sum=0,i=0,len=arr.length;i<len;i++) sum+=arr[i]
    var sum2=len*(len-1)/2,len3=(len+1)/2,sum3=len3*(len3+1)
    return sum>=sum3?sum-sum2:sum3-sum
  }
  function duplicateOrUnique(arr){ //bit version
    for(var xor1=0,len=arr.length,xor2=[len-1,1,1^(len-1),0][(len-1)%4],i=0,half= ~~((len+1)/2),dup=false;i<len;i++) {
      xor1^=arr[i]
      dup|=(arr[i]>half)
    }
    return dup?xor1^xor2:xor1
  }
  ////////////
    