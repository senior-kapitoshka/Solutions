fun include(arr: IntArray, it : Int): Boolean {
    return it in arr;
}

////////////////
fun include(arr: IntArray, item: Int) = item in arr

////////////////
fun include(arr: IntArray, item : Int) = arr.contains(item)

///////////
val include = IntArray::contains
/*
    The above solution leverages the function reference to IntArray.contains. 
    It is an abbreviated version of:

    val includes: (IntArray, Int) -> Boolean = IntArray::contains

    The example usage:

    includes(intArrayOf(1), 1)

    The function reference meets the same function signature.
*/

///////////
fun include(arr: IntArray, item : Int) = arr.any { it == item }

//////////////
fun include(arr: IntArray, item : Int): Boolean {
    var flag = false
    for(number in arr) {
        if(item == number) flag = true
    }
    return flag 
}

/////////////
