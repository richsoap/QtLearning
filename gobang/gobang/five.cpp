#include <string.h>
#include <stdio.h>
#include <QDebug>
#include "five.h"

five::five() {
	field =  new int*[17];
	for(int i = 0;i < 17;i ++) {
		field[i] = new int[17];
	}
}

five::~five() {
	for(int i = 0;i < 17;i ++) {
		delete field[i];
	}
	delete field;
}


void five::init(int kind = 0) {
	for(int i = 0;i < 17;i ++) {
		memset(field[i],0,sizeof(int)*17);
	}
	switch(kind) {
		case 1:
		for(int i = 0;i < 5;i ++) {
			field[i + 4][i + 4] = black;
		}
		break;
		case 2:
		for(int i = 0;i < 5;i ++) {
			field[i+5][5] = white;
		}
		break;
		case 3:
		for(int i = 0;i < 5;i ++) {
			for(int p = 0;p < 6;p ++) {
				field[i+4][p+2] = (i+p)%2+1;
			}
		}
		field[8][6] = 2;
		field[8][7] = 1;
		break;
	}	
}


bool five::addPiece(int x,int y,int color) {
	if(x > 14 || x < 0 || y > 14 || y < 0) {
		return false;
	}
	else if(field[x+1][y+1] == 0){
		field[x+1][y+1] = color;
		return true;
	}
	else {
		return false;
	}
}
void five::removePiece(int x, int y) {
    if(x > 14 || x < 0 || y > 14 || y < 0) {
    }
    else if(field[x+1][y+1] != 0) {
        field[x+1][y+1] = 0;
    }
}

bool five::whoWin(int *result) {
	int flag = 0;
	for(int i = 0;i < 4;i ++) {
		for(int p = 1;p < 16;p ++) {
			for(int q = 1;q < 16;q ++) {
				flag = 1;
				for(int x = 1;x < 5 && flag == 1;x ++) {
					if(field[p][q] != field[p + x*dx[i]][q + x*dy[i]] || field[p][q] == 0) {
						flag = 0;
					}
				}
				if(flag == 1) {
					result[0] = field[p][q];
                    result[1] = p-1;
                    result[2] = q-1;
                    result[3] = p-1+4*dx[i];
                    result[4] = q-1+4*dy[i];
					return true;
				}
			}
		}
	}
	return false;
}

bool five::issame(int x,int y,int dir,int level,int ** table) {
	if(level >= 5) {
		return true;
	}
	if(table[x][y] == table[x + dx[dir]][y + dy[dir]]) {
		if(issame(x+dx[dir],y+dy[dir],dir,level+1,table)) {
			return true;
		}
		else {
			table[x][y] = 0;
			table[x + dx[dir]][y + dy[dir]] = 0;
			return false;
		}
	}
	else {
		return false;
	}
}

void five::printtable() {
	for(int p = 1;p < 16;p ++) {
		for(int q = 1;q < 16;q ++) {
			printf("%d",field[p][q]);
		}
		printf("\n");
	}
}
