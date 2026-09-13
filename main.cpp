#include <stdlib.h>
#include <GL/freeglut.h>
#include <math.h>
#include <iostream>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;


///////////////////////////////////////////////////////// common //////////////////////////////////////////////////////////////////

int scene = 1;
const float PI = 3.1416;

void drawCircle(float cx, float cy, float r, int numSegments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; i++) {
        float angle = 2.0f * PI * i / numSegments;
        float x = r * cos(angle);
        float y = r * sin(angle);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

///////////////////////////////////////////////////////// common //////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////// 1st Scene Start /////////////////////////////////////////////////////////

bool night_d = false;
bool light_on = true;

float waveMovement1 = 0.0f;
float waveMovement2 = 0.0f;
float waveMovement3 = 0.0f;
float sunMovement = 0.0f;
float cloudMovement1 = 0.0f;
float cloudMovement2 = 0.0f;
float shipMovement = 0.0f;
float smallShipMovement = 0.0f;
float truckMovement = 0.0f;
float moveLight = 200.0f;

float waveMovementSpeed1 = 0.3f;
float waveMovementSpeed2 = 0.3f;
float waveMovementSpeed3 = 0.3f;
float sunMovementSpeed = 0.5f;
float cloudMovement1Speed = 1.0f;
float cloudMovement2Speed = 1.0f;
float shipMovementSpeed = 2.2f;
float smallShipMovementSpeed = 1.4f;
float truckMovementSpeed = 2.0f;
float moveLightSpeed = 0.5f;
bool lightUp = true;

void update_d(int value) {

    waveMovement1 += waveMovementSpeed1;
    if (waveMovement1 > 400) {
        waveMovement1 = -1250.0f;
    }
    waveMovement2 += waveMovementSpeed2;
    if (waveMovement2 > 700) {
        waveMovement2 = -1300.0f;
    }
    waveMovement3 += waveMovementSpeed3;
    if (waveMovement3 > 1300) {
        waveMovement3 = -800.0f;
    }

    sunMovement += sunMovementSpeed;
    if (sunMovement > 1300) {
        sunMovement = -500.0f;
    }

    cloudMovement1 -= cloudMovement2Speed;
    cloudMovement2 -= cloudMovement2Speed;

    if (cloudMovement1 < -570) {
        cloudMovement1 = 1400.0f;
    }
    if (cloudMovement2 < -1350) {
        cloudMovement2 = 800.0f;
    }
    shipMovement += shipMovementSpeed;
    if (shipMovement > 1000) {
        shipMovement = -1300.0f;
    }
    smallShipMovement -= smallShipMovementSpeed;
    if (smallShipMovement <- 1000) {
        smallShipMovement = 850.0f;
    }
    truckMovement -= truckMovementSpeed;
    if (truckMovement <- 1000) {
        truckMovement = 1200.0f;
    }
    if (moveLight == 200){
        moveLightSpeed = 0.5f;
        lightUp = true;
    }

    else if (moveLight == 450){
        moveLightSpeed = -0.5f;
        lightUp = false;
    }
    moveLight += moveLightSpeed;

    glutPostRedisplay();
    glutTimerFunc(20, update_d, 0);
}

void drawWater_d()
{
	glBegin(GL_QUADS);
	if(night_d == false) glColor3f(0.149, 0.847, 0.866);
	else glColor3f(0.0f, 0.1f, 0.3f);
	glVertex2f(0, 200);
	glVertex2f(1400, 200);
	glVertex2f(1400, 607);
	glVertex2f(0, 607);
	glEnd();
}

void drawLand_d()
{
    glBegin(GL_QUADS);
    if(night_d == false) glColor3f(0.547, 0.449, 0.461);
    else glColor3f(0.247, 0.176, 0.231);
    glVertex2f(0, 0);
    glVertex2f(1400, 0);

    if(night_d == false) glColor3f(0.647, 0.549, 0.561);
    else glColor3f(0.247, 0.176, 0.231);
    glVertex2f(1400, 200);
    glVertex2f(0, 200);
    glEnd();
}


void drawContainer_d(float startX, float startY, string color)
{
	if(color == "p")
    {
        if(night_d == false) glColor3f(0.416, 0.204, 0.533);
        else glColor3f(0.325, 0.145, 0.423);
    }
	else if(color == "y")
    {
        if(night_d == false) glColor3f(0.902, 0.866, 0.149);
        else glColor3f(0.737, 0.702, 0);
    }
	else if(color == "b")
    {
        if(night_d == false)  glColor3f(0.145, 0.694, 0.855);
        else glColor3f(0.301, 0.525, 0.635);
    }
	else if(color == "r")
    {
        if(night_d == false) glColor3f(0.859, 0.196, 0.224);
        else glColor3f(0.556, 0.031, 0.054);
    }

	glBegin(GL_QUADS);
	glVertex2f(startX, startY);
	glVertex2f(startX + 100, startY);
	glVertex2f(startX + 100, startY + 50);
	glVertex2f(startX, startY + 50);
	glEnd();

	if(color == "p")
    {
        if(night_d == false) glColor3f(0.711, 0.176, 1);
        else glColor3f(0.416, 0.204, 0.533);
    }
	else if(color == "y")
	{
	    if(night_d == false) glColor3f(0.737, 0.702, 0);
	    else glColor3f(0.902, 0.866, 0.149);
	}
	else if(color == "b")
    {
        if(night_d == false) glColor3f(0.380, 0.796, 1);
        else glColor3f(0.145, 0.694, 0.855);
    }
	else if(color == "r")
    {
        if(night_d == false) glColor3f(1, 0.471, 0.494);
        else glColor3f(0.859, 0.196, 0.224);
    }
	glLineWidth(2);
	glBegin(GL_LINES);
	for(int i=10; i<100; i+=10)
	{
		glVertex2f(startX + i, startY + 5);
		glVertex2f(startX + i, startY + 45);
	}
	glEnd();
}

void drawBarrier()
{
    glColor3f(0.3f, 0.3f, 0.3f);
    float barrierHeight = 50.0f;
    float barrierThickness = 19.0f;

    for (float x = 0; x < 1400; x += 60) {
        glBegin(GL_QUADS);

        // Vertical
        glVertex2f(x, 200);
        glVertex2f(x + barrierThickness, 200);
        glVertex2f(x + barrierThickness, 200 + barrierHeight);
        glVertex2f(x, 200 + barrierHeight);
        glEnd();

        // Horizontal rail
        if (x < 1400 - 60) {
            glBegin(GL_QUADS);
            glVertex2f(x, 200 + barrierHeight - 5);
            glVertex2f(x + 60, 200 + barrierHeight - 5);
            glVertex2f(x + 60, 200 + barrierHeight);
            glVertex2f(x, 200 + barrierHeight);
            glEnd();
        }
    }
}

void drawSun_d() {
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(450.0f, 690.0f, 40.0f, 100);
}
void drawMoon_d(){

        glColor3f(0.8f, 0.8f, 0.8f);
        drawCircle(450.0f, 690.0f, 40.0f, 100);
        glColor3f(0.0, 0.2, 0.4);
        drawCircle(470.0f, 695.0f, 33.0f, 100);

}
void drawCloud_d(float x, float y)
{
    if(night_d == false) glColor3f(1.0f, 1.0f, 1.0f);
    else glColor3f(0.498f, 0.549f, 0.553f);
    // Cloud
    float radius = 30.0f;
    int numSegments = 100;

    // Circle 1
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= numSegments; i++) {
        float angle = 2.0f * PI * i / numSegments;
        glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
    }
    glEnd();

    // Circle 2
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x - 40, y + 10);
    for (int i = 0; i <= numSegments; i++) {
        float angle = 2.0f * PI * i / numSegments;
        glVertex2f(x - 40 + radius * cos(angle), y + 10 + radius * sin(angle));
    }
    glEnd();

    // Circle 3
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x + 40, y + 10);
    for (int i = 0; i <= numSegments; i++) {
        float angle = 2.0f * PI * i / numSegments;
        glVertex2f(x + 40 + radius * cos(angle), y + 10 + radius * sin(angle));
    }
    glEnd();

    // Circle 4
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x - 20, y - 20);
    for (int i = 0; i <= numSegments; i++) {
        float angle = 2.0f * PI * i / numSegments;
        glVertex2f(x - 20 + radius * cos(angle), y - 20 + radius * sin(angle));
    }
    glEnd();

    // Circle 5
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x + 20, y - 20);
    for (int i = 0; i <= numSegments; i++) {
        float angle = 2.0f * PI * i / numSegments;
        glVertex2f(x + 20 + radius * cos(angle), y - 20 + radius * sin(angle));
    }
    glEnd();
}


void drawStars_d()
{
    glPointSize(3);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);
    glVertex2f(100, 680);
    glVertex2f(200, 680);
    glVertex2f(300, 650);
    glVertex2f(400, 630);
    glVertex2f(500, 600);
    glVertex2f(600, 660);
    glVertex2f(700, 640);
    glVertex2f(850, 660);
    glVertex2f(950, 740);
    glVertex2f(800, 710);
    glVertex2f(1020, 700);
    glVertex2f(1140, 660);
    glVertex2f(1250, 700);
    glVertex2f(980, 690);
    glVertex2f(710, 670);
    glVertex2f(350, 700);
    glEnd();
}


void drawSky_d()
{
    glBegin(GL_QUADS);
    if(night_d == false)glColor3f(0.553, 0.824, 0.957);
	else glColor3f(0.0, 0.2, 0.4);
    glVertex2f(0, 600);
    glVertex2f(1400, 600);
    glVertex2f(1400, 750);
    glVertex2f(0, 750);
    glEnd();

    if(night_d) drawStars_d();

    glPushMatrix();
    glTranslatef(sunMovement, 0.0f, 0.0f);
    if (night_d == false)drawSun_d();
    else drawMoon_d();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloudMovement1, 0.0f, 0.0f);
    drawCloud_d(220, 690);
    drawCloud_d(500, 725);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloudMovement2, 0.0f, 0.0f);
    drawCloud_d(910, 710);
    drawCloud_d(1210, 735);
    //drawCloud(1050, 750);
    glPopMatrix();
}

void drawLighthouse()
{
    glBegin(GL_POLYGON);
    if(night_d == false) glColor3f(0.547, 0.449, 0.461);
    else glColor3f(0.247, 0.176, 0.231);
    glVertex2f(1140, 370);
    glVertex2f(1160, 325);
    glVertex2f(1340, 325);
    glVertex2f(1350, 380);
    glVertex2f(1330, 390);
    glVertex2f(1170, 385);
    glEnd();


    float baseX = 1250.0f;
    float baseY = 350.0f;
    float bottomWidth = 130.0f;
    float topWidth = 58.0f;
    float height = 250.0f;

    for (int i = 0; i < 5; i++) {
        if (i % 2 == 0) glColor3f(0.9f, 0.0f, 0.0f);
        else glColor3f(0.92f, 0.94f, 0.91f);

        float currentBottomWidth = bottomWidth - (i * (bottomWidth - topWidth) / 5);
        float currentTopWidth = bottomWidth - ((i + 1) * (bottomWidth - topWidth) / 5);

        glBegin(GL_QUADS);
        glVertex2f(baseX - currentBottomWidth / 2, baseY + i * (height / 5));
        glVertex2f(baseX + currentBottomWidth / 2, baseY + i * (height / 5));
        glVertex2f(baseX + currentTopWidth / 2, baseY + (i + 1) * (height / 5));
        glVertex2f(baseX - currentTopWidth / 2, baseY + (i + 1) * (height / 5));
        glEnd();
    }


    float houseWidth = 50.0f;
    float houseHeight = 40.0f;
    float houseX = baseX - houseWidth / 2;
    float houseY = baseY + height;

    glColor3f(0.64f, 0.18f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(houseX, houseY);
    glVertex2f(houseX + houseWidth, houseY);
    glVertex2f(houseX + houseWidth, houseY + houseHeight);
    glVertex2f(houseX, houseY + houseHeight);
    glEnd();


    glColor3f(0.88f, 0.92f, 0.95f);
    glBegin(GL_QUADS);
    glVertex2f(houseX + 5, houseY + 7);
    glVertex2f(houseX + 16, houseY + 7);
    glVertex2f(houseX + 16, houseY + 30);
    glVertex2f(houseX + 5, houseY + 30);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(houseX + 34, houseY + 7);
    glVertex2f(houseX + 45, houseY + 7);
    glVertex2f(houseX + 45, houseY + 30);
    glVertex2f(houseX + 34, houseY + 30);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(1250 , 630, 8, 100);

    if (night_d && light_on) {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(1245, 630);
    glVertex2f(1255, 630);
    glColor3f(1.0f, 1.0f, 0.6f);
    glVertex2f(850, moveLight);
    glVertex2f(1000, moveLight);
    glEnd();
    }

    float roofHeight = 20.0f;
    glColor3f(0.5f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(houseX - 5, houseY + houseHeight);
    glVertex2f(houseX + houseWidth + 5, houseY + houseHeight);
    glVertex2f(baseX, houseY + houseHeight + roofHeight);
    glEnd();

}

void drawWave_d(float startX, float startY, float length, string color)
{
	if(color == "dark")
    {
        if(night_d == false) glColor3f(0.145, 0.694, 0.855);
        else glColor3f(0.0, 0.184, 0.294);
    }
	else
    {
        if(night_d == false) glColor3f(0.161, 0.996, 0.847);
        else glColor3f(0.0039, 0.309, 0.525);
    }

	float waveRadius = 3.3f;
    int numSegments = 30;

    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= numSegments; i++) {
        float angle = 1.0f * M_PI * i / numSegments;
        glVertex2f(startX + waveRadius * cos(angle + M_PI * 0.5), startY + waveRadius * sin(angle + M_PI * 0.5));
    }
    glEnd();

	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i <= numSegments; i++) {
        float angle = 1.0f * M_PI * i / numSegments;
        glVertex2f(startX + length + waveRadius * cos(angle - M_PI * 0.5), startY + waveRadius * sin(angle - M_PI * 0.5));
    }
    glEnd();

	glBegin(GL_QUADS);
	glVertex2f(startX, startY - waveRadius);
	glVertex2f(length + startX, startY - waveRadius);
	glVertex2f(length + startX, startY - waveRadius + 2 * waveRadius);
	glVertex2f(startX, startY - waveRadius + 2 * waveRadius);
	glEnd();
}


