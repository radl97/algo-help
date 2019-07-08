# Egyszerű compile & run & diff

Itt egy egyszerű kód, ami összevet két fájlt:

## Windows

### run & diff


```batch
for /L %%i in (1,1,99) do (
  if not exist test/ (
    mkdir test
  )
  if exist be%%i.txt (
    %%1 < be%%i.txt > test/ki%%i.txt
    FC ki%%i.txt test/ki%%i.txt
  )
)
```

Használat:

`./rundiff compiled.exe`

Ez a be1-be99.txt fájlokra (ha léteznek) lefuttatja a programokat, és a kimenetet leellenőrizni. (ha nem egyezik meg bájtról bájtra, akkor tekinti rossznak a kimenetet.)

## Linux

### compile

`g++ -o compiled main.cpp`

Ez a `main.cpp` nevű fájlt fordítja le.

Compile flageket lehet beletenni.

### Run & diff

```
for i in *.test; do
  $1 < $i > $i.result
  diff $i.output $i.result
done
```

Ez a `*.test` alakú fájlokon végigmegy, ezek a tesztbemenetek. Ha `a.test` a bemenet, `a.test.output` a helyes kimeneti fájl. A kimenetet ezzel veti össze (ha nem egyezik meg bájtról bájtra, akkor tekinti rossznak a kimenetet.)
