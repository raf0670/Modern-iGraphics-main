#include "iGraphics.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void drawmaze(int maze[17][17]);
int find(int l, int x);
void pacmove();
void packy();
void intoch(int);
void playmenu();
void ghost();
int eat();
void finish();
void showscore();
void ghostrun();
void ghostrun1();
void ghostrun2();
void ghostrun3();
void reset();

const int MAX_NAME_LENGTH = 50;
typedef struct PlayerScore {
    char name[MAX_NAME_LENGTH];
    int score;
} PlayerScore;

FILE *fp;

int maze[5][17][17] = {
    1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1,
    1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1,
    1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1, 0, 1,
    1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1,
    1, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1,
    1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1,
    0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0,
    1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1,
    1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 3, 1, 0, 0, 0, 1,
    1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1,
    1, 0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
    1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1,
    1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1,

    1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 3, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 3, 1,
    1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1,
    1, 3, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 3, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1,

    1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
    1, 0, 0, 3, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 1, 3, 1,
    1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1,
    1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1,
    1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1,
    1, 0, 0, 3, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 1, 3, 1,
    1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1
};

int level = 0, life = 3, p = 32, a, b, c, i, j, sx = 1, sy = 1, flag1 = 0, run = 0;
int pr = 1, pc = 1, move = 0, status = 1, pause = 0;
int total = 0, gr = 8, gc = 8, grun = 0, gr1 = 8, gc1 = 8, grun1 = 1, gr2 = 8, gc2 = 8, grun2 = 2, gr3 = 8, gc3 = 8, grun3 = 3;
char hscore[20], score[20];
clock_t t1, t2, tim;

Image frames[8];
Image ghostsss[2];
Image block[1];
Image start;

char currentPlayerName[MAX_NAME_LENGTH];
int nameInputMode = 0;
int nameIndex = 0;
PlayerScore highscores[7];

void loadResources() {
    iLoadImage(&frames[0], "assets/images/sprites/Pacman/Pac_rgt.bmp");
    iLoadImage(&frames[1], "assets/images/sprites/Pacman/Pac_lft.bmp");
    iLoadImage(&frames[2], "assets/images/sprites/Pacman/Pac_upp.bmp");
    iLoadImage(&frames[3], "assets/images/sprites/Pacman/Pac_dwn.bmp");
    iLoadImage(&frames[4], "assets/images/sprites/Pacman/Pac_rgt_2.bmp");
    iLoadImage(&frames[5], "assets/images/sprites/Pacman/Pac_lft_2.bmp");
    iLoadImage(&frames[6], "assets/images/sprites/Pacman/Pac_upp_2.bmp");
    iLoadImage(&frames[7], "assets/images/sprites/Pacman/Pac_dwn_2.bmp");
    iLoadImage(&ghostsss[0], "assets/images/sprites/Pacman/ghost.bmp");
    iLoadImage(&ghostsss[1], "assets/images/sprites/Pacman/ghost_2.bmp");
    iLoadImage(&block[0], "assets/images/sprites/blocks/block9.bmp");
    iLoadImage(&start, "assets/images/start.bmp");
}

void iAnim() {
}

