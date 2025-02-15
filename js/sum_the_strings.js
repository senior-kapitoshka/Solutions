function sumArr(a,b) {
    let res=[];
    for(let i=0,n=a.length;i<n;++i){
      res[i]=(a[i]===""&&b[i]==="")?"0":
              a[i]===""?b[i]:
              b[i]===""?a[i]:
        new String((Number.parseInt(a[i])+Number.parseInt(b[i])));
    }
    return res;
  }

  //////////////
  function sumArr(a, b) {
    return a.map((x, i) => String(Number(x) + Number(b[i])))
  }