void drawSmallShip()
{
    float y = 465;

    // Body
    glBegin(GL_QUADS);
    if(night_d == false) glColor3f(0.1f, 0.1f, 0.1f);
    else glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(750, 55 + y);
    glVertex2f(950, 55 + y);
    glVertex2f(970, 90 + y);
    glVertex2f(730, 90 + y);
    glEnd();

    // containers
    drawContainer_d(785, 148 + y, "y");
    drawContainer_d(735, 102 + y, "p");
    drawContainer_d(810, 102 + y, "b");
    drawContainer_d(865, 102 + y, "r");

    // Railing part
    glBegin(GL_QUADS);
    if(night_d == false) glColor3f(0.3f, 0.22f, 0.23f);
    else glColor3f(0.28f, 0.22f, 0.23f);
    glVertex2f(730, 90 + y);
    glVertex2f(970, 90 + y);
    glVertex2f(970, 110 + y);
    glVertex2f(730, 110 + y);
    glEnd();

    // windows
    if(night_d == false) glColor3f(0.88f, 0.92f, 0.95f);
    else glColor3f(1.0f, 1.0f, 0.0f);
    for (int i = 0; i <= 190; i += 30)
        drawCircle(755 + i, 90 + y, 5, 100);
}


void drawShip_d()
{
    float shipYOffset = 115;

    // Body
    glBegin(GL_QUADS);
    if(night_d == false) glColor3f(0.1f, 0.1f, 0.1f);
    else glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(700, 90 + shipYOffset);
    glVertex2f(1100, 90 + shipYOffset);
    glVertex2f(1140, 150 + shipYOffset);
    glVertex2f(660, 150 + shipYOffset);
    glEnd();

    // Railing part
    glBegin(GL_QUADS);
    if(night_d == false) glColor3f(0.3f, 0.22f, 0.23f);
    else glColor3f(0.28f, 0.22f, 0.23f);
    glVertex2f(660, 150 + shipYOffset);
    glVertex2f(1140, 150 + shipYOffset);
    glVertex2f(1140, 170 + shipYOffset);
    glVertex2f(660, 170 + shipYOffset);
    glEnd();

    // windows
 	if(night_d == false) glColor3f(0.88f, 0.92f, 0.95f);
	else  glColor3f(1.0f, 1.0f, 0.0f);
    for (int i = 0; i <= 390; i += 35) {
        drawCircle(710 + i, 150 + shipYOffset, 7, 100);
    }

    // containers
    drawContainer_d(680, 170 + shipYOffset, "p");
    drawContainer_d(780, 170 + shipYOffset, "b");
    drawContainer_d(880, 170 + shipYOffset, "r");
    drawContainer_d(980, 170 + shipYOffset, "y");
    drawContainer_d(785, 220 + shipYOffset, "y");
    drawContainer_d(885, 220 + shipYOffset, "p");
}

void drawTruck()
{
    glBegin(GL_QUADS);
    if(night_d == false) glColor3f(0.2f, 0.2f, 0.2f);
    else glColor3f(0.2f, 0.1f, 0.1f);
    glVertex2f(300, 120);
    glVertex2f(500, 120);
    glVertex2f(500, 135);
    glVertex2f(300, 135);
    glEnd();

    if(night_d == false) glColor3f(0.88f, 0.92f, 0.95f);
    else glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(299, 159, 5, 100);
    if(night_d) {
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(301, 160);
    glColor3f(1.0f, 1.0f, 0.6f);
    glVertex2f(223, 120);
    glVertex2f(220, 166);
    glEnd();
 }

    glBegin(GL_QUADS);
    if(night_d == false) glColor3f(0.859, 0.196, 0.224);
    else glColor3f(0.6f, 0.0f, 0.0f);
    glVertex2f(302, 135);
    glVertex2f(362, 135);
    glVertex2f(362, 185);
    glVertex2f(302, 185);
    glEnd();

    glBegin(GL_QUADS);
    if(night_d == false) glColor3f(0.6f, 0.8f, 1.0f);
    else glColor3f(0.3f, 0.5f, 0.8f);
    glVertex2f(302, 157);
    glVertex2f(332, 157);
    glVertex2f(332, 185);
    glVertex2f(302, 185);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(340, 110, 15, 100);
    drawCircle(460, 110, 15, 100);

    glColor3f(0.7f, 0.7f, 0.7f);
    drawCircle(340, 110, 5, 100);
    drawCircle(460, 110, 5, 100);

    drawContainer_d(375, 135, "p");


}


void display_d()
{
    glClear(GL_COLOR_BUFFER_BIT);
	drawSky_d();
	drawWater_d();
    //Wave
    glPushMatrix();
    glTranslatef(waveMovement1, 0.0f, 0.0f);
	//drawWave(1100, 380, 200, "dark");
	//drawWave(1200, 255, 150, "dark");
    drawWave_d(1100, 265, 150, "dark");
    drawWave_d(1350, 265, 170, "dark");
    drawWave_d(1110, 340, 160, "dark");
    drawWave_d(1100, 415, 130, "light");
    drawWave_d(1290, 415, 150, "dark");
    drawWave_d(1250, 490, 100, "dark");
    drawWave_d(1150, 490, 210, "dark");
    drawWave_d(1150, 565, 200, "dark");
    glPopMatrix();

	glPushMatrix();
    glTranslatef(waveMovement2, 0.0f, 0.0f);
	//drawWave(900, 285, 250, "light");
	//drawWave(900, 480, 150, "light");
    drawWave_d(500, 265, 150, "dark");
    drawWave_d(750, 265, 170, "dark");
    drawWave_d(490, 340, 160, "dark");
    drawWave_d(500, 415, 130, "light");
    drawWave_d(760, 415, 150, "dark");
    drawWave_d(400, 490, 100, "dark");
    drawWave_d(640, 490, 210, "light");
    drawWave_d(670, 565, 300, "dark");
	drawWave_d(200, 565, 50, "dark");
    glPopMatrix();

    glPushMatrix();
    glTranslatef(waveMovement3, 0.0f, 0.0f);
    drawWave_d(-160, 265, 150, "dark");
    drawWave_d(180, 265, 170, "dark");
    drawWave_d(40, 340, 160, "light");
    drawWave_d(-120, 415, 150, "dark");
    drawWave_d(180, 415, 150, "dark");
    drawWave_d(50, 490, 100, "light");
    drawWave_d(90, 565, 300, "dark");
	drawWave_d(-130, 565, 120, "dark");
	glPopMatrix();

	drawLand_d();

    glPushMatrix();
    if (night_d == false)glTranslatef(smallShipMovement, 0.0f, 0.0f);
	else glTranslatef(800.0f, 0.0f, 0.0f);
    drawSmallShip();
    glPopMatrix();

	drawLighthouse();

    glPushMatrix();
    if(night_d == false) glTranslatef(shipMovement, 0.0f, 0.0f);
    else glTranslatef(-300.0f, 0.0f, 0.0f);
	drawShip_d();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(truckMovement, 0.0f, 0.0f);
    drawTruck();
    glPopMatrix();
    drawBarrier();

	//Container
	drawContainer_d(0, 0, "p");
	drawContainer_d(100, 0, "y");
	drawContainer_d(200, 0, "r");
	drawContainer_d(300, 0, "b");
	drawContainer_d(400, 0, "y");
	drawContainer_d(575, 0, "r");
	drawContainer_d(900, 0, "p");
	drawContainer_d(1000, 0, "b");
	drawContainer_d(1100, 0, "y");
	drawContainer_d(1200, 0, "r");
	drawContainer_d(1300, 0, "b");
	drawContainer_d(20, 50, "r");
	drawContainer_d(138, 50, "b");
	drawContainer_d(240, 50, "y");
	drawContainer_d(342, 50, "p");
	drawContainer_d(940, 50, "y");
	drawContainer_d(1050, 50, "p");
	drawContainer_d(1150, 50, "b");
	drawContainer_d(1270, 50, "p");
	drawContainer_d(270, 100, "r");
	drawContainer_d(1090, 100, "r");

	glutSwapBuffers();
	//glFlush();
}


///////////////////////////////////////////////////////// 1st Scene End /////////////////////////////////////////////////////////







///////////////////////////////////////////////////////// 2nd Scene Start /////////////////////////////////////////////////////////

float moveWave = 0.0f;
float moveWave2 = 0.0f;
float moveCloud1 = 0.0f;
float moveCloud2 = 0.0f;
float moveShip = -1050.0f;
float movePirateShip = 1000.0f;
float moveWave_factor = 0.5f;
float moveCloud_factor = 1.0f;
float moveShip_factor = 2.0f;
float movePirateShip_factor = -2.0f;
float moveBird_factor = 2.0f;

bool liftContainer = false;
float moveContainer = 0.0f;
float moveContainer_factor = 0.5f;

float hookLength = 345;
bool hookLength_change = false;
float hookLength_changeFactor = 0.5f;

bool night = false;
float starSize = 2.0f;
float starSize1 = 4.0f;
float birdmove1= 0.0f;
float birdmove2= 0.0f;
float birdmove3= 0.0f;
float birdmove4= 0.0f;
float birdmove5= 0.0f;

//0 none, 1 black, 2 light yellow, 3 white, 4 dark yellow, 5 dark white, 6 red, 7 darker yellow
char bird[12][18] = {"00000011111100000",
                     "00001122213310000",
                     "00012244133331000",
                     "01111444153313100",
                     "13333144153313100",
                     "13333314415333100",
                     "15333514441111110",
                     "01555144416666661",
                     "00111444161111111",
                     "00177444416666610",
                     "00011777771111100",
                     "00000111110000000"};

char batmanLogo[20][32] = {"0000000000111111111110000000000",
                           "0000000111222222222221110000000",
                           "0000011222222122212222211100000",
                           "0001112111222111112221122111000",
                           "0011222112222111112222112221100",
                           "0112211112222111112222111122110",
                           "0121111112222111112222111111210",
                           "1121111111221111111221111111121",
                           "1211111111111111111111111111121",
                           "1211111111111111111111111111121",
                           "1211111111111111111111111111121",
                           "1211111111111111111111111111121",
                           "1211111111111111111111111111121",
                           "0121112222122111112212222111210",
                           "0112212222122211122212222122110",
                           "0011221222222221222222221221100",
                           "0001112222222221222222222111000",
                           "0000011122222222222222211100000",
                           "0000000111112222222111110000000",
                           "0000000000111111111110000000000"};

char pirate[14][18] = {"01100000000000110",
                       "11100000000000111",
                       "11110011111001111",
                       "00110111111101100",
                       "00001111111110000",
                       "00001001110010000",
                       "00001001110010000",
                       "00001111011110000",
                       "00001110001110000",
                       "00000011111000000",
                       "00011010001011000",
                       "01111011111011110",
                       "01110001110001110",
                       "00110000000001100"};

void restart()
{
    moveWave = 0.0f;
    moveWave2 = 0.0f;
    moveCloud1 = 0.0f;
    moveCloud2 = 0.0f;
    moveShip = -1050.0f;
    movePirateShip = 1000.0f;
    moveShip_factor = 2.0f;

    liftContainer = false;
    moveContainer = 0.0f;
    moveContainer_factor = 0.5f;

    hookLength = 345;
    hookLength_change = false;

    birdmove1= 0.0f;
    birdmove2= 0.0f;
    birdmove3= 0.0f;
    birdmove4= 0.0f;
    birdmove5= 0.0f;
}

void update(int value) {
    moveWave += moveWave_factor;
    moveWave2 += moveWave_factor;
    moveCloud1 += moveCloud_factor;
    moveCloud2 += moveCloud_factor;
    moveShip += moveShip_factor;
    birdmove1 += moveBird_factor;
    birdmove2 += moveBird_factor;
    birdmove3 += moveBird_factor;
    birdmove4 += moveBird_factor;
    birdmove5 += moveBird_factor;
    movePirateShip += movePirateShip_factor;

    if(liftContainer)
    {
        if(night == false) moveContainer += moveContainer_factor;
    }
    if(hookLength < 345-135 && liftContainer == false)
    {
        hookLength_change = false;
        liftContainer = true;
    }
    if(hookLength_change == true)
    {
        if(night == false) hookLength -= hookLength_changeFactor;
    }
    if(moveShip > 80 && hookLength > 345-135 && liftContainer == false)
    {
        moveShip_factor = 0.0f;
        hookLength_change = true;
    }
    if (moveShip > 80 && liftContainer)
    {
        if(hookLength < 345 && night == false) hookLength += hookLength_changeFactor;
    }
    if (moveContainer > 125)
    {
        moveContainer_factor = 0.0f;
    }

    if(movePirateShip < -1200)
    {
        movePirateShip = 1400;
    }

    if (moveWave > 1400) {
        moveWave = -1400.0f;
    }
    if (moveWave2 > 2800) {
        moveWave2 = -2800.0f;
    }

    if (moveCloud1 > 1300) {
        moveCloud1 = -800.0f;
    }
    if (moveCloud2 > 600) {
        moveCloud2 = -1300.0f;
    }

    if (birdmove1 > 1400.0f) {
        birdmove1 = -200.0f;
    }
    if (birdmove2 > 900.0f) {
        birdmove2 = -700.0f;
    }
    if (birdmove3 > 400.0f) {
        birdmove3 = -1200.0f;
    }
    if (birdmove4 > 700.0f) {
        birdmove4 = -900.0f;
    }
    if (birdmove5 > 500.0f) {
        birdmove5 = -1100.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}

void updateStars(int value)
{
    if(starSize == 4)
    {
        starSize = 2.0f;
        starSize1 = 4.0f;
    }
    else
    {
        starSize = 4.0f;
        starSize1 = 2.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(500, updateStars, 0);
}

void drawContainer(float startX, float startY, string color)
{
	if(color == "p")
    {
        if(night == false) glColor3f(0.416, 0.204, 0.533);
        else glColor3f(0.325, 0.145, 0.423);
    }
	else if(color == "y")
    {
        if(night == false) glColor3f(0.902, 0.866, 0.149);
        else glColor3f(0.737, 0.702, 0);
    }
	else if(color == "b")
    {
        if(night == false)  glColor3f(0.145, 0.694, 0.855);
        else glColor3f(0.301, 0.525, 0.635);
    }
	else if(color == "r")
    {
        if(night == false) glColor3f(0.859, 0.196, 0.224);
        else glColor3f(0.556, 0.031, 0.054);
    }

	glBegin(GL_QUADS);
	glVertex2f(startX, startY);
	glVertex2f(startX + 100, startY);
	glVertex2f(startX + 100, startY + 50);
	glVertex2f(startX, startY + 50);
	glEnd();

	if(color == "p")
    {
        if(night == false) glColor3f(0.711, 0.176, 1);
        else glColor3f(0.416, 0.204, 0.533);
    }
	else if(color == "y")
	{
	    if(night == false) glColor3f(0.737, 0.702, 0);
	    else glColor3f(0.902, 0.866, 0.149);
	}
	else if(color == "b")
    {
        if(night == false) glColor3f(0.380, 0.796, 1);
        else glColor3f(0.145, 0.694, 0.855);
    }
	else if(color == "r")
    {
        if(night == false) glColor3f(1, 0.471, 0.494);
        else glColor3f(0.859, 0.196, 0.224);
    }
	glLineWidth(2);
	glBegin(GL_LINES);
	for(int i=10; i<100; i+=10)
	{
		glVertex2f(startX + i, startY + 5);
		glVertex2f(startX + i, startY + 45);
	}
	glEnd();
}

void drawBird(int x, int y)
{
    float pointSize = 2.0f;
    glPointSize(pointSize);

    glBegin(GL_POINTS);
    int currY = y;
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 18; j++){
                if(bird[i][j] == '0'){
                    //skip
                }
                else if(bird[i][j] == '1'){
                    glColor3f(0.0f, 0.0f, 0.0f);
                    glVertex2f(j*pointSize+x, currY);
                }
                else if(bird[i][j] == '2'){
                    glColor3f(0.976f, 0.843f, 0.553f);
                    glVertex2f(j*pointSize+x, currY);
                }
                else if(bird[i][j] == '3'){
                    glColor3f(1.0f, 1.0f, 1.0f);
                    glVertex2f(j*pointSize+x, currY);
                }
                else if(bird[i][j] == '4'){
                    glColor3f(0.973f, 0.718f, 0.208f);
                    glVertex2f(j*pointSize+x, currY);
                }
                else if(bird[i][j] == '5'){
                    glColor3f(0.847f, 0.902f, 0.804f);
                    glVertex2f(j*pointSize+x, currY);
                }
                else if(bird[i][j] == '6'){
                    glColor3f(0.961f, 0.220f, 0.004f);
                    glVertex2f(j*pointSize+x, currY);
                }
                else if(bird[i][j] == '7'){
                    glColor3f(0.878f, 0.502f, 0.173f);
                    glVertex2f(j*pointSize+x, currY);
                }
            }
            currY -= pointSize;
        }
    glEnd();
}

