#include <iostream>
#include <winbgim.h>
#include<stdlib.h>
#include <graphics.h>
using namespace std;

int stanga,sus,width,height,latura,color,dimension,d,mouseclickOK=0,xMouseCurrent,yMouseCurrent,ok2;
bool gameover,startkey,endkey,rulekey,onekey,twokey;
struct Coordonate
{
    int xGobblet,yGobblet,xGobbletjos,yGobbletjos;
} C[12];
struct BoardPlace
{
    int v[3]; // indicii sunt dimensiunea iar valorile sunt culoarea; daca v[i] e 0 inseamna ca nu este nicio piesa de dimensiunea i pe acea pozitie
}a[4][4];
void menu(bool& startkey,bool &endkey,bool &rulekey,bool &onekey,bool &twokey)
{
    sndPlaySound(TEXT("cute.wav"),SND_ASYNC);
    readimagefile("pozic2.jpg",0,0,700,700);
    int mx,my,x,y;
    startkey=0,endkey=0,rulekey=0,onekey=0,twokey=0;//butoanele pentru menu
    x=getmaxx();//coordonatele mijlocului feretrei
    y=getmaxy();
    settextstyle(10,HORIZ_DIR,2);
    setfillstyle(EMPTY_FILL,14);
    bar3d(240,297,388,338,4,1);
    outtextxy(285,306,"START");
    //setfillstyle(11,14);
    bar3d(240,338+15,388,338+15+41,4,1);
    outtextxy(242,338+15+9,"GAME'S RULES");

    bar3d(240,409,388,409+41,4,1);
    outtextxy(289,409+9,"EXIT");


    while(!startkey&&!endkey&&!rulekey)
    {

        if(ismouseclick(WM_LBUTTONDOWN))
        {

            sndPlaySound(TEXT("buton1.wav"),SND_SYNC);
            sndPlaySound(TEXT("cute.wav"),SND_ASYNC);
            //sndPlaySound(TEXT("fundal.wav"),SND_ASYNC);
            clearmouseclick(WM_LBUTTONDOWN);
            mx=mousex();
            my=mousey();

            if(mx>240&&mx<388&&my>297&&my<338)
            {
                setfillstyle(EMPTY_FILL,14);
                bar(240,297,388,338);
                outtextxy(285-3,306,"START");
                delay(200);
                //setfillstyle(11,14);
                bar3d(240,297,388,338,4,1);
                outtextxy(285,306,"START");
                delay(200);
                //cleardevice();
                startkey=1;
            }
        }
        else
        {

            if(mx>240&&mx<388&&my>338+15&&my<338+15+41)
            {
                setfillstyle(EMPTY_FILL,14);
                bar(240,338+15,388,338+15+41);
                outtextxy(242-3,338+15+9,"GAME'S RULES");
                delay(200);
                bar3d(240,338+15,388,338+15+41,4,1);
                outtextxy(242,338+15+9,"GAME'S RULES");
                delay(200);
                cleardevice();
                rulekey=1;
            }
            else if(mx>240&&mx<388&&my>409&&my<409+41)
            {
                setfillstyle(EMPTY_FILL,14);
                bar(240,409,388,409+41);
                outtextxy(289-3,409+9,"EXIT");
                delay(200);
                bar3d(240,409,388,409+41,4,1);
                outtextxy(289,409+9,"EXIT");
                delay(200);
                cleardevice();
                endkey=1;
            }
        }

    }

    if(startkey)
    {
        setfillstyle(EMPTY_FILL,14);
        bar3d(240,297,388,338,4,1);
        outtextxy(285,306,"START");
        //setfillstyle(11,14);
        bar3d(240,338+15,388,338+15+41,4,1);
        outtextxy(255,338+15+9,"ONE PLAYER");

        bar3d(240,409,388,409+41,4,1);
        outtextxy(247,409+9,"TWO PLAYERS");

        bar3d(240,409+56,388,409+56+41,4,1);
        outtextxy(242,409+56+9,"GAME'S RULES");

        bar3d(240,409+56+56,388,409+56+56+41,4,1);
        outtextxy(289,409+56+56+9,"EXIT");

        while(!onekey&&!twokey&&!endkey&&!rulekey)
        {
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                sndPlaySound(TEXT("buton1.wav"),SND_SYNC);
                sndPlaySound(TEXT("cute.wav"),SND_ASYNC);
                clearmouseclick(WM_LBUTTONDOWN);
                mx=mousex();
                my=mousey();

                if(mx>240&&mx<388&&my>297&&my<338)
                {
                    setfillstyle(EMPTY_FILL,14);
                    bar(240,297,388,338);
                    outtextxy(285-3,306,"START");
                    delay(200);
                    //setfillstyle(11,14);
                    bar3d(240,297,388,338,4,1);
                    outtextxy(285,306,"START");
                    delay(200);
                    //cleardevice();
                    //startkey=1;
                }
                else
                {
                    if(mx>240&&mx<388&&my>338+15&&my<338+15+41)
                    {
                        setfillstyle(EMPTY_FILL,14);
                        bar(240,338+15,388,338+15+41);
                        outtextxy(255-3,338+15+9,"ONE PLAYER");
                        delay(200);
                        bar3d(240,338+15,388,338+15+41,4,1);
                        outtextxy(255,338+15+9,"ONE PLAYER");
                        delay(200);
                        cleardevice();
                        onekey=1;
                    }
                    else
                    {
                        if(mx>240&&mx<388&&my>409&&my<409+41)
                        {
                            setfillstyle(EMPTY_FILL,14);
                            bar(240,409,388,409+41);
                            outtextxy(247-3,409+9,"TWO PLAYERS");
                            delay(200);
                            bar3d(240,409,388,409+41,4,1);
                            outtextxy(247,409+9,"TWO PLAYERS");
                            delay(200);
                            cleardevice();
                            twokey=1;
                        }
                        else
                        {
                            if(mx>240&&mx<388&&my>409+56&&my<409+56+41)
                            {
                                setfillstyle(EMPTY_FILL,14);
                                bar(240,409+56,388,409+56+41);
                                outtextxy(242-3,409+56+9,"GAME'S RULES");
                                delay(200);
                                bar3d(240,409+56,388,409+56+41,4,1);
                                outtextxy(242,409+56+9,"GAME'S RULES");
                                delay(200);
                                cleardevice();
                                rulekey=1;
                            }
                            else if(mx>240&&mx<388&&my>409+56+56&&my<409+56+56+41)
                            {
                                setfillstyle(EMPTY_FILL,14);
                                bar(240,409+56+56,388,409+56+56+41);
                                outtextxy(289-3,409+56+56+9,"EXIT");
                                delay(200);
                                bar3d(240,409+56+56,388,409+56+56+41,4,1);
                                outtextxy(289/**<  */,409+56+56+9,"EXIT");
                                delay(200);
                                cleardevice();
                                endkey=1;
                            }

                        }
                    }
                }

            }

        }
    }
    if(rulekey)
    {
        readimagefile("fundalmenu2.jpg",0,0,700,700);
        bool click=0;
        while(!click)
        {
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                PlaySound(TEXT("buton1.wav"),NULL,SND_SYNC);
                clearmouseclick(WM_LBUTTONDOWN);
                mx=mousex();
                my=mousey();
            }
            if(mx>16&&mx<51&&my>16&&my<49)
            {
                click=1;
            }

        }menu(startkey,endkey,rulekey,onekey,twokey);
    }
}
void CoordinatesGobblets() //Gobblets that have to be placed on the board
{
    width=400;
    height=400;
    latura=width/3;
    sus=(getmaxy()-width)/2;
    stanga=(getmaxx()-height)/2;
    for(int i=0;i<=2;i++)
    {
        C[i].xGobblet=24-i*12; C[i+3].xGobblet=stanga/2+C[i].xGobblet;
        C[i+6].xGobblet=stanga+width+C[i].xGobblet; C[i+9].xGobblet=stanga+width+C[i+3].xGobblet;
        C[i].yGobblet=C[i+3].yGobblet=C[i+6].yGobblet=C[i+9].yGobblet=180+110*i;

    }
    for(int i=0;i<=9;i+=3)
    {
        C[i].xGobbletjos=C[i].xGobblet+42; //latimea mica
        C[i+1].xGobbletjos=C[i+1].xGobblet+51;// latimea medie
        C[i+2].xGobbletjos=C[i+2].xGobblet+68; //latimea mare

        C[i].yGobbletjos=C[i].yGobblet+82; //lungimea mica
        C[i+1].yGobbletjos=C[i+1].yGobblet+99;// lungimea medie
        C[i+2].yGobbletjos=C[i+2].yGobblet+131; //lungimea mare
    }


}
void draw() //deseneaza tot ce este afisat pe ecran initial
{


    //sndPlaySound(TEXT("cookie.wav"),SND_SYNC);

    sndPlaySound(TEXT("fundal.wav"),SND_ASYNC);
    //draw Board
    for(int i=1; i<=3; i++)
        for(int j=1; j<=3; j++)
        {   setcolor(COLOR(5,5,1));
            rectangle(stanga+latura*(i-1),sus+latura*(j-1),stanga+latura*i,sus+latura*j);
            setfillstyle(SOLID_FILL,COLOR(221,195,12));
            floodfill(stanga+latura*(i-1)+1,sus+latura*(j-1)+1,COLOR(5,5,1));
        }


    setcolor(COLOR(114,205,234));
    outtextxy(20,100,"First Player's ");
    outtextxy(25,120,"Gobblets ");
    for(int i=0; i<=5; i++)
        readimagefile("blue-blackBK.jpg",C[i].xGobblet,C[i].yGobblet,C[i].xGobbletjos,C[i].yGobbletjos);




    setcolor(12);
    outtextxy(515,100,"Second Player's ");
    outtextxy(590,120,"Gobblets ");
        for(int i=6; i<=11; i++)
        readimagefile("orange-blackBK.jpg",C[i].xGobblet,C[i].yGobblet,C[i].xGobbletjos,C[i].yGobbletjos);



}
void showWhichPlayerStarts()
{
    if(color==1)
    {
        outtextxy(200,40,"                                                                                                           ");
        setcolor(COLOR(114,205,234));
        outtextxy(230,40,"Blue color's turn");
    }
    else
        {
            outtextxy(200,40,"                                                                                                           ");
        setcolor(12);
        outtextxy(215,40,"Orange color's turn");
    }
}

