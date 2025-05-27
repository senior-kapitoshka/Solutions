const {Buffer} = require('buffer');

String.prototype.toBase64 = function() {
  const buf = Buffer.from(this, 'utf-8');
  return buf.toString('base64');
}

String.prototype.fromBase64 = function() {
  const buf = Buffer.from(this, 'base64');
  return buf.toString('utf-8');
}

/////////////
String.prototype.toBase64 = function() {
    return new Buffer(this.toString()).toString('base64');
  }
  
  String.prototype.fromBase64 = function() {
    return new Buffer(this.toString(), 'base64').toString('utf8');
  }