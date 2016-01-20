
#include "Reversi.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
//#include "title.h"
#include "HelloWorldScene.h"
extern int ban[101];

//extern int D,shu,chu,jo;
void initi(void)
{
    
    int i,j;
   
    c=4;
          for(i=0;i<=100;i++)
                ban[i]=3;
        for (i=1;i<=8;i++)
                for(j=1;j<=8;j++)
                       ban[i+j*10]=0;
    
    ban[4+4*10]=1;
    ban[4+5*10]=-1;
    ban[5+5*10]=1;
    ban[5+4*10]=-1;
    Board_Sente=1;
    Board_Gote=-1;
    //srand((unsigned)time(NULL));
}
void sen()
{
    te=1;
}
void got()
{
    te=-1;
    
    
}
void initig(void)
{
	int i,j;

	c=4;
      for(i=0;i<=100;i++)
            ban[i]=3;
for (i=1;i<=8;i++)
            for(j=1;j<=8;j++)
                   ban[i+j*10]=0;
    Board_Sente=1;
    Board_Gote=-1;
    ban[4+4*10]=-1;
    ban[4+5*10]=1;
    ban[5+5*10]=-1;
    ban[5+4*10]=1;
    //srand((unsigned)time(NULL));
}
void level1()
{
    {chu=1;shu=1;jo=1;D=57;lv=1;}

}
void level2()
{
	{jo=3;chu=2;shu=2;D=55;lv=2;}
}
void level3()
{
	{jo=4;chu=4;shu=4;D=49;lv=3;}


}
void level4()
{
	{jo=5;chu=5;shu=7;D=48;lv=4;}
}

void level5()
{
	{jo=5;chu=6;shu=7;D=47;lv=5;}
}
extern int reversi_put(int* copyBan)
{
    int i;
   // reversi();
   


    return(0);
}
extern int reversi(void)
{
    int all,al,be,put;
    init();
        printf("counter:%d\n ",c);
    

    
c=sekisa();
c=man+com;
    if(c>=D){
        open=0;
        e=OFF;
                al=-1;
                be=1;
                if(c>=D+3){al=-64;be=64;}
                put=min_maxf(65-c,al,be,c);
                printf("\nput:%d#man:%d\n",put,maxe);
              
                all=check(put,COM,OFF);

                if (all){
                        check(put,COM,ON);
                }
    }
    else if(c<8){
                        al=-10000;be=10000;e=ON;put=min_max(jo,al,be,c);e=OFF;open=11;c=64;
    }
    else if(c<35){
                            al=-10000;be=10000;e=ON;put=min_max(chu,al,be,c);e=OFF;open=11;c=64;
                }
                else if(c<D){
                    al=-10000;be=10000;e=ON;put=min_max(shu,al,be,c);e=OFF;open=0;
                }
  {check(put,COM,ON);xy=put;return(put);}
  
    
    
 //       init();
   // return(put);
}
extern int xyput(void)
{
    return xy;
}
extern void reput(void)
{
    int i;
    for(i=0;i<=100;i++)
        ban[i]=undo[i];
}
int put( int put)
{
    int sp;
       /* kifu[c-4]=put;*/
        sekisa();
        printf("com:%d,man:%d",com,man);
        
        if(put==0) return(1);
    
        sp=evl();
        printf("sp:%d",sp);
    
        init();
        /*kifusaisei();*/
        return (0);
}


