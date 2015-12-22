#include "..\Include\Mesh.h"

Mesh::Mesh(std::string modelFileName) : m_fileName(modelFileName)
{
	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_ibo);
	Assimp::Importer importer;
	std::string path = MESH_PATH + m_fileName;
	const aiScene* scene = importer.ReadFile(m_fileName.c_str(),
		aiProcess_Triangulate |
		aiProcess_GenSmoothNormals |
		aiProcess_FlipUVs);
	if (!scene)
	{
		MessageBox(nullptr, L"Mesh failed to load", L"Error", MB_OK);
	}
	const aiMesh* model = scene->mMeshes[0];

	std::vector<Vertex3D> vertices;
	std::vector<unsigned int> indices;

	const aiVector3D aiZeroVector(0.0f, 0.0f, 0.0f);
	for (unsigned int i = 0; i < model->mNumVertices; i++)
	{
		const aiVector3D* pPos = &(model->mVertices[i]);
		const aiVector3D* pNormal = &(model->mNormals[i]);
		const aiVector3D* pTexCoord = model->HasTextureCoords(0) ? &(model->mTextureCoords[0][i]) : &aiZeroVector;

		Vertex3D vert;
		vert.pos = Vector3(pPos->x, pPos->y, pPos->z);
		//vert.normal = Vector3(pNormal->x, pNormal->y, pNormal->z);

		vertices.push_back(vert);
	}
	for (unsigned int i = 0; i < model->mNumFaces; i++)
	{
		const aiFace& face = model->mFaces[i];
		assert(face.mNumIndices == 3);
		indices.push_back(face.mIndices[0]);
		indices.push_back(face.mIndices[1]);
		indices.push_back(face.mIndices[2]);
	}
	m_indices = 3 * model->mNumFaces;
	InitMesh(vertices, sizeof(Vertex3D), indices, 1);
}
Mesh::~Mesh()
{
	if (m_ibo)
		glDeleteBuffers(1, &m_ibo);
	if (m_vbo)
		glDeleteBuffers(1, &m_vbo);
}
void Mesh::Draw()
{
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	// Pos
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3D), BUFFER_OFFSET(0));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glDrawElements(GL_TRIANGLES, m_indices, GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
}
void Mesh::InitMesh(const std::vector<Vertex3D> & vertices, int vertSize, const std::vector<unsigned int> & indices, int indexSize)
{

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, vertSize * sizeof(Vertex3D), &vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexSize * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
}
