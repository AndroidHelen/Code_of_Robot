#include <glut.h>

int flag = 0;
int state = 1;
static int armupl = 180, armdownl = 0;//�����ֱۺ��ⲿ�ľ�̬����
static int armupr = 180, armdownr = 0;
static int blegl = 0, slegl = 0;//������Ⱥ�С�ȵľ�̬����
static int blegr = 0, slegr = 0;
float xTranslation = 0.0, yTranslation = 0.0, zTranslation = 0.0;//������//ƽ�ƾ����ʼ��Ϊ0
float xRotation = 0.0, yRotation = 0.0;//�ӽ�//��������Ϊ0

void drawbody(int armup, int armdown)//draawlimbΪ���ֱ۵ķ���,��display�����ﱻ����
{

	glPushMatrix();//������ջ����
	glTranslatef(0.0, -1.0, 0.0);//���α任����
	glRotatef((GLfloat)armup, 1.0, 0.0, 0.0);//���α任�������ֱ�
	glTranslatef(0.0, 1.0, 0.0);//���α任����
	glPushMatrix();//������ջ����
	glScalef(1.0, 2.0, 1.0);//���α任����
	glutWireCube(1.0);//����������
	glPopMatrix();//�����ջ����
	glTranslatef(0.0, 1.0, 0.0);//���α任����
	glRotatef((GLfloat)armdown, 1.0, 0.0, 0.0);//���α任�������ⲿ��
	glTranslatef(0.0, 1.5, 0.0);//���α任����
	glScalef(0.9, 3.0, 0.9); //���α任����
	glutWireCube(1.0);//����������
	glPopMatrix();//�����ջ����
}
void display(void)//��ͼ����
{
	glClear(GL_COLOR_BUFFER_BIT);//ʹ�������ɫ�����ָ���Ļ�����
	glLoadIdentity();//���õ�ǰ����Ϊ��λ����
	gluLookAt(xTranslation+30, yTranslation,  zTranslation, xTranslation, yTranslation, zTranslation, 0.0, 1.0, 0.0);//��һ�����ݾ����Դ���λ��,�ڶ������ݾ����۾����������λ��,���������ͷ������ķ���
	glRotatef(xRotation, 1.0, 0.0, 0.0);//xRotationΪ��ת�Ƕȣ��˴���ʼ��Ϊ0
	glRotatef(yRotation, 0.0, 1.0, 0.0);
	//��shoulderr��elbowerr���ֱ�
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.0f);//��ɫ
	//glColor3f(1.0f, 0.0f, 0.0f);   //��ɫ
	glTranslatef(-2.0, 3.0, 0.0);
	drawbody(armupr, armdownr);
	glPopMatrix();
	//��shoulderl��elbowl���ֱ�
	glPushMatrix();
	glTranslatef(2.0, 3.0, 0.0);
	drawbody(armupl, armdownl);
	glPopMatrix();
	//���ϰ���
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glScalef(3, 5, 2);
	glutWireCube(1.0);
	glPopMatrix();
	//����С��
	glPushMatrix();
	glTranslatef(0.0, 2.75, 0.0);
	glScalef(1.0, 0.5, 1.0);
	glutWireCube(1.0);//��һ��������(С��)����СΪһ����λ��ϵ����ʾ��С
	glScalef(1.0, 2.0, 1.0);
	glTranslatef(0.0, 0.25 + 0.75, 0.0);
	glScalef(1.5, 1.5, 1.5);
	glutWireCube(1.0);//������
	glPopMatrix();
	//��������
	glPushMatrix();
	glTranslatef(-(0.6 + 0.1), -(2.5 + 1), 0.0);
	glPushMatrix();
	glTranslatef(0.0, 1.0, 0.0);
	glRotatef((GLfloat)blegr, 1.0, 0.0, 0.0);//�Ҵ��ȿ���ת
	glTranslatef(0.0, -1.0, 0.0);
	glPushMatrix();
	glScalef(1.2, 2.0, 1.2);
	glutWireCube(1.0);//�Ҵ��ȴ�С����Ϊһ����λ���������С
	glPopMatrix();
	glTranslatef(0.0, -1.0, 0.0);
	glRotatef((GLfloat)slegr, 1.0, 0.0, 0.0);//��С�ȿ���ת
	glTranslatef(0.0, -1.25, 0.0);
	glPushMatrix();
	glScalef(1.0, 2.5, 1.0);
	glutWireCube(1.0);//����С��
	glPopMatrix();
	glTranslatef(0.0, -1.25, 0.0);
	glTranslatef(0.0, -0.25, 0.75 - 0.5);
	glScalef(1.2, 0.5, 1.5);
	glutWireCube(1.0);//���ҽŵ�
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.6 + 0.1, -(2.5 + 1), 0.0);
	glPushMatrix();
	glTranslatef(0.0, 1.0, 0.0);
	glRotatef((GLfloat)blegl, 1.0, 0.0, 0.0);//����ȿ���ת
	glTranslatef(0.0, -1.0, 0.0);
	glPushMatrix();
	glScalef(1.2, 2.0, 1.2);
	glutWireCube(1.0);//�������
	glPopMatrix();
	glTranslatef(0.0, -1.0, 0.0);
	glRotatef((GLfloat)slegl, 1.0, 0.0, 0.0);//��С�ȿ���ת
	glTranslatef(0.0, -1.25, 0.0);
	glPushMatrix();
	glScalef(1.0, 2.5, 1.0);
	glutWireCube(1.0);//����С��
	glPopMatrix();
	glTranslatef(0.0, -1.25, 0.0);
	glTranslatef(0.0, -0.25, 0.75 - 0.5);
	glScalef(1.2, 0.5, 1.5);
	glutWireCube(1.0);//����ŵ�
	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();//����������

}
void reshape(int w, int h)
{

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);//�ӿڱ任����
	glMatrixMode(GL_PROJECTION);//��ǰ������
	glLoadIdentity();//װ�ؾ�����
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 180.0);//����͸��ͶӰ�������ܿ����ķ�Χ��
	glMatrixMode(GL_MODELVIEW);//��ǰ������
	
}

void Onwalk()//�����������ߵķ���
{

	if (flag == 1)//��flagΪһʱ����ʼ��������״̬
	{

		armupl = 180; armdownl = 0;
		armupr = 180; armdownr = 0;
		blegl = 0; slegl = 0;
		blegr = 0; slegr = 0;
		flag = 0;
		return;

	}
	switch (state)//��flagΪ��ʱ������state��ֵȷ�������˵�״̬
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

	glClearColor(0.0, 0.0, 0.0, 0.0);//�����ɫ

}
int main()
{

	init();
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("MyRobot");
	glutDisplayFunc(display);//�ص�����
	glutReshapeFunc(reshape);//���ڴ�����
	glutKeyboardFunc(keyboard);//������Ϣ
	glutMainLoop();//�������к���
	return 0;

}