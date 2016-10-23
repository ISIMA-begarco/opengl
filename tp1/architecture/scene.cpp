#include "scene.hpp"

Scene::Scene(const std::string path):
mSceneMin(new aiVector3D()),
mSceneMax(new aiVector3D()),
mCenter(new aiVector3D())
{
	/* we are taking one of the postprocessing presets to avoid
	   spelling out 20+ single postprocessing flags here. */
	this->mScene = aiImportFileEx(path.c_str(),aiProcess_GenNormals, NULL); //aiProcessPreset_TargetRealtime_MaxQuality|

	if (this->mScene) {
		this->getBoundindBox();
		this->mCenter->x = (this->mSceneMin->x + this->mSceneMax->x) / 2.0f;
		this->mCenter->y = (this->mSceneMin->y + this->mSceneMax->y) / 2.0f;
		this->mCenter->z = (this->mSceneMin->z + this->mSceneMax->z) / 2.0f;
	}

}

Scene::~Scene(){
	aiReleaseImport(this->mScene);
	delete this->mCenter;
	delete this->mSceneMin;
	delete this->mSceneMax;
}

void Scene::getBoundindBox ()
{
	aiMatrix4x4 trafo;
	aiIdentityMatrix4(&trafo);

	this->mSceneMin->x = this->mSceneMin->y = this->mSceneMin->z =  1e10f;
	this->mSceneMax->x = this->mSceneMax->y = this->mSceneMax->z = -1e10f;
	getBoundindBoxForNode(this->mScene->mRootNode,&trafo);
}

void Scene::getBoundindBoxForNode (
	const aiNode* nd,
	aiMatrix4x4* trafo
){
	aiMatrix4x4 prev;

	prev = *trafo;
	aiMultiplyMatrix4(trafo,&(nd->mTransformation));

	for (unsigned n = 0; n < nd->mNumMeshes; ++n) {
		const aiMesh* mesh = this->mScene->mMeshes[nd->mMeshes[n]];
		for (unsigned t = 0; t < mesh->mNumVertices; ++t) {

			aiVector3D tmp = mesh->mVertices[t];
			aiTransformVecByMatrix4(&tmp,trafo);

			this->mSceneMin->x = aisgl_min(this->mSceneMin->x,tmp.x);
			this->mSceneMin->y = aisgl_min(this->mSceneMin->y,tmp.y);
			this->mSceneMin->z = aisgl_min(this->mSceneMin->z,tmp.z);

			this->mSceneMax->x = aisgl_max(this->mSceneMax->x,tmp.x);
			this->mSceneMax->y = aisgl_max(this->mSceneMax->y,tmp.y);
			this->mSceneMax->z = aisgl_max(this->mSceneMax->z,tmp.z);
		}
	}

	for (unsigned n = 0; n < nd->mNumChildren; ++n) {
		this->getBoundindBoxForNode(nd->mChildren[n],trafo);
	}
	*trafo = prev;
}

void Scene::render (){
	this->render(this->getRacine());
}


void Scene::render (Noeud noeud){
	this->recursiveRender(noeud.mNoeud);
}

void Scene::recursiveRender (const aiNode* nd)
{
	unsigned int i;
	aiMatrix4x4 m = nd->mTransformation;

	/* update transform */
	aiTransposeMatrix4(&m);
	glPushMatrix();
	glMultMatrixf((float*)&m);

	/* draw all meshes assigned to this node */
	for (unsigned n = 0; n < nd->mNumMeshes; ++n) {
		const aiMesh* mesh = this->mScene->mMeshes[nd->mMeshes[n]];

		//apply_material(this->mScene->mMaterials[mesh->mMaterialIndex]);

		if(mesh->mNormals == NULL) {
			glDisable(GL_LIGHTING);
		} else {
			glEnable(GL_LIGHTING);
		}

		for (unsigned t = 0; t < mesh->mNumFaces; ++t) {
			const aiFace* face = &(mesh->mFaces[t]);

			GLenum face_mode;

			switch(face->mNumIndices) {
				case 1: face_mode = GL_POINTS; break;
				case 2: face_mode = GL_LINES; break;
				case 3: face_mode = GL_TRIANGLES; break;
				default: face_mode = GL_POLYGON; break;
			}

			glBegin(face_mode);

			for(i = 0; i < face->mNumIndices; i++) {
				int index = face->mIndices[i];
				if(mesh->mColors[0] != NULL)
					glColor4fv((GLfloat*)&mesh->mColors[0][index]);
				if(mesh->mNormals != NULL)
					glNormal3fv(&mesh->mNormals[index].x);
				glVertex3fv(&mesh->mVertices[index].x);
			}

			glEnd();
		}

	}

	/* draw all children */
	for (unsigned n = 0; n < nd->mNumChildren; ++n) {
		this->recursiveRender(nd->mChildren[n]);
	}

	glPopMatrix();
}

Noeud Scene::getRacine(){
	return Noeud(this->mScene->mRootNode);
}

std::vector<Vecteur3D> Scene::getVertices(){
	std::vector<Vecteur3D> vertices;
	std::vector<Vecteur3D> temp;
	for(unsigned i=0;i<this->mScene->mNumMeshes;i++){
		Maillage maillage(this->mScene->mMeshes[i]);
		temp = maillage.getVertices();
		vertices.insert( vertices.end(), temp.begin(), temp.end() );
	}
	return vertices;
}

std::vector<Vecteur3D> Scene::getNormals(){
	std::vector<Vecteur3D> normals;
	std::vector<Vecteur3D> temp;
	for(unsigned i=0;i<this->mScene->mNumMeshes;i++){
		Maillage maillage(this->mScene->mMeshes[i]);
		temp = maillage.getNormals();
		normals.insert( normals.end(), temp.begin(), temp.end() );
	}
	return normals;
}
