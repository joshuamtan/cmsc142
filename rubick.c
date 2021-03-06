
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#define N 3
#define L 12

int indexCol[6] = {4,4,7,10,4,1};
int indexRow[6] = {1,4,4,4,7,4};

int cube[9][4*N] = {};
int copy[N*3][N*4] = {};

int checkSolved(int cube[N*3][N*4]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(cube[i][j+N] != 1){
                return 0;
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(cube[i+N][j] != 2){
                return 0;
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(cube[i+N][j+N] != 3){
                return 0;
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(cube[i+N][j+N*2] != 4){
                return 0;
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(cube[i+N][j+N*3] != 5){
                return 0;
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(cube[i+N*2][j+N] != 6){
                return 0;
            }
        }
    }
    return 1;
}
void rotate_cube(int colour, int direction, int cube[N*3][N*4]){
    int temp;
    int tempArray[N] = {};
    if(direction == 0){ //cc
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
                      cube[N][j+N] = cube[N][j];
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
                temp = cube[N][N*4-1];
                cube[N][N*4-1] = cube[N*2-1][N*4-1];
                cube[N*2-1][N*4-1] = temp;

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
                    cube[0][j+N] = cube[j+N][0];
                    cube[j+N][0] = temp;
                }
                for(int j=0; j<N; j++){
                    temp = cube[j+N][0];
                    cube[j+N][0] = cube[N*3-1][j+N];
                    cube[N*3-1][j+N] = temp;
                }
                for(int j=0; j<N; j++){
                    temp = cube[N*3-1][j+N];
                    cube[N*3-1][j+N] = cube[j+N][N*3-1];
                    cube[j+N][N*3-1] = temp;
                }
                temp = cube[N*3-1][N];
                cube[N*3-1][N] = cube[N*3-1][N*2-1];
                cube[N*3-1][N*2-1] = temp;

                temp = cube[0][N];
                cube[0][N] = cube[0][N*2-1];
                cube[0][N*2-1] = temp;

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
                
                for(int j=0; j<N; j++){
                      tempArray[j] = cube[N][j];
                  }
                  for(int j=0; j<N*4; j++){
                      cube[N][j] = cube[N][j+N];
                  }
                  for(int j=0; j<N; j++){
                      cube[N][j+N*3] = tempArray[j];
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
                temp = cube[N][N*4-1];
                cube[N][N*4-1] = cube[N*2-1][N*4-1];
                cube[N*2-1][N*4-1] = temp;

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
                for(int j=0; j<N; j++){
                    temp = cube[j][N];
                    cube[j][N] = cube[j+N][N*4-1];
                    cube[j+N][N*4-1] = temp;
                }
                break;
            case 3:
            //reverse
                for(int i=0; i<N; i++){
                  temp = cube[0+N][i+N];
                  cube[0+N][i+N] = cube[N-1+N][i+N];
                  cube[N-1+N][i+N] = temp;
                }
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
            //swap

                for(int j=0; j<N; j++){
                    temp = cube[N-1][j+N];
                    cube[N-1][j+N] = cube[j+N][N-1];
                    cube[j+N][N-1] = temp;
                }
                temp = cube[N-1][N];
                cube[N-1][N] = cube[N-1][N*2-1];
                cube[N-1][N*2-1] = temp;
                for(int j=0; j<N; j++){
                    temp = cube[j+N][N-1];
                    cube[j+N][N-1] = cube[N*2][j+N];
                    cube[N*2][j+N] = temp;
                }
                
                for(int j=0; j<N; j++){
                    temp = cube[N*2][j+N];
                    cube[N*2][j+N] = cube[j+N][N*2];
                    cube[j+N][N*2] = temp;
                }
                temp = cube[N*2][N];
                cube[N*2][N] = cube[N*2][N*2-1];
                cube[N*2][N*2-1] = temp;

                break;
            case 4:
            //reverse
                for(int i=0; i<N; i++){
                  temp = cube[0+N][i+N*2];
                  cube[0+N][i+N*2] = cube[N-1+N][i+N*2];
                  cube[N-1+N][i+N*2] = temp;
                }
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
            //swap
                for(int j=0; j<N; j++){
                    temp = cube[j+N][N*3];
                    cube[j+N][N*3] = cube[j][N*2-1];
                    cube[j][N*2-1] = temp;
                }
                for(int j=0; j<N; j++){
                    temp = cube[j][N*2-1];
                    cube[j][N*2-1] = cube[j+N][N*2-1];
                    cube[j+N][N*2-1] = temp;
                }
                for(int j=0; j<N; j++){
                    temp = cube[j+N][N*2-1];
                    cube[j+N][N*2-1] = cube[j+N*2][N*2-1];
                    cube[j+N*2][N*2-1] = temp;
                }
                
                temp = cube[N][N*3];
                cube[N][N*3] = cube[N*2-1][N*3];
                cube[N*2-1][N*3] = temp;
                break;
            case 5:
            //reverse
                for(int i=0; i<N; i++){
                  temp = cube[0+N][i+N*3];
                  cube[0+N][i+N*3] = cube[N-1+N][i+N*3];
                  cube[N-1+N][i+N*3] = temp;
                }
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
            //swap
                temp = cube[N*3-1][N];
                cube[N*3-1][N] = cube[N*3-1][N*2-1];
                cube[N*3-1][N*2-1] = temp;

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
            //reverse
                for(int i=0; i<N; i++){
                  temp = cube[0+N*2][i+N];
                  cube[0+N*2][i+N] = cube[N-1+N*2][i+N];
                  cube[N-1+N*2][i+N] = temp;
                }
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
            //swap
                for(int j=0; j<N; j++){
                      tempArray[j] = cube[N*2-1][j+N*3];
                  }
                  for(int j=N*3-1; j>=0; j--){
                      cube[N*2-1][j+N] = cube[N*2-1][j];
                  }
                  for(int j=0; j<N; j++){
                      cube[N*2-1][j] = tempArray[j];
                  }
                break;
            default:
                break;
            
        }
    }
}

void applyRotation(int rotate, int c[N*3][N*4]){
    switch(rotate){
        case 1:
            rotate_cube(1,0,c);
            break;
        case 2:
            rotate_cube(2,0,c);
            break;
        case 3:
            rotate_cube(3,0,c);
            break;
        case 4:
            rotate_cube(4,0,c);
            break;
        case 5:
            rotate_cube(5,0,c);
            break;
        case 6:
            rotate_cube(6,0,c);
            break;
        case 7:
            rotate_cube(1,1,c);
            break;
        case 8:
            rotate_cube(2,1,c);
            break;
        case 9:
            rotate_cube(3,1,c);
            break;
        case 10:
            rotate_cube(4,1,c);
            break;
        case 11:
            rotate_cube(5,1,c);
            break;
        case 12:
            rotate_cube(6,1,c);
            break;
        default:
            break;
    }
}

void printSolution(int rotate){
    switch(rotate){
        case 1:
            printf("W, Counter Clockwise");
            break;
        case 2:
            printf("R, Counter Clockwise");
            break;
        case 3:
            printf("B, Counter Clockwise");
            break;
        case 4:
            printf("O, Counter Clockwise");
            break;
        case 5:
            printf("G, Counter Clockwise");
            break;
        case 6:
            printf("Y, Counter Clockwise");
            break;
        case 7:
            printf("W, Clockwise");
            break;
        case 8:
            printf("R, Clockwise");
            break;
        case 9:
            printf("B, Clockwise");
            break;
        case 10:
            printf("O, Clockwise");
            break;
        case 11:
            printf("G, Clockwise");
            break;
        case 12:
            printf("Y, Clockwise");
            break;
        default:
            break;
    }
}



void solveCube(){
	int start, move;
	int nopts[L+2]; //array top of stacks
	int option[L+2][L+2]; //array stacks of options
	int i, candidate;

	move = start = 0; 
	nopts[start]= 1;
	
	while (nopts[start] >0)
	{
		if(nopts[move]>0)
		{
			move++;
			nopts[move]=0; //initialize new move

            for(i = 0; i< N*3; i++){
                for(int j = 0; j<N*4; j++){
                    copy[i][j] = cube[i][j];
                }
            }

            

            for(i=1;i<move;i++){
                if(nopts[i] == nopts[i+1] && nopts[i+1] == nopts[i+2] && nopts[i+2] == nopts[i+3]){
                    break;
                }else if(abs(nopts[i] - nopts[i+1]) == 6){
                    break;
                }else{
                    // printf("%2i", option[i][nopts[i]]);
                    applyRotation(option[i][nopts[i]], copy);
                }
            }
            
            // printf("\n");
            
            // for(i=1;i<move;i++)
			// 	applyRotation(option[i][nopts[i]], copy);
                
			if(checkSolved(copy) == 1){
                printf("Solution: \n");
                for(i=1;i<move;i++){
                    printSolution(option[i][nopts[i]]);
                    printf("\n");
                }
                printf("\n");
                
                
			}else if(move == 11){

            }else{
                for(candidate = L; candidate >=1; candidate --) 
                    {
                        nopts[move]++;
                        option[move][nopts[move]] = candidate;
                    } 
            
            }
		}
		else 
		{
			//backtrack
			move--;
			nopts[move]--;
		}
	}

}


int main(){
    loadCube(cube);
    printCube(cube);
    solveCube();

    // printCube(cube);
}



