# Min-stack

Nem ismerem hivatalos nevét az adatstruktúrának.

Egy listán végigiterálva fenntartjuk az eddigi domináns pontjait. Domináns pontnak azon elemek részsorozatát nevezzük, amelyeknél nincsen kisebb(egyenlő) elem a listában a kiválasztott elem után (a jelenlegi elemig bezárólag). A formálisabb megfogalmazása: j. elem domináns, ha nem létezik`j<k<=i`, amire `T[k]<T[j]`.

Ennek a részsorozatnak nagyon szép tulajdonságai vannak: monoton növekvő, alsó becslést adnak a pontok egy részére.

```
for (int i = 0; i < N; i++) {
    while (!S.empty() && values[S.back()] >= values[i])
        S.pop_back();
    for (int j: S) {
        // T[j] egy domináns pont...
    }
    S.push_back(i);
}
```

VAGY

```
for (int i = 0; i < N; i++) {
    while (!S.empty() && !values[S.back()] < values[i])
        S.pop_back();
    S.push_back(i);
    for (int j: S) {
        // (j,T[j]) egy domináns "pont"...
    }
}
```

Ha jól tudom, nem ad nagyságrendi gyorsítást, de annyival lehet gyorsabb egy-egy megoldás, hogy versenyen el lehessen várni.
