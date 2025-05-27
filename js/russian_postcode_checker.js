function zipvalidate(postcode){
    return /^[12346]{1}[0-9]{5}$/.test(postcode);
  }
  /////////////
  var zipvalidate = RegExp.prototype.test.bind(/^[12346]\d{5}$/);