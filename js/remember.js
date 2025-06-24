function remember(str) {
    return str.split('').reduce((pair,curr)=>{
      if(pair[0].includes(curr) && !pair[1].includes(curr)){
        pair[1].push(curr);
      }else if(!pair[0].includes(curr)){
        pair[0].push(curr);
      }
      return pair;
    },[[],[]])[1]
  }
  
  /* let dict=str.split('').reduce((dict,curr,i)=>{
      dict[curr]=dict[curr]?[dict[curr][0]+1,dict[curr][1]]:[1,i];
      return dict;
    },{});
    let k=Object.keys(dict).filter(_=>dict[_][0]>1);
    return  k.sort((l,r)=>dict[r][1]-dict[l][1]);*/
    //////////////////////
    function remember(str) {  
        return str.split('')
        .filter((item,i,allItems) => i !== allItems.indexOf(item))
        .filter((item,i,allItems) => i === allItems.indexOf(item));
    }
    ////////////////
    function remember(str) {
        var result = [];
        var counts = {};
        
        for (var i = 0; i < str.length; i++) {
          var c = str[i];
          counts[c] = (counts.hasOwnProperty(c) ? counts[c] : 0) + 1;
          
          if (counts[c] === 2) {
            result.push(c);
          }
        }
        
        return result;
      }
      ////////////
      const remember = s => [ ... new Set( [ ... s ].filter( (v,i) => s.slice(0,i).includes(v) ) ) ] ;