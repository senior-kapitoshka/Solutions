fun filterList(l: List<Any>): List<Int> {
    return l.filterIsInstance<Int>()
}

////////////////
fun filterList(l: List<Any>): List<Int> {
    var res: MutableList<Int> = mutableListOf()
    
    for (m in l) {
        // checking l
        
        if (!(m is Int)) {
            continue
        }
        
        res.add(m)
    }
    
    return res.toList()
}

////////////
fun filterList(l: List<Any>): List<Int> {
    var arr = mutableListOf<Int>()
    for (i in l){
        if (i is Int) arr.add(i)
    }
    return arr
}

/////////////////
