function uniqueSum(lst){
    return lst.length===0?null
          :Object.keys(lst.reduce((dict,curr)=>{
                  dict[curr]=(dict[curr]||0)+1;
                    return dict;
              },{}))
                .reduce((sum,curr)=>sum+parseInt(curr),0);
  }

  /////////////
  function uniqueSum(lst){
    return [...new Set(lst)].reduce((a,b)=>a+b,null);
  }

  //////////
  