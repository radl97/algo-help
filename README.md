# Algo help

Ez egy pár tanács algoritmusos versenyeken való jó szerepléshez. Nem csak algoritmusokról akar szólni, hanem valamivel többet akar nyújtani: debuggolás, tesztelés, kisebb trükkök. Azaz a (versenyeken való) fejlesztés folyamatának minél nagyobb darabját le akarom ezzel fedni.

A fókuszban a következő áll:
 - *1-6 óra* hosszú verseny
 - algoritmust kell kódolni
 - (ahol általában) standard bemenetről standard kimenetre kell írni dolgokat
 - lehet (és ezért általában érdemes) C++-ban fejleszteni

## Tanácsok

Itt bizonyos kategóriák szerint megpróbálom csoportosítani a feladatot.

- [Egy adott feladatot akarok megoldani](problem/index.md)
- [Automatizálni szeretném a tesztelést](auto/index.md)
- [Egy bugot keresek a programomban](debugging/index.md)

## Bevezető

Ha rendezetten tudnék gondolkodni:

Megpróbálom jó tanácsok kategorizált sorozatára és a miértjére bontani ezt a témát.

A következő kategóriákat választottam eddig szét:

Más kategóriákba is lehet sorolni: a hibákat elkerülni, a hibákat fordításidőben elkapni, futásidőben elkapni debuggolhatóan, stb.

- algoritmusok/adatszerkezetek, továbbiakban algoritmusok
  - Mit jelent egy algoritmus, mikor jöhet szóba
  - Táblázatos összehasonlítások a hasonló algoritmikusokról
    - futásidők, memóriaigény, stb.
    - mennyire nehéz (jól) implementálni
  - Szempontok:
    - Milyen versenyre kell
    - Egyéb?
- Kódolás
  - Általános, nem C++-hoz kötődő tanácsok (pl. ne használj goto-t, változók elnevezése)
  - Szempontok:
    - Mennyi hibalehetőséget vesz el (a fordítási hibává konvertálás ideszámít)
    - Mennyi hibalehetőség debuggolását segíti
    - Mennyire nehéz kódolni (időben, etc.)
- C++
  - A C++11 vagy C++14 eszköztára, jó tanácsok (pl. tömb helyett vector vagy array)
  - Hogyan kell gyors és jól debuggolható kódot írni, minél gyorsabban
  - Pár tanács konkrétan az stdin-stdout-on történő adatcserére...
  - Szempontok: 
    - nehézség (mennyire kell érteni a C++-t, mennyire a C-t az adott manőverhez)
- Tesztelés
  - Általában shell parancsok, amikkel minimálisan automatizálhatóvá tehető pár hasznos dolog
  - Hogyan futtassuk a programot tesztesetre
  - Hogyan generáljunk (valid) tesztesetet
  - Referenciaimplementáció készítése
  - Hogyan keressünk (minél kisebb) olyan tesztesetet, amire nem működik a kódunk
- Debuggolás
  - Fordítási opciók
  - Memóriával kapcsolatos hibák elkapása
  - Crash kezelése
  - Debugger kezelése
