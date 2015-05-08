#include <stdio.h>
#include <stdlib.h>

// Definisci le costanti
#define MAX_LEN 30
#define MAX_FNAME 255

// Definisco il tipo di dato struct s_studente

struct s_studente {
    char nome[MAX_LEN + 1];
    char cognome[MAX_LEN + 1];
    int eta;
    char classe[MAX_LEN + 1];
};

// Definisci studente come struct s_studente
typedef struct s_studente studente;

int main(int argc, char** argv) {
    // Dichiaro le variabili locali
    studente k;
    int i;
    FILE *puntaFile;
    char fileName[MAX_FNAME + 1];
    int returnCode = EXIT_SUCCESS;

    // Codice per la richiesta del nome del file
    printf("Inserisci il nome del file da cui leggere i dati: ");
    scanf("%s", fileName);

    //apertura del file
    puntaFile = fopen(fileName, "rb");
    //serve per far concludere il programma per aver scritto male il nome del File
    if (puntaFile == NULL) {
        fprintf(stderr, "ERRORE: Impossibile aprire il file %s in lettura\n", puntaFile);
        //exit(1);
        returnCode = 1;
        /* NOTA_PROF
         * L'invocazione della funzione exit interrompe l'esecuzione del programma.
         * Se vuoi impiegare il ramo else nella verifica della corretta apertura del
         * file, non serve, quindi, invocare exit.
         * Se, invece, vuoi usare exit, non serve impiegare il ramo else.
         */
    }
        //serve per far continuare il programma
    else {
        /* La corretta indentazione del codice è essenziale per la sua chiarezza.
         * Ti invito a notare lo strumento nel menù Source->Format
         */
        for (i = 0; !feof(puntaFile); i++) {
            
            if (i == 0) {
                /* NOTA_PROF
                 * La prima riga del file contiene l'intestazione delle colonne:
                 * la leggo e non la utilizzo.
                 */
                fscanf(puntaFile, "%[^;];%[^;];%[^;];%[^;\n]\n", k.nome, k.nome, k.nome, k.nome);
            }
            else {
                fscanf(puntaFile, "%[^;];%[^;];%d;%[^;\n]\n", k.nome, k.cognome, &(k.eta), k.classe);
                /* NOTA_PROF
                 * La stampa dei dati avviene solo dalla seconda riga in poi,
                 * quando leggo effettivamente dei dati inerenti gli studenti.
                 */
                printf("Studente %d\nNome: %s\nCognome: %s\nEta': %d\nClasse: %s\n\n",
                    i,
                    k.nome,
                    k.cognome,
                    k.eta,
                    k.classe);
            }            
        }

        /* NOTA_PROF
         * La chiusura del file deve avvenire solo nel caso che sia stato aperto
         * con successo.         
         */
        //chiudo il file
        fclose(puntaFile);
    }

    return returnCode;
}
