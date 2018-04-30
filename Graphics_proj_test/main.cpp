#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <Windows.h>
#include <MMSystem.h>

GLint day=1;
GLint night=0;
GLint evening=0;
GLint rain=0;

GLfloat angle = 0.0f;
GLfloat angled = 3.0f;//windmill

GLfloat position = 0.0f;//car
GLfloat positionc1 = 0.0f;//c1
GLfloat position2 = 0.0f;//bird
GLfloat position3 = 0.0f;//cloud
GLfloat position4 = 0.0f;//sun
GLfloat position5 = 0.0f;//truck
GLfloat position6 = 0.0f;//ship
GLfloat position7 = 0.0f;//rain
GLfloat position8 = 0.0f;//heli

GLfloat speed = 0.03f;//car
GLfloat speedc1 = 0.03f;//c1
GLfloat speed2 = 0.01f;//bird
GLfloat speed3 = 0.002f;//cloud
GLfloat speed4 = 0.05f;//sun
GLfloat speed5 = 0.05f;//truck
GLfloat speed6 = 0.03f;//ship
GLfloat speed7 = 0.03f;//rain
GLfloat speed8 = 0.03f;//heli


void DrawCircle(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < num_segments; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle

		float x = r * cosf(theta);//calculate the x component
		float y = r * sinf(theta);//calculate the y component
		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
}

void Timer(int value)//for windmill
{
    glutPostRedisplay();      // Post re-paint request to activate display()
            int i=50;
   glutTimerFunc(i, Timer, 0); // next Timer call milliseconds later
}

void update(int value)//for car
{
    if(position > 1.8)
    {
         position = -1.2f;
    }
    else if(position < -1.8)
    {
         position = 1.8f;

    }
    position += speed;

	glutPostRedisplay();

	glutTimerFunc(100, update, 0);
}
void updatec1(int value)//for car1
{
    if(positionc1 > 1.8)
    {
         positionc1 = -1.8f;
    }
    positionc1 += speedc1;

	glutPostRedisplay();

	glutTimerFunc(100, updatec1, 0);
}

void update2(int value)//for bird
{
    if(position2 > 1.0)
    {
         position2 = -1.2f;
    }
    position2 += speed2;

	glutPostRedisplay();

	glutTimerFunc(100, update2, 0);
}

void update3(int value)//for cloud
{
    if(position3 > 1.8)
    {
         position3 = -1.0f;
    }
    position3 += speed3;

	glutPostRedisplay();

	glutTimerFunc(100, update3, 0);
}

/*void update4(int value)//for sun
{
    if(position4 > 0.6)
    {
         speed4= -0.05f;
    }
    else if(position4 < -0.5)
    {
         speed4= 0.05f;
    }
    position4 += speed4;

	glutPostRedisplay();

	glutTimerFunc(100, update4, 0);
}*/

void update5(int value)//for cloud
{
    if(position5 < -1.8)
    {
         position5 = 1.8f;
    }
    position5 -= speed5;

	glutPostRedisplay();

	glutTimerFunc(100, update5, 0);
}

void update6(int value)//for ship
{
    if(position6 < -1.8)
    {
         position6 = 1.8f;
    }
    position6 -= speed6;

	glutPostRedisplay();

	glutTimerFunc(500, update6, 0);
}

void update7(int value)//for rain
{
    if(position7 < -1.8)
    {
         position7 = 1.0f;
    }
    position7 -= speed7;

	glutPostRedisplay();

	glutTimerFunc(100, update7, 0);
}
void update8(int value)//for rain
{
    if(position8 > 1.8)
    {
         position8 = -1.2f;
    }
    position8 += speed8;

	glutPostRedisplay();

	glutTimerFunc(200, update8, 0);
}

void init()
{
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

}

void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
        case 'n':
            day = 0;
            night = 1;
            evening = 0;
            break;
        case 'd':
            day = 1;
            night = 0;
            evening = 0;
            break;
        case 'e':
            day = 0;
            night = 0;
            evening = 1;
            break;
        case 'r':
            if(rain==0)
            {
                rain=1;
            }
            else if(rain==1)
            {
                rain=0;
            }
            break;

        glutPostRedisplay();
	}
}

void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_DOWN:
            speed = 0.0f;
            break;
        case GLUT_KEY_RIGHT:
            speed += 0.1f;
            speed8 += 0.1f;
            break;
        case GLUT_KEY_LEFT:
            speed -= 0.1f;
            //speed6 -= 0.1f;
            break;
    }

glutPostRedisplay();
}

void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

glPushMatrix();//sky
    glBegin(GL_QUADS);

    if(day==1 && night==0 && evening==0)//p1
    {
         glColor3f(0.529, 0.808, 0.980);
    }
    else if(day==0 && night==1 && evening==0)
    {
         glColor3f(0.4, 0.4, 0.6);
    }
    else if(day==0 && night==0 && evening==1)
    {
         glColor3f(	1.000, 0.549, 0.000);
    }
    glVertex2f(-1.0f, 0.5f);

    if(day==1 && night==0 && evening==0)//p2
    {
         glColor3f(0.529, 0.808, 0.980);
    }
    else if(day==0 && night==1 && evening==0)
    {
         glColor3f(0.4, 0.4, 0.6);
    }
    else if(day==0 && night==0 && evening==1)
    {
         glColor3f(	1.000, 0.549, 0.000);
    }
    glVertex2f( 1.0f, 0.5f);

    if(day==1 && night==0 && evening==0)//p3
    {
         glColor3f(0.118, 0.565, 1.00);
    }
    else if(day==0 && night==1 && evening==0)
    {
         glColor3f(0.098, 0.098, 0.439);
    }
    else if(day==0 && night==0 && evening==1)
    {
         glColor3f(1.000, 0.271, 0.000);
    }
    glVertex2f( 1.0f, 1.0f);

    if(day==1 && night==0 && evening==0)//p4
    {
         glColor3f(0.118, 0.565, 1.00);
    }
    else if(day==0 && night==1 && evening==0)
    {
         glColor3f(0.098, 0.098, 0.439);
    }
    else if(day==0 && night==0 && evening==1)
    {
         glColor3f(1.000, 0.271, 0.000);
    }
    glVertex2f(-1.0f, 1.0f);

    glEnd();
glPopMatrix();



glPushMatrix();//sun
glTranslatef(0.0f,position4, 0.0f);
    glBegin(GL_QUADS); //
    if(night==0)
    {
        glColor4f(1.0, 1.0, 0.0, 1.0);
        DrawCircle(0.75, 0.83, .07, 1300);
    }
    else if(night==1)
    {
        glColor4f(.9, .9, .9, 1.0);
        DrawCircle(-0.71, 0.87, .07, 1300);
        glColor4f(.8, .8, .8, 1.0);
        DrawCircle(-0.75, 0.83, .01, 1300);
        glColor4f(.8, .8, .8, 1.0);
        DrawCircle(-0.76, 0.85, .01, 1300);
    }
    glEnd();
glPopMatrix();



glPushMatrix();//sea
    glBegin(GL_QUADS);

    if(day==1 && night==0 && evening==0)//p1
    {
        glColor3f(0.000, 0.000, 0.545);
    }
    else if(day==0 && night==1 && evening==0)
    {
        glColor3f(0.098, 0.098, 0.439);
    }
    else if(day==0 && night==0 && evening==1)
    {
        glColor3f(1.000, 0.647, 0.000);
    }
    glVertex2f(-1.0f, -0.5f);

    if(day==1 && night==0 && evening==0)//p2
    {
        glColor3f(0.000, 0.000, 0.545);
    }
    else if(day==0 && night==1 && evening==0)
    {
        glColor3f(0.098, 0.098, 0.439);
    }
    else if(day==0 && night==0 && evening==1)
    {
        glColor3f(1.000, 0.647, 0.000);
    }
    glVertex2f( 1.0f, -0.5f);

    if(day==1 && night==0 && evening==0)//p3
    {
        glColor3f(0.000, 0.000, 0.804);
    }
    else if(day==0 && night==1 && evening==0)
    {
        glColor3f(0.4, 0.4, 0.6);
    }
    else if(day==0 && night==0 && evening==1)
    {
        glColor3f(1.000, 0.549, 0.000);
    }
    glVertex2f( 1.0f, 0.5f);

    if(day==1 && night==0 && evening==0)//p4
    {
        glColor3f(0.000, 0.000, 0.804);
    }
    else if(day==0 && night==1 && evening==0)
    {
        glColor3f(0.4, 0.4, 0.6);
    }
    else if(day==0 && night==0 && evening==1)
    {
        glColor3f(1.000, 0.549, 0.000);
    }
    glVertex2f(-1.0f, 0.5f);

   glEnd();
glPopMatrix();

glPushMatrix();//sea in rain
    if(rain==0)
    {

    }
    else if(rain==1)
    {
        glBegin(GL_QUADS);
            glColor3f(0.502, 0.502, 0.502);
            glVertex2f(-1.0f, -0.5f);
            glColor3f(0.502, 0.502, 0.502);
            glVertex2f( 1.0f, -0.5f);
            glColor3f(0.663, 0.663, 0.663);
            glVertex2f( 1.0f, 0.5f);
            glColor3f(0.663, 0.663, 0.663);
            glVertex2f(-1.0f, 0.5f);
        glEnd();
    }
glPopMatrix();

glPushMatrix();//Train
glTranslatef(position,0.0f, 0.0f);
glBegin(GL_POLYGON);
       glColor3f(0.804, 0.361, 0.361);
       glVertex2f(0.0, 0.3f);
       glVertex2f(-0.4, 0.3f);
       glVertex2f(-0.4, 0.4f);
       glVertex2f(-0.2, 0.4f);
glEnd();
glBegin(GL_QUADS);
       glColor3f(0.804, 0.361, 0.361);
       glVertex2f(-0.41, 0.3f);
       glVertex2f(-0.9, 0.3f);
       glVertex2f(-0.9, 0.4f);
       glVertex2f(-0.41, 0.4f);
glEnd();

glLineWidth(10.0);
glBegin(GL_LINES);
       glColor3f(0.000, 0.000, 0.545);
       glVertex2f(-0.425, 0.36f);
       glVertex2f(-0.48, 0.36f);
glEnd();

glBegin(GL_LINES);
       glColor3f(0.000, 0.000, 0.545);
       glVertex2f(-0.485, 0.36f);
       glVertex2f(-0.54, 0.36f);
glEnd();

glBegin(GL_LINES);
       glColor3f(0.000, 0.000, 0.545);
       glVertex2f(-0.545, 0.36f);
       glVertex2f(-0.60, 0.36f);
glEnd();

