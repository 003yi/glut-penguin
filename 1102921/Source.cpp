#include <GL/glut.h>

using namespace std;
GLfloat my = 0.5f;
GLfloat angle = 0.5f;
GLfloat move_eye = 0.0f;
GLfloat move_leg = 0.0f;

GLdouble eyeX = 0.0f, eyeY = 0.0f, eyeZ = 0.0f;

void head() {
  GLUquadricObj *quadricPtr;
  quadricPtr = gluNewQuadric();
  gluQuadricDrawStyle(quadricPtr, GLU_FILL);
  gluQuadricNormals(quadricPtr, GLU_NONE);
  gluQuadricTexture(quadricPtr, GL_FALSE);
  glPushMatrix();
  glColor3f(0.0, 0.0, 0.0);
  glTranslatef(0.0, 250.0, 0.0);
  glScalef(1.3, 1, 1);
  gluSphere(quadricPtr, 220, 50, 10);
  glPopMatrix();
}

void lefteye() {
  glPushMatrix();
  GLUquadricObj *quadricPtr;
  quadricPtr = gluNewQuadric();
  gluQuadricDrawStyle(quadricPtr, GLU_FILL);
  gluQuadricNormals(quadricPtr, GLU_NONE);
  gluQuadricTexture(quadricPtr, GL_FALSE);

  glColor3f(1.0, 1.0, 1.0);
  glTranslatef(-100.0, 300.0, 250.0);
  glScalef(1, 1.3, 1.5);
  gluPartialDisk(quadricPtr, 0, 60, 20, 15, 90, 180);
  glPopMatrix();
}

void righteye() {
  glPushMatrix();
  GLUquadricObj *quadricPtr1;
  quadricPtr1 = gluNewQuadric();
  gluQuadricDrawStyle(quadricPtr1, GLU_FILL);
  gluQuadricNormals(quadricPtr1, GLU_NONE);
  gluQuadricTexture(quadricPtr1, GL_FALSE);

  glColor3f(1.0, 1.0, 1.0);
  glTranslatef(100.0, 300.0, 250.0);
  glScalef(1, 1.3, 1.5);
  gluPartialDisk(quadricPtr1, 0, 60, 20, 15, 90, 180);
  glPopMatrix();
}

void body() {
  GLUquadricObj *quadricPtr;
  quadricPtr = gluNewQuadric();
  gluQuadricDrawStyle(quadricPtr, GLU_FILL);
  gluQuadricNormals(quadricPtr, GLU_NONE);
  gluQuadricTexture(quadricPtr, GL_FALSE);

  glPushMatrix();
  glColor3f(0.0, 0.0, 0.0);
  glTranslatef(0.0, -50.0, 0.0);
  // glTranslatef(0.0, -200.0, 0.0);
  // glRotatef(-90, 1, 0, 0);
  // gluCylinder(quadricPtr, 250, 50, 500, 80, 10);
  glScalef(1.3, 1, 1);
  gluSphere(quadricPtr, 150, 50, 10);
  glPopMatrix();

  glPushMatrix();
  glColor3f(1.0, 1.0, 1.0);
  glTranslatef(0.0, -90.0, 0.0);
  glScalef(1.3, 1, 1);
  gluSphere(quadricPtr, 90, 50, 10);
  glPopMatrix();
}

void blefteye() {
  glPushMatrix();
  GLUquadricObj *quadricPtr;
  quadricPtr = gluNewQuadric();
  gluQuadricDrawStyle(quadricPtr, GLU_FILL);
  gluQuadricNormals(quadricPtr, GLU_NONE);
  gluQuadricTexture(quadricPtr, GL_FALSE);

  glColor3f(0.0, 0.0, 0.0);
  glTranslatef(-100.0 + move_eye, 300.0, 280.0);
  glRotatef(angle, 1, 1, 0);
  gluSphere(quadricPtr, 20, 50, 10);
  glPopMatrix();
}

