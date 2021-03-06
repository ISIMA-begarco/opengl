/**
 * @file light.hpp
 * @brief Classes de lumière
 * @author Pierre Chevalier et Benoît Garçon
 * @version 1.0
 * @date Octobre 2016
 */

#ifndef HEADER_LIGHT_SOURCE_HPP
#define HEADER_LIGHT_SOURCE_HPP

#include <vector>
#include "renderingModel.hpp"
/**
 *  MÉTHODES CONCERNANT LES MODÈLES DE SOURCES LUMINEUSES
 */
struct LightSourceData{
    /** Classe représentant une source lumineuse */
  struct PointLightSource{
    int mLightId; /// ATTENTION NE FONCTIONNE QU'AVEC GL_LIGHT0, GL_LIGHT1, etc.
    float mIntensity; /// Intensité de la source de lumiere

    float mLightPosition[4] = {0.0f,0.0f,10.0f,0.0f};	/// Position de la source de lumiere
    float mDiffuseIntensity[4] = {0.6f,0.6f,0.6f,1.0f}; // Intensité diffuse de la source de lumiere
    float mSpecularIntensity[4] = {0.6f,0.6f,0.6f,1.0f}; // Intensité spéculaire de la source de lumiere

    PointLightSource(){}

    /** Constructeur initialisant toutes les propriétés de la source */
    PointLightSource(int lightId, float intensity,
                float lightPositionX, float lightPositionY, float lightPositionZ,
                float diffuseIntensityR, float diffuseIntensityG, float diffuseIntensityB,
                float specularIntensityR, float specularIntensityG, float specularIntensityB)
      :mLightId(lightId), mIntensity(intensity)
    {
      mLightPosition[0] = lightPositionX;
      mLightPosition[1] = lightPositionY;
      mLightPosition[2] = lightPositionZ;
      mLightPosition[3] = 1.0;
      mDiffuseIntensity[0] = diffuseIntensityR;
      mDiffuseIntensity[1] = diffuseIntensityG;
      mDiffuseIntensity[2] = diffuseIntensityB;
      mDiffuseIntensity[3] = 1.0;
      mSpecularIntensity[0] = specularIntensityR;
      mSpecularIntensity[1] = specularIntensityG;
      mSpecularIntensity[2] = specularIntensityB;
      mSpecularIntensity[3] = 1.0;
    }

    /** Positionner la source dans le repère courant */
    void ApplyPosition() const{
      RenderingModel::ApplyPointLightPosition(mLightId, mLightPosition);
    }

    /** Applique l'intensité de la source et active la source */
    void ApplyIntensity() const{
      RenderingModel::ApplyPointLightIntensity(mLightId,
				    mDiffuseIntensity, mSpecularIntensity);
    }

    /** Désactive la source */
    void Disable() const {
        RenderingModel::DisablePointLight(mLightId);
    }
    
	/** Setter d'intensite de la source
	* @param float newIntensity nouvelle valeur de l'intensite
	*/
    void setIntensity(float newIntensity){
      if(newIntensity>=0 && newIntensity<1.0){
        mIntensity=newIntensity;
        mDiffuseIntensity[0] = newIntensity;
        mDiffuseIntensity[1] = newIntensity;
        mDiffuseIntensity[2] = newIntensity;
        mSpecularIntensity[0] = newIntensity;
        mSpecularIntensity[1] = newIntensity;
        mSpecularIntensity[2] = newIntensity;
      }
    }
    
	/** Setter de la position de la source
	* @param float lightPositionX nouvelle valeur de la position X
	* @param float lightPositionY nouvelle valeur de la position Y
	* @param float lightPositionZ nouvelle valeur de la position Z
	*/
    void setPosition(float lightPositionX, float lightPositionY, float lightPositionZ){
      mLightPosition[0] = lightPositionX;
      mLightPosition[1] = lightPositionY;
      mLightPosition[2] = lightPositionZ;
    }
  };


  std::vector<PointLightSource> mSourcesRepereCamera;	/// vecteurs des sources lumineuses liees a la camera
  std::vector<PointLightSource> mSourcesRepereMonde;	// /vecteurs des sources lumineuses liees au monde
  float mIntensity;	/// Intensite commune

  /** Constructeur par défaut (ne crée aucune source lumineuse) */
  LightSourceData()
  :mSourcesRepereCamera(),
  mSourcesRepereMonde(),
  mIntensity(0.4f)
   {}

  /** Destructeur */
  ~LightSourceData() = default;


  /** Obtient l'ensemble des sources à placer dans un certain repère
   * @param reverse true pour les sources de l'autre repère que typeRepere **/
  std::vector<PointLightSource>& GetSourcesByRepere(AbstractCamera::TypeRepere typeRepere,
                                        bool reverse = false){
    if (typeRepere == AbstractCamera::TypeRepere::CAMERA){
      return reverse ? mSourcesRepereMonde : mSourcesRepereCamera;
    }
    return reverse ? mSourcesRepereCamera : mSourcesRepereMonde;
  }