glBegin(GL_LINES);
       glColor3f(0.000, 0.000, 0.545);
       glVertex2f(-0.605, 0.36f);
       glVertex2f(-0.66, 0.36f);
glEnd();

glBegin(GL_LINES);
       glColor3f(0.000, 0.000, 0.545);
       glVertex2f(-0.665, 0.36f);
       glVertex2f(-0.72, 0.36f);
glEnd();

glBegin(GL_LINES);
       glColor3f(0.000, 0.000, 0.545);
       glVertex2f(-0.725, 0.36f);
       glVertex2f(-0.78, 0.36f);
glEnd();

glBegin(GL_LINES);
       glColor3f(0.000, 0.000, 0.545);
       glVertex2f(-0.785, 0.36f);
       glVertex2f(-0.84, 0.36f);
glEnd();

glBegin(GL_LINES);
       glColor3f(0.000, 0.000, 0.545);
       glVertex2f(-0.845, 0.36f);
       glVertex2f(-0.895, 0.36f);
glEnd();

glLineWidth(3.0);//stripe2car
glBegin(GL_LINES);
       glColor3f(0.416, 0.353, 0.804);
       glVertex2f(-0.415, 0.33f);
       glVertex2f(-0.895, 0.33f);
glEnd();

glLineWidth(3.0);//stripe1car
glBegin(GL_LINES);
       glColor3f(0.416, 0.353, 0.804);
       glVertex2f(-0.063, 0.33f);
       glVertex2f(-0.395, 0.33f);
glEnd();

glBegin(GL_TRIANGLES);
       glColor3f(0.000, 0.000, 0.545);
       glVertex2f(-0.12, 0.345f);
       glVertex2f(-0.20, 0.345f);
       glVertex2f(-0.20, 0.375f);
glEnd();

glLineWidth(10.0);
glBegin(GL_LINES);
       glColor3f(0.000, 0.000, 0.545);
       glVertex2f(-0.205, 0.36f);
       glVertex2f(-0.26, 0.36f);
glEnd();

glBegin(GL_LINES);
       glColor3f(0.000, 0.000, 0.545);
       glVertex2f(-0.265, 0.36f);
       glVertex2f(-0.32, 0.36f);
glEnd();

glBegin(GL_LINES);
       glColor3f(0.000, 0.000, 0.545);
       glVertex2f(-0.325, 0.36f);
       glVertex2f(-0.389, 0.36f);
glEnd();

glPopMatrix();

glPushMatrix();//shetu :p
    glBegin(GL_QUADS);
      glColor3f(0.741, 0.718, 0.420);
      float o= -1;
      float p= -.95;
      int l=0;
      for(l=0;l<10;l++)
      {
            glVertex2f(o, 0.2f);
            glVertex2f(p, 0.2f);
            glVertex2f(p, 0.3f);
            glVertex2f(o, 0.3f);
            o= o+ .2 ;
            p= p+ .2 ;
      }
    glEnd();
    glBegin(GL_QUADS);//MAIN ROAD
      glColor3f(0.741, 0.718, 0.420);
      glVertex2f(-1.0f, 0.3f);
      glVertex2f( 1.0f, 0.3f);
      glVertex2f( 1.0f, 0.32f);
      glVertex2f(-1.0f, 0.32f);
   glEnd();
   glBegin(GL_QUADS);//MAIN ROAD
      glColor3f(0.741, 0.718, 0.420);
      glVertex2f(-1.0f, 0.42f);
      glVertex2f( 1.0f, 0.42f);
      glVertex2f( 1.0f, 0.43f);
      glVertex2f(-1.0f, 0.43f);
   glEnd();
   glBegin(GL_QUADS);
      glColor3f(0.741, 0.718, 0.420);
      float y= -1;
      float u= -.995;
      int t=0;
      for(t=0;t<20;t++)
      {
            glVertex2f(y, 0.32f);
            glVertex2f(u, 0.32f);
            glVertex2f(u, 0.42f);
            glVertex2f(y, 0.42f);
            y= y+ .1 ;
            u= u+ .1 ;
      }
    glEnd();
glPopMatrix();

glPushMatrix();//far land
    glBegin(GL_QUADS);//MAIN ROAD
      glColor3f(0.000, 0.392, 0.00);
      glVertex2f(-1.0f, 0.48f);
      glVertex2f( 1.0f, 0.48f);
      glVertex2f( 1.0f, 0.51f);
      glVertex2f(-1.0f, 0.51f);
   glEnd();
glPopMatrix();

glPushMatrix();//SmallShip
glTranslatef(position,0.0f, 0.0f);
glBegin(GL_QUADS); //ShipUpper
        glColor3f(0.545, 0.000, 0.000);
        glVertex2f(-0.64f, 0.25f);
        glVertex2f(-0.59f, 0.265f);
        glVertex2f(-0.59f, 0.08f);
        glVertex2f(-0.64f, 0.08f);
    glEnd();
    glPointSize(10.0);
    glBegin(GL_POINTS);
            glColor3f(1.000, 1.000, 1.000);
            glVertex2f(-0.60f, 0.23f);
    glEnd();
    glLineWidth(7.0);
    glBegin(GL_LINES); //ShipUpperHat
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(-0.65f, 0.25f);
        glVertex2f(-0.58f, 0.265f);
    glEnd();
    glLineWidth(7.0);
    glBegin(GL_LINES); //ShipUpperHat
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(-0.71f, 0.16f);
        glVertex2f(-0.64f, 0.17f);
    glEnd();
glBegin(GL_POLYGON); //shipBottom
        glColor3f(0.722, 0.525, 0.043);
        glVertex2f(-0.55f, 0.18f);
        glVertex2f(-0.57f, 0.08f);
        glVertex2f(-0.70f, 0.08f);
        glVertex2f(-0.73f, 0.15f);
        glVertex2f(-0.62f, 0.16f);
        glVertex2f(-0.60f, 0.18f);
    glEnd();
glPopMatrix();

glPushMatrix();//car1light
glTranslatef(position,0.0f, 0.0f);
    if(day==1 && night==0 && evening==0)
        {

        }
        else if(day==0 && night==1 && evening==0)
        {
            glBegin(GL_QUADS); //car1Bottom
                glColor3f(1.000, 1.000, 0.000);
                glVertex2f(-0.55f, 0.15f);
                glColor3f(1.000, 1.000, 0.000);
                glVertex2f(-0.35f, 0.18f);
                glColor3f(1.000, 1.000, 0.000);
                glVertex2f(-0.35f, 0.12f);
                glColor3f(1.000, 1.000, 0.000);
                glVertex2f(-0.55f, 0.15f);
            glEnd();
        }
        else if(day==0 && night==0 && evening==1)
        {
            glBegin(GL_QUADS); //car1Bottom
                glColor3f(1.000, 1.000, 0.000);
                glVertex2f(-0.55f, 0.15f);
                glColor3f(1.000, 1.000, 1.000);
                glVertex2f(-0.35f, 0.18f);
                glColor3f(1.000, 1.000, 1.000);
                glVertex2f(-0.35f, 0.12f);
                glColor3f(1.000, 1.000, 0.000);
                glVertex2f(-0.55f, 0.15f);
            glEnd();
        }

glPopMatrix();

glPushMatrix();//Speed boat
glTranslatef(position5,0.0f, 0.0f);
glBegin(GL_QUADS); //speedbUpper
       glColor3f(0.502, 0.502, 0.502);
       glVertex2f(0.60f, 0.13f);
       glVertex2f(0.73f, 0.11f);
       glVertex2f(0.73f, 0.02f);
       glVertex2f(0.58f, 0.07f);
glEnd();
glBegin(GL_POLYGON); //speedbLower
       glColor3f(1.0, 1.0, 1.0);
       glVertex2f(0.55f, 0.1f);
       glVertex2f(0.75f, 0.07f);
       glVertex2f(0.75f, 0.01f);
       glVertex2f(0.62f, 0.01f);
glEnd();
glLineWidth(3.0);
glBegin(GL_LINES); //SpeedBoatStripe
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(0.75f, 0.04f);
        glVertex2f(0.58f, 0.06f);
    glEnd();

glLineWidth(3.0);
    glBegin(GL_LINES); //SpeedBoatRailings
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(0.56f, 0.10f);
        glVertex2f(0.57f, 0.12f);
    glEnd();
    glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(0.57f, 0.12f);
        glVertex2f(0.68f, 0.10f);
    glEnd();
    glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(0.68f, 0.10f);
        glVertex2f(0.68f, 0.08f);
    glEnd();
    glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(0.64f, 0.10f);
        glVertex2f(0.64f, 0.09f);
    glEnd();
    glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(0.60f, 0.11f);
        glVertex2f(0.60f, 0.094f);
    glEnd();
glPopMatrix();

