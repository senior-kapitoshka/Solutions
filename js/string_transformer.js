function stringTransformer(str) {
    return str.split(" ").map((s)=>[...s].map((c)=>{
      let i=c.charCodeAt(0);
      return (i>=65 && i<=90)?c.toLowerCase():
                              c.toUpperCase();
    }).join("")).reverse().join(" ");
  }

  /////////
  function stringTransformer(str) {
    return str
      .split(' ')
      .reverse()
      .join(' ')
      .split('')
      .map(v => v == v.toUpperCase() ?
        v.toLowerCase() :
        v.toUpperCase())
      .join('');
  }

  //////////
  const stringTransformer = str =>
  str.split(` `).reverse().join(` `).replace(/./g, val => val[`to${val < `a` ? `Low` : `Upp`}erCase`]());