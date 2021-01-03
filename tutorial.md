### Writing CPP Classes

The CPP classes are a block of memories that stores some fields (data) and some members (Other types, or method)
of the class. 

What is the different between class and struct? 

```
class Class1 {
    int integer; 
}

struct Struct1 {
    int integer; 
}
```

The struct will not hide the field by default, but the class will. Meaning that: 

```
Class1 instance1{};
Class1.integer; // --> Compiler errors 
Struct1 intance2{}; 
Structu1.integerl // --> this is ok. 
```

When writing class/structs, keep in mind the following: 

1. The constructors: 
    1. Default constructors. 
    2. Copy constructures. 
    3. The assignement operators (Relavent to the copy constructor)
2. The destructor. 
    1. The default destructor. 
3. The Assignment operator. (The equal sign)

When writing classes/structs, the following will be hard: 

1. No memeory leakage please. 




