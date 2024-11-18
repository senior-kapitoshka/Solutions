import java.util.*;

//list
public class CircularList<T> {
    private List<T>ls=new ArrayList<>();
    private int id;
    private int sz;
    public CircularList(final T... elem) {
       if(elem.length==0) throw new RuntimeException();
        ls.addAll(Arrays.asList(elem));
        id=-1;
        sz=elem.length;
    }

    T next() {
        if(id<sz-1) id++;
        else id=0;
        return ls.get(id);
    }

    T prev() {
        if(id>0) id--;
        else id=sz-1;
        return ls.get(id);
    }
}

////////////////////
//array
public class CircularList<T> {
    private int index=-1;
    private int length;
    final private T[] elements;
    
    public CircularList(final T... elements) {
        if(elements.length==0){throw new RuntimeException("${T}");}
        this.elements=elements;
        this.length=elements.length;
    }

    T next() {
        if(++index==length)index=0;
        return elements[index];
    }

    T prev() {
        if(--index<0)index=length-1;
        return elements[index];
    }
}
///////////////
//linked list

public class CircularList<T> {
  private Node<T> curr = null;
  private int lastOp = 0;
  
  @SafeVarargs
  public CircularList(final T... elements) {
    curr = new Node<>(elements[0]);
    Node<T> prev = curr;
    
    for(int i = 1; i < elements.length; ++i) {
      prev.next = new Node<>(prev,elements[i]);
      prev = prev.next;
    }
    
    prev.next = curr;
    curr.prev = prev;
  }
  
  T next() {
    if(lastOp == -1) {
      curr = curr.getNext().getNext();
    }
    
    T value = curr.getValue();
    curr = curr.getNext();
    lastOp = 1;
    return value;
  }
  
  T prev() {
    switch(lastOp) {
      case 0: curr = curr.getPrev(); break;
      case 1: curr = curr.getPrev().getPrev(); break;
    }
    
    T value = curr.getValue();
    curr = curr.getPrev();
    lastOp = -1;
    return value;
  }
  
  class Node<T> {
    private Node<T> prev,next;
    private T value;
    
    public Node(Node<T> prev,T value,Node<T> next) {
      this.prev = prev;
      this.value = value;
      this.next = next;
    }
    
    public Node(Node<T> prev,T value) {
      this(prev,value,null);
    }
    
    public Node(T value) {
      this(null,value,null);
    }
    
    public Node<T> getPrev() { return prev; }
    public T getValue() { return value; }
    public Node<T> getNext() { return next; }
  }
}

///////////////////
//linked list

public class CircularList<T> {


    private Entry current = null;
    private boolean first = true;

    public CircularList(final T... elements) {
       if (elements.length==0)throw new IllegalArgumentException(); 
       for (T t : elements) {
            Entry n = new Entry(t);
            if (current == null) {
                n.next = n;
                n.prev = n;
                current = n;
            } else {
                n.next = current.next;
                n.prev = current;
                n.next.prev = n;
                current.next = n;
            }
            n.data = t;
            current = n;
        }
    }

    private class Entry {
        private T data;
        private Entry next;
        private Entry prev;

        private Entry(T data) {
            this.data = data;
        }
    }

    T next() {
        current = current.next;
        first = false;
        return current.data;
        }
    T prev () {
            if(first){
                first=false;
                return current.data;
            }
            current = current.prev;
            return current.data;
        }
    }

