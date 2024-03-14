// get any info from GL
// https://docs.gl/gl3/glGet
glGet*


// use following symbolic constants to get info
GL_VENDOR
GL_RENDERER
GL_VERSION
GL_SHADING_LANGUAGE_VERSION

GL_CONTEXT_PROFILE_MASK, GL_CONTEXT_CORE_PROFILE_BIT


//get integer
GLint myint;
glGetIntegerv(GL_SOME_PARAMETER_NAME, &myint);

std::cout << "Value is:" << myint << '\n';

//get string
const char* mystring = (const char*)glGetString(GL_SOME_PARAMETER_NAME);
 
std::cout << "Value is:" << mystring << '\n';
