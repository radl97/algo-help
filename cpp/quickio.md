# Gyors I/O kezelés

Az stdin és stdout kezelése lehet lassú, ha >100'000 számot kezelünk. (leginkább bemenetnél probléma, ezért a kimenetet nem részletezem)

Lassútól gyorsig a módszerek:

*TODO mindegyikhez a számok, szövegek és sorok beolvasását megírni...*

### std::cin

`#include <iostream>`

`using namespace std;`

`cin << a;`

Kényelmesen kezelhető, típusos, stb., egyszerűen szólva király. Viszont a leglassabb az összes közül.


De egy kis trükkel gyorsabb, mint a C-s beolvasás.

### scanf

`#include <cstdio>`

`scanf("%d%s", &szam, szoveg);`

Kényelmetlen picit, de sok nyelvben megmaradt ugyanez a sablon. Kb mindig elég.

Ha ezt használod, akkor nem lehet gondod, mert ezzel a sebességgel szoktak kb. számolni. Viszont, ha máshol nem tudsz gyorsítani, érdemes lehet meggondolni a következőket.

### cin #2

A program indításakor be kell írni pár parancsot, érdemes megjegyezni:

```
cin.tie(NULL);
cin.sync_with_stdio(false);
```

Ez azt jelenti, hogy felteszi, hogy `scanf`-fel és hasonló függvényeket nem használsz. (Se bármilyen függvénykönyvtár, amit használsz)

**VIGYÁZAT:** Ezen már sültek fel. C-s és C++-os beolvasást ilyenkor ne keverj, mert nem fog működni!

### saját beolvasás

`char ch=getchar();`

```
#define gc getchar_unlocked
template<typename T>
T quickIO() {
    char c = gc();
    while (c <= 32) c = gc();
    T r = 0;
    do {
        r *= 10;
        r += c-'0';
        c = gc();
    } while (c > 32);
    return r;
}

using readInt=quickIO<int>();
#undef gc
```

Ez nem kezel +- jelet az elején, se hasonlót.

Kb. intelligenciában ezeket tudja értelmezni: `0`, `123`, `01245`.

Template-ek nélkül természetesen még rövidebb.

A `getchar_unlocked()` nem ISO C, azt hiszem, csak GCC-ben van. Valamivel gyorsabb, mint a sima `getchar()`, de mindkettő ugyanazt csinálja.

TODO nem teszteltem! (a kódban lehet elírás)

### saját beolvasás - negatív számok

```
#define READ c = getchar_unlocked()
long long read() {
    char READ;
    while (c <= ' ') READ;
    bool sign = false;
    if (c == '-') { sign = true; READ; }
    long long r = 0;
    do {
        r *= 10;
        r += c-'0';
        READ;
    } while (c > ' ');
    if (sign) return -r;
    return r;
}
#undef READ
```

Ez még mindig nem kezeli a + jelet.

Kb. ilyeneket tud értelmezni: `0`, `123`, `01245`, `-123`, `-01`.

Regexszel: `-?[0-9]*`-ot helyesen kezeli, amíg belefér a long long-ba.