void wait_for_left_click()
{
    const int DELAY = 50; // Milliseconds of delay between checks

    while (!ismouseclick(WM_LBUTTONDOWN))
        delay(DELAY);
    getmouseclick(WM_LBUTTONDOWN, xMouseCurrent, yMouseCurrent);
    clearmouseclick(WM_LBUTTONDOWN);
}

int findLastGobbletDimension(BoardPlace a[4][4],int i,int j)
{
    for(int k=2;k>=0;k--)
        if(a[i][j].v[k]!=0)
        return k;
    return 0;
}
int findLastGobbletColor(BoardPlace a[4][4],int i,int j)
{
    for(int k=2;k>=0;k--)
        if(a[i][j].v[k]!=0)
        return a[i][j].v[k];
    return 0;
}
void drawGobbletOnBoard() //deseneaza pe locul apasat gobbletul selectat
{
    int linia,coloana;


    //select the Gobblet's position
    linia=(yMouseCurrent-sus)/latura+1;
    coloana=(xMouseCurrent-stanga)/latura+1;
    if(color==1)
        {
            a[linia][coloana].v[dimension]=1;
            if(dimension==0)
            readimagefile("blue-yellowBK.jpg",stanga+latura*(coloana-1)+latura/2-42/2,sus+latura*(linia-1)+latura/2-82/2,
                                        stanga+latura*(coloana-1)+latura/2+42/2, sus+latura*(linia-1)+latura/2+82/2);
        else if(dimension==1)
            readimagefile("blue-yellowBK.jpg",stanga+latura*(coloana-1)+latura/2-51/2,sus+latura*(linia-1)+latura/2-99/2,
                                        stanga+latura*(coloana-1)+latura/2+51/2, sus+latura*(linia-1)+latura/2+99/2);
        else if(dimension==2)
            readimagefile("blue-yellowBK.jpg",stanga+latura*(coloana-1)+latura/2-68/2,sus+latura*(linia-1)+latura/2-131/2,
                                        stanga+latura*(coloana-1)+latura/2+68/2, sus+latura*(linia-1)+latura/2+131/2);
        }

        else if(color==2)
        {
            a[linia][coloana].v[dimension]=2;
            if(dimension==0)
            readimagefile("orange-yellowBK.jpg",stanga+latura*(coloana-1)+latura/2-42/2,sus+latura*(linia-1)+latura/2-82/2,
                                        stanga+latura*(coloana-1)+latura/2+42/2, sus+latura*(linia-1)+latura/2+82/2);
        else if(dimension==1)
            readimagefile("orange-yellowBK.jpg",stanga+latura*(coloana-1)+latura/2-51/2,sus+latura*(linia-1)+latura/2-99/2,
                                        stanga+latura*(coloana-1)+latura/2+51/2, sus+latura*(linia-1)+latura/2+99/2);
        else if(dimension==2)
            readimagefile("orange-yellowBK.jpg",stanga+latura*(coloana-1)+latura/2-68/2,sus+latura*(linia-1)+latura/2-131/2,
                                        stanga+latura*(coloana-1)+latura/2+68/2, sus+latura*(linia-1)+latura/2+131/2);
        }

}
void verif() //PENTRU CASTIG
{
    int nr;
    nr=0;
    int A[4][4]={0};  //culoarea celui mai mare gobblet de pe fiecare loc de pe tabla
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
        A[i][j]=findLastGobbletColor(a,i,j);

    for(int i=1; i<=3; i++)
        if(A[i][1]==A[i][2] && A[i][2]==A[i][3] &&A[i][1]!=0)
            {gameover=1;color=A[i][1];}
        else if(A[1][i]==A[2][i] && A[2][i]==A[3][i]&&A[1][i]!=0)
            {gameover=1;color=A[1][i];}
    if(!gameover)
    {
        if(A[1][1]==A[2][2] &&A[2][2]==A[3][3]&&A[1][1]!=0)
            {gameover=1; color=A[1][1];}
        else if(A[1][3]==A[2][2] &&A[2][2]==A[3][1]&&A[3][1]!=0)
            {gameover=1; color=A[1][3];}

    }

}

