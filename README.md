# Cyclic_list
Cyclic list implementation in C++ for OOP classes @ WUT.

###To **build** project:  

1. create build directory 
  * `mkdir build`
2. go into build directory  
  * `cd build`
3. run `cmake` command  
  * `cmake ..`

This will create a **Makefile**. Simply run it using `make` to create executables.  
You can run main program by running *./src_run* and tests by *./runBasicTest* in respective directories.

###Original task [Polish]
Napisać klasę realizującą listę cykliczną jednokierunkową przechowującą liczby całkowite.

Klasa powinna umożliwiać:
  * Dodawanie elementu (na początek, po określonym elemencie, w miejsce wyznaczone przez indeks...)
  * Usuwanie elementu (o określonym indeksie, określnej wartości, zakresie wartości...)
  * Pobranie elementu z listy (o określonej wartości, określonym indeksie...)
  * Dodawanie dwóch list do siebie
  * Odjęcie od siebie dwóch list
  * Kopiowanie obiektu
  * Usuwanie wartości powtarzających się
  * Sprawdzenie wielkości listy
  * Porównanie list

Klasa powinna dostarczać również zestaw operatorów realizujących dodawanie, usuwanie, kopiowanie obiektu, dostęp do elementu oraz porównanie obiektu z innym. Do klasy powinien zostać wykonany zestaw testów udowadniający jej działanie.
