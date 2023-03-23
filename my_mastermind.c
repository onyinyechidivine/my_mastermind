#include "headerfile.h"
// check if the user's guess is misplaced
int it_misplaced(char* secretcode, char* guess){
    int it_misplaced=0; int i,j;
    int p = strlen(guess);
    int y = strlen(secretcode);
    for(i=0; i < p;i++){
        for(j=0;j<y;j++){
            if(guess[i]==secretcode[j]){
                it_misplaced++;
              
            }
        }
    }
    return it_misplaced;
}
// check if the user's guess is well placed
int it_wellplaced(char* secretcode, char* guess){
    int it_wellplaced = 0; int i;
    int p = strlen(guess);
    for(i=0; i< p;i++){
        if(guess[i]==secretcode[i]){
            it_wellplaced++;
        }
    }
    return it_wellplaced;
    
}
// check if the user's guess is a digit btw 0-8
int check(char* guess){
    int count = 0; int i;
    int p = strlen(guess);
    for(i=0; i < p; i++){
        if(guess[i] >='0' && guess[i]<='8'){
            count++;
        }
    }
    if(count == 4){
        return 1;
    }
    else{
        return 0;
    }
    
}
// to read the user's input
int gabriel(char the_input[]){
    int freeman =read(0,the_input,5);
    the_input[5]='\0';
    return freeman;
}
// generate a secertcode code of 4 digits
int main(int argc, char** argv){
    char secretcode[5];
        if(argc > 2 && argv [1][0]=='-' && argv[1][1]=='c'){
            for(int i =0; i < 4; i++){
                secretcode[i]=argv[2][i];
            }
        }
        else {
            //Generate a random code
            srand(time(NULL));
            int arrs[5];
            bool unique_num = true;
            int random_numb ;
            for(int i =0; i < 4; i++){
                do{
                    random_numb = (rand() % 8);
                    for(int u = 0; u < i; u++){
                        if(arrs[u]== random_numb){
                            unique_num =false;
                        }
                    }
                }
                    while(!unique_num);
                    secretcode[i]=(random_numb + '0');
                
            }

        }
        secretcode[4] ='\0';
        
        char guess[6];
        int sphere = 0;
        printf("Will you find the secret code?\nPlease enter a valid guess\n");

        while(it_wellplaced(secretcode,guess)<4 && sphere < 10){
            //To read the input of the guess
            if(gabriel(guess)==0){
                return 0;
            }
            if (check(guess)){
                printf("\nRound %d\nWell placed pieces: %d\nMisplaced pieces: %d\n",sphere,it_wellplaced(secretcode,guess),it_misplaced(secretcode,guess)-it_wellplaced(secretcode,guess));
                sphere++;
            }
            else{
                printf("Wrong input!\n");

            }
        }
        printf("Congratz! You did it!");
        return 0;

}