void drawBatman(float x, float y, float size)
{
    glColor3f(0.8f, 0.8f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y-size*20*0.5);
    glVertex2f(x+size*31*0.5, 300);
    glVertex2f(x+size*31, y-size*20*0.5);
    glEnd();

    glPointSize(size);
    glBegin(GL_POINTS);
    int currY = y;
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 31; j++){
                if(batmanLogo[i][j] == '0'){
                    //glColor3f(1.0f, 1.0f, 1.0f);
                    //glVertex2f(j*size+x, currY);
                }
                else if(batmanLogo[i][j] == '1'){
                    glColor3f(0.0f, 0.0f, 0.0f);
                    glVertex2f(j*size+x, currY);
                }
                else if(batmanLogo[i][j] == '2'){
                    glColor3f(1.0f, 1.0f, 0.0f);
                    glVertex2f(j*size+x, currY);
                }
            }

            currY -= size;
        }
    glEnd();
}

void drawWater()
{
	glBegin(GL_QUADS);

	if(night == false) glColor3f(0.149, 0.847, 0.866);
	else glColor3f(0.0039, 0.227, 0.388);
	glVertex2f(0, 0);
	glVertex2f(1400, 0);
	glVertex2f(1400, 140);
	glVertex2f(0, 140);

	glEnd();
}
void drawLand()
{
	glBegin(GL_QUADS);

	if(night == false) glColor3f(0.647, 0.549, 0.561);
	else glColor3f(0.247, 0.176, 0.231);
	glVertex2f(0, 140);
	glVertex2f(1400, 140);
	glVertex2f(1400, 230);
	glVertex2f(0, 230);

	//horizontal line
	if(night == false) glColor3f(0.541, 0.471, 0.482);
	else glColor3f(0.180, 0.117, 0.145);
	glVertex2f(0, 200);
	glVertex2f(1400, 200);
	glVertex2f(1400, 210);
	glVertex2f(0, 210);

	//vertical lines
	for(int i=50; i<=1350; i+=100)
	{
		if(night == false) glColor3f(0.824, 0.776, 0.776);
		else glColor3f(0.647, 0.549, 0.560);
		glVertex2f(i, 145);
		glVertex2f(i+5, 145);
		glVertex2f(i+5, 195);
		glVertex2f(i, 195);
	}

	glEnd();
}

void drawSky()
{
	glBegin(GL_QUADS);

	if(night == false)glColor3f(0.553, 0.824, 0.957);
	else glColor3f(0.0, 0.2, 0.4);
	glVertex2f(0, 230);
	glVertex2f(1400, 230);
	glVertex2f(1400, 750);
	glVertex2f(0, 750);

	glEnd();
}

void drawWave(float startX, float startY, float length, string color)
{
	if(color == "dark")
    {
        if(night == false) glColor3f(0.145, 0.694, 0.855);
        else glColor3f(0.0, 0.184, 0.294);
    }
	else
    {
        if(night == false) glColor3f(0.161, 0.996, 0.847);
        else glColor3f(0.0039, 0.309, 0.525);
    }

	float waveRadius = 4.0f;
    int numSegments = 30;

    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= numSegments; i++) {
        float angle = 1.0f * M_PI * i / numSegments;
        glVertex2f(startX + waveRadius * cos(angle + M_PI * 0.5), startY + waveRadius * sin(angle + M_PI * 0.5));
    }
    glEnd();

	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i <= numSegments; i++) {
        float angle = 1.0f * M_PI * i / numSegments;
        glVertex2f(startX + length + waveRadius * cos(angle - M_PI * 0.5), startY + waveRadius * sin(angle - M_PI * 0.5));
    }
    glEnd();

	glBegin(GL_QUADS);
	glVertex2f(startX, startY - waveRadius);
	glVertex2f(length + startX, startY - waveRadius);
	glVertex2f(length + startX, startY - waveRadius + 2 * waveRadius);
	glVertex2f(startX, startY - waveRadius + 2 * waveRadius);
	glEnd();
}

void drawBgBuildings()
{
	if(night == false) glColor3f(0.443, 0.749, 0.824);
	else glColor3f(0.066, 0.168, 0.263);

    glBegin(GL_QUADS);
	glVertex2f(0, 230);
    glVertex2f(20, 230);
    glVertex2f(20, 420);
    glVertex2f(00, 420);
    glEnd();

    glBegin(GL_QUADS);
	glVertex2f(20, 230);
    glVertex2f(40, 230);
    glVertex2f(40, 400);
    glVertex2f(20, 400);
    glEnd();

    glBegin(GL_QUADS);
	glVertex2f(40, 230);
    glVertex2f(90, 230);
    glVertex2f(90, 370);
    glVertex2f(40, 370);
    glEnd();

    glBegin(GL_QUADS);
	glVertex2f(90, 230);
    glVertex2f(190, 230);
    glVertex2f(190, 430);
    glVertex2f(90, 430);
    glEnd();

    glBegin(GL_QUADS);
	glVertex2f(190, 230);
    glVertex2f(300, 230);
    glVertex2f(300, 400);
    glVertex2f(190, 400);
    glEnd();

    glBegin(GL_QUADS);
	glVertex2f(300, 230);
    glVertex2f(380, 230);
    glVertex2f(380, 480);
    glVertex2f(300, 480);
    glEnd();

    glBegin(GL_QUADS);
	glVertex2f(330, 230);
    glVertex2f(350, 230);
    glVertex2f(350, 520);
    glVertex2f(330, 520);
    glEnd();

    glBegin(GL_QUADS);
	glVertex2f(380, 230);
    glVertex2f(400, 230);
    glVertex2f(400, 460);
    glVertex2f(380, 460);
    glEnd();

    glBegin(GL_QUADS);
	glVertex2f(400, 230);
    glVertex2f(450, 230);
    glVertex2f(450, 400);
    glVertex2f(400, 400);
    glEnd();

    glBegin(GL_QUADS);
	glVertex2f(450, 230);
    glVertex2f(510, 230);
    glVertex2f(510, 450);
    glVertex2f(450, 450);
    glEnd();

    glBegin(GL_QUADS);
	glVertex2f(510, 230);
    glVertex2f(580, 230);
    glVertex2f(580, 420);
    glVertex2f(510, 420);
    glEnd();

    glBegin(GL_QUADS);
	glVertex2f(600, 230);
    glVertex2f(660, 230);
    glVertex2f(660, 400);
    glVertex2f(600, 400);
    glEnd();

    glBegin(GL_QUADS);
	glVertex2f(660, 230);
    glVertex2f(800, 230);
    glVertex2f(800, 430);
    glVertex2f(660, 430);
    glEnd();

    glBegin(GL_QUADS);
	glVertex2f(800, 230);
    glVertex2f(900, 230);
    glVertex2f(900, 400);
    glVertex2f(800, 400);
    glEnd();

    glBegin(GL_QUADS);
	glVertex2f(900, 230);
    glVertex2f(1000, 230);
    glVertex2f(1000, 350);
    glVertex2f(900, 350);
    glEnd();

    glBegin(GL_QUADS);
	glVertex2f(1050, 230);
    glVertex2f(1150, 230);
    glVertex2f(1150, 390);
    glVertex2f(1050, 390);
    glEnd();

    glBegin(GL_QUADS);
	glVertex2f(1150, 230);
    glVertex2f(1200, 230);
    glVertex2f(1200, 430);
    glVertex2f(1150, 430);
    glEnd();

    glBegin(GL_QUADS);
	glVertex2f(1200, 230);
    glVertex2f(1300, 230);
    glVertex2f(1300, 450);
    glVertex2f(1200, 450);
    glEnd();

    glBegin(GL_QUADS);
	glVertex2f(1330, 230);
    glVertex2f(1400, 230);
    glVertex2f(1400, 470);
    glVertex2f(1330, 470);
    glEnd();
}


void renderBitmapText(float x, float y, void* font, const char* text) {
    if(night == true) glColor3f(0.902, 0.867, 0.149);
    else glColor3f(1, 1, 1);
    glRasterPos2f(x, y);
    while (*text) {
        glutBitmapCharacter(font, *text);
        text++;
    }
}

void drawPortBuilding()
{
    //base
    glColor3f(0.427, 0.475, 0.522);
    glBegin(GL_QUADS);
    glVertex2f(400, 230);
    glVertex2f(700, 230);
    glVertex2f(700, 480);
    glVertex2f(400, 480);
    glEnd();

    //base corner
    glColor3f(0.258, 0.263, 0.243);
    glBegin(GL_QUADS);
    glVertex2f(410, 230);
    glVertex2f(690, 230);
    glVertex2f(690, 470);
    glVertex2f(410, 470);
    glEnd();

    //floor divider
    glLineWidth(5);
    for(int i=0; i<680-450; i+=48)
    {
        glColor3f(0.427, 0.475, 0.522);
        glBegin(GL_LINES);
        glVertex2f(410, 232+i);
        glVertex2f(690, 232+i);
        glEnd();
    }

    //windows
    for(int i=0; i<680-450; i+=48)
    {
        if(night == false) glColor3f(0.443, 0.749, 0.824);
        else glColor3f(0.902, 0.867, 0.149);
        glBegin(GL_QUADS);
        glVertex2f(450, 235+i);
        glVertex2f(650, 235+i);
        glVertex2f(650, 235+i+38);
        glVertex2f(450, 235+i+38);
        glEnd();
    }

    //billboard corner
    if(night == false) glColor3f(0.035, 0.255, 0.388);
    else glColor3f(0.902, 0.867, 0.149);
    glBegin(GL_QUADS);
    glVertex2f(495, 480);
    glVertex2f(605, 480);
    glVertex2f(605, 525);
    glVertex2f(495, 525);
    glEnd();

    //billboard
    if(night == false) glColor3f(0.415, 0.533, 0.6);
    else glColor3f(0.035, 0.255, 0.388);
    glBegin(GL_QUADS);
    glVertex2f(500, 480);
    glVertex2f(600, 480);
    glVertex2f(600, 520);
    glVertex2f(500, 520);
    glEnd();

    renderBitmapText(525.0f, 495.0f, GLUT_BITMAP_HELVETICA_18, "PORT");
}

void drawRays(float cx, float cy, float innerRadius, float outerRadius, int numRays) {
    float angleStep = 2.0f * PI / numRays;

    glBegin(GL_LINES);
    for (int i = 0; i < numRays; i++) {
        float angle = i * angleStep;
        float xInner = cx + innerRadius * cos(angle);
        float yInner = cy + innerRadius * sin(angle);
        float xOuter = cx + outerRadius * cos(angle);
        float yOuter = cy + outerRadius * sin(angle);
        glVertex2f(xInner, yInner);
        glVertex2f(xOuter, yOuter);
    }
    glEnd();
}

void drawCloud(float x, float y, float size) {
    if(night == false) glColor3f(1.0f, 1.0f, 1.0f);
    else glColor3f(0.498f, 0.549f, 0.553f);

    drawCircle(x, y, size, 100);
    drawCircle(x + size * 0.5, y + size * 0.5, size, 100);
    drawCircle(x - size * 0.5, y + size * 0.5, size, 100);
    drawCircle(x + size * 0.5, y - size * 0.5, size, 100);
    drawCircle(x - size * 0.5, y - size * 0.5, size, 100);
    drawCircle(x - size, y, size, 100);
    drawCircle(x + size, y, size, 100);
}


