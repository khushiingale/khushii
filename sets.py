setA=set()
setB=set()
n=int(input("enter the limit of setA:"))
m=int(input("enter the limit of setB:"))
def add():
    for i in range(n):
        ele=input("enter element for setA:")
        setA.add(ele)
        print(setA);
def add1():
    for i in range(m):
        ele=input("enter element for setB:")
        setB.add(ele)
        print(setB);
def remove():
        ele=input("enter element to remove:")
        setA.remove(ele)
        print(setA,"\n");
def contain():
    contains = 7 in setA
    print("7 present is setA:");
    print(contains);

def union():
    print("union of sets:");
    print(setA|setB,"\n");

def intersection():
    print("Intersections:");
    print(setA.intersection(setB),"\n");

def difference():
    print("difference of sets:");
    print(setA-setB,"\n");

def length():
    print("Lenth of setA:");
    print(len(setA));
    print("Lenth of setB:");
    print(len(setB));

def subset():
    print(setB.issubset(setA));
add()
add1()
remove()
contain()
union()
intersection()
difference()
length()
subset()

