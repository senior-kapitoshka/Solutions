function addProperty(obj, prop, value) {
    if (!obj.hasOwnProperty(prop)) {
      obj[prop] = value
    } else {
      throw new Error()
    }
  }
  ///////////
  function addProperty(obj, prop, value) {
    if (prop in obj) throw new Error()
    obj[prop] = value
  }
  /////////
  const addProperty = (obj, prop, value) =>
  prop in obj ? (() => {throw new Error()})() : obj[prop] = value;
  //////////
  