void drawShip()
{
    // red bottom of ship
    glBegin(GL_QUADS);
    if(night == false) glColor3f(0.858f, 0.196f, 0.223f);
    else glColor3f(0.415f, 0.019f, 0.035f);
	glVertex2f(700, 70);
	glVertex2f(1100, 70);
	glVertex2f(1100, 90);
	glVertex2f(700, 90);
	glEnd();

	//body of ship
	glBegin(GL_QUADS);
    if(night == false) glColor3f(0.353f, 0.309f, 0.317f);
    else glColor3f(0.258f, 0.262f, 0.243f);
	glVertex2f(700, 90);
	glVertex2f(1100, 90);
	glVertex2f(1140, 150);
	glVertex2f(660, 150);
	glEnd();

    //railing part of ship
	glBegin(GL_QUADS);
    if(night == false) glColor3f(0.353f, 0.309f, 0.317f);
    else glColor3f(0.258f, 0.262f, 0.243f);
	glVertex2f(660, 150);
	glVertex2f(1140, 150);
	glVertex2f(1140, 170);
	glVertex2f(660, 170);
	glEnd();

	//first floor of ship
	glBegin(GL_QUADS);
    if(night == false) glColor3f(1.0f, 1.0f, 1.0f);
    else glColor3f(0.678f, 0.709f, 0.741f);
	glVertex2f(900, 170);
	glVertex2f(1105, 170);
	glVertex2f(1095, 210);
	glVertex2f(900, 210);
	glEnd();

	//second floor of ship
	glBegin(GL_QUADS);
    if(night == false) glColor3f(1.0f, 1.0f, 1.0f);
    else glColor3f(0.678f, 0.709f, 0.741f);
	glVertex2f(900, 170);
	glVertex2f(1120, 170);
	glVertex2f(1095, 210);
	glVertex2f(900, 210);
	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.353f, 0.309f, 0.317f);
	glVertex2f(900, 210);
	glVertex2f(1075, 210);
	glVertex2f(1075, 220);
	glVertex2f(900, 220);
	glEnd();

	glBegin(GL_QUADS);
    if(night == false) glColor3f(1.0f, 1.0f, 1.0f);
    else glColor3f(0.678f, 0.709f, 0.741f);
	glVertex2f(900, 220);
	glVertex2f(1075, 220);
	glVertex2f(1050, 260);
	glVertex2f(900, 260);
	glEnd();

	//windows
	glBegin(GL_QUADS);
    if(night == false) glColor3f(0.145f, 0.695f, 0.855f);
    else glColor3f(0.737f, 0.701f, 0.0f);
	glVertex2f(910, 180);
	glVertex2f(1080, 180);
    glVertex2f(1070, 200);
    glVertex2f(910, 200);
	glEnd();

	glBegin(GL_QUADS);
    if(night == false) glColor3f(0.145f, 0.695f, 0.855f);
    else glColor3f(0.737f, 0.701f, 0.0f);
	glVertex2f(910, 230);
	glVertex2f(1050, 230);
    glVertex2f(1040, 250);
    glVertex2f(910, 250);
	glEnd();

	// round windows
	if(night == false) glColor3f(0.035f, 0.255f, 0.388f);
	else  glColor3f(0.737f, 0.701f, 0.0f);
	for(int i=0; i<=390; i+=35)
	{
	    drawCircle(710+i, 150, 7, 100);
	}

	//add containers
	if(night == false)
    {
        drawContainer(680, 170, "p");
        drawContainer(780, 170, "y");
        drawContainer(685, 220, "r");
        if(liftContainer)
        {
            glPushMatrix();
            glTranslatef(0.0f, moveContainer, 0.0f);
            drawContainer(785, 220, "b");
            glPopMatrix();
        }
        else
        {
            drawContainer(785, 220, "b");
        }
    }
}

void drawCurvedRectangle(float width, float height, float curveFactor) {
    int segments = 30;

    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= segments; i++) {
        float t = (float)i / segments;

        float x1 = -width / 2 - curveFactor * sin(t * 3.14159f);
        float y1 = -height / 2 + t * height;

        float x2 = width / 2 - curveFactor * sin(t * 3.14159f);
        float y2 = -height / 2 + t * height;

        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    }
    glEnd();
}

void drawPirateShip()
{
    // bottom of ship
    glBegin(GL_QUADS);
    glColor3f(0.486f, 0.294f, 0.043f);
	glVertex2f(700, 80);
	glVertex2f(1100, 80);
	glVertex2f(1100, 90);
	glVertex2f(700, 90);
	glEnd();

	//body of ship
	glBegin(GL_QUADS);
    glColor3f(0.192f, 0.122f, 0.032f);
	glVertex2f(700, 90);
	glVertex2f(1100, 90);
	glVertex2f(1140, 150);
	glVertex2f(660, 150);
	glEnd();

	drawContainer(760, 150, "p");
    drawContainer(890, 150, "y");

    //left sail stick
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.376f, 0.243f, 0.161f);
    glVertex2f(720, 150);
    glVertex2f(720, 275);
    glEnd();

    //left sail
    glColor3f(0.137f, 0.133f, 0.125f);
	glPushMatrix();
    glTranslatef(725, 230, 0);
    drawCurvedRectangle(80, 80, 20);
    glPopMatrix();

    //right sail stick
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.376f, 0.243f, 0.161f);
    glVertex2f(1060, 150);
    glVertex2f(1060, 275);
    glEnd();

    //right sail
    glColor3f(0.137f, 0.133f, 0.125f);
	glPushMatrix();
    glTranslatef(1065, 230, 0);
    drawCurvedRectangle(80, 80, 20);
    glPopMatrix();

    //middle sail stick
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.376f, 0.243f, 0.161f);
    glVertex2f(880, 150);
    glVertex2f(880, 375);
    glEnd();

    //middle sail
    glColor3f(0.137f, 0.133f, 0.125f);
	glPushMatrix();
    glTranslatef(885, 230, 0);
    drawCurvedRectangle(110, 90, 20);
    glPopMatrix();

    glColor3f(0.137f, 0.133f, 0.125f);
	glPushMatrix();
    glTranslatef(885, 330, 0);
    drawCurvedRectangle(90, 80, 20);
    glPopMatrix();

    //pirate flag
    glPointSize(3.0f);
    glBegin(GL_POINTS);
    int currY = 350;
        for(int i = 0; i < 14; i++){
            for(int j = 0; j < 18; j++){
                if(pirate[i][j] == '0')
                {
                    //skip
                }
                else if(pirate[i][j] == '1'){
                    glColor3f(1.0f, 1.0f, 1.0f);
                    glVertex2f(j*3+845, currY);
                }
            }
            currY -= 3;
        }
    glEnd();


    //railing part of ship
	glBegin(GL_QUADS);
    glColor3f(0.192f, 0.122f, 0.032f);
	glVertex2f(660, 150);
	glVertex2f(740, 150);
	glVertex2f(740, 180);
	glVertex2f(660, 180);
	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.192f, 0.122f, 0.032f);
	glVertex2f(1000, 150);
	glVertex2f(1140, 150);
	glVertex2f(1140, 180);
	glVertex2f(1000, 180);
	glEnd();

	// round windows
	glColor3f(0.737f, 0.701f, 0.0f);
	for(int i=0; i<=340; i+=50)
	{
	    drawCircle(750+i, 130, 9, 100);
	}
}


void drawStars()
{
    glPointSize(starSize);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);
    glVertex2f(100, 680);
    glVertex2f(200, 580);
    glVertex2f(300, 650);
    glVertex2f(400, 630);
    glVertex2f(500, 600);
    glVertex2f(600, 660);
    glVertex2f(700, 540);
    glVertex2f(650, 460);
    glVertex2f(750, 440);
    glVertex2f(800, 610);
    glVertex2f(520, 700);
    glVertex2f(640, 560);
    glVertex2f(750, 500);
    glVertex2f(680, 490);
    glVertex2f(710, 470);
    glVertex2f(850, 650);
    glEnd();

    glPointSize(starSize1);
    glBegin(GL_POINTS);
    glVertex2f(900, 620);
    glVertex2f(1000, 640);
    glVertex2f(1100, 500);
    glVertex2f(1200, 680);
    glVertex2f(1300, 660);
    glVertex2f(140, 580);
    glVertex2f(240, 590);
    glVertex2f(180, 540);
    glVertex2f(280, 510);
    glVertex2f(530, 690);
    glVertex2f(1200, 600);
    glVertex2f(240, 480);

    glEnd();
}

void drawCrane()
{
    if(night == false) glColor3f(0.91, 0.87, 0.15);
    else glColor3f(0.737, 0.702, 0.0);
    //cross lines base
    bool right = true;
    glLineWidth(8);
    glBegin(GL_LINES);
    for(int i = 240; i<420; i+=30)
    {
        if(right == true)
        {
            glVertex2f(700, i);
            glVertex2f(750, i+30);
            right = false;
        }
        else
        {
           glVertex2f(750, i);
           glVertex2f(700, i+30);
           right = true;
        }
    }
    glEnd();

    //top part
    glBegin(GL_QUADS);
    glVertex2f(680, 420);
    glVertex2f(770, 420);
    glVertex2f(770, 470);
    glVertex2f(680, 470);
    glEnd();

    //cross lines hand
    bool up = true;
    glLineWidth(8);
    glBegin(GL_LINES);
    for(int i = 770; i<950; i+=30)
    {
        if(up == true)
        {
            glVertex2f(i, 430);
            glVertex2f(i+30, 460);
            up = false;
        }
        else
        {
           glVertex2f(i, 460);
           glVertex2f(i+30, 430);
           up = true;
        }
    }
    glEnd();

    glLineWidth(8);
    glBegin(GL_LINES);
    //body
    glVertex2f(700, 240);
    glVertex2f(700, 420);
    glVertex2f(750, 240);
    glVertex2f(750, 420);
    //hand
    glVertex2f(770, 430);
    glVertex2f(950, 430);
    glVertex2f(770, 460);
    glVertex2f(920, 460);

    //hand wire left
    glColor3f(0.18, 0.12, 0.15);
    glVertex2f(890, 425);
    glVertex2f(915, 370);
    glVertex2f(940, 425);
    glVertex2f(915, 370);
    glEnd();

    //hand wire base
    glBegin(GL_QUADS);
    glVertex2f(900, 370);
    glVertex2f(930, 370);
    glVertex2f(930, 380);
    glVertex2f(900, 380);
    glEnd();

    //hand wire round
    float wireRadius = 15.0f;
    int numSegments = 30;

    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= numSegments; i++) {
        float angle = 1.0f * M_PI * i / numSegments;
        glVertex2f(915 + wireRadius * cos(angle + M_PI * 1), 375 + wireRadius * sin(angle - M_PI * 1));
    }
    glEnd();

    //hook
    glBegin(GL_LINES);
    glVertex2f(915, 375);
    glVertex2f(915, hookLength);
    glEnd();

    //base
    if(night == false) glColor3f(0.58, 0.58, 0.58);
    else glColor3f(0.353, 0.310, 0.318);
    glBegin(GL_QUADS);
    glVertex2f(680, 230);
    glVertex2f(770, 230);
    glVertex2f(770, 240);
    glVertex2f(680, 240);
    glEnd();
}


void display_a()
{
    glClear(GL_COLOR_BUFFER_BIT);

	drawSky();
	drawWater();
	drawLand();

    // draw sun moon stars
	if(night == false)
    {
        glColor3f(1.0f, 1.0f, 0.0f);
        drawCircle(850.0f, 600.0f, 30.0f, 100);

        glColor3f(1.0f, 1.0f, 0.0f);
        drawRays(850.0f, 600.0f, 30.0f, 30.0f + 25.0f, 16);
    }
    else
    {
        glColor3f(0.8f, 0.8f, 0.0f);
        drawCircle(450.0f, 600.0f, 30.0f, 100);
        glColor3f(0.0, 0.2, 0.4);
        drawCircle(460.0f, 600.0f, 25.0f, 100);

        drawStars();
    }
    // end sun moon stars

    if(night)
    {
        drawBatman(590, 580, 2.0f);
    }

    drawBgBuildings();

    glPushMatrix();
    glTranslatef(moveCloud1, 0.0f, 0.0f);
    drawCloud(200, 650, 25);
    drawCloud(700, 675, 20);
    drawCloud(400, 625, 18);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(moveCloud2, 0.0f, 0.0f);
    drawCloud(1000, 625, 22.5);
    drawCloud(1200, 635, 20);
    glPopMatrix();

	glPushMatrix();
    glTranslatef(moveWave, 0.0f, 0.0f);
	drawWave(25, 60, 100, "dark");
    drawWave(185, 95, 200, "light");
    drawWave(225, 30, 100, "dark");
    drawWave(400, 115, 350, "dark");
    drawWave(525, 60, 100, "dark");
    drawWave(685, 95, 200, "light");
    drawWave(725, 30, 100, "dark");
    drawWave(900, 35, 350, "dark");
    glPopMatrix();

    glPushMatrix();
    glTranslatef(moveWave2, 0.0f, 0.0f);
    drawWave(-900, 65, 250, "light");
	drawWave(-1100, 25, 200, "dark");
	drawWave(-1200, 95, 150, "dark");
	drawWave(-100, 35, 250, "light");
	drawWave(-300, 75, 200, "dark");
	drawWave(-400, 105, 150, "dark");
	glPopMatrix();

	glPushMatrix();
    glTranslatef(580, 0.0f, 0.0f);
    drawPortBuilding();
    glPopMatrix();

	drawContainer(600, 230, "b");
	drawContainer(700, 230, "p");
	drawContainer(800, 230, "r");
	drawContainer(900, 230, "p");
    drawContainer(1200, 230, "r");
    drawContainer(1300, 230, "b");
	drawContainer(850, 280, "y");
	if(night == false)
    {
        drawContainer(400, 230, "y");
        drawContainer(500, 230, "r");
        drawContainer(300, 230, "p");
        drawContainer(1100, 230, "y");
        drawContainer(1000, 230, "b");
        drawContainer(1050, 280, "b");
        drawContainer(1150, 280, "y");
        drawContainer(1300, 280, "p");
        drawContainer(1100, 330, "r");
        drawContainer(320, 280, "r");
        drawContainer(430, 280, "b");
        drawContainer(580, 280, "y");
        drawContainer(730, 280, "p");
    }

	drawCrane();

	if (night == false)
    {
        glPushMatrix();
        glTranslatef(moveShip, -50.0f, 0.0f);
        drawShip();
        glPopMatrix();
    }
    else
    {
        glPushMatrix();
        glTranslatef(80, 0.0f, 0.0f);
        drawShip();
        glPopMatrix();
    }

    if(night)
    {
        glPushMatrix();
        glScalef(0.7f, 0.7f, 1.0f);
        glTranslatef(movePirateShip, -70.0f, 0.0f);
        drawPirateShip();
        glPopMatrix();
    }

    if(!night)
    {
        glPushMatrix();
        glTranslatef(birdmove1, 0.0f, 0.0f);
        drawBird(100, 500);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(birdmove4, 0.0f, 0.0f);
        drawBird(700, 480);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(birdmove5, 0.0f, 0.0f);
        drawBird(900, 520);
        glPopMatrix();
    }


	glutSwapBuffers();
	//glFlush();
}


