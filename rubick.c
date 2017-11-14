
#include <stdio.h>
#include <stdlib.h>

int indexCol[6] = {4,4,7,10,4,1};
int indexRow[6] = {1,4,4,4,7,4};

int cube[9][12] = {{0,0,0,1,1,1,0,0,0,0,0,0},
                   {0,0,0,1,1,1,0,0,0,0,0,0},
                   {0,0,0,1,1,1,0,0,0,0,0,0},
                   {6,6,6,2,2,2,3,3,3,4,4,4},
                   {6,6,6,2,2,2,3,3,3,4,4,4},
                   {6,6,6,2,2,2,3,3,3,4,4,4},
                   {0,0,0,5,5,5,0,0,0,0,0,0},
                   {0,0,0,5,5,5,0,0,0,0,0,0},
                   {0,0,0,5,5,5,0,0,0,0,0,0}};

int adjMatrix[6][6] = {{0,1,1,1,0,1},
                       {1,0,1,1,1,1},
                       {1,1,0,0,1,0},
                       {1,0,1,0,1,1},
                       {0,1,1,1,0,1},
                       {1,1,0,1,1,0}}
int main(){
    for(int i=0; i<9; i++){
        for(int j=0; j<12; j++){
            printf("%d ",cube[i][j]);
        }
        printf("\n");
    }
    
    for(int i=0; i<6; i++){
        printf("%d", cube[indexRow[i]][indexCol[i]]);
    }

}

void rotate_cube(colour, direction){
    if(direction == "CLOCKWISE"){
        switch(colour){
            case 1:
                
                break;
            default:

        }
    }else{

    }
}

