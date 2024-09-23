def sum_no_duplicates(l):
    dict = {}
    res=0
    for i in l:
        dict[i] = dict.get(i, 0) + 1
    for i,j in  dict.items():
        if j==1:
            res+=i
    return res

######################
def sum_no_duplicates(l):
    return sum(n for n in set(l) if l.count(n) == 1)

###########################3
def sum_no_duplicates(l):
    new = []
    for x in l:
        if l.count(x) == 1:
            new.append(x)
    return sum(new)
            
