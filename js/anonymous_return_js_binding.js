//https://alistapart.com/article/getoutbindingsituations/

name = 'The Window';
var alpha = {
  name : 'My Alpha',
  getNameFunc : function() {
    return function() {
      return this.name;
    }.bind(this)
  }
};

/////////////////
name = 'The Window';

var alpha = {
    name : 'My Alpha',
    getNameFunc : function(){
      var self = this;
      return function(){
        return self.name;
      };
    }
};

/////////////////
name = 'The Window';

var alpha = {
    name : 'My Alpha',
    getNameFunc : function() {
        return () => this.name;
    }
};
////////////////