glPushMatrix();//Ship
glTranslatef(position6,0.0f, 0.0f);

   glBegin(GL_QUADS);//1
      glColor3f(1.000, 0.894, 0.882);
      glVertex2f(-0.1f, -0.2f);
      glVertex2f( 0.1f, -0.2f);
      glVertex2f( 0.2f, -0.05f);
      glVertex2f(-0.2f, -0.05f);
   glEnd();

   glBegin(GL_QUADS);//2
      glColor3f(0.467, 0.533, 0.600);
      glVertex2f(-0.15f, -0.05f);
      glVertex2f( 0.15f, -0.05f);
      glVertex2f( 0.15f, 0.02f);
      glVertex2f(-0.15f, 0.02f);
   glEnd();

   glBegin(GL_QUADS);//3
      glColor3f(0.184, 0.310, 0.310);
      glVertex2f(-0.12f, 0.02f);
      glVertex2f( 0.12f, 0.02f);
      glVertex2f( 0.12f, 0.08f);
      glVertex2f(-0.12f, 0.08f);
   glEnd();

   glBegin(GL_QUADS);//c1
      glColor3f(0.545, 0.000, 0.000);
      glVertex2f( 0.08f, 0.08f);
      glVertex2f( 0.11f, 0.08f);
      glVertex2f( 0.11f, 0.14f);
      glVertex2f( 0.08f, 0.14f);
   glEnd();

   glBegin(GL_QUADS);//c2
      glColor3f(0.545, 0.000, 0.000);
      glVertex2f( 0.02f, 0.08f);
      glVertex2f( 0.05f, 0.08f);
      glVertex2f( 0.05f, 0.14f);
      glVertex2f( 0.02f, 0.14f);
   glEnd();

   glBegin(GL_QUADS);//c3
      glColor3f(0.545, 0.000, 0.000);
      glVertex2f( -0.02f, 0.08f);
      glVertex2f( -0.05f, 0.08f);
      glVertex2f( -0.05f, 0.14f);
      glVertex2f( -0.02f, 0.14f);
   glEnd();

   glBegin(GL_QUADS);//c4
      glColor3f(0.545, 0.000, 0.000);
      glVertex2f( -0.08f, 0.08f);
      glVertex2f( -0.11f, 0.08f);
      glVertex2f( -0.11f, 0.14f);
      glVertex2f( -0.08f, 0.14f);
   glEnd();

   glBegin(GL_QUADS);//w1
        if(day==1 && night==0 && evening==0)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
        else if(day==0 && night==1 && evening==0)
        {
            glColor3f(1.000, 0.843, 0.000);
        }
        else if(day==0 && night==0 && evening==1)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
      glVertex2f( 0.08f, -0.04f);
      glVertex2f( 0.11f, -0.04f);
      glVertex2f( 0.11f, 0.0f);
      glVertex2f( 0.08f, 0.0f);
   glEnd();

   glBegin(GL_QUADS);//w2
      if(day==1 && night==0 && evening==0)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
        else if(day==0 && night==1 && evening==0)
        {
            glColor3f(1.000, 0.843, 0.000);
        }
        else if(day==0 && night==0 && evening==1)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
      glVertex2f( 0.02f, -0.04f);
      glVertex2f( 0.05f, -0.04f);
      glVertex2f( 0.05f, 0.0f);
      glVertex2f( 0.02f, 0.0f);
   glEnd();

   glBegin(GL_QUADS);//w3
      if(day==1 && night==0 && evening==0)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
        else if(day==0 && night==1 && evening==0)
        {
            glColor3f(1.000, 0.843, 0.000);
        }
        else if(day==0 && night==0 && evening==1)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
      glVertex2f( -0.02f, -0.04f);
      glVertex2f( -0.05f, -0.04f);
      glVertex2f( -0.05f, 0.0f);
      glVertex2f( -0.02f, 0.0f);
   glEnd();

   glBegin(GL_QUADS);//w4
     if(day==1 && night==0 && evening==0)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
        else if(day==0 && night==1 && evening==0)
        {
            glColor3f(1.000, 0.843, 0.000);
        }
        else if(day==0 && night==0 && evening==1)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
      glVertex2f( -0.08f, -0.04f);
      glVertex2f( -0.11f, -0.04f);
      glVertex2f( -0.11f, 0.0f);
      glVertex2f( -0.08f, 0.0f);
   glEnd();

   glBegin(GL_QUADS);//uw1
      if(day==1 && night==0 && evening==0)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
        else if(day==0 && night==1 && evening==0)
        {
            glColor3f(1.000, 0.843, 0.000);
        }
        else if(day==0 && night==0 && evening==1)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
      glVertex2f( 0.08f, 0.03f);
      glVertex2f( 0.11f, 0.03f);
      glVertex2f( 0.11f, 0.07f);
      glVertex2f( 0.08f, 0.07f);
   glEnd();

   glBegin(GL_QUADS);//uw2
      if(day==1 && night==0 && evening==0)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
        else if(day==0 && night==1 && evening==0)
        {
            glColor3f(1.000, 0.843, 0.000);
        }
        else if(day==0 && night==0 && evening==1)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
      glVertex2f( 0.02f, 0.03f);
      glVertex2f( 0.05f, 0.03f);
      glVertex2f( 0.05f, 0.07f);
      glVertex2f( 0.02f, 0.07f);
   glEnd();

   glBegin(GL_QUADS);//uw3
      if(day==1 && night==0 && evening==0)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
        else if(day==0 && night==1 && evening==0)
        {
            glColor3f(1.000, 0.843, 0.000);
        }
        else if(day==0 && night==0 && evening==1)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
      glVertex2f( -0.02f, 0.03f);
      glVertex2f( -0.05f, 0.03f);
      glVertex2f( -0.05f, 0.07f);
      glVertex2f( -0.02f, 0.07f);
   glEnd();

   glBegin(GL_QUADS);//uw4
      if(day==1 && night==0 && evening==0)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
        else if(day==0 && night==1 && evening==0)
        {
            glColor3f(1.000, 0.843, 0.000);
        }
        else if(day==0 && night==0 && evening==1)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
      glVertex2f( -0.08f, 0.03f);
      glVertex2f( -0.11f, 0.03f);
      glVertex2f( -0.11f, 0.07f);
      glVertex2f( -0.08f, 0.07f);
   glEnd();

glPopMatrix();

glPushMatrix(); //ROAD
//glTranslatef(position,0.0f, 0.0f);
   glBegin(GL_QUADS);//MAIN ROAD
      glColor3f(0.184, 0.310, 0.310);
      glVertex2f(-1.0f, -1.0f);
      glVertex2f( 1.0f, -1.0f);
      glVertex2f( 1.0f, -0.75f);
      glVertex2f(-1.0f, -0.75f);
   glEnd();

   glBegin(GL_QUADS); //FOOTPATH1
      glColor3f(0.827, 0.827, 0.827);
      glVertex2f(-1.0f, -0.75f);
      glVertex2f( 1.0f, -0.75f);
      glVertex2f( 1.0f, -0.73f);
      glVertex2f(-1.0f, -0.73f);
   glEnd();

   glBegin(GL_QUADS); //FOOTPATH2
      glColor3f(0.627, 0.322, 0.176);
      glVertex2f(-1.0f, -0.73f);
      glVertex2f( 1.0f, -0.73f);
      glVertex2f( 1.0f, -0.7f);
      glVertex2f(-1.0f, -0.7f);
   glEnd();

   glBegin(GL_QUADS); //DIVIDER
      glColor3f(1.000, 0.843, 0.000);
      float i= -1;
      float j= -.9;
      int k=0;
      for(k=0;k<10;k++)
      {
            glVertex2f(i, -0.87f);
            glVertex2f(j, -0.87f);
            glVertex2f(j, -0.874f);
            glVertex2f(i, -0.874f);
            i= i+ .2 ;
            j= j+ .2 ;
      }
    glEnd();

glPopMatrix();

glPushMatrix();
    glBegin(GL_QUADS); //grasspark
        glColor3f(0.133, 0.545, 0.133);
        glVertex2f(-1.0f, -0.7f);
        glVertex2f( 1.0f, -0.7f);
        glVertex2f( 1.0f, -0.5f);
        glVertex2f(-1.0f, -0.5f);
    glEnd();
glPopMatrix();

