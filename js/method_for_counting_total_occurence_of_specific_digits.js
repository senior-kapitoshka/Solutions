function List(){
    this.countSpecDigits=function(il, dl){
     return dl.map(i=>[i,il.toString()
                       .split('')
                       .filter(j=>j===i.toString())
                       .length]);
    }
  }
  /////////////
  class List {
    countSpecDigits (integersList, digitsList) {
      return digitsList.map(val => [val, `${integersList}`.split(val).length - 1]);
    }
  }
  ///////////
  class List {
    countSpecDigits (i, d) {
      d = d.map(e => [e, 0]);
      return i.reduce((r, e) => r.concat(Math.abs(e).toString().split``), [])
              .reduce((r, e) => d.map(d => d[0] == e ? [d[0], ++d[1]] : d) , d);
    }
  }