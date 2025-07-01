#include "iGraphics.h"

void drawmaze(int maze[17][17]);
int find (int l,int x);
void pacmove();
void packy();
void intoch(int);
void playmenu (void);
void ghost();
int eat ();
void finish();
void showscore();
void ghostrun ();
void ghostrun1 ();
void ghostrun2 ();
void ghostrun3 ();
void reset();

const int MAX_NAME_LENGTH=50;
typedef struct PlayerScore {
    char name[MAX_NAME_LENGTH];
    int score;
} PlayerScore;

FILE *fp;

int maze[5][17][17]={
	1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,
	1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,
	1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,
	1,0,1,0,0,0,0,0,0,0,0,0,0,3,1,0,1,
	1,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,
	1,0,0,0,1,3,0,0,0,0,0,0,1,0,0,0,1,
	1,0,1,0,1,0,1,0,0,1,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,
	0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,
	1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,1,0,0,1,0,1,0,1,0,1,
	1,0,0,0,1,0,0,0,0,0,0,3,1,0,0,0,1,
	1,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,
	1,0,1,3,0,0,0,0,0,0,0,0,0,0,1,0,1,
	1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,
	1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,
	1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,
	
	1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,
	1,3,0,0,0,0,0,1,0,1,0,0,0,0,0,3,1,
	1,0,1,1,1,1,0,1,0,1,0,1,1,1,1,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,1,0,1,1,0,1,1,1,0,1,1,0,1,0,1,
	1,0,1,0,1,1,0,0,0,0,0,1,1,0,1,0,1,
	1,0,1,0,1,1,0,1,0,1,0,1,1,0,1,0,1,
	1,0,1,0,1,1,0,1,0,1,0,1,1,0,1,0,1,
	0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
	1,0,1,0,1,1,0,1,0,1,0,1,1,0,1,0,1,
	1,0,1,0,1,1,0,1,0,1,0,1,1,0,1,0,1,
	1,0,1,0,1,1,0,0,0,0,0,1,1,0,1,0,1,
	1,0,1,0,1,1,0,1,1,1,0,1,1,0,1,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,1,1,1,1,0,1,0,1,0,1,1,1,1,0,1,
	1,3,0,0,0,0,0,1,0,1,0,0,0,0,0,3,1,
	1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,

	1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,
	1,0,0,3,0,0,0,0,0,1,3,0,0,0,1,3,1,
	1,0,1,0,1,1,1,1,0,1,0,1,1,0,1,0,1,
	1,0,1,0,1,1,1,1,0,1,0,1,1,0,1,0,1,
	1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,
	1,0,1,0,1,1,0,1,0,1,0,1,1,0,1,0,1,
	1,0,1,0,1,1,0,1,0,1,0,1,1,0,1,0,1,
	1,0,1,0,1,1,0,1,0,1,0,1,1,0,1,0,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	1,0,1,0,1,1,0,1,0,1,0,1,1,0,1,0,1,
	1,0,1,0,1,1,0,1,0,1,0,1,1,0,1,0,1,
	1,0,1,0,1,1,0,1,0,1,0,1,1,0,1,0,1,
	1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,
	1,0,1,0,1,1,1,1,0,1,0,1,1,0,1,0,1,
	1,0,1,0,1,1,1,1,0,1,0,1,1,0,1,0,1,
	1,0,0,3,0,0,0,0,0,1,3,0,0,0,1,3,1,
	1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1 
};

// PlayerScore highscore[7];
// char currentPlayerName[MAX_NAME_LENGTH];
// int nameIndex = 0;

int level=0,life=3,p=32,a,b,c,i,j,sx=1,sy=1, flag1=0,run=0,highscore[20];
int pr = 1, pc = 1, move = 0,status=1, pause = 0;
int total=0,gr=8,gc=8,grun=0,gr1=8,gc1=8,grun1=1,gr2=8,gc2=8,grun2=2,gr3=8,gc3=8,grun3=3;
char hscore[20],score[20];
clock_t t1,t2,tim;

Image frames[2];
Image ghostsss[2];
Image block[2];

