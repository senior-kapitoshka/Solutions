class Person {
  constructor(name) {
    this.name = name;
  }
  greet(you) {
    return `Hello ${you}, my name is ${this.name}`;
  }
}
//////////
function Person(name){
  this.name = name
}

Person.prototype.greet = function(yourName){
  return "Hello " + yourName + ", my name is " + this.name
}
//////////
class Person {
    constructor(name){
        this.name = name;      
        this.greet = (yourName) => `Hello ${yourName}, my name is ${this.name}`
  }
}
//////////
function Person(n){
  this.name=n
  this.greet=(s)=>`Hello ${s}, my name is ${n}`
}