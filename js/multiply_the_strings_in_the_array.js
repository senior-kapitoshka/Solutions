function arrMultiply(ar){
    return String(ar.reduce((acc,curr)=>acc*Number(curr),1));
    
 }

 ///////////
 let arrMultiply = ([a, b]) => '' + (a * b);

 ///////////
 const arrMultiply = ([a, b]) => `${a * b}`; 