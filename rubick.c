
#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int indexCol[6] = {4,4,7,10,4,1};
int indexRow[6] = {1,4,4,4,7,4};

int cube[9][12] = {};

int adjMatrix[6][6] = {{0,1,1,1,0,1},
                       {1,0,1,1,1,1},
                       {1,1,0,0,1,0},
                       {1,0,1,0,1,1},
                       {0,1,1,1,0,1},
                       {1,1,0,1,1,0}};
int main(){
    loadCube(cube);
    printCube(cube);    
    for(int i=0; i<6; i++){
        printf("%d", cube[indexRow[i]][indexCol[i]]);
    }

}

// void rotate_cube(colour, direction){
//     if(direction == "CLOCKWISE"){
//         switch(colour){
//             case 1:
                
//                 break;
//             default:

//         }
//     }else{

//     }
// }

