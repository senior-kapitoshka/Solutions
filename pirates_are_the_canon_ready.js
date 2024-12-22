const cannonsReady = (g) => {
    for(var [k,v] of Object.entries(g))
      switch(v){
        case "nay": return "Shiver me timbers!";
      }
    return "Fire!";
  }

  ///////////
  const cannonsReady = (gunners) => {
    for (var i in gunners) {
        if (gunners[i] == "nay") {
          return "Shiver me timbers!"
        }
    }
  return "Fire!"
}

////////////
const cannonsReady = (gunners) => {
    return Object.values(gunners).some(m => m === 'nay') ? 'Shiver me timbers!' : 'Fire!';
  }

  ///////////
  const cannonsReady = (gunners) => {
    return Object.values(gunners).includes('nay')?'Shiver me timbers!':'Fire!';
  }
  //////////
  const cannonsReady = a => Object.keys(a).every(g => a[g] === "aye") ? "Fire!" : "Shiver me timbers!";