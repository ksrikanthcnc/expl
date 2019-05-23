# expl Compiler

Reference: https://silcnitc.github.io/

This is a compiler for a toy operating system ([xos](https://xosnitc.github.io/))\
Running `chmod +x z && ./z` in terminal probably works(after having the pre-requisites)\
For debugging output, uncomment `#define BUG` in [expr.h](expr.h) file
### Outline of stages
Please follow the [Roadmap](documentation/Roadmap.pdf)
1. CodeGeneration for Arithmetic Expressions
2. Introduction to static storage allocation
3. Adding Flow Control Statements
4. User Defined Variables and arrays
5. Adding Functions
6. User defined types and Dynamic Memory Allocation
7. Adding Objects – Data encapsulation
8. Inheritance and Sub-type Polymorphism

#### Pre-Requisites
You need flex(lex) and bison(yacc). For futher details click [here](documentation/Installation.pdf)


## Features implemented and learnt
Parsing, Tokenizing\
Working of stack\
Abstract Syntax tree\
Usage of machine registers\
Error handling\
Symbol Table\
Type-Checking\
Dynamic memory allocation (Heap) \
Functions' implementation\
Object Oriented Programming
- Inner workings of Polymorphism
- Runtime binding of functions
- Classes

### To-Do
- Increment(++) and Decrement(--) operator
- a[1] (*a should work)
- *&&p
  - \*
  - &
  - &
  - p		
- Implement arr[i] using down pointer
- Assignment for arr should be possible i local scope
- extra lines label.l

**Important**
- read (self.name)
  - check parameters to func in classes
- checkid
  - checkmembr
  - checktype
- reg optimization set getreg freereg

