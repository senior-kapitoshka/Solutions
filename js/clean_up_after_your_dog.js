function crap(x, bags, cap){
    let dog=false;
    let cnt=x.flat().reduce((cnt,curr)=>{
      if(curr==='D') dog=true;
      return cnt+=curr==='@';
    },0);
    let o=bags*cap;
    return dog?"Dog!!":cnt<=o?"Clean":"Cr@p";
  }
  ////////////////
  function crap(x, bags, cap){
    var yard = x.reduce( (a, b) => a.concat(b) );
    return yard.includes('D') ? 'Dog!!' : bags * cap - yard.filter( val => val === '@' ).length > 0 ? 'Clean' : 'Cr@p';
  }
  ///////////
  const crap = (x, bags, cap) =>
  `${x}`.includes(`D`) ? `Dog!!` : `${x}`.split(`@`).length > bags * cap ? `Cr@p` : `Clean`;