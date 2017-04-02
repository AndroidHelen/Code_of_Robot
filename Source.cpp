#include <glut.h>

int flag = 0;
int state = 1;
static int armupl = 180, armdownl = 0;//定义手臂和肘部的静态变量
static int armupr = 180, armdownr = 0;
static int blegl = 0, slegl = 0;//定义大腿和小腿的静态变量
static int blegr = 0, slegr = 0;
float xTranslation = 0.0, yTranslation = 0.0, zTranslation = 0.0;//坐标轴//平移距离初始化为0
float xRotation = 0.0, yRotation = 0.0;//视角//缩放设置为0

void drawbody(int armup, int armdown)//draawlimb为画手臂的方法,在display方法里被调用
{

	glPushMatrix();//矩阵入栈函数
	glTranslatef(0.0, -1.0, 0.0);//几何变换函数
	glRotatef((GLfloat)armup, 1.0, 0.0, 0.0);//几何变换函数（手臂
	glTranslatef(0.0, 1.0, 0.0);//几何变换函数
	glPushMatrix();//矩阵入栈函数
	glScalef(1.0, 2.0, 1.0);//几何变换函数
	glutWireCube(1.0);//绘制立方体
	glPopMatrix();//矩阵出栈函数
	glTranslatef(0.0, 1.0, 0.0);//几何变换函数
	glRotatef((GLfloat)armdown, 1.0, 0.0, 0.0);//几何变换函数（肘部）
	glTranslatef(0.0, 1.5, 0.0);//几何变换函数
	glScalef(0.9, 3.0, 0.9); //几何变换函数
	glutWireCube(1.0);//绘制立方体
	glPopMatrix();//矩阵出栈函数
}
void display(void)//绘图函数
{
	glClear(GL_COLOR_BUFFER_BIT);//使用清除颜色来清除指定的缓冲区
	glLoadIdentity();//设置当前矩阵为单位矩阵
	gluLookAt(xTranslation+30, yTranslation,  zTranslation, xTranslation, yTranslation, zTranslation, 0.0, 1.0, 0.0);//第一组数据就是脑袋的位置,第二组数据就是眼睛看的物体的位置,第三组就是头顶朝向的方向
	glRotatef(xRotation, 1.0, 0.0, 0.0);//xRotation为旋转角度，此处初始化为0
	glRotatef(yRotation, 0.0, 1.0, 0.0);
	//画shoulderr和elbowerr右手臂
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.0f);//蓝色
	//glColor3f(1.0f, 0.0f, 0.0f);   //红色
	glTranslatef(-2.0, 3.0, 0.0);
	drawbody(armupr, armdownr);
	glPopMatrix();
	//画shoulderl和elbowl左手臂
	glPushMatrix();
	glTranslatef(2.0, 3.0, 0.0);
	drawbody(armupl, armdownl);
	glPopMatrix();
	//画上半身
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glScalef(3, 5, 2);
	glutWireCube(1.0);
	glPopMatrix();
	//画大小脑
	glPushMatrix();
	glTranslatef(0.0, 2.75, 0.0);
	glScalef(1.0, 0.5, 1.0);
	glutWireCube(1.0);//画一个立方体(小脑)，大小为一个单位，系数表示大小
	glScalef(1.0, 2.0, 1.0);
	glTranslatef(0.0, 0.25 + 0.75, 0.0);
	glScalef(1.5, 1.5, 1.5);
	glutWireCube(1.0);//画大脑
	glPopMatrix();
	//画两条腿
	glPushMatrix();
	glTranslatef(-(0.6 + 0.1), -(2.5 + 1), 0.0);
	glPushMatrix();
	glTranslatef(0.0, 1.0, 0.0);
	glRotatef((GLfloat)blegr, 1.0, 0.0, 0.0);//右大腿可旋转
	glTranslatef(0.0, -1.0, 0.0);
	glPushMatrix();
	glScalef(1.2, 2.0, 1.2);
	glutWireCube(1.0);//右大腿大小设置为一个单位的立方体大小
	glPopMatrix();
	glTranslatef(0.0, -1.0, 0.0);
	glRotatef((GLfloat)slegr, 1.0, 0.0, 0.0);//右小腿可旋转
	glTranslatef(0.0, -1.25, 0.0);
	glPushMatrix();
	glScalef(1.0, 2.5, 1.0);
	glutWireCube(1.0);//画右小腿
	glPopMatrix();
	glTranslatef(0.0, -1.25, 0.0);
	glTranslatef(0.0, -0.25, 0.75 - 0.5);
	glScalef(1.2, 0.5, 1.5);
	glutWireCube(1.0);//画右脚底
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.6 + 0.1, -(2.5 + 1), 0.0);
	glPushMatrix();
	glTranslatef(0.0, 1.0, 0.0);
	glRotatef((GLfloat)blegl, 1.0, 0.0, 0.0);//左大腿可旋转
	glTranslatef(0.0, -1.0, 0.0);
	glPushMatrix();
	glScalef(1.2, 2.0, 1.2);
	glutWireCube(1.0);//画左大腿
	glPopMatrix();
	glTranslatef(0.0, -1.0, 0.0);
	glRotatef((GLfloat)slegl, 1.0, 0.0, 0.0);//左小腿可旋转
	glTranslatef(0.0, -1.25, 0.0);
	glPushMatrix();
	glScalef(1.0, 2.5, 1.0);
	glutWireCube(1.0);//画左小腿
	glPopMatrix();
	glTranslatef(0.0, -1.25, 0.0);
	glTranslatef(0.0, -0.25, 0.75 - 0.5);
	glScalef(1.2, 0.5, 1.5);
	glutWireCube(1.0);//画左脚底
	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();//交换缓冲区

}
void reshape(int w, int h)
{

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);//视口变换函数
	glMatrixMode(GL_PROJECTION);//当前矩阵函数
	glLoadIdentity();//装载矩阵函数
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 180.0);//设置透视投影矩阵（我能看到的范围）
	glMatrixMode(GL_MODELVIEW);//当前矩阵函数
	
}

