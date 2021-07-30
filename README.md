### Environments 
* Linux, with clang, or gcc

### Build
* A mixed of Makefiles and CMAKE, my cmake skills are not yet good enough. 

### Why did I had So Much Pain when I dealt with CPP Last Time? 

* I am not using Linux. 
* I am not aware of the complexity of building and compiling a CPP programs, which is a big part of programming in CPP. 
* I am not good at testing and debugging. 
* I am not good with Macros and Pre-processors too. 

### What Noobs from Python or Java should be aware when learning CPP? 

* CPP it's totally different and it's really dumb comparing to java and python. 
* CPP place big importance on building the system via header files, include directory, macros, and linkage. 
* CPP won't tell you what exactly is wrong, beause if it blows up, it's down to the binary level, and OS/(cpp runtime) won't be able to provide satisfying answers on the errors. 

**Phase of Translation**: [here](https://en.cppreference.com/w/cpp/language/translation_phases)

---
# Topics

* Pre-Processor
* Debugger

### **Pre-Processor**: 

Takes in the program as input, and output programs, it's like meta-programming. E.g, Java reflection and function decorators. 

When? 

Before programs are compiled

How? 

It literally replaces text in the source code. 

Fun fact: `-E` will print out all the text included by using `#include `. 

Fun fact: `-D` will pass macros variable to the pre-processor. 

For more Fun Fact about Compiler flags that are related to the Pre-Processor, visit [here](https://gcc.gnu.org/onlinedocs/gcc/Preprocessor-Options.html)

Why? 

Flags, `NDEBUG` can enable or disable the assert features. To use  assert feature, do `#include <assert.h>`. 

### **Debugger**

What are some of the debugger out there? 

`lldb`, for stuff compiled by LLVM 
`gdb`, for stuff compled by GCC
Make sure assert is enabled for these debugger, and there are no compiler optimization involved when compiling it, and `-g` is used when compiling the debugging version of the program. 


For example: 

```bash
lldb a.out
```

type `up`

