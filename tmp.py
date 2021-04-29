def dontadd(z):    
    def notadd(c):    
        return z + c    
      
    return notadd    
      
tmp = dontadd(15)    
      
print(tmp(10))   