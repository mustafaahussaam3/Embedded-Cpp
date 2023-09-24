/*

    What is Singleton ? 

    * The Singleton pattern ensures a class has only one instance, and provides a global point of access to it.
    * A Singleton is an elegant way of maintaining global state, but we should always question whether we need global state    

    Use Cases: 

    * Singleton pattern offers several advantages over global variables because it does the following:
    * Enforces that only one instance of the class can be instantiated.
    * Allows control over the allocation and destruction of the object.
    * Provides thread-safe access to the object's global state.
    * Prevents the global namespace from being polluting
    
    Pattern VS Anti-Pattern:

    * In 2009, the authors of the original design patterns said the only pattern they would consider removing from the original list is Singleton.
      This is because it is essentially a way to store global data and tends to be an indicator of poor design.

    Alternatives: 

    * dependency injection
    * Monostate pattern
    * session context




*/