///////////////////////////////////////////////////////// 2nd Scene End /////////////////////////////////////////////////////////





///////////////////////////////////////////////////////// 3rd Scene Start /////////////////////////////////////////////////////////


float move_shipPosition = 0.0f;
float cloudMovePosition = 0.0f;
float sunMovePosition = 0.0f;
float carMovePosition = 0.0f;
float shipmove = 0.0f ;
float move_wave = 0.0f ;
float move_fish =0.0f ;
bool isDay = true;
bool isCarRunning = false;
bool isYellow = false;

float ropeLength = 590.0f;
float containerLength = 590.0f;
float containerX = 0.0f;

void drawWater_s() {
    if (isDay) {
        glBegin(GL_QUADS);
        glColor3f(0.149, 0.847, 0.866);
        glVertex2f(0, 0);
        glVertex2f(1400, 0);
        glVertex2f(1400, 340);
        glVertex2f(0, 340);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.149, 0.847, 0.866);
        glVertex2f(900, 340);
        glVertex2f(1400, 340);
        glVertex2f(1400, 430);
        glVertex2f(900, 430);
        glEnd();
    } else {
        glBegin(GL_QUADS);
        glColor3f(0.0, 0.1, 0.2);
        glVertex2f(0, 0);
        glVertex2f(1400, 0);
        glVertex2f(1400, 340);
        glVertex2f(0, 340);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.0, 0.1, 0.2);
        glVertex2f(900, 340);
        glVertex2f(1400, 340);
        glVertex2f(1400, 430);
        glVertex2f(900, 430);
        glEnd();
    }
}


void drawWheel(float x, float y) {
glColor3f(0.0, 0.0, 0.0);
glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180;
        glVertex2f(x + cos(angle) * 10, y + sin(angle) * 10);
    }
    glEnd();

}
void drawCar() {

glPushMatrix();
glTranslatef(carMovePosition, 0.0f, 0.0f);
glBegin(GL_QUADS);
glColor3f(0.0, 0.0, 1.0);
glVertex2f(640, 440);
glVertex2f(800, 440);
glVertex2f(800, 470);
glVertex2f(640, 470);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0, 0.0, 1.0);
glVertex2f(640, 470);
glVertex2f(690, 470);
glVertex2f(690, 500);
glVertex2f(660, 500);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0, 1.0, 1.0);
glVertex2f(665, 475);
glVertex2f(680, 475);
glVertex2f(680, 485);
glVertex2f(665, 485);
glEnd();


drawWheel(660, 440);
drawWheel(740, 440);
drawWheel(690, 440);
drawWheel(780, 440);
glPopMatrix();

}

void drawContainer_s(float x, float y, float width, float height, float r, float g, float b) {

glColor3f(r, g, b);
glBegin(GL_QUADS);
glVertex2f(x, y);
glVertex2f(x + width, y);
glVertex2f(x + width, y + height);
glVertex2f(x, y + height);
glEnd();
glLineWidth(3.0f);
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_LINES);

int numLines = 3;
float spacing = width / (4);

for (int i = 1; i <= 3; i++) {
float lineX = x + i * spacing;
glVertex2f(lineX, y);
glVertex2f(lineX, y + height);
}

glEnd();
}

void drawLand_s() {
glBegin(GL_QUADS);
glColor3f(0.647, 0.549, 0.561);
glVertex2f(0, 340);
glVertex2f(900, 340);
glVertex2f(900, 430);
glVertex2f(0, 430);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.541, 0.471, 0.482);
glVertex2f(0, 400);
glVertex2f(900, 400);
glVertex2f(900, 410);
glVertex2f(0, 410);
glEnd();

glBegin(GL_QUADS);
for (int i = 50; i <= 850; i += 100) {
glColor3f(0.824, 0.776, 0.776);
glVertex2f(i, 340);
glVertex2f(i + 5, 340);
glVertex2f(i + 5, 430);
glVertex2f(i, 430);
}
glEnd();
if (isDay) {
drawContainer_s(160, 430, 50, 40, 0.3, 0.7, 0.4);
drawContainer_s(110, 430, 50, 40, 0.7, 0.2, 0.5);
drawContainer_s(260, 430, 50, 40, 0.0, 1.0, 1.0);
drawContainer_s(310, 430, 50, 40, 1.0, 0.0, 0.0);
drawContainer_s(360, 430, 50, 40, 1.0, 1.0, 0.0);
drawContainer_s(410, 430, 50, 40, 0.4, 0.4, 0.8);
drawContainer_s(460, 430, 50, 40, 1.0, 0.0, 0.0);
drawContainer_s(510, 430, 50, 40, 0.0, 1.0, 0.0);
drawContainer_s(560, 430, 50, 40, 1.0, 0.5, 0.0);
drawContainer_s(300, 470, 50, 40, 0.6, 0.3, 0.7);
drawContainer_s(350, 470, 50, 40, 0.8, 0.4, 0.2);
}
else {
drawContainer_s(110, 430, 50, 40, 0.2, 0.1, 0.3);
drawContainer_s(260, 430, 50, 40, 0.0, 0.3, 0.3);
drawContainer_s(310, 430, 50, 40, 0.4, 0.0, 0.0);
drawContainer_s(360, 430, 50, 40, 0.4, 0.4, 0.0);
drawContainer_s(410, 430, 50, 40, 0.2, 0.2, 0.4);
drawContainer_s(460, 430, 50, 40, 0.4, 0.0, 0.0);
drawContainer_s(510, 430, 50, 40, 0.0, 0.3, 0.0);
drawContainer_s(560, 430, 50, 40, 0.5, 0.2, 0.0);
drawContainer_s(300, 470, 50, 40, 0.3, 0.2, 0.3);
drawContainer_s(350, 470, 50, 40, 0.4, 0.2, 0.1);
drawContainer_s(400, 470, 50, 40, 0.2, 0.2, 0.4);
drawContainer_s(450, 470, 50, 40, 0.4, 0.0, 0.0);
drawContainer_s(500, 470, 50, 40, 0.0, 0.3, 0.3);
drawContainer_s(440, 510, 50, 40, 0.5, 0.2, 0.4);
drawContainer_s(340, 510, 50, 40, 0.2, 0.2, 0.4);
drawContainer_s(390, 510, 50, 40, 0.4, 0.4, 0.0);
drawContainer_s(810, 430, 50, 40, 0.5, 0.5, 0.0);

    }
}


void drawSky_s() {
    if (isDay) {
        glBegin(GL_QUADS);
        glColor3f(0.553, 0.824, 0.957);
        glVertex2f(0, 430);
        glVertex2f(1400, 430);
        glVertex2f(1400, 750);
        glVertex2f(0, 750);
        glEnd();
    } else {
        glBegin(GL_QUADS);
        glColor3f(0.1, 0.1, 0.3);
        glVertex2f(0, 430);
        glVertex2f(1400, 430);
        glVertex2f(1400, 750);
        glVertex2f(0, 750);
        glEnd();
    }
}


void drawShip_s() {
    glBegin(GL_QUADS);
    glColor3f(0.33, 0.33, 0.33);
    glVertex2f(950, 370);
    glVertex2f(1050, 370);
    glVertex2f(1050, 475);
    glVertex2f(950, 450);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.33, 0.33, 0.33);
    glVertex2f(1050, 370);
    glVertex2f(1150, 370);
    glVertex2f(1150, 450);
    glVertex2f(1050, 475);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(970, 475);
    glVertex2f(1130, 475);
    glVertex2f(1130, 550);
    glVertex2f(970, 550);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2f(970, 550);
    glVertex2f(1130, 550);
    glVertex2f(1130, 550);
    glVertex2f(1130, 475);
    glVertex2f(1130, 475);
    glVertex2f(970, 475);
    glVertex2f(970, 475);
    glVertex2f(970, 550);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(970, 520);
    glVertex2f(1130, 520);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(1010, 510);
    glVertex2f(1040, 510);
    glVertex2f(1040, 530);
    glVertex2f(1010, 530);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(1060, 510);
    glVertex2f(1090, 510);
    glVertex2f(1090, 530);
    glVertex2f(1060, 530);
    glEnd();

    if (isDay) {
        drawContainer_s(950, 475, 40, 30, 0.4, 0.4, 0.8);
        drawContainer_s(990, 475, 40, 30, 1.0, 1.0, 0.0);
        drawContainer_s(1030, 475, 40, 30, 0.4, 1.4, 1.8);
        drawContainer_s(1070, 475, 40, 30, 1.4, 1.4, 0.8);
        drawContainer_s(1100, 475, 40, 30, 1.0, 0.0, 0.0);
        drawContainer_s(980, 505, 40, 30, 1.0, 0.0, 0.0);
        drawContainer_s(1020, 505, 50, 30, 0.4, 0.4, 0.8);
        drawContainer_s(1070, 505, 50, 30, 1.0, 1.0, 0.0);
    }

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(950, 450);
    glVertex2f(1050, 475);
    glVertex2f(1050, 500);
    glVertex2f(950, 475);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(1050, 475);
    glVertex2f(1150, 450);
    glVertex2f(1150, 475);
    glVertex2f(1050, 500);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2f(950, 450);
    glVertex2f(1050, 475);
    glVertex2f(1050, 475);
    glVertex2f(1050, 500);
    glVertex2f(1050, 500);
    glVertex2f(950, 475);
    glVertex2f(950, 475);
    glVertex2f(950, 450);
    glVertex2f(1050, 475);
    glVertex2f(1150, 450);
    glVertex2f(1150, 450);
    glVertex2f(1150, 475);
    glVertex2f(1150, 475);
    glVertex2f(1050, 500);
    glVertex2f(1050, 500);
    glVertex2f(1050, 475);
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(1050, 550);
    glVertex2f(1050, 590);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(1050, 590);
    glVertex2f(1080, 575);
    glVertex2f(1050, 560);
    glEnd();
}

void secondDrawShip()
{
glPushMatrix();
glTranslatef(move_shipPosition, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3f(0.33, 0.33, 0.33);
glVertex2f(300, 100);
glVertex2f(600, 100);
glVertex2f(650, 140);
glVertex2f(250, 140);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.1, 0.1, 0.1);
glVertex2f(300, 90);
glVertex2f(600, 90);
glVertex2f(600, 100);
glVertex2f(300, 100);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(580, 140);
glVertex2f(650, 140);
glVertex2f(650, 160);
glVertex2f(580, 160);
glEnd();

if (isDay) {
drawContainer_s(310, 140, 50, 40, 0.0, 1.0, 0.0);
drawContainer_s(370, 140, 50, 40, 1.0, 1.0, 0.0);
drawContainer_s(430, 140, 50, 40, 1.0, 0.0, 0.0);
drawContainer_s(490, 140, 50, 40, 1.0, 1.0, 0.0);
drawContainer_s(340, 180, 50, 40, 0.5, 0.5, 0.5);
drawContainer_s(400, 180, 50, 40, 0.0, 0.0, 1.0);
drawContainer_s(460, 180, 50, 40, 0.5, 0.5, 0.5);
}
else {
drawContainer_s(310, 140, 50, 40, 0.1, 0.3, 0.1);
drawContainer_s(370, 140, 50, 40, 0.3, 0.3, 0.0);
drawContainer_s(430, 140, 50, 40, 0.3, 0.0, 0.0);
drawContainer_s(490, 140, 50, 40, 0.3, 0.3, 0.0);
drawContainer_s(400, 180, 50, 40, 0.0, 0.0, 0.3);
}

glPopMatrix();
}
void thirdDrawShip() {
    glPushMatrix();

    if (isDay) {
        glTranslatef(shipmove, 0.0f, 0.0f);
    }

    glBegin(GL_QUADS);
    glColor3f(0.33, 0.33, 0.33);
    glVertex2f(300, 300);
    glVertex2f(600, 300);
    glVertex2f(650, 340);
    glVertex2f(250, 340);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(300, 290);
    glVertex2f(600, 290);
    glVertex2f(600, 300);
    glVertex2f(300, 300);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(250, 340);
    glVertex2f(300, 340);
    glVertex2f(300, 360);
    glVertex2f(250, 360);
    glEnd();

    if (isDay) {

        drawContainer_s(310, 340, 50, 40, 0.7, 0.9, 0.3);
        drawContainer_s(370, 340, 50, 40, 0.9, 0.8, 0.1);
        drawContainer_s(430, 340, 50, 40, 0.9, 0.3, 0.3);
        drawContainer_s(490, 340, 50, 40, 0.7, 0.6, 0.2);
        drawContainer_s(340, 380, 50, 40, 0.2, 0.5, 0.8);
        drawContainer_s(400, 380, 50, 40, 0.1, 0.3, 0.7);
        drawContainer_s(460, 380, 50, 40, 0.5, 0.2, 0.8);
    } else {

glBegin(GL_QUADS);
   glColor3f(0.6f, 0.3f, 0.1f);
    glVertex2f(420, 340);
    glVertex2f(480, 340);
    glVertex2f(500, 370);
    glVertex2f(400, 370);
    glEnd();

    }

    glPopMatrix();
}

void drawFish(float x, float y) {

    if (isDay) {
        return ;
    }
    else {
    glPushMatrix ();
glTranslatef(move_fish, 0.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.2); // Body color
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159 / 180;
        glVertex2f(x + cos(angle) * 20.0f, y + sin(angle) * 10.0f); // Draw ellipse body at (x, y)
    }
    glEnd();

    // Fish tail (triangle)
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 0.0); // Tail color
    glVertex2f(x - 20.0f, y);  // Tail base left
    glVertex2f(x - 35.0f, y + 5.0f); // Tail top
    glVertex2f(x - 35.0f, y - 5.0f); // Tail bottom
    glEnd();

    glPopMatrix ();
    }
}


void drawCrane_s() {
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(700.0f, 430.0f);
glVertex2f(720.0f, 430.0f);
glVertex2f(720.0f, 650.0f);
glVertex2f(700.0f, 650.0f);
glEnd();

glBegin(GL_QUADS);
glVertex2f(650.0f, 600.0f);
glVertex2f(780.0f, 600.0f);
glVertex2f(780.0f, 620.0f);
glVertex2f(650.0f, 620.0f);
glEnd();

glColor3f(0.65f, 0.33f, 0.16f);
glBegin(GL_LINES);
glVertex2f(760.0f, 600.0f);
glVertex2f(760.0f, ropeLength);
glEnd();
if(isDay){
    drawContainer_s(735, containerLength - 40.0f, 50.0f, 40.0f, 0.3f, 0.7f, 0.4f);
}
else{
    drawContainer_s(735, containerLength - 40.0f, 50.0f, 40.0f, 0.0f, 0.0f, 0.2f);
}

}

