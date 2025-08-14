function factory(x){
    return function(a){
      return a.map(i=>i*x);
    }
   }

/////////
function factory(x){
    return array => array.map( a => a*x );
}