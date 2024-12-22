fun firstReverseTry(a: IntArray) : IntArray {
    if(a.size==0) return a;
    var tmp:Int=a[a.size-1];
    a[a.size-1]=a[0];
    a[0]=tmp;
    return a;
}

/////////////
fun firstReverseTry(arr: IntArray) = 
if (arr.size < 2) arr
else arr.copyOf()
                .apply { this[0] = arr[lastIndex];
                         this[lastIndex] = arr[0] }
////////////////
fun firstReverseTry(arr: IntArray) = arr.toMutableList().mapIndexed { index, i ->
    when (index) {
        0 -> arr.last()
        arr.lastIndex -> arr.first()
        else -> i
    }
}.toIntArray()

////////////
fun firstReverseTry(arr: IntArray) = 
arr.clone()
    .also { if (it.lastIndex > 0) {
             it[0] = arr.last(); it[it.lastIndex] = arr.first()}
             }