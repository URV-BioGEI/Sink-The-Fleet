#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int mida, num, acum, k, p, puntuacio;
    k=1;
    p=0;
    num=0;
    printf("Aquest programa calcula la puntuació\n\n");
    printf("Introdueix la mida del tauler: ");
    scanf("%i", &mida);
    system("cls");
    printf("Ara introdueix els valors del resultat dels llençaments\n");
    printf("Aquests resultats poden ser 3, 2, 1 o 0\n");
    printf("Sent tocat i enfonsat, tocat, aigua o posicio repetida respectivament\n");
    printf("Introdueix cada valor amb intro afegint -1 per acabar: ");
    while (num!=-1)
    {
        p=p+1;
        k=num-1;
        acum=acum+k;
        scanf("%i",&num);
    }
    p=p-1;
    if (p==0)
	{
	printf("No has introduit cap data, torna-ho a provar");
	main();
	}
    puntuacio=(100*(mida/p)*acum);
    printf("La puntuacio es %i",puntuacio);
    getch();
    return 0;
}