void loadResources() {
	iLoadImage(frames, "assets/images/sprites/Pacman/Pac_rgt.bmp");
	iLoadImage(frames, "assets/images/sprites/Pacman/Pac_lft.bmp");
	iLoadImage(frames, "assets/images/sprites/Pacman/Pac_upp.bmp");
	iLoadImage(frames, "assets/images/sprites/Pacman/Pac_dwn.bmp");
	iLoadImage(frames, "assets/images/sprites/Pacman/Pac_rgt_2.bmp");
	iLoadImage(frames, "assets/images/sprites/Pacman/Pac_lft_2.bmp");
	iLoadImage(frames, "assets/images/sprites/Pacman/Pac_upp_2.bmp");
	iLoadImage(frames, "assets/images/sprites/Pacman/Pac_dwn_2.bmp");
	iLoadImage(ghostsss, "assets/images/sprites/Pacman/ghost.bmp");
	iLoadImage(block, "assets/images/sprites/blocks/block9.bmp");
}

void iAnim()
{
	// iAnimateSprite(&sprite);
}

/*
function iDraw() is called again and again by the system.
*/
void iDraw()
{
	t2=clock();
	
	tim = (t2-t1)/CLOCKS_PER_SEC;		//time record

	if (run==0)		//start
	{
		iClear();
		iShowImage(0,0,"assets/images/start.bmp");
	}
	else if (run==1)		//menu
	{	
		iClear();
		iShowImage(200,20,"assets/images/menu.bmp");
	}
	else if (run==2)		//game start
	{
		iClear();
		if (level==0)	iShowImage(274,82,"assets/images/level1.bmp");
		else if (level==1)	iShowImage(274,82,"assets/images/level2.bmp");
		else if (level==2)	iShowImage(274,82,"assets/images/level3.bmp");
	}
	else if (run==3)		//play game
	{
		iClear();
		
		if (( find(level,0)==0)&&( find(level,3)==0)) {
			level++;		//level changing
	
			gr=gc=gr1=gc1=gr2=gc2=gr3=gc3=8;

			run=2;
			iDelay (1);
			pr =pc = 1;
			move = 0, status = 1;
		}
		drawmaze(maze[level]);
		playmenu ();
		
		pacmove();
		eat ();
		finish();

		if((tim%2)==0)	iShowImage(gr*32+sx,gc*32+sy,"assets/images/blinky.bmp");
		else iShowImage(gr*32+sx,gc*32+sy,"assets/images/blinky_2.bmp");
		if((tim%2)==0)	iShowImage(gr1*32+sx,gc1*32+sy,"assets/images/clyde.bmp");
		else iShowImage(gr1*32+sx,gc1*32+sy,"assets/images/clyde_2.bmp");
		if((tim%2)==0)	iShowImage(gr2*32+sx,gc2*32+sy,"assets/images/pinky.bmp");
		else iShowImage(gr2*32+sx,gc2*32+sy,"assets/images/pinky_2.bmp");
		if((tim%2)==0)	iShowImage(gr3*32+sx,gc3*32+sy,"assets/images/inky.bmp");
		else iShowImage(gr3*32+sx,gc3*32+sy,"assets/images/inky_2.bmp");
	}
	else if (run==4)		//choose level
	{
		iClear();
		iShowImage(274,72,"assets/images/chooselevel.bmp");
	}
	else if (run==10){		//showhighscore
		iClear();
		iShowImage(274,82,"assets/images/savedscores.bmp");
		showscore();
	}
	else if (run==5){		//show current score
		iClear();
		if (total>highscore[6]){
			iShowImage(274,82,"assets/images/high.bmp");
			iText(481,293,score,GLUT_BITMAP_TIMES_ROMAN_24);
			iDelay(1);
			total=0;
		}
		else{
			iShowImage(274,82,"assets/images/high_2.bmp");
			iText(481,293,score,GLUT_BITMAP_TIMES_ROMAN_24);
			iDelay(1);
			total=0;
		}
	}
	else if (run==7){		//help
		iClear();
		iShowImage(125,82,"assets/images/help.bmp");
	}
}

