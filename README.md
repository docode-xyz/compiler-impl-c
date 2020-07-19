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

## Modularity principles for C programs
1. Each phase or module of the compiler belongs in its own `.c` file, which will have a corresponding `.h` file.
2. Each module shall have a prefix unique to that module.  
   All global names(`structure` & `union` fields are *not* global names) exported by the module shall start with the prefix. Then the human reader of a file will not have to look outside that file to determine where a name comes from.
3. All functions shall have *prototypes*, and the C compiler shall be told to warn about uses of functions without prototypes. The `-Wmissing-prototypes` flag responsible for it.
4. The `util.h` file will be included in each file.
5. The `string` type means a heap-allocated string that will not be modified after its initial creation. Like as `strdup`.
6. *Never* call `malloc` directly, but call only our own function `checked_malloc` which *guarantees* never return `NULL`.
7. *Never* call `free`. In order to be able to concetrate more on compiling techniques than on memory deallocation techniques, we can simply neglect to do anything *freeing*.