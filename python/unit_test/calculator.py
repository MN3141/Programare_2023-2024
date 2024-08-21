class BasicCalculator:

    def __init__(self):
        self.result=0
    
    def add(self,a):
        
        self.result=self.result+a
    
    def divide(self,a):
        if a==0:
            return -9999999999999999
        else:
            self.result=self.result/a

    def get_result(self):
        
        return self.result
    