glPushMatrix();
//glTranslatef(position,0.0f, 0.0f);
    glBegin(GL_QUADS); //BUIlDING 1F
        glColor3f(0.914, 0.588, 0.478);
        glVertex2f(-0.12f, -0.7f);
        glVertex2f( 0.12f, -0.7f);
        glVertex2f( 0.12f, -0.1f);
        glVertex2f(-0.12f, -0.1f);
    glEnd();

    glPointSize(15.0);
    glBegin(GL_POINTS);//windows


        if(day==1 && night==0 && evening==0)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
        else if(day==0 && night==1 && evening==0)
        {
            glColor3f(1.000, 0.843, 0.000);
        }
        else if(day==0 && night==0 && evening==1)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
        glVertex2f(-0.10f, -0.6f); //1st column 1f
        glVertex2f(-0.10f, -0.5f);
        glVertex2f(-0.10f, -0.4f);
        glVertex2f(-0.10f, -0.3f);
        glVertex2f(-0.10f, -0.2f);

        glVertex2f(-0.06f, -0.6f); //2nd column 1f
        glVertex2f(-0.06f, -0.5f);
        glVertex2f(-0.06f, -0.4f);
        glVertex2f(-0.06f, -0.3f);
        glVertex2f(-0.06f, -0.2f);

        glVertex2f(-0.02f, -0.6f); //3rd column 1f
        glVertex2f(-0.02f, -0.5f);
        glVertex2f(-0.02f, -0.4f);
        glVertex2f(-0.02f, -0.3f);
        glVertex2f(-0.02f, -0.2f);

        glVertex2f(0.02f, -0.6f); //4th column 1f
        glVertex2f(0.02f, -0.5f);
        glVertex2f(0.02f, -0.4f);
        glVertex2f(0.02f, -0.3f);
        glVertex2f(0.02f, -0.2f);

        glVertex2f(0.06f, -0.6f); //5th column 1f
        glVertex2f(0.06f, -0.5f);
        glVertex2f(0.06f, -0.4f);
        glVertex2f(0.06f, -0.3f);
        glVertex2f(0.06f, -0.2f);

        glVertex2f(0.10f, -0.6f); //6th column 1f
        glVertex2f(0.10f, -0.5f);
        glVertex2f(0.10f, -0.4f);
        glVertex2f(0.10f, -0.3f);
        glVertex2f(0.10f, -0.2f);

    glEnd();

    glBegin(GL_QUADS); //BUIlDING 2F
        glColor3f(0.698, 0.133, 0.133);
        glVertex2f(-0.36f, -0.7f);
        glVertex2f(-0.13f, -0.7f);
        glVertex2f(-0.13f, -0.13f);
        glVertex2f(-0.36f, -0.13f);
    glEnd();

    glPointSize(17.0);
    glBegin(GL_POINTS);//windows

        if(day==1 && night==0 && evening==0)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
        else if(day==0 && night==1 && evening==0)
        {
            glColor3f(1.000, 0.843, 0.000);
        }
        else if(day==0 && night==0 && evening==1)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
       glVertex2f(-0.32f, -0.6f); //1st col 2f
       glVertex2f(-0.32f, -0.5f);
       glVertex2f(-0.32f, -0.4f);
       glVertex2f(-0.32f, -0.3f);
       glVertex2f(-0.32f, -0.2f);

       glVertex2f(-0.28f, -0.6f); //2nd col 2f
       glVertex2f(-0.28f, -0.5f);
       glVertex2f(-0.28f, -0.4f);
       glVertex2f(-0.28f, -0.3f);
       glVertex2f(-0.28f, -0.2f);

       glVertex2f(-0.24f, -0.6f); //3rd col 2f
       glVertex2f(-0.24f, -0.5f);
       glVertex2f(-0.24f, -0.4f);
       glVertex2f(-0.24f, -0.3f);
       glVertex2f(-0.24f, -0.2f);

       glVertex2f(-0.20f, -0.6f); //4th col 2f
       glVertex2f(-0.20f, -0.5f);
       glVertex2f(-0.20f, -0.4f);
       glVertex2f(-0.20f, -0.3f);
       glVertex2f(-0.20f, -0.2f);

       glVertex2f(-0.16f, -0.6f); //5th col 2f
       glVertex2f(-0.16f, -0.5f);
       glVertex2f(-0.16f, -0.4f);
       glVertex2f(-0.16f, -0.3f);
       glVertex2f(-0.16f, -0.2f);
    glEnd();

    glBegin(GL_QUADS); //BUIlDING 3F
        glColor3f(0.333, 0.420, 0.184);
        glVertex2f(-0.76f, -0.7f);
        glVertex2f(-0.40f, -0.7f);
        glVertex2f(-0.40f, -0.23f);
        glVertex2f(-0.76f, -0.23f);
    glEnd();

    glPointSize(20.0);
    glBegin(GL_POINTS);//windows

        if(day==1 && night==0 && evening==0)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
        else if(day==0 && night==1 && evening==0)
        {
            glColor3f(1.000, 0.843, 0.000);
        }
        else if(day==0 && night==0 && evening==1)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
        glVertex2f(-0.73f, -0.6f);// 3f 1st row
        glVertex2f(-0.68f, -0.6f);
        glVertex2f(-0.63f, -0.6f);
        glVertex2f(-0.58f, -0.6f);
        glVertex2f(-0.53f, -0.6f);
        glVertex2f(-0.48f, -0.6f);
        glVertex2f(-0.43f, -0.6f);

        glVertex2f(-0.73f, -0.5f);// 3f 2nd row
        glVertex2f(-0.68f, -0.5f);
        glVertex2f(-0.63f, -0.5f);
        glVertex2f(-0.58f, -0.5f);
        glVertex2f(-0.53f, -0.5f);
        glVertex2f(-0.48f, -0.5f);
        glVertex2f(-0.43f, -0.5f);

        glVertex2f(-0.73f, -0.4f); // 3f 4th row
        glVertex2f(-0.68f, -0.4f);
        glVertex2f(-0.63f, -0.4f);
        glVertex2f(-0.58f, -0.4f);
        glVertex2f(-0.53f, -0.4f);
        glVertex2f(-0.48f, -0.4f);
        glVertex2f(-0.43f, -0.4f);

        glVertex2f(-0.73f, -0.3f); // 3f 5th row
        glVertex2f(-0.68f, -0.3f);
        glVertex2f(-0.63f, -0.3f);
        glVertex2f(-0.58f, -0.3f);
        glVertex2f(-0.53f, -0.3f);
        glVertex2f(-0.48f, -0.3f);
        glVertex2f(-0.43f, -0.3f);
    glEnd();

    glBegin(GL_QUADS); //BUIlDING 4F
        glColor3f(0.741, 0.718, 0.420);
        glVertex2f(-1.0f, -0.7f);
        glVertex2f(-0.79f, -0.7f);
        glVertex2f(-0.79f, -0.1f);
        glVertex2f(-1.0f, -0.1f);
    glEnd();

    glPointSize(17.0);
    glBegin(GL_POINTS);//windows

        if(day==1 && night==0 && evening==0)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
        else if(day==0 && night==1 && evening==0)
        {
            glColor3f(1.000, 0.843, 0.000);
        }
        else if(day==0 && night==0 && evening==1)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
        glVertex2f(-0.98f, -0.65f);// 4f 1st row
        glVertex2f(-0.94f, -0.65f);
        glVertex2f(-0.90f, -0.65f);
        glVertex2f(-0.86f, -0.65f);
        glVertex2f(-0.82f, -0.65f);

        glVertex2f(-0.98f, -0.55f);// 4f 2nd row
        glVertex2f(-0.94f, -0.55f);
        glVertex2f(-0.90f, -0.55f);
        glVertex2f(-0.86f, -0.55f);
        glVertex2f(-0.82f, -0.55f);

        glVertex2f(-0.98f, -0.45f);// 4f 3rd row
        glVertex2f(-0.94f, -0.45f);
        glVertex2f(-0.90f, -0.45f);
        glVertex2f(-0.86f, -0.45f);
        glVertex2f(-0.82f, -0.45f);

        glVertex2f(-0.98f, -0.35f);// 4f 4th row
        glVertex2f(-0.94f, -0.35f);
        glVertex2f(-0.90f, -0.35f);
        glVertex2f(-0.86f, -0.35f);
        glVertex2f(-0.82f, -0.35f);

        glVertex2f(-0.98f, -0.25f);// 4f 5th row
        glVertex2f(-0.94f, -0.25f);
        glVertex2f(-0.90f, -0.25f);
        glVertex2f(-0.86f, -0.25f);
        glVertex2f(-0.82f, -0.25f);

        glVertex2f(-0.98f, -0.15f);// 4f 6th row
        glVertex2f(-0.94f, -0.15f);
        glVertex2f(-0.90f, -0.15f);
        glVertex2f(-0.86f, -0.15f);
        glVertex2f(-0.82f, -0.15f);
    glEnd();


    glBegin(GL_QUADS); //BUIlDING 5F
        glColor3f(0.545, 0.271, 0.075);
        glVertex2f(0.13f, -0.7f);
        glVertex2f(0.37f, -0.7f);
        glVertex2f(0.37f, -0.12f);
        glVertex2f(0.13f, -0.12f);
    glEnd();

    glPointSize(23.0);
    glBegin(GL_POINTS);//windows

       if(day==1 && night==0 && evening==0)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
        else if(day==0 && night==1 && evening==0)
        {
            glColor3f(1.000, 0.843, 0.000);
        }
        else if(day==0 && night==0 && evening==1)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
       glVertex2f(0.16f, -0.6f); // 5f r 1
       glVertex2f(0.22f, -0.6f);
       glVertex2f(0.28f, -0.6f);
       glVertex2f(0.34f, -0.6f);

       glVertex2f(0.16f, -0.5f); // 5f r 2
       glVertex2f(0.22f, -0.5f);
       glVertex2f(0.28f, -0.5f);
       glVertex2f(0.34f, -0.5f);

       glVertex2f(0.16f, -0.4f); // 5f r 3
       glVertex2f(0.22f, -0.4f);
       glVertex2f(0.28f, -0.4f);
       glVertex2f(0.34f, -0.4f);

       glVertex2f(0.16f, -0.3f); // 5f r 4
       glVertex2f(0.22f, -0.3f);
       glVertex2f(0.28f, -0.3f);
       glVertex2f(0.34f, -0.3f);

       glVertex2f(0.16f, -0.2f); // 5f r 4
       glVertex2f(0.22f, -0.2f);
       glVertex2f(0.28f, -0.2f);
       glVertex2f(0.34f, -0.2f);
    glEnd();

    glBegin(GL_QUADS); //BUIlDING 6F
        glColor3f(0.184, 0.310, 0.310);
        glVertex2f(0.38f, -0.7f);
        glVertex2f(0.65f, -0.7f);
        glVertex2f(0.65f, 0.0f);
        glVertex2f(0.38f, 0.0f);
    glEnd();

    glPointSize(18.0);
    glBegin(GL_POINTS);//windows

        if(day==1 && night==0 && evening==0)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
        else if(day==0 && night==1 && evening==0)
        {
            glColor3f(1.000, 0.843, 0.000);
        }
        else if(day==0 && night==0 && evening==1)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
        glVertex2f(0.41f, -0.6f);//6f r1
        glVertex2f(0.46f, -0.6f);
        glVertex2f(0.51f, -0.6f);
        glVertex2f(0.56f, -0.6f);
        glVertex2f(0.61f, -0.6f);

        glVertex2f(0.41f, -0.5f);//6f r2
        glVertex2f(0.46f, -0.5f);
        glVertex2f(0.51f, -0.5f);
        glVertex2f(0.56f, -0.5f);
        glVertex2f(0.61f, -0.5f);

        glVertex2f(0.41f, -0.4f);//6f r3
        glVertex2f(0.46f, -0.4f);
        glVertex2f(0.51f, -0.4f);
        glVertex2f(0.56f, -0.4f);
        glVertex2f(0.61f, -0.4f);

        glVertex2f(0.41f, -0.3f);//6f r4
        glVertex2f(0.46f, -0.3f);
        glVertex2f(0.51f, -0.3f);
        glVertex2f(0.56f, -0.3f);
        glVertex2f(0.61f, -0.3f);

        glVertex2f(0.41f, -0.2f);//6f r5
        glVertex2f(0.46f, -0.2f);
        glVertex2f(0.51f, -0.2f);
        glVertex2f(0.56f, -0.2f);
        glVertex2f(0.61f, -0.2f);

        glVertex2f(0.41f, -0.1f);//6f r6
        glVertex2f(0.46f, -0.1f);
        glVertex2f(0.51f, -0.1f);
        glVertex2f(0.56f, -0.1f);
        glVertex2f(0.61f, -0.1f);
    glEnd();

    glBegin(GL_QUADS); //BUIlDING 7F
        glColor3f(0.824, 0.706, 0.549);
        glVertex2f(0.66f, -0.7f);
        glVertex2f(1.0f, -0.7f);
        glVertex2f(1.0f, -0.1f);
        glVertex2f(0.66f, -0.1f);
    glEnd();

    glPointSize(18.0);
    glBegin(GL_POINTS);

        if(day==1 && night==0 && evening==0)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
        else if(day==0 && night==1 && evening==0)
        {
            glColor3f(1.000, 0.843, 0.000);
        }
        else if(day==0 && night==0 && evening==1)
        {
            glColor3f(0.529, 0.808, 0.922);
        }
        glVertex2f(0.69f, -0.65f);//7f r1
        glVertex2f(0.74f, -0.65f);
        glVertex2f(0.79f, -0.65f);
        glVertex2f(0.84f, -0.65f);
        glVertex2f(0.89f, -0.65f);
        glVertex2f(0.94f, -0.65f);
        glVertex2f(0.99f, -0.65f);

        glVertex2f(0.69f, -0.55f);//7f r2
        glVertex2f(0.74f, -0.55f);
        glVertex2f(0.79f, -0.55f);
        glVertex2f(0.84f, -0.55f);
        glVertex2f(0.89f, -0.55f);
        glVertex2f(0.94f, -0.55f);
        glVertex2f(0.99f, -0.55f);

        glVertex2f(0.69f, -0.45f);//7f r3
        glVertex2f(0.74f, -0.45f);
        glVertex2f(0.79f, -0.45f);
        glVertex2f(0.84f, -0.45f);
        glVertex2f(0.89f, -0.45f);
        glVertex2f(0.94f, -0.45f);
        glVertex2f(0.99f, -0.45f);

        glVertex2f(0.69f, -0.35f);//7f r4
        glVertex2f(0.74f, -0.35f);
        glVertex2f(0.79f, -0.35f);
        glVertex2f(0.84f, -0.35f);
        glVertex2f(0.89f, -0.35f);
        glVertex2f(0.94f, -0.35f);
        glVertex2f(0.99f, -0.35f);

        glVertex2f(0.69f, -0.25f);//7f r5
        glVertex2f(0.74f, -0.25f);
        glVertex2f(0.79f, -0.25f);
        glVertex2f(0.84f, -0.25f);
        glVertex2f(0.89f, -0.25f);
        glVertex2f(0.94f, -0.25f);
        glVertex2f(0.99f, -0.25f);

        glVertex2f(0.69f, -0.15f);//7f r6
        glVertex2f(0.74f, -0.15f);
        glVertex2f(0.79f, -0.15f);
        glVertex2f(0.84f, -0.15f);
        glVertex2f(0.89f, -0.15f);
        glVertex2f(0.94f, -0.15f);
        glVertex2f(0.99f, -0.15f);
    glEnd();

