## CPP for Noobs Like me

---
### What are Classes/Structs? 

They are a bunch of members glued together, fields (the data inside of the class/structs), and 
member functions (The methods that operates on the classes.)

---
### When are Fields of the class instance destoyed?

It's automatic, when the variable goes out of scope, the things inside of the class are destoryed. 

---
### What is dynamic Memory?

When an object is initialized with `new`, it's then called dynamically allocated, they are in the 
heap until `delete` is called on them.

When using the `new` keyword, **ownership of the pointers must be very very clear.**. Especially who is ultimtely responsible for destorying it.

If `new` used, then use `delete` on it, ONCE ONLY.
if `new[]` used, or array contains pointers to elements invoked using `new`, then `delete[]` is expected. 

**Set pointers to NULL after deletion.**

---
#### What is difference between new MyClass[?] and new MyClass? 

* The first creates an array of pointers, the second one creates one pointer to an instance of MyClass. 
* When using, make sure only one entity has ownership to the pointers inside, or else double free can be caused.

---
### Arrays FAQs

* How to make an array of a type `T` of size `size`?
  * T[size];
* How to make an array of pointers of type `T`?
  * T*[size];
* How to make a pointer to an array of type `T`?
  * T arr = T[size];
  * T* ptrarr = arr[0];
* How to make a pointer to an array of pointers of type `T`?
  * T** arrptrs = T*[size]; 

---
### `#include` or Declerations Forwarding?

Say we are writing class `A`, and somehow we need `B` for it. 
  
* Use **Forward Declations** when: 
  * in the *definition* of a, we only have a pointer that points to A.
  * In the definition of `A`, we never called any function of `B`.
* Use **#include** when:
  * We need to know the size of `A`.
  * You need to call function of class B.

---
### Separate Compilations (Template)

When using template, your implementations in the CPP is different compare to classes without a template. You, **Cannot seperate** the definitions and declarations of memebers of a class using template. (`#include` in `.h` is needed if the defintion is in `.cpp`)

See [here](https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl) for more explanations

---
### Default Constructor and Assignment Operator Fiassco

```
MyClass t1, t2;  // invokes default constructors.
Myclass t3 = t2  // invokes copy constructor on t2 and move reference to t3.
t2 = t1          // invokes default constructor and then invokes `operator`.
```

Move assignment operator is deleted if the default ctor is not there, the same for copy constructor. 

---
### Smart Pointers: `std::unique_ptr`, `std::shared_ptr`

A smart pointer is a pointer that can help programmer to prevent the ownership problem, hence preventing the double free error. 

Motivations:

  * This is needed becaues copying a lot of data is expensive, that is why a reference to the heap memory will be very useful if that thing is a handle, or it's using a lot of resources.

Scenarios:
  
  * Assuming multiple instances of class is sharing a pointer with the same memory address.

  * This is a problem because if we don't delete it, then it's a memory leak, if we delete it, then we will have double free, because the pointer (the handle) are shared in different instances of classes.

Solutions:
  * The `unique_ptr`; 
    
    * The unique pointer is a pointer that can be references by one instance of the class at a time, and moved around (transfer of ownership). Once it's moved, the original instance of the `unique_ptr` is given a `NULL`. 
    
    * `std::unique_ptr<T> newptr = std::move(oldptr)`. After this line of code, the `oldptr` will have NULL when `.get()` is evoked on it. 
    
    *  `auto z = std::unique_ptr<int>(new int{0})`, and when: `z = unique_ptr<int>(new int{10})`, the oritinal value it refers to will be deleted, because of the rule for `=` opertor. The same thing happens when the `std::move` is passed into it. 

    * The ordering of the `unique_ptr`:
      
      * Take notice that, the `unique_ptr` is sorted by the value of the pointer in the memoery, **it's not the value of whatever the pointer is referring to.** So whenvever the ordering of the element it holds is needed, please customizer your comparator for STL datastructures.
      * The same goes for `shared_ptr`.

  * The `shared_ptr`; 
    
    * This `shared_ptr` allows for multiple instances of the clas to hold a reference to a value. And they will be refering to the same value. When all of the goes out of scope, the value will be automatically deleted. 
    
    * Take not that, if there are **Circular Refernces**, then it will cause a **Memory Leak.**
    
    * Just use it as a java references, and avoid circular references. 

  * The `weak_pointer`; 

    * A `weak_pointer` can only ponts to a pointer that is managed by a `shared_pointer`. 

    * Only the weak_pointer for a node that is at the junction of the circular reference. 

    * THis is used to the eliminate cyclic refernces when using `shared_ptr` and it will help with the memory management when: 
      * You know ther is a cyclic reference and you know which node is going to be the junction node. 

    

