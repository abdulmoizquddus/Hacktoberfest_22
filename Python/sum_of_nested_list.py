def sum_nestedlist( l ):
   
    # specify that global variable is
    # referred to here in this function
    total = 0
     
    for j in range(len(l)):
       
        if type(l[j]) == list :
           
            # call the same function if
            # the element is a list
            total+= sum_nestedlist(l[j])
        else:
           
            # if it's a single element
            # and not a list, add it to total
            total += l[j]  
             
    return total
             
print(sum_nestedlist([[1,2,3],[4,[5,6]],7]))