/*
function iDraw() is called again and again by the system.
*/
void iDraw() {
    t2 = clock();
    tim = (t2 - t1) / CLOCKS_PER_SEC; 

    if (run == 0) {
        iClear();
        int scr_ht = 1800, scr_wid = 600;
        iShowImage(-235, 15, "assets/images/start.bmp", scr_ht, scr_wid);
    } else if (run == 1) {
        iClear();
        iShowImage(200, 20, "assets/images/menu.bmp");
    } else if (run == 2) {
        iClear();
        if (level == 0) iShowImage(274, 82, "assets/images/level1.bmp");
        else if (level == 1) iShowImage(274, 82, "assets/images/level2.bmp");
        else if (level == 2) iShowImage(274, 82, "assets/images/level3.bmp");
    } else if (run == 3) {
        iClear();

        if ((find(level, 0) == 0) && (find(level, 3) == 0)) {
            level++;
            gr = gc = gr1 = gc1 = gr2 = gc2 = gr3 = gc3 = 8;
            run = 2;
            iDelay(1);
            pr = pc = 1;
            move = 0;
            status = 1;
        }
        drawmaze(maze[level]);
        playmenu();

        pacmove();
        eat();
        finish();

        if ((tim % 2) == 0) iShowImage(gr * 32 + sx, gc * 32 + sy, "assets/images/blinky.bmp");
        else iShowImage(gr * 32 + sx, gc * 32 + sy, "assets/images/blinky_2.bmp");
        if ((tim % 2) == 0) iShowImage(gr1 * 32 + sx, gc1 * 32 + sy, "assets/images/clyde.bmp");
        else iShowImage(gr1 * 32 + sx, gc1 * 32 + sy, "assets/images/clyde_2.bmp");
        if ((tim % 2) == 0) iShowImage(gr2 * 32 + sx, gc2 * 32 + sy, "assets/images/pinky.bmp");
        else iShowImage(gr2 * 32 + sx, gc2 * 32 + sy, "assets/images/pinky_2.bmp");
        if ((tim % 2) == 0) iShowImage(gr3 * 32 + sx, gc3 * 32 + sy, "assets/images/inky.bmp");
        else iShowImage(gr3 * 32 + sx, gc3 * 32 + sy, "assets/images/inky_2.bmp");
    } else if (run == 4) {
        iClear();
        iShowImage(274, 72, "assets/images/chooselevel.bmp");
    } else if (run == 10) {
        iClear();
        iShowImage(274, 82, "assets/images/savedscores.bmp");
        showscore();
    } else if (run == 5) {
        iClear();
        if (total > highscores[6].score) {
            iShowImage(274, 82, "assets/images/high.bmp");
            iText(481, 293, score, GLUT_BITMAP_TIMES_ROMAN_24);
            iDelay(1);
            total = 0;
        } else {
            iShowImage(274, 82, "assets/images/high_2.bmp");
            iText(481, 293, score, GLUT_BITMAP_TIMES_ROMAN_24);
            iDelay(1);
            total = 0;
        }
    } else if (run == 7) {
        iClear();
        iShowImage(125, 82, "assets/images/help.bmp");
    } else if (run == 6) {
        iClear();
        iSetColor(255, 255, 255);
        iText(300, 350, "ENTER YOUR NAME:", GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0, 0, 0);
        iFilledRectangle(300, 300, 400, 30);
        iSetColor(255, 255, 255);
        iText(305, 305, currentPlayerName, GLUT_BITMAP_TIMES_ROMAN_24);
        iText(300, 250, "Press ENTER to confirm", GLUT_BITMAP_HELVETICA_18);
    }
}

void playmenu(void)
{
    iShowImage(720, 500, "assets/images/pacman_run.bmp");
    iShowImage(700, 20, "assets/images/score.bmp");
    iSetColor(40, 240, 120);
    intoch(highscores[0].score);
    strcpy(hscore, score);
    iText(859, 176, score, GLUT_BITMAP_TIMES_ROMAN_24);
    intoch(total);
    iText(859, 283, score, GLUT_BITMAP_TIMES_ROMAN_24);
    for (i = 0; i < life; i++)
        iShowImage(830 + i * 40, 100, "assets/images/life.bmp");
    if (level == 0) iShowImage(842, 344, "assets/images/lev1.bmp");
    else if (level == 1) iShowImage(842, 344, "assets/images/lev2.bmp");
    else if (level == 2) iShowImage(842, 344, "assets/images/lev3.bmp");
}

void randomize() {
    int i, j, k;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 17; j++)
            for (k = 0; k < 17; k++)
                if (maze[i][j][k] == 1 || maze[i][j][k] >= 7)
                    maze[i][j][k] = rand() % 3 + 7;
}

int find(int l, int x) {
    int i, j, count = 0;
    for (i = 0; i < 17; i++)
        for (j = 0; j < 17; j++)
            if (maze[l][i][j] == x) count++;
    return (count);
}

