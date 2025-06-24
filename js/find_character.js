function findCharacters(mx){
    let dict= mx.replace(/\n/g,'').split('')
      .reduce((res,curr)=>{
      res[curr]=res[curr]+1||1;
      return res;
    },{});
    let val=Math.min(...Object.values(dict));
    return [...Object.keys(dict)].filter((k)=>dict[k]===val)
      .sort((l,r)=>{
    const getOrder = (ch) => {
      if (/[A-Z]/.test(ch)) return ch.charCodeAt(0);       
      if (/[a-z]/.test(ch)) return 1000 + ch.charCodeAt(0); 
      if (/[0-9]/.test(ch)) return 2000 + ch.charCodeAt(0); 
      return 9999; 
    }
    return getOrder(l) - getOrder(r);
      }
    ).join('');
  }
  /////////////
  const findCharacters = matrix => {
    const hash = [...matrix.replace(/\n/g, '')]
    .reduce((acc, ch) => ({...acc, [ch]: ~~acc[ch] + 1}), {});
    const min = Math.min(...Object.values(hash));
    
    return Object.keys(hash)
    .filter(ch => hash[ch] === min)
    .sort().join``
    .replace(/(\d*)(.*)/, '$2$1');
  }
  ////////////////
  function findCharacters(matrix) {  
    return matrix
      .split``
      .sort()
      .join``
      .match(/(.)\1*/g)
      .sort((a, b) => a.length - b.length)    
      .filter((e, i, a) => e.length == a[0].length)    
      .map(a => a[0])
      .sort((a, b) => isNaN(b) - isNaN(a))    
      .join``
  }
  ///////////
  