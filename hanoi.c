# include <stdio.h>

void hanoi(int n, char Origen, char Dest, char Aux) // A C B
{
    if (n == 0)
        return;
    hanoi(n-1, Origen, Aux, Dest);
    printf("Moviendo %d de %c a %c\n", n, Origen, Dest);
    hanoi(n-1, Aux, Dest, Origen);
}

int main() {
    int n = 3;
    hanoi(n, 'A', 'C', 'B');
    return 0;
}