oneEdge = 4
useArray = [list(range(i*oneEdge+1,(i+1)*oneEdge-1)) for i in range(1,oneEdge-1)]
useArray = [j for i in useArray for j in i]

print (useArray)
