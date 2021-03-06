/**
 * @file abstractScene.cpp
 * @brief Classe abstraite de scene
 * @author Pierre Chevalier et Benoît Garçon
 * @version 1.0
 * @date Octobre 2016
 */

 #include "computedScene.hpp"

void Teapot::render(){
 	glutSolidTeapot(this->mSize);
}

void SystemeSolaire::render(){
	glPushMatrix();

		// Soleil
		glutSolidSphere(mRayonSoleil, 15, 15);

		// Planete
		// Rotation superieur
		GeometricTransform::Rotate(0, 1, 0, mRevolutionSun);

		// Translation de la petite planete
		GeometricTransform::Translate(-mRayonSoleil*3, 0, 0);

		// Rotation de la planete meme
		GeometricTransform::Rotate(0, 1, 0, mRevolutionSelf);

		// Affichage de la planete
//		glutSolidSphere(mRayonSoleil/2, 10, 10);
		glutSolidTeapot(mRayonSoleil/2);

		// Update
		mRevolutionSelf=fmod((mRevolutionSelf+inc*4),360.0);
		mRevolutionSun=fmod((mRevolutionSun+inc),360.0);
	glPopMatrix();
}

void Voiture::drawRoue(){
	glPushMatrix();
		GeometricTransform::Rotate(0, 1, 0, 90);
		GeometricTransform::Rotate(0, 0, 1, mStep * mVitesseRoue);
		gluCylinder(gluNewQuadric(),
		 	5,	//base,
		 	5,  	//top,
		 	0.5, 	//height,
		 	12, 	//slices,
		 	12  	//stacks
		 );
	glPopMatrix();
}

void Voiture::drawEssieu(double longueur){
	glPushMatrix();
		GeometricTransform::Translate(-longueur/2, 0, 0);
		GeometricTransform::Rotate(0, 1, 0, 90);
		gluCylinder(gluNewQuadric(),
		 	0.5,		//base,
		 	0.5,  	//top,
		 	longueur, 	//height,
		 	8, 	//slices,
		 	8  	//stacks
		 );
	glPopMatrix();

	// Roue gauche
	glPushMatrix();
		GeometricTransform::Translate(longueur/2, 0, 0);
		drawRoue();
	glPopMatrix();

	// Roue droite
	glPushMatrix();
		GeometricTransform::Translate(-longueur/2, 0, 0);
		drawRoue();
	glPopMatrix();
}

void Voiture::drawCorps(){
	// Gros bloc
	glPushMatrix();
		GeometricTransform::Scale(1,1,3);
		glutWireCube(10);
	glPopMatrix();

	// Petit bloc
	glPushMatrix();
		GeometricTransform::Translate(0, 8, -3);
		GeometricTransform::Scale(1,1,2);
		glutWireCube(8);
	glPopMatrix();

	// Essieu arriere
	glPushMatrix();
		GeometricTransform::Translate(0, -5, -12);
		drawEssieu(12);
	glPopMatrix();

	// Essieu avant
	glPushMatrix();
		GeometricTransform::Translate(0, -5, 12);
		drawEssieu(12);
	glPopMatrix();

}

void Voiture::render(){
	drawCorps();

	mStep = (mStep+1) % maxStep;
}

Cylindre::Cylindre(double pRayon, double pHauteur, int pNbMeridien, const  char* pPath)
        : AbstractScene(pPath), mRayon(pRayon), mHauteur(pHauteur), mNbMeridien(pNbMeridien) {

  float falala = 2*M_PI/this->mNbMeridien;
  float demiHauteur = this->mHauteur/2;
  for (int i=0 ; i<this->mNbMeridien+1 ; i++) {
    float fololo = i*falala;
    float folocos = this->mRayon*cos(fololo);
    float folosin = this->mRayon*sin(fololo);
    mSommets.push_back(Vecteur3D(folocos, folosin, demiHauteur));
    mSommets.push_back(Vecteur3D(folocos, folosin, -demiHauteur));
  }

}

void Cylindre::render() {
  glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUAD_STRIP);
    mTexture.SelectTexture2D();
    for (unsigned i=0 ; i<this->mSommets.size() ; i++) {
      glTexCoord2f ( ((int)((this->mSommets.size()-i)/2))/(float)(mNbMeridien), i%2 );
      glVertex3f(mSommets[i].GetX(),mSommets[i].GetY(),mSommets[i].GetZ());
    }
    glEnd();
  glPopMatrix();
}