void Onwalk()//机器人连续走的方法
{

	if (flag == 1)//当flag为一时，初始化机器人状态
	{

		armupl = 180; armdownl = 0;
		armupr = 180; armdownr = 0;
		blegl = 0; slegl = 0;
		blegr = 0; slegr = 0;
		flag = 0;
		return;

	}
	switch (state)//当flag为零时，根据state的值确定机器人的状态
	{

	case 1:
		armupl = armupl + 5;
		armupr = armupr - 5;
		blegl = blegl - 3;
		blegr = blegr + 3;
		armdownr = armdownr - 3;
		slegr = slegr + 3;
		if (armupl >= 210)
		{

			state = 2;

		}
		break;
	case 2:
		armupl = armupl - 5;
		armupr = armupr + 5;
		blegl = blegl + 3;
		blegr = blegr - 3;
		armdownr = armdownr + 3;
		slegr = slegr - 3;
		if (armupl == 180)
		{

			state = 3;

		}
		break;
	case 3:
		armupl = armupl - 5;
		armupr = armupr + 5;
		blegl = blegl + 3;
		blegr = blegr - 3;
		armdownl = armdownl - 3;
		slegl = slegl + 3;
		if (armupl <= 150)
		{

			state = 4;

		}
		break;
	case 4:
		armupl = armupl + 5;
		armupr = armupr - 5;
		blegl = blegl - 3;
		blegr = blegr + 3;
		armdownl = armdownl + 3;
		slegl = slegl - 3;
		if (armupl == 180)
		{

			state = 1;

		}
		break;
	default:
		break;

	}

}
void keyboard(unsigned char key, int x, int y)
{
		Onwalk();
		glutPostRedisplay();
}

void init(void)
{

	glClearColor(0.0, 0.0, 0.0, 0.0);//清除颜色

}
int main()
{

	init();
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("MyRobot");
	glutDisplayFunc(display);//回调函数
	glutReshapeFunc(reshape);//窗口处理函数
	glutKeyboardFunc(keyboard);//键盘消息
	glutMainLoop();//程序运行函数
	return 0;

}