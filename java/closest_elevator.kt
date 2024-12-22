fun elevator(l: Int, r: Int, cl: Int): String {
  if((cl==l && r!=cl) || 
          (cl==0 &&r==2 && l==1) 
                      || (cl==2 &&r==0 && l==1)) return "left" 
   return "right"
}

/////////////////
import kotlin.math.abs
fun elevator(left: Int, right: Int, call: Int) = if (abs(call - left) < abs(call - right)) "left" else "right"

/////////////////
import kotlin.math.abs

fun elevator(left: Int, right: Int, call: Int): String {
      return when {
        abs(call - right) <= abs(call - left) -> "right"
        else -> "left"
    }
}

///////////
fun elevator(left: Int, right: Int, call: Int) = 
    mapOf(left to "left", right to "right").filter {
        when (it.key == call) {
            true -> it.key == call
            false -> {
                when (Math.abs(call - right) <= Math.abs(call - left)) {
                    true -> it.key == right
                    false -> it.key == left
                }
            }
        }
    }.values.first()
///////////////
