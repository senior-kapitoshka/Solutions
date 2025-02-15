var _originalToString = function(func) {
    console.log(Function.toString.apply(func));
    return Function.toString.apply(func);
  };

  ///////////
  var _originalToString = function(func) {
    var temp = func['toString'];
    delete func['toString'];
    var str = func.toString();
    func['toString'] = temp;
    return str;
  };

  ///////////
  