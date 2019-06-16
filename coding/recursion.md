## Rekurzió

A rekurzió egy szép dolog, szeretem, de sajnos lassú.

Plusz van egy olyan limitációja néhány rendszeren, ami miatt csak kevés szintig megy csak el. Ezen már vesztettem sokszor pontokat/helyezéseket.

### Kevés helyi változó

Próbáljunk minél kevesebb helyi változóra szorítkozni.

### Triviálisan átalakítható rekurzív kódok

Néha a fordító is át tudja alakítani a rekurziót, de ez inkább speciális esetnek tekinthető, nem érdemes ezzel számolni.

### Rekurzió nélküli implementáció csak szükség esetén

```
bool check(int N); // backtrack részfeltétele [0;N) intervallumon

int T[MAX_DB];
bool backtrack(int N=0) {
    if (check(N)) {
        if (N == MAX_DB)
            return true;
        for (T[N]=0; T[N]<MAX_VAL; T[N]++) {
            if (backtrack(N+1))
                return true;
        }
    }
    return false;
}
```

Ezt próbáld átírni rekurzió nélkülire...

Én valami ilyesmit csináltam:

```
int T[MAX_DB], N;

// viszonylag átláthatatlan kóddal:
void brother();
void child();
void dad();

bool backtrack() {
    N = 0;
    while (N >= 0) {
        if (check(N)) {
            if (N == MAX_DB)
                return true;
            child();
        } else {
            brother();
            while (N >= 0 && T[i] == MAX_VAL) { // csak T[i] < N értelmes
                dad();
                brother();
            }
        }
    }
    return false;
}
```

(ezek se tesztelt/átgondolt kódok, csupán szemléltetésnek vannak itt)

Ugyanakkor a rekurziós megoldás lassabb. Érdemes tudni rekurzió nélkül implementálni a dolgokat, de nem elvesztegetni az időt, ha nem kell.