extern int evl()
{
        int i,j,sp,ev;
        sp=0;
        for(i=11;i<=88;i++)
 {
                if (ban[i]==-1){
                               for(j=1;j<=8;j++){
                               ev=ban[i]+dir[j];
                               if(ev==0)
                             
                               sp++;
                               
                               
                               }
                        }       
                 
                else if(ban[i]==1)
                            { 
                               for(j=1;j<=8;j++){
                               ev=ban[i]+dir[j];
                               if(ev==0)
                               sp--;
                               }
                        }       
          
 }
                return sp*open;
}   
extern void init(void)
{
        int x,y;
        printf("\n  a b c d e f g h\n");
        for (y=1;y<9;y++){
                printf("%d",y);
                for(x=1;x<9;x++)

                        switch (ban[x+y*10]){
                        case 1:
                                printf(" o");
                                break;
                        case -1:
                                printf(" x");
                                break;
                        default:
                                printf(" .");
                }
                printf("\n");
        }
}
extern int check(int put,int turn,int done)
{

        int all;
        all=0;
        if (ban[put] == 0)
        for (i=0; i<8; i++) {
                 for (count = 0, value = put+dir[i];
                 ban[value] ==-turn; value += dir[i])
                count++;

            if (count && ban[value] == turn) {
                all += count;
                value  = put;
                if (done)
                    do
                        ban[value] = turn, value += dir[i];
                    while (ban[value] != turn);
            }
        }
        return (all);
}
int Hen1(void)
{
    int Hen,i,Point,y,order=0;;
    int eval=13;
    int yama=9;
    int wing=-4;
    int Cuti=-6;
   
    
    for (y=1;y<=8;y+=7){
        if(ban[y*10+1]!=0 || ban[y*10+8]!=0)
            if(ban[y*10+1]!=0)
                if(ban[y*10+8]!=0){
                    for(i=1;i<=8;i++)
                        Point+=ban[y*10+i]*eval;
                        }else{
                            for(i=1;i<=8;++i){
                                if(ban[y*10+i]!=ban[y*10+1])
                                    break;
                                Point+=ban[y*10+i]*eval;
                            }
                        }
                else {
                    for(i=8;i>=1;--i){
                        if(ban[y*10+i]!=ban[y*10+8])
                            break;
                    Point+=ban[y*10+i]*eval;
                }
            }
    else {
        
    Hen=0;
    if(ban[y*10+2]!=0 ||  ban[y*10+7]!=0) {
        if(ban[y*10+2]!=0 &&
           ban[y*10+3]==0 &&
           ban[y*10+4]==0)
            Point+=ban[y*10+2]*Cuti;
        
        else if(ban[y*10+7]!=0&&
            ban[y*10+6]==0&&
            ban[y*10+5]==0)
            Point+=ban[y*10+7]*Cuti;
       
        else {
            for(i=1;i<=8;++i){
                Hen+=ban[y*10+i];
            }
        if(Hen==6)
            Point+=yama;
            else if(Hen==-6)
                Point-=yama;
            else if(Hen==5||Hen==-5){
                if(Hen==5)
                    order=1;
                else
                    order=-1;
                if(y==1&&((ban[y*10+2]==order && ban[2*10+6]==order)|| (ban[y*10+7]==order && ban[2*10+3]==order)))
                    Point+=wing*order;
                else if(y==8 && ((ban[y*10+2] == order && ban[7*10+6]==order)|| (ban[y*10+7]==order && ban[7*10+3]==order)))
                        Point+=wing*order;
                        }
                    }
                }
            }
        }
    
    return(Point);
}
int Hen2(void)
{
    int i,Hen,x,Point=0,order=0;;
    int eval=13;
    int yama=9;
    int wing=-4;
    int Cuti=-6;
    
    
    for (x=1;x<=8;x+=7){
        if(ban[10+x]!=0 || ban[8*10+x]!=0)
            if(ban[10*8+x]!=0)
                if(ban[8*10+x]!=0){
                    for(i=1;i<=8;i++)
                        Point+=ban[i*10+x]*eval;
                }else{
                    for(i=1;i<=8;++i){
                        if(ban[i*10+x]!=ban[1*10+x])
                            break;
                        Point+=ban[i*10+x]*eval;
                    }
                }
                else {
                    for(i=8;i>=1;--i){
                        if(ban[i*10+x]!=ban[8*10+x])
                            break;
                        Point+=ban[i*10+x]*eval;
                    }
                }
                else {
                    
                    Hen=0;
                    if(ban[2*10+x]!=0 ||  ban[10*7+x]!=0) {
                        if(ban[2*10+x]!=0 &&
                           ban[3*10+x]==0 &&
                           ban[4*10+x]==0)
                            Point+=ban[2*10+x]*Cuti;
                        
                        else if(ban[7*10+x]!=0&&
                                ban[6*10+x]==0&&
                                ban[5*10+x]==0)
                            Point+=ban[7*10+x]*Cuti;
                      
                        else{
                            for(i=1;i<=8;++i){
                                Hen+=ban[i*10+x];
                            }
                            if(Hen==6)
                                Point+=yama;
                            else if(Hen ==-6)
                                Point-=yama;
                            else if(Hen==5||Hen==-5){
                                if(Hen==5)
                                    order=Board_Sente;
                                else
                                    order=Board_Gote;
                                if(x==1 && ((ban[2*10+x]==order && ban[6*10+7]==order)|| (ban[7*10+x]==order && ban[3*10+7]==order)))
                                    Point+=wing*order;
                                else if(x==8 && ((ban[2*10+x] == order && ban[6*10+7]==order)|| (ban[7*10+x]==order && ban[3*10+7]==order)))
                                    Point+=wing*order;
                            }
                        }
                    }
                }
    
    }
    return(Point);
}

