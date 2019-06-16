# Feltételellenőrzések

## Elmélet

Invariánsoknak hívják azokat a feltételeket, amik a kód megadott pontján biztosan teljesülnek.

Például:

```
bool p = false;
int i = 0;
while (i <= N && p) {
    ...
    i++;
}
```

Ez után `i == N+1` vagy `!p` mindenképp teljesül.

Vannak speciális invariánsok: előfeltétel, utófeltétel és osztályinvariáns.

### Előfeltétel és utófeltétel

Az előfeltétel az, aminek egy függvény hívása előtt teljesülnie kell ahhoz, hogy a függvényt értelme legyen használni, ekkor a futás után teljesül az utófeltétel.

Pontosabban: előfeltétel esetén a függvény lefutása után garantálja az utófeltétel teljesülését, beleértve az esetleges visszatérési értéket.

### Osztályinvariáns

Ha OOP-ben gondolkozol, hasznos fogalom.

Gyakorlatilag azt jelenti, hogy a belső állapota egy osztálynak mikor konzisztens.

Konstruktor meghívása után, illetve két metódushívás között kell teljesülnie.

Például egy rendezett tömbben minden behelyezés után rendezettnek kell lennie a tömbnek.

## Gyakorlatban

A lényege ezeknek, hogy tesztelés közben belefussunk a hibákba.

`#include <cassert>`

`assert(feltétel);`

A feltétel, ha nem teljesül, akkor hibát dob a program. A hibát bármilyen debugger elkapja, ahol a stack trace megvizsgálható, azaz, hogy hol fordult elő a hiba.

Minél gyakrabban ellenőrizzük az invariánsokat, annál kevesebb kódot kell debuggolni.

**Megjegyzés:** A feltétel ellenőrzése lassíthatja (nagyságrendekben) a programot. Éles kódban 

### Éles kódban ellenőrzés eltűntetése

```
#ifdef MYDEBUG
#define E(...) __VA_ARGS__
#else
#define E(...)
#endif
```

Az `E(...)` gyakorlatilag egy saját komment, ami csak saját módban működik. TODO lásd `cpp/debug.md`.

Ezt fogjuk arra használni, hogy a lassú ellenőrzések fent ne fussanak. Nyilvánvalóan akkor is lehet lassú, ha túl nagy a teszteset, de az általában nem probléma, kis példákat keresünk.

### Elő-, és utófeltétel

`int sort(int T[1000])` utófeltétele, hogy rendezi az elemeket.

### Osztályinvariáns

```
class SortedArray {
    int T[1000];
    void check() {
        for (int i = 1; i < 1000; i++) {
            assert(T[i-1] <= T[i]);
        }
    }
    E(int check_helper[1000];)
public:
    SortedArray() {
        // etc.
        E(check());
    }

    void insertElement() {
        // ha itt romlik el, akkor az nem az insertElement hibája,
        // valami fura memóriatúlírás lehet
        E(check());

        // blabla
        // blabla

        E(check()); // ha itt romlik el, 99%, hogy a fenti kód rossz
    }
;
```

