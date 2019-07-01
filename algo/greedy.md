# Mohó algoritmus

Ez a [Mester](mester.inf.elte.hu) oldalon megtekinthető definíció/leírás:

Optimalizálási probléma megoldására szolgáló algoritmus gyakran olyan lépések sorozatából áll, ahol minden lépésben adott halmazból választhatunk. 

A mohó algoritmus mindig az adott lépésben optimálisnak látszó választást teszi. 
A lokális optimumot választja abban a reményben, hogy ez globális optimumhoz fog majd vezetni.

Mohó stratégia nem mindig ad optimális megoldást, ezért fontos, hogy be tudjuk bizonyítani (avagy ellenpéldát tudjunk adni), hogy a tervezett algoritmus tényleg optimális megoldást állít elő.

A mohó stratégia elemi:

1. Fogalmazzuk meg az optimalizációs feladatot úgy, hogy választások sorozatával építjük fel a megoldást.
2. Mutassuk meg, hogy mindig van olyan megoldása az eredeti feladatnak, 
	  amely a mohó választással kezdődik. Ezt mohó választási tulajdonságnak nevezzük.
3. Bizonyítsuk be, hogy a mohó választással olyan redukált problémát kapunk, amelynek optimális megoldásához hozzávéve a mohó választást, az eredeti probléma megoldását kapjuk. Ezt optimális részprobléma tulajdonságnak nevezzük.

Általában sokféle mohó választás kínálkozik, de nem mindegyik mohó választás eredményez optimális megoldást, ezért fontos, hogy bebizonyítsuk, hogy az adott mohó választás tényleg optimumot eredményez. 

A mohó választás gyakran úgy valósítható meg, hogy a bemeneti adatokat megfelelő szempont szerint rendezzük, és ebben a sorrendben vizsgáljuk a választhatóságot.  Előfordulhat, hogy a mohó választás megvalósítására prioritási sort kell használni.
