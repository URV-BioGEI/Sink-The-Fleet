#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <conio.h>
#include "tipus.h"
#include "funcions.h"
int main(){
    char matriujocaa[10][10];
    char matriujocab[10][10];
    char matriujocba[10][10];
    char matriujocbb[10][10];
    char escapadatime;
    records_tipus taula[10];
    srand(time(NULL));
    int  i,j,monflag, opciotauler, noacabata, noacabatb, puntuacioa, puntuaciob,llancamentsa, llancamentsb, tira, encertsa, encertsb, filaa, filab, columnaa, columnab, jugadaa, fi, jugadab, opcio, caselles, load, menu, orientacioa, orientaciob, verticala, verticalb, horitzontala, horitzontalb;
    fi=0;
    load=0;
    opciotauler=-1;
    dadesjoc dades;
    noacabata=0;
    noacabatb=0;
    encertsa=0;
    encertsb=0;
    jugadaa=1;
    jugadab=1;
    orientacioa=-1;
    orientaciob=-1;
    horitzontala=-1;
    horitzontalb=-1;
    verticala=-1;
    verticalb=-1;
    puntuacioa=0;
    puntuaciob=0;
    llancamentsa=0;
    llancamentsb=0;
    monflag=1;
    INICIALITZA_TAULA(taula);
    RECUPERA_RECORDS(taula);
    while (1!=0)
    {
    menu:
    menu=MOSTRAR_MENU(&load);
    switch (menu)
        {
        case 1:
            opcio=TIPUS_JOC(&caselles);
            switch(opcio)
            {
                case 1:
                    INICIA_TAULELL(matriujocaa, matriujocab, caselles);
                    INICIA_TAULELL(matriujocbb, matriujocba, caselles);
                    load=1;
                break;
                case 2:
                    INICIA_TAULELL(matriujocaa, matriujocab, caselles);
                    INICIA_TAULELL(matriujocbb, matriujocba, caselles);
                    load=1;
                break;
                case 3:
                    while ((opciotauler!=78)&&(opciotauler!=83))
                    {
                        printf("\nJugador 1: Vols colocar els teus propis vaixells? (S/N)");
                        opciotauler=getche();
                        if (opciotauler>=97)
                        {
                            opciotauler=opciotauler-32;
                        }
                    }
                    if (opciotauler==78)
                    {
                        INICIA_TAULELL(matriujocaa, matriujocab, caselles);
                        INICIA_TAULELL(matriujocbb, matriujocba, caselles);
                    }
                    else
                    {
                        INICIA_EL_MEU_TAULELL(matriujocaa, matriujocab, caselles);
                        INICIA_TAULELL(matriujocbb, matriujocba, caselles);
                    }
                    load=1;
                break;
            }
        break;
        case 2:
            if (0==RECUPERA_JOC(&dades))
        {
            printf("No s'ha carregat cap joc...");
        }
        else
        {
            printf("El teu  joc s'ha carregat correctament");
        monflag=0;
        opcio=dades.opcio;
        caselles=dades.caselles;
        i=0;
        j=0;
        while (i<10)
        {
            while (j<10)
            {
                matriujocaa[i][j]=dades.matriujocaa[i][j];
                j++;
            }
            j=0;
            i++;
        }
        i=0;
        while (i<10)
        {
            while (j<10)
            {
                matriujocab[i][j]=dades.matriujocab[i][j];
                j++;
            }
            j=0;
            i++;
        }
        i=0;
        while (i<10)
        {
            while (j<10)
            {
                matriujocbb[i][j]=dades.matriujocbb[i][j];
                j++;
            }
            j=0;
            i++;
        }
        i=0;
        while (i<10)
        {
            while (j<10)
            {
                matriujocba[i][j]=dades.matriujocba[i][j];
                j++;
            }
            j=0;
            i++;
        }
        noacabata=dades.noacabata;
        noacabatb=dades.noacabatb;
        puntuacioa=dades.puntuacioa;
        puntuaciob=dades.puntuaciob;
        llancamentsa=dades.llancamentsa;
        llancamentsb=dades.llancamentsb;
        tira=dades.tira;
        encertsa=dades.encertsa;
        encertsb=dades.encertsb;
        filaa=dades.filaa;
        filab=dades.filab;
        columnaa=dades.columnaa;
        columnab=dades.columnab;
        jugadaa=dades.jugadaa;
        jugadab=dades.jugadab;
        orientacioa=dades.orientacioa;
        orientaciob=dades.orientaciob;
        verticala=dades.verticala;
        verticalb=dades.verticalb;
        horitzontala=dades.horitzontala;
        horitzontalb=dades.horitzontalb;
        monflag=dades.monflag;
            load=true;
            menu=0;
        printf("\nLa partida es de %i jugadors", opcio-1);
        printf("\nI el tauler es de %i caselles", caselles);
        }
            break;
        case 3:
            switch(opcio)
            {
            case 1:
                if (monflag==1)
                {
                    tira=MONEDA();
                    monflag=0;
                }
            while (fi==0)
                    {
                        while (((jugadaa==2 || jugadaa==3) || tira==1)&&(fi==0))
                        {
                            jugadaa=DISPARA(matriujocbb, matriujocab, &filaa, &columnaa, &jugadaa, caselles, &orientacioa, &verticala, &horitzontala, noacabata);
                            if (jugadaa==3)
                            {
                                POSA_AIGUA(matriujocab, filaa, columnaa, caselles);
                            }
                            puntuacioa=puntuacioa+jugadaa-1;
                            llancamentsa++;
                            system("cls");
                            VISUALITZA(matriujocaa, matriujocab, caselles, 1);
                            VISUALITZA(matriujocbb, matriujocba, caselles, 2);
                            printf("\nTorn del jugador 1:");
                            printf("\n\nResultat: Jugador 1 casella %i%c:", filaa, columnaa+65);
                            switch(jugadaa)
                            {
                            case 1:
                                printf(" Aigua.");
                                tira=2;
                            break;
                            case 2:
                                printf(" Tocat.");
                                encertsa++;
                                if (encertsa!=20)
                                {
                                    printf(" Torna a tirar.");
                                }
                                noacabata=1;
                                tira=1;
                            break;
                            case 3:
                                printf(" Tocat i enfonsat. ");
                                encertsa++;
                                if (encertsa!=20)
                                {
                                    printf("Torna a tirar.");
                                }
                                noacabata=0;
                                tira=1;
                            break;
                            }
                            escapadatime=getch();
                            if (escapadatime=='\t')
                            {
                                system("cls");
                                goto menu;
                            }
                            if (encertsa==20)
                            {
                                fi=1;
                            }
                        }
                        while (((jugadab==2)||(jugadab==3)||(tira==2))&&(fi==0))
                        {
                            jugadab=DISPARA(matriujocaa, matriujocba, &filab, &columnab, &jugadab, caselles, &orientaciob, &verticalb, &horitzontalb, noacabatb);
                            if (jugadab==3)
                            {
                                  POSA_AIGUA(matriujocba, filab, columnab, caselles);
                            }
                            llancamentsb++;
                            system("cls");
                            VISUALITZA(matriujocaa, matriujocab, caselles, 1);
                            VISUALITZA(matriujocbb, matriujocba, caselles, 2);
                            puntuaciob=puntuaciob+jugadab-1;
                            printf("\nTorn del jugador 2:");
                            printf("\n\nResultat: Jugador 2 casella %i%c:", filab, columnab+65);
                            switch(jugadab)
                            {
                            case 1:
                                printf(" Aigua.");
                                tira=1;
                            break;
                            case 2:
                                printf(" Tocat. ");
                                encertsb++;
                                if (encertsb!=20)
                                {
                                    printf("Torna a tirar.");
                                }
                                noacabatb=1;
                                tira=2;
                            break;
                            case 3:
                                printf(" Tocat i enfonsat. ");
                                encertsb++;
                                if (encertsb!=20)
                                {
                                    printf("Torna a tirar.");
                                }
                                noacabatb=0;
                                tira=2;
                            break;
                            }
                        escapadatime=getch();
                            if (escapadatime=='\t')
                            {
                                system("cls");
                                goto menu;
                            }
                        if (encertsb==20)
                            {
                                fi=1;
                            }
                        }
                    }
                    puntuacioa=CALCULAPUNTUACIO(caselles, puntuacioa, llancamentsa);
                    puntuaciob=CALCULAPUNTUACIO(caselles, puntuaciob, llancamentsb);
                    if (encertsa==20)
                    {
                        printf("\nHa guanyat el jugador 1, amb %i punts, felicitats!\n", puntuacioa);
                    }
                    if (encertsb==20)
                    {
                        printf("\nHa guanyat el jugador 2, amb %i punts, felicitats!\n", puntuaciob);
                    }
                    getch();
                    if (0==AFEGIR_RECORD(puntuacioa, taula, 1)) {printf("El teu record no s'ha afegit...\n");}
                    if (0==AFEGIR_RECORD(puntuaciob, taula, 2)) {printf("El teu record no s'ha afegit...\n");}
                    EMMAGATZEMA_RECORDS(taula);
                    IMPRIMIR_RECORDS(taula);
                    fi=0;
                    noacabata=0;
                    noacabatb=0;
                    encertsa=0;
                    encertsb=0;
                    jugadaa=1;
                    jugadab=1;
                    orientacioa=-1;
                    orientaciob=-1;
                    horitzontala=-1;
                    horitzontalb=-1;
                    verticala=-1;
                    verticalb=-1;
                    puntuacioa=0;
                    puntuaciob=0;
                    llancamentsa=0;
                    llancamentsb=0;
                    load=0;
                    monflag=1;
                    getch();
                break;
                case 2:
                    while (fi==0)
                    {
                        filaa=-1;
                        columnaa=-1;
                        VISUALITZASIMPLE(matriujocab, caselles);
                        printf("\nTorn del jugador 1:");
                        while ((filaa<0)||(filaa>=caselles))
                        {
                            printf("\nIntrodueix la fila per a disparar: ");
                            filaa=getche();
                            filaa=filaa-48;
                            if ((filaa<0)||(filaa>=caselles))
                            {
                                printf("\nFila incorrecta! tu creus que en aqueta fila pots llancar una bomba?");
                            }
                        }
                        while ((columnaa<0)||(columnaa>=caselles))
                        {
                            printf("\nIntrodueix la columna per a disparar: ");
                            columnaa=getche();
                            if (columnaa>=97)
                            {
                                columnaa=columnaa-32;
                            }
                            columnaa=columnaa-65;
                            if ((columnaa<0)||(columnaa>=caselles))
                            {
                                printf("\nColumna incorrecta tros d'ase!");
                            }
                        }
                        llancamentsa++;
                        if (matriujocab[filaa][columnaa]=='?')
                        {
                            if (matriujocbb[filaa][columnaa]=='.')
                            {
                                matriujocbb[filaa][columnaa]='-';
                                matriujocab[filaa][columnaa]='.';
                                jugadaa=1;
                            }
                            if (matriujocbb[filaa][columnaa]=='X')
                            {
                                matriujocbb[filaa][columnaa]='@';
                                matriujocab[filaa][columnaa]='@';
                                encertsa++;
                                jugadaa=COMPROVA(matriujocbb, filaa, columnaa,caselles, &tira);
                                if (jugadaa==3)
                                {
                                    POSA_AIGUA(matriujocab, filaa, columnaa, caselles);
                                }
                            }
                        }
                        else
                        {
                            jugadaa=0;
                        }
                        puntuacioa=puntuacioa+jugadaa-1;
                        printf("\nResultat: Jugador 1 casella %i%c:", filaa, columnaa+65);
                        switch(jugadaa)
                        {
                        case 0:
                            printf(" Casella repetida. ");
                        break;
                        case 1:
                            printf(" Aigua. ");
                        break;
                        case 2:
                            printf(" Tocat. ");
                        break;
                        case 3:
                            printf(" Tocat i enfonsat. ");
                        break;
                        }
                        if (encertsa==20)
                        {
                            fi=1;
                        }
                        else
                        {
                                printf("Torna a tirar.");
                        }
                        escapadatime=getch();
                            if (escapadatime=='\t')
                            {
                                system("cls");
                                goto menu;
                            }
                        system("cls");
                    }
                    puntuacioa=CALCULAPUNTUACIO(caselles, puntuacioa, llancamentsa);
                    if (encertsa==20)
                    {
                        printf("\nHa guanyat el jugador 1, amb %i punts, felicitats!\n", puntuacioa);
                    }
                    getch();
                    if (0==AFEGIR_RECORD(puntuacioa, taula, 1)) {printf("El teu record no s'ha afegit...\n");}
                    EMMAGATZEMA_RECORDS(taula);
                    IMPRIMIR_RECORDS(taula);
                    fi=0;
                    noacabata=0;
                    encertsa=0;
                    jugadaa=1;
                    orientacioa=-1;
                    horitzontala=-1;
                    verticala=-1;
                    puntuacioa=0;
                    llancamentsa=0;
                    load=0;
                    getch();
                break;
                case 3:
                    if (monflag==1)
                {
                    tira=MONEDA();
                    monflag=0;
                }
                while (fi==0)
                {
                    while (((jugadaa==2 || jugadaa==3) || tira==1)&&(fi==0))
                    {
                        system("cls");
                        filaa=-1;
                        columnaa=-1;
                        VISUALITZA(matriujocaa, matriujocab, caselles, 1);
                        while ((filaa<0)||(filaa>=caselles))
                        {
                            printf("\nTorn del jugador 1");
                            printf("\nIntrodueix la fila per a disparar: ");
                            filaa=getche();
                            filaa=filaa-48;
                            if ((filaa<0)||(filaa>=caselles))
                            {
                                printf("\nHas introduit una fila incorrecta empanat!!");
                            }
                        }
                        while ((columnaa<0)||(columnaa>=caselles))
                        {
                            printf("\nIntrodueix la columna per a disparar: ");
                            columnaa=getche();
                            if (columnaa>=97)
                            {
                                columnaa=columnaa-32;
                            }
                            columnaa=columnaa-65;
                            if ((columnaa<0)||(columnaa>=caselles))
                            {
                                printf("\nPero que no veus que el que acabes de posar esta malament? torna-hi...");
                            }
                        }
                        llancamentsa++;
                        if (matriujocab[filaa][columnaa]=='?')
                        {
                            if (matriujocbb[filaa][columnaa]=='.')
                            {
                                matriujocbb[filaa][columnaa]='-';
                                matriujocab[filaa][columnaa]='.';
                                jugadaa=1;
                                tira=2;
                            }
                            if (matriujocbb[filaa][columnaa]=='X')
                            {
                                matriujocbb[filaa][columnaa]='@';
                                matriujocab[filaa][columnaa]='@';
                                encertsa++;
                                jugadaa=COMPROVA(matriujocbb, filaa, columnaa,caselles, &tira);
                                if (jugadaa==3)
                                {
                                    POSA_AIGUA(matriujocab, filaa, columnaa, caselles);
                                }
                                tira=1;
                            }
                        }
                        else
                        {
                            jugadaa=0;
                        }
                        puntuacioa=puntuacioa+jugadaa-1;
                        printf("\n\nResultat: Jugador 1 casella %i%c:", filaa, columnaa+65);
                        switch(jugadaa)
                        {
                        case 0:
                            printf(" Casella repetida. ");
                            tira=2;
                        break;
                        case 1:
                            printf(" Aigua. ");
                        break;
                        case 2:
                            printf(" Tocat. ");
                        break;
                        case 3:
                            printf(" Tocat i enfonsat. ");
                        break;
                        }
                        if (encertsa==20)
                        {
                            fi=1;
                        }
                        else
                        {
                            if ((jugadaa==2)||(jugadaa==3))
                            {
                                printf("Torna a tirar.");
                            }
                        }
                        escapadatime=getch();
                            if (escapadatime=='\t')
                            {
                                system("cls");
                                goto menu;
                            }
                    }
                    while (((jugadab==2)||(jugadab==3)||(tira==2))&&(fi==0))
                    {
                        jugadab=DISPARA(matriujocaa, matriujocba, &filab, &columnab, &jugadab, caselles, &orientaciob, &verticalb, &horitzontalb, noacabatb);
                        if (jugadab==3)
                        {
                            POSA_AIGUA(matriujocba, filab, columnab, caselles);
                        }
                        llancamentsb++;
                        system("cls");
                        VISUALITZA(matriujocaa, matriujocab, caselles, 1);
                        printf("\nTorn del jugador 2:");
                        puntuaciob=puntuaciob+jugadab-1;
                        printf("\n\nResultat: Jugador 2 casella %i%c:", filab, columnab+65);
                        switch(jugadab)
                        {
                        case 1:
                            printf(" Aigua.");
                            tira=1;
                        break;
                        case 2:
                            printf(" Tocat. ");
                            encertsb++;
                            if (encertsb!=20)
                            {
                                printf(" Torna a tirar");
                            }
                            noacabatb=1;
                            tira=2;
                        break;
                        case 3:
                            printf(" Tocat i enfonsat. ");
                            encertsb++;
                            if (encertsb!=20)
                            {
                                printf(" Torna a tirar.");
                            }
                            noacabatb=0;
                            tira=2;
                        break;
                        }
                        escapadatime=getch();
                            if (escapadatime=='\t')
                            {
                                system("cls");
                                goto menu;
                            }
                        if (encertsb==20)
                            {
                                fi=1;
                            }
                        }
                    }
                    puntuacioa=CALCULAPUNTUACIO(caselles, puntuacioa, llancamentsa);
                    puntuaciob=CALCULAPUNTUACIO(caselles, puntuaciob, llancamentsb);
                    if (encertsa==20)
                    {
                        printf("\nHa guanyat el jugador 1, amb %i punts, felicitats!\n", puntuacioa);
                    }
                    if (encertsb==20)
                    {
                        printf("\nHa guanyat el jugador 2, amb %i punts, felicitats!\n", puntuaciob);
                    }
                    getch();
                    if (0==AFEGIR_RECORD(puntuacioa, taula, 1)) {printf("El teu record no s'ha afegit...\n");}
                    if (0==AFEGIR_RECORD(puntuaciob, taula, 2)) {printf("El teu record no s'ha afegit...\n");}
                    EMMAGATZEMA_RECORDS(taula);
                    IMPRIMIR_RECORDS(taula);
                     fi=0;
                    noacabata=0;
                    noacabatb=0;
                    encertsa=0;
                    encertsb=0;
                    jugadaa=1;
                    jugadab=1;
                    orientacioa=-1;
                    orientaciob=-1;
                    horitzontala=-1;
                    horitzontalb=-1;
                    verticala=-1;
                    verticalb=-1;
                    puntuacioa=0;
                    puntuaciob=0;
                    llancamentsa=0;
                    llancamentsb=0;
                    load=0;
                    monflag=1;
                    opciotauler=-1;
                    getch();
                break;
            }
        break;
    case 4:
        dades.opcio=opcio;
        dades.caselles=caselles;
        i=0;
        j=0;
        while (i<10)
        {
            while (j<10)
            {
                dades.matriujocaa[i][j]=matriujocaa[i][j];
                j++;
            }
            j=0;
            i++;
        }
        i=0;
        while (i<10)
        {
            while (j<10)
            {
                dades.matriujocab[i][j]=matriujocab[i][j];
                j++;
            }
            j=0;
            i++;
        }
        i=0;
        while (i<10)
        {
            while (j<10)
            {
                dades.matriujocbb[i][j]=matriujocbb[i][j];
                j++;
            }
            j=0;
            i++;
        }
        i=0;
        while (i<10)
        {
            while (j<10)
            {
                dades.matriujocba[i][j]=matriujocba[i][j];
                j++;
            }
            j=0;
            i++;
        }
        dades.noacabata=noacabata;
        dades.noacabatb=noacabatb;
        dades.puntuacioa=puntuacioa;
        dades.puntuaciob=puntuaciob;
        dades.llancamentsa=llancamentsa;
        dades.llancamentsb=llancamentsb;
        dades.tira=tira;
        dades.encertsa=encertsa;
        dades.encertsb=encertsb;
        dades.filaa=filaa;
        dades.filab=filab;
        dades.columnaa=columnaa;
        dades.columnab=columnab;
        dades.jugadaa=jugadaa;
        dades.jugadab=jugadab;
        dades.orientacioa=orientacioa;
        dades.orientaciob=orientaciob;
        dades.verticala=verticala;
        dades.verticalb=verticalb;
        dades.horitzontala=horitzontala;
        dades.horitzontalb=horitzontalb;
        dades.monflag=monflag;
        if (0==EMMAGATZEMA_JOC(dades))
        {
            printf("No s'ha guardat cap joc...");
        }
        else
        {
            printf("El teu  joc s'ha guardat correctament");
        }
            break;
    case 5:
        IMPRIMIR_RECORDS(taula);
        break;
    case 6:
        return 0;
        break;
    case 7:
        system("cls");
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
        printf("\nAquest joc es el joc hundir la flota en versio 3.0");
        printf("\nPer a comencar escolleix la opcio carregar una partida o crear un nou joc");
        printf("\nAixo carregara una partida guardada (si n'hi ha una) o be creara un nou joc. ");
        printf("\n");
        printf("\nHi ha tres tipus de joc: cap jugador, on nomes juga la maquina. Un jugador,");
        printf("\non nomes jugues tu per a enfonsar tots els vaixells del contrincant i la maquina");
        printf("es completament passiva. I per ultim esta la opcio de jugar tu contra la maquina");
        printf("que jo he dissenyat per a que perdis un cop rere un altre muahahahaha. Aquesta  ");
        printf("es l'opcio mes divertida.");
        printf("A l' opcio de dos jugadors es troba de forma exclusiva\nl'opcio de dissenyar el");
        printf(" teu propi tauler de joc.");
        printf("\n");
        printf("\nEl joc esta dissenyat per obtenir informacio de lusuari capturant les pulsacions");
        printf("del teclat, de manera que un cop hagis apretat una tecla no hi haura opcio per a");
        printf("tornar enrere; procura no equivocarte ;). Les opcions possibles a triar solen ");
        printf("\nestar escrites al mateix enunciat de la pregunta indicades entre parentesi,");
        printf("\no be davant de l'opcio amb un numero, per exemple: 3.-carregar partida, ");
        printf("\nes a dir, que per a seleccionar aquella opcio has de premer 3. De vegades pero,");
        printf("\nsi la pantalla es queda quieta; el joc espera que premis qualsevol tecla per a");
        printf("\npoder continuar.");
        printf("\n");
        printf("\nEl joc esta fet a prova de poca-soltes que intenten rebentar el codi o be a ");
        printf("\nprova d'australopitecs que no son capacos d'introduir l'informacio que el joc   ");
        printf("els hi esta demanant. Pots equivocarte sense problema,pero procura no tocar molt");
        printf("els pebrots o potser sere jo qui et faci una visita per a aixafarte la guitarra ");
        printf("poca-solta.");
        printf("\n");
        printf("\nEs pot sortir d'una partida per a tornar al menu en el moment que s'anuncia el");
        printf("\nresultat de la jugada (jugador 1: aigua) prement la tecla tabulador; en la ");
        printf("\nmajoria de teclats es troba sobre el bloc de majuscules (bloq mayus). Aixo pot ");
        printf("\nfer-se per a guardar la partida, per exemple.");
        printf("\n\nAu va!! prou d'instruccions i a enfonsar vaixells, que jugar a aquesta andromina");
        printf("es bufar i fer ampolles!!");
        printf("\n");
        printf("\nmolta sort!!! :D\n");
        break;
    }
        printf("\nPrem qualsevol tecla per a tornar al menu principal \n");
        getch();
        system("cls");
}
return 0;
}



