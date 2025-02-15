function binRota(arr){
    var res=[];
    let n=arr.length;
    let m=arr[0].length;
    let flag=true;
    for(let i=0;i<n;++i){
      for(let j=flag?0:m-1;flag?(j<m):(j>=0);flag?++j:--j){
        res.push(arr[i][j]);
      }
      flag=!flag;
    }
    return res;
  
  }
  ///////////
  function binRota(arr){
    return arr.map((e,i) => i % 2 ? e.slice().reverse() : e)
              .reduce((acc,e) => acc.concat(e), []);  
  }

  ////////////
  function binRota(arr) {
    return arr.reduce(function(a, b, index) {
        return (index % 2 === 0) ? a.concat(b) : a.concat(b.reverse());
    });
}
///////////
const binRota = a => a.flatMap((r, i) => i % 2 ? r.map(_ => _).reverse() : r);
/////////
const binRota = arr =>
  [].concat(...arr.map((val, idx) => idx % 2 ? val.reverse() : val));