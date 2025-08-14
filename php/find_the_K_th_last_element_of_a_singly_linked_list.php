/*
  Predefined class for list nodes:
  
  class Node {
    public $data, $next;
    public function __construct($data, $next = NULL) {
      $this->data = $data;
      $this->next = $next;
    }
  }
*/
/*function reverse($h){
  $first=$h;
  $second=$h->next;
  $h->next=null;
  $sz=0;
  while($second!=null){
    ++$sz;
    $tmp=$second->next;
    $second->next=$first;
    $first=$second;
    $second=$tmp;
  }
  return [$first,$sz];
}

function get_kth_last_element($h, $k) {
  if($k<0) return null;
  if($h==null || $h->next==null) return $h;
  [$h,$sz]=reverse($h);
  if($k>$sz){
    [$h,$sz]=reverse($h);
    return null;
  } 
  $res=$h;
  if($k==0){
    [$h,$sz]=reverse($h);
    return $res;
  } 
  for($i=0;$i<$k;++$i){
    if($res->next!=null)$res=$res->next;
    else{
      [$h,$sz]=reverse($h);
      return null;
    } 
  }
  [$h,$sz]=reverse($h);
  return $res;
}*/

function get_kth_last_element($h, $k) {
  if ($k < 0 || $h === null) return null;

  $fast = $h;
  $slow = $h;

  for ($i = 0; $i < $k; ++$i) {
    if ($fast->next === null) return null;
    $fast = $fast->next;
  }

  while ($fast->next !== null) {
    $fast = $fast->next;
    $slow = $slow->next;
  }

  return $slow;
}



//////////////////
