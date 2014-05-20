#include "MyRobot.h"

myRobot :: myRobot( int stacks)
{	this->stacks = stacks;
	this->teta = 0;
	this->x = 0;
	this->z = 0;
}


void myRobot :: draw()
{
	glPushMatrix();
	glTranslated(x, 0 ,z);
	glRotated(teta, 0 ,1,0);
	

		glPushMatrix();
		glRotated(90,0,1,0);
		drawComponent(2);
		glPopMatrix();


		glPushMatrix();	
		glRotated(180,0,1,0);
		drawComponent(3);		
		glPopMatrix();
	
		glPushMatrix();
		glRotated(-90,0,1,0);
		drawComponent(4);
		glPopMatrix();


		drawComponent(1);
	

		glPushMatrix();
		glRotated(180, 1,0,0);
		glBegin(GL_TRIANGLE_STRIP);
		glNormal3d(0, 1,0);
		glVertex3d(0.5,0,0.5);
		glVertex3d(0.5,0,-0.5);
		glVertex3d(-0.5,0,-0.5);
		glVertex3d(-0.5,0,0.5);
		glEnd();
		glPopMatrix();

	glPopMatrix();

}

void myRobot :: drawComponent(int side)//1 = lado da frente, 2 = esquerda, 3 = trás, 4 = direita
{
	float alpha = -45 * PI /180;//angulo do 1º vertice
	float incA = 30 * PI /180;//metade de cada angulo 

	vector <vector<double >> coordx, coordy,coordz, normalx, normalz, texturex, texturey;


	coordx.resize(stacks);
	coordy.resize(stacks);
	coordz.resize(stacks);
	normalx.resize(stacks);
	normalz.resize(stacks);
	texturex.resize(stacks);
	texturey.resize(stacks);

	for (int i = 0 ; i < stacks; i++){
		coordx[i].resize(4);
		coordy[i].resize(4);
		coordz[i].resize(4);
		normalx[i].resize(4);
		normalz[i].resize(4);
		texturex[i].resize(4);
		texturey[i].resize(4);
	}

	for (int i = 0 ; i < 4 ; i ++ )
	{
		double normalize;

		coordx[0][i] = 0.5*tan(alpha + i*incA);
		coordy[0][i] = 0;
		coordz[0][i] = 0.5;

		normalx[0][i] = 0;
		normalz[0][i] = 1;

		coordx[stacks-1][i] = 0.25*sin(alpha + incA*i); 
		coordy[stacks-1][i] = 1;
		coordz[stacks-1][i] =  0.25*cos(alpha + incA*i);

		texturex[0][i] =  (float) i/3;
		texturey[0][i] = (float) 0;


		//drawing top



		normalize = sqrt( (coordx[stacks-1][i] * coordx[stacks-1][i]) + (coordz[stacks-1][i] * coordz[stacks-1][i]));

		normalx[stacks-1][i] = coordx[stacks-1][i]/normalize;
		normalz[stacks-1][i] = coordz[stacks-1][i]/normalize;

		double incX = (double) (coordx[stacks-1][i] - coordx[0][i])/stacks;
		double incZ = (double) (coordz[stacks-1][i] - coordz[0][i])/ stacks;

		double incNx = normalx[stacks-1][i] /stacks;
		double incNz = (normalz[stacks-1][i] -1) /stacks;

		double incTx =(0.5-texturex[0][i])/(stacks +1);
		double incTy = 0.5/(stacks+1);

		for (int j = 1 ; j < stacks - 1 ; j++) // começa na 2 linha a contar por baixo e termina na penultima
		{
			coordx[j][i] = (double) incX + coordx[j-1][i];
			coordy[j][i] = (double) j/stacks;
			coordz[j][i] = (double) incZ + coordz[j-1][i];
			normalx[j][i] = (double) incNx + normalx[j-1][i];//confirmar depois
			normalz[j][i] = (double) incNz + normalz[j-1][i];
			texturex[j][i] = (double) incTx + texturex[j-1][i];
			texturey[j][i] = (double) incTy + texturey[j-1][i];
		}


		texturex[stacks-1][i] =(float) incTx + texturex[stacks-2][i];
		texturey[stacks-1][i] = (float) incTy + texturey[stacks-2][i];

		for (int k = 0 ; k < 3 ; k++)
		{
			glBegin(GL_TRIANGLES);
			glNormal3d(0,1,0);
			glTexCoord2d(0.5 ,0.5);
			glVertex3d(0,1,0);
			glTexCoord2d(texturex[stacks-1][k] , texturey[stacks-1][k] );
			glVertex3d(coordx[stacks-1][k],1,coordz[stacks-1][k]);	
			glTexCoord2d(texturex[stacks-1][k+1] , texturey[stacks-1][k+1] );
			glVertex3d(coordx[stacks-1][k+1] , 1 , coordz[stacks-1][k+1]);
			glEnd();
		}
	}



	switch(side)
	{

	case 1:
		for (unsigned int i = 0 ; i < stacks-1 ; i++)
		{

			for (unsigned int j = 0 ; j < 3 ; j++)
			{
				glBegin(GL_TRIANGLE_STRIP);

				glTexCoord2d(texturex[i][j]  , texturey[i][j] );
				glNormal3d(normalx[i][j],0,normalz[i][j]); 
				glVertex3d(coordx[i][j] , coordy[i][j] , coordz[i][j]);


				glTexCoord2d(texturex[i][j+1]  , texturey[i][j+1] );
				glNormal3d(normalx[i][j+1],0,normalz[i][j+1]); 
				glVertex3d(coordx[i][j+1] , coordy[i][j+1] , coordz[i][j+1]);

				glTexCoord2d(texturex[i+1][j]  , texturey[i+1][j] );
				glNormal3d(normalx[i+1][j],0,normalz[i+1][j]);	
				glVertex3d(coordx[i+1][j] , coordy[i+1][j] , coordz[i+1][j]);
				
				glTexCoord2d(texturex[i+1][j+1]  , texturey[i+1][j+1] );
				glNormal3d(normalx[i+1][j+1],0,normalz[i+1][j+1]);	
				glVertex3d(coordx[i+1][j+1] , coordy[i+1][j+1] , coordz[i+1][j+1]);

				
				glEnd();
			}

		}
		break;
	case 2:
		for (unsigned int i = 0 ; i < stacks-1 ; i++)
		{

			for (unsigned int j = 0 ; j < 3 ; j++)
			{
				glBegin(GL_TRIANGLE_STRIP);

				glTexCoord2d(1- texturey[i][j],texturex[i][j] );
				glNormal3d(normalx[i][j],0,normalz[i][j]); 
				glVertex3d(coordx[i][j] , coordy[i][j] , coordz[i][j]);


				glTexCoord2d(1-texturey[i][j+1],texturex[i][j+1]   );
				glNormal3d(normalx[i][j+1],0,normalz[i][j+1]); 
				glVertex3d(coordx[i][j+1] , coordy[i][j+1] , coordz[i][j+1]);

				glTexCoord2d(1-texturey[i+1][j],texturex[i+1][j]  );
				glNormal3d(normalx[i+1][j],0,normalz[i+1][j]);	
				glVertex3d(coordx[i+1][j] , coordy[i+1][j] , coordz[i+1][j]);

				glTexCoord2d( 1-texturey[i+1][j+1], texturex[i+1][j+1] );
				glNormal3d(normalx[i+1][j+1],0,normalz[i+1][j+1]);	
				glVertex3d(coordx[i+1][j+1] , coordy[i+1][j+1] , coordz[i+1][j+1]);

				glEnd();
			}

		}

		break;
	case 3:
		for (unsigned int i = 0 ; i < stacks-1 ; i++)
		{

			for (unsigned int j = 0 ; j < 3 ; j++)
			{
				glBegin(GL_TRIANGLE_STRIP);

				glTexCoord2d(1-texturex[i][j]  , 1-texturey[i][j] );
				glNormal3d(normalx[i][j],0,normalz[i][j]); 
				glVertex3d(coordx[i][j] , coordy[i][j] , coordz[i][j]);


				glTexCoord2d(1-texturex[i][j+1]  , 1-texturey[i][j+1] );
				glNormal3d(normalx[i][j+1],0,normalz[i][j+1]); 
				glVertex3d(coordx[i][j+1] , coordy[i][j+1] , coordz[i][j+1]);


				glTexCoord2d(1-texturex[i+1][j]  ,1- texturey[i+1][j] );
				glNormal3d(normalx[i+1][j],0,normalz[i+1][j]);	
				glVertex3d(coordx[i+1][j] , coordy[i+1][j] , coordz[i+1][j]);

				glTexCoord2d(1-texturex[i+1][j+1]  , 1-texturey[i+1][j+1] );
				glNormal3d(normalx[i+1][j+1],0,normalz[i+1][j+1]);	
				glVertex3d(coordx[i+1][j+1] , coordy[i+1][j+1] , coordz[i+1][j+1]);

				glEnd();
			}

		}
		break;
	case 4:

		for (unsigned int i = 0 ; i < stacks-1 ; i++)
		{

			for (unsigned int j = 0 ; j < 3 ; j++)
			{
				glBegin(GL_TRIANGLE_STRIP);

				glTexCoord2d( texturey[i][j],1-texturex[i][j] );
				glNormal3d(normalx[i][j],0,normalz[i][j]); 
				glVertex3d(coordx[i][j] , coordy[i][j] , coordz[i][j]);


				glTexCoord2d(texturey[i][j+1],1-texturex[i][j+1]   );
				glNormal3d(normalx[i][j+1],0,normalz[i][j+1]); 
				glVertex3d(coordx[i][j+1] , coordy[i][j+1] , coordz[i][j+1]);

				glTexCoord2d(texturey[i+1][j],1-texturex[i+1][j]  );
				glNormal3d(normalx[i+1][j],0,normalz[i+1][j]);	
				glVertex3d(coordx[i+1][j] , coordy[i+1][j] , coordz[i+1][j]);

				glTexCoord2d( texturey[i+1][j+1],1- texturex[i+1][j+1] );
				glNormal3d(normalx[i+1][j+1],0,normalz[i+1][j+1]);	
				glVertex3d(coordx[i+1][j+1] , coordy[i+1][j+1] , coordz[i+1][j+1]);

				glEnd();
			}

		}
		break;
	}



}

void myRobot:: processKeyboard(unsigned char key)
{
	switch (key)
	{
	case 'J':
		teta += 15; 
		break;
	case 'I':
		x += 0.5*sin(teta*PI/180);
		z += 0.5*cos(teta*PI/180);
		break;
	case 'K':
		x -= 0.5*sin(teta*PI/180);
		z -= 0.5*cos(teta*PI/180);
		break;
	case 'L':
		teta -= 15; 
		break;
	}

}