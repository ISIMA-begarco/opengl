#ifndef HEADER_TEXTURES_HPP
#define HEADER_TEXTURES_HPP
/*
*
* CLASSE DE GESTION DES TEXTURES
*/

struct TextureManager{

/*
* I d e n t i f i a n t de texture
*/
  GLuint mTexId ;

/*
* Unique b u f f e r réu t i l i sé à chaque nouvel a f f i c h a g e
*/
  PixelsBuffer  mBuffer ;

/*
* Constructeur par défaut avec rendu d’un t e x t e dans la texture
*/
  TextureManager (const  char* pathToBMP):mTexId (0) ,
      mBuffer (0 ,  0 ,  0)
    {
      CreeBufferFormPicture (pathToBMP) ;
      CreeTexture2D () ;
    }

    ~TextureManager () {

      glDeleteTextures (1 , &mTexId) ;
    }

  /*
  * Sélectionne la texture
  */

  void SelectTexture2D () const
  {
    glBindTexture (GL_TEXTURE_2D,  mTexId) ;
  }

   protected :

/*
* Crée une surface SDL à p a r t i r d’un f i c h i e r BMP
*/
  SDL_Surface*  CreeSurface (const  char * pathToBMP)
  {

  ///Vér i f i c a t i o n de l’ extension du f i c h i e r
    if( strlen (pathToBMP)<5  ||
      ( strcmp (”.bmp”, pathToBMP+( strlen (pathToBMP)-4) &&
      strcmp (”.BMP”, pathToBMP+( strlen (pathToBMP)-4)) )){
      fprintf ( stderr , ”Erreur d ’ ouverture  de  f i c h i e r BMP  : %s  ( extension incorrecte )\n”,
      pathToBMP) ;
    }
    SDL_Surface *  surface = SDL_LoadBMP(pathToBMP) ;


    if ( ! surface ) {
      fprintf ( stderr , ”Erreur d ’ ouverture  de  f i c h i e r BMP  : %s  (Échec  de
      SDL_LoadBMP)\n”  ,
      pathToBMP) ;
    }
    return surface ;
  }
    public :
/*
* @brief Crée Crée dans mBuffer un b u f f e r en chargeant.
* @param pathToBMP
*/

void CreeBufferFormPicture (const  char* pathToBMP)
{
// Chargement de l’Image au format BMP
SDL_Surface*  surface = CreeSurface (pathToBMP) ;

// Création d’un b u f f e r maison à p a r t i r de la surface SDL
mBuffer = PixelsBuffer ( surface->w, surface->h, surface->format->BytesPerPixel,
(uint8_t *)surface->pixels);

//Libération de la surface
SDL_FreeSurface ( surface ) ; // On n’oublie pas , s’pas ?
     }

/*
* Crée une texture 2D en m é moire vidéo à p a r t i r du b u f f e r en v a r i a b l e g l o b a l e
* Le b u f f e r en question doit avoir é t é rempli avec des p i x e l s avec
* @link <Cree_RGBA_buffer_with_text>
*/

void CreeTexture2D ()
{
// Au cas où la texture  e x i s t e déjà
glDeleteTextures (1 , &mTexId) ;

// Génération de l’ID  de texture et sél e c t i o n
glGenTextures (1 , &mTexId) ;
SelectTexture2D () ;
// pour modifier la  texture  en mémoire  vidéo
// Paramètres de f i l t r e s  l i néaires
glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR) ;
glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR) ;

GLint mode ;

switch ( mBuffer.GetBytesPerPixel () ) {
case 1 : mode = GL_LUMINANCE;
break;

case 3 : mode = GL_RGB;
break;

case 4 : mode = GL_RGBA;
break;

default:
     fprintf( stderr , ”Nombre de  b i t s  par  p i x e l s  non gé r é\n”) ;
return;
}

//Transfer de la texture en mémoire vidéo
glTexImage2D (GL_TEXTURE_2D,  0 , mode ,  mBuffer . GetWidth () ,  mBuffer . GetHeight (),
0 , mode , GL_UNSIGNED_BYTE,  mBuffer . GetRawData () ) ;
glBindTexture  (GL_TEXTURE_2D,  mTexId) ;
   }
} ;
