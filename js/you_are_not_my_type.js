Array.prototype.ofType = function (t) {
    return this.filter((i)=>{
    if (t === String) {
      return typeof i === "string";
    } else if (t === Number) {
      return typeof i === "number";
    } else if (t === Boolean) {
      return typeof i === "boolean";
    } else {
      return i instanceof t;
    }
  });
}

////////////
Array.prototype.ofType = function (type) {
    return this.filter(i=>i instanceof type || (i != null && i.constructor === type));
}

///////////
Array.prototype.ofType = function (type) {
    return this.filter(item => {
      if (typeof item === 'object' || typeof item === 'function') {
        return item instanceof type
      } else {
        return typeof item === type.name.toLowerCase()
      }
    })
  }

  ///////////
  Array.prototype.ofType = function(type) {
    let object = (type !== Object) ? Object : (x) => x;
    return this.filter((x) => object(x) instanceof type);
}

//////
