class Node {

    int data;
    Node next = null;
    
    Node(final int data) {
      this.data = data;
    }
    Node(final int data,Node nxt) {
      this.data = data;
      next=nxt;
    }
    
    public static Node push(final Node head, final int data) {
      Node toPush=new Node(data);
      toPush.next=head;
      Node c=head;
      if(head==null) return new Node(data);
      else{
            
            for(;head.next!=null;c=c.next);
            c.next=toPush;
      }
      return toPush; // FIXME - Your code goes here
    }
    
    public static Node buildOneTwoThree() {
      return new Node(1,new Node(2,new Node(3))); // FIXME - Your code goes here
    }
  }

  ///////////////
  class Node {
    int data;
    Node next;
  
    Node(int data) {
      this(null, data);
    }
  
    Node(Node child, int data) {
      this.next = child;
      this.data = data;
    }
  
    static Node push(Node head, int data) {
      return new Node(head, data);
    }
  
    static Node buildOneTwoThree() {
      return new Node(new Node(new Node(3), 2), 1);
    }
  }