void drawCloud_s(float x, float y) {
glPushMatrix();
glTranslatef (cloudMovePosition,0.0f, 0.0f);

glColor3f(0.9f, 0.9f, 0.9f);
glBegin(GL_POLYGON);
for (int i = 0; i <= 360; i++) {
float angle = i * 3.14159 / 180;
glVertex2f(x + cos(angle) * 30, y + sin(angle) * 20);
}
glEnd();

glBegin(GL_POLYGON);
for (int i = 0; i <= 360; i++) {
float angle = i * 3.14159 / 180;
glVertex2f(x + 40 + cos(angle) * 30, y + sin(angle) * 20);
}
glEnd();

glBegin(GL_POLYGON);
for (int i = 0; i <= 360; i++) {
float angle = i * 3.14159 / 180;
glVertex2f(x +20+ cos(angle) * 30, y-20 + sin(angle) * 10);
}
glEnd();

glBegin(GL_POLYGON);
for (int i = 0; i <= 360; i++) {
float angle = i * 3.14159 / 180;
glVertex2f(x +10+cos(angle) * 20, y +20+ sin(angle) * 10);
}
glEnd();

glBegin(GL_POLYGON);
for (int i = 0; i <= 360; i++) {
float angle = i * 3.14159 / 180;
glVertex2f(x +30+ cos(angle) * 20, y +20+ sin(angle) * 10);
}
glEnd();


glPopMatrix();
}

void drawSun_s(float x, float y) {

    if (isDay) {
        glPushMatrix();
        glTranslatef(0.0f, sunMovePosition, 0.0f);
        glColor3f(1.0f, 1.0f, 0.0f);
        glBegin(GL_POLYGON);
        for (int i = 0; i <= 360; i++) {
            float angle = i * 3.14159 / 180;
            glVertex2f(x + cos(angle) * 50, y + sin(angle) * 50);
        }
        glEnd();
        glPopMatrix();
    }

    else {
        glPushMatrix();
        glTranslatef(0.0f, sunMovePosition, 0.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_POLYGON);
        for (int i = 0; i <= 360; i++) {
            float angle = i * 3.14159 / 180;
            glVertex2f(x + cos(angle) * 50, y + sin(angle) * 50);
        }
        glEnd();
        glPopMatrix();
    }
}

    void drawwave_s(float x, float y) {

    glPushMatrix ();
    glTranslatef (move_wave, 0.0f,0.0f);
    if (isDay) {
    glColor3f(0.145f, 0.694f, 0.855f); }

    else {glColor3f(1.0f, 1.0f, 1.0f);
}
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 180; i++) {
        float angle = i * 3.14159 / 180;
        glVertex2f(x + cos(angle) * 50, y + sin(angle) * 15);
    }
    glEnd();


    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 180; i++) {
        float angle = i * 3.14159 / 180;
        glVertex2f(x + 100 + cos(angle) * 50, y - sin(angle) * 15);
    }
    glEnd();


    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 180; i++) {
        float angle = i * 3.14159 / 180;
        glVertex2f(x + 200 + cos(angle) * 50, y + sin(angle) * 15);
    }
    glEnd();
    glPopMatrix () ;
}

void drawWarehouse() {

    if (isDay){
glBegin(GL_QUADS);
glColor3f(1.0f, 0.647f, 0.0f);
glVertex2f(-600, 430);
glVertex2f(140, 430);
glVertex2f(140, 580);
glVertex2f(-60, 580);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.6f, 0.3f, 0.0f);
glVertex2f(-60, 580);
glVertex2f(140, 580);
glVertex2f(40, 620);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.9f, 0.9f, 0.9f);
glVertex2f(-10, 430);
glVertex2f(80, 430);
glVertex2f(80, 500);
glVertex2f(-10, 500);
glEnd();

drawContainer_s(-5, 440, 40, 20, 0.0f, 0.5f, 0.0f);
drawContainer_s(20, 440, 40, 20, 0.0f, 0.0f, 1.0f);
drawContainer_s(10, 460, 40, 20, 1.0f, 0.0f, 1.0f);

glLineWidth (1);
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-60, 580);
glVertex2f(140, 580);
glVertex2f(140, 580);
glVertex2f(40, 620);
glVertex2f(-60, 580);
glVertex2f(40, 620);
glVertex2f(-600, 430);
glVertex2f(140, 430);
glVertex2f(140, 430);
glVertex2f(140, 580);
glVertex2f(140, 580);
glVertex2f(-60, 580);
glVertex2f(-60, 580);
glVertex2f(-600, 430);
glVertex2f(-10, 430);
glVertex2f(80, 430);
glVertex2f(80, 430);
glVertex2f(80, 500);
glVertex2f(80, 500);
glVertex2f(-10, 500);
glVertex2f(-10, 500);
glVertex2f(-10, 430);
glEnd();
    }
else {
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.2f, 0.1f);
    glVertex2f(-600, 430);
    glVertex2f(140, 430);
    glVertex2f(140, 580);
    glVertex2f(-60, 580);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.1f, 0.0f);
    glVertex2f(-60, 580);
    glVertex2f(140, 580);
    glVertex2f(40, 620);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-10, 430);
    glVertex2f(80, 430);
    glVertex2f(80, 500);
    glVertex2f(-10, 500);
    glEnd();

    drawContainer_s(-5, 440, 40, 20, 0.1f, 0.2f, 0.1f);
    drawContainer_s(20, 440, 40, 20, 0.0f, 0.0f, 0.2f);

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-60, 580);
    glVertex2f(140, 580);
    glVertex2f(140, 580);
    glVertex2f(40, 620);
    glVertex2f(-60, 580);
    glVertex2f(40, 620);
    glVertex2f(-600, 430);
    glVertex2f(140, 430);
    glVertex2f(140, 430);
    glVertex2f(140, 580);
    glVertex2f(140, 580);
    glVertex2f(-60, 580);
    glVertex2f(-60, 580);
    glVertex2f(-600, 430);
    glVertex2f(-10, 430);
    glVertex2f(80, 430);
    glVertex2f(80, 430);
    glVertex2f(80, 500);
    glVertex2f(80, 500);
    glVertex2f(-10, 500);
    glVertex2f(-10, 500);
    glVertex2f(-10, 430);
    glEnd();
}

}

void drawcircle(float x, float y, float radius) {
    glBegin(GL_TRIANGLE_FAN);

    if (isYellow) {
        glColor3f(1.0f, 1.0f, 0.0f);
    } else {
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    glVertex2f(x, y);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159f / 180.0f;
        float dx = cos(angle) * radius;
        float dy = sin(angle) * radius;
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}
void drawlamp () {
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(220, 430);
    glVertex2f(240, 430);
    glVertex2f(240, 600);
    glVertex2f(220, 600);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(180, 600);
    glVertex2f(280, 600);
    glVertex2f(230, 650);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_LINES);
    glVertex2f(200, 600);
    glVertex2f(200, 570);
    glVertex2f(260, 600);
    glVertex2f(260, 570);
    glEnd();

    drawcircle(200, 570, 15);
    drawcircle(260, 570, 15);
}


void timer(int value) {

move_shipPosition -= 10.0f;

if (move_shipPosition < -1400) {
move_shipPosition = +1800;
}

shipmove += 5.0f;

if (shipmove >1800) {
shipmove = -1800;
}

cloudMovePosition += 1.0f;

if (cloudMovePosition >1400) {
cloudMovePosition = -1400;
}

sunMovePosition += 1.0f;

if (sunMovePosition >750) {
sunMovePosition = -50;
}

carMovePosition -= 0.01f;

if (carMovePosition < -1400) {
 return;
}

move_wave += 0.5f;

if (move_wave >1400) {
move_wave = -1400;
}

move_fish += 3.0f;

if (move_fish >1400) {
move_fish = 0.0f;
}

glutPostRedisplay();
glutTimerFunc(30, timer, 0);
}

void ropetimer(int value) {
ropeLength -= 0.5f;
if (ropeLength <= 510.0f) {
ropeLength = 510.0f;
containerLength = 510.0f;
return;
}

if(containerLength <= 510.0f)
{
    containerX -= 0.5f;
}

containerLength = ropeLength;

glutPostRedisplay();
glutTimerFunc(30, ropetimer, 0);
}


void display_s() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawSky_s();

    drawSun_s(1230, 430);
    //drawCloud(50, 640);
    drawCloud_s(650, 710);
    drawCloud_s(800, 670);
    drawCloud_s(150, 600);
    drawCloud_s(700, 650);
    drawCloud_s(1100, 720);
    drawCloud_s(300, 650);
    drawCloud_s(350, 660);
    drawCloud_s(400, 650);
    drawWater_s();
    drawFish(100, 200); // Fish at (100, 200)
    drawFish(200, 300); // Fish at (200, 300)
    drawFish(300, 250); // Fish at (300, 250)
    drawFish(400, 350); // Fish at (400, 350)
    drawFish(500, 150); // Fish at (500, 150)
    drawFish(600, 275); // Fish at (600, 275)
    drawFish(700, 325); // Fish at (700, 325)
    drawFish(800, 175); // Fish at (800, 175)
    drawFish(900, 400); // Fish at (900, 400)

    drawwave_s(100, 100);
    drawwave_s(500, 100);
    drawwave_s(1100, 100);
    drawwave_s(600, 300);
    drawwave_s(150, 300);
    drawwave_s(1000, 300);
    drawwave_s(1000, 400);
    drawShip_s();
    secondDrawShip();
    thirdDrawShip();
    drawCrane_s();
    drawWarehouse();
    drawLand_s();
    drawlamp ();
    drawCar();
    thirdDrawShip();

    //glFlush();
    glutSwapBuffers();
}


///////////////////////////////////////////////////////// 3rd Scene End ///////////////////////////////////////////////////////////






///////////////////////////////////////////////////////// 4th Scene Start /////////////////////////////////////////////////////////

float move_shipPosition_ss=0.0f ;
float move_shipPosition2=0.0f ;
float move_car=0.0f;
float move_cloud=0.0f ;
float move_sun=0.0f;
float move_wave_ss=0.0f ;
float move_plane= 0.0f ;
bool isDay_ss = true;
bool isYellow_ss = false;

void drawsky_ss() {
    glBegin(GL_QUADS);


    if (isDay_ss) {
        glColor3f(0.529, 0.808, 0.922);
    } else {
        glColor3f(0.1, 0.1, 0.3);
    }

    glVertex2f(0, 550);
    glVertex2f(1400, 550);
    glVertex2f(1400, 750);
    glVertex2f(0, 750);
    glEnd();
}

void drawplane() {

    if (isDay_ss) {
        return ;
    }
else {
    glPushMatrix () ;
    glTranslatef (move_plane, 0.0f,0.0f);

glBegin(GL_QUADS);
 glColor3f(1.0,1.0, 1.0);
 glVertex2f(100, 650);
    glVertex2f(300, 650);
    glVertex2f(300, 700);
    glVertex2f(100, 700);
    glEnd();

    glBegin(GL_QUADS);
 glColor3f(1.0f, 1.0f, 0.0f);
 glVertex2f(120, 680);
    glVertex2f(140, 680);
    glVertex2f(140, 690);
    glVertex2f(120, 690);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
 glVertex2f(150, 680);
    glVertex2f(170, 680);
    glVertex2f(170, 690);
    glVertex2f(150, 690);
    glEnd();

      glBegin(GL_QUADS);
 glColor3f(1.0f, 1.0f, 0.0f);
 glVertex2f(180, 680);
    glVertex2f(200, 680);
    glVertex2f(200, 690);
    glVertex2f(180, 690);
    glEnd();

      glBegin(GL_QUADS);
 glColor3f(1.0f, 1.0f, 0.0f);
 glVertex2f(220, 680);
    glVertex2f(240, 680);
    glVertex2f(240, 690);
    glVertex2f(220, 690);
    glEnd();


      glBegin(GL_QUADS);
 glColor3f(1.0f, 1.0f, 0.0f);
 glVertex2f(250, 680);
    glVertex2f(270, 680);
    glVertex2f(270, 690);
    glVertex2f(250, 690);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(1.0,1.0, 1.0);

    glVertex2f(300, 650);
    glVertex2f(400, 720);
    glVertex2f(380, 720);
    glVertex2f(300, 700);
    glEnd();

    glBegin(GL_TRIANGLES);
 glColor3f(1.0,1.0, 1.0);
 glVertex2f(50, 675);
 glVertex2f(100, 650);
 glVertex2f(100, 700);
    glEnd();

   glBegin(GL_QUADS);
 glColor3f(0.1,0.1, 0.1);
  glVertex2f(210, 610);
   glVertex2f(240, 610);
 glVertex2f(200, 670);
 glVertex2f(170, 670);

 glBegin(GL_QUADS);
 glColor3f(0.1,0.1, 0.1);
  glVertex2f(170, 700);
   glVertex2f(200, 700);
 glVertex2f(240, 740);
 glVertex2f(210, 740);

    glEnd();

glPopMatrix ();
}

}
void drawHill() {
    glBegin(GL_TRIANGLES);
    if (isDay_ss) {
        glColor3f(0.0,0.8, 0.0);
    } else {
        glColor3f(0.0, 0.5,0.0 );
    }

    glVertex2f(300,550);
    glVertex2f(800,550);
    glVertex2f(550,700);


    glEnd();
}

void drawHill2() {
    glBegin(GL_TRIANGLES);
    if (isDay_ss) {
        glColor3f(0.0, 0.5, 0.0);
    } else {
        glColor3f(34.0/255.0, 139.0/255.0, 34.0/255.0);

    }

    glVertex2f(500,550);
    glVertex2f(1000,550);
    glVertex2f(800,700);


    glEnd();
}

