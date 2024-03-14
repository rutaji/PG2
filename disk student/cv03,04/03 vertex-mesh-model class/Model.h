#include "Vertex.h"
#include "Mesh.h"
#include "ShaderProgram.h"

class Model
{
public:

    Model(const std::filesystem::path & filename) {
        // load mesh (all meshes) of the model, load material of each mesh, load textures...
        // TODO: call LoadOBJFile, LoadMTLFile, process data, create mesh and set its properties 
    }

    void Draw(const ShaderProgram & shader) {
        // call Draw() on all meshes
        for (auto const& mesh : meshes) {
            mesh.Draw(shader);
        }
    }

private:
    std::vector<Mesh> meshes;
    std::string name;
    
    void LoadOBJFile(const std::filesystem::pathg& filename); //TODO: modify
    void LoadMTLFile(const std::filesystem::pathg& filename); //TODO: implement
    
    //GLuint LoadTexture(const std::filesystem::pathg& filename);
    
    //...
}

