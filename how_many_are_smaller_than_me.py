def smaller(arr):
    if len(arr)==1:return [0]
    cnt =  0;
    for i in arr[1:]:
        if arr[0]>i:
            cnt+=1
    return [cnt]+smaller(arr[1:])


###################################
def smaller(arr):
    res_list = []                      
    for i in range(len(arr)):            # for each number in list
        tally = 0                      # init tally (reset for each number)
        for next_num in arr[i+1::]:   # arr[i+1::] = rest of list without this number               
            if next_num < arr[i]:     # if next_num is smaller
                tally += 1            # add 1 to tally
        res_list.append(tally)   # add tally to list
    return res_list

############################
def smaller(arr):
    return [sum(b < a for b in arr[i + 1:]) for i, a in enumerate(arr)]