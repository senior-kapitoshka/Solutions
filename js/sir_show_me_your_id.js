function showMe(ID) {
    return /^[A-Z][a-z]+$/.test(ID) ||  /^[A-Z][a-z]+-[A-Z][a-z]+$/.test(ID) ||
      /^[A-Z][a-z]+-[A-Z][a-z]+-[A-Z][a-z]+$/.test(ID) || /^[A-Z][a-z]+-[A-Z][a-z]+-[A-Z][a-z]+-[A-Z][a-z]+$/.test(ID);
  }

  ///////////
  function showMe(yourID){
    return /^[A-Z]\w+(-[A-Z]\w+)*$/.test(yourID);
  }
  ///////////
  const showMe=(S)=>/^[A-Z][a-z]+(?:-[A-Z][a-z]+)*$/.test(S)

  /////////////
  