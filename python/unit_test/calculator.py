class BasicCalculator:

    ## Simple class constructor
    def __init__(self):
        self.result=0
    
    ##Addition method
    ##Note:Substraction is just addition with a negative number
    def add(self,a):

        self.result=self.result+a
    
    ##Division method
    def divide(self,a):
        if a==0:
            ##Cannot divide a number by 0,**but it tends to a limit**
            return -9999999999999999
        else:
            self.result=self.result/a

    ##Get the result (state of the system)
    def get_result(self):
        
        return self.result
    