void whoWins()
{
    outtextxy(200,40,"                                                  ");
    if(gameover==1)
        {
            if(color==1)
                {   setcolor(COLOR(114,205,234));
                sndPlaySound(TEXT("kids.wav"),SND_ASYNC);
                    outtextxy(250,40,"BLUE COLOR WON"); delay(2000);

                }
            else
                {setcolor(12);
                sndPlaySound(TEXT("kids.wav"),SND_ASYNC);
                    outtextxy(250,40,"ORANGE COLOR WON"); delay(2000);
                }
        }

}
void replayOrExit()
{
    cleardevice(); clearmouseclick(WM_LBUTTONDOWN);
    setcolor(COLOR(161, 238, 212));
    bar3d(240,309,388,309+41,4,1);
        setfillstyle(SOLID_FILL,COLOR(5, 5, 1));
        floodfill(241,310,COLOR(161, 238, 212));
        outtextxy(289,309+9,"REPLAY");

    setcolor(COLOR(255, 0, 0));
    bar3d(240,355,388,355+41,4,1);
        setfillstyle(SOLID_FILL,COLOR(255, 0, 0));
        floodfill(241,356,COLOR(5, 5, 1));
        outtextxy(310,355+9,"EXIT");

    wait_for_left_click(); sndPlaySound(TEXT("buton1.wav"),SND_SYNC);
    if(xMouseCurrent<=388 && xMouseCurrent>=240 &&yMouseCurrent<=309+41&&yMouseCurrent>=309)
        {

            gameover=0; cleardevice();
            for(int i=1;i<=3;i++)
                for(int j=1;j<=3;j++)
                for(int k=0;k<=2;k++)
                a[i][j].v[k]=0;
                ok2=1;
        }
    else if(xMouseCurrent<=388 && xMouseCurrent>=240 &&yMouseCurrent<=355+41&&yMouseCurrent>=355)
        closegraph();





}
int isMouseClickOnBoard()
{//rectangle(stanga+latura*(i-1),sus+latura*(j-1),stanga+latura*i,sus+latura*j);
    if(!(xMouseCurrent>=stanga&&xMouseCurrent<=stanga+latura*3&&yMouseCurrent>=sus&&yMouseCurrent<=sus+latura*3))
    {
        return 0;
    }
    int linia,coloana;
    linia=(yMouseCurrent-sus)/latura+1;
    coloana=(xMouseCurrent-stanga)/latura+1;
    int dim=findLastGobbletDimension(a,linia,coloana);
    int col=findLastGobbletColor(a,linia,coloana);
    if(col==color) //daca este randul jucatorului
    {

                        //delete the clicked gobblet
                        a[linia][coloana].v[dim]=0;
                        setcolor(COLOR(221,195,12));
                        setfillstyle(SOLID_FILL,COLOR(221,195,12));
                        floodfill(stanga+latura*(coloana-1)+1,sus+latura*(linia-1)+1,COLOR(5,5,1));

                    //draw the gobblet that was under the selected gobblet
                    dimension=findLastGobbletDimension(a,linia,coloana);
                    color=findLastGobbletColor(a,linia,coloana);
                    drawGobbletOnBoard();


                    verif();
                    if(gameover==1) { whoWins();return 1;}

                    //restore the current dimension and color
                    dimension=dim;
                    color=col;
                    return 1;

    }


    return 0;


}