extern int input(int xx,int yy)
{

    
    char a,i,j,all,p;
    printf("a-h,1-8,p");
    all=a=0;
    for(i=0;i<=100;i++)
        undo[i]=ban[i];
    
    for (i=1;i<9;i++)
        for(j=1;j<9;j++){
            p=i+j*10;
            a+=check(p,MAN,OFF);
            
        }
    if(a==0)return(-1);
    
    int put=xx+yy*10;
    all=check(put,MAN,OFF);
    if(all==0){
        printf("%d,do not put",put);
        return(0);
    }
    
    else if(all){
        //printf("put,%d",put);
        check(put,MAN,ON);
        ban[put]=MAN;
        //init();
        return(put);
    
}
}
int corner(void)
    {
        int p=0;
        p=ban[11]+ban[88]+ban[81]+ban[18];
        return p;
    }
    
int xuti(void)
{
	int p=0;
	        p=ban[22]+ban[77]+ban[72]+ban[27];
	        return -p;
}
int cuti(void)
{
	int p=0;
	p=ban[12]+ban[17]+ban[21]+ban[28]+ban[71]+ban[78]+ban[82]+ban[87];
	return -p;
}

/*int enableput(void){
    int a,enb,put,i,j;
    a=0;
    for(i=1;i<=8;i++)
        for(j=1;j<=8;j++){
        	a=i+j*10;
        	if(ban[a]==COM)
        	           {
        	            	if(!ban[a-11])a++;
        	            	if(!ban[a-10])a++;
        	            	if(!ban[a-9])a++;
        	            	if(!ban[a-1])a++;
        	            	if(!ban[a+1])a++;
        	            	if(!ban[a+9])a++;
        	            	if(!ban[a+10])a++;
        	            	if(!ban[a+11])a++;
        	           }

        	if(ban[a]==MAN)
        	           {
        	            	if(!ban[a-11])a--;
        	            	if(!ban[a-10])a--;
        	            	if(!ban[a-9])a--;
        	            	if(!ban[a-1])a--;
        	            	if(!ban[a+1])a--;
        	            	if(!ban[a+9])a--;
        	            	if(!ban[a+10])a--;
        	            	if(!ban[a+11])a--;
        	           }

               }
    return(a);
}*/
int enableput(void){
int a,enb,put,i,j;
 a=enb=0;
 for(i=1;i<=8;i++)
     for(j=1;j<=8;j++){
         a=check(i+j*10,COM,OFF);
         if(a)enb++;
         else     {  a=check(i+j*10,MAN,OFF);
         if (a)enb--;
         }
     }
 return(a);
}
extern int sekisa()
{
        int x,y,tmp;
        tmp=com=man=0;
    for(y=1;y<=8;y++)
        for(x=1;x<=8;x++){
        
   /* if(y==22 || y==72 || y==27 || y==77)continue;*/
            if(ban[x+y*10]==COM){
            com++;
            }else if(ban[x+y*10]==MAN){
            man++;
        }
        }
                return (com-man);
}

