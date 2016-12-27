/**
 * @file lookAtCamera.hpp
 * @brief Classe de caméra utilisant gluLookAt
 * @author Pierre Chevalier et Benoît Garçon
 * @version 1.0
 * @date Octobre 2016
 */

#ifndef HEADER_BITMAP_HPP
#define HEADER_BITMAP_HPP

#include <vector>
/** @brief Structure pour stocker un buffer de pixels (BITMAP)
 * dans le but d'en faire une texture. */
class PixelsBuffer{

  int mWidth; /// largeur (pixels)
  int mHeight; /// hauteur (pixels)
  int mBytesPerPixel; /// Nombre d'octets par pixel
  int mScanLineWidth; /// Largeur d'une scanline doit être multiple de 4
		      // = width*bytesPerPixel + ((4-(width*bytesPerPixel)%4)%4);
  std::vector<unsigned char> mPixels; /// couleurs des pixels dans un tableau contigu.

  /** Constructeur par défaut */
  PixelsBuffer()
  :mWidth(0),
    mHeight(0),
    mBytesPerPixel(0),
    mScanLineWidth(0),
    mPixels()
  {}

  public:

  /** Constructeur avec fond blanc */
  PixelsBuffer(int width, int height, int bytesPerPixel)
  :mWidth(width),
    mHeight(height),
    mBytesPerPixel(bytesPerPixel),
    mScanLineWidth(width*bytesPerPixel + (4-(width*bytesPerPixel)%4)%4),
    mPixels(mScanLineWidth*height, 0xff)
  {}

  /** Constructeur en copiant un buffer */
  PixelsBuffer(int width, int height, int bytesPerPixel, unsigned char* data)
  :mWidth(width),
    mHeight(height),
    mBytesPerPixel(bytesPerPixel),
    mScanLineWidth(width*bytesPerPixel + (4-(width*bytesPerPixel)%4)%4),
    mPixels(mScanLineWidth*height)
  {
    memcpy(mPixels.data(), data, mScanLineWidth*height);
  }

  /** Modifie la taille du buffer
   * @return true si la dimension du buffer suffit
   **/
  void SetSize(int width, int height, int bytesPerPixel){
    mWidth = width;
    mHeight = height;
    mBytesPerPixel = bytesPerPixel;
    mScanLineWidth = width*bytesPerPixel + (4-(width*bytesPerPixel)%4)%4;
    mPixels = std::vector<unsigned char>(mScanLineWidth*height, 0xff);
  }

  /** Width accessor */
  int GetWidth(){
    return mWidth;
  }

  /** Height accessor */
  int GetHeight(){
    return mHeight;
  }

  /** Bytes Per Pixel accessor */
  int GetBytesPerPixel(){
    return mBytesPerPixel;
  }

  /** Set pixelsvalues */
  void SetPixelBytes(int x, int y, unsigned char *array){
    int startByte = x*mScanLineWidth + y*mBytesPerPixel;
    memcpy(mPixels.data()+startByte, array, mBytesPerPixel);
  }

  /** Acces raw pointer to pixels */
  unsigned char* GetRawData(){
    return mPixels.data();
  }
};

#endif
