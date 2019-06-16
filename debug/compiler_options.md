# Compiler flagek

### `-Wall -Wextra` Kötelezők

Bekapcsolnak nagyon hasznos figyelmeztéteseket, mielőtt lábon lövöd magad egy `if (a = 0)` sorral.

Vannak fals pozitívek, de érdemes rájuk figyelni.

### `-D_GLIBCXX_DEBUG` Túlindexelés védelem

STL könyvtárban található tárolókhoz. Ezzel fordítva a kódot szól, ha alul-, vagy túlindexelsz, vagy rosszul használod a tárolót. (pl. invalid iterátort használsz)

Ezért érdemes lehet használni a megszokott `int[1000]` helyett mondjuk `std::array<int, 1000>`-t vagy hasonlót.

### Profilozás

Kód lassú részeit meg tudod határozni vele. [Link](https://www.thegeekstuff.com/2012/08/gprof-tutorial)
(Nem használtam még)
