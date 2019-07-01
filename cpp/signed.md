# Előjeles vs. előjel nélküli műveletek

Van pár művelet, aminél fontos meggondolni, hogy a számok negatívak lehetnek-e, történhet-e túlcsordulás.

Például a `<<` és `>>` műveletek a negatív számokkal furcsán viselkednek (a bal oldali negatív számoknál is).

### Túlcsordulás

Két szám összege, különbsége, szorzata túlcsordulhat, ha nagyobb a maximum értéknél, vagy kisebb a minimumnál.

Bővebben: [Integer overflow](https://www.pixelbeat.org/programming/gcc/integer_overflow.html)

### Negatívval osztás

Itt a trükk abban van, hogy az osztás 0 felé kerekít, azaz `(-1)/2==0`, ami nem túl intuitív.

Azt garantálja, hogy `(a/b)*b + a%b == a`, ami azt jelenti, hogy a maradék is furán fog viselkedni (nem-pozitív lesz).

Ezért érdemes valamit kitalálni, hogy amikor maradékot vagy egészrészt akarunk számolni, akkor ugyanúgy viselkedjen negatív, illetve pozitív számként.

`(a-b) MOD M` helyett `(a - (b%M) + M)%M` használható (nem tesztelt).

### Truncation

Amikor a kimenetbe nem fér el az érték (`short a = 60000+60000`) nem feltétlen túlcsordulásról beszélünk. A zárójeles példában két `int`-et összegzünk, ami `int` típusú, abba még elfér a megoldás. De az összeget `short`-tá kell alakítani. Itt fog elveszni a tényleges összeg egy része. Ennek is fura a viselkedése, érdemes kerülni.

### Bit-shift

Negatív számot ne shiftelj jobbra (azaz kisebb helyiértékre).

Részletesebben:

A standard szerint `implementation-defined`, de gyakorlatilag GCC is és CLang is hasonlóan viselkedik: az első 1-es bitet másolja, így (bináris számokat jelölve) `1010>>3==1101>>2==1110>>1==1111`

Ezt akartam leírni: [Wikipédia arithmetic shift](https://en.wikipedia.org/wiki/Arithmetic_shift)

Ha nagyon akarod használni, akkor a következő történik: `(int)a>>1` lefelé (-végtelen felé) kerekítve a/2: "divides a signed number by a power of two, rounding towards negative infinity".
