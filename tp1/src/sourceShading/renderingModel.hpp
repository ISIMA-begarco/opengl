/**
 * @file renderingModel.hpp
 * @brief Matériel et rendu
 * @author Pierre Chevalier et Benoît Garçon
 * @version 1.0
 * @date Octobre 2016
 */

#ifndef HEADER_SHADING_HPP
#define HEADER_SHADING_HPP

/**
* Structure qui contient les proprietes d ’un materiau
**/
struct Material {
  GLfloat mAmbient [ 4 ] ; // Coefficient de réflexion ambiante
  GLfloat mDiffuse [ 4 ] ; // Coefficient de réflexion diffuse
  GLfloat mSpecular [ 4 ] ; // Coefficient de réflexion spéculaire
  GLfloat mShininess [1] ; // Brillance

  /** Initialise les attributs en mettant 1.0 dans l e canal alpha */
  Material ( GLfloat ambientR , GLfloat ambientG , GLfloat ambientB ,
  GLfloat diffuseR , GLfloat diffuseG , GLfloat diffuseB ,
  GLfloat specularR , GLfloat specularG , GLfloat specularB ,
  GLfloat shininess ) {
    mShininess [0] = shininess ;
    mAmbient [ 0 ] = ambientR ; mAmbient [ 1 ] = ambientG ; mAmbient [ 2 ] = ambientB ;
    mAmbient [ 3 ] = 1.0 ;
    mDiffuse [ 0 ] = diffuseR ; mDiffuse [ 1 ] = diffuseG ; mDiffuse [ 2 ] = diffuseB ;
    mDiffuse [ 3 ] = 1.0 ;
    mSpecular [ 0 ] = specularR ; mSpecular [ 1 ] = specularG ; mSpecular [ 2 ] =  specularB ;
    mSpecular [ 3 ] = 1.0 ;
  }
};


/**
* MÉTHODES CONCERNANT LES MODÈLES DE RENDU ET D’ÉCLAIREMENT
**/
struct RenderingModel{
	/** Initialise les paramètres globaux du rendu de la scène */
	static void Init () {
		glClearColor ( 0.0 , 0.0 , 0.0 , 0.0 ) ; // Régler la couleur de fond
		glEnable (GL_DEPTH_TEST) ; // Élimination des parties cachées
		glEnable (GL_LIGHTING) ; // Active l’éclairage
		glLightModelf (GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE) ; // modèle local
		glShadeModel (GL_SMOOTH) ; // lissage de phong
		
		// Intensité de la lumière ambiante
		GLfloat ambientIntensityScene[] = {0.2f , 0.2f , 0.2f , 1.0f } ;
		glLightModelfv (GL_LIGHT_MODEL_AMBIENT, ambientIntensityScene ) ;
	}

		/** Réinitialise la vue ( efface l’écran ) */
	static void InitView ( ) {
		glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT) ;
	}

	/** Positionner la source dans le repère courant 
	* @param GLint lightId id de la source lumineuse a activer
	* @param GLfloat[] position nouvelle position
	*/
	static void ApplyPointLightPosition ( GLint lightId , const GLfloat position [ 4 ] ) {
		glLightfv( lightId , GL_POSITION, position ) ;
	}

	/** Applique l’intensité d'une source lumineuse donnée par son ID et active la source 
	* @param GLint lightId id de la source lumineuse a activer
	* @param GLfloat[] diffuseIntensity valeur diffuse
	* @param GLfloat[] specularIntensity valeur speculaire
	*/
	static void ApplyPointLightIntensity ( 
		GLint lightId,
		const GLfloat diffuseIntensity[4] ,
		const GLfloat specularIntensity[4] ) {
		
		glLightfv( lightId , GL_DIFFUSE, diffuseIntensity ) ;
		glLightfv( lightId  , GL_SPECULAR, specularIntensity ) ;
		glEnable ( lightId  ) ;
	}

	/** Désactive une source lumineuse donnée par son ID 
	* @param id de la lumiere a desactiver
	*/
	static void DisablePointLight ( GLint lightId ) {
		glDisable ( lightId ) ;
	}

	/** Applique des propriétés de matériaux pour les rendus qui vont suivre 
	* @param Material materiau a appliquer
	*/
	static void ApplyMaterial ( Material material ) {
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material.mAmbient) ;
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material.mDiffuse ) ;
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material.mSpecular ) ;
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, material.mShininess ) ;
	}

	/** Dessin d’une théière ( ajouterglutInit(&argc,argv) dans le main) */
	static void DrawTeapot ( ) {
		glutSolidTeapot (1) ;
	}
};

#endif