void brighteye() {
  glPushMatrix();
  GLUquadricObj *quadricPtr1;
  quadricPtr1 = gluNewQuadric();
  gluQuadricDrawStyle(quadricPtr1, GLU_FILL);
  gluQuadricNormals(quadricPtr1, GLU_NONE);
  gluQuadricTexture(quadricPtr1, GL_FALSE);

  glColor3f(0.0, 0.0, 0.0);
  glTranslatef(100.0 + move_eye, 300.0, 280.0);
  gluSphere(quadricPtr1, 20, 50, 10);
  glPopMatrix();
}

void leftleg() {

  glPushMatrix();
  glRotatef(-move_leg, 0, 0, 1);
  glTranslatef(-60.0, -200.0, 0.0);
  glColor3f(1.0, 0.65, 0.0);
  GLUquadricObj *quadricPtr;
  quadricPtr = gluNewQuadric();
  gluQuadricDrawStyle(quadricPtr, GLU_FILL);
  gluQuadricNormals(quadricPtr, GLU_NONE);
  gluQuadricTexture(quadricPtr, GL_FALSE);
  glScalef(1.5, 0.5, 1);
  gluSphere(quadricPtr, 50, 50, 10);
  glPopMatrix();
}

void rightleg() {
  glPushMatrix();
  glRotatef(move_leg, 0, 0, 1);
  glTranslatef(60.0, -200.0, 0.0);
  glColor3f(1.0, 0.65, 0.0);
  GLUquadricObj *quadricPtr;
  quadricPtr = gluNewQuadric();
  gluQuadricDrawStyle(quadricPtr, GLU_FILL);
  gluQuadricNormals(quadricPtr, GLU_NONE);
  gluQuadricTexture(quadricPtr, GL_FALSE);
  glScalef(1.5, 0.5, 1);
  gluSphere(quadricPtr, 50, 50, 10);
  glPopMatrix();
}

void mouse() {
  glBegin(GL_TRIANGLES);
  glColor3f(1.0, 0.65, 0.0);

  glVertex3f(0.0, 200.0, 250.0);
  glVertex3f(-50.0, 170.0, 250.0);
  glVertex3f(50.0, 170.0, 250.0);

  glVertex3f(0.0, 130.0, 250.0);
  glVertex3f(-50.0, 160.0, 250.0);
  glVertex3f(50.0, 160.0, 250.0);

  glEnd();
}

void hair() {
  GLUquadricObj *quadricPtr;
  quadricPtr = gluNewQuadric();
  gluQuadricDrawStyle(quadricPtr, GLU_FILL);
  gluQuadricNormals(quadricPtr, GLU_NONE);
  gluQuadricTexture(quadricPtr, GL_FALSE);
  glPushMatrix();
  glColor3f(0.0, 0.0, 0.0);
  glTranslatef(-180.0, 400.0, 0.0);
  glRotatef(-90, 1, 1, 0);
  gluCylinder(quadricPtr, 80, 1, 150, 80, 10);
  // glRotatef(30, 0, 0, 1);
  // glScalef(0.6, 1.2, 1);
  // gluSphere(quadricPtr, 110, 50, 10);
  glPopMatrix();

  glPushMatrix();
  glColor3f(0.0, 0.0, 0.0);
  // glTranslatef(-80.0, 470.0, 0.0);
  glTranslatef(-80.0, 450.0, 0.0);
  glRotatef(-90, 1, 0.2, 0);
  gluCylinder(quadricPtr, 80, 1, 150, 80, 10);
  // glRotatef(20, 0, 0, 1);
  // glScalef(0.6, 1.2, 1);
  // gluSphere(quadricPtr, 110, 50, 10);
  glPopMatrix();

  glPushMatrix();
  glColor3f(0.0, 0.0, 0.0);
  // glTranslatef(40.0, 470.0, 0.0);
  glTranslatef(75.0, 440.0, 0.0);
  glRotatef(90, -1, 0.35, 0);
  gluCylinder(quadricPtr, 80, 1, 155, 80, 10);
  // glRotatef(160, 0, 0, 1);
  // glScalef(0.6, 1.2, 1);
  // gluSphere(quadricPtr, 110, 50, 10);
  glPopMatrix();

  glPushMatrix();
  glColor3f(0.0, 0.0, 0.0);
  // glTranslatef(155.0, 420.0, 0.0);
  glTranslatef(190.0, 400.0, 0.0);
  glRotatef(90, -1, 0.8, 0);
  gluCylinder(quadricPtr, 80, 1, 160, 80, 10);
  // glRotatef(140, 0, 0, 1);
  // glScalef(0.6, 1.2, 1);
  // gluSphere(quadricPtr, 110, 50, 10);
  glPopMatrix();
}