void ghostrun() {
    if (run != 3) return;
    int px = gr, py = gc;
    switch (grun) {
        case 0:
            px++;
            if (maze[level][px][py] >= 7) {
                px--;
                grun = (rand() % 4);
            }
            if (px >= 16) grun = 1;
            break;
        case 1:
            px--;
            if (maze[level][px][py] >= 7) {
                px++;
                grun = (rand() % 4);
            }
            if (px <= 0) grun = 0;
            break;
        case 2:
            py++;
            if (maze[level][px][py] >= 7) {
                py--;
                grun = (rand() % 4);
            }
            if (py >= 16) grun = 3;
            break;
        case 3:
            py--;
            if (maze[level][px][py] >= 7) {
                py++;
                grun = (rand() % 4);
            }
            if (py <= 0) grun = 2;
            break;
    }
    if (px == pr) {
        if (py < pc) grun = 2;
        else grun = 3;
    }

    if (py == pc) {
        if (px < pr) grun = 0;
        else grun = 1;
    }
    gr = px;
    gc = py;
}

void ghostrun1() {
    if (run != 3) return;
    int px = gr1, py = gc1;
    switch (grun1) {
        case 0:
            px++;
            if (maze[level][px][py] >= 7) {
                px--;
                grun1 = (rand() % 4);
            }
            if (px >= 16) grun1 = 1;
            break;
        case 1:
            px--;
            if (maze[level][px][py] >= 7) {
                px++;
                grun1 = (rand() % 4);
            }
            if (px <= 0) grun1 = 0;
            break;
        case 2:
            py++;
            if (maze[level][px][py] >= 7) {
                py--;
                grun1 = (rand() % 4);
            }
            if (py >= 16) grun1 = 3;
            break;
        case 3:
            py--;
            if (maze[level][px][py] >= 7) {
                py++;
                grun1 = (rand() % 4);
            }
            if (py <= 0) grun1 = 2;
            break;
    }
    if (px == pr) {
        if (py < pc) grun1 = 2;
        else grun1 = 3;
    }

    if (py == pc) {
        if (px < pr) grun1 = 0;
        else grun1 = 1;
    }
    gr1 = px;
    gc1 = py;
}

void ghostrun2() {
    if (run != 3) return;
    int px = gr2, py = gc2;
    switch (grun2) {
        case 0:
            px++;
            if (maze[level][px][py] >= 7) {
                px--;
                grun2 = (rand() % 4);
            }
            if (px >= 16) grun2 = 1;
            break;
        case 1:
            px--;
            if (maze[level][px][py] >= 7) {
                px++;
                grun2 = (rand() % 4);
            }
            if (px <= 0) grun2 = 0;
            break;
        case 2:
            py++;
            if (maze[level][px][py] >= 7) {
                py--;
                grun2 = (rand() % 4);
            }
            if (py >= 16) grun2 = 3;
            break;
        case 3:
            py--;
            if (maze[level][px][py] >= 7) {
                py++;
                grun2 = (rand() % 4);
            }
            if (py <= 0) grun2 = 2;
            break;
    }
    if (px == pr) {
        if (py < pc) grun2 = 2;
        else grun2 = 3;
    }

    if (py == pc) {
        if (px < pr) grun2 = 0;
        else grun2 = 1;
    }
    gr2 = px;
    gc2 = py;
}

void ghostrun3() {
    if (run != 3) return;
    int px = gr3, py = gc3;
    switch (grun3) {
        case 0:
            px++;
            if (maze[level][px][py] >= 7) {
                px--;
                grun3 = (rand() % 4);
            }
            if (px >= 16) grun3 = 1;
            break;
        case 1:
            px--;
            if (maze[level][px][py] >= 7) {
                px++;
                grun3 = (rand() % 4);
            }
            if (px <= 0) grun3 = 0;
            break;
        case 2:
            py++;
            if (maze[level][px][py] >= 7) {
                py--;
                grun3 = (rand() % 4);
            }
            if (py >= 16) grun3 = 3;
            break;
        case 3:
            py--;
            if (maze[level][px][py] >= 7) {
                py++;
                grun3 = (rand() % 4);
            }
            if (py <= 0) grun3 = 2;
            break;
    }
    if (px == pr) {
        if (py < pc) grun3 = 2;
        else grun3 = 3;
    }

    if (py == pc) {
        if (px < pr) grun3 = 0;
        else grun3 = 1;
    }
    gr3 = px;
    gc3 = py;
}