  /** Ajoute une source lumineuse dans un certain repère
   * @return true en case de succès, false en cas d'ID lightId déjà pris */
  bool AddSource(AbstractCamera::TypeRepere typeRepere, int lightId,
	  float lightPositionX, float lightPositionY, float lightPositionZ,
	  float diffuseIntensityR, float diffuseIntensityG, float diffuseIntensityB,
	  float specularIntensityR, float specularIntensityG, float specularIntensityB){

    auto& sourcesAutre = GetSourcesByRepere(typeRepere, true);
    // Test de doublon pour l'ID de la source
    for (auto it = sourcesAutre.cbegin() ; it != sourcesAutre.cend() ; it++){
        if (it->mLightId == lightId){
          return false;
        }
    }
    auto& sources = GetSourcesByRepere(typeRepere);
     // Test de doublon pour l'ID de la source
    for (auto it = sources.cbegin() ; it != sources.cend() ; ++it){
        if (it->mLightId == lightId){
          return false;
        }
    }

    GetSourcesByRepere(typeRepere).push_back(PointLightSource(lightId, mIntensity,
                lightPositionX, lightPositionY, lightPositionZ,
                diffuseIntensityR, diffuseIntensityG, diffuseIntensityB,
                specularIntensityR, specularIntensityG, specularIntensityB));
    return true;
  }

  /** Supprime une source lumineuse dans un certain repère
   * La méthode est un peu lourde pour garder des tableaux contigus.
   * @return true en case de succès, false en case d'ID inexistant */
  bool DeleteSource(int lightId){
    auto& sourcesCamera = mSourcesRepereCamera;
    // Test de doublon pour l'ID de la source
    for (auto it = sourcesCamera.begin() ; it != sourcesCamera.end() ; ++it){
        if (it->mLightId == lightId){
	  sourcesCamera.erase(it); // suppression de l'élément
          return true;
        }
    }
    auto &sourcesMonde = mSourcesRepereMonde;
    // Test de doublon pour l'ID de la source
    for (auto it = sourcesMonde.begin() ; it != sourcesMonde.end() ; ++it){
        if (it->mLightId == lightId){
	  sourcesMonde.erase(it);
         return true;
        }
    }
   return false;
  }

  /** Positionner les sources qui se trouvent dans un certain repère 
  @param AbstractCamera::TypeRepere typeRepere permet de ne faire l'application que sur un type de source */
  void ApplyLightPositions(AbstractCamera::TypeRepere typeRepere){
    auto sources = GetSourcesByRepere(typeRepere);
    for (auto it = sources.cbegin() ; it != sources.cend() ; ++it){
      it->ApplyPosition();
    }
  }

  /** Applique les intensités de toutes les sources de la scène 
  * @param float intensity nouvelle valeur de l'intensite*/
  void SetIntensities(float intensity){
    if(intensity>=0 && intensity<1.0){
      mIntensity = intensity;
      auto& sourcesCamera = mSourcesRepereCamera;
      for (auto it = sourcesCamera.begin() ; it != sourcesCamera.end() ; ++it){
        it->setIntensity(intensity);
      }
      auto& sourcesMonde = mSourcesRepereMonde;
      for (auto it = sourcesMonde.begin() ; it != sourcesMonde.end() ; ++it){
        it->setIntensity(intensity);
      }
    }
  }

  /** Renvoie la source en fonction de son id 
  * @param int lightId id de la source recherchee
  * @return PointLightSource* Renvoie la source demandee
  */
  PointLightSource* getById(int lightId){
    PointLightSource* point=NULL;
    auto& sourcesCamera = mSourcesRepereCamera;
    for (auto it = sourcesCamera.begin() ; it != sourcesCamera.end() ; ++it){
      if(it->mLightId == lightId){
        point = &(*it);
      }
    }
    auto& sourcesMonde = mSourcesRepereMonde;
    for (auto it = sourcesMonde.begin() ; it != sourcesMonde.end() ; ++it){
      if(it->mLightId == lightId){
        point = &(*it);
      }
    }
    return point;
  }

	/** Setter de la position d'une source en fct de son id
	* @param int lightId id de la lumiere
	* @param float lightPositionX nouvelle valeur de la position X
	* @param float lightPositionY nouvelle valeur de la position Y
	* @param float lightPositionZ nouvelle valeur de la position Z
	*/
	void SetPosition(int lightId, float lightPositionX, float lightPositionY, float lightPositionZ){
		PointLightSource* point = getById(lightId);
		point->setPosition(lightPositionX,lightPositionY,lightPositionZ);
		point->ApplyPosition();
	}

  /** Applique les intensités de toutes les sources de la scène */
  void ApplyLightIntensities(){
    auto& sourcesCamera = mSourcesRepereCamera;
    for (auto it = sourcesCamera.cbegin() ; it != sourcesCamera.cend() ; ++it){
      it->ApplyIntensity();
    }
    auto& sourcesMonde = mSourcesRepereMonde;
    for (auto it = sourcesMonde.cbegin() ; it != sourcesMonde.cend() ; ++it){
      it->ApplyIntensity();
    }
  }

  /** Applique les intensités de toutes les sources de la scène */
  void DisbaleLightSources(AbstractCamera::TypeRepere typeRepere){
    auto &sources = GetSourcesByRepere(typeRepere);
    for (auto it = sources.cbegin() ; it != sources.cend() ; ++it){
      it->Disable();
    }
  }
};

#endif
