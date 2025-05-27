function Node(data) {
    this.data = data;
    this.next = null;
  }
  
  function insertNth(head, id, data) {
    let n=new Node(data);
    if(id===0){
      n.next=head;
      head=n;
    }else{
      for(let curr=head, dummy=null,i=0;curr!=null;dummy=curr,curr=curr.next,++i){
        if(id===i){
          dummy.next=n;
          n.next=curr;
          break;
        }
        if(curr.next===null && i+1===id){
          curr.next=n;
          break;
        }else if(curr.next===null && i+1!==id){
          throw new Error("Error");
        }
      }
    }
    for(let curr=head;curr.next!=null;curr=curr.next){
      console.log(curr.data);
    }
     console.log("\n");
    return head;
  }

  //////////////
  function Node(data, nxt) {
    this.data = data;
    this.next = nxt;
  }
  function insertNth(head, index, data) {
    if(index == 0) return new Node(data, head);
    if(head && index > 0) {
      head.next = insertNth(head.next, index - 1, data);
      return head;
    }
    throw "Error";
  }
  //////////
  function Node(data) {
    this.data = data;
    this.next = null;
  }
  
  function insertNth(head, index, data) {
    if (index == 0) {
      return push(head, data);
    }
  
    head.next = insertNth(head.next, index - 1, data);
  
    return head;
  }
  ///////////
  class Node {
    constructor(data, next = null) {
      Object.assign(this, {data, next});
    }
  }
  
  const insertNth = (head, index, data) =>
    !index ? new Node(data, head) : (head.next = insertNth(head.next, --index, data), head);