fun catchSignChange(a: Array<Int>): Int {
    if(a.size==0)return 0;
    var flag:Boolean = if(a[0]>=0) true else false;
    var cnt:Int=0;
    for(i in a){
            if(i<0 && flag){
              ++cnt;
                flag=false;
            }
            else if(i>=0 && !flag){
                ++cnt;
                flag=true;
            }
    }
    return cnt;
}

////////////////
fun catchSignChange(arr: Array<Int>): Int = 
arr.map { it < 0 }
                .zipWithNext { a, b -> a != b }
                                            .count { it }

//////////////
fun catchSignChange(arr: Array<Int>): Int =
  arr.asSequence().windowed(2).count { (x, y) -> (x >= 0) != (y >= 0) }

//////////////
fun catchSignChange(arr: Array<Int>) = 
    arr
    .map{if (it==0) 1 else it}
    .zipWithNext{a,b -> if (a*b < 0) 1 else 0}
    .sum()
/////////////
import kotlin.math.*;
fun catchSignChange(arr: Array<Int>): Int {
    return arr.toList().zipWithNext().count { (a, b) ->
        val sign_a = if (a < 0) -1 else 1
        val sign_b = if (b < 0) -1 else 1
        sign_a != sign_b 
    }
}
//////////////
import kotlin.math.abs
import kotlin.math.absoluteValue

fun catchSignChange(arr: Array<Int>): Int {
    return arr.map { if (it == 0) 1 else it }
        .zipWithNext()
        .filter { it.first * it.second != it.first.absoluteValue * it.second.absoluteValue }
        .count()
}
/////////////////
