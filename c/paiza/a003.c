
#include <stdio.h>
#define BLACK 1
#define WHITE 2
#define put(a,b,c) board[a-1][b-1]=c

int board[8][8];

void printTable(){
	printf("%s %d\n",__func__,__LINE__);
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			printf("%2d",board[i][j]);
		}
		printf("\n");
	}
	printf("end %s %d\n",__func__,__LINE__);
}

void boardInit(){
	put(4,4,WHITE);
	put(4,5,BLACK);
	put(5,4,BLACK);
	put(5,5,WHITE);
}

int checkBoard(int col,int row,int color){
	while(board[col--][row]!=color);
	if(board[col][row]==0){
		printf("can't put\n");
	}else if (board[col][row]==color){
		put(col,row,color);
	}

}

int main(){
	int turn;
	char color='B';
	char buf[128];
	int col,row;
	boardInit();
	scanf("%d",&turn);
	printf("turn %d\n",turn);
	for(int i=0;i<turn;i++){
		fscanf(stdin,"%s",buf);
		printf(buf);
		if(color=='B'){
			checkBoard(col,row,BLACK);
		}else if(color=='W'){
			checkBoard(col,row,WHITE);
		}else{
			printf("unknown color\n");
		}
//		printTable();
	}
	return 0;
}
