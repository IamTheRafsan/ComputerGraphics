
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>

float r = 10.0;
float f = 70.0;
float t = 0.0005;
float c = 90.0;
float c2 = 90.0;
float mp = 830;
float v = 880;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
    glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
    glLoadIdentity();
    glOrtho(0.0, 1000.0, 0.0, 500.0, -1.0, 1.0); // Left, Right, Bottom, Top, Near, Far
    // glOrtho(0.0, 100.0, 0.0, 50.0, -1.0, 1.0); // Left, Right, Bottom, Top, Near, Far
    //gluOrtho2D(0.0,300.0,0.0,300.0); // Left, Right, Bottom, Top, Near, Far
}
void renderBitmapString(float x, float y, void *font, const char *string) {
    glRasterPos2f(x, y);
    while (*string) {
        glutBitmapCharacter(font, *string);
        string++;
    }
}
float rgb(float rgb)
{
    float x = rgb / 255;
    return floorf(x * 100) / 100;
}


void Draw()

{
    // moving objects-----------------
    if (r <= 1000)
    {
        r = r + 0.07;
        f = f + t;
        t = t + 0.000003;

        // r = r + 0.5;
        // f = f + t;
        // t = t + 0.0001;
        // p = p + 0.001;
    }
    else {
        r = -200;
        f = 70;
        t = 0.0005;


    }
    if (c <= 1000)
    {
        // c = c + 0.1;
        c = c + 0.01;
    }
    else {
        c = -50;
    }
    if (c2 <= 1000)
    {
        // c2 = c2 + 0.1;
        c2 = c2 + 0.01;
    }
    else {
        c2 = -500;
    }
    if (mp >= -100)
    {
        // c2 = c2 + 0.1;
        mp = mp - 0.1;
    }
    else {
        mp = 2000;
    }
    if (v >= -100)
    {
        // c2 = c2 + 0.1;
        v = v - 0.02;
    }
    else {
        v = 2000;
    }


    glutPostRedisplay();

    // ===================================
    glClear(GL_COLOR_BUFFER_BIT);

    // drawing sky==================================================
    glBegin(GL_QUADS);
    glColor3f(rgb(228), rgb(247), rgb(254));
    glVertex2i(0, 100);
    glVertex2i(1000, 100);

    glColor3f(rgb(47), rgb(199), rgb(236));
    glVertex2i(1000, 500);
    glVertex2i(0, 500);
    glEnd();
    // drawing building
    glBegin(GL_QUADS);
    glColor3f(rgb(103), rgb(202), rgb(221));
    glVertex2f(870, 250);
    glVertex2f(920, 250);
    glVertex2f(920, 270);
    glVertex2f(870, 270);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(175), rgb(201), rgb(213));
    glVertex2f(870, 270);
    glVertex2f(920, 270);
    glVertex2f(920, 280);
    glVertex2f(870, 280);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(109), rgb(137), rgb(144));
    glVertex2f(620, 250);
    glVertex2f(940, 230);
    glVertex2f(940, 250);
    glVertex2f(620, 270);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(rgb(175), rgb(182), rgb(184));
    glVertex2f(720, 180);
    glVertex2f(920, 231);
    glVertex2f(620, 251);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(rgb(211), rgb(157), rgb(61));
    glVertex2f(720, 232);
    glVertex2f(920, 220);
    glVertex2f(920, 232);
    glVertex2f(720, 244);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(rgb(128), rgb(184), rgb(218));
    glVertex2f(720, 100);
    glVertex2f(920, 100);
    glVertex2f(920, 220);
    glVertex2f(720, 232);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(rgb(220), rgb(242), rgb(247));
    glVertex2f(740, 110);
    glVertex2f(810, 110);
    glVertex2f(810, 200);
    glVertex2f(740, 200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(rgb(220), rgb(242), rgb(247));
    glVertex2i(830, 110);
    glVertex2i(900, 110);
    glVertex2i(900, 200);
    glVertex2i(830, 200);
    glEnd();

    // glass window---------------------------------------
    glBegin(GL_QUADS);
    glColor3f(rgb(143), rgb(198), rgb(218));
    glVertex2f(750, 120);
    glVertex2f(770, 120);
    glVertex2f(770, 130);
    glVertex2f(750, 130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(143), rgb(198), rgb(218));
    glVertex2f(750, 140);
    glVertex2f(770, 140);
    glVertex2f(770, 150);
    glVertex2f(750, 150);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(143), rgb(198), rgb(218));
    glVertex2f(750, 160);
    glVertex2f(770, 160);
    glVertex2f(770, 170);
    glVertex2f(750, 170);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(143), rgb(198), rgb(218));
    glVertex2f(750, 180);
    glVertex2f(770, 180);
    glVertex2f(770, 190);
    glVertex2f(750, 190);
    glEnd();

    // --------------
    glBegin(GL_QUADS);
    glColor3f(rgb(143), rgb(198), rgb(218));
    glVertex2f(780, 120);
    glVertex2f(800, 120);
    glVertex2f(800, 130);
    glVertex2f(780, 130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(143), rgb(198), rgb(218));
    glVertex2f(780, 140);
    glVertex2f(800, 140);
    glVertex2f(800, 150);
    glVertex2f(780, 150);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(143), rgb(198), rgb(218));
    glVertex2f(780, 160);
    glVertex2f(800, 160);
    glVertex2f(800, 170);
    glVertex2f(780, 170);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(143), rgb(198), rgb(218));
    glVertex2f(780, 180);
    glVertex2f(800, 180);
    glVertex2f(800, 190);
    glVertex2f(780, 190);
    glEnd();

    // 2nd part glass window
    glBegin(GL_QUADS);
    glColor3f(rgb(143), rgb(198), rgb(218));
    glVertex2f(840, 120);
    glVertex2f(860, 120);
    glVertex2f(860, 130);
    glVertex2f(840, 130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(143), rgb(198), rgb(218));
    glVertex2f(840, 140);
    glVertex2f(860, 140);
    glVertex2f(860, 150);
    glVertex2f(840, 150);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(143), rgb(198), rgb(218));
    glVertex2f(840, 160);
    glVertex2f(860, 160);
    glVertex2f(860, 170);
    glVertex2f(840, 170);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(143), rgb(198), rgb(218));
    glVertex2f(840, 180);
    glVertex2f(860, 180);
    glVertex2f(860, 190);
    glVertex2f(840, 190);
    glEnd();
    // --------------
    glBegin(GL_QUADS);
    glColor3f(rgb(143), rgb(198), rgb(218));
    glVertex2f(870, 120);
    glVertex2f(890, 120);
    glVertex2f(890, 130);
    glVertex2f(870, 130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(143), rgb(198), rgb(218));
    glVertex2f(870, 140);
    glVertex2f(890, 140);
    glVertex2f(890, 150);
    glVertex2f(870, 150);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(143), rgb(198), rgb(218));
    glVertex2f(870, 160);
    glVertex2f(890, 160);
    glVertex2f(890, 170);
    glVertex2f(870, 170);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(143), rgb(198), rgb(218));
    glVertex2f(870, 180);
    glVertex2f(890, 180);
    glVertex2f(890, 190);
    glVertex2f(870, 190);
    glEnd();

    // signbord
    glBegin(GL_QUADS);
    glColor3f(rgb(143), rgb(198), rgb(218));
    glVertex2f(630, 290);
    glVertex2f(765, 290);
    glVertex2f(765, 320);
    glVertex2f(630, 320);
    glEnd();
    // line
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(650, 290);
    glVertex2f(650, 268);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(745, 290);
    glVertex2f(745, 262);
    glEnd();

    // Title
    glColor3f(0,0,0);
    renderBitmapString(640, 300, GLUT_BITMAP_TIMES_ROMAN_24, "SkyGate Airport");

    // ------------
    glBegin(GL_QUADS);
    glColor3f(rgb(3), rgb(199), rgb(219));
    glVertex2f(670, 100);
    glVertex2f(720, 100);
    glVertex2f(720, 110);
    glVertex2f(670, 110);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(200), rgb(233), rgb(242));
    glVertex2f(680, 110);
    glVertex2f(690, 110);
    glColor3f(rgb(201), rgb(234), rgb(243));
    glVertex2f(670, 240);
    glVertex2f(650, 240);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(200), rgb(233), rgb(242));
    glVertex2i(700, 110);
    glVertex2i(710, 110);
    glColor3f(rgb(201), rgb(234), rgb(243));
    glVertex2i(710, 230);
    glVertex2i(690, 230);
    glEnd();

    // ==============mini signbord
    glBegin(GL_QUADS);
    glColor3f(rgb(143), rgb(198), rgb(218));
    glVertex2i(580, 120);
    glVertex2i(620, 120);
    glVertex2i(620, 140);
    glVertex2i(580, 140);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(590, 100);
    glVertex2f(590, 120);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(610, 100);
    glVertex2f(610, 120);
    glEnd();

    // Title
    glColor3f(0,0,0);
    renderBitmapString(585, 125, GLUT_BITMAP_HELVETICA_12, "Caution");

    glBegin(GL_QUADS);
    glColor3f(rgb(238), rgb(154), rgb(32));
    glVertex2i(630, 140);
    glVertex2i(640, 140);
    glVertex2i(640, 170);
    glVertex2i(630, 170);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(640, 100);
    glVertex2f(640, 170);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(rgb(238), rgb(154), rgb(32));
    glVertex2i(930, 110);
    glVertex2i(940, 110);
    glVertex2i(940, 130);
    glVertex2i(930, 130);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(930, 130);
    glVertex2f(930, 100);
    glEnd();
    // =========================================
     // Drawing cloud-----------------------------------------


    glColor3f(0.5f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(c, 400);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 20 * cosf(angle);
        float y = 20 * sinf(angle);
        glVertex2f(x + c, y + 400);
    }
    glEnd();


    glColor3f(0.5f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(c + 30, 410);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 20 * cosf(angle);
        float y = 20 * sinf(angle);
        glVertex2f(x + c + 30, y + 410);
    }
    glEnd();

    glColor3f(0.5f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(c + 60, 400);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 20 * cosf(angle);
        float y = 20 * sinf(angle);
        glVertex2f(x + c + 60, y + 400);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 1.0f, 1.0f);
    glVertex2i(c, 380);
    glVertex2i(c + 60, 380);
    glVertex2i(c + 60, 400);
    glVertex2i(c, 400);
    glEnd();

    // mini cloud-----------------------------------
    glColor3f(0.5f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(c2 + 530, 470);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 15 * cosf(angle);
        float y = 15 * sinf(angle);
        glVertex2f(x + c2 + 530, y + 470);
    }
    glEnd();
    glColor3f(0.5f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(c2 + 550, 470);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 15 * cosf(angle);
        float y = 15 * sinf(angle);
        glVertex2f(x + c2 + 550, y + 470);
    }
    glEnd();
    glColor3f(0.5f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(c2 + 540, 480);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 15 * cosf(angle);
        float y = 15 * sinf(angle);
        glVertex2f(x + c2 + 540, y + 480);
    }
    glEnd();
    glColor3f(0.5f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(c2 + 570, 470);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 15 * cosf(angle);
        float y = 15 * sinf(angle);
        glVertex2f(x + c2 + 570, y + 470);
    }
    glEnd();
    glColor3f(0.5f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(c2 + 560, 480);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 15 * cosf(angle);
        float y = 15 * sinf(angle);
        glVertex2f(x + c2 + 560, y + 480);
    }
    glEnd();

    // ======================================
    // || mini Plane ||
    // ======================================
    // tail
    glBegin(GL_POLYGON);
    glColor3f(rgb(35), rgb(50), rgb(64));
    glVertex2i(mp + 70, 440);
    glVertex2i(mp + 100, 440);
    glVertex2i(mp + 100, 460);
    glVertex2i(mp + 90, 450);
    glVertex2i(mp + 80, 450);
    glVertex2i(mp + 80, 450);
    glEnd();
    // body
    glBegin(GL_POLYGON);
    glColor3f(rgb(65), rgb(86), rgb(111));
    glVertex2i(mp, 420);
    glVertex2i(mp + 80, 420);
    glVertex2i(mp + 100, 440);
    glVertex2i(mp + 30, 440);
    glVertex2i(mp + 30, 430);
    glVertex2i(mp + 10, 430);
    glEnd();
    // cokepit
    glBegin(GL_POLYGON);
    glColor3f(rgb(166), rgb(214), rgb(252));
    glVertex2i(mp + 20, 430);
    glVertex2i(mp + 30, 430);
    glVertex2i(mp + 30, 440);
    glEnd();
    // backline
    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3f(rgb(166), rgb(214), rgb(252));
    glVertex2f(mp + 80, 440);
    glVertex2f(mp + 110, 440);
    glEnd();
    // fan
    glBegin(GL_POLYGON);
    glColor3f(rgb(35), rgb(50), rgb(64));
    glVertex2i(mp + 40, 410);
    glVertex2i(mp + 60, 410);
    glVertex2i(mp + 70, 420);
    glVertex2i(mp + 60, 430);
    glVertex2i(mp + 40, 430);
    glEnd();
    
    // =====================================
    // drawing tower
    // =====================================
    glBegin(GL_QUADS);
    glColor3f(rgb(92), rgb(141), rgb(148));
    glVertex2f(520, 100);
    glVertex2f(550, 100);
    glVertex2f(550, 240);
    glVertex2f(520, 240);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(rgb(198), rgb(226), rgb(227));
    glVertex2f(530, 110);
    glVertex2f(540, 110);
    glVertex2f(540, 130);
    glVertex2f(530, 130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(198), rgb(226), rgb(227));
    glVertex2f(530, 140);
    glVertex2f(540, 140);
    glVertex2f(540, 160);
    glVertex2f(530, 160);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(198), rgb(226), rgb(227));
    glVertex2f(530, 170);
    glVertex2f(540, 170);
    glVertex2f(540, 190);
    glVertex2f(530, 190);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(198), rgb(226), rgb(227));
    glVertex2f(530, 200);
    glVertex2f(540, 200);
    glVertex2f(540, 220);
    glVertex2f(530, 220);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(rgb(101), rgb(203), rgb(224));
    glVertex2f(510, 240);
    glVertex2f(560, 240);
    glVertex2f(560, 250);
    glVertex2f(510, 250);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(173), rgb(184), rgb(186));
    glVertex2f(520, 250);
    glVertex2f(550, 250);
    glVertex2f(590, 280);
    glVertex2f(480, 280);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(241), rgb(161), rgb(36));
    glVertex2f(480, 280);
    glVertex2f(590, 280);
    glVertex2f(590, 310);
    glVertex2f(480, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(198), rgb(226), rgb(227));
    glVertex2f(490, 285);
    glVertex2f(580, 285);
    glVertex2f(580, 305);
    glVertex2f(490, 305);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(78), rgb(187), rgb(221));
    glVertex2f(480, 310);
    glVertex2f(590, 310);
    glVertex2f(550, 320);
    glVertex2f(520, 320);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(78), rgb(187), rgb(221));
    glVertex2f(520, 320);
    glVertex2f(550, 320);
    glVertex2f(550, 330);
    glVertex2f(520, 330);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(530, 379);
    glVertex2f(530, 410);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(540, 379);
    glVertex2f(540, 430);
    glEnd();
    // circle
    glColor3f(rgb(92), rgb(141), rgb(148));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(535, 360); // circle er center position
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 20 * cosf(angle); // value ta radius
        float y = 20 * sinf(angle);  // value ta radius
        glVertex2f(x + 535, y + 360); // .. + circle er center position
    }
    glEnd();
    // mini circle--1
    glColor3f(rgb(92), rgb(141), rgb(148));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(540, 430); // circle er center position
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 5 * cosf(angle); // value ta radius
        float y = 5 * sinf(angle);  // value ta radius
        glVertex2f(x + 540, y + 430); // .. + circle er center position
    }
    glEnd();
    // mini circle--2
    glColor3f(rgb(255), rgb(141), rgb(148));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(530, 410); // circle er center position
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 5 * cosf(angle); // value ta radius
        float y = 5 * sinf(angle);  // value ta radius
        glVertex2f(x + 530, y + 410); // .. + circle er center position
    }
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(173), rgb(184), rgb(186));
    glVertex2f(520, 330);
    glVertex2f(550, 330);
    glVertex2f(560, 350);
    glVertex2f(510, 350);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(241), rgb(161), rgb(36));
    glVertex2f(510, 350);
    glVertex2f(560, 350);
    glVertex2f(560, 360);
    glVertex2f(510, 360);
    glEnd();

    // ================================
    // drawing runway
    // ================================
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(0, 50);
    glVertex2f(50, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(100, 50);
    glVertex2f(150, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(200, 50);
    glVertex2f(250, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(300, 50);
    glVertex2f(350, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(400, 50);
    glVertex2f(450, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(500, 50);
    glVertex2f(550, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(600, 50);
    glVertex2f(650, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(700, 50);
    glVertex2f(750, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(800, 50);
    glVertex2f(850, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(900, 50);
    glVertex2f(950, 50);
    glEnd();

    // ================================
    // drawing runway light
    // ================================
    glBegin(GL_QUADS);
    glColor3f(rgb(255), rgb(236), rgb(39));
    glVertex2f(70, 100);
    glVertex2f(90, 100);
    glVertex2f(90, 110);
    glVertex2f(70, 110);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(255), rgb(236), rgb(39));
    glVertex2f(170, 100);
    glVertex2f(190, 100);
    glVertex2f(190, 110);
    glVertex2f(170, 110);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(255), rgb(236), rgb(39));
    glVertex2f(270, 100);
    glVertex2f(290, 100);
    glVertex2f(290, 110);
    glVertex2f(270, 110);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(255), rgb(236), rgb(39));
    glVertex2f(370, 100);
    glVertex2f(390, 100);
    glVertex2f(390, 110);
    glVertex2f(370, 110);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(255), rgb(236), rgb(39));
    glVertex2f(470, 100);
    glVertex2f(490, 100);
    glVertex2f(490, 110);
    glVertex2f(470, 110);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(rgb(255), rgb(236), rgb(39));
    glVertex2f(950, 100);
    glVertex2f(970, 100);
    glVertex2f(970, 110);
    glVertex2f(950, 110);
    glEnd();
    // vehicle-----------------------------
    // ====================================
    // driver
    glBegin(GL_POLYGON);
    glColor3f(rgb(142), rgb(197), rgb(217));
    glVertex2i(v, 110);
    glVertex2i(v + 20, 110);
    glVertex2i(v + 20, 130);
    glEnd();
    // carback
    glBegin(GL_POLYGON);
    glColor3f(rgb(110), rgb(140), rgb(146));
    glVertex2i(v + 20, 110);
    glVertex2i(v + 40, 110);
    glVertex2i(v + 40, 120);
    glVertex2i(v + 20, 120);
    glEnd();
    // driver seat up
    glBegin(GL_POLYGON);
    glColor3f(rgb(213), rgb(158), rgb(61));
    glVertex2i(v, 130);
    glVertex2i(v + 20, 130);
    glVertex2i(v + 20, 140);
    glVertex2i(v, 140);
    glEnd();
    // car stear
    glBegin(GL_POLYGON);
    glColor3f(rgb(213), rgb(158), rgb(61));
    glVertex2i(v + 50, 110);
    glVertex2i(v + 60, 110);
    glVertex2i(v + 60, 120);
    glVertex2i(v + 50, 120);
    glVertex2i(v + 20, 140);
    glVertex2i(v + 20, 130);
    glEnd();
    // car lower body
    glBegin(GL_POLYGON);
    glColor3f(rgb(110), rgb(140), rgb(146));
    glVertex2i(v , 100);
    glVertex2i(v + 45, 100);
    glVertex2i(v + 45, 110);
    glVertex2i(v , 110);
    glEnd();
    // car wheel 1
    glColor3f(rgb(92), rgb(141), rgb(148));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(v + 10, 100); // circle er center position
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 5 * cosf(angle); // value ta radius
        float y = 5 * sinf(angle);  // value ta radius
        glVertex2f(x + v + 10, y + 100); // .. + circle er center position
    }
    glEnd();
    // car wheel 2
    glColor3f(rgb(92), rgb(141), rgb(148));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(v + 40, 100); // circle er center position
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 5 * cosf(angle); // value ta radius
        float y = 5 * sinf(angle);  // value ta radius
        glVertex2f(x + v + 40, y + 100); // .. + circle er center position
    }
    glEnd();



    // =========================================
    // || drawing airplane                    ||
    // =========================================

    //second Plane

    glBegin(GL_POLYGON);
    glColor3f(rgb(236), rgb(154), rgb(32));
    glVertex2i(180, 150);
    glVertex2i(200, 150);
    glVertex2i(200, 160);
    glVertex2i(180, 180);
    glVertex2i(160, 180);
    glEnd();
    // body
    glBegin(GL_POLYGON);
    glColor3f(rgb(150), rgb(122), rgb(144));
    glVertex2i(180, 130);
    glVertex2i(360, 130);
    glVertex2i(370, 140);
    glVertex2i(360, 150);
    glVertex2i(330, 150);
    glVertex2i(330, 160);
    glVertex2i(190, 160);
    glVertex2i(160, 150);
    glVertex2i(160, 140);
    glEnd();
    // cockepit
    glBegin(GL_POLYGON);
    glColor3f(rgb(88), rgb(204), rgb(255));
    glVertex2i(330, 150);
    glVertex2i(360, 150);
    glVertex2i(350, 158);
    glVertex2i(330, 160);
    glEnd();
    // window
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(200, 150);
    glVertex2f(210, 150);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(220, 150);
    glVertex2f(230, 150);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(240, 150);
    glVertex2f(250, 150);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(260, 150);
    glVertex2f(270, 150);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(280, 150);
    glVertex2f(290, 150);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(300, 150);
    glVertex2f(310, 150);
    glEnd();
    // wing
    glBegin(GL_POLYGON);
    glColor3f(rgb(78), rgb(188), rgb(220));
    glVertex2i(190, 120);
    glVertex2i(280, 120);
    glVertex2i(300, 140);
    glVertex2i(200, 140);
    glVertex2i(160, 130);
    glEnd();
    // fan
    glBegin(GL_POLYGON);
    glColor3f(rgb(236), rgb(154), rgb(32));
    glVertex2i(210, 110);
    glVertex2i(230, 110);
    glVertex2i(230, 130);
    glVertex2i(210, 130);
    glVertex2i(200, 120);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(236), rgb(154), rgb(32));
    glVertex2i(250, 110);
    glVertex2i(270, 110);
    glVertex2i(270, 130);
    glVertex2i(250, 130);
    glVertex2i(240, 120);
    glEnd();
    // wheel 1
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(200, 120);
    glVertex2f(200, 100);
    glEnd();
    // mini circle
    glColor3f(rgb(236), rgb(154), rgb(32));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(200, 100); // circle er center position
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 5 * cosf(angle); // value ta radius
        float y = 5 * sinf(angle);  // value ta radius
        glVertex2f(x + 200, y + 100); // .. + circle er center position
    }
    glEnd();
    // wheel 2
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(300, 130);
    glVertex2f(300, 100);
    glEnd();
    // mini circle
    glColor3f(rgb(236), rgb(154), rgb(32));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(300, 100); // circle er center position
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 5 * cosf(angle); // value ta radius
        float y = 5 * sinf(angle);  // value ta radius
        glVertex2f(x + 300, y + 100); // .. + circle er center position
    }
    glEnd();
    // wheel 3
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(340, 130);
    glVertex2f(340, 100);
    glEnd();
    // mini circle
    glColor3f(rgb(236), rgb(154), rgb(32));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(340, 100); // circle er center position
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 5 * cosf(angle); // value ta radius
        float y = 5 * sinf(angle);  // value ta radius
        glVertex2f(x + 340, y + 100); // .. + circle er center position
    }
    glEnd();

    //First Plane

    glBegin(GL_POLYGON);
    glColor3f(rgb(236), rgb(154), rgb(32));
    glVertex2i(20, 140);
    glVertex2i(40, 140);
    glVertex2i(40, 150);
    glVertex2i(20, 170);
    glVertex2i(00, 170);
    glEnd();
    // body
    glBegin(GL_POLYGON);
    glColor3f(rgb(55), rgb(55), rgb(55));
    glVertex2i(20, 120);
    glVertex2i(200, 120);
    glVertex2i(210, 130);
    glVertex2i(200, 140);
    glVertex2i(170, 140);
    glVertex2i(170, 150);
    glVertex2i(30, 150);
    glVertex2i(00, 140);
    glVertex2i(00, 130);
    glEnd();
    // cockepit
    glBegin(GL_POLYGON);
    glColor3f(rgb(88), rgb(204), rgb(255));
    glVertex2i(170, 140);
    glVertex2i(200, 140);
    glVertex2i(190, 148);
    glVertex2i(170, 150);
    glEnd();
    // window
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(40, 140);
    glVertex2f(50, 140);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(60, 140);
    glVertex2f(70, 140);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(80, 140);
    glVertex2f(90, 140);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(100, 140);
    glVertex2f(110, 140);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(120, 140);
    glVertex2f(130, 140);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(140, 140);
    glVertex2f(150, 140);
    glEnd();
    // wing
    glBegin(GL_POLYGON);
    glColor3f(rgb(78), rgb(188), rgb(220));
    glVertex2i(30, 110);
    glVertex2i(120, 110);
    glVertex2i(140, 130);
    glVertex2i(40, 130);
    glVertex2i(00, 120);
    glEnd();
    // fan
    glBegin(GL_POLYGON);
    glColor3f(rgb(236), rgb(154), rgb(32));
    glVertex2i(50, 100);
    glVertex2i(70, 100);
    glVertex2i(70, 120);
    glVertex2i(50, 120);
    glVertex2i(40, 110);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(236), rgb(154), rgb(32));
    glVertex2i(90, 100);
    glVertex2i(110, 100);
    glVertex2i(110, 120);
    glVertex2i(90, 120);
    glVertex2i(80, 110);
    glEnd();
    // wheel 1
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(40, 110);
    glVertex2f(40, 90);
    glEnd();
    // mini circle
    glColor3f(rgb(236), rgb(154), rgb(32));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(40, 90); // circle er center position
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 5 * cosf(angle); // value ta radius
        float y = 5 * sinf(angle);  // value ta radius
        glVertex2f(x + 40, y + 90); // .. + circle er center position
    }
    glEnd();
    // wheel 2
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(140, 120);
    glVertex2f(140, 90);
    glEnd();
    // mini circle
    glColor3f(rgb(236), rgb(154), rgb(32));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(140, 90); // circle er center position
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 5 * cosf(angle); // value ta radius
        float y = 5 * sinf(angle);  // value ta radius
        glVertex2f(x + 140, y + 90); // .. + circle er center position
    }
    glEnd();
    // wheel 3
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(180, 120);
    glVertex2f(180, 90);
    glEnd();
    // mini circle
    glColor3f(rgb(236), rgb(154), rgb(32));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(180, 90); // circle er center position
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 5 * cosf(angle); // value ta radius
        float y = 5 * sinf(angle);  // value ta radius
        glVertex2f(x + 180, y + 90); // .. + circle er center position
    }
    glEnd();

    //Flying Plane
    // tail
    glBegin(GL_POLYGON);
    glColor3f(rgb(236), rgb(154), rgb(32));
    glVertex2i(r + 20, f + 50);
    glVertex2i(r + 40, f + 50);
    glVertex2i(r + 40, f + 60);
    glVertex2i(r + 20, f + 80);
    glVertex2i(r + 00, f + 80);
    glEnd();
    // body
    glBegin(GL_POLYGON);
    glColor3f(rgb(50), rgb(122), rgb(144));
    glVertex2i(r + 20, f + 30);
    glVertex2i(r + 200, f + 30);
    glVertex2i(r + 210, f + 40);
    glVertex2i(r + 200, f + 50);
    glVertex2i(r + 170, f + 50);
    glVertex2i(r + 170, f + 60);
    glVertex2i(r + 30, f + 60);
    glVertex2i(r, f + 50);
    glVertex2i(r, f + 40);
    glEnd();
    // cockepit
    glBegin(GL_POLYGON);
    glColor3f(rgb(88), rgb(204), rgb(255));
    glVertex2i(r + 170, f + 50);
    glVertex2i(r + 200, f + 50);
    glVertex2i(r + 190, f + 58);
    glVertex2i(r + 170, f + 60);
    glEnd();
    // window
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(r + 40, f + 50);
    glVertex2f(r + 50, f + 50);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(r + 60, f + 50);
    glVertex2f(r + 70, f + 50);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(r + 80, f + 50);
    glVertex2f(r + 90, f + 50);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(r + 100, f + 50);
    glVertex2f(r + 110, f + 50);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(r + 120, f + 50);
    glVertex2f(r + 130, f + 50);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(r + 140, f + 50);
    glVertex2f(r + 150, f + 50);
    glEnd();
    // wing
    glBegin(GL_POLYGON);
    glColor3f(rgb(78), rgb(188), rgb(220));
    glVertex2i(r + 30, f + 20);
    glVertex2i(r + 120, f + 20);
    glVertex2i(r + 140, f + 40);
    glVertex2i(r + 40, f + 40);
    glVertex2i(r, f + 30);
    glEnd();
    // fan
    glBegin(GL_POLYGON);
    glColor3f(rgb(236), rgb(154), rgb(32));
    glVertex2i(r + 50, f + 10);
    glVertex2i(r + 70, f + 10);
    glVertex2i(r + 70, f + 30);
    glVertex2i(r + 50, f + 30);
    glVertex2i(r + 40, f + 20);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(236), rgb(154), rgb(32));
    glVertex2i(r + 90, f + 10);
    glVertex2i(r + 110, f + 10);
    glVertex2i(r + 110, f + 30);
    glVertex2i(r + 90, f + 30);
    glVertex2i(r + 80, f + 20);
    glEnd();
    // wheel 1
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(r + 40, f + 20);
    glVertex2f(r + 40, f);
    glEnd();
    // mini circle
    glColor3f(rgb(236), rgb(154), rgb(32));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(r + 40, f); // circle er center position
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 5 * cosf(angle); // value ta radius
        float y = 5 * sinf(angle);  // value ta radius
        glVertex2f(x + r + 40, y + f); // .. + circle er center position
    }
    glEnd();
    // wheel 2
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(r + 140, f + 30);
    glVertex2f(r + 140, f);
    glEnd();
    // mini circle
    glColor3f(rgb(236), rgb(154), rgb(32));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(r + 140, f); // circle er center position
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 5 * cosf(angle); // value ta radius
        float y = 5 * sinf(angle);  // value ta radius
        glVertex2f(x + r + 140, y + f); // .. + circle er center position
    }
    glEnd();
    // wheel 3
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(180 + r, f + 30);
    glVertex2f(180 + r, f);
    glEnd();
    // mini circle
    glColor3f(rgb(236), rgb(154), rgb(32));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(180 + r, f); // circle er center position
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 5 * cosf(angle); // value ta radius
        float y = 5 * sinf(angle);  // value ta radius
        glVertex2f(x + r + 180, y + f); // .. + circle er center position
    }
    glEnd();

    glutSwapBuffers();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1400, 680);
    glutCreateWindow("Computer Graphics Project");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