glPopMatrix();

glPushMatrix();//car
glTranslatef(position,0.0f, 0.0f);
    glBegin(GL_QUADS); //car1Bottom
        glColor3f(0.2, 0.2, 0.2);
        glVertex2f(-0.9f, -0.83f);
        glVertex2f(-0.7f, -0.83f);
        glVertex2f(-0.7f, -0.77f);
        glVertex2f(-0.9f, -0.77f);
    glEnd();
    glBegin(GL_QUADS); //car1top
        glColor3f(0.5, 0.1, 0.5);
        glVertex2f(-0.86f, -0.77f);
        glVertex2f(-0.75f, -0.77f);
        glVertex2f(-0.77f, -0.73f);
        glVertex2f(-0.83f, -0.73f);
    glEnd();
    glBegin(GL_QUADS); //car1glass
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(-0.84f, -0.77f);
        glVertex2f(-0.77f, -0.77f);
        glVertex2f(-0.78f, -0.75f);
        glVertex2f(-0.83f, -0.75f);
    glEnd();
    glBegin(GL_QUADS); //car1wheelB
        glColor3f(0.412, 0.412, 0.412);
        DrawCircle(-0.85, -0.83, .025, 1300);
    glEnd();
    glBegin(GL_QUADS); //car1wheelF
        glColor3f(0.412, 0.412, 0.412);
        DrawCircle(-0.75, -0.83, .025, 1300);
    glEnd();
    glBegin(GL_QUADS); //car1wheelrimB
        glColor3f(0.863, 0.863, 0.863);
        DrawCircle(-0.85, -0.83, .015, 1300);
    glEnd();
    glBegin(GL_QUADS); //car1wheelrimF
        glColor3f(0.863, 0.863, 0.863);
        DrawCircle(-0.75, -0.83, .015, 1300);
    glEnd();

glPopMatrix();

glPushMatrix();//car2
glTranslatef(positionc1,0.0f, 0.0f);
    glBegin(GL_QUADS); //car1Bottom
        glColor3f(0.8, 0.56, 0.3);
        glVertex2f(0.9f, -0.83f);
        glVertex2f(0.7f, -0.83f);
        glVertex2f(0.7f, -0.77f);
        glVertex2f(0.9f, -0.77f);
    glEnd();
    glBegin(GL_QUADS); //car1top
        glColor3f(0.2, 0.60, 0.6);
        glVertex2f(0.86f, -0.77f);
        glVertex2f(0.75f, -0.77f);
        glVertex2f(0.77f, -0.73f);
        glVertex2f(0.83f, -0.73f);
    glEnd();
    glBegin(GL_QUADS); //car1glass
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.84f, -0.77f);
        glVertex2f(0.77f, -0.77f);
        glVertex2f(0.78f, -0.75f);
        glVertex2f(0.83f, -0.75f);
    glEnd();
    glBegin(GL_QUADS); //car1wheelB
        glColor3f(0.0, 0.0, 0.0);
        DrawCircle(0.85, -0.83, .025, 1300);
    glEnd();
    glBegin(GL_QUADS); //car1wheelF
        glColor3f(0.0, 0.0, 0.0);
        DrawCircle(0.75, -0.83, .025, 1300);
    glEnd();
    glBegin(GL_QUADS); //car1wheelrimB
        glColor3f(0.863, 0.863, 0.863);
        DrawCircle(0.85, -0.83, .015, 1300);
    glEnd();
    glBegin(GL_QUADS); //car1wheelrimF
        glColor3f(0.863, 0.863, 0.863);
        DrawCircle(0.75, -0.83, .015, 1300);
    glEnd();

glPopMatrix();

glPushMatrix();//car1light
glTranslatef(position,0.0f, 0.0f);
    if(day==1 && night==0 && evening==0)
        {

        }
        else if(day==0 && night==1 && evening==0)
        {
            glBegin(GL_QUADS);
                glColor3f(1.000, 1.000, 0.000);
                glVertex2f(-0.7f, -0.8f);
                glColor3f(1.000, 1.000, 0.000);
                glVertex2f(-0.5f, -0.83f);
                glColor3f(1.000, 1.000, 0.000);
                glVertex2f(-0.5f, -0.77f);
                glColor3f(1.000, 1.000, 0.000);
                glVertex2f(-0.7f, -0.8f);
            glEnd();
        }
        else if(day==0 && night==0 && evening==1)
        {
            glBegin(GL_QUADS);
                glColor3f(1.000, 1.000, 0.000);
                glVertex2f(-0.7f, -0.8f);
                glColor3f(1.000, 1.000, 1.000);
                glVertex2f(-0.5f, -0.83f);
                glColor3f(1.000, 1.000, 1.000);
                glVertex2f(-0.5f, -0.77f);
                glColor3f(1.000, 1.000, 0.000);
                glVertex2f(-0.7f, -0.8f);
            glEnd();
        }
glPopMatrix();
glPushMatrix();//car2light
glTranslatef(positionc1,0.0f, 0.0f);
    if(day==1 && night==0 && evening==0)
        {

        }
        else if(day==0 && night==1 && evening==0)
        {
            glBegin(GL_QUADS);
                glColor3f(1.000, 1.000, 0.000);
                glVertex2f(0.9f, -0.8f);
                glColor3f(1.000, 1.000, 0.000);
                glVertex2f(1.1f, -0.83f);
                glColor3f(1.000, 1.000, 0.000);
                glVertex2f(1.1f, -0.77f);
                glColor3f(1.000, 1.000, 0.000);
                glVertex2f(0.9f, -0.8f);
            glEnd();
        }
        else if(day==0 && night==0 && evening==1)
        {
            glBegin(GL_QUADS);
                glColor3f(1.000, 1.000, 0.000);
                glVertex2f(0.9f, -0.8f);
                glColor3f(1.000, 1.000, 1.000);
                glVertex2f(1.1f, -0.83f);
                glColor3f(1.000, 1.000, 1.000);
                glVertex2f(1.1f, -0.77f);
                glColor3f(1.000, 1.000, 0.000);
                glVertex2f(0.9f, -0.8f);
            glEnd();
        }
glPopMatrix();

glPushMatrix();//truck
glTranslatef(position5,0.0f, 0.0f);
    glBegin(GL_QUADS); //Truckfront
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(0.48f, -0.85f);
        glVertex2f(0.55f, -0.85f);
        glVertex2f(0.55f, -0.91f);
        glVertex2f(0.48f, -0.91f);
    glEnd();

    glBegin(GL_POLYGON); //TruckFRONT
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(0.55f, -0.85f);
        glVertex2f(0.55f, -0.77f);
        glVertex2f(0.62f, -0.77f);
        glVertex2f(0.62f, -0.91f);
        glVertex2f(0.5f, -0.91f);
        glVertex2f(0.5f, -0.85f);
    glEnd();
    glBegin(GL_QUADS); //TruckBack
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(0.62f, -0.91f);
        glVertex2f(0.75f, -0.91f);
        glVertex2f(0.75f, -0.85f);
        glVertex2f(0.62f, -0.85f);
    glEnd();

    glBegin(GL_TRIANGLES); //TruckWindow
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.52f, -0.85f);
        glVertex2f(0.55f, -0.78f);
        glVertex2f(0.55f, -0.85f);
    glEnd();

    glBegin(GL_QUADS); //TruckWindow
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.57f, -0.85f);
        glVertex2f(0.60f, -0.85f);
        glVertex2f(0.60f, -0.80f);
        glVertex2f(0.57f, -0.80f);
    glEnd();
    glBegin(GL_QUADS); //truck1wheelB
        glColor3f(0.412, 0.412, 0.412);
        DrawCircle(0.52, -0.92, .029, 1300);
    glEnd();
    glBegin(GL_QUADS); //truck1wheelF
        glColor3f(0.412, 0.412, 0.412);
        DrawCircle(0.68, -0.92, .029, 1300);
    glEnd();
    glBegin(GL_QUADS); //car1wheelrimB
        glColor3f(0.863, 0.863, 0.863);
        DrawCircle(0.52, -0.92, .02, 1300);
    glEnd();
    glBegin(GL_QUADS); //car1wheelrimF
        glColor3f(0.863, 0.863, 0.863);
        DrawCircle(0.68, -0.92, .02, 1300);
    glEnd();
glPopMatrix();
glPushMatrix();//truck1light
glTranslatef(position5,0.0f, 0.0f);
    if(day==1 && night==0 && evening==0)
        {

        }
        else if(day==0 && night==1 && evening==0)
        {
            glBegin(GL_QUADS);
                glColor3f(1.000, 1.000, 0.000);
                glVertex2f(0.48f, -0.88f);
                glColor3f(1.000, 1.000, 0.000);
                glVertex2f(0.25f, -0.86f);
                glColor3f(1.000, 1.000, 0.000);
                glVertex2f(0.25f, -0.91f);
                glColor3f(1.000, 1.000, 0.000);
                glVertex2f(0.48f, -0.88f);
            glEnd();
        }
        else if(day==0 && night==0 && evening==1)
        {
            glBegin(GL_QUADS);
                glColor3f(1.000, 1.000, 0.000);
                glVertex2f(0.48f, -0.88f);
                glColor3f(1.000, 1.000, 1.000);
                glVertex2f(0.25f, -0.86f);
                glColor3f(1.000, 1.000, 1.000);
                glVertex2f(0.25f, -0.91f);
                glColor3f(1.000, 1.000, 0.000);
                glVertex2f(0.48f, -0.88f);
            glEnd();
        }
glPopMatrix();

