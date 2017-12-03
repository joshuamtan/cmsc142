
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#define N 3

int indexCol[6] = {4,4,7,10,4,1};
int indexRow[6] = {1,4,4,4,7,4};

int cube[6][4*N] = {};

void rotate_cube(int colour, int direction){
    int temp;
    int tempArray[N] = {};
    if(direction == 0){
        switch(colour){
            case 1:
            //transpose
                for(int i=0; i<N; i++){
                  for(int j=0; j<N; j++){
                      if(i!=j && i<j){
                          temp = cube[i][j+N];
                          cube[i][j+N] = cube[j][i+N];
                          cube[j][i+N] = temp;
                      }
                  }
                }
            //reverse
                for(int i=0; i<N; i++){
                  temp = cube[0][i+N];
                  cube[0][i+N] = cube[N-1][i+N];
                  cube[N-1][i+N] = temp;
                }
            //swap
                  for(int j=0; j<N; j++){
                      tempArray[j] = cube[N][j+N*3];
                  }
                  for(int j=N*3-1; j>=0; j--){
                      cube[N][j+3] = cube[N][j];
                  }
                  for(int j=0; j<N; j++){
                      cube[N][j] = tempArray[j];
                  }

                break;
            case 2:
            //transpose
                for(int i=0; i<N; i++){
                  for(int j=0; j<N; j++){
                      if(i!=j && i<j){
                          temp = cube[i+N][j];
                          cube[i+N][j] = cube[j+N][i];
                          cube[j+N][i] = temp;
                      }
                  }
                }
            //reverse
                for(int i=0; i<N; i++){
                  temp = cube[0+N][i];
                  cube[0+N][i] = cube[N-1+N][i];
                  cube[N-1+N][i] = temp;
                }
            //swap
                for(int j=0; j<N; j++){
                    temp = cube[j+N][N*4-1];
                    cube[j+N][N*4-1] = cube[j][N];
                    cube[j][N] = temp;
                }
                for(int j=0; j<N; j++){
                    temp = cube[j][N];
                    cube[j][N] = cube[j+N][N];
                    cube[j+N][N] = temp;
                }
                for(int j=0; j<N; j++){
                    temp = cube[j+N][N];
                    cube[j+N][N] = cube[j+N*2][N];
                    cube[j+N*2][N] = temp;
                }
                break;
            case 3:
            //transpose
                for(int i=0; i<N; i++){
                  for(int j=0; j<N; j++){
                      if(i!=j && i<j){
                          temp = cube[i+N][j+N];
                          cube[i+N][j+N] = cube[j+N][i+N];
                          cube[j+N][i+N] = temp;
                      }
                  }
                }
            //reverse
                for(int i=0; i<N; i++){
                  temp = cube[0+N][i+N];
                  cube[0+N][i+N] = cube[N-1+N][i+N];
                  cube[N-1+N][i+N] = temp;
                }
            //swap
                for(int j=0; j<N; j++){
                    temp = cube[j+N][N-1];
                    cube[j+N][N-1] = cube[N-1][j+N];
                    cube[N-1][j+N] = temp;
                }
                temp = cube[N][N-1];
                cube[N][N-1] = cube[N*2-1][N-1];
                cube[N*2-1][N-1] = temp;
                for(int j=0; j<N; j++){
                    temp = cube[N-1][j+N];
                    cube[N-1][j+N] = cube[j+N][N*2];
                    cube[j+N][N*2] = temp;
                }
                temp = cube[N*2][N];
                cube[N*2][N] = cube[N*2][N*2-1];
                cube[N*2][N*2-1] = temp;
                for(int j=0; j<N; j++){
                    temp = cube[j+N][N*2];
                    cube[j+N][N*2] = cube[N*2][j+N];
                    cube[N*2][j+N] = temp;
                }
                break;
            case 4:
            //transpose
                for(int i=0; i<N; i++){
                  for(int j=0; j<N; j++){
                      if(i!=j && i<j){
                          temp = cube[i+N][j+N*2];
                          cube[i+N][j+N*2] = cube[j+N][i+N*2];
                          cube[j+N][i+N*2] = temp;
                      }
                  }
                }
            //reverse
                for(int i=0; i<N; i++){
                  temp = cube[0+N][i+N*2];
                  cube[0+N][i+N*2] = cube[N-1+N][i+N*2];
                  cube[N-1+N][i+N*2] = temp;
                }
            //swap
                for(int j=0; j<N; j++){
                    temp = cube[j+N][N*2-1];
                    cube[j+N][N*2-1] = cube[j+N*2][N*2-1];
                    cube[j+N*2][N*2-1] = temp;
                }
                for(int j=0; j<N; j++){
                    temp = cube[j][N*2-1];
                    cube[j][N*2-1] = cube[j+N][N*2-1];
                    cube[j+N][N*2-1] = temp;
                }
                for(int j=0; j<N; j++){
                    temp = cube[j][N*2-1];
                    cube[j][N*2-1] = cube[j+N][N*3];
                    cube[j+N][N*3] = temp;
                }
                temp = cube[0][N*2-1];
                cube[0][N*2-1] = cube[N-1][N*2-1];
                cube[N-1][N*2-1] = temp;
                break;
            case 5:
            //transpose
                for(int i=0; i<N; i++){
                  for(int j=0; j<N; j++){
                      if(i!=j && i<j){
                          temp = cube[i+N][j+N*3];
                          cube[i+N][j+N*3] = cube[j+N][i+N*3];
                          cube[j+N][i+N*3] = temp;
                      }
                  }
                  
                }
            //reverse
                for(int i=0; i<N; i++){
                  temp = cube[0+N][i+N*3];
                  cube[0+N][i+N*3] = cube[N-1+N][i+N*3];
                  cube[N-1+N][i+N*3] = temp;
                }
            //swap
                for(int j=0; j<N; j++){
                    temp = cube[0][j+N];
                    cube[0][j+N] = cube[j+N][N*3-1];
                    cube[j+N][N*3-1] = temp;
                }
                for(int j=0; j<N; j++){
                    temp = cube[j+N][N*3-1];
                    cube[j+N][N*3-1] = cube[N*3-1][j+N];
                    cube[N*3-1][j+N] = temp;
                }
                for(int j=0; j<N; j++){
                    temp = cube[N*3-1][j+N];
                    cube[N*3-1][j+N] = cube[j+N][0];
                    cube[j+N][0] = temp;
                }
                temp = cube[N][0];
                cube[N][0] = cube[N*2-1][0];
                cube[N*2-1][0] = temp;
                break;
            case 6:
            //transpose
                for(int i=0; i<N; i++){
                  for(int j=0; j<N; j++){
                      if(i!=j && i<j){
                          temp = cube[i+N*2][j+N];
                          cube[i+N*2][j+N] = cube[j+N*2][i+N];
                          cube[j+N*2][i+N] = temp;
                      }
                  }
                  
                }
            //reverse
                for(int i=0; i<N; i++){
                  temp = cube[0+N*2][i+N];
                  cube[0+N*2][i+N] = cube[N-1+N*2][i+N];
                  cube[N-1+N*2][i+N] = temp;
                }
            //swap
                for(int j=0; j<N; j++){
                    temp = cube[N*2-1][j];
                    cube[N*2-1][j] = cube[N*2-1][j+N];
                    cube[N*2-1][j+N] = temp;
                }
                for(int j=0; j<N; j++){
                    temp = cube[N*2-1][j+N];
                    cube[N*2-1][j+N] = cube[N*2-1][j+N*2];
                    cube[N*2-1][j+N*2] = temp;
                }
                for(int j=0; j<N; j++){
                    temp = cube[N*2-1][j+N*2];
                    cube[N*2-1][j+N*2] = cube[N*2-1][j+N*3];
                    cube[N*2-1][j+N*3] = temp;
                }
                break;
            default:
                break;
            
        }
        
    }else{
        switch(colour){
            case 1:
            //reverse
                for(int i=0; i<N; i++){
                  temp = cube[0][i+N];
                  cube[0][i+N] = cube[N-1][i+N];
                  cube[N-1][i+N] = temp;
                }
            //transpose
                for(int i=0; i<N; i++){
                  for(int j=0; j<N; j++){
                      if(i!=j && i<j){
                          temp = cube[i][j+N];
                          cube[i][j+N] = cube[j][i+N];
                          cube[j][i+N] = temp;
                      }
                  }
                }
                break;
            case 2:
                
                for(int i=0; i<N; i++){
                  temp = cube[0+N][i];
                  cube[0+N][i] = cube[N-1+N][i];
                  cube[N-1+N][i] = temp;
                }
                for(int i=0; i<N; i++){
                  for(int j=0; j<N; j++){
                      if(i!=j && i<j){
                          temp = cube[i+N][j];
                          cube[i+N][j] = cube[j+N][i];
                          cube[j+N][i] = temp;
                      }
                  }
                  
                }
                for(int j=0; j<N; j++){
                    temp = cube[j+N][N*4-1];
                    cube[j+N][N*4-1] = cube[j+N*2][N];
                    cube[j+N*2][N] = temp;
                }
                for(int j=0; j<N; j++){
                    temp = cube[j+N*2][N];
                    cube[j+N*2][N] = cube[j+N][N];
                    cube[j+N][N] = temp;
                }
                for(int j=0; j<N; j++){
                    temp = cube[j+N][N];
                    cube[j+N][N] = cube[j][N];
                    cube[j][N] = temp;
                }
                break;
            case 3:
                
                for(int i=0; i<N; i++){
                  temp = cube[0+N][i+N];
                  cube[0+N][i+N] = cube[N-1+N][i+N];
                  cube[N-1+N][i+N] = temp;
                }
                for(int i=0; i<N; i++){
                  for(int j=0; j<N; j++){
                      if(i!=j && i<j){
                          temp = cube[i+N][j+N];
                          cube[i+N][j+N] = cube[j+N][i+N];
                          cube[j+N][i+N] = temp;
                      }
                  }
                  
                }
                break;
            case 4:
                
                for(int i=0; i<N; i++){
                  temp = cube[0+N][i+N*2];
                  cube[0+N][i+N*2] = cube[N-1+N][i+N*2];
                  cube[N-1+N][i+N*2] = temp;
                }
                for(int i=0; i<N; i++){
                  for(int j=0; j<N; j++){
                      if(i!=j && i<j){
                          temp = cube[i+N][j+N*2];
                          cube[i+N][j+N*2] = cube[j+N][i+N*2];
                          cube[j+N][i+N*2] = temp;
                      }
                  }
                  
                }
                break;
            case 5:
                
                for(int i=0; i<N; i++){
                  temp = cube[0+N][i+N*3];
                  cube[0+N][i+N*3] = cube[N-1+N][i+N*3];
                  cube[N-1+N][i+N*3] = temp;
                }
                for(int i=0; i<N; i++){
                  for(int j=0; j<N; j++){
                      if(i!=j && i<j){
                          temp = cube[i+N][j+N*3];
                          cube[i+N][j+N*3] = cube[j+N][i+N*3];
                          cube[j+N][i+N*3] = temp;
                      }
                  }
                  
                }
                break;
            case 6:
                
                for(int i=0; i<N; i++){
                  temp = cube[0+N*2][i+N];
                  cube[0+N*2][i+N] = cube[N-1+N*2][i+N];
                  cube[N-1+N*2][i+N] = temp;
                }
                for(int i=0; i<N; i++){
                  for(int j=0; j<N; j++){
                      if(i!=j && i<j){
                          temp = cube[i+N*2][j+N];
                          cube[i+N*2][j+N] = cube[j+N*2][i+N];
                          cube[j+N*2][i+N] = temp;
                      }
                  }
                  
                }
                break;
            default:
                break;
            
        }
    }
}

int main(){
    loadCube(cube);
    printCube(cube);
    // rotate_cube(1, 0);
    // rotate_cube(2, 0);
    // rotate_cube(3, 0);
    // rotate_cube(4, 0);
    // rotate_cube(5, 0);
    rotate_cube(6, 0);
    // rotate_cube(1, 1);
    // rotate_cube(2, 1);
    // rotate_cube(3, 1);
    // rotate_cube(4, 1);
    // rotate_cube(5, 1);
    // rotate_cube(6, 1);

    printCube(cube);

}