extern int min_max(int level ,int alpha,int beta,int c)
{
    int ban_cpy[101];
    int sumi,j,ev,put,i,pos,all,X1,X2,X3;
    pos=put=sumi=0;
    maxe=-10000;
    X1=0;
        for (i=0;i<=100;i++)
                ban_cpy[i]=ban[i];
    c=sekisa();
    c=man+com;
    for(j=0;j<60;j++)
        {
    	 all=sumi=0;
    	 put=tbl[j];
    	 if (ban[put]!=0)continue;
    	 //if((put==11 || put==18 || put==81 || put==88) && (c<D)){sumi=1;X1=315;}
           // else if((put==22 || put==27 || put==72 || put==77) && (c<D)){
             //   sumi=1;
               // X1=-512;
            //}
              // else if((put==12 || put==17 || put==21 || put==28 || put==71 || put==78 || put==82 || put==87 )&&(c<=35)){sumi=1;X1=-253;}
                //else if((put==12 || put==17 || put==21 || put==28 || put==71 || put==78 || put==82 || put==87 )&&(c<D)){sumi=1;X1=-128;}
                
                all=check(put,COM,OFF);
            if(all){
                all=check(put,COM,ON);
                ev=min_level(OFF,level-1,alpha,beta);
                //ev+=sumi*X1;
                ev+=rand()%3;
                sumi=0;
                       if(ev>maxe){
                        maxe=ev;
                        pos=put;
                        

            }
            }for(i=11;i<89;i++)
                        ban[i]=ban_cpy[i];
               
        
        }
        printf("maxe:%d#pos:%d",maxe,pos);
    eval=maxe;
        return pos;
}
int max_level(int f,int level,int alpha,int beta)
{
        int ev,pf,i,j,all,tmp,p;
        int ban_cpy[101];
    ev=0;
    for(i=11;i<=88;i++)
    ban_cpy[i]=ban[i];
    if(level==0 && e==ON){
        ev+=evl()*7;
            tmp=sekisa();
        if(com==0){ev=-10000;return ev;}
            else if((man+com)<=D)ev-=tmp*31;
        ev+=cuti()*128;
        ev+=corner()*2048;
        ev+=xuti()*256;
            ev+=enableput()*87;
        ev+=Hen1();
        ev+=Hen2();
        return ev;
        }
        else if(level==0)  return (sekisa());
        pf=OFF;tmp=-10000;
    
                for(j=0;j<=60;j++){
                                all=0;
                             
                                p=tbl[j];
                                all=check(p,COM,OFF);
                                if(all){
                                       pf=ON;
                                        all=check(p,COM,ON);
                                
                                              tmp=min_level(OFF,level-1,alpha,beta);
                                              if(alpha<tmp) alpha=tmp;
                                for(i=11;i<89;i++)
                                ban[i]=ban_cpy[i];
                        }   
                        if(alpha>=beta) return alpha;
                        }
                                                if (pf!=OFF) return (alpha);
                        if(f==ON) return (sekisa());
                        return min_level(ON,level-1,alpha,beta);
}

