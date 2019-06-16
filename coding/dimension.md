# Dimenzióanalízis

A dimenzióanalízis egy olyan eszköz, amit érdemes fejben használni, amikor nagyon sok tömb van. (Létezik rá megoldás. Lásd: [Kód](https://github.com/madasigon/mytl3/pull/32) és talán később a cpp szekcióban.)

### A lényege

Van valami fizika abban, amit akarunk írni.

`v=s/t/t` ez gyanúsan nézhet ki azoknak, akik nem rühellik nagyon a fizikát...

Programozásban sokkal szigorúbbak lehetünk: pl. mondhatnánk ilyesmiket, hogy egy `i` futóváltozónak ne vegyük kétszeresét.

Ezeket érdemes hiba esetén végigbogarászni a kódban, vagy valami egyszerű implementációt használni.

# Tömbök

A tömböket úgy lehet tekinteni, hogy egyik dimenzióból a másikba váltunk: méterből másodpercbe, satöbbi.

`T[i]` az "indextípusból" "értéktípusba" viszi az értéket.

`T[i][j]`-ben pedig a "sortípus" és az "oszloptípus"-ból együtt "értéktípusú" értéket ad vissza.

A gondolatmenete picit szokatlan, de számtalanszor használtam.

Speciális esete az, hogy "minden kétdimenziós első eleme az X-koordináta legyen".
