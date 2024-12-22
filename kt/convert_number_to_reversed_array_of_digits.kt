object Kata {
  fun digitize(n:Long):IntArray {
    return n.toString().toCharArray().reversed().map({ it.toString().toInt() }).toIntArray()
  }
}
///////////
object Kata {
  fun digitize(n:Long):IntArray {
  
  var result = n.toString().map { it.toString().toInt() }.toIntArray();

    return result.reversedArray();
  }
}
//////////
object Kata {
    fun digitize(n: Long) = "$n".reversed().map { "$it".toInt() }.toIntArray()
}
/////////
object Kata {
  fun digitize(n:Long):IntArray {
     return n.toString()
            .toList()
            .map { it.toString().toInt() }
            .asReversed()
            .toIntArray()
  }
}
//////////