glPushMatrix();//cloud_______________________________________________________________________________________
glTranslatef(position3,0.0f, 0.0f);
    glBegin(GL_QUADS); //
        glColor4f(0.863, 0.863, 0.863, 0.5);
        DrawCircle(-0.75, 0.83, .05, 1300);
        DrawCircle(-0.7, 0.8, .05, 1300);
        DrawCircle(-0.72, 0.86, .05, 1300);
        DrawCircle(-0.67, 0.88, .05, 1300);
        DrawCircle(-0.67, 0.88, .05, 1300);
        DrawCircle(-0.67, 0.82, .05, 1300);
        DrawCircle(-0.67, 0.82, .05, 1300);
        DrawCircle(-0.64, 0.85, .05, 1300);
        DrawCircle(-0.64, 0.85, .05, 1300);
    glEnd();
    glBegin(GL_QUADS); //
        glColor4f(0.863, 0.863, 0.863, 0.5);
        DrawCircle(-0.55, 0.86, .05, 1300);
        DrawCircle(-0.50, 0.83, .05, 1300);
        DrawCircle(-0.52, 0.89, .05, 1300);
        DrawCircle(-0.47, 0.91, .05, 1300);
        DrawCircle(-0.47, 0.91, .05, 1300);
        DrawCircle(-0.47, 0.85, .05, 1300);
        DrawCircle(-0.47, 0.85, .05, 1300);
        DrawCircle(-0.44, 0.88, .05, 1300);
        DrawCircle(-0.44, 0.88, .05, 1300);
    glEnd();
    glBegin(GL_QUADS); //
        glColor4f(0.863, 0.863, 0.863, 0.5);
        DrawCircle(0.75, 0.83, .05, 1300);
        DrawCircle(0.7, 0.8, .05, 1300);
        DrawCircle(0.72, 0.86, .05, 1300);
        DrawCircle(0.67, 0.88, .05, 1300);
        DrawCircle(0.67, 0.88, .05, 1300);
        DrawCircle(0.67, 0.82, .05, 1300);
        DrawCircle(0.67, 0.82, .05, 1300);
        DrawCircle(0.64, 0.85, .05, 1300);
        DrawCircle(0.64, 0.85, .05, 1300);
    glEnd();
    glBegin(GL_QUADS); //
        glColor4f(0.863, 0.863, 0.863, 0.5);
        DrawCircle(0.55, 0.86, .05, 1300);
        DrawCircle(0.50, 0.83, .05, 1300);
        DrawCircle(0.52, 0.89, .05, 1300);
        DrawCircle(0.47, 0.91, .05, 1300);
        DrawCircle(0.47, 0.91, .05, 1300);
        DrawCircle(0.47, 0.85, .05, 1300);
        DrawCircle(0.47, 0.85, .05, 1300);
        DrawCircle(0.44, 0.88, .05, 1300);
        DrawCircle(0.44, 0.88, .05, 1300);
    glEnd();
glPopMatrix();

glPushMatrix();//rainy sky
    if(rain==0)
    {

    }
    else if(rain==1)
    {
        glBegin(GL_QUADS);
            glColor3f(0.663, 0.663, 0.663);
            glVertex2f(-1.0f, 0.51f);
            glColor3f(0.663, 0.663, 0.663);
            glVertex2f( 1.0f, 0.51f);
            glColor3f(0.502, 0.502, 0.502);
            glVertex2f( 1.0f, 1.0f);
            glColor3f(0.502, 0.502, 0.502);
            glVertex2f(-1.0f, 1.0f);
        glEnd();
    }
glPopMatrix();

