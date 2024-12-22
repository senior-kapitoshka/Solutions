function evil(n) {
    var res=0;
    for(;n > 0; n = n >> 1) res += n & 1;
    return res&1? "It's Odious!" : "It's Evil!";
  }

  ////////////
  function evil(n) {
    return n.toString(2).match(/1/g).length % 2 ? 'It\'s Odious!' : 'It\'s Evil!';
}

////////////
const evil = (n) => [...(n).toString(2)].filter(e => e==1).length % 2 == 0 ? "It's Evil!" : "It's Odious!";

///////////
const evil = n => 
    `It's ${n.toString(2).replace(/0/g, ``).length % 2 ? `Odious` : `Evil`}!`;