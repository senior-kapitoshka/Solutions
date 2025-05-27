let FilterNumbers = function(str) {
    return str.split('').filter(c => !(parseInt(c)>=0 && parseInt(c)<=9)).join('');
  }

  /////////////
  var FilterNumbers = function(str) {
    return str.split('').filter(c => isNaN(c)).join('');
  }
  //////////
  const FilterNumbers = str => str.replace(/\d/g, '');