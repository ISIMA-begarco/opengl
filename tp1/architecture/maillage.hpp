/**
 * @file maillage.hpp
 * @brief Classe de maillage
 * @author Pierre Chevalier et Benoît Garçon
 * @version 1.0
 * @date Octobre 2016
 */


#ifndef HEADER_MAILLAGE_HPP
#define HEADER_MAILLAGE_HPP

#include "vecteur3D.hpp"
#include <vector>

/**
* Classe de maillage, c'est a dire un ensemble de vecteur3D
* representant un objet 3D ainsi que les vecteurs normaux associes
*/
class Maillage{

  	private:
  		aiMesh* mMaillage;  /// Pointeur vers le mesh opengl

    public:
      Maillage();
      Maillage(aiMesh* maillage);
      virtual ~Maillage();

      /**
       * @brief Renvoie la liste des vertices de la scene
       */
      std::vector<Vecteur3D> getVertices();

      /**
  		 * @brief Revoie la liste des normales de la scene
  		 */
      std::vector<Vecteur3D> getNormals();
};

#endif
