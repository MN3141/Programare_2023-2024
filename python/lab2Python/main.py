print("Hello World")
class Animal:
    def Mananca(self):
        print("ANIMAL")
class Pisica(Animal):
    def Mananca(self):
        print("PISICA")
listAnimal=[Animal,Animal,Pisica,Pisica,Animal]
for i in listAnimal:
    i.Mananca(self=i)
