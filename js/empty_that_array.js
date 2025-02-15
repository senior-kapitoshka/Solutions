function empty(a) {
    a.length=0;
    return a;
  }
  ////////
  function empty(array) {
    array.splice(0, array.length);
    return array;
  }

  