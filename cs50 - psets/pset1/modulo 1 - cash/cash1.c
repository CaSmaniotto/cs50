#include <stdio.h>
#include <cs50.h>

int main (void){
    //to use precise values we can't use floating decimals or code might bug
    int change[4];
    change [0] = 25;
    change [1] = 10;
    change [2] = 5;
    change [3] = 1;
    //coin counter
    int coins[4];
    coins [0] = 0;
    coins [1] = 0;
    coins [2] = 0;
    coins [3] = 0;

    //recieves imprecise input
    float money = get_float("Change Owed: ");
    //makes it precise
        money = money*100;
        money = (int)money;

    //enters a loop where the money keeps being subtracted until its 0
    do{
        //checks if it can subtract quarters and do if so.
        if(money>=change[0]){
            do{
                money = money - change[0];
                coins[0]++;
            }while(money>=change[0]);

        }
        //checks if it can subtract dimes and do if so.
        if(money>=change[1]){
            do{
                money = money - change[1];
                coins[1]++;
            }while(money>=change[1]);

        }
       //checks if it can subtract nickels and do if so.
       if(money>=change[2]){
            do{
                money = money - change[2];
                coins[2]++;
            }while(money>=change[2]);

        }
        //checks if it can subtract pennies and do if so.
        if(money>=change[3]){
            do{
                money = money - change[3];
                coins[3]++;
            }while(money>=change[3]);

        }



    }while(money > 0);
    //prints the amount of coins needed
    printf("You need a minimum of: %i coins to pay\n",coins[0]+coins[1]+coins[2]+coins[3]);
    //prints amount of each coin.
    printf("%i: 0.25 coins\n",coins[0]);
    printf("%i: 0.10 coins\n",coins[1]);
    printf("%i: 0.05 coins\n",coins[2]);
    printf("%i: 0.01 coins\n",coins[3]);
}