function Node(data) {
    this.data = data;
    this.next = null;
  }
  
  function Context(source, dest) {
    this.source = source;
    this.dest = dest;
  }
  
  function moveNode(sc, dt) {
    if(sc === null) throw new Error("Error"); 
    let n = new Node(sc.data);
    if(dt === null)  dt=n;
    else{
      n.next=dt;
      dt=n;
    }
    sc.data=sc.next.data;
    sc.next=sc.next.next;
    return new Context(sc, dt);
  }

  ///////////
  function Node(data, nxt = null) {
    this.data = data, this.next = nxt;
  }
  function Context(source, dest) {
    this.source = source, this.dest = dest;
  }
  function moveNode(source, dest) {
    if(!source) throw "Error"
    return new Context(source.next, new Node(source.data, dest));
  }
  ///////
  function Node(data) {
    this.data = data;
    this.next = null;
  }
  
  function Context(source, dest) {
    this.source = source;
    this.dest = dest;
  }
  
  function moveNode(source, dest) {
    if (!source) throw Error();
    
    const newSource = source.next;
    source.next = dest;
    dest = source;
    return new Context(newSource, dest);
  }
  /////////////
  function Node(data) {
    this.data = data;
    this.next = null;
  }
  
  function Context(source, dest) {
    this.source = source;
    this.dest = dest;
  }
  
  function moveNode(a, b) {
    if (a == null) throw 'empty';
    let n = a;
    a = a.next;
    n.next = b;
    b = n;
    return new Context(a, b);
  }