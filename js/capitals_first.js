function capitalsFirst(str){
    return str.split(" ").filter(word => /^[A-Za-z]/.test(word)).sort((a,b)=>{
      let x=a[0];
      let y=b[0];
      if(x===x.toUpperCase() && y===y.toUpperCase()){
        return 0;
      }else if(x===x.toUpperCase() && y!==y.toUpperCase()){
        return -1;
      }else if(x!==x.toUpperCase() && y===y.toUpperCase()){
        return 1;
      }
    }).join(" ");
  }

  /////////////////
  function capitalsFirst(str){
	let words = str.split(' ');
  let upper = words.filter(function(x) { return x.charAt(0).match(/[A-Z]/) });
  let lower = words.filter(function(x) { return x.charAt(0).match(/[a-z]/) });
  return upper.concat(lower).join(' ');
}

/////////////

function capitalsFirst(str) {
    return str
      .split(" ")
      .filter(([a]) => a >= "a" && a <= "z" || a >= "A" && a <= "Z")
      .sort(([a], [b]) => a < "a" && b >= "a" ? -1 : a >= "a" && b < "a" ? 1 : 0)
      .join(" ")
  }

  ////////////

  const capitalsFirst = str =>
  (fn => [...fn(/^[A-Z]/), ...fn(/^[a-z]/)].join(` `))
  (reg => str.split(` `).filter(val => reg.test(val)));

  /////////

  const capitalsFirst = s => s
  .split` `
  .filter(e => /^[a-z]/i.test(e))
  .sort((x, y) => (y[0] === y[0].toUpperCase()) - (x[0] === x[0].toUpperCase()))
  .join` `;

/////////////

function capitalsFirst(str){
    var s1=str.match(/( |^)[A-Z]([^ ]+)?(?= |$)/g)||[];
    var s2=str.match(/( |^)[a-z]([^ ]+)?(?= |$)/g)||[];
    return s1.concat(s2).map(x=>x.trim()).join(" ");
  }