#ifndef TIPUS_H_INCLUDED
#define TIPUS_H_INCLUDED
typedef struct{
    int opcio;
    int caselles;
    char matriujocaa[10][10];
    char matriujocab[10][10];
    char matriujocba[10][10];
    char matriujocbb[10][10];
    int noacabata;
    int noacabatb;
    int puntuacioa;
    int puntuaciob;
    int llancamentsa;
    int llancamentsb;
    int tira;
    int encertsa;
    int encertsb;
    int filaa;
    int filab;
    int columnaa;
    int columnab;
    int jugadaa;
    int jugadab;
    int orientacioa;
    int orientaciob;
    int verticala;
    int verticalb;
    int horitzontala;
    int horitzontalb;
    int monflag;
}dadesjoc;
typedef struct{
char nom[20];
int puntuacio;
}records_tipus;
#endif // TIPUS_H_INCLUDED
