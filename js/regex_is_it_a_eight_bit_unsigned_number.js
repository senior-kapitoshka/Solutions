String.prototype.eightBitNumber = function() {
    console.log(this);
    return /^([12][0-9]|[1-9]{0,1})[0-9]{1}$/.test(this) && parseInt(this)<=255;
  }
  ////////////
  String.prototype.eightBitNumber = function() {
    return /^(2([0-4]\d|5[0-5])|1\d\d|[1-9]?\d)$/.test(this);
}
///////////
String.prototype.eightBitNumber = function () {
    return String(+this) == this && +this >= 0 && +this <=255;
  };
  ////////
  String.prototype.eightBitNumber = function() {
    return /^[0-9]$|^[1-9][0-9]$|^1[0-9][0-9]$|^2[0-4][0-9]$|^25[0-5]$/.test(this);
  }
  ////////
  String.prototype.eightBitNumber = function() {
    return /^([1-9]?\d|1\d\d|2[0-4]\d|25[0-5])$/.test(this);
  }
  ////////
  String.prototype.eightBitNumber = function() {
    return /^(?:[1-9]?|1\d|2[0-4]|25(?![6-9]))\d$/.test(this);
  }