int eat() {
    if (((pr == gr) && (pc == gc)) || ((pr == gr1) && (pc == gc1)) || ((pr == gr2) && (pc == gc2)) || ((pr == gr3) && (pc == gc3))) {
        life--;
        pr = pc = 1;
        iDelay(2);
        gr = gc = gr1 = gc1 = gr2 = gc2 = gr3 = gc3 = 8;
        return 1;
    } else
        return 0;
}

void packy() {
    if (pause) return;

    int tx = pr, ty = pc;
    if (abs(move) == 1) tx += move;
    if (abs(move) == 2) ty += move / 2;

    if (tx == -1) tx = 16;
    if (ty == -1) ty = 16;
    tx %= 17;
    ty %= 17;

    if (maze[level][tx][ty] >= 7) {
        if (abs(move) == 1) tx -= move;
        if (abs(move) == 2) ty -= move / 2;
        move = 0;
    } else if (maze[level][tx][ty] == 0) {
        maze[level][tx][ty] = 2;
         maze[level][pr][pc] = -1;
        total += 10;
    } else if (maze[level][tx][ty] == 3) {
        maze[level][tx][ty] = 2;
         maze[level][pr][pc] = -3;
        total += 30;
    }
    pr = tx, pc = ty;
    status *= -1;
}

void drawmaze(int maze[17][17]) {
    for (i = 0; i < 17; ++i)
        for (j = 0; j < 17; ++j) {
            if (maze[i][j] >= 7) {
                iShowImage(p * i + sx, p * j + sy, "assets/images/block9.bmp");
            } else if (maze[i][j] == 0) {
                iSetColor(224, 224, 64);
                iFilledCircle(p * i + p / 2 + sx, p * j + p / 2 + sy, 4, 10);
            } else if (maze[i][j] == 3) {
                if ((tim % 2) == 0)
                    iShowImage(p * i + sx, p * j + sy, "assets/images/sprites/PacMan Food/food.bmp");
                else
                    iShowImage(p * i + sx, p * j + sy, "assets/images/sprites/PacMan Food/food2.bmp");
            }
        }
}

