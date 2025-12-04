const asteriscIt=(n)=>{ 
    let str;
    if(typeof n === "number")str = n.toString();
    else if(Array.isArray(n)) str=n.map(x=>x.toString()).join('');
    else if (typeof n === "string") str=n; 
    let m=str.length;
    let res='';
    for(let i=0;i<m-1;++i){
      if((+str[i])%2===0 && (+str[i+1])%2===0){
        res+=str[i] +'*'; 
      }else{
        res+=str[i]; 
      }
    }
    res+=str[m-1];
    return res;
  }

/////////////
Array.prototype.toString = function() { return this.join(''); };

function asteriscIt(n = '') {
  return n.toString().replace(/([02468])(?=[02468])/g, '$1*');
};

/////////
function asteriscIt(n) { 
    let str = '';
    if ( typeof n === 'object' ){
      str =  [...n.join('')].map( (el, i, arr)=> el % 2 || arr[i+1] % 2 ? el : el + '*' ).join('')
    }else{
      str = [...[] + n].map((el, i, arr)=> el % 2 || arr[i+1] % 2 ? el : el + '*' ).join('')
    }
    return str.endsWith('*') ? str.slice(0, -1) : str;
  };

////////////////  /
