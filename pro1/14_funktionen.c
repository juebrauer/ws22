#include <stdio.h>

// Ein 1. Beispiel einer rekursiven Funktion:
// die Funktion foo() ruft sich selber wieder auf!
// Achtung! Noch kein Rekursionsabbruch
void foo(int x, int stop)
{
    // Rekursionsabbruch
    if (x>stop)
        return;
    else
    {
        printf("%d ", x);
        foo(x+1, stop);
    }
}


int main()
{
    foo(1, 15);
}