/*
function iMouseMove() is called when the user moves the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my) {
    
}

/*
function iMouseDrag() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseDrag(int mx, int my) {
    
}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my) {
    if (run == 0) run = 1;
    if (run == 5) run = 1;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (run == 1) {
            if (mx >= 396 && mx <= 644 && my >= 390 && my <= 430) {
                run = 6;
                nameInputMode = 1;
                nameIndex = 0;
                currentPlayerName[0] = '\0';
            } else if (mx >= 396 && mx <= 644 && my >= 316 && my <= 358) {
                run = 4;
            } else if (mx >= 396 && mx <= 644 && my >= 90 && my <= 132) {
                exit(0);
            } else if (mx >= 396 && mx <= 644 && my >= 239 && my <= 283) {
                run = 10;
            } else if (mx >= 396 && mx <= 644 && my >= 165 && my <= 208) {
                run = 7;
            }
        }
        if (run == 4) {
            if (mx >= 273 && mx <= 381 && my >= 74 && my <= 119) run = 1;
            else if (mx >= 444 && mx <= 675 && my >= 275 && my <= 314) {
                level = 0;
                run = 2;
                reset();
            } else if (mx >= 444 && mx <= 675 && my >= 207 && my <= 245) {
                level = 1;
                run = 2;
                reset();
            } else if (mx >= 444 && mx <= 675 && my >= 135 && my <= 173) {
                level = 2;
                run = 2;
                reset();
            }
        }
        if (run == 3) {
            if (mx >= 712 && mx <= 943 && my >= 38 && my <= 79) {
                run = 1;
                reset();
            }
        }
        if (run == 10) {
            if (mx >= 461 && mx <= 569 && my >= 84 && my <= 127) run = 1;
        }
        if (run == 7) {
            if (mx >= 325 && mx <= 433 && my >= 93 && my <= 139) run = 1;
        }
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        
    }
}

/*
function iMouseWheel() is called when the user scrolls the mouse wheel.
dir = 1 for up, -1 for down.
*/
void iMouseWheel(int dir, int mx, int my) {
    
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key) {
    if (run == 0) run = 1;
    if (run == 2) run = 3;
    if (run == 5) run = 1;

    if (run == 6) {
        if (key == '\b') {
            if (nameIndex > 0) {
                nameIndex--;
                currentPlayerName[nameIndex] = '\0';
            }
        } else if (key == '\r' || key == 13) {
            nameInputMode = 0;
            if (strlen(currentPlayerName) == 0) {
                strcpy(currentPlayerName, "Player");
            }
            run = 2;
            reset();
        } else if (nameIndex < MAX_NAME_LENGTH - 1) {
            currentPlayerName[nameIndex++] = key;
            currentPlayerName[nameIndex] = '\0';
        }
    } else {
        if (key == 'q') exit(0);
        if ((run == 3) && (key == 'r')) randomize();
        if ((run == 3) && (key == 'p')) {
            pause = 1 - pause;
            if (pause) {
                iPauseTimer(0); iPauseTimer(1); iPauseTimer(2); iPauseTimer(3); iPauseTimer(4);
            } else {
                iResumeTimer(0); iResumeTimer(1); iResumeTimer(2); iResumeTimer(3); iResumeTimer(4);
            }
        }
    }
}

void pacmove()
{
    if (pause) return;

    if (move == 0 || status == 0) iShowImage(pr * 32 + sx, pc * 32 + sy, "assets/images/sprites/Pacman/Pac_rgt_2.bmp");
    if (status == 1) {
        if (move == 1) iShowImage(pr * 32 + sx, pc * 32 + sy, "assets/images/sprites/Pacman/Pac_rgt.bmp");
        if (move == -1) iShowImage(pr * 32 + sx, pc * 32 + sy, "assets/images/sprites/Pacman/Pac_lft.bmp");
        if (move == 2) iShowImage(pr * 32 + sx, pc * 32 + sy, "assets/images/sprites/Pacman/Pac_upp.bmp");
        if (move == -2) iShowImage(pr * 32 + sx, pc * 32 + sy, "assets/images/sprites/Pacman/Pac_dwn.bmp");
    } else if (status == -1) {
        if (move == 1) iShowImage(pr * 32 + sx, pc * 32 + sy, "assets/images/sprites/Pacman/Pac_rgt_2.bmp");
        if (move == -1) iShowImage(pr * 32 + sx, pc * 32 + sy, "assets/images/sprites/Pacman/Pac_lft_2.bmp");
        if (move == 2) iShowImage(pr * 32 + sx, pc * 32 + sy, "assets/images/sprites/Pacman/Pac_upp_2.bmp");
        if (move == -2) iShowImage(pr * 32 + sx, pc * 32 + sy, "assets/images/sprites/Pacman/Pac_dwn_2.bmp");
    }
}

