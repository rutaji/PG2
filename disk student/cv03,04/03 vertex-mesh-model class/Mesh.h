#pragma once

#include <glm/glm.hpp> 
#include <glm/ext.hpp>
#include <string>
#include <vector>

#include "Vertex.h"

class Mesh {
public:

    // mesh data
	std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    GLuint texture_id{0}; // texture id=0  means no texture
    GLenum primitive_type = GL_POINT;
    
    // mesh material
    glm::vec4 diffuse_color{1.0f}; //white, non-transparent 
    
    // indirect (indexed) draw 
	Mesh(GLenum primitive_type, std::vector<vertex>& vertices, std::vector<GLuint>& indices, GLuint texture_id):
        primitive_type(primitive_type),
        vertices(vertices),
        indices(indices),
        texture_id(texture_id)
    {
        // TODO: create and initialize VAO, VBO, EBO and parameters
    };

    void Draw(ShaderProgram& shader) {
        // TODO: set uniform variables: color
        
        //set texture id etc...
        //if (texture_id > 0) {
        //    glActiveTexture(GL_TEXTURE0);
        //    glBindTexture(GL_TEXTURE_2D, texture_id);
        //    shader.setUniform("mytexture", 0);
        //}
        
        //TODO: draw mesh: bind vertex array object, draw all elements with selected primitive type, unbind vertex array object 
    }


	void clear(void) {
        vertices.clear();
        indices.clear();
        texture_id = 0;
        primitive_type = GL_POINT;
        
        // TODO: delete all allocations 
        glDeleteBuffers...
        glDeleteVertexArrays...
        
    };

private:
    // OpenGL buffer IDs
    // ID = 0 is reserved (i.e. uninitalized)
     unsigned int VAO{0}, VBO{0}, EBO{0};
};
  


