import numpy as np

array = [[1,-2,1.5,0],[1,-0.5,-2,-1.5],[0,1,-1,-1.5]]
desired=[1,-1,1]

x = np.array(array)

weight = [1,-1,0,0.5]

output = []

c = 1
p = 0
def signum(y):
    if(y>0): y=1
    elif(y<0): y=-1
    return y


list=[]
a=100
while(desired != output):
    output=[]

    for i in range(3):
        y = 0

        for j in range(len(x[i])):
            y = y + x[i][j]*weight[j]
        
        y=signum(y)
        
        
        output.append(y)
        weight = weight + c*(desired[i]-y)*x[i]
        
        print("List Output",weight,output)
    
    p=p+1
    
    print("\n{} epoch {}\n".format(p,output))
    list.append(a)

print(list)

