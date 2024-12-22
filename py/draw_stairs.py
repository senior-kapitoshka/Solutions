def draw_stairs(n):
    res=""
    ws=" "
    for i in range (1,n):
        res=res+"I\n"+ws*i
    return res+"I" 


###########################33
def draw_stairs(n):
    return '\n'.join(' '*i+'I' for i in range(n))
########################3
