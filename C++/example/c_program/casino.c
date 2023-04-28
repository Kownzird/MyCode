#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

double balance = 0;
double step = 0;
long count = 0;

float get_rand_num(){
    float f = rand() % 10001;
    f /= 100.0;
    return f;
}


bool check_result(float result){
    if(result >= 50.50){
        return 1;
    }else{
        return 0;
    }
}

void set_balance(double b){
    balance = b;
}

void set_step(double s){
    step = s;
}

bool disk_bet(double bet){
    if(check_result(get_rand_num())){
        balance += bet;
        return true;
    }else{
        balance -= bet;
        return false;
    }
}

void play_game_doublestyle(){
    long count = 1;
    double s = step;
    long maxFail = 0;
    long fail = 0;
    double maxBalance = 0;

    while(balance > 0){
        if(!disk_bet(s)){
            fail++;
            if(maxFail < fail){
                maxFail = fail;
            }
            s *= 2; 
        }else{
            fail=0;
            s = step;
        }
        if(maxBalance < balance){
            maxBalance = balance;
        }
        count++;
    }
    printf("|-------------------------------\n");
    printf("|   YOUR BALANCE IS EMPTY! (D)  \n");
    printf("|-------------------------------\n");
    printf("|   count=%ld\t\t\t\n", count);
    printf("|   MaxFail=%ld\t\t\t\n", maxFail);
    printf("|   MaxBalance=%lf\t\t\n", maxBalance);
    printf("|-------------------------------\n\n");
}

void play_game_singlestyle(){
    long count = 1;
    double s = step;
    long maxFail = 0;
    long fail = 0;
    double maxBalance = 0;

    while(balance > 0){
        if(!disk_bet(s)){
            fail++;
            if(maxFail < fail){
                maxFail = fail;
            }
        }else{
            fail=0;
        }
        if(maxBalance < balance){
            maxBalance = balance;
        }
        count++;
    }
    printf("|-------------------------------\n");
    printf("|   YOUR BALANCE IS EMPTY!  (S) \n");
    printf("|-------------------------------\n");
    printf("|   count=%ld\t\t\t\n", count);
    printf("|   MaxFail=%ld\t\t\t\n", maxFail);
    printf("|   MaxBalance=%lf\t\t\n", maxBalance);
    printf("|-------------------------------\n\n");
}


int main(int argc, char **argv){
    

    srand(time(NULL));

    if(argc < 3){
        fprintf(stderr,"<Usage>: %s <Balance> <Step>\n",argv[0]);
        return -1;
    }

    set_balance(atof(argv[1]));
    set_step(atof(argv[2]));


    // play_game_singlestyle();
    play_game_doublestyle();
    
    return 0;
}