void drawwave_ss(float x, float y, float width, float height) {

    glPushMatrix();
    glTranslatef(move_wave ,0.0f,0.0f);
     if (isDay_ss) {
        glColor3f(0.0f, 0.0f, 0.5f);
    } else {
        glColor3f(0.678f, 0.847f, 0.902f);
    }
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
    glPopMatrix () ;
}
void drawSea_ss() {
    glBegin(GL_QUADS);

    if (isDay_ss) {
        glColor3f(0.149, 0.847, 0.866);
    } else {
        glColor3f(0.0, 0.0, 0.3);
    }

    glVertex2f(0, 300);
    glVertex2f(1400, 300);
    glVertex2f(1400, 550);
    glVertex2f(0, 550);
    glEnd();
drawwave_ss(0, 420, 150, 10);
drawwave_ss(120, 350, 150, 10);
drawwave_ss(240, 500, 150, 10);
drawwave_ss(360, 310, 150, 10);
drawwave_ss(400, 325, 150, 10);
drawwave_ss(520, 450, 150, 10);
drawwave_ss(640, 370, 150, 10);
drawwave_ss(760, 530, 150, 10);
drawwave_ss(880, 475, 150, 10);
drawwave_ss(1000, 420, 150, 10);
drawwave_ss(1120, 350, 150, 10);
drawwave_ss(1240, 500, 150, 10);
drawwave_ss(1360, 310, 150, 10);




}

void drawContainer_ss(float x, float y, float width, float height, float r, float g, float b) {

glColor3f(r, g, b);
glBegin(GL_QUADS);
glVertex2f(x, y);
glVertex2f(x + width, y);
glVertex2f(x + width, y + height);
glVertex2f(x, y + height);
glEnd();
glLineWidth(3.0f);
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_LINES);

int numLines = 3;
float spacing = width / (4);

for (int i = 1; i <= 3; i++) {
float lineX = x + i * spacing;
glVertex2f(lineX, y);
glVertex2f(lineX, y + height);
}

glEnd();
}

void drawland_ss() {
    glBegin(GL_QUADS);
    glColor3f(0.647, 0.549, 0.561);
    glVertex2f(0, 0);
    glVertex2f(1400, 0);
    glVertex2f(1400, 300);
    glVertex2f(0, 300);
    glEnd();


}
void landcontainer_ss () {

    if (isDay_ss) {
        drawContainer_ss(1140, 0, 60, 40, 1.0f, 0.647f, 0.0f);
        drawContainer_ss(1200, 0, 60, 40, 0.0f, 0.0f, 1.0f);
        drawContainer_ss(1260, 0, 60, 40, 1.0f, 0.0f, 0.0f);
        drawContainer_ss(1320, 0, 60, 40, 0.0f, 1.0f, 0.0f);
        drawContainer_ss(1160, 40, 60, 40, 1.0f, 1.0f, 0.0f);
        drawContainer_ss(1220, 40, 60, 40, 1.0f, 0.647f, 0.0f);
        drawContainer_ss(1280, 40, 60, 40, 0.0f, 0.0f, 0.0f);
        drawContainer_ss(1400, 40, 60, 40, 0.0f, 0.5f, 0.5f);
        drawContainer_ss(1260, 80, 60, 40, 0.2f, 0.6f, 0.2f);
        drawContainer_ss(1200, 80, 60, 40, 0.6f, 0.2f, 0.6f);

        drawContainer_ss(0, 0, 60, 40, 1.0f, 0.647f, 0.0f);
        drawContainer_ss(60, 0, 60, 40, 0.0f, 0.0f, 1.0f);
        drawContainer_ss(120, 0, 60, 40, 1.0f, 0.0f, 0.0f);
        drawContainer_ss(180, 0, 60, 40, 0.0f, 1.0f, 0.0f);
        drawContainer_ss(50, 40, 60, 40, 1.0f, 1.0f, 0.0f);
        drawContainer_ss(110, 40, 60, 40, 1.0f, 0.647f, 0.0f);
        drawContainer_ss(170, 40, 60, 40, 0.0f, 0.0f, 0.0f);
        drawContainer_ss(100, 80, 60, 40, 0.2f, 0.6f, 0.2f);
        drawContainer_ss(160, 80, 60, 40, 0.6f, 0.2f, 0.6f);
    }

    else {
        drawContainer_ss(1140, 0, 60, 40, 0.5f, 0.5f, 0.5f);
        drawContainer_ss(1200, 0, 60, 40, 0.2f, 0.2f, 0.2f);
        drawContainer_ss(1260, 0, 60, 40, 0.8f, 0.0f, 0.0f);
        drawContainer_ss(1320, 0, 60, 40, 0.0f, 0.4f, 0.0f);
        drawContainer_ss(1160, 40, 60, 40, 0.7f, 0.7f, 0.0f);
        drawContainer_ss(1220, 40, 60, 40, 0.7f, 0.4f, 0.2f);
        drawContainer_ss(1280, 40, 60, 40, 0.1f, 0.1f, 0.1f);
        drawContainer_ss(1400, 40, 60, 40, 0.0f, 0.2f, 0.2f);
        drawContainer_ss(1260, 80, 60, 40, 0.1f, 0.3f, 0.1f);
        drawContainer_ss(1200, 80, 60, 40, 0.4f, 0.1f, 0.4f);

        drawContainer_ss(0, 0, 60, 40, 0.5f, 0.5f, 0.5f);
        drawContainer_ss(60, 0, 60, 40, 0.2f, 0.2f, 0.2f);
        drawContainer_ss(120, 0, 60, 40, 0.8f, 0.0f, 0.0f);
        drawContainer_ss(180, 0, 60, 40, 0.0f, 0.4f, 0.0f);
        drawContainer_ss(50, 40, 60, 40, 0.7f, 0.7f, 0.0f);
        drawContainer_ss(110, 40, 60, 40, 0.7f, 0.4f, 0.2f);
        drawContainer_ss(170, 40, 60, 40, 0.1f, 0.1f, 0.1f);
        drawContainer_ss(100, 80, 60, 40, 0.1f, 0.3f, 0.1f);
        drawContainer_ss(160, 80, 60, 40, 0.4f, 0.1f, 0.4f);
    }
}

void drawBarricade() {
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    for (float x = 0; x <= 1400; x += 100) {
        glVertex2f(x, 300);
        glVertex2f(x, 350);
    }
    glEnd();

    glBegin(GL_LINES);
    for (float y = 325; y <= 350; y += 25) {
        for (float x = 0; x <= 1400; x += 100) {
            glVertex2f(x, y);
            glVertex2f(x + 100, y);
        }
    }
    glEnd();
}

void drawhouse() {
    glLineWidth(1.0f);
    if(isDay_ss){
    glBegin(GL_QUADS);
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.0);
    glVertex2f(300, 100);
    glVertex2f(700, 100);
    glVertex2f(700, 250);
    glVertex2f(300, 250);
    glEnd();
    }
    else{
    glBegin(GL_QUADS);
    glColor3f(255.0f / 255.0f, 140.0f / 255.0f, 0.0f);  // Dark Orange color
    glVertex2f(300, 100);
    glVertex2f(700, 100);
    glVertex2f(700, 250);
    glVertex2f(300, 250);
    glEnd();

    }


    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(300, 100);
    glVertex2f(700, 100);
    glVertex2f(700, 100);
    glVertex2f(700, 250);
    glVertex2f(700, 250);
    glVertex2f(300, 250);
    glVertex2f(300, 250);
    glVertex2f(300, 100);
    glEnd();



    if (isDay_ss){
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(300, 250);
    glVertex2f(700, 250);
    glVertex2f(550, 350);
    glVertex2f(150, 350);
    glEnd();
    }
 else{
    glBegin(GL_QUADS);
    glColor3f(139.0f / 255.0f, 0.0f, 0.0f);
    glVertex2f(300, 250);
    glVertex2f(700, 250);
    glVertex2f(550, 350);
    glVertex2f(150, 350);
    glEnd();

 }

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(300, 250);
    glVertex2f(700, 250);
    glVertex2f(700, 250);
    glVertex2f(550, 350);
    glVertex2f(550, 350);
    glVertex2f(150, 350);
    glVertex2f(150, 350);
    glVertex2f(300, 250);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.5, 0.2);
    glVertex2f(150, 150);
    glVertex2f(300, 100);
    glVertex2f(300, 250);
    glVertex2f(150, 350);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(150, 150);
    glVertex2f(300, 100);
    glVertex2f(300, 100);
    glVertex2f(300, 250);
    glVertex2f(300, 250);
    glVertex2f(150, 350);
    glVertex2f(150, 350);
    glVertex2f(150, 150);
    glEnd();

    if (isDay_ss) {
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(450, 100);
    glVertex2f(550, 100);
    glVertex2f(550, 200);
    glVertex2f(450, 200);
    glEnd();
    }
    else {
        glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);

    glVertex2f(450, 100);
    glVertex2f(550, 100);
    glVertex2f(550, 200);
    glVertex2f(450, 200);
    glEnd();
    }
}

void drawWheels_ss(float x, float y) {
glColor3f(0.0, 0.0, 0.0);
glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180;
        glVertex2f(x + cos(angle) * 20, y + sin(angle) * 20);
    }
    glEnd();

}


