###A Programozási Nyelvek (C++) beadandó
* A feladat leírása a main.cpp elején megtalálható
* A beadandó kiértékeléséhez a gcc/g++ fordítóprogram 9.3.0-as verzióját használjuk Ubuntu 20.04 alatt a következő paraméterekkel:
>g++ -fsanitize=address,leak,undefined -O3 -Wall -Wextra -Werror main.cpp
 
* Nem elfogadható, ha azzal nem fordul le vagy nem működik helyesen. A program kódját ellenőrizzük a clang-tidy eszközzel:
>clang-tidy-11 main.cpp --
>
* Nem elfogadható, ha ez bármilyen hibát vagy figyelmeztetést talál. A programot a valgrind segítségével futtatjuk és akkor fogadjuk el, amennyiben nem talál sem hibát sem fel nem szabadított memóriát:
>valgrind --leak-check=full --show-leak-kinds=all ./a.out
