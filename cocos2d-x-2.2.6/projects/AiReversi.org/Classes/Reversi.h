//
//  Reversi.h
//  Reversi
//
//  Created by 宮下修治 on 2015/05/24.
//
#ifndef EXTERN
#define EXTERN extern

#endif
EXTERN int hint;
EXTERN int sound;
EXTERN int te;
EXTERN int jo;
EXTERN int shu;
EXTERN int chu;
EXTERN int D;
EXTERN int lv;
EXTERN int Score_w1;
EXTERN int Score_l1;
EXTERN int Score_draw1;
EXTERN int Score_w2;
EXTERN int Score_l2;
EXTERN int Score_draw2;
EXTERN int Score_w3;
EXTERN int Score_l3;
EXTERN int Score_draw3;
EXTERN int Score_w4;
EXTERN int Score_l4;
EXTERN int Score_draw4;
EXTERN int Score_w5;
EXTERN int Score_l5;
EXTERN int Score_draw5;
#ifndef Reversi_Reversi_h
#define Reversi_Reversi_h
#include<stdio.h>
#include<stdlib.h>
#define COM 1
#define MAN -1
#define ON 1
#define OFF 0
void init(void);
extern int check(int,int,int);
int enableput(void);
int scan(void);
int min_level(int,int,int,int);
int max_level(int,int,int,int);
int min_levelf(int,int,int,int);
int min_max(int, int, int,int);
int max_levelf(int,int,int,int);
int min_maxf(int, int, int,int);
int xuti(void);
int cuto(void);
int passf(void);
int evl(void);
int sekisa(void);
int input(int,int);
int Hen1(void);
int Hen2(void);
int eopen(void);
void sen(void);
void got(void);
void level (int);
//void level5(void);
extern int reversi(void);
extern int reversi_put(int*);
extern void initi(void);
extern void initig(void);
extern void reput(void);
extern int xyput(void);
extern void Reset(int);
static int c;
static int o,xy,e,maxe,com,man,done,count, value, i, dir[]={-11, -10, -9, -1, 1, 9, 10, 11};
static char tbl[]={
		
		11,18,81,88,
    34,43,53,35,64,56,46,65,
    24,25,42,52,74,75,47,57,
    23,26,32,37,62,67,73,76,
    36,33,63,66,
    14,15,41,51,48,58,84,85,
    13,16,31,38,61,68,83,86,
    12,17,21,28,71,78,82,87,
    22,27,72,77};
extern int copyBan[101];
//static int ixp;
//static int iyp;
static int teban=1;
static int num;
static int undo[101];
static int kifu[60];
static int eval;
static int Board_Sente=1;
static int Board_Gote=-1;
static int open;
extern int untap;
extern int music;
extern int sound;
extern int passm;
extern int pass;
extern int hint;
extern int rep;
static int point[64];
void level1(void);
void level2(void);
void level3(void);
void level4(void);
void level5(void);
#endif
