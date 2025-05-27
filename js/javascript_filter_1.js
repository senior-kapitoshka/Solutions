function searchNames( ls ){
    return ls.filter((i)=>i[0].match(/^[a-z|_]+_$/));
  }
  //////////////
  function searchNames( logins ){
    return logins.filter(function (login) { return login[0].slice(-1) === '_' });
  }
  //////////
  function searchNames( logins ){
    return logins.filter(a=>a[0].endsWith('_'));
  }
  //////////
  function searchNames( logins ){
    return logins.filter(function(arr){
      return arr[0].match(/_$/);});
  }
  /////////
  function searchNames(logins) {
    return logins.filter(x => /_$/g.test(x[0]))
}