void printCube(int cube[9][12]){
    int i, j;
    for(i=0; i<9; i++){
        for(j=0; j<12; j++){
            printf("%2d ", cube[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int getColor(char color){
    if(color == 'W') return 1;
    else if(color == 'R') return 2;
    else if(color == 'B') return 3;
    else if(color == 'O') return 4;
    else if(color == 'G') return 5;
    else if(color == 'Y') return 6;
}

void setFace(FILE * fp, int startX, int startY, int cube[9][12]){
    int i, j;
    char a, b, c;

    for(i=startX; i<startX+3; i++){
        fscanf(fp, "%c%c%c\n", &a, &b, &c);
        cube[i][startY] = getColor(a);
        cube[i][startY+1] = getColor(b);
        cube[i][startY+2] = getColor(c);  
    }
}


void loadCube(int cube[9][12]){
    int startX, startY, i, j;
    FILE * fp = fopen("cube.in", "r");

    setFace(fp, 0, 3, cube); //White
    setFace(fp, 3, 0, cube); //Red
    setFace(fp, 3, 3, cube); //Blue
    setFace(fp, 3, 6, cube); //Orange
    setFace(fp, 3, 9, cube); //Green
    setFace(fp, 6, 3, cube); //Yellow
    fclose(fp);

}

