function Node(data) {
    this.data = data === undefined ? null : data;
    this.next = null;
  }
  
  function reverse(head) {
    if(!head) return null;
    if(!head.next) return head;
    let f=head,s=head.next;
    head.next=null;
    while(s){
      let t=s.next;
      s.next=f;
      f=s;
      s=t;
    }
    return f;
  }

  //////////
  function Node(data = null, next = null) {
    this.data = data
    this.next = next
  }
  
  function reverse(list, prev = null) {
    return list ? reverse(list.next, new Node(list.data, prev)) : prev
  }
  ///////
  function Node(data, next) {
    this.data = data === undefined ? null : data;
    this.next = next;
  }
  
  function reverse(head) {
    if (!head) {
      return null;
    }
    var reversedList = null;
    while (head) {
      reversedList = new Node(head.data , reversedList);
      head = head.next;
    }
    return reversedList;    
  }
  //////////
  