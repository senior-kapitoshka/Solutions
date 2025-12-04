function maximumSeating(sts) {
    let res =0;
    let n= sts.length;
    if(n<=3){
      if(sts.every(x=>x===0)){
        return 1;
      }else return 0;
    }
    for(let i=0;i<n;){
      if(i===0){
        if(sts[i]===0 && sts[i+1]===0 && sts[i+2]===0){
          ++res;
          i+=3;
        }else{
          ++i;
        }
      }else if(i===n-1){
        if(sts[i]===0 && sts[i-1]===0 && sts[i-2]===0){
          ++res;
          ++i;
        }else{
          ++i;
        }
      }else{
        if(sts[i]===0 && sts[i-1]===0 && sts[i-2]===0 && 
            sts[i]===0 && sts[i+1]===0 && sts[i+2]===0){
          ++res;
          i+=3;
        }else{
          ++i;
        }
      }
    }
  return res;
  }

  ///////////

  function maximumSeating(seats) {
    let count = 0;
    
    seats.slice().forEach((_, i, arr) => {
      if (arr.slice(Math.max(0, i - 2), i + 3).every((n) => !n)) {
        count++;
        arr[i] = 1;
      }    
    });
     
    return count;
  }

  /////////////
  function maximumSeating(seats) {
    return (seats.join('').match(/(?:^|00)0(?=00|$)|(^0{1,3}$)/g) || []).length;
  }

  //////////
  function maximumSeating(seats) {
    let amount = 0;
    for ( let i = 0; i < seats.length; i++){
     let left1 = seats[i-1] || 0;
     let left2 = seats[i-2] || 0;
     let right1 = seats[i+1] || 0;
     let right2 = seats[i+2] || 0;
   //   console.log(i, left1, left2, right1, right2);
     if (seats[i] === 0 && left1 === 0 && left2 === 0 && right1 === 0 && right2 === 0) {
       amount++;
       i += 2;
     }
    }
     return amount;
   }

   /////////
   function maximumSeating(seats) {
    let padded = [0, 0, ...seats, 0, 0];
    let count = 0;
    for (let i = 2; i < padded.length - 2; i++) {
        if (padded[i] === 0 && padded[i - 1] === 0 && padded[i - 2] === 0
            && padded[i + 1] === 0 && padded[i + 2] === 0) {
            padded[i] = 1;
            count++;
        }
    }
    return count;
}