int min_level(int f,int level,int alpha,int beta)
{
        int p,j,ev,pf,i,all,tmp;
        int ban_cpy[101];
    ev=0;
    for(i=11;i<=88;i++)
        ban_cpy[i]=ban[i];
    if(level==0 && e==ON){
            
            ev+=evl()*7;
    tmp=sekisa();
        if(com==0){ev=-10000;return ev;}
     else if((man+com)<D)ev-=tmp*31;
    ev+=enableput()*87;
      ev+=corner()*2048;
        ev+=xuti()*256;
        ev+=cuti()*128;
    ev+=Hen1();
    ev+=Hen2();
            return ev;
        }
    else if (level==0){
                return(sekisa());
        }
    pf=OFF;tmp=10000;
    
                for(j=0;j<=60;j++)
                        {
                                all=0;
                                p=tbl[j];
                           
                                all=check(p,MAN,OFF);
                                if(all){
                                                                                        pf=ON;
                                        all=check(p,MAN,ON);
                                      tmp=max_level(OFF,level-1,alpha,beta);
                                if(beta>tmp) beta=tmp;
                              for(i=11;i<89;i++)
                               ban[i]=ban_cpy[i];
                                }
                                if(beta<=alpha) return (beta);
                                }
                        if(pf!=OFF) return(beta);
                        if(f==ON)return (sekisa());
                        return max_level(ON,level-1,alpha,beta);
}
int min_maxf(int level ,int alpha,int beta,int c)
{
    int ban_cpy[101];
    int sumi,j,ev,put,i,pos,all;
    pos=put=sumi=0;
    maxe=-10000;
    for (i=0;i<=100;i++)
                   ban_cpy[i]=ban[i];
    for(j=0;j<60;j++)
          {
      	 all=sumi=0;
      	 put=tbl[j];
      	 if (ban[put]!=0)continue;
                all=check(put,COM,OFF);
            if(all){
                all=check(put,COM,ON);
                ev=min_levelf(OFF,level-1,alpha,beta);

                sumi=0;
                       if(ev>maxe){
                        maxe=ev;
                        pos=put;


            }
            }for(i=11;i<89;i++)
                        ban[i]=ban_cpy[i];


          }
        printf("maxe:%d#pos:%d",maxe,pos);
    eval=maxe;
        return pos;
}
int max_levelf(int f,int level,int alpha,int beta)
{
        int ev,pf,i,j,all,tmp,p;
        int ban_cpy[101];
    ev=0;
    for(i=11;i<=88;i++)
    ban_cpy[i]=ban[i];

      if(level==0)  return (sekisa());
        pf=OFF;tmp=-10000;

                for(j=0;j<=60;j++){
                                all=0;

                                p=tbl[j];
                                all=check(p,COM,OFF);
                                if(all){
                                       pf=ON;
                                        all=check(p,COM,ON);

                                              tmp=min_levelf(OFF,level-1,alpha,beta);
                                              if(alpha<tmp) alpha=tmp;
                                for(i=11;i<89;i++)
                                ban[i]=ban_cpy[i];
                        }
                        if(alpha>=beta) return alpha;
                        }
                                                if (pf!=OFF) return (alpha);
                        if(f==ON) return (sekisa());
                        return min_levelf(ON,level-1,alpha,beta);
}

int min_levelf(int f,int level,int alpha,int beta)
{
        int p,j,ev,pf,i,all,tmp;
        int ban_cpy[101];
    ev=0;
    for(i=11;i<=88;i++)
        ban_cpy[i]=ban[i];
if (level==0){
                return(sekisa());
        }
    pf=OFF;tmp=10000;

                for(j=0;j<=60;j++)
                        {
                                all=0;
                                p=tbl[j];

                                all=check(p,MAN,OFF);
                                if(all){
                                         pf=ON;
                                        all=check(p,MAN,ON);
                                      tmp=max_levelf(OFF,level-1,alpha,beta);
                                if(beta>tmp) beta=tmp;
                              for(i=11;i<89;i++)
                               ban[i]=ban_cpy[i];
                                }
                                if(beta<=alpha) return (beta);
                                }
                        if(pf!=OFF) return(beta);
                        if(f==ON)return (sekisa());
                        return max_levelf(ON,level-1,alpha,beta);
}
int kifusaisei()
{
        int i,put,a;
        char g=59;
        for (i=11;i<=88;i++)
                ban[i]=0;
        ban[44]=-1;
        ban[54]=1;
        ban[45]=-1;
        ban[55]=1;
KIFU:   for(i=0;i<=g;i++){
                put=kifu[i];
        a=check(put,COM,ON);
        init();
        a=check(put,MAN,ON);
        init();
      
        }
        goto KIFU;
}
