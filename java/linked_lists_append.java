class Node {

	int data;
	Node next = null;

	Node(final int data) {
		this.data = data;
	}

	public Node(int data, Node next) {
		this.data = data;
		this.next = next;
	}

	public static Node append(Node listA, Node listB) {
    if(listA==null) return listB;
    if(listB==null) return listA;
    Node t=listA;
    while(t.next!=null) t=t.next;
    t.next=listB;
		return listA;
	}
}

/////////////////