void lefthand() {
  GLUquadricObj *quadricPtr;
  quadricPtr = gluNewQuadric();
  gluQuadricDrawStyle(quadricPtr, GLU_FILL);
  gluQuadricNormals(quadricPtr, GLU_NONE);
  gluQuadricTexture(quadricPtr, GL_FALSE);
  glPushMatrix();
  glColor3f(0.0, 0.0, 0.0);
  glTranslatef(-155, 15.0, 0.0);
  glRotatef(-angle, 0, 0, 1);
  glScalef(1.5, 0.5, 1);
  gluSphere(quadricPtr, 60, 50, 10);
  glPopMatrix();
}

void righthand() {
  GLUquadricObj *quadricPtr;
  quadricPtr = gluNewQuadric();
  gluQuadricDrawStyle(quadricPtr, GLU_FILL);
  gluQuadricNormals(quadricPtr, GLU_NONE);
  gluQuadricTexture(quadricPtr, GL_FALSE);
  glPushMatrix();
  glColor3f(0.0, 0.0, 0.0);
  glTranslatef(150, 15.0, 0.0);
  glRotatef(angle, 0, 0, 1);
  glScalef(1.5, 0.5, 1);
  gluSphere(quadricPtr, 60, 50, 10);
  glPopMatrix();
}

void number() {
  glBegin(GL_LINES);
  glColor3f(1.0, 0.0, 0.0);

  glVertex3f(-700.0, -500.0, 0.0); // 1
  glVertex3f(-700.0, -560.0, 0.0);

  glVertex3f(-650.0, -500.0, 0.0); // 1
  glVertex3f(-650.0, -560.0, 0.0);

  glVertex3f(-600.0, -500.0, 0.0); // 0
  glVertex3f(-600.0, -560.0, 0.0);
  glVertex3f(-570.0, -500.0, 0.0);
  glVertex3f(-570.0, -560.0, 0.0);
  glVertex3f(-600.0, -500.0, 0.0);
  glVertex3f(-570.0, -500.0, 0.0);
  glVertex3f(-600.0, -560.0, 0.0);
  glVertex3f(-570.0, -560.0, 0.0);

  glVertex3f(-520.0, -500.0, 0.0); // 2
  glVertex3f(-490.0, -500.0, 0.0);
  glVertex3f(-520.0, -530.0, 0.0);
  glVertex3f(-490.0, -530.0, 0.0);
  glVertex3f(-520.0, -560.0, 0.0);
  glVertex3f(-490.0, -560.0, 0.0);
  glVertex3f(-520.0, -530.0, 0.0);
  glVertex3f(-520.0, -560.0, 0.0);
  glVertex3f(-490.0, -500.0, 0.0);
  glVertex3f(-490.0, -530.0, 0.0);

  glVertex3f(-440.0, -500.0, 0.0); // 9
  glVertex3f(-410.0, -500.0, 0.0);
  glVertex3f(-440.0, -530.0, 0.0);
  glVertex3f(-410.0, -530.0, 0.0);
  glVertex3f(-440.0, -500.0, 0.0);
  glVertex3f(-440.0, -530.0, 0.0);
  glVertex3f(-410.0, -500.0, 0.0);
  glVertex3f(-410.0, -560.0, 0.0);

  glVertex3f(-360.0, -500.0, 0.0); // 2
  glVertex3f(-330.0, -500.0, 0.0);
  glVertex3f(-360.0, -530.0, 0.0);
  glVertex3f(-330.0, -530.0, 0.0);
  glVertex3f(-360.0, -560.0, 0.0);
  glVertex3f(-330.0, -560.0, 0.0);
  glVertex3f(-360.0, -530.0, 0.0);
  glVertex3f(-360.0, -560.0, 0.0);
  glVertex3f(-330.0, -500.0, 0.0);
  glVertex3f(-330.0, -530.0, 0.0);

  glVertex3f(-280.0, -500.0, 0.0); // 1
  glVertex3f(-280.0, -560.0, 0.0);
  glEnd();
}

