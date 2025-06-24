List<int> cantBeatSoJoin(List<List<int>> n) {
  n.sort((l,r)=>
                r.fold(0,(sum,_)=>sum+_)-l.fold(0,(sum,_)=>sum+_)
               );
    return n.expand((_)=>_).toList();
}
///////////////
List<int> cantBeatSoJoin(List<List<int>> numbers) {
  numbers = numbers.where((n) => n.length > 0).toList();
  numbers.sort((a, b) => b.reduce((x, y) => x + y).compareTo(a.reduce((x, y) => x + y)));
  return numbers.expand((i) => i).toList();
}
///////////
