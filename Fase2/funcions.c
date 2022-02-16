#include "tipus.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <conio.h>
void VISUALITZASIMPLE(char matriujocaa[][10],int caselles){
    int i, k;
    k=0;
    i=0;
    printf("Matriu atac\n");
    putchar(254);
    while (i<caselles)
    {
        putchar(i+65);
        i++;
    }
    i=0;
    printf("\n");
    while (i<caselles)
    {
        printf("%i",i);
        while(k<caselles)
        {
            printf("%c",matriujocaa[i][k]);
            k++;
        }
        k=0;
        printf("\n");
        i++;
    }
}
void PAUSA(){
    printf("\nPrem qualsevol tecla per continuar...\n");
    getch();
}
void INICIA_EL_MEU_TAULELL(char matriu[][10], char matriuk[][10], int caselles){
    int comprova,control, vaixell, comptador, f, c, direccio, superior, dreta, inferior, esquerra, correcte, i, j;
    i=0;
    j=0;
    control=0;
    correcte=0;
    vaixell=3;
    direccio=-1;
    c=-1;
    f=-1;
    comptador=0;
    comprova=0;
    while (i<10){ 
        while (j<10)
        {
            matriu[i][j]='.';
            j++;
        }
        j=0;
        i++;
    }
    i=0;
    while (i<10){ 
        while (j<10)
        {
            matriuk[i][j]='?';
            j++;
        }
        j=0;
        i++;
    }
    i=0;
    while (vaixell!=-1)
    {
        i=0;
        j=0;
        while (correcte==0)
        {
            if ((correcte==0)&&(control!=0))
            {
                printf("\nEl vaixell a les coordenades que has introduit no s'ha pogut colocar...");
                PAUSA();
            }
            system("cls");
            VISUALITZASIMPLE(matriu, caselles);
            printf("\nEstem colocant un vaixell de %i caselles", vaixell+1);
            while ((f<0)||(f>=caselles))
            {
                if (comprova>0)
                {
                    printf("\nFila incorrecta gamarus!!!");
                }
                printf("\nEn quina fila vols colocar el vaixell?: ");
                f=getche();
                f=f-48;
                comprova++;
            }
            comprova=0;
            while ((c<0)||(c>=caselles))
            {
                if (comprova>0)
                {
                    printf("\nColumna incorrecta cap de pardals!!!");
                }
                printf("\nEn quina columna vols colocar el vaixell?: ");
                c=getche();
                if (c>=97)
                {
                    c=c-32;
                }
                c=c-65;
                comprova++;
            }
            comprova=0;
            if (vaixell!=0)
            {
                while ((direccio!=1)&&(direccio!=0))
                {
                    if (comprova>0)
                    {
                        printf("\nDireccio incorrecta borinot!!!");
                    }
                    printf("\nEn quina direccio vols colocar el vaixell?: (H/V)");
                    direccio=getche();
                    if (direccio>=97) {direccio=direccio-32;}
                    if (direccio==72) {direccio=0;}
                    if (direccio==86) {direccio=1;}
                    comprova++;
                }
            }
            else
            {
                direccio=1; 
            }
            correcte=1;
            comprova=0;
            if ((((f+vaixell)>=caselles)&&(direccio==1))||(((c+vaixell)>=caselles)&&(direccio==0)))
            {
                correcte=0;
            }
            if (direccio==0)
            {
                superior=f-1;if (superior==-1){superior++;}
                inferior=f+1; if (inferior==caselles){inferior--;}
                esquerra=c-1; if (esquerra==-1){esquerra++;}
                dreta=c+vaixell+1; if (dreta==caselles){dreta--;}
            }
            else
            {
                superior=f-1;if (superior==-1){superior++;}
                inferior=f+vaixell+1; if (inferior==caselles){inferior--;}
                esquerra=c-1; if (esquerra==-1){esquerra++;}
                dreta=c+1; if (dreta==caselles){dreta--;}
            }
            while (esquerra<=dreta)
            {
                while (superior<=inferior)
                {
                    if (matriu[superior][esquerra]!='.') {correcte=0;}
                    superior++;
                    i++;
                }
                superior=superior-i;
                i=0;
                esquerra++;
            }
            control++;
            if (correcte==0)
            {
                direccio=-1;
                c=-1;
                f=-1;
            }
        }
        if (direccio==0)
        {
            while (j<=vaixell)
            {
                matriu[f][c+j]='X';
                j++;
            }
        }
        else
        {
            while(j<=vaixell)
            {
                matriu[f+j][c]='X';
                j++;
            }
        }
        comptador++;
        if (comptador==(4-vaixell))
        {
            comptador=0;
            vaixell--;
        }
        control=0;
        correcte=0;
        direccio=-1;
        c=-1;
        f=-1;
    }
    printf("\nJa has colocat tots els vaixells!! si fa patxoca... pero segur que perds :P");
}
bool EMMAGATZEMA_JOC(dadesjoc dades){
    FILE *f;
    int n;
    n=0;
    f=fopen("partida.bin","wb+");
    if (f!=NULL)
    {
        n=fwrite(&dades, sizeof(dadesjoc),1, f);
    }
    fclose(f);
return(n);
}
bool RECUPERA_JOC(dadesjoc *dades){
    FILE *f;
    int n;
    n=0;
    f=fopen("partida.bin","rb");
    if (f!=NULL)
    {
        n=fread(&*dades, sizeof(dadesjoc),1,f);
        fclose(f);
    }
    return(n);
}
int CALCULAPUNTUACIO(int caselles, int puntuacio, int llancaments){
    float casellesf, puntuaciof, llancamentsf;
    casellesf=caselles;
    llancamentsf=llancaments;
    puntuaciof=puntuacio*100*(casellesf/llancamentsf);
    puntuacio=puntuaciof;
    return(puntuacio);
}
bool EMMAGATZEMA_RECORDS(records_tipus records[10]){
    int n, i, j;
    FILE *f;
    f=fopen("records.txt","w");
    i=0;
    j=0;
    if (f!=NULL)
    {
        n=0;
        while (i!=10)
        {
            while (j!=20)
            {
                fprintf(f,"%c", records[i].nom[j]);
                j++;
            }
            fprintf(f, "%c", '\t');
            fprintf(f, "%i", records[i].puntuacio);
            fprintf(f, "%c", '\n');
            j=0;
            i++;
        }
    }
    else
    {
        n=-1;
    }
    fclose(f);
    return(n);
}
int RECUPERA_RECORDS(records_tipus records[10]){
    int i,k,n;
    char lectura;
    i=0;
    k=0;
    FILE *f;
    f=fopen("records.txt","r");
    if (f==NULL)
    {
        n=-1;
    }
    else
    {
        while (!feof(f))
        {
            while (k!=21)
            {
                fscanf(f, "%c", &lectura);
                if (lectura!='\t') {records[i].nom[k]=lectura;}
                k++;
            }
            fscanf(f, "%i", &records[i].puntuacio);
            fscanf(f, "%c", &lectura);
            k=0;
            i++;
        }
        fclose(f);
    }
    return(n);
}
void INICIALITZA_TAULA(records_tipus records[10]){
int i,k;
k=0;
while (k<=9)
{
    records[k].puntuacio=-666;
    k++;
}
k=0;
i=0;
while (i<=9)
{
    while (k<20)
    {
        records[i].nom[k]=' ';
        k++;
    }
k=0;
i++;
}
}
void IMPRIMIR_RECORDS(records_tipus records[10]){
int flag,i, k;
i=0;
k=0;
flag=0;
system("cls");
while (i<=9)
{
    if (records[i].puntuacio!=-666)
    {
        flag=1;
    }
    i++;
}
if (flag==1)
{
    i=0;
    printf ("Nom                 Puntuacio\n");
while (i<=9)
{
    if (records[i].puntuacio!=-666)
    {
        flag=1;
        while (k!=20)
        {
            printf("%c",records[i].nom[k]);
            k++;
        }
        printf ("%i", records[i].puntuacio);
        printf("\n");
        k=0;
    }
    i++;
}
}
else
{
    printf("El fitxer de records esta buit o no existeix, prova a afegir un record jugant.");
}
}
void POSA_AIGUA(char atac[][10],int f,int c, int caselles){
    int up, down, right, left, i;
    i=0;
    if (f-1>=0)
    {
        if (atac[f-1][c]=='@')
        {
            if (f-2>=0)
            {
                if (atac[f-2][c]=='@')
                {
                    if (f-3>=0)
                    {
                        if (atac[f-3][c]=='@')
                        {
                            if (f-4>=0)
                            {
                                up=f-4;
                            }
                            else
                            {
                                up=f-3;
                            }
                        }
                        else
                        {
                            up=f-3;
                        }
                    }
                    else
                    {
                        up=f-2;
                    }
                }
                else
                {
                    up=f-2;
                }
            }
            else
            {
                up=f-1;
            }
        }
        else
        {
            up=f-1;
        }
    }
    else
    {
        up=f;
    }
    if (c-1>=0)
    {
        if (atac[f][c-1]=='@')
        {
            if (c-2>=0)
            {
                if (atac[f][c-2]=='@')
                {
                    if (c-3>=0)
                    {
                        if (atac[f][c-3]=='@')
                        {
                            if (c-4>=0)
                            {
                                left=c-4;
                            }
                            else
                            {
                                left=c-3;
                            }
                        }
                        else
                        {
                            left=c-3;
                        }
                    }
                    else
                    {
                        left=c-2;
                    }
                }
                else
                {
                    left=c-2;
                }
            }
            else
            {
                left=c-1;
            }
        }
        else
        {
            left=c-1;
        }
    }
    else
    {
        left=c;
    }
    if (c+1<caselles)
    {
        if (atac[f][c+1]=='@')
        {
            if (c+2<caselles)
            {
                if (atac[f][c+2]=='@')
                {
                    if (c+3<caselles)
                    {
                        if (atac[f][c+3]=='@')
                        {
                            if (c+4<caselles)
                            {
                                right=c+4;
                            }
                            else
                            {
                                right=c+3;
                            }
                        }
                        else
                        {
                            right=c+3;
                        }
                    }
                    else
                    {
                        right=c+2;
                    }
                }
                else
                {
                    right=c+2;
                }
            }
            else
            {
                right=c+1;
            }
        }
        else
        {
            right=c+1;
        }
    }
    else
    {
        right=c;
    }
    if (f+1<caselles)
    {
        if (atac[f+1][c]=='@')
        {
            if (f+2<caselles)
            {
                if (atac[f+2][c]=='@')
                {
                    if (f+3<caselles)
                    {
                        if (atac[f+3][c]=='@')
                        {
                            if (f+4<caselles)
                            {
                                down=f+4;
                            }
                            else
                            {
                                down=f+3;
                            }
                        }
                        else
                        {
                            down=f+3;
                        }
                    }
                    else
                    {
                        down=f+2;
                    }
                }
                else
                {
                    down=f+2;
                }
            }
            else
            {
                down=f+1;
            }
        }
        else
        {
            down=f+1;
        }
    }
    else
    {
        down=f;
    }
     while (left<=right)
            {
                while (up<=down)
                {
                    if (atac[up][left]!='@') {atac[up][left]='.';}
                    up++;
                    i++;
                }
                up=up-i;
                i=0;
                left++;
            }
}
bool AFEGIR_RECORD(int puntuacio, records_tipus records[10], int jugador){
records_tipus record;
char opciorecord, lectura;
int i,j,k;
bool flag;
flag=0;
i=0;
j=0;
opciorecord='k';
lectura='k';
while (i!=10)
{
    if (records[i].puntuacio<=puntuacio) {flag=1;}
    i++;
}
if (flag==1)
{
    flag=0;
    while ((opciorecord!='s')&&(opciorecord!='S')&&(opciorecord!='N')&&(opciorecord!='n'))
    {
        system("cls");
        printf("Jugador %i, vols actualitzar els record? S/N ", jugador);
        opciorecord=getche();
    }
    if ((opciorecord=='s')||(opciorecord=='S'))
    {
        i=0;
        printf("\nIntrodueix el nom del jugador %i (20 caracters com a maxim) i apreta intro: ", jugador);
        while ((lectura!='\r')&&(i<20))
        {
            lectura=getche();
            if (lectura!='\r') {record.nom[i]=lectura;}
            i++;
        }
        i--;
        while (i!=20)
        {
            record.nom[i]=' ';
            i++;
        }
        system("cls");
        record.puntuacio=puntuacio;
        i=9;
        k=8;
        while (i>=0)
        {
            if (((records[i-1].puntuacio>record.puntuacio) && (records[i].puntuacio<=record.puntuacio))||((records[i].puntuacio<=record.puntuacio)&&(i==0)))
            {
                flag=1;
                while (k!=(i-1))
                {
                    records[k+1].puntuacio=records[k].puntuacio;
                    while (20!=j)
                    {
                        records[k+1].nom[j]=records[k].nom[j];
                        j++;
                    }
                k--;
                j=0;
                }
                records[i].puntuacio=record.puntuacio;
                k=0;
                while (k!=20)
                {
                    records[i].nom[k]=record.nom[k];
                    k++;
                }
            }
            i--;
        }
    }
}
return (flag);
}
int MONEDA(){
    char opcio;
    int flag,  opciok, guanya;
    flag=0;
while (flag==0)
{
printf("Que vols ser? Cara o creu?  C/X ") ;
opcio=getche();
if((opcio=='C') ||(opcio=='X') ||(opcio=='x') ||(opcio=='c'))
{
if (opcio=='c') {opcio='C';}
if(opcio=='x') {opcio='X';}
flag=true;
}
else
{
system("cls") ;
}
}
printf("\nApreta qualsevol tecla per a tirar la moneda: ") ;
getch();
opciok=rand()%2;
if (opciok==1)
{
printf("C \n") ;
if (opcio=='C')
{
printf("\nComenca el jugador 1\n");
guanya=1;
}
else
{
printf("\nComenca el jugador 2\n");
guanya=0;
}
}
else
{
printf("X\n") ;
if (opcio=='X')
{
printf("\nComenca el jugador 1\n");
guanya=1;
}
else
{
printf("\nComenca el jugador 2\n");
guanya=0;
}
}
if (guanya==0) {guanya=2;}
getch();
system("cls");
return(guanya) ;
}
int COMPROVA(char defensa[][10], int f, int c,int caselles, int *tirada){
int jugada, up, down, left, right;
up=0;
down=0;
left=0;
right=0;
    if (f-1>=0)
        {
            if (defensa[f-1][c]=='X')
            {
                jugada=2;
            }
            if ((defensa[f-1][c]=='.')||(defensa[f-1][c]=='-'))
            {
                up=1;
            }
            if (defensa[f-1][c]=='@')
            {
                if (f-2>=0)
                {
                    if (defensa[f-2][c]=='X')
                    {
                        jugada=2;
                    }
                    if ((defensa[f-2][c]=='.')||(defensa[f-2][c]=='-'))
                    {
                        up=1;
                    }
                    if (defensa[f-2][c]=='@')
                    {
                        if (f-3>=0)
                        {
                            if (defensa[f-3][c]=='X')
                            {
                                jugada=2;
                            }
                            if ((defensa[f-3][c]=='.')||(defensa[f-3][c]=='-'))
                            {
                                up=1;
                            }
                            if (defensa[f-3][c]=='@') {up=1;}
                        }
                        else
                        {
                            up=1;
                        }

                    }
                }
                else
                {
                    up=1;
                }
            }
        }
        else
        {
            up=1;
        }
        if (f+1<caselles)
        {
            if (defensa[f+1][c]=='X')
            {
                jugada=2;
            }
            if ((defensa[f+1][c]=='.')||(defensa[f+1][c]=='-'))
            {
                down=1;
            }
            if (defensa[f+1][c]=='@')
            {
                if (f+2<caselles)
                {
                    if (defensa[f+2][c]=='X')
                    {
                        jugada=2;
                    }
                    if ((defensa[f+2][c]=='.')||(defensa[f+2][c]=='-'))
                    {
                        down=1;
                    }
                    if (defensa[f+2][c]=='@')
                    {
                        if (f+3<caselles)
                        {
                            if (defensa[f+3][c]=='X')
                            {
                                jugada=2;
                            }
                            if ((defensa[f+3][c]=='.')||(defensa[f+3][c]=='-'))
                            {
                                down=1;
                            }
                            if (defensa[f+3][c]=='@') {down=1;}
                        }
                        else
                        {
                            down=1;
                        }
                    }
                }
                else
                {
                    down=1;
                }
            }
        }
        else
        {
            down=1;
        }
        if (c-1>=0)
        {
            if (defensa[f][c-1]=='X')
            {
                jugada=2;
            }
            if ((defensa[f][c-1]=='.')||(defensa[f][c-1]=='-'))
            {
                left=1;
            }
            if (defensa[f][c-1]=='@')
            {
                if (c-2>=0)
                {
                    if (defensa[f][c-2]=='X')
                    {
                        jugada=2;
                    }
                    if ((defensa[f][c-2]=='.')||(defensa[f][c-2]=='-'))
                    {
                        left=1;
                    }
                    if (defensa[f][c-2]=='@')
                    {
                        if (c-3>=0)
                        {
                            if (defensa[f][c-3]=='X')
                            {
                                jugada=2;
                            }
                            if ((defensa[f][c-3]=='.')||(defensa[f][c-3]=='-'))
                            {
                                left=1;
                            }
                            if (defensa[f][c-3]=='@') {left=1;}
                        }
                        else
                        {
                            left=1;
                        }
                    }
                }
                else
                {
                    left=1;
                }
            }
        }
        else
        {
            left=1;
        }
        if (c+1<caselles)
        {
            if (defensa[f][c+1]=='X')
            {
                jugada=2;
            }
            if ((defensa[f][c+1]=='.')||(defensa[f][c+1]=='-'))
            {
                right=1;
            }
            if (defensa[f][c+1]=='@')
            {
                if (c+2<caselles)
                {
                    if (defensa[f][c+2]=='X')
                    {
                        jugada=2;
                    }
                    if ((defensa[f][c+2]=='.')||(defensa[f][c+2]=='-'))
                    {
                        right=1;
                    }
                    if (defensa[f][c+2]=='@')
                    {
                        if (c+3<caselles)
                        {
                            if (defensa[f][c+3]=='X')
                            {
                                jugada=2;
                            }
                            if ((defensa[f][c+3]=='.')||(defensa[f][c+3]=='-'))
                            {
                                right=1;
                            }
                            if (defensa[f][c+3]=='@') {right=1;}
                        }
                        else
                        {
                            right=1;
                        }
                    }
                }
                else
                {
                    right=1;
                }
            }
        }
        else
        {
            right=1;
        }
        if ((up==1)&&(down==1)&&(left==1)&&(right==1)) {jugada=3;}
        *tirada=1;
    return(jugada);
}
void RANDOMIZE(int *fila, int *columna, int *direccio, int caselles){
    *fila=rand()%(caselles);
    *columna=rand()%(caselles);
    *direccio=rand()%2; 
}
int TIPUS_JOC(int *caselles){
    int opcio;
    opcio=0;
    *caselles=0;
    while ((*caselles>10)||(*caselles<8))
            {
                printf("De cuantes caselles vols que sigui el tauler? min 8 max 10: ");
                *caselles=getche();
                *caselles=*caselles-48;
                if (*caselles==1)
                {
                    while (*caselles!=0)
                    {
                        *caselles=getch();
                        *caselles=*caselles-48;
                    }
                    printf("0");
                    *caselles=10;
                }
                system("cls");
            }
            while ((opcio<1)||(opcio>3))
            {system("cls");
                printf("A quina modalitat de joc vols jugar?\n");
                printf("1.-Cap jugador\n");
                printf("2.-Un jugador\n");
                printf("3.-Dos jugadors\n");
                opcio=getche();
                opcio=opcio-48;
                system("cls");
            }
            return(opcio);
}
void INICIA_TAULELL(char matriu[][10], char matriuk[][10], int caselles){
    int control, vaixell, comptador, f, c, direccio, superior, dreta, inferior, esquerra, correcte, i, j;
repeteix:
    i=0;
    j=0;
    control=0;
    correcte=0;
    vaixell=3;
    comptador=0;
    while (i<10){ 
        while (j<10)
        {
            matriu[i][j]='.';
            j++;
        }
        j=0;
        i++;
    }
    i=0;
    while (i<10){ 
        while (j<10)
        {
            matriuk[i][j]='?';
            j++;
        }
        j=0;
        i++;
    }
    i=0;
    while (vaixell!=-1)
    {
        i=0;
        j=0;
        while (correcte==0)
        {
            correcte=1;
            RANDOMIZE(&f, &c, &direccio, caselles);
            if ((((f+vaixell)>=caselles)&&(direccio==1))||(((c+vaixell)>=caselles)&&(direccio==0)))
            {
                correcte=0;
            }
            if (direccio==0)
            {
                superior=f-1;if (superior==-1){superior++;}
                inferior=f+1; if (inferior==caselles){inferior--;}
                esquerra=c-1; if (esquerra==-1){esquerra++;}
                dreta=c+vaixell+1; if (dreta==caselles){dreta--;}
            }
            else
            {
                superior=f-1;if (superior==-1){superior++;}
                inferior=f+vaixell+1; if (inferior==caselles){inferior--;}
                esquerra=c-1; if (esquerra==-1){esquerra++;}
                dreta=c+1; if (dreta==caselles){dreta--;}
            }
            while (esquerra<=dreta)
            {
                while (superior<=inferior)
                {
                    if (matriu[superior][esquerra]!='.') {correcte=0;}
                    superior++;
                    i++;
                }
                superior=superior-i;
                i=0;
                esquerra++;
            }
            control++;
            if (control>=2000)
            {
                goto repeteix;
            }
        }
        correcte=0;
        if (direccio==0)
        {
            while (j<=vaixell)
            {
                matriu[f][c+j]='X';
                j++;
            }
        }
        else
        {
            while(j<=vaixell)
            {
                matriu[f+j][c]='X';
                j++;
            }
        }
        comptador++;
        if (comptador==(4-vaixell))
        {
            comptador=0;
            vaixell--;
        }
    }
}
int MOSTRAR_MENU(int *load){
    int menu;
    menu=0;
        while ((menu>7)|| (menu<1) || (menu==3 && *load==0) || (menu==4 && *load==0) || (menu==0))
        {
            printf("\nMenu:\n");
            printf("1.- Crear un nou joc\n");
            printf("2.- Carregar un joc emmagatzemat\n");
            if (*load==1)
            {
                printf("3.- Jugar partida\n");
                printf("4.- Emmagatzemar el joc\n");
            }
            printf("5.- Veure podium\n");
            printf("6.- Sortir del joc\n");
            printf("7.- Instruccions\n\n");
            printf("Selecciona la opcio i prem intro\n\n");
            menu=getche();
            menu=menu-48;
            system("cls");
        }
        return(menu);
    }