void drawcircle_ss(float x, float y, float radius) {
    glBegin(GL_TRIANGLE_FAN);

    if (isYellow_ss) {
        glColor3f(1.0f, 1.0f, 0.0f);
    } else {
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    glVertex2f(x, y);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159f / 180.0f;
        float dx = cos(angle) * radius;
        float dy = sin(angle) * radius;
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

void drawCar_ss() {
    glPushMatrix();
    glTranslatef(move_car ,0.0f,0.0f);


    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(850, 100);
    glVertex2f(1100, 100);
    glVertex2f(1100, 130);
    glVertex2f(850, 130);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(850, 130);
    glVertex2f(920, 130);
    glVertex2f(920, 160);
    glVertex2f(870, 160);
    glEnd();

    if(isDay_ss){
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(880,140);
    glVertex2f(915,140);
    glVertex2f(915,155);
    glVertex2f(880,155);
    glEnd();
    }

    else{
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(880,140);
    glVertex2f(915,140);
    glVertex2f(915,155);
    glVertex2f(880,155);
    glEnd();
    }


    drawWheels_ss(890, 90);
    drawWheels_ss(1050, 90);


    if (isDay_ss) {

        drawContainer_ss(930, 130, 60, 40, 1.0f, 1.0f, 0.0f);
        drawContainer_ss(990, 130, 60, 40, 1.0f, 0.0f, 0.0f);
        drawContainer_ss(1040, 130, 50, 40, 0.0f, 1.0f, 0.0f);
    }

    drawcircle_ss (850,110,5) ;
    drawcircle_ss (850,120,5) ;

    glPopMatrix();
}
void drawCar2() {
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(850, 200);
    glVertex2f(850, 230);
    glVertex2f(1100, 230);
    glVertex2f(1100, 200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(1030, 230);
    glVertex2f(1030, 260);
    glVertex2f(1075, 260);
    glVertex2f(1100, 230);
    glEnd();

    if(isDay_ss){
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(1035, 240);
    glVertex2f(1075, 240);
    glVertex2f(1075, 250);
    glVertex2f(1035, 250);
    glEnd();
    }

    else{
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(1035, 240);
    glVertex2f(1075, 240);
    glVertex2f(1075, 250);
    glVertex2f(1035, 250);
    glEnd();
    }





    drawWheels_ss(1050, 190);
    drawWheels_ss(890, 190);

    drawcircle_ss (1100,210,5) ;
    drawcircle_ss (1100,220,5) ;



    if (isDay_ss) {

        drawContainer_ss(880, 230, 60, 40, 1.0f, 0.0f, 0.0f);
        drawContainer_ss(950, 230, 60, 40, 0.0f, 1.0f, 0.0f);
    }
}
void drawShip_ss() {

    glPushMatrix();
    glTranslatef(move_shipPosition, 0.0f, 0.0f);


    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    glVertex2f(550, 400);
    glVertex2f(850, 400);
    glVertex2f(880, 430);
    glVertex2f(500, 430);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    glVertex2f(500, 430);
    glVertex2f(580, 430);
    glVertex2f(580, 440);
    glVertex2f(500, 440);
    glEnd();


    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(550, 400);
    glVertex2f(850, 400);
    glEnd();


    if (isDay_ss) {

        drawContainer_ss(600, 430, 60, 40, 0.0f, 1.0f, 0.0f);
        drawContainer_ss(660, 430, 60, 40, 0.0f, 0.0f, 1.0f);
        drawContainer_ss(720, 430, 60, 40, 1.0f, 0.0f, 0.0f);
        drawContainer_ss(620, 470, 60, 40, 0.0f, 1.0f, 1.0f);
        drawContainer_ss(680, 470, 60, 40, 1.0f, 0.0f, 1.0f);
    } else {

        drawContainer_ss(600, 430, 60, 40, 0.0f, 0.5f, 0.0f);
        drawContainer_ss(660, 430, 60, 40, 0.0f, 0.0f, 0.5f);
        drawContainer_ss(720, 430, 60, 40, 0.5f, 0.0f, 0.0f);
        drawContainer_ss(620, 470, 60, 40, 0.0f, 0.5f, 0.5f);
        drawContainer_ss(680, 470, 60, 40, 0.5f, 0.0f, 0.5f);
    }

    glPopMatrix();
}

void drawShip2() {

    glPushMatrix();
    glTranslatef(move_shipPosition2, 0.0f, 0.0f);


    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    glVertex2f(100, 500);
    glVertex2f(400, 500);
    glVertex2f(430, 530);
    glVertex2f(70, 530);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    glVertex2f(350, 530);
    glVertex2f(430, 530);
    glVertex2f(430, 540);
    glVertex2f(350, 540);
    glEnd();


    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(100, 500);
    glVertex2f(400, 500);
    glEnd();


    if (isDay_ss) {

        drawContainer_ss(100, 530, 60, 40, 1.0f, 0.0f, 0.0f);
        drawContainer_ss(160, 530, 60, 40, 0.0f, 1.0f, 0.0f);
        drawContainer_ss(220, 530, 60, 40, 0.0f, 0.0f, 1.0f);
        drawContainer_ss(280, 530, 60, 40, 1.0f, 1.0f, 0.0f);
    } else {

        drawContainer_ss(100, 530, 60, 40, 0.5f, 0.0f, 0.0f);
        drawContainer_ss(160, 530, 60, 40, 0.0f, 0.5f, 0.0f);
        drawContainer_ss(220, 530, 60, 40, 0.0f, 0.0f, 0.5f);
        drawContainer_ss(280, 530, 60, 40, 0.5f, 0.5f, 0.0f);
    }

    glPopMatrix();
}


void drawCloud_ss(float x, float y) {

    glPushMatrix();
    glTranslatef (move_cloud,0.0f,0.0f);
    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180;
        glVertex2f(x + cos(angle) * 30, y + sin(angle) * 20);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180;
        glVertex2f(x + 40 + cos(angle) * 30, y + sin(angle) * 20);
    }
    glEnd();

    glPopMatrix();
}
void drawSun_ss(float x, float y) {
    glPushMatrix();
    glTranslatef(move_sun, 0.0f, 0.0f);


    if (isDay_ss) {
        glColor3f(1.0f, 1.0f, 0.0f);
    } else {
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180;
        glVertex2f(x + cos(angle) * 60, y + sin(angle) * 60);
    }
    glEnd();

    glPopMatrix();
}


void display_ss() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawsky_ss();
    drawplane ();
    drawSea_ss();

    drawland_ss();

    drawBarricade();
    drawhouse();
    drawCar_ss();
    landcontainer_ss ();
    drawCar2();
    drawSun_ss(1225, 630);
    drawCloud_ss(50, 640);
    drawCloud_ss(650, 710);
    drawCloud_ss(800, 670);
    drawCloud_ss(150, 600);
    drawCloud_ss(700, 650);
    drawCloud_ss(1100, 720);
    drawHill2();
    drawHill();
    drawShip2();
    drawShip_ss();


    glFlush();
}

void timer_ss(int value) {
    move_shipPosition_ss += 5.0f;

    if (move_shipPosition_ss > 1400) {
        move_shipPosition_ss = -1800;
    }

    move_shipPosition2 -= 2.0f;

    if (move_shipPosition2 < -1400) {
        move_shipPosition2 = 1800;
    }
move_cloud += 2.0f;

    if (move_cloud >1400) {
        move_cloud = -1500;
    }

    move_wave_ss += 2.0f;

    if (move_wave_ss >1400) {
        move_wave_ss = -1500;
    }

move_car -=5.0f;
if (move_car < -1400){
    move_car = 1400;
}

move_sun+= 3.0f;

    if (move_sun > 1400) {
        move_sun = -1500;
    }

move_plane-= 3.0f;

    if (move_plane < -1400) {
        move_plane = 1500;
    }
    glutPostRedisplay();
    glutTimerFunc(16, timer_ss, 0);
}

///////////////////////////////////////////////////////// 4th Scene End ///////////////////////////////////////////////////////////

void playSound(const std::string& soundFile) {
    PlaySound(soundFile.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}
// stop sound
void stopSound() { PlaySound(NULL, NULL, 0); }

bool playing = true;
bool playing_d = true;

void display()
{
    if(scene == 1)
    {
        display_d();
    }
    else if(scene == 2)
    {
        display_a();
    }
    else if(scene == 3)
    {
        display_s();
    }
    else if(scene == 4)
    {
        display_ss();
    }
}

void keyboard(unsigned char key, int x, int y) {

    //scene transition
    switch (key) {
        case '1':
            scene = 1;
            stopSound();
            if(playing_d) playSound("seaport.wav");
            break;
        case '2':
            restart();
            scene = 2;
            stopSound();
            if(playing &&  night == false) playSound("day-2.wav");
            else if(night == true) playSound("pirates.wav");
            break;
        case '3':
            scene = 3;
            stopSound();
            break;
        case '4':
            scene = 4;
            stopSound();
            break;
    }

    //Keyboard functions for first scene
    if(scene == 1)
    {
        switch (key)
        {
            case 'N':
            case 'n':
                night_d = true;
                break;
            case 'D':
            case 'd':
                night_d = false;
                break;
            case ' ':
                waveMovementSpeed1 = 0.0f;
                waveMovementSpeed2 = 0.0f;
                waveMovementSpeed3 = 0.0f;
                sunMovementSpeed = 0.0f;
                cloudMovement1Speed = 0.0f;
                cloudMovement2Speed = 0.0f;
                shipMovementSpeed = 0.0f;
                smallShipMovementSpeed = 0.0f;
                truckMovementSpeed = 0.0f;
                moveLightSpeed = 0.0f;
                break;
            case 's':
            case 'S':
                waveMovementSpeed1 = 0.5f;
                waveMovementSpeed2 = 0.5f;
                waveMovementSpeed3 = 0.5f;
                sunMovementSpeed = 0.5f;
                cloudMovement1Speed = 1.0f;
                cloudMovement2Speed = 1.0f;
                shipMovementSpeed = 2.2f;
                smallShipMovementSpeed = 1.4f;
                truckMovementSpeed = 2.0f;
                if(lightUp) moveLightSpeed = 0.5f;
                else moveLightSpeed = -0.5f;
                break;
            case 'M':
            case 'm':
                playing_d = !playing_d;
                if(!playing_d) stopSound();
                if(playing_d)
                {
                    stopSound();
                    playSound("seaport.wav");
                }
                break;
            case 27:
                exit(0);
                break;
        }
    }

    //Keyboard functions for second scene
    if(scene == 2)
    {
        switch (key)
        {
            case 'N':
            case 'n':
                night = true;
                stopSound();
                if(playing) playSound("pirates.wav");
                break;
            case 'D':
            case 'd':
                night = false;
                stopSound();
                if(playing) playSound("day-2.wav");
                break;
            case ' ':
                moveWave_factor = 0.0f;
                moveCloud_factor = 0.0f;
                moveShip_factor = 0.0f;
                moveBird_factor = 0.0f;
                movePirateShip_factor = 0.0f;
                hookLength_changeFactor = 0.0f;
                moveContainer_factor = 0.0f;
                break;
            case 'S':
            case 's':
                moveWave_factor = 0.5f;
                moveCloud_factor = 1.0f;
                if(moveShip < 80) moveShip_factor = 2.0f;
                moveBird_factor = 2.0f;
                movePirateShip_factor = -2.0f;
                hookLength_changeFactor = 0.5f;
                moveContainer_factor = 0.5f;
                break;
            case 'R':
            case 'r':
                restart();
                break;
            case 'M':
            case 'm':
                playing = !playing;
                if(!playing) stopSound();
                if(playing)
                {
                    stopSound();
                    //playSound("./ambience.wav");
                }
                break;
            case 27:
                exit(0);
                break;
        }
    }

    //Keyboard functions for third scene
    if (scene == 3)
    {
        if (key == 'd' || key == 'D') {
            isDay = true;
        } else if (key == 'n' || key == 'N') {
            isDay = false;
        }

        if (key == 'b' || key == 'B') {
            carMovePosition += 1.0f;
        } else if (key == 'f' || key == 'F') {
            carMovePosition -= 1.0f;
        }
    }

    //Keyboard functions for fourth scene
    if (key == 'd' || key == 'D') {
        isDay_ss = true;
    } else if (key == 'n' || key == 'N') {
        isDay_ss = false;
    }

}


void mouseCallback(int button, int state, int x, int y)
{
    if(scene == 1)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            light_on = !light_on;
        }
    }
    else if(scene == 2)
    {
        if (button == GLUT_LEFT_BUTTON) {
            if (state == GLUT_DOWN)
            {
                moveWave_factor = 3*0.5f;
                moveCloud_factor = 3*1.0f;
                if(moveShip < 80) moveShip_factor = 3*2.0f;
                else if(moveShip > 80) moveShip_factor = 0.0f;
                moveBird_factor = 3*2.0f;
                if(moveContainer < 125) moveContainer_factor = 3*0.5f;
                else if(moveContainer > 125 ) moveContainer_factor = 0.0f;
                hookLength_changeFactor = 3*0.5f;
                movePirateShip_factor = -3*2.0f;
            }

            else if (state == GLUT_UP)
            {
                moveWave_factor = 0.5f;
                moveCloud_factor = 1.0f;
                if(moveShip < 80) moveShip_factor = 2.0f;
                else if(moveShip > 80) moveShip_factor = 0.0f;
                moveBird_factor = 2.0f;
                if(moveContainer < 125) moveContainer_factor = 0.5f;
                else if(moveContainer > 125) moveContainer_factor = 0.0f;
                hookLength_changeFactor = 0.5f;
                movePirateShip_factor = -2.0f;
            }
        }
        else if (button == GLUT_RIGHT_BUTTON) {
            if (state == GLUT_DOWN)
            {
                moveWave_factor = 0.5*0.5f;
                moveCloud_factor = 0.5*1.0f;
                if(moveShip < 80) moveShip_factor = 0.5*2.0f;
                else if(moveShip > 80) moveShip_factor = 0.0f;
                moveBird_factor = 0.5*2.0f;
                if(moveContainer < 125) moveContainer_factor = 0.5*0.5f;
                else if(moveContainer > 125 ) moveContainer_factor = 0.0f;
                hookLength_changeFactor = 0.5*0.5f;
                movePirateShip_factor = -0.5*2.0f;
            }

            else if (state == GLUT_UP)
            {
                moveWave_factor = 0.5f;
                moveCloud_factor = 1.0f;
                if(moveShip < 80) moveShip_factor = 2.0f;
                else if(moveShip > 80) moveShip_factor = 0.0f;
                moveBird_factor = 2.0f;
                if(moveContainer < 125) moveContainer_factor = 0.5f;
                else if(moveContainer > 125 ) moveContainer_factor = 0.0f;
                hookLength_changeFactor = 0.5f;
                movePirateShip_factor = -2.0f;
            }
        }
    }
    else if (scene == 3)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            isYellow = !isYellow;
        }
    }
    else if (scene == 4)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            isYellow_ss = !isYellow_ss;
        }
    }
}


void myInit(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluOrtho2D(0,1400,0,750);
}

int main(int argc, char** argv) {


    cout << ".----------------------------------------." << endl;
    cout << "|                                        |" << endl;
    cout << "|              SEA PORT PROJECT          |" << endl;
    cout << "|                                        |" << endl;
    cout << ".----------------------------------------." << endl;
    cout << "|      Faculty: UMME SADIA SALSABIL      |" << endl;
    cout << "|            2024-2025, FALL             |" << endl;
    cout << "|       Submission Date: 4/2/2025        |" << endl;
    cout << ".----------------------------------------." << endl;
    cout << "|                                        |" << endl;
    cout << "|               Group Members            |" << endl;
    cout << ".------------------------.---------------." << endl;
    cout << "|   NAME                 |   ID          |" << endl;
    cout << "-------------------------|---------------." << endl;
    cout << "|   SYED AL SADMAN DIP   |   22-47884-2  |" << endl;
    cout << "|                        |               |" << endl;
    cout << "|   MD. ATIKUR RAHMAN    |   22-47944-2  |" << endl;
    cout << "|                        |               |" << endl;
    cout << "|   K.M.M. SAMIN         |   22-49904-3  |" << endl;
    cout << "|                        |               |" << endl;
    cout << "|   SAIMA AKTER          |   22-49880-3  " << endl;
    cout << "`------------------------.--------------`" << endl;


    cout << endl << endl;
    cout << ".-------------------------------------------------------------.\n";
    cout << "| FIirst Scene:   SYED AL SADMAN DIP                          |\n";
    cout << ".-------------------------------------------------------------.\n";
    cout << "| KEY / MOUSE INPUT        | ACTION                           |\n";
    cout << ".-------------------------------------------------------------.\n";
    cout << "| 'N' or 'n'               | Transition to night              |\n";
    cout << "| 'D' or 'd'               | Transition to day                |\n";
    cout << "| Space                    | Stop scenery                     |\n";
    cout << "| 'S' or 's'               | Start scenery                    |\n";
    cout << "| 'M' or 'm'               | Stop/play sound                  |\n";
    cout << "| Hold 'LEFT' Mouse        | Toggle lighthouse light on/off   |\n";
    cout << "| Esc                      | Exit App                         |\n";
    cout << ".-------------------------------------------------------------.\n";


    cout << endl << endl;
    cout << ".-------------------------------------------------------------.\n";
    cout << "| Second Scene:   MD. ATIKUR RAHMAN                           |\n";
    cout << ".-------------------------------------------------------------.\n";
    cout << "| KEY / MOUSE INPUT        | ACTION                           |\n";
    cout << ".-------------------------------------------------------------.\n";
    cout << "| 'N' or 'n'               | Transition to night              |\n";
    cout << "| 'D' or 'd'               | Transition to day                |\n";
    cout << "| Space                    | Stop Movement                    |\n";
    cout << "| 'S' or 's'               | Start Movement                   |\n";
    cout << "| 'R' or 'r'               | Restart Movement                 |\n";
    cout << "| 'M' or 'm'               | Stop/play music                  |\n";
    cout << "| Hold 'LEFT' Mouse        | Speed 3x                         |\n";
    cout << "| Hold 'RIGHT' Mouse       | Speed 0.5x                       |\n";
    cout << "| Esc                      | Exit App                         |\n";
    cout << ".-------------------------------------------------------------.\n";


    cout << endl << endl;
    cout << ".-------------------------------------------------------------.\n";
    cout << "| Third Scene:   K.M.M. SAMIN                                 |\n";
    cout << ".-------------------------------------------------------------.\n";
    cout << "| KEY / MOUSE INPUT        | ACTION                           |\n";
    cout << ".-------------------------------------------------------------.\n";
    cout << "| 'D' or 'd'               | Transition to day                |\n";
    cout << "| 'N' or 'n'               | Transition to night              |\n";
    cout << "| 'F' or 'f'               | Move car forward                 |\n";
    cout << "| 'B' or 'b'               | Move car backward                |\n";
    cout << "| MOUSE                    | Toggle lamp light                |\n";
    cout << "`-------------------------------------------------------------`\n";


    cout << endl << endl;
    cout << ".-------------------------------------------------------------.\n";
    cout << "| Fourth Scene:   SAIMA AKTER                                 |\n";
    cout << ".-------------------------------------------------------------.\n";
    cout << "| KEY / MOUSE INPUT        | ACTION                           |\n";
    cout << ".-------------------------------------------------------------.\n";
    cout << "| 'D' or 'd'               | Transition to day                |\n";
    cout << "| 'N' or 'n'               | Transition to night              |\n";
    cout << "| MOUSE                    | Toggle car headlight             |\n";
    cout << "`-------------------------------------------------------------`\n";
    cout << endl;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1400, 750);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Sea port");

    //playSound("ambience.wav");

    myInit();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseCallback);

    glutTimerFunc(10, update, 0);
    glutTimerFunc(10, updateStars, 0);
    glutTimerFunc(10, update_d, 0);
    glutTimerFunc(25, timer, 0);
    glutTimerFunc(25, ropetimer, 0);
    glutTimerFunc(16, timer_ss, 0);

    glutMainLoop();

    return 0;
}
