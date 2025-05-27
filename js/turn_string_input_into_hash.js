function strToHash(str){
    let mch=str.matchAll("([a-zA-Z]+)=([0-9]+)");
     let obj={};
     [...mch].forEach(m=> obj[m[1]]=parseInt(m[2]));
     return obj;
   }

   //////////
   function strToHash(str) {
  
    let match
    ,   regex = /(\S+)=(-?\d+)/g
    ,    hash = {};
    
    while (match = regex.exec(str))
      hash[match[1]] = parseInt(match[2]);
    
    return hash;
    
  }
  ///////////
  const strToHash = str =>
  JSON.parse(`{${str.replace(/(\w+)=(\d+)/g, (_, key, val) => `"${key}":${val}`)}}`);
  ///////
  const strToHash = str => str ?
  Object.fromEntries(str.split`, `.map(i => i.split`=`).map(([key, val]) => [key, +val])) : {}
  ////////
  const strToHash = str => JSON.parse(`{${str.replace(/(\w+)=/g, '"$1":')}}`);
  ///////
  function strToHash(str){
    return str? str.split(', ').reduce((a,c) => {a[c.split('=')[0]]=+c.split('=')[1];return a},{}):{};
  }