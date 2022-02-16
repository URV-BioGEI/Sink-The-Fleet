#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
int i=0,e, record;
char llegir, joc[100];
char cosa;
FILE *records;
e=0;
inici:
system("cls");
printf("Escull una opcio i prem intro \n\n");
printf("1.- Llegir fitxer de puntuacions\n");
printf("2.- Escriure sobre el fitxer de puntuacions\n");
printf("3.- Sortir\n");
scanf("%i",&i);
if ((i<1) || (i>3))
{
    system("cls");
    printf("Opció incorrecta, prem qualsevol tecla i torna-ho a intentar");
    getch();
    goto inici;
}
switch (i)
{
case 1:
    system("cls");
    records= fopen("records.txt","r");
    if (records==NULL)
    {
        fclose(records);
        records =fopen("records.txt","w");
    }
   printf("|||||||||||||||||\n");
printf("|HALL DE LA FAMA|\n");
printf("|||||||||||||||||\n");
    while (!feof(records))
    {
        llegir = fgetc(records);
        printf("%c",llegir);
        if (llegir==32)
        {
            e=e+1;
        }
        if ((llegir==32) && (e%2==0))
        {
            putchar('\n');
        }
    }
    printf("\n\n Prem qualsevol tecla per tornar al menu...");
    getch();
    fclose(records);
    goto inici;
    break;
case 2:
    i=0;
            cosa=0;
            records= fopen("records.txt", "a");
            printf("Introdueix el nom :\n");
            scanf("%c",&cosa);
            scanf("%c",&cosa);
            while(cosa!='\n')
            {
                joc[i]=cosa;
                i++;
                scanf("%c",&cosa);
            }
            joc[i]='\0';
            i=0;
            while(joc[i]!='\0')
            {
                fprintf(records,"%c", joc[i]);
                i++;
            }
            printf("Introdueix el record: ");
            scanf("%d",&record);
            fprintf(records,"    Record: %d \n", record);
            fclose(records);
        break;


case 3:
    break;
    return 0;
}
    return 0;
}
