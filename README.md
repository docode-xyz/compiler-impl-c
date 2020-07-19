# compiler-impl-c
Modern Compiler Implementation in C.


## Programming style
* Conventions for representing tree Data Structure in C
    1. Trees are described by a grammar.
    2. A tree is described by one or more `typedefs`, corresponding to a symbol in the grammar.
    3. Each `typedef` defines a *pointer* to a corresponding `struct`. The `struct` name, which ends in an underscope, is **never** used anywhere except in the declaration of the `typedef` and the definition of the `struct` itself.
    4. Each `struct` contains a `kind` field, which is an `enum` showing different veriants, one for each grammar rule; and a `u` field - union.
    5. Every class will have a *constuctor function* that initializes all the fields. The `malloc` function shall **never** be called directly, except in these constructor functions.
    6. Each module(header file) shall have a prefix unique to that module.
    7. Typedefs names(after the prefix) shall start with lowercas latters;  
       Constructor functions(after the prefix) with uppercase;  
       Enumeration atoms(after the prefix) with lowercase;  
       Union variants(which have no prefix) with lowercase;  
