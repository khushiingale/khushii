class SeparateHash:
    def __init__(self,n):
        self.n = n
        self.v = [[] for i in range(n)]
    def getHashIndex(self, x):
        return x % self.n
        
    def add(self, x):
        i = self.getHashIndex(x)
        if x not in self.v[i]:
            self.v[i].append(x)
            
    def del_(self, x):
        i = self.getHashIndex(x)
        if x in self.v[i]:
            self.v[i].remove(x)
            print(x, "deleted!")
        else:
            print("No Element Found!")
            
    def displayHash(self):
        for i in range(self.n):
            print(i, end=" -> ")
            if(len(self.v[i])==0):
                print("NULL",end=" ")
            for j in self.v[i]:
                print(j, end=" ")
            
            print()
            
ch = 'y'
obj = SeparateHash(10)
while(ch=='y' or ch=='Y'):
    n = int(input("\n1.Insert Element\n2.Find Key\n3.Display Element.\n4.Delete Element\nEnter your choice: "))

    if(n==1):
        num = int(input("How many elements you want to insert?: "))
        for i in range(num):
            key = int(input("Enter element to insert : "))
            obj.add(key)

    if(n==2):
        key = int(input("Enter element to find : "))
        print(" Value of index is ", obj.getHashIndex(key))
        
    if(n==3):
        obj.displayHash()
        
    if(n==4):
        key = int(input("Enter element to delete : "))
        obj.del_(key)
        
    ch = input("Do you want to continue??(y/n): ")