void VISUALITZA(char matriudefensa[][10],char matriuatac[][10],int caselles, int jugador){
    int i, k;
    k=0;
    i=0;
    printf("Jugador %i\nMatriu atac                ",jugador);
    if (caselles==9)
    {
        printf(" ");
    }
    if (caselles==10)
    {
        printf("  ");
    }
    printf("Matriu defensa\n");
    putchar(254);
    while (i<caselles)
    {
        putchar(i+65);
        i++;
    }
    printf("                  ");
    i=0;
    putchar(254);
    while (i<caselles)
    {
        putchar(i+65);
        i++;
    }
    i=0;
    printf("\n");
    while (i<caselles)
    {
        printf("%i",i);
        while(k<caselles)
        {
            printf("%c",matriuatac[i][k]);
            k++;
        }
        k=0;
        printf("                  ");
        printf("%i",i);
        while(k<caselles)
        {
            printf("%c",matriudefensa[i][k]);
            k++;
        }
        k=0;
        printf("\n");
        i++;
    }
}
int DISPARA(char defensa[][10], char atac[][10], int *f, int *c, int *jugada, int caselles, int *orientacio, int *vertical, int *horitzontal, int noacabat){
int  tirada, fila, columna, correcte;
correcte=0;
tirada=0;
while (tirada==0)
{
if ((*jugada==1)&&(noacabat==0))
{
    while (correcte==0)
    {
        *f=rand()%(caselles);
        *c=rand()%(caselles);
        if (atac[*f][*c]=='?') {correcte=1;}
    }
    if (defensa[*f][*c]=='X')
    {
        defensa[*f][*c]='@';
        atac[*f][*c]='@';
        fila=*f;
        columna=*c;
        *jugada=COMPROVA(defensa, fila, columna, caselles, &tirada);
    }
    if (defensa[*f][*c]=='.')
    {
        defensa[*f][*c]='-';
        atac[*f][*c]='.';
        *jugada=1;
    }
    tirada=1;
}
if (((*jugada==2)||(noacabat==1))&&(tirada==0))
{
    if (*orientacio==-1)
    {
        *orientacio=rand()%2;
    }
    if (*orientacio==0)
    {
        if (*horitzontal==-1)
        {
            *horitzontal=rand()%2;
        }
        if (*horitzontal==0)
        {
            if (*c-1>=0)
            {
                if (atac[*f][*c-1]=='?')
                {
                    if ((defensa[*f][*c-1]=='X')&&(tirada==0))
                    {
                        defensa[*f][*c-1]='@';
                        atac[*f][*c-1]='@';
                        *c=*c-1;
                        fila=*f;
                        columna=*c;
                        *jugada=COMPROVA(defensa, fila, columna, caselles, &tirada);
                        *orientacio=0;
                        if (*jugada==3)
                        {
                            *orientacio=-1;
                            *horitzontal=-1;
                        }
                        tirada=1;
                    }
                    if ((defensa[*f][*c-1]=='.')&&(tirada==0))
                    {
                        defensa[*f][*c-1]='-';
                        atac[*f][*c-1]='.';
                        *horitzontal=1;
                        *jugada=1;
                        tirada=1;
                        if (*c+1<caselles)
                        {
                            if ((atac[*f][*c-1]=='.')&&(atac[*f][*c+1]=='.'))
                            {
                                *orientacio=1;
                                *horitzontal=-1;
                            }
                        }
                        else
                        {
                            *orientacio=1;
                            *horitzontal=-1;
                        }
                    }
                }
                if ((atac[*f][*c-1]=='@')&&(tirada==0))
                {
                    *c=*c-1;
                    *orientacio=0;
                }
                if ((atac[*f][*c-1]=='.')&&(tirada==0))
                {
                    *horitzontal=1;
                    if ((atac[*f][*c-1]=='.')&&(atac[*f][*c+1]=='.'))
                    {
                        *orientacio=1;
                        *horitzontal=-1;
                    }
                }
            }
            else
            {
                *horitzontal=1;
                if (atac[*f][*c+1]=='.')
                {
                    *orientacio=1;
                    *horitzontal=-1;
                }
            }
        }
        else 
        {
        if (*c+1<caselles)
            {
                if (atac[*f][*c+1]=='?')
                {
                    if ((defensa[*f][*c+1]=='X')&&(tirada==0))
                    {
                        defensa[*f][*c+1]='@';
                        atac[*f][*c+1]='@';
                        *c=*c+1;
                        fila=*f;
                        columna=*c;
                        *jugada=COMPROVA(defensa, fila, columna, caselles, &tirada);
                        *orientacio=0;
                        tirada=1;
                        if (*jugada==3)
                        {
                            *orientacio=-1;
                            *horitzontal=-1;
                        }
                    }
                    if ((defensa[*f][*c+1]=='.')&&(tirada==0))
                    {
                        defensa[*f][*c+1]='-';
                        atac[*f][*c+1]='.';
                        *horitzontal=0;
                        *jugada=1;
                        tirada=1;
                        if (*c-1>=0)
                        {
                            if ((atac[*f][*c-1]=='.')&&(atac[*f][*c+1]=='.'))
                            {
                                *orientacio=1;
                                *horitzontal=-1;
                            }
                        }
                        else
                        {
                            *orientacio=1;
                            *horitzontal=-1;
                        }
                    }
                }
                if ((atac[*f][*c+1]=='@')&&(tirada==0))
                {
                    *c=*c+1;
                    *orientacio=0;
                }
                if ((atac[*f][*c+1]=='.')&&(tirada==0))
                {
                    *horitzontal=0;
                    if ((atac[*f][*c+1]=='.')&&(atac[*f][*c-1]=='.'))
                    {
                        *orientacio=1;
                        *horitzontal=-1;
                    }
                }
            }
            else
            {
                *horitzontal=0;
                if (atac[*f][*c-1]=='.')
                {
                    *orientacio=1;
                    *horitzontal=-1;
                }
            }
        }
    }
    else 
    {
        if (*vertical==-1)
        {
            *vertical=rand()%2;
        }
        if (*vertical==0) 
        {
            if (*f-1>=0)
            {
                if (atac[*f-1][*c]=='?')
                {
                    if ((defensa[*f-1][*c]=='X')&&(tirada==0))
                    {
                        defensa[*f-1][*c]='@';
                        atac[*f-1][*c]='@';
                        *f=*f-1;
                        fila=*f;
                        columna=*c;
                        *jugada=COMPROVA(defensa, fila, columna, caselles, &tirada);
                        *orientacio=1;
                        tirada=1;
                        if (*jugada==3)
                        {
                            *orientacio=-1;
                            *vertical=-1;
                        }
                    }
                    if ((defensa[*f-1][*c]=='.')&&(tirada==0))
                    {
                        defensa[*f-1][*c]='-';
                        atac[*f-1][*c]='.';
                        *vertical=1;
                        *jugada=1;
                        tirada=1;
                        if ((atac[*f-1][*c]=='.')&&(atac[*f+1][*c]=='.'))
                        {
                            *orientacio=0;
                            *vertical=-1;
                        }
                    }
                }
                if ((atac[*f-1][*c]=='@')&&(tirada==0))
                {
                    *f=*f-1;
                    *orientacio=1;
                }
                if ((atac[*f-1][*c]=='.')&&(tirada==0))
                {
                    *vertical=1;
                    if (*f+1<caselles)
                    {
                        if ((atac[*f-1][*c]=='.')&&(atac[*f+1][*c]=='.'))
                        {
                            *orientacio=0;
                            *vertical=-1;
                        }
                    }
                    else
                    {
                        *vertical=-1;
                        *orientacio=0;
                    }
                }
            }
            else
            {
                *vertical=1;
                if (atac[*f+1][*c]=='.')
                {
                    *orientacio=0;
                    *vertical=-1;
                }
            }
        }
        else 
        {
        if (*f+1<caselles)
            {
                if (atac[*f+1][*c]=='?')
                {
                    if ((defensa[*f+1][*c]=='X')&&(tirada==0))
                    {
                        defensa[*f+1][*c]='@';
                        atac[*f+1][*c]='@';
                        *f=*f+1;
                        fila=*f;
                        columna=*c;
                        *jugada=COMPROVA(defensa, fila, columna, caselles, &tirada);
                        *orientacio=1;
                        tirada=1;
                        if (*jugada==3)
                        {
                            *orientacio=-1;
                            *vertical=-1;
                        }
                    }
                    if ((defensa[*f+1][*c]=='.')&&(tirada==0))
                    {
                        defensa[*f+1][*c]='-';
                        atac[*f+1][*c]='.';
                        *vertical=0;
                        *jugada=1;
                        tirada=1;
                        if (*f-1>=0)
                        {
                            if ((atac[*f-1][*c]=='.')&&(atac[*f+1][*c]=='.'))
                            {
                                *orientacio=0;
                                *vertical=-1;
                            }
                        }
                        else
                        {
                            *orientacio=0;
                            *vertical=-1;
                        }

                    }
                }
                if ((atac[*f+1][*c]=='@')&&(tirada==0))
                {
                    *f=*f+1;
                    *orientacio=1;
                }
                if ((atac[*f+1][*c]=='.')&&(tirada==0))
                {
                    *vertical=0;
                    if (atac[*f-1][*c]=='.')
                    {
                        *orientacio=0;
                        *vertical=-1;
                    }
                }
            }
            else
            {
                *vertical=0;
                if (atac[*f-1][*c]=='.')
                {
                    *orientacio=0;
                    *vertical=-1;
                }
            }
        }
    }
}
if ((*jugada==3)&&(tirada==0))
{
*jugada=1;
noacabat=0;
tirada=0;
}
}
return (*jugada);
}
