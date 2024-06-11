def find_average(n):
    if len(n) == 0:
        return 0
    return sum(n)/len(n)
################################
def find_average(array):
    return sum(array) / len(array) if array else 0
########################
def find_average(array):
    try:
        return sum(array) / len(array)
    except ZeroDivisionError:
        return 0
    
    #################