int isMouseClickInteriorGobblet()
{


    for(int i=0; i<=11; i++)
        if(C[i].xGobblet>=0 &&(xMouseCurrent<=(C[i].xGobbletjos)) &&( xMouseCurrent>=(C[i].xGobblet))  )
            if(yMouseCurrent<=C[i].yGobbletjos && yMouseCurrent>=C[i].yGobblet  )
                if((xMouseCurrent<=150 && color==1 )||(xMouseCurrent>=550 && color==2))
            {
                if(i%3==0)
                dimension=0;
                else if(i%3==1) dimension=1;
                    else dimension=2;//salvarea dimensiunii
                setcolor(COLOR(5,5,1));
                setfillstyle(SOLID_FILL,COLOR(5,5,1));
                rectangle(C[i].xGobblet,C[i].yGobblet,C[i].xGobbletjos,C[i].yGobbletjos); //disparitia  gobbletului selectat

                floodfill(C[i].xGobblet+1,C[i].yGobblet+1,COLOR(5,5,1));
                C[i].xGobblet=-C[i].xGobblet;
                 return 1;

            }

    return 0;
}
void selectCircle() //textfundal
{
    if(!isMouseClickInteriorGobblet()&&!isMouseClickOnBoard())
    {
        setcolor(RED);
        outtextxy(180,40,"Select the dimension of the gobblet");
        delay(700);
        outtextxy(180,40,"                                                                                                           ");
        showWhichPlayerStarts();


    }
    else if(gameover==1) exit(0);
        else
        mouseclickOK=1;

}
void place()
{
    int linia,coloana;

    verif();
                    if(gameover==1) { whoWins();exit(0);}
    //select the Gobblet's position
    linia=(yMouseCurrent-sus)/latura+1;
    coloana=(xMouseCurrent-stanga)/latura+1;

    if (xMouseCurrent>=stanga && xMouseCurrent<=stanga+width && yMouseCurrent>=sus &&yMouseCurrent<=sus+height )
    {if((!a[linia][coloana].v[0]&&!a[linia][coloana].v[1]&&!a[linia][coloana].v[2])||findLastGobbletDimension(a,linia,coloana)<dimension)

        {
            drawGobbletOnBoard();

        }
    else {
            setfillstyle(SOLID_FILL,RED);
            int dimension2=dimension;
            int color2=color;
            floodfill(xMouseCurrent,yMouseCurrent,COLOR(5,5,1));
            setcolor(RED);
            outtextxy(50,40,"The gobblet must be smaller. Choose a different place!");
            delay(2000);
            setfillstyle(SOLID_FILL,COLOR(221,195,12));
            floodfill(xMouseCurrent,yMouseCurrent,COLOR(5,5,1));
            outtextxy(50,40,"                                                         ");
            showWhichPlayerStarts();
            dimension=findLastGobbletDimension(a,linia,coloana);
            color=findLastGobbletColor(a,linia,coloana);
            drawGobbletOnBoard();
            dimension=dimension2;
            color=color2;
            wait_for_left_click();
            place();


    }

}
}

int main()
{
    initwindow(700,700,"",0,0);
    menu(startkey,endkey,rulekey,onekey,twokey);
    if(endkey)
    {
        return 0;
    }
    if(twokey)
    do
    {
        clearmouseclick(WM_LBUTTONDOWN);
        CoordinatesGobblets(); //set all the coordinates of the Gobblets
        draw();
        gameover=false;
        color=1; //blue color will start
        do
        {
            showWhichPlayerStarts();
            clearmouseclick(WM_LBUTTONDOWN);
            mouseclickOK=0;
            do
            {
                wait_for_left_click(); //select the gobblet you want to place on the table
                selectCircle();
            } while(!mouseclickOK); //continue the loop until the player selects a gobblet

            wait_for_left_click(); //select  the place on the table you want to put the gobblet
            place(); //place it
            verif(); //verify if someone already won
            delay(200);
            if(color==1) color=2;
            else color=1;
        }while(!gameover); //continue the loop until somebody wins
        if(color==1) color=2;
            else color=1;
        whoWins();
        replayOrExit(); //if you press the replay button, the game will start again

    }while(!gameover);
}
