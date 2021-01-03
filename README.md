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