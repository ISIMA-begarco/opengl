#ifndef HEADER_SHADING_HPP
#define HEADER_SHADING_HPP
/**
* MÉTHODES CONCERNANT LES MODÈLES DE RENDU ET D’ÉCLAIREMENT
**/
struct RenderingModel{
/** I n i t i a l i s e l e s paramètres globaux du rendu de l a scène */
static void Init ( ) {
glClearColor ( 1.0 , 1.0 , 1.0 , 1.0 ) ; // Ré g l e r l a couleur de fond

 glEnable (GL_DEPTH_TEST) ; // Élimination des p a r t i e s cach é es
 glEnable (GL_LIGHTING) ; // Active l ’ é c l a i r a g e
 glLightModelf (GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE) ; // modèle l o c a l
 glShadeModel (GL_SMOOTH) ; // l i s s a g e de phong
 // I n t e n s i t é de l a lumière ambiante
 GLfloat ambientIntensityScene[] = {0.2f , 0.2f , 0.2f , 1.0f } ;
 glLightModelfv (GL_LIGHT_MODEL_AMBIENT, ambientIntensityScene ) ;
 }

 /** Ré i n i t i a l i s e l a vue ( e f f a c e l ’ é cran ) */
 static void InitView ( ) {
 glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT) ;
 }

 /** Positionner l a source dans l e repère courant */
 static void ApplyPointLightPosition ( GLint lightId , const GLfloat position [ 4 ] ) {
 glLightfv( lightId , GL_POSITION, position ) ;
 }

 /** Applique l ’ i n t e n s i t é d ’ une source lumineuse donné e par son ID et a c t i v e l a
source */
 static void ApplyPointLightIntensity ( GLint lightId ,
 const GLfloat diffuseIntensity[4] , const GLfloat specularIntensity[4] ) {
 glLightfv( lightId , GL_DIFFUSE, diffuseIntensity ) ;
 glLightfv( lightId  , GL_SPECULAR, specularIntensity ) ;
 glEnable ( lightId  ) ;
 }

 /** Dé s a c t i v e une source lumineuse donné e par son ID */
 static void DisablePointLight ( GLint lightId ) {
 glDisable ( lightId ) ;
 }

 /** Applique des propri é t é s de maté riaux pour l e s rendus qui vont s u i v r e */
 /*static void ApplyMaterial ( Material material ) {
 glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material.mAmbient) ;
 glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material . mDiffuse ) ;
 glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material . mSpecular ) ;
 glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, material . mShininess ) ;
 }*/

 // Dessin d ’ une th é i è r e ( aj o u t e r g l u t I n i t (&argc , argv ) dans l e main)
 static void DrawTeapot ( ) {
	glutSolidTeapot (1) ;
 }
} ;
#endif
