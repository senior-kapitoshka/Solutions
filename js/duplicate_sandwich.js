function duplicateSandwich(a) {
    let x,y,dict={};
    for(let i=0;i<a.length;++i){
      console.log(dict);
      if(dict[a[i]]!==undefined){
        x=dict[a[i]];
        y=i;
        break;
      }else{
        dict[a[i]]=i;
      }
    }
    return a.slice(x+1,y);
  }

  /////////
  const duplicateSandwich = (list) => {
    let duplicated = [...list].find(a => list.indexOf(a) !== list.lastIndexOf(a))
    return list.slice(list.indexOf(duplicated) + 1, list.lastIndexOf(duplicated))
  }

  /////////
  function duplicateSandwich(a) {
    for (let i = 0; i < a.length; i++)
      if (i != a.lastIndexOf(a[i])) return a.slice(i + 1, a.lastIndexOf(a[i]))
  }
  ////////
  const duplicateSandwich = a =>
  ((start, end) => a.slice(++start, end))
  (...[...a].reduce((pre, val, idx) => a.indexOf(val) === a.lastIndexOf(val) ? pre : [...pre, idx], []));
  ///////
  