void playmenu (void)	//shows score ,level,life
{
	iShowImage(720,505,"assets/images/pacman_run.bmp");
	iShowImage(700,20,"assets/images/score.bmp");
	iSetColor(40,240,120);
	intoch(highscore[0]);
	strcpy(hscore, score);
	iText(859,176,score,GLUT_BITMAP_TIMES_ROMAN_24);
	intoch(total);
	iText(859,283,score,GLUT_BITMAP_TIMES_ROMAN_24);
	for (i=0;i<life;i++)
		iShowImage(830+i*40,100,"assets/images/life.bmp");
	if (level==0)	iShowImage(842,344,"assets/images/lev1.bmp");
	else if (level==1)	iShowImage(842,344,"assets/images/lev2.bmp");
	else if (level==2)	iShowImage(842,344,"assets/images/lev3.bmp");
}

void randomize ()
{	
	int i, j, k;
	for ( i = 0; i < 4; i++ )	
		for ( j = 0; j < 17; j++ )	
			for ( k = 0; k < 17; k++ )	
				if ( maze[i][j][k] == 1 || maze[i][j][k] >= 7 )	
					maze[i][j][k] = rand()%3+7;
				
			
}

int find (int l,int x)
{
	int i, j, count=0;
	for ( i = 0; i < 17; i++ )	
		for ( j = 0; j < 17; j++ )
			if ( maze[l][i][j] == x )	count++;

	return(count);
				
}

void ghostrun ()
{
	if (run!=3) return;
	int px=gr,py=gc;
	switch(grun){
	case 0:
		px++;
		if ( maze[level][px][py] >= 7 ){
			px--;
			grun=(rand()%4);

		}
		if (px>=16) grun=1; 
		break;
	case 1:
		px--;
		if ( maze[level][px][py] >= 7 ){
			px++;
			grun=(rand()%4);

		}
		if (px<=0) grun=0;
		break;
	case 2:
		py++;
		if ( maze[level][px][py] >= 7 ){
			py--;
			grun=(rand()%4);

		}
		if (py>=16) grun=3;
		break;
	case 3:
		py--;
		if ( maze[level][px][py] >= 7 ){
			py++;
			grun=(rand()%4);

		}

		if (py<=0) grun=2;
		break;
	}
	if (px==pr){
		if (py<pc) grun=2;
		else grun=3;
	}
	
	if (py==pc){
		if (px<pr) grun=0;
		else grun=1;
	}
	gr=px;
	gc=py;
}

void ghostrun1 ()
{
	if (run!=3) return;
	int px=gr1,py=gc1;
	switch(grun1){
	case 0:
		px++;
		if ( maze[level][px][py] >= 7 ){
			px--;
			grun1=(rand()%4);

		}
		if (px>=16) grun1=1; 
		break;
	case 1:
		px--;
		if ( maze[level][px][py] >= 7 ){
			px++;
			grun1=(rand()%4);

		}
		if (px<=0) grun1=0;
		break;
	case 2:
		py++;
		if ( maze[level][px][py] >= 7 ){
			py--;
			grun1=(rand()%4);

		}
		if (py>=16) grun1=3;
		break;
	case 3:
		py--;
		if ( maze[level][px][py] >= 7 ){
			py++;
			grun1=(rand()%4);

		}

		if (py<=0) grun1=2;
		break;
	}
	if (px==pr){
		if (py<pc) grun1=2;
		else grun1=3;
	}
	
	if (py==pc){
		if (px<pr) grun1=0;
		else grun1=1;
	}
	gr1=px;
	gc1=py;
}

