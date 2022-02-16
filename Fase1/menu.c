int main()
{
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <conio.h>

    bool load;
    int menu;
    menu=0;
    load=false;
    printf("||     ||          _____                            __________       ||||   \n");
    printf("||     ||         /     \\        ||               ||          ||    ||||   \n");
    printf("||     ||        /       \\       ||               ||          ||     ||||   \n");
    printf("||     ||       /         \\      ||               ||          ||    ||||   \n");
    printf("||     ||      /           \\     ||               ||          ||     ||||   \n");
    printf("||-----||     |             |    ||               ||----------||    ||||  \n");
    printf("||     ||      \\           /     ||               ||          ||     ||||   \n");
    printf("||     ||       \\         /      ||               ||          ||           \n");
    printf("||     ||        \\       /       ||               ||          ||    ****   \n");
    printf("||     ||         \\_____/         _____________   ||          ||     ****   \n");
    printf(" \n");
    printf("                      _____   ______  __     ____   ___      ____     __ \n");
    printf("      || ||     ||  //       ||    | || \\  ||    | ||   \\   ||       /    \n");
    printf("      || ||     || ||        ||    | ||  | ||    | ||   ||  ||      |    \n");
    printf(" ||   || ||     || || _____  ||____| ||  | ||    | ||___/   ||===    \\   \n");
    printf("  \\   // ||     ||  \\     || ||    | || /  ||    | ||   \\   ||        | \n");
    printf("   \\__//  \\____//    \\___//  ||    | ||/   ||____| ||    \\  ||____  __/    \n");
menu:
    printf("\nMenu:\n");
    printf("1.- Crear un nou joc\n");
    printf("2.- Carregar un joc emmagatzemat\n");
    if (load==true)
    {
        printf("3.- Jugar partida\n");
        printf("4.- Emmagatzemar el joc\n");
    }
    printf("5.- Veure podium\n");
    printf("6.- Sortir del joc\n\n");
    printf("Selecciona la opcio i prem intro\n\n");
    scanf("%i", &menu);
    if ((menu>6)|| (menu<1) || (menu==3 && load==0) || (menu==4 && load==0))
    {
        printf("\nOpcio incorrecta, prem qualsevol tecla i torna-ho a intentar\n");
        getch();
        system("cls");
        goto menu;
    }
    switch (menu)
    {
    case 1:
        //aqui aniran totes les funcions per a crear la matriu del joc i tot el que faci falta per a començar a jugar
        load=true;
        system("cls");
        goto menu;
    case 2:
        //aqui carregarem una partida
        //Consistirà en llegir variables des d'una font externa per a recuperar l'estat d'un joc en un moment determinat
        load=true;
        system("cls");
        printf("\nPrem qualsevol tecla per a tornar al menu principal \n");
        getch();
        system("cls");
        goto menu;
    case 3:
        //aqui iniciariem el vertader cos del programa, on estarien la majoria de funcions
        system("cls");
        printf("\nPrem qualsevol tecla per a tornar al menu principal \n");
        getch();
        system("cls");
        goto menu;
    case 4:
        //aqui guardariem les variables d'estat del joc en una font externa que podriem carregar en l'apartat 2
        system("cls");
        printf("\nPrem qualsevol tecla per a tornar al menu principal \n");
        getch();
        system("cls");
        goto menu;
    case 5:
        //aqui llegiriem el fitxer de podium
        //En la fase dos integrarem aquesta part del menú amb l'exercici del fitxer de text de la fase 1
        //Com un programa independent
        system("cls");
        printf("\nPrem qualsevol tecla per a tornar al menu principal \n");
        getch();
        system("cls");
        goto menu;
    case 6:
        //sortir
        return 0;
    }
    return 0;
}
printf("Jugador 1\n")
printf
Matriu de defensa          Matriu d'atac
0000000000                 0000000000  
0000000000                 0000000000
0000000000                 0000000000
0000000000                 0000000000 
0000000000                 0000000000
0000000000                 0000000000
0000000000
0000000000
0000000000
0000000000
0000000000
0000000000
0000000000
0000000000   
