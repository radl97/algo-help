# Tárolt rekurzió

Egy kis rövidítést ad ez az egyszerű trükk:

```
int _D[1000];
#define RET return _D[x]

int D(int i) {
    if (_D[i] != -1) RET;
    if (_D[i] < 2) RET = 1;
    RET = D(i-1) + D(i-2);
}

// és valahol: for(int i = 0; i < 1000; i++) _D[i] = -1;
```
