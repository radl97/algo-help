# T[0]=0

## Példa

Van egy 100-elemű T tömböd, egy intervallumba eső rész összege érdekel.

Ha sok kérdés van, érdemes kumulatív tömbbel csinálni, ahol `K[i]`-ben az első `i` elem összegét tároljuk.

A lényege, hogy 3.-tól az 5.-ig elemig az összeg `K[5]-K[3-1]`.

Viszont ez nem működik a nulladik elemre: `K[-1]` nem értelmezett.

### Megoldás

A nulladik eleme a kumulált tömbnek legyen 0. A "tényleges" elemeket egytől indexeljük: `K[1]=T[1]`, `K[2]=T[1]+T[2]`, stb.

Amikor az első és a harmadik elemet (nulladik elem ugye nincs), akkor `K[3]-K[1-1]` értelmezett lesz.

## Általánosítva

Ez máskor is jól jöhet. A Dinamikus Programozási problémáknál sok eset kerülhet elő, amikor az első sort vagy első oszlopot külön kell kezelni. Ezeknél általában megoldható, hogy egy nulladik oszlop vagy nulladik sor bevezetésével egy esetre tudjuk visszavezetni a problémát.
