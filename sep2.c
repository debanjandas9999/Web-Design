#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

    enum colour{
        WHITE,
        BLACK,
        NONE
    };

    typedef struct position{
        int row;
        int col;
    } position;

    typedef struct disk{
        enum colour type;
        position pos;
    } disk;

    typedef struct player{
        char name[20];
        enum colour type;
        int points;
    } player;
    
	
    void initializePlayers(player player1, player player2);

    void initializeBoard(disk board[SIZE][SIZE]);
	

    void printBoard(disk board [SIZE][SIZE]);
	void logic(disk board[SIZE][SIZE], player player1, player player2, enum colour turn);
	
int main()
{
    // Variables declaration

    player player1= {"player1", NONE,0};
    player player2= {"player2", NONE,0};
    disk board[SIZE][SIZE];
    enum colour turn;
    initializePlayers(player1, player2);

    initializeBoard(board);

    printBoard(board);
	
	logic(board,player1,player2,turn);

    //invoke a method that implements the game logic

    //invoke a method that prints the final result

}

void initializePlayers(player player1, player player2){
    int nameSize;
    // Insert player 1
    printf("Player 1 please insert your name:   \n");
    fgets(player1.name, 20, stdin);
    nameSize = strlen(player1.name);
    player1.name[nameSize -1] = '\0';

    // Assign colours and points to player 1
    player1.type = BLACK;
    player1.points = 2;

    // Insert player 2
    printf("Player 2 please insert your name:   \n");
    fgets(player2.name, 20, stdin);
    nameSize = strlen(player2.name);
    player2.name[nameSize -1] = '\0';

    // Assign colours and points to player 2
    player2.type = WHITE;
    player2.points = 2;
	printf("%s plays with the colour BLACK\n",player1.name);
	printf("%s plays with the colour WHITE\n",player2.name);

}

void initializeBoard(disk board [SIZE][SIZE]){
 int i, j;
 //board initialization
    for(i=0; i< SIZE; i++){
        for(j=0;j<SIZE; j++){
            if(i==3){
                if(j==3)
                    board[i][j].type = WHITE;
                else{
                    if(j==4)
                        board[i][j].type = BLACK;
                    else
                        board[i][j].type = NONE;
                    }
                }
            else {
                if(i==4){
                    if(j == 3)
                        board[i][j].type = BLACK;
                    else {
                        if(j == 4)
                        board[i][j].type = WHITE;
                        else
                            board[i][j].type = NONE;
                        }
                    }
                else
                    board[i][j].type = NONE;
            }
            board[i][j].pos.row = i;
            board[i][j].pos.col = j;

            }
        }
    }


void printBoard(disk board[SIZE][SIZE])
{
    int i,j;
    j = 0;

    printf("\n    ");
    for(i=0; i< SIZE; i++){
        printf("%d   ",i+1);
    }
    for(i=0; i< SIZE; i++){
        printf("\n%d | ", i+1);
        for(j=0;j<SIZE; j++){
            switch(board[i][j].type){
                case BLACK:
                    printf("1 | ");
                    break;
                case WHITE:
                    printf("0 | ");
                    break;
                case NONE:
                    printf("x | ");
                    break;
                default:
                    break;
            }
        }
    }

}

void logic(disk board[SIZE][SIZE], player player1, player player2, enum colour turn)
{
	int i,j;
	turn = BLACK;
	int flag =0;
	int flag2=0;
	int x1,x2,y1,y2,x3,x4,y3,y4;
	if(turn == BLACK)
	{
	printf("Player %s choose  your next move\n",player2.name);
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if ((board[i][j].type == WHITE) && (turn == BLACK))
			{
				x1=i-1;
				y1=j;
				x2=i+1;
				y2=j;
				x3=i;
				y3=j-1;
				x4=i;
				y4=j+1;
				
				if((board[x1][y1].type == NONE) && (board[x2][y2].type == BLACK)) 
				{
					flag=1;
					printf("Possible move: ");
					printf("%d, %d  ", x1+1,y1+1);
					
					
				}
			    if((board[x1][y1].type == BLACK) && (board[x2][y2].type == NONE))
				{
					flag =1;
					printf("Possible move: ");
					printf("%d,%d  ",x2+1,y2+1);
					
					
				}
			    if((board[x3][y3].type == NONE) && (board[x4][y4].type == BLACK))
				{
					flag =1;
					printf("Possible move: ");
					printf("%d,%d  ",x3+1,y3+1);
					
				}
				if((board[x3][y3].type == BLACK) && (board[x4][y4].type == NONE))
				{
					flag =1;
					printf("Possible move: ");
					printf("%d,%d  ", x4+1,y4+1);
					
				}
			    
			}
		}
	}
	}
	if(turn == WHITE)
	{
	printf("Player %s choose  your next move\n",player1.name);
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
					
			if ((board[i][j].type == BLACK) && (turn == WHITE))
			{
				x1=i-1;
				y1=j;
				x2=i+1;
				y2=j;
				x3=i;
				y3=j-1;
				x4=i;
				y4=j+1;
				
			    if((board[x1][y1].type == NONE) && (board[x2][y2].type == WHITE)) 
				{
					flag2 = 1;
					printf("Possible move:");
					printf("%d,%d  ", x1+1,y1+1);
					
					
				}
			    if((board[x1][y1].type == WHITE) && (board[x2][y2].type == NONE))
				{
					flag2 = 1;
					printf("Possible move");
					printf("%d,%d  ", x2+1,y2+1);
					
					
				}
			    if((board[x3][y3].type == NONE) && (board[x4][y4].type == WHITE))
				{
					flag2 =1;
					printf("Possible move: ");
					printf("%d,%d  ", x3+1,y3+1);
					
				}
				if((board[x3][y3].type == WHITE) && (board[x4][y4].type == NONE))
				{
					flag2 =1;
					printf("Possible move: ");
					printf("%d,%d  ", x4+1,y4+1);
					
				}
				
			
			}
				
		}
	}
	}
}
	
	
	
		
	
				
				

				
					
							
					
					
		
