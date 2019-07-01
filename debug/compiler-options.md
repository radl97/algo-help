# Compiler flagek

### `-Wall -Wextra` Kötelezők

Bekapcsolnak nagyon hasznos figyelmeztéteseket, mielőtt lábon lövöd magad egy `if (a = 0)` sorral.

Vannak fals pozitívek, de érdemes rájuk figyelni.

### `-D_GLIBCXX_DEBUG` Túlindexelés védelem

STL könyvtárban található tárolókhoz. Ezzel fordítva a kódot szól, ha alul-, vagy túlindexelsz, vagy rosszul használod a tárolót. (pl. invalid iterátort használsz)

Ezért érdemes lehet használni a megszokott `int[1000]` helyett mondjuk `std::array<int, 1000>`-t vagy hasonlót.

### `-fsanitize=undefined -fsanitize-undefined-trap-on-error` Túlcsordulás és egyéb "védelem"

`-ftrapv` **nem** működik: [Bug report](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=35412).

A legtöbb `undefined behaviour`-t megpróbálja elkapni. Többek között az előjeles számoknál a túlcsordulást.

Debuggerrel el lehet kapni, és meg lehet nézni, hogy mikor történt a hiba.

Egyébként érdemes minél kevesebbszer előjel nélküli műveletet használni, csak ott, ahol tuti, hogy nincs overflow (vagy ott, ahol kell). Megengedhet a fordító olyan optimalizációkat, ami csak akkor működik, ha nincs overflow: `int f(int x) { return x+1>x; }` pl. általában `int f(int x) { return 1; }`-re optimalizálható.

Úgy tűnik, hogy `short`-nál nem működik :/ Intnél teszteltem pár dolgot.

**Megjegyzés:** Azért idézőjeles védelem, mert csak elszáll, ha probléma történik, de legalább debuggolható.

[Dokumentáció](https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html#index-fsanitize_003dundefined)

### Profilozás

Kód lassú részeit meg tudod határozni vele. [Link](https://www.thegeekstuff.com/2012/08/gprof-tutorial)
(TODO Nem használtam még)
