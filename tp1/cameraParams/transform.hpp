/******************************************************************************\
*     Copyright (C) 2016 by Rémy Malgouyres                                    * 
*     http://malgouyres.org                                                    * 
*     File: transform.hpp                                                      * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#ifndef HEADER_GEOMETRIC_TRANSFORM_HPP
#define HEADER_GEOMETRIC_TRANSFORM_HPP
/**
 * GESTION DES TRANSFORMATIONS GEOMETRIQUE (WRAPPER)
 */
struct GeometricTransform{
    static void Viewport(int32_t viewCenterX,  int32_t viewCenterY,
			 uint32_t viewWidth, uint32_t viewHeight){
      glViewport(viewCenterX, viewCenterY, viewWidth, viewHeight);
    }

 /** Applique la nouvelle projection en perspectives sur les primitives graphiques
   * Seuls les objets affichés ultérieurement sont affectés */
  static void ApplyPerspectiveProjection(double angleOuvertureY, double aspect,
					 double zProche, double zEloigne){
    // Réinitialisation des paramètres intrinsèques de la caméra
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angleOuvertureY, aspect, zProche, zEloigne);
  }
  
  /** Réinitialise la transformation ModelView à l'identité */
  static void ClearModelView(){
    // Réinitialisation des paramètres de la caméra
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
  }
  
  /** Réinitialise la transformation Projection à l'identité */
  static void ClearProjection(){
    // Réinitialisation des paramètres de la caméra
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
  }
  
  /** Redéfinit la position et l'orientation de la caméra */
  static void LookAt(double position[3], double pointDeVisee[3], double vecteurVertical[3]){
    gluLookAt(position[0], position[1], position[2], 
	      pointDeVisee[0], pointDeVisee[1], pointDeVisee[2], 
	      vecteurVertical[0], vecteurVertical[1], vecteurVertical[2]);
  }
  
  /** Applique une translation d'un vecteur */
  static void Translate(double vecX, double vecY, double vecZ){
    glTranslated(vecX, vecY, vecZ);
  }
  
  /** Applique une rotation autour de l'axe passant par O dirigé par un vecteur */
  static void Rotate(double vecX, double vecY, double vecZ, double angle){
    glRotated(vecX, vecY, vecZ, angle);
  }
  
  /** Applique un changement d'échelle (affinités orthogonales) sur chaque axe */
  static void Scale(double factorX, double factorY, double factorZ){
    glScaled(factorX, factorY, factorZ);
  }
};
#endif
