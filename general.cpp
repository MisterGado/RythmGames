#include "general.h"

void InitRandom()
{
    srand((unsigned int)time(0));
}

int Random(int a, int b) //randrange(a,b)
{
    return int(a + (b-a)*double(rand())/RAND_MAX);
}

int AffichageMenu(){ // retourne 1 si l'utilisateur veut jouer à Slack, 2 s'il veut jouer à Piano Tiles
    Window win = openWindow(800,400,"Test Event");
    Event ev;

    //Displaying menu's buttons
    IntPoint2 P1(250,150), P2(250,250);
    int w=300, h=50;
    IntPoint2 Q1(P1.x()+w/3,P1.y()+h*3/5);
    IntPoint2 Q2(P2.x()+w/3,P2.y()+h*3/5);
    fillRect(P1,w,h,AlphaColor(150,150,150,255));
    drawString(Q1,"SLACK",WHITE);
    fillRect(P2,w,h,Color(150,150,150));
    drawString(Q2,"PIANO TILES", WHITE);
    bool b = false;
    int k=0;

    // receiving mouse move events even if no button is pressed
    enableMouseTracking(true);
    do {
        getEvent(-1,ev); // ev becomes the next event
        switch (ev.type) {
        case EVT_NONE:
            cout << "No event" << endl;
            break;
        case EVT_MOTION: {
            int x = ev.pix.x();   // cursor's x coord
            int y = ev.pix.y();   // cursor's y coord
            // Cursor is in the "SLACK" box.
            if(P1.x()<=x && x<P1.x()+w && P1.y()<=y && y<P1.y()+h) {
                // Changing the box's style
                fillRect(P1,w,h,Color(128,139,203));
                drawString(Q1,"SLACK",YELLOW);
            } else if(P2.x()<=x && x<P2.x()+w && P2.y()<=y && y<P2.y()+h) {
                // Cursor is in the "PIANO TILES" box.
                // Changing the box's style
                fillRect(P2,w,h,Color(128,139,203));
                drawString(Q2,"PIANO TILES", YELLOW);
            } else {
                fillRect(P1,w,h,Color(150,150,150));
                drawString(Q1,"SLACK",WHITE);
                fillRect(P2,w,h,Color(150,150,150));
                drawString(Q2,"PIANO TILES", WHITE);
            }
            break;
        }
        case EVT_KEY_ON:
            cout << "Use your mouse!"<< endl;
            break;
        case EVT_BUT_ON: {
            int x = ev.pix.x();   // cursor's x coord
            int y = ev.pix.y();   // cursor's y coord
            // Click on the SLACK box
            if(P1.x()<=x && x<P1.x()+w && P1.y()<=y && y<P1.y()+h) {
                k=1;
                b = true;         // Stop the menu's loop
            }
            else if(P2.x()<=x && x<P2.x()+w && P2.y()<=y && y<P2.y()+h) {
                k=2;
                b = true;         // Stop the menu's loop
            }
            break;
       }
        default: break;
        }
    } while ((ev.type!=EVT_KEY_ON || ev.key!='q' )&& !b);
    closeWindow(win);
    return k;
}