bool f = 0, f2 = 0, f3 = 0;

void myIdle() //旋轉
{
  /*
  angle += 0.05f;
  angle = (int)angle % 720;
  if (angle > 360)
  {
      angle = angle - 360;
  }
  else
  {
      angle = 360 - angle;
  }*/

  my += 0.05f;
  if (angle >= 20)
    f = 1;
  else if (angle <= -30)
    f = 0;
  if (!f)
    angle += 0.5f;
  else
    angle -= 0.5f;

  if (move_eye >= 50)
    f2 = 1;
  else if (move_eye <= -30)
    f2 = 0;
  if (!f2)
    move_eye += 0.08f;
  else
    move_eye -= 0.08f;

  if (move_leg >= 20)
    f3 = 1;
  else if (move_leg <= 5)
    f3 = 0;
  if (!f3)
    move_leg += 0.05f;
  else
    move_leg -= 0.05f;
  glutPostRedisplay();
}

void mydisplay() {
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // glRotatef(angle, 0, 1, 0);

  glPushMatrix();
  {
    // gluLookAt(0.5, -0.3, 0.8, 0, 0, 0, 1, 1,
    // 0);//照相機位置,物體位置,調整相機角度 glRotatef(my, 0, 1, 0);
    // gluLookAt(eyeX, eyeY, 0.1 + eyeZ, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0);
    // glRotatef(rotateAngle, 0.0f, 0.1f, 0.0f);
    head();
    hair();

    glPushMatrix();
    leftleg();
    glPopMatrix();

    glPushMatrix();
    rightleg();
    glPopMatrix();

    body();
    lefteye();
    blefteye();
    righteye();
    brighteye();

    glPushMatrix();
    mouse();
    glPopMatrix();

    glPushMatrix();
    lefthand();
    glPopMatrix();

    glPushMatrix();
    righthand();
    glPopMatrix();
  }
  glPopMatrix();
  number();

  glFlush();
}

/*void myIdle()//旋轉角度增加
{
    angle += 0.05;
    glutPostRedisplay();
}*/

void myReshape(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (w <= h)
    glOrtho(-800.0, 800.0, -800.0 * (GLfloat)h / (GLfloat)w,
            800.0 * (GLfloat)h / (GLfloat)w, -800.0, 800.0);
  else
    glOrtho(-800.0 * (GLfloat)w / (GLfloat)h, 800.0 * (GLfloat)w / (GLfloat)h,
            -800.0, 800.0, -800.0, 800.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void init() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-800.0, 800.0, -800.0, 800.0, -800.0, 800.0);
  glMatrixMode(GL_MODELVIEW);
}

void keyboardInput(unsigned char key, int x, int y) {
  if (key == 'w' || key == 'W') {
    // posY += 5;
    eyeY += 0.1;
  }
  if (key == 's' || key == 'S') {
    // posY -= 5;
    eyeY -= 0.1;
  }
  if (key == 'a' || key == 'A') {
    // posX -= 5;
    eyeX -= 0.1;
  }
  if (key == 'd' || key == 'D') {
    // posX += 5;
    eyeX += 0.1;
  }
  if (key == 'q' || key == 'Q') {
    // posX += 5;
    eyeZ -= 0.1;
  }
  if (key == 'e' || key == 'E') {
    // posX += 5;
    eyeZ += 0.1;
  }

  glutPostRedisplay();
}

void main(int argc, char **argv) {
  glutInitWindowSize(800, 800);
  glutCreateWindow("simple");
  glutDisplayFunc(mydisplay);

  init();

  glutIdleFunc(myIdle);       //旋轉
  glutReshapeFunc(myReshape); //預防圖案變形
  glutKeyboardFunc(keyboardInput);

  glutMainLoop();
}