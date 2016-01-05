/**
 * Created by Kenan Polat on 04.01.2016
 */

/******************************************************************************
 *  Compilation:  gcc main.c -o first
 *  Execution:    ./first
 *
 *  Input  x,y coordinate:   (1,4)
 *                           (2,1)
 *                           (2,5)
 *                           (3,2)
 *                           (3,4)
 *                           (4,1)
 *                           (5,2)
 *                           (5,4) 
 *   
 *   Input starting point:   (1,1)
 *   Input endind point  :   (1,5)
 *
 *
 *       -------------------------------
 *   
 *    +  -  +  -  +  -  + 
 *    |  *  |        X  | 
 *    +     +  -  +     + 
 *    |                 | 
 *    +     +  -  +  -  + 
 *    |                 | 
 *    +  -  +  -  +  -  + 
 *   
 *   -------------------------------
 *   Step Sequence: 0
 *   Iteration Number: 0
 *   
 *   
 *   -------------------------------
 *   
 *    +  -  +  -  +  -  + 
 *    |  *  |        X  | 
 *    +     +  -  +     + 
 *    |  I              | 
 *    +     +  -  +  -  + 
 *    |                 | 
 *    +  -  +  -  +  -  + 
 *   
 *   -------------------------------
 *   Step Sequence: 1
 *  Iteration Number: 1
 *   
 *   
 *   -------------------------------
 *   
 *    +  -  +  -  +  -  + 
 *    |  *  |        X  | 
 *    +     +  -  +     + 
 *    |  I              | 
 *    +     +  -  +  -  + 
 *    |  I              | 
 *    +  -  +  -  +  -  + 
 *   
 *   -------------------------------
 *   Step Sequence: 2
 *   Iteration Number: 2
 *   
 *   
 *   -------------------------------
 *   
 *    +  -  +  -  +  -  + 
 *    |  *  |        X  | 
 *    +     +  -  +     + 
 *    |  I              | 
 *    +     +  -  +  -  + 
 *    |  I     I        | 
 *    +  -  +  -  +  -  + 
 *   
 *   -------------------------------
 *   Step Sequence: 3
 *   Iteration Number: 3
 *   
 *   
 *   -------------------------------
 *   
 *    +  -  +  -  +  -  + 
 *    |  *  |        X  | 
 *    +     +  -  +     + 
 *    |  I              | 
 *    +     +  -  +  -  + 
 *    |  I     I     I  | 
 *    +  -  +  -  +  -  + 
 *   
 *   -------------------------------
 *   Step Sequence: 4
 *   Iteration Number: 4
 *   
 *   
 *        Backtracking    
 *   
 *   
 *   -------------------------------
 *   
 *    |  *  |        X  | 
 *    +     +  -  +     + 
 *    |  I              | 
 *    +     +  -  +  -  + 
 *    |                 | 
 *    +  -  +  -  +  -  + 
 *   
 *   -------------------------------
 *   Step Sequence: 1
 *   Iteration Number: 5
 *   
 *   
 *   -------------------------------
 *   
 *    +  -  +  -  +  -  + 
 *    |  *  |        X  | 
 *    +     +  -  +     + 
 *    |  I     I        | 
 *    +     +  -  +  -  + 
 *    |                 | 
 *    +  -  +  -  +  -  + 
 *   
 *   -------------------------------
 *   Step Sequence: 2
 *   Iteration Number: 6
 *   
 *   
 *   -------------------------------
 *   
 *    +  -  +  -  +  -  + 
 *    |  *  |        X  | 
 *    +     +  -  +     + 
 *    |  I     I     I  | 
 *    +     +  -  +  -  + 
 *    |                 | 
 *    +  -  +  -  +  -  + 
 *   
 *   -------------------------------
 *   Step Sequence: 3
 *   Iteration Number: 7
 *   
 *   
 *   -------------------------------
 *   
 *    +  -  +  -  +  -  + 
 *    |  *  |        X  | 
 *    +     +  -  +     + 
 *    |  I     I     I  | 
 *    +     +  -  +  -  + 
 *    |                 | 
 *    +  -  +  -  +  -  + 
 *   
 *   -------------------------------
 *   
 *   Step Sequence: 4
 *   Iteration Number: 8
 *   
 *                        
 *      TARGET REACHED!   
 *  
 *
 *  
 *
 *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define H 7  // height of labyrinth - only odd
#define W 7  // width of labyrinth - only odd

// for display labyrinth
#define CORNER " + "
#define START " * "
#define END " X "
#define TRACE " I "
#define WALLH " | "
#define WALLW " - "
#define PATH "   "

//  Escape coloring
#define ESC "\x1b[0m"

//  formatting colours
#define RESET "\x1b[0m"
#define BRIGHT "\x1b[1m"
#define DIM "\x1b[2m"
#define UNDRSCR "\x1b[4m"
#define BLINK "\x1b[5m"
#define REVERSE "\x1b[7m"
#define HIDDEN "\x1b[8m"

//  foreground colours
#define BLACKF "\x1b[30m"
#define REDF "\x1b[31m"
#define GREENF "\x1b[32m"
#define YELLOWF "\x1b[33m"
#define BLUEF "\x1b[34m"
#define MAGENTAF "\x1b[35m"
#define CYANF "\x1b[36m"
#define WHITEF "\x1b[37m"

//  background colours
#define BLACKB "\x1b[40m"
#define REDB "\x1b[41m"
#define GREENB "\x1b[42m"
#define YELLOWB "\x1b[43m"
#define BLUEB "\x1b[44m"
#define MAGENTAB "\x1b[45m"
#define CYANB "\x1b[46m"
#define WHITEB "\x1b[47m"

// line break
#define nwl printf("\n\t");
// Clear Screen
#define clr printf("\e[1;1H\e[2J");


int stack[2][W/2*H/2];       //  DepthFirstSearch Algorithm stack building
int visit[2][W/2*H/2];       //  DepthFirstSearch Algorithm visited building
int turnOut[W/2*H/2] = {0};  //  holds the crossroads of the labyrinth
int labyrinth[H][W];         //  Matrix of labyrinth
int stackCount = -1;         //  Initial of the Stack-pointer
int visitCount = -1;         //  Initial of the Visit-pointer


//  Assigns incoming coordinates stack
void pushStack(int pointX, int pointY) {
    stackCount++;
    stack[0][stackCount] = pointX;
    stack[1][stackCount] = pointY;
}

//  pulls stack coordinates.
int popStack() {
    int temp;
    if( stackCount < 0)
        return stackCount;
    temp = stackCount;
    stackCount--;
    return temp;
}

//  visited or unvisited node
int notVisited(int pointX, int pointY) {
    int i;
    for(i=0; i<=visitCount; i++){
        if((visit[0][i] == pointX) && (visit[1][i] == pointY)) { return 0; }
    }
    return 1;
}

// Formatting labyrinth display screen
void print_labyrinth(int startX, int startY, int endX, int endY) {
    int i,j;
    nwl
    printf("\n");
    printf(YELLOWF"----------------------------------------------------"ESC); nwl nwl
    for(i=0;i<H;i++) {
        for(j=0;j<W;j++) {
            if((i*j)%2 == 1) {
                if((i == startX) && (j == startY)) { printf(BLUEF START ESC); }
                else { if((i == endX) && (j == endY)) { printf(GREENF END ESC); } else {  if( notVisited(i,j)) { printf(PATH); } else { printf(REDF TRACE ESC); } } }
            }
            if((i%2 == 0) && (j%2 == 1)) {
                if(labyrinth[i][j] == 1) { if(!((i == endX) && (j == endY))) printf(PATH); } else { printf(WALLW); }
            }
            if((i%2 == 1) && (j%2 == 0)) {
                if(labyrinth[i][j] == 1) { if(!((i == startX) && (j == startY))) printf(PATH); } else { printf(WALLH); }
            }
            if((i%2 == 0) && (j%2 == 0)) { printf(CORNER); }
        }
        nwl
    }
    printf("\n");
    printf(YELLOWF"----------------------------------------------------"ESC); nwl
}

int main()
{
    int i, j, check, x, y, temp, checkSum,iteration=0;
    int startX, startY, stopX, stopY, pointX, pointY;
    int adjacent[2][4] = {{0, 1, 0, -1},
                          {1, 0, -1, 0}};    // Node's Four neighbors' index

// Binary Labyrint structure ---  1 - Path ;  2 - Wall
    for(i=0;i<H;i++) {
        for(j=0;j<W;j++) {
            if((i*j)%2 == 1) {
                labyrinth[i][j] = 1;
            } else {
                labyrinth[i][j] = 0;
            }
        }
    }
    nwl nwl
    printf(CYANB WHITEF BRIGHT"  Initial Labyrinth  "ESC); nwl
    print_labyrinth(-1, -1, -1, -1);
    // take a Path coordinates from user
    check = 1;   //  Leave condition
    while (check) {
        nwl
        printf("Enter the coordinates of the road:"); nwl
        scanf("%d",&x); printf("\t");
        scanf("%d",&y);
        if((x == 0) && (y == 0)) {
            check = 0;
        } else {
            labyrinth[x][y] = 1;
        }
    }
    nwl nwl nwl
    printf(CYANB WHITEF BRIGHT"  Created Labyrinth  "ESC); nwl
    print_labyrinth(-1, -1, -1, -1);
    nwl
    //  take a start and end point of labyrinth solution
    printf("Enter the coordinates of the starting point"); nwl
    scanf("%d",&startX); printf("\t");
    scanf("%d",&startY); nwl
    printf("Enter the coordinates of the ending point"); nwl
    scanf("%d",&stopX); printf("\t");
    scanf("%d",&stopY);
    nwl nwl nwl
    printf(CYANB WHITEF BRIGHT BLINK"     Let's Start     "ESC); nwl

    pointX = startX;    // temporary variable for start point x coordinate
    pointY = startY;    // temporary variable for start point y coordinate

    // logic part of Depth First Search Algorith

    check = 1;          //  leave condition
    while(((pointX != stopX) || (pointY != stopY)) && (check)) {

        //is a visible
        visitCount++;
        visit[0][visitCount] = pointX;
        visit[1][visitCount] = pointY;
        print_labyrinth(startX,startY,stopX,stopY);
        printf("Step Sequence: %d",visitCount); nwl
        printf("Iteration Number: %d",iteration); nwl nwl
        iteration++;

        // send stack for matching neighbors
        checkSum = 0;
        for(i=0; i<4; i++) {
            x = pointX + adjacent[0][i];
            y = pointY + adjacent[1][i];
            if(labyrinth[x][y] == 1) {

                x += adjacent[0][i];
                y += adjacent[1][i];
                if(notVisited(x, y) == 1 ) {
                    pushStack(x, y);
                    checkSum++;
                }
            }
        }

        // crossroads of the labyrinth point
        if(checkSum > 1) {
            turnOut[visitCount] = checkSum-1;
        }

        //  Returning to the temporary dead-end road
        if(checkSum == 0) {
            nwl
            j = visitCount;
            while(turnOut[j] == 0) { j--; }
            visitCount = j;
            turnOut[visitCount]-- ;
            if(j > 0) {
                nwl
                printf(CYANB WHITEF BRIGHT"     Backtracking    "ESC); nwl
                nwl
                print_labyrinth(startX,startY,stopX,stopY);
                printf("Step Sequence: %d",visitCount); nwl
                printf("Iteration Number: %d",iteration); nwl
                iteration++;
            }
        }

        //  End of Game!!! either to continue or you will die
        temp = popStack();
        if( temp < 0) {
            nwl
            printf(REDB"                     "ESC); nwl
            printf(WHITEB REDF BRIGHT BLINK "      DEAD END!      "ESC); nwl
            printf(REDB"                     "ESC); nwl nwl nwl
            check = 0;
            exit(-1);
        } else {
            pointX = stack[0][temp];
            pointY = stack[1][temp];
        }
    }

    nwl
    print_labyrinth(startX,startY,stopX,stopY); nwl
    visitCount++;
    printf("Step Sequence: %d",visitCount); nwl
    printf("Iteration Number: %d",iteration); nwl nwl
    printf(WHITEB"                     "ESC); nwl nwl
    printf(CYANB WHITEF BRIGHT BLINK "   TARGET REACHED!   "ESC); nwl
    printf(WHITEB"                     "ESC); nwl nwl nwl

    return 0;
}
