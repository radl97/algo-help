# 2-SAT visszavezetése erősen összefüggő komponensekre

2-SAT-nak nevezzük azt a problémát, amikor adott N változó, és egy speciális
Boolean-képlet, és az a kérdés, hogy adható-e úgy érték a változóknak, hogy a képlet értéke igaz lesz.

Konkrétan, ha van `a,b,c,d` (igaz/hamis) változó, akkor `(a+b)(c+d)(a+!b)(b+!a)`
egy 2-SAT formula (jelölés: `+` a `vagy`, szorzás az `és`, `!` a tagadás).
Ez a formula igaz, ha például `a,b,c,d` mind igaz.

Az `(a+!a)` formula viszont mindenképp hamis.

### Visszavezetés

Legyenek adottak bool változók közti implikációk (következtetések).
Nevezzük implikációs gráfnak azt, amiben minden csúcs egy változó (vagy a negáltja),
és egy irányított `a->b` élet akkor húzunk be, ha `a`-ból következik `b`.

A 2-SAT megadható implikációk formájában: `a vagy b` = `!a -> b`, ami ekvivalens azzal, hogy `!b -> a`.
Az implikációs gráfban mindkét élt létre kell hozni.

**implikáció/következtetés/`a`-ból következik `b`:** Akkor és csak akkor hamis, ha `a` igaz és `b` hamis.

Az implikációs gráfban, ha valamit igaznak "tippelünk", akkor az onnan elérhető összes csúcsnak igaznak kell lennie.

Ha létezik `a -> !a` út, akkor `a` hamis. Ha létezik `!a -> a` út, akkor igaz. Ha mindkettő létezik, akkor nincs megoldás.

Erősen összefüggő komponensekre redukálható a 2-SAT probléma: Ha egy SCC-ben van egy csúcs és tagadása, akkor nincs megoldás.
Egyébként belátható, hogy van (a komponensekből előállítható a megoldása a 2-SAT problémának.)

### Példa

```
3 5 (3 változó, 5 "állítás")
1 -2 (a vagy nem b)
2 -1 (b vagy nem a)
1 2
2 3 (b vagy c)
-2 3
```

**Megjegyzés: -1 az 1. változó tagadása. A változókat a,b,c-vel jelölöm az átláthatóság kedvéért.

Gráf: (minden két sor egy állításból jön)

```
-1 -2
2 1

-2 -1
1 2

-1 2
-2 1

-2 3
-3 2

2 3
-3 -2
```

Komponensek: (minden sorban egy komponens összes tagja van, kettőspont előtt az azonosítója)

```
A: -1 -2
B: 1 2
C: -3
D: 3
```

A komponensen belül mindegyik literál (=változó vagy annak negáltja) értéke azonos.

Komponensek közti élek:
```
A->B
A->D
C->B
B->D
C->A
```

`-3`-ból (eleme C) elérhető +3 (eleme D) a `C->A->D` úton. Ezért C minden eleme hamis: -3 hamis,
tehát 3 (azaz `c` változó) igaz.

`-1`-ből (eleme A) elérhető +1 (eleme B) a `A->B` úton, ezért A minden eleme hamis: -1 és -2, tehát `a` és `b` igaz.

Ellenőrizzük le, hogy ha mind a három változó igaz értéket vesz fel, valóban mindegyik állítás teljesül.
