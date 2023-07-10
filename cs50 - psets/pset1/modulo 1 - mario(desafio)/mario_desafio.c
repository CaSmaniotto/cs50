#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = 0;
    int row = 1;
    int rowlenght;
    int space;
    
    do{
    height = get_int("choose a height between 1 and 8:  ");
    }
    while (height < 1 || height > 8);
    
    
    //1st row = ....#..#            height = 5
    //2nd row = ...##..##    row = 1     space = 4
    //3rd row = ..###..###   space = height - row
    //4th row = .####..#### 
    //5th row = #####..#####    (edit: print spaces, reprint rowlenght)
    
    for(;row<=height;row++){
        
    space = height - row;
    rowlenght = row;
        
        //the if statement checks if space is > 0 before entering the do loop.
        if(space>0){
            
            //the do loop makes space decreases by 1 until its = 0.
            do{
                printf(" ");
                space--;
            }while(space>0);
        
        }
        
        /*rowlenght = row,so rowlenght prints itself the amount of the row value,
                decreasing its value by 1 until it reaches 0*/
        do{
            printf("#");
            rowlenght--;
        }while (rowlenght >0);
        
        
        printf("  "); //prints spaces in between the pyramids
        
        rowlenght = row; //resets rowlenght value to row
        
        //reprints the same pyramid without the spaces
        do{
            printf("#");
            rowlenght--;
        }while (rowlenght >0);
        
    printf("\n"); //this ends the line before repeating the for loop.
    }
}
 
