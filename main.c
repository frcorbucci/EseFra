#include <stdio.h>
#include <stdlib.h>

// Definisci le costanti
#define MAX_LEN 30
#define MAX_FNAME 255

// Definisco il tipo di dato struct s_studente
struct s_studente {
    char nome[MAX_LEN+1];
    char cognome[MAX_LEN+1];
    int eta;
    char classe[MAX_LEN+1];
};

// Definisci studente come struct s_studente
typedef struct s_studente studente;

int main(int argc, char** argv) {
    // Dichiaro le variabili locali
    studente k;
    int i;
    FILE *puntaFile;
    char fileName[MAX_FNAME+1];
    
    // Codice per la richiesta del nome del file
    printf("Inserisci il nome del file da cui leggere i dati: ");
    scanf("%s", fileName);
    
    //apertura del file
    puntaFile = fopen(fileName, "rb");
    //serve per far concludere il programma per aver scritto male il nome del File
    if(puntaFile == NULL) {
        fprintf(stderr, "ERRORE: Impossibile aprire il file %s in lettura\n", puntaFile);
        exit(1);
    }         
    //serve per far continuare il programma
    else{
    for(i=0;!feof(puntaFile);i++)
    {
    //serve per il primo studente
     if(i==0)
     {
     fscanf(puntaFile, "%[^;];%[^;];%[^;];%[^;\n]\n", k.nome, k.nome, k.nome, k.nome);
     fscanf(puntaFile, "%[^;];%[^;];%d;%[^;\n]\n", k.nome, k.cognome, &(k.eta), k.classe);
     }
    //serve per i successivi studenti
     else
     {
     fscanf(puntaFile, "%[^;];%[^;];%d;%[^;\n]\n", k.nome, k.cognome, &(k.eta), k.classe);
     }
     //usato per stampare gli studenti
      printf("Studente %d\nNome: %s\nCognome: %s\nEta': %d\nClasse: %s\n\n",
                i+1,
                k.nome,
                k.cognome,
                k.eta,
                k.classe);   
    }
    }
    //chiudo il file
    fclose(puntaFile);
    
    return (EXIT_SUCCESS);
}
