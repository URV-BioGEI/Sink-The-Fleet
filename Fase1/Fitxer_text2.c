#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    int taula[12]= {8,2,1,1,2,2,3,3,4,4,5,5},  i, temp, opcio;
    FILE *f;
    printf("Tenim un fitxer amb unes dimensions, un numero de jugadors i una taula:\n");
     printf(" 1.- Llegir el fitxer \n 2.- Escriure en el fitxer\n 3.- Sortir del programa\n");
     printf(" Escull una opcio i apreta intro: \t");
    scanf("%i",&opcio);
    switch(opcio)
    {
        case 1:
            f = fopen("Fitxer.txt","r");
            i=0;
            while(i<12)
            {
                fscanf(f,"%d",&temp);
                printf("%i\n",temp);
                i++;
            }
            fclose(f);
        break;
        case 2:
            printf("Introdueix cada valor confirmant amb intro  fins a 12 valors");
            f = fopen("Fitxer.txt","w");
            i=0;
            while(i<12)
            {
                scanf("%i",&temp);
                taula[i]=temp;
                fprintf(f,"%d ",taula[i]);
                i++;
            }
            printf("Finalitzat");
            getch();
            fclose(f);
        break;
        case 3:
        break;

    default: {printf( "opcio no valida, sortint del joc...");}
    }
return(0);}
