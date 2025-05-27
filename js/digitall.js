function digitAll(x){
    if(typeof x!=='string') return 'Invalid input !';
    return x.split('').filter(c=>(parseInt(c)>=0 && parseInt(c)<=9)).join('');
  }

  //////////////
  function digitAll(x) {
    return typeof(x) == 'string' ? x.replace(/\D/g, '') : 'Invalid input !';
  }

  /////////////
  function digitAll(x){
    return typeof x === 'string' ? x.replace(/[^\d]/g, '') : 'Invalid input !';
    
  }