LList.prototype[Symbol.iterator]=function*(){
    for(let n=this.head;n;n=n.next){
      if(!n) return;
      yield n.value;
    }
  }
  ////////////
  LList.prototype[Symbol.iterator] = function() {
    return {
      node: this.head,
      next() {
        let hold = this.node;
        this.node = hold ? this.node.next : null;
        return {
          value: hold ? hold.value : undefined,
          done: hold ? false : true
        };
      }
    };
  }
  /////////
  Object.defineProperty( LList.prototype, Symbol.iterator, { *value() {
    if ( this.head ) yield* this.head;  
  } } );
  
  Object.defineProperty( Node.prototype, Symbol.iterator, { *value() {
    yield this.value;
    if ( this.next ) yield* this.next;
  } } );