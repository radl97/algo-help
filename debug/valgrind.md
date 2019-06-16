# Valgrind

A Valgrind egy nagyon hasznos eszköz, ami memóriakezelési hibák ellen véd. Alapvetően versenyen nem tűnik hasznosnak, bár volt, amikor ez mentett meg.

Csak Linuxon működik, amennyire tudom.

### Használata

`valgrind ./run`, azaz egyszerűen lefuttatjuk a run-t.

Nagyon sok opciója van.

Túlindexelés, alulindexelés ellen általánosabban tud védekezni, mint általában más módszerek. (pl. sima tömbbel is működik, ha heap-en van)
