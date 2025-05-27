function validate(msg){
    console.log(msg);
    return  /^MDZHB [0-9]{2} [0-9]{3} [A-Z]+ [0-9]{2} [0-9]{2} [0-9]{2} [0-9]{2}$/g.test(msg);
  }
  //////////////
  const validate = msg => /^MDZHB [\d]{2} [\d]{3} [A-Z]+( [\d]{2}){4}$/.test(msg);
  ///////////
  