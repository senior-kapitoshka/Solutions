function* generator(x=1) {
    while(1){
      let res = yield x++;
      if(res!==undefined) x=res;
    }
  }
  //res === undefined, если в next() не передано аргумента,
  // либо это самый первый next()

  ////////////
  function* generator(i = 1) {
    while(true){
      var value = yield i++;
      i = value || i;
    }
  }

  /////////////
  function* generator() {
    let a = 1, b;
    while(true){
      b = yield b || a++;
    }
  }
