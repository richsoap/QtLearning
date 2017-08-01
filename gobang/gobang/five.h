#ifndef FIVE_H
#define FIVE_H

	const static int dx[4] = {0,1,1,-1};
	const static int dy[4] = {1,0,1,1};
class five {
private:
	int** field;
public:
	const static int black = 2;
	const static int white = 1;
	five();
	~five();
	void init(int kind);
	bool chess(int x,int y,int color);
	bool whoWin(int* result);
	bool issame(int x,int y,int dir,int level,int **table);
	void printtable();
};

#endif