void ghostrun2 ()
{
	if (run!=3) return;
	int px=gr2,py=gc2;
	switch(grun2){
	case 0:
		px++;
		if ( maze[level][px][py] >= 7 ){
			px--;
			grun2=(rand()%4);

		}
		if (px>=16) grun2=1; 
		break;
	case 1:
		px--;
		if ( maze[level][px][py] >= 7 ){
			px++;
			grun2=(rand()%4);

		}
		if (px<=0) grun2=0;
		break;
	case 2:
		py++;
		if ( maze[level][px][py] >= 7 ){
			py--;
			grun2=(rand()%4);

		}
		if (py>=16) grun2=3;
		break;
	case 3:
		py--;
		if ( maze[level][px][py] >= 7 ){
			py++;
			grun2=(rand()%4);

		}

		if (py<=0) grun2=2;
		break;
	}
	if (px==pr){
		if (py<pc) grun2=2;
		else grun2=3;
	}
	
	if (py==pc){
		if (px<pr) grun2=0;
		else grun2=1;
	}
	gr2=px;
	gc2=py;
}

void ghostrun3 ()
{
	if (run!=3) return;
	int px=gr3,py=gc3;
	switch(grun3){
	case 0:
		px++;
		if ( maze[level][px][py] >= 7 ){
			px--;
			grun3=(rand()%4);

		}
		if (px>=16) grun3=1; 
		break;
	case 1:
		px--;
		if ( maze[level][px][py] >= 7 ){
			px++;
			grun3=(rand()%4);

		}
		if (px<=0) grun3=0;
		break;
	case 2:
		py++;
		if ( maze[level][px][py] >= 7 ){
			py--;
			grun3=(rand()%4);

		}
		if (py>=16) grun3=3;
		break;
	case 3:
		py--;
		if ( maze[level][px][py] >= 7 ){
			py++;
			grun3=(rand()%4);

		}

		if (py<=0) grun3=2;
		break;
	}
	if (px==pr){
		if (py<pc) grun3=2;
		else grun3=3;
	}
	
	if (py==pc){
		if (px<pr) grun3=0;
		else grun3=1;
	}
	gr3=px;
	gc3=py;
}

int eat ()
{
	if (((pr==gr)&&(pc==gc))||((pr==gr1)&&(pc==gc1))||((pr==gr2)&&(pc==gc2))||((pr==gr3)&&(pc==gc3)))
	{
		life--;
		pr=pc=1;
		iDelay (2);
		gr=gc=gr1=gc1=gr2=gc2=gr3=gc3=8;
		return 1;
	}
	else return 0;
}

void packy ()
{
	int tx = pr, ty = pc;
	if ( abs(move) == 1 )	tx+=move;

	if ( abs(move) == 2 )	ty+=move/2;

	if ( tx == -1 )	tx = 16;
	if ( ty == -1 )	ty = 16;
	tx%= 17;
	ty%= 17;

	if ( maze[level][tx][ty] >= 7 )	{
		if ( abs(move) == 1 )	tx-=move;
		if ( abs(move) == 2 )	ty-=move/2;
		
		move = 0;
	}
	else if ( maze[level][tx][ty] == 0 )			//eating points
	{
		maze[level][tx][ty] = 2;
		maze[level][pr][pc] = -1;
		total+=10;
	}
	else if ( maze[level][tx][ty] == 3 )			//eating stars
	{
		maze[level][tx][ty] = 2;
		maze[level][pr][pc] = -3;
		total+=30;
	}
	pr = tx, pc = ty;
	status*= -1;
}

void drawmaze(int maze[17][17])
{
	char x[30]="assets/images/block9.bmp";
	// iShowImage(100,100,"assets/images/block9.bmp");
	
	for(i=0;i<17;++i)
	for(j=0;j<17;++j)
		{
			if(maze[i][j]>=7){
				x[12]=maze[i][j]+'0';
				iShowImage(p*i+sx,p*j+sy,"assets/images/block9.bmp");
			}

			else if(maze[i][j]==0){
				iSetColor(224,224,64);
				iFilledCircle(p*i+p/2+sx,p*j+p/2+sy,4,10);
			}

			else if(maze[i][j]==3){
				if((tim%2)==0)
					iShowImage(p*i+sx,p*j+sy,"assets/images/sprites/PacMan Foodfood.bmp");
				else
					iShowImage(p*i+sx,p*j+sy,"assets/images/sprites/PacMan Foodfood2.bmp");
			}
		}
	iSetColor (255,0,255);
	iFilledRectangle (50,620, 256, 50);
	iSetColor (0,0,0);
	iText ( 55, 625, "CHANGE THE COLOURS",GLUT_BITMAP_HELVETICA_18);
	
}

