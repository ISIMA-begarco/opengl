#ifndef HEADER_MAILLAGE_HPP
#define HEADER_MAILLAGE_HPP

#include "vecteur3D.hpp"
#include <vector>

class Maillage{

  	private:
  		aiMesh* mMaillage;

    public:
      Maillage();
      Maillage(aiMesh* maillage);
      virtual ~Maillage();

      std::vector<Vecteur3D> getVertices();
      std::vector<Vecteur3D> getNormals();
};

#endif