glPushMatrix();//windmill1
    glTranslatef(0.2f, 0.57f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees
    glBegin(GL_LINE_STRIP);
      glColor3f(1.000f, 1.0f, 1.0f);
      glVertex3f(-0.015f, -0.015f,0.0f);
      glVertex3f( 0.015f, 0.015f,0.0f);
    glEnd();
    glBegin(GL_LINE_STRIP);
      glColor3f(1.000f, 1.0f, 1.0f);
      glVertex3f(-0.015f, 0.015f,0.0f);
      glVertex3f( 0.015f, -0.015f,0.0f);
    glEnd();
    //glutSwapBuffers();
    angle -= angled;
glPopMatrix();
glPushMatrix();//windmill2
    glTranslatef(0.35f, 0.57f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees
    glBegin(GL_LINE_STRIP);
      glColor3f(1.000f, 1.0f, 1.0f);
      glVertex3f(-0.015f, -0.015f,0.0f);
      glVertex3f( 0.015f, 0.015f,0.0f);
    glEnd();
    glBegin(GL_LINE_STRIP);
      glColor3f(1.000f, 1.0f, 1.0f);
      glVertex3f(-0.015f, 0.015f,0.0f);
      glVertex3f( 0.015f, -0.015f,0.0f);
    glEnd();
    //glutSwapBuffers();
    angle -= angled;
glPopMatrix();
glPushMatrix();//windmill3
    glTranslatef(0.5f, 0.57f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees
    glBegin(GL_LINE_STRIP);
      glColor3f(1.000f, 1.0f, 1.0f);
      glVertex3f(-0.015f, -0.015f,0.0f);
      glVertex3f( 0.015f, 0.015f,0.0f);
    glEnd();
    glBegin(GL_LINE_STRIP);
      glColor3f(1.000f, 1.0f, 1.0f);
      glVertex3f(-0.015f, 0.015f,0.0f);
      glVertex3f( 0.015f, -0.015f,0.0f);
    glEnd();
    //glutSwapBuffers();
    angle -= angled;
glPopMatrix();
glPushMatrix();//windmill4
    glTranslatef(0.4f, 0.57f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees
    glBegin(GL_LINE_STRIP);
      glColor3f(1.000f, 1.0f, 1.0f);
      glVertex3f(-0.015f, -0.015f,0.0f);
      glVertex3f( 0.015f, 0.015f,0.0f);
    glEnd();
    glBegin(GL_LINE_STRIP);
      glColor3f(1.000f, 1.0f, 1.0f);
      glVertex3f(-0.015f, 0.015f,0.0f);
      glVertex3f( 0.015f, -0.015f,0.0f);
    glEnd();
    //glutSwapBuffers();
    angle -= angled;
glPopMatrix();
glPushMatrix();//windmill5
    glTranslatef(0.3f, 0.57f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees
    glBegin(GL_LINE_STRIP);
      glColor3f(1.000f, 1.0f, 1.0f);
      glVertex3f(-0.015f, -0.015f,0.0f);
      glVertex3f( 0.015f, 0.015f,0.0f);
    glEnd();
    glBegin(GL_LINE_STRIP);
      glColor3f(1.000f, 1.0f, 1.0f);
      glVertex3f(-0.015f, 0.015f,0.0f);
      glVertex3f( 0.015f, -0.015f,0.0f);
    glEnd();
    //glutSwapBuffers();
    angle -= angled;
glPopMatrix();
glPushMatrix();//windmill poles
    glBegin(GL_LINE_STRIP);
      glColor3f(1.000f, 1.0f, 1.0f);
      glVertex3f( 0.5f, 0.51f,0.0f);
      glVertex3f( 0.5f, 0.57f,0.0f);
    glEnd();
    glBegin(GL_LINE_STRIP);
      glColor3f(1.000f, 1.0f, 1.0f);
      glVertex3f( 0.35f, 0.51f,0.0f);
      glVertex3f( 0.35f, 0.57f,0.0f);
    glEnd();
    glBegin(GL_LINE_STRIP);
      glColor3f(1.000f, 1.0f, 1.0f);
      glVertex3f( 0.2f, 0.51f,0.0f);
      glVertex3f( 0.2f, 0.57f,0.0f);
    glEnd();
    glBegin(GL_LINE_STRIP);
      glColor3f(1.000f, 1.0f, 1.0f);
      glVertex3f( 0.3f, 0.51f,0.0f);
      glVertex3f( 0.3f, 0.57f,0.0f);
    glEnd();
    glBegin(GL_LINE_STRIP);
      glColor3f(1.000f, 1.0f, 1.0f);
      glVertex3f( 0.4f, 0.51f,0.0f);
      glVertex3f( 0.4f, 0.57f,0.0f);
    glEnd();
glPopMatrix();

glPushMatrix();//rainy cloud
    if(rain==0)
    {

    }
    else if(rain==1)
    {
        glBegin(GL_QUADS); //
        glColor3f(0.412, 0.412, 0.412);
        DrawCircle(-0.95, 0.88, .08, 1300);
        DrawCircle(-0.9, 0.85, .08, 1300);
        DrawCircle(-0.92, 0.91, .08, 1300);
        DrawCircle(-0.87, 0.93, .08, 1300);
        DrawCircle(-0.87, 0.93, .08, 1300);
        DrawCircle(-0.87, 0.87, .08, 1300);
        DrawCircle(-0.87, 0.87, .08, 1300);
        DrawCircle(-0.84, 0.90, .08, 1300);
        DrawCircle(-0.84, 0.90, .08, 1300);
    glEnd();
    glBegin(GL_QUADS); //
        glColor3f(0.412, 0.412, 0.412);
        DrawCircle(-0.75, 0.88, .08, 1300);
        DrawCircle(-0.7, 0.85, .08, 1300);
        DrawCircle(-0.72, 0.91, .08, 1300);
        DrawCircle(-0.67, 0.93, .08, 1300);
        DrawCircle(-0.67, 0.93, .08, 1300);
        DrawCircle(-0.67, 0.87, .08, 1300);
        DrawCircle(-0.67, 0.87, .08, 1300);
        DrawCircle(-0.64, 0.90, .08, 1300);
        DrawCircle(-0.64, 0.90, .08, 1300);
    glEnd();
    glBegin(GL_QUADS); //
        glColor3f(0.412, 0.412, 0.412);
        DrawCircle(-0.55, 0.88, .08, 1300);
        DrawCircle(-0.50, 0.85, .08, 1300);
        DrawCircle(-0.52, 0.91, .08, 1300);
        DrawCircle(-0.47, 0.93, .08, 1300);
        DrawCircle(-0.47, 0.93, .08, 1300);
        DrawCircle(-0.47, 0.87, .08, 1300);
        DrawCircle(-0.47, 0.87, .08, 1300);
        DrawCircle(-0.44, 0.90, .08, 1300);
        DrawCircle(-0.44, 0.90, .08, 1300);
    glEnd();
    glBegin(GL_QUADS); //
        glColor3f(0.412, 0.412, 0.412);
        DrawCircle(-0.35, 0.88, .08, 1300);
        DrawCircle(-0.30, 0.85, .08, 1300);
        DrawCircle(-0.32, 0.91, .08, 1300);
        DrawCircle(-0.27, 0.93, .08, 1300);
        DrawCircle(-0.27, 0.93, .08, 1300);
        DrawCircle(-0.27, 0.87, .08, 1300);
        DrawCircle(-0.27, 0.87, .08, 1300);
        DrawCircle(-0.24, 0.90, .08, 1300);
        DrawCircle(-0.24, 0.90, .08, 1300);
    glEnd();
    glBegin(GL_QUADS); //neg
        glColor3f(0.412, 0.412, 0.412);
        DrawCircle(-0.15, 0.88, .08, 1300);
        DrawCircle(-0.10, 0.85, .08, 1300);
        DrawCircle(-0.12, 0.91, .08, 1300);
        DrawCircle(-0.07, 0.93, .08, 1300);
        DrawCircle(-0.07, 0.93, .08, 1300);
        DrawCircle(-0.07, 0.87, .08, 1300);
        DrawCircle(-0.07, 0.87, .08, 1300);
        DrawCircle(-0.04, 0.90, .08, 1300);
        DrawCircle(-0.04, 0.90, .08, 1300);
    glEnd();
    glBegin(GL_QUADS); //
        glColor3f(0.412, 0.412, 0.412);
        DrawCircle(0.95, 0.88, .08, 1300);
        DrawCircle(0.9, 0.85, .08, 1300);
        DrawCircle(0.92, 0.91, .08, 1300);
        DrawCircle(0.87, 0.93, .08, 1300);
        DrawCircle(0.87, 0.93, .08, 1300);
        DrawCircle(0.87, 0.87, .08, 1300);
        DrawCircle(0.87, 0.87, .08, 1300);
        DrawCircle(0.84, 0.90, .08, 1300);
        DrawCircle(0.84, 0.90, .08, 1300);
    glEnd();
    glBegin(GL_QUADS); //
        glColor3f(0.412, 0.412, 0.412);
        DrawCircle(0.75, 0.88, .08, 1300);
        DrawCircle(0.7, 0.85, .08, 1300);
        DrawCircle(0.72, 0.91, .08, 1300);
        DrawCircle(0.67, 0.93, .08, 1300);
        DrawCircle(0.67, 0.93, .08, 1300);
        DrawCircle(0.67, 0.87, .08, 1300);
        DrawCircle(0.67, 0.87, .08, 1300);
        DrawCircle(0.64, 0.90, .08, 1300);
        DrawCircle(0.64, 0.90, .08, 1300);
    glEnd();
    glBegin(GL_QUADS); //
        glColor3f(0.412, 0.412, 0.412);
        DrawCircle(0.55, 0.88, .08, 1300);
        DrawCircle(0.50, 0.85, .08, 1300);
        DrawCircle(0.52, 0.91, .08, 1300);
        DrawCircle(0.47, 0.93, .08, 1300);
        DrawCircle(0.47, 0.93, .08, 1300);
        DrawCircle(0.47, 0.87, .08, 1300);
        DrawCircle(0.47, 0.87, .08, 1300);
        DrawCircle(0.44, 0.90, .08, 1300);
        DrawCircle(0.44, 0.90, .08, 1300);
    glEnd();
    glBegin(GL_QUADS); //
        glColor3f(0.412, 0.412, 0.412);
        DrawCircle(0.35, 0.88, .08, 1300);
        DrawCircle(0.30, 0.85, .08, 1300);
        DrawCircle(0.32, 0.91, .08, 1300);
        DrawCircle(0.27, 0.93, .08, 1300);
        DrawCircle(0.27, 0.93, .08, 1300);
        DrawCircle(0.27, 0.87, .08, 1300);
        DrawCircle(0.27, 0.87, .08, 1300);
        DrawCircle(0.24, 0.90, .08, 1300);
        DrawCircle(0.24, 0.90, .08, 1300);
    glEnd();
    glBegin(GL_QUADS); //
        glColor3f(0.412, 0.412, 0.412);
        DrawCircle(0.15, 0.88, .08, 1300);
        DrawCircle(0.10, 0.85, .08, 1300);
        DrawCircle(0.12, 0.91, .08, 1300);
        DrawCircle(0.07, 0.93, .08, 1300);
        DrawCircle(0.07, 0.93, .08, 1300);
        DrawCircle(0.07, 0.87, .08, 1300);
        DrawCircle(0.07, 0.87, .08, 1300);
        DrawCircle(0.04, 0.90, .08, 1300);
        DrawCircle(0.04, 0.90, .08, 1300);
    glEnd();
    }
glPopMatrix();

glPushMatrix();//BIRD
glTranslatef(position2,0.0f, 0.0f);
   glBegin(GL_LINE_STRIP);
      glColor3f(1.000f, 1.0f, 1.0f);
      glVertex3f(0.03f, 0.8f,0.0f);
      glVertex3f( 0.05f, 0.77f,0.0f);
      glVertex3f( 0.07f, 0.8f,0.0f);
   glEnd();

   glBegin(GL_LINE_STRIP);
      glColor3f(1.000f, 1.0f, 1.0f);
      glVertex3f(0.08f, 0.8f,0.0f);
      glVertex3f( 0.1f, 0.77f,0.0f);
      glVertex3f( 0.12f, 0.8f,0.0f);
   glEnd();

   glBegin(GL_LINE_STRIP);
      glColor3f(1.000f, 1.0f, 1.0f);
      glVertex3f(0.05f, 0.85f,0.0f);
      glVertex3f( 0.07f, 0.82f,0.0f);
      glVertex3f( 0.09f, 0.85f,0.0f);
   glEnd();

   glBegin(GL_LINE_STRIP);
      glColor3f(1.000f, 1.0f, 1.0f);
      glVertex3f(0.1f, 0.85f,0.0f);
      glVertex3f( 0.12f, 0.82f,0.0f);
      glVertex3f( 0.14f, 0.85f,0.0f);
   glEnd();
glPopMatrix();

glPushMatrix();//helicopter
glTranslatef(position8,0.0f, 0.0f);
     glColor3f(0.0, 0.812, 0.412);
        DrawCircle(0.15, 0.88, .04, 1300);
     glColor3f(0.0,0.0,1.0);
        DrawCircle(0.17, 0.89, .02, 1300);
       glBegin(GL_LINES);
          glColor3f(0.000f, 0.0f, 0.0f);
          glVertex2f(0.15f, 0.92f);
          glVertex2f(0.15f, 0.94f);
       glEnd();
       glBegin(GL_LINES);
          glColor3f(0.000f, 0.0f, 0.0f);
          glVertex2f(0.07f, 0.94f);
          glVertex2f(0.23f, 0.94f);
       glEnd();
       glBegin(GL_LINES);
          glColor3f(0.000f, 0.4f, 0.8f);
          glVertex2f(0.02f, 0.89f);
          glVertex2f(0.11f, 0.89f);
       glEnd();
       glBegin(GL_LINES);
          glColor3f(0.000f, 0.4f, 0.8f);
          glVertex2f(0.02f, 0.885f);
          glVertex2f(0.11f, 0.885f);
       glEnd();
       glBegin(GL_LINES);
          glColor3f(0.000f, 0.4f, 0.8f);
          glVertex2f(0.02f, 0.88f);
          glVertex2f(0.11f, 0.88f);
       glEnd();
       glBegin(GL_LINES);
          glColor3f(0.000f, 0.4f, 0.8f);
          glVertex2f(0.02f, 0.92f);
          glVertex2f(0.02f, 0.88f);
       glEnd();
glPopMatrix();

glPushMatrix();//rain drops0
glTranslatef(0.0f, position7, 0.0f);
    if(rain==0)
    {

    }
    else if(rain==1)
    {
            float x_ch=-0.99;
            float y_ch_1=2.96;
            float y_ch_2=2.94;
                for(int axis=0;axis<50;axis++)
                {
                    glBegin(GL_LINES);
                    glColor3f(0.000, 0.000, 0.804);
                        glVertex2f(x_ch, y_ch_1);
                        glVertex2f(x_ch, y_ch_2);
                    glEnd();
                    y_ch_1-=0.1;
                    y_ch_2-=0.1;
                }
    }
glPopMatrix();
glPushMatrix();//rain drops1
glTranslatef(0.0f, position7, 0.0f);
    if(rain==0)
    {

    }
    else if(rain==1)
    {
            float x_ch=-0.9;
            float y_ch_1=2.99;
            float y_ch_2=2.97;
                for(int axis=0;axis<50;axis++)
                {
                    glBegin(GL_LINES);
                    glColor3f(0.000, 0.000, 0.804);
                        glVertex2f(x_ch, y_ch_1);
                        glVertex2f(x_ch, y_ch_2);
                    glEnd();
                    y_ch_1-=0.1;
                    y_ch_2-=0.1;
                }
    }
glPopMatrix();
glPushMatrix();//rain drops2
glTranslatef(0.0f, position7, 0.0f);
    if(rain==0)
    {

    }
    else if(rain==1)
    {
            float x_ch=-0.8;
            float y_ch_1=2.96;
            float y_ch_2=2.94;
                for(int axis=0;axis<50;axis++)
                {
                    glBegin(GL_LINES);
                    glColor3f(0.000, 0.000, 0.804);
                        glVertex2f(x_ch, y_ch_1);
                        glVertex2f(x_ch, y_ch_2);
                    glEnd();
                    y_ch_1-=0.1;
                    y_ch_2-=0.1;
                }
    }
glPopMatrix();
glPushMatrix();//rain drops3
glTranslatef(0.0f, position7, 0.0f);
    if(rain==0)
    {

    }
    else if(rain==1)
    {
            float x_ch=-0.7;
            float y_ch_1=2.99;
            float y_ch_2=2.97;
                for(int axis=0;axis<50;axis++)
                {
                    glBegin(GL_LINES);
                    glColor3f(0.000, 0.000, 0.804);
                        glVertex2f(x_ch, y_ch_1);
                        glVertex2f(x_ch, y_ch_2);
                    glEnd();
                    y_ch_1-=0.1;
                    y_ch_2-=0.1;
                }
    }
glPopMatrix();
glPushMatrix();//rain drops4
glTranslatef(0.0f, position7, 0.0f);
    if(rain==0)
    {

    }
    else if(rain==1)
    {
            float x_ch=-0.6;
            float y_ch_1=2.96;
            float y_ch_2=2.94;
                for(int axis=0;axis<50;axis++)
                {
                    glBegin(GL_LINES);
                    glColor3f(0.000, 0.000, 0.804);
                        glVertex2f(x_ch, y_ch_1);
                        glVertex2f(x_ch, y_ch_2);
                    glEnd();
                    y_ch_1-=0.1;
                    y_ch_2-=0.1;
                }
    }
glPopMatrix();
glPushMatrix();//rain drops5
glTranslatef(0.0f, position7, 0.0f);
    if(rain==0)
    {

    }
    else if(rain==1)
    {
            float x_ch=-0.5;
            float y_ch_1=2.99;
            float y_ch_2=2.97;
                for(int axis=0;axis<50;axis++)
                {
                    glBegin(GL_LINES);
                    glColor3f(0.000, 0.000, 0.804);
                        glVertex2f(x_ch, y_ch_1);
                        glVertex2f(x_ch, y_ch_2);
                    glEnd();
                    y_ch_1-=0.1;
                    y_ch_2-=0.1;
                }
    }
glPopMatrix();
glPushMatrix();//rain drops6
glTranslatef(0.0f, position7, 0.0f);
    if(rain==0)
    {

    }
    else if(rain==1)
    {
            float x_ch=-0.4;
            float y_ch_1=2.96;
            float y_ch_2=2.94;
                for(int axis=0;axis<50;axis++)
                {
                    glBegin(GL_LINES);
                    glColor3f(0.000, 0.000, 0.804);
                        glVertex2f(x_ch, y_ch_1);
                        glVertex2f(x_ch, y_ch_2);
                    glEnd();
                    y_ch_1-=0.1;
                    y_ch_2-=0.1;
                }
    }
glPopMatrix();
glPushMatrix();//rain drops7
glTranslatef(0.0f, position7, 0.0f);
    if(rain==0)
    {

    }
    else if(rain==1)
    {
            float x_ch=-0.3;
            float y_ch_1=2.99;
            float y_ch_2=2.97;
                for(int axis=0;axis<50;axis++)
                {
                    glBegin(GL_LINES);
                    glColor3f(0.000, 0.000, 0.804);
                        glVertex2f(x_ch, y_ch_1);
                        glVertex2f(x_ch, y_ch_2);
                    glEnd();
                    y_ch_1-=0.1;
                    y_ch_2-=0.1;
                }
    }
glPopMatrix();
glPushMatrix();//rain drops8
glTranslatef(0.0f, position7, 0.0f);
    if(rain==0)
    {

    }
    else if(rain==1)
    {
            float x_ch=-0.2;
            float y_ch_1=2.96;
            float y_ch_2=2.94;
                for(int axis=0;axis<50;axis++)
                {
                    glBegin(GL_LINES);
                    glColor3f(0.000, 0.000, 0.804);
                        glVertex2f(x_ch, y_ch_1);
                        glVertex2f(x_ch, y_ch_2);
                    glEnd();
                    y_ch_1-=0.1;
                    y_ch_2-=0.1;
                }
    }
glPopMatrix();
glPushMatrix();//rain drops9
glTranslatef(0.0f, position7, 0.0f);
    if(rain==0)
    {

    }
    else if(rain==1)
    {
            float x_ch=-0.1;
            float y_ch_1=2.99;
            float y_ch_2=2.97;
                for(int axis=0;axis<50;axis++)
                {
                    glBegin(GL_LINES);
                    glColor3f(0.000, 0.000, 0.804);
                        glVertex2f(x_ch, y_ch_1);
                        glVertex2f(x_ch, y_ch_2);
                    glEnd();
                    y_ch_1-=0.1;
                    y_ch_2-=0.1;
                }
    }
glPopMatrix();
glPushMatrix();//rain drops10
glTranslatef(0.0f, position7, 0.0f);
    if(rain==0)
    {

    }
    else if(rain==1)
    {
            float x_ch=-0.0;
            float y_ch_1=2.96;
            float y_ch_2=2.94;
                for(int axis=0;axis<50;axis++)
                {
                    glBegin(GL_LINES);
                    glColor3f(0.000, 0.000, 0.804);
                        glVertex2f(x_ch, y_ch_1);
                        glVertex2f(x_ch, y_ch_2);
                    glEnd();
                    y_ch_1-=0.1;
                    y_ch_2-=0.1;
                }
    }
glPopMatrix();
glPushMatrix();//rain drops11
glTranslatef(0.0f, position7, 0.0f);
    if(rain==0)
    {

    }
    else if(rain==1)
    {
            float x_ch=0.1;
            float y_ch_1=2.99;
            float y_ch_2=2.97;
                for(int axis=0;axis<50;axis++)
                {
                    glBegin(GL_LINES);
                    glColor3f(0.000, 0.000, 0.804);
                        glVertex2f(x_ch, y_ch_1);
                        glVertex2f(x_ch, y_ch_2);
                    glEnd();
                    y_ch_1-=0.1;
                    y_ch_2-=0.1;
                }
    }
glPopMatrix();
glPushMatrix();//rain drops12
glTranslatef(0.0f, position7, 0.0f);
    if(rain==0)
    {

    }
    else if(rain==1)
    {
            float x_ch=0.2;
            float y_ch_1=2.96;
            float y_ch_2=2.94;
                for(int axis=0;axis<50;axis++)
                {
                    glBegin(GL_LINES);
                    glColor3f(0.000, 0.000, 0.804);
                        glVertex2f(x_ch, y_ch_1);
                        glVertex2f(x_ch, y_ch_2);
                    glEnd();
                    y_ch_1-=0.1;
                    y_ch_2-=0.1;
                }
    }
glPopMatrix();
glPushMatrix();//rain drops13
glTranslatef(0.0f, position7, 0.0f);
    if(rain==0)
    {

    }
    else if(rain==1)
    {
            float x_ch=0.3;
            float y_ch_1=2.99;
            float y_ch_2=2.97;
                for(int axis=0;axis<50;axis++)
                {
                    glBegin(GL_LINES);
                    glColor3f(0.000, 0.000, 0.804);
                        glVertex2f(x_ch, y_ch_1);
                        glVertex2f(x_ch, y_ch_2);
                    glEnd();
                    y_ch_1-=0.1;
                    y_ch_2-=0.1;
                }
    }
glPopMatrix();
glPushMatrix();//rain drops14
glTranslatef(0.0f, position7, 0.0f);
    if(rain==0)
    {

    }
    else if(rain==1)
    {
            float x_ch=0.4;
            float y_ch_1=2.96;
            float y_ch_2=2.94;
                for(int axis=0;axis<50;axis++)
                {
                    glBegin(GL_LINES);
                    glColor3f(0.000, 0.000, 0.804);
                        glVertex2f(x_ch, y_ch_1);
                        glVertex2f(x_ch, y_ch_2);
                    glEnd();
                    y_ch_1-=0.1;
                    y_ch_2-=0.1;
                }
    }
glPopMatrix();
glPushMatrix();//rain drops15
glTranslatef(0.0f, position7, 0.0f);
    if(rain==0)
    {

    }
    else if(rain==1)
    {
            float x_ch=0.5;
            float y_ch_1=2.99;
            float y_ch_2=2.97;
                for(int axis=0;axis<50;axis++)
                {
                    glBegin(GL_LINES);
                    glColor3f(0.000, 0.000, 0.804);
                        glVertex2f(x_ch, y_ch_1);
                        glVertex2f(x_ch, y_ch_2);
                    glEnd();
                    y_ch_1-=0.1;
                    y_ch_2-=0.1;
                }
    }
glPopMatrix();
glPushMatrix();//rain drops16
glTranslatef(0.0f, position7, 0.0f);
    if(rain==0)
    {

    }
    else if(rain==1)
    {
            float x_ch=0.6;
            float y_ch_1=2.96;
            float y_ch_2=2.94;
                for(int axis=0;axis<50;axis++)
                {
                    glBegin(GL_LINES);
                    glColor3f(0.000, 0.000, 0.804);
                        glVertex2f(x_ch, y_ch_1);
                        glVertex2f(x_ch, y_ch_2);
                    glEnd();
                    y_ch_1-=0.1;
                    y_ch_2-=0.1;
                }
    }
glPopMatrix();
glPushMatrix();//rain drops17
glTranslatef(0.0f, position7, 0.0f);
    if(rain==0)
    {

    }
    else if(rain==1)
    {
            float x_ch=0.7;
            float y_ch_1=2.99;
            float y_ch_2=2.97;
                for(int axis=0;axis<50;axis++)
                {
                    glBegin(GL_LINES);
                    glColor3f(0.000, 0.000, 0.804);
                        glVertex2f(x_ch, y_ch_1);
                        glVertex2f(x_ch, y_ch_2);
                    glEnd();
                    y_ch_1-=0.1;
                    y_ch_2-=0.1;
                }
    }
glPopMatrix();
glPushMatrix();//rain drops18
glTranslatef(0.0f, position7, 0.0f);
    if(rain==0)
    {

    }
    else if(rain==1)
    {
            float x_ch=0.8;
            float y_ch_1=2.96;
            float y_ch_2=2.94;
                for(int axis=0;axis<50;axis++)
                {
                    glBegin(GL_LINES);
                    glColor3f(0.000, 0.000, 0.804);
                        glVertex2f(x_ch, y_ch_1);
                        glVertex2f(x_ch, y_ch_2);
                    glEnd();
                    y_ch_1-=0.1;
                    y_ch_2-=0.1;
                }
    }
glPopMatrix();
glPushMatrix();//rain drops19
glTranslatef(0.0f, position7, 0.0f);
    if(rain==0)
    {

    }
    else if(rain==1)
    {
            float x_ch=0.9;
            float y_ch_1=2.99;
            float y_ch_2=2.97;
                for(int axis=0;axis<50;axis++)
                {
                    glBegin(GL_LINES);
                    glColor3f(0.000, 0.000, 0.804);
                        glVertex2f(x_ch, y_ch_1);
                        glVertex2f(x_ch, y_ch_2);
                    glEnd();
                    y_ch_1-=0.1;
                    y_ch_2-=0.1;
                }
    }
glPopMatrix();
glPushMatrix();//rain drops20
glTranslatef(0.0f, position7, 0.0f);
    if(rain==0)
    {

    }
    else if(rain==1)
    {
            float x_ch=0.99;
            float y_ch_1=2.96;
            float y_ch_2=2.94;
                for(int axis=0;axis<50;axis++)
                {
                    glBegin(GL_LINES);
                    glColor3f(0.000, 0.000, 0.804);
                        glVertex2f(x_ch, y_ch_1);
                        glVertex2f(x_ch, y_ch_2);
                    glEnd();
                    y_ch_1-=0.1;
                    y_ch_2-=0.1;
                }
    }
glPopMatrix();

   glFlush();
}


int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitWindowSize(1000, 690);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("Basic Animation");
   glutDisplayFunc(display);
   init();
   glutKeyboardFunc(handleKeypress);
   glutSpecialFunc(SpecialInput);
   //9glutMouseFunc(handleMouse);
   glutTimerFunc(100, update, 0);
   glutTimerFunc(100, updatec1, 0);
   glutTimerFunc(100, update2, 0);
   glutTimerFunc(100, update3, 0);
   //glutTimerFunc(100, update4, 0);
   glutTimerFunc(100, update5, 0);
   glutTimerFunc(100, update6, 0);
   glutTimerFunc(100, update7, 0);
   glutTimerFunc(100, update8, 0);
   glutTimerFunc(0, Timer, 0);

   sndPlaySound("15980_1460552244.wav", SND_ASYNC);
  // sndPlaySound("rain-07.wav", SND_ASYNC);
   glutMainLoop();
   return 0;
}

/*void handleMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speed += 0.1f;
			printf("clicked at (%d, %d)\n", x, y);
		}
	}
	glutPostRedisplay();
}*/
