function scratch(l){
    return l.reduce((sum,curr)=>{
      let a=curr.split(' ');
      return sum+=(a[0]===a[1] && a[1]===a[2])?
        parseInt(a[3]):0;
    },0);
  }
  ///////////
  function scratch(lottery){
    return lottery.map( e => e.split(" ") )
                  .filter( array => array[0] === array[1] && array[1] === array[2] )
                  .map( s => parseInt(s[3]) )
                  .reduce( (a, b) => a + b, 0);
  }
  ////////////
  const scratch = lottery =>
  lottery.reduce((pre, val) => pre + /(\w+ )\1\1/.test(val) * val.replace(/\D/g, ``), 0);
  /////////////
  function scratch(lottery) {
    return lottery
      .reduce((acc,curr) => {
        let [ one, two, three, bonus] = curr.split(' ');
        return acc + (one === two && two === three ? +bonus : 0);
      }, 0);
  }