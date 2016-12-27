/**
 * @file lookAtCamera.hpp
 * @brief Classe de caméra utilisant gluLookAt
 * @author Pierre Chevalier et Benoît Garçon
 * @version 1.0
 * @date Octobre 2016
 */


#ifndef HEADER_TEXTURES_HPP
#define HEADER_TEXTURES_HPP
/*
*
* CLASSE DE GESTION DES TEXTURES
*/

#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>


#include "bitmap.hpp"

/**
*	Permet d'appliquer une texture sur un objet
*/
struct TextureManager{


  GLuint mTexId ; /// Identifiant de texture
  PixelsBuffer  mBuffer ; /// Unique buffer reutilise à chaque nouvel affichage

	/** Constructeur par défaut avec rendu d’un t e x t e dans la texture */
	TextureManager (const  char* pathToBMP): mTexId (0), mBuffer (0 ,  0 ,  0) {
		CreeBufferFormPicture (pathToBMP) ;
		CreeTexture2D () ;
	}
	
	/** Destructeur par défaut */
    ~TextureManager () {
      glDeleteTextures (1 , &mTexId) ;
    }


	/** @brief Sélectionne la texture */
	void SelectTexture2D () const {
		glBindTexture (GL_TEXTURE_2D,  mTexId) ;
	}

   protected :

	/** @brief Crée une surface SDL à partir d’un fichier BMP
	* @param char * pathToBMP Chemin vers le bitmap
	* @return SDL_Surface* renvoie l'objet surface SDL
	*/
	SDL_Surface*  CreeSurface (const  char * pathToBMP)
	{

	// Vérification de l’ extension du fichier
	if( strlen (pathToBMP)<5  ||
	( strcmp (".bmp", pathToBMP+( strlen (pathToBMP)-4)) &&
	strcmp (".BMP", pathToBMP+( strlen (pathToBMP)-4)) )){
		fprintf ( stderr , "Erreur d ’ ouverture  de  fichier BMP  : %s  ( extension incorrecte )\n",
		pathToBMP) ;
	}
	SDL_Surface *  surface = SDL_LoadBMP(pathToBMP) ;

    if ( ! surface ) {
      fprintf ( stderr , "Erreur d ’ ouverture  de  fichier BMP  : %s  (Échec  de SDL_LoadBMP)\n"  ,
      pathToBMP) ;
    }
    return surface ;
  }
  
    public :
  /*
  * @brief Crée dans mBuffer un buffer en chargeant.
  * @param pathToBMP Chemin vers le bitmap
  */

  void CreeBufferFormPicture (const  char* pathToBMP)
  {
    // Chargement de l’Image au format BMP
    SDL_Surface*  surface = CreeSurface (pathToBMP) ;

    // Création d’un buffer maison à partir de la surface SDL
    mBuffer = PixelsBuffer ( surface->w, surface->h, surface->format->BytesPerPixel,
    (uint8_t *)surface->pixels);

    //Libération de la surface
    SDL_FreeSurface ( surface );
  }

  /*
  * Crée une texture 2D en m é moire vidéo à partir du buffer en variable globale
  * Le buffer en question doit avoir ete rempli avec des pixels avec
  * @link <Cree_RGBA_buffer_with_text>
  */

  void CreeTexture2D ()
  {
    // Au cas où la texture  existe déjà
    glDeleteTextures (1 , &mTexId) ;

    // Génération de l’ID  de texture et selection
    glGenTextures (1 , &mTexId) ;
    SelectTexture2D () ;
    // pour modifier la texture en mémoire vidéo
    // Paramètres de filtres  lineaires
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR) ;
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR) ;

    GLint modeIn, modeOut;

    switch ( mBuffer.GetBytesPerPixel () ) {
      case 1 :
        modeIn = GL_LUMINANCE;
        modeOut = GL_LUMINANCE;
      break;

      case 3 :
        modeIn = GL_RGB;
        modeOut = GL_BGR;
      break;

      case 4 :
        modeIn = GL_RGBA;
        modeOut = GL_RGBA;
      break;

      default:
           fprintf( stderr , "Nombre de bits par pixels  non gere\n") ;
      return;
    }

    //Transfer de la texture en mémoire vidéo
    glTexImage2D (GL_TEXTURE_2D,  0 , modeIn ,  mBuffer . GetWidth () ,  mBuffer . GetHeight (),
    0 , modeOut , GL_UNSIGNED_BYTE,  mBuffer . GetRawData () ) ;
    glBindTexture  (GL_TEXTURE_2D,  mTexId) ;
  }
};

#endif