void finish()
{
    int k;
    fp = fopen("highscore.txt", "r");
    if (fp == NULL) {
        for (i = 0; i < 7; i++) {
            strcpy(highscores[i].name, "_______");
            highscores[i].score = 0;
        }
    } else {
        for (i = 0; i < 7; i++) {
            fscanf(fp, "%s %d\n", highscores[i].name, &highscores[i].score);
        }
        fclose(fp);
    }

    if ((life == 0) || (level == 3)) {
        run = 5;
        if (total > highscores[6].score) {
            strcpy(highscores[6].name, currentPlayerName);
            highscores[6].score = total;

            for (i = 0; i < 6; i++) {
                for (j = i + 1; j < 7; j++) {
                    if (highscores[j].score > highscores[i].score) {
                        PlayerScore temp = highscores[i];
                        highscores[i] = highscores[j];
                        highscores[j] = temp;
                    }
                }
            }

            fp = fopen("highscore.txt", "w");
            for (k = 0; k < 7; k++) {
                fprintf(fp, "%s %d\n", highscores[k].name, highscores[k].score);
            }
            fclose(fp);
        }
        reset();
    }
}

void intoch(int num)
{
    int k = 0;
    if (num == 0) {
        score[0] = '0';
        score[1] = '\0';
        return;
    }
    while (num > 0) {
        score[k++] = num % 10 + '0';
        num /= 10;
    }
    score[k] = '\0';
    int start = 0, end = k - 1;
    while (start < end) {
        char temp = score[start];
        score[start] = score[end];
        score[end] = temp;
        start++;
        end--;
    }
}

void showscore(void) {
    fp = fopen("highscore.txt", "r");
    if (fp == NULL) {
        iSetColor(255, 255, 255);
        iText(371, 350, "No High Scores Yet!", GLUT_BITMAP_TIMES_ROMAN_24);
        return;
    }

    for (i = 0; i < 7; i++) {
        fscanf(fp, "%s %d\n", highscores[i].name, &highscores[i].score);
    }
    fclose(fp);

    iSetColor(50, 250, 50);
    for (i = 0; i < 7; i++) {
        char scoreDisplay[MAX_NAME_LENGTH + 10];
        sprintf(scoreDisplay, "%s: %d", highscores[i].name, highscores[i].score);
        iText(371, 450 - (i * 50), scoreDisplay, GLUT_BITMAP_TIMES_ROMAN_24);
    }
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
void iSpecialKeyboard(unsigned char key) {
    if (run == 0) run = 1;
    if (run == 2) run = 3;
    if (run == 5) run = 1;

    if (run == 3 && !pause) {
        if (key == GLUT_KEY_UP) move = 2;
        if (key == GLUT_KEY_DOWN) move = -2;
        if (key == GLUT_KEY_RIGHT) move = 1;
        if (key == GLUT_KEY_LEFT) move = -1;
    }
}

void iKeyboardUP(unsigned char key) {
}

void reset(void)
{
    int a, b, c;
    for (a = 0; a < 3; ++a)
        for (b = 0; b < 17; ++b)
            for (c = 0; c < 17; ++c) {
                if (maze[a][b][c] == 2 || maze[a][b][c] == -1) maze[a][b][c] = 0;
                else if (maze[a][b][c] == 2 || maze[a][b][c] == -3) maze[a][b][c] = 3;
            }
    pr = 1, pc = 1;
    gr = gc = gr1 = gc1 = gr2 = gc2 = gr3 = gc3 = 8;
    life = 3;
    total = 0;
    level = 0;
    move = 0;
    pause = 0;
    randomize();
}

void iSpecialKeyboardUP(unsigned char key) {
    if (run == 0) run = 1;
    if (run == 2) run = 3;
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    loadResources();
    t1 = clock();

    fp = fopen("highscore.txt", "r");
    if (fp == NULL) {
        for (i = 0; i < 7; i++) {
            strcpy(highscores[i].name, "_______");
            highscores[i].score = 0;
        }
    } else {
        for (i = 0; i < 7; i++) {
            fscanf(fp, "%s %d\n", highscores[i].name, &highscores[i].score);
        }
        fclose(fp);
    }
    strcpy(currentPlayerName, "Player");


    srand(time(NULL));
    randomize();
    iSetTimer(400, packy);
    iSetTimer(350, ghostrun);
    iSetTimer(350, ghostrun1);
    iSetTimer(350, ghostrun2);
    iSetTimer(350, ghostrun3);
    iInitialize(1800, 600, "Pacman 151.159");
    return 0;
}