/*
function iMouseMove() is called when the user moves the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    // place your codes here
}

/*
function iMouseDrag() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseDrag(int mx, int my)
{
    // place your codes here
}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (run==0) run=1;
	if (run==5) run=1;

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
		//printf ( "mx: %d, my: %d\n", mx, my );
		if ( mx>=50 && mx<=306 && my>=620 && my<=670 )	randomize();
		
		if (run==1)
		{	
			if ( mx>=396 && mx<=644 && my>=390 && my<=430 )		run=2;
			else if ( mx>=396 && mx<=644 && my>=316 && my<=358 )	run=4;
			else if ( mx>=396 && mx<=644 && my>=90 && my<=132 )		exit(0);
			else if ( mx>=396 && mx<=644 && my>=239 && my<=283 )	run=10;
			else if ( mx>=396 && mx<=644 && my>=165 && my<=208 )	run=7;
		}
		if (run==4)
		{
			if ( mx>=273 && mx<=381 && my>=74 && my<=119 ) run=1;
			else if ( mx>=444 && mx<=675 && my>=275 && my<=314 ){
				level=0;
				run=2;}
			else if ( mx>=444 && mx<=675 && my>=207 && my<=245 ){
				level=1;
				run=2;}
			else if ( mx>=444 && mx<=675 && my>=135 && my<=173 ){
				level=2;
				run=2;}
		}
		if (run==3)
		{	
			//pr =pc = 1;
			if ( mx>=712 && mx<=943 && my>=38 && my<=79 ){
				run=1;
				total=0;
				life=3;
				level=0;
				reset();
			}
		}
		if (run==10)
		{
			if ( mx>=461 && mx<=569 && my>=84 && my<=127 )		run=1;
		}
		if (run==7)
		{
			if ( mx>=325 && mx<=433 && my>=93 && my<=139 )		run=1;
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

/*
function iMouseWheel() is called when the user scrolls the mouse wheel.
dir = 1 for up, -1 for down.
*/
void iMouseWheel(int dir, int mx, int my)
{
    // place your code here
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (run==0) run=1;
	if (run==2) run=3;
	if (run==5) run=1;
	if(key == 'q') exit(0);
	if ((run==3)&&(key == 'r')) randomize();
	//place your codes for other keys here
}

void pacmove()      //moves the pacman
{
	if ( move==0||status==0)	iShowImage(pr*32+sx,pc*32+sy,"assets/images/sprites/Pacman/Pac_rgt_2.bmp");
		if ( status == 1 )	{
			if ( move == 1 )	iShowImage(pr*32+sx,pc*32+sy,"assets/images/sprites/Pacman/Pac_rgt.bmp");
			if ( move == -1 )	iShowImage(pr*32+sx,pc*32+sy,"assets/images/sprites/Pacman/Pac_lft.bmp");
			if ( move == 2 )	iShowImage(pr*32+sx,pc*32+sy,"assets/images/sprites/Pacman/Pac_upp.bmp");
			if ( move == -2 )	iShowImage(pr*32+sx,pc*32+sy,"assets/images/sprites/Pacman/Pac_dwn.bmp");
		}
		else if (status==-1)	{
			if ( move == 1 )	iShowImage(pr*32+sx,pc*32+sy,"assets/images/sprites/Pacman/Pac_rgt_2.bmp");
			if ( move == -1 )	iShowImage(pr*32+sx,pc*32+sy,"assets/images/sprites/Pacman/Pac_lft_2.bmp");
			if ( move == 2 )	iShowImage(pr*32+sx,pc*32+sy,"assets/images/sprites/Pacman/Pac_upp_2.bmp");
			if ( move == -2 )	iShowImage(pr*32+sx,pc*32+sy,"assets/images/sprites/Pacman/Pac_dwn_2.bmp");
		}
}

void finish()		//determines the finishing point
{
	int s,k;
	fp=fopen("highscore.txt","r");
	
    for (i=0;i<7;i++) {
        fscanf(fp,"%d\n",&highscore[i]);
	}
	fclose(fp);

	if ((life==0)||(level==3)){
		run=5;
		reset();
		if (total>highscore[6]){
			life=3;
			level=0;
			pr=pc=1;
			highscore[6]=total;
			for (i=0;i<6;i++)
				for (j=i+1;j<7;j++)
					if (highscore[j] > highscore[i])
					{
						s=highscore[i];
						highscore[i]=highscore[j];
						highscore[j]=s;
					}
			fp=fopen("highscore.txt","w");
			for (k=0;k<7;k++)
				fprintf(fp,"%d\n",highscore[k]);
			fclose(fp);
		}
	}
}

void intoch(int num)		//converts int to char
{
	int k=0;

	while(num/10){
		score[k++]=num%10+48;
		num/=10;
	}
	score[k++]=num+48;
	score[k]=0;

	strrev(score);
}

void showscore(void)
{
	fp=fopen("highscore.txt","r");
	
    for (i=0;i<7;i++)
        fscanf(fp,"%d\n",&highscore[i]);

	fclose(fp);
	iSetColor(50,250,50);
	intoch(highscore[0]);
	iText(371,450,score,GLUT_BITMAP_TIMES_ROMAN_24);
	intoch(highscore[1]);
	iText(371,400,score,GLUT_BITMAP_TIMES_ROMAN_24);
	intoch(highscore[2]);
	iText(371,350,score,GLUT_BITMAP_TIMES_ROMAN_24);
	intoch(highscore[3]);
	iText(371,300,score,GLUT_BITMAP_TIMES_ROMAN_24);
	intoch(highscore[4]);
	iText(371,250,score,GLUT_BITMAP_TIMES_ROMAN_24);
	intoch(highscore[5]);
	iText(371,200,score,GLUT_BITMAP_TIMES_ROMAN_24);
	intoch(highscore[6]);
	iText(371,150,score,GLUT_BITMAP_TIMES_ROMAN_24);
}

/*
function iSpecialKeyboard() is called whenver user hits special keys likefunction
keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11,
GLUT_KEY_F12, GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN,
GLUT_KEY_PAGE_UP, GLUT_KEY_PAGE_DOWN, GLUT_KEY_HOME, GLUT_KEY_END,
GLUT_KEY_INSERT */
int direction = 1;
void iSpecialKeyboard(unsigned char key)
{
	if (run==0) run=1;
	if (run==2) run=3;
	if (run==5) run=1;
	if ( key == GLUT_KEY_UP )	move = 2;
	if ( key == GLUT_KEY_DOWN)	move = -2;
	if ( key == GLUT_KEY_RIGHT )	move = 1;
	if ( key == GLUT_KEY_LEFT )	move = -1;
	// place your codes for other keys here
}

void iKeyboardUP(unsigned char key)
{
}

void reset(void)	//resets the maze
{
	int a,b,c;
	for (a=0;a<3;++a)
		for (b=0;b<17;++b)
			for (c=0;c<17;++c){
				if (maze[a][b][c]==-1)	maze[a][b][c]=0;
				else if (maze[a][b][c]==-3)	maze[a][b][c]=3;
			}
	pr=1,pc=1;
	gr=gc=gr1=gc1=gr2=gc2=gr3=gc3=8;
	life=3;

}

void iSpecialKeyboardUP(unsigned char key)
{
	if (run==0) run=1;
	if (run==2) run=3;
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    // place your own initialization codes here.
    loadResources();
    t1 = clock();

	srand (time(NULL));
	randomize();
	iSetTimer (400, packy);
	iSetTimer (350, ghostrun);
	iSetTimer (350, ghostrun1);
	iSetTimer (350, ghostrun2);
	iSetTimer (350, ghostrun3);
	// iInitialize (1100, 690);
    iInitialize(1800, 600, "Pacman 151.159");
    return 0;
}