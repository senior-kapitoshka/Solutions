class Class {
    static foo = 42;
  
    static foo() {
      return this.foo;
    }
  }

  //////////////////

  class Class {
    static #foo = 42;
  
    static get foo() {
      return Class.#foo;
    }
  }
  /////////
  class Class {
    static #foo = 42;
  
    static get foo() {
      return this.hasOwnProperty('foo') ? this.#foo : Class.#foo;
    }
  }
  /////////
  class Class { 
    static #foo = 42;  
    static get foo() { 
        let func = () => { 
            return Class.#foo; 
        }
        return func(); 
    }
}