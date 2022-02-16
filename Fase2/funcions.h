#include "tipus.h"
void VISUALITZASIMPLE(char matriujocaa[][10],int caselles);
void PAUSA();
void INICIA_EL_MEU_TAULELL(char matriu[][10], char matriuk[][10], int caselles);
bool EMMAGATZEMA_JOC(dadesjoc dades);
bool RECUPERA_JOC(dadesjoc *dades);
int CALCULAPUNTUACIO(int caselles, int puntuacio, int llancaments);
bool EMMAGATZEMA_RECORDS(records_tipus records[10]);
int RECUPERA_RECORDS(records_tipus records[10]);
void INICIALITZA_TAULA(records_tipus records[10]);
void IMPRIMIR_RECORDS(records_tipus records[10]);
void POSA_AIGUA(char atac[][10],int f,int c, int caselles);
bool AFEGIR_RECORD(int puntuacio, records_tipus records[10], int jugador);
int MONEDA();
int COMPROVA(char defensa[][10], int f, int c,int caselles, int *tirada);
void RANDOMIZE(int *fila, int *columna, int *direccio, int caselles);
int TIPUS_JOC(int *caselles);
void INICIA_TAULELL(char matriu[][10], char matriuk[][10], int caselles);
int MOSTRAR_MENU(int *load);
void VISUALITZA(char matriudefensa[][10],char matriuatac[][10],int caselles, int jugador);
int DISPARA(char defensa[][10], char atac[][10], int *f, int *c, int *jugada, int caselles, int *orientacio, int *vertical, int *horitzontal, int noacabat);