function equalize(a){
    return a.map((i)=>{
                  let x=i-a[0];
                 return x>=0?`+${x}`:`${x}`;
                });
  }

  ///////////
  const equalize=a=>a.map(x=>("+"+(x-a[0])).replace("+-","-"))