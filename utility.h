#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// verifichiamo se num si puo mettere in grid
int valido(int grid[9][9], int row, int col, int num){
    for(int i = 0; i < 9; i++)//controlla riga
        if(grid[row][i] == num)
        return 0;

    for(int i = 0; i < 9; i++)//controlla colonna
        if(grid[i][col] == num)
        return 0;
    
    int startrow = row - row % 3;
    int startcol = col - col % 3;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(grid[startrow + i][startcol + j] == num)
            return 0;
    
    return 1;// numero valido
}

//funzione principale per risolvere il sudoku
//cerca una cella vuota (0 inserito da utente) se non ce ne sono il sudoku e risolto
int risolvi_sudoku(int grid[9][9]){
    int row = -1, col = -1;
    int trovato = 0;

    for(int i = 0; i < 9 && !trovato; i++){
        for(int j = 0; j < 9; j++){
            if(grid[i][j] == 0){
                row = i;
                col = j;
                trovato = 1;
                break;
            }
        }
    }

    if(!trovato) return 1; // sudoku completo

    for(int num = 1; num <= 9; num++){
        if(valido(grid, row, col, num)){
            grid[row][col] = num;
            if (risolvi_sudoku(grid)) 
            return 1;
            grid[row][col] = 0; // backtrack
        }
    }
    return 0; // nessuna soluzione possibile
}


void griglia(int grid[9][9]){
   for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            printf("(%d)", grid[x][y]);
            if ((y + 1) % 3 == 0 && y < 8) printf("|"); // separatore verticale
        }
        printf("\n");
        if ((x + 1) % 3 == 0 && x < 8)
            printf("---------+---------+---------\n"); // separatore orizzontale
    }
}

void chiedi_griglia(int grid[9][9]){
    char riga[100]; // per leggere la riga

    for(int x = 0; x < 9; x++){
    
    while(1){
        printf("inserisci la riga %d: \n", x+1);
        if (fgets(riga, sizeof(riga), stdin) == NULL){
            printf("qualcosa e andato storto\n");
            continue;
        }

        int count = 0;
        char *token = strtok(riga, " \n");// estraggo i numeri come stringa

        while(token != NULL && count < 9){
            int val = atoi(token);//converto il token in intero
            if(val < 0 || val > 9){
                printf("il numero deve stare dentro... 1 e 9\n");
                count--;
                break;
            }
            grid[x][count++] = val;//salva il numero nella griglia
            token = strtok(NULL, " \n"); // passa al numero successivo( lo spazio e importante in " \n")
        }

        if (count == 9 && token == NULL) break; // se abbiamo letto 9 numeri validi, usciamo dal ciclo
        else      
                printf("Devi inserire esattamente 9 numeri.\n");
                      
    }    
    }
}