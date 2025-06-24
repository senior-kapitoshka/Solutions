function sum(x,y) {
    if(y || y===0) return x+y; 
   return function(y){
     return x+y;
   };
  }

  /////////
  