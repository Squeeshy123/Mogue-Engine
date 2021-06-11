#include "OpenGLRenderDevice.h"
#include "Servers/ServerManager.h"

#include "Core.h"

#include "Libs/imgui.h"
#include "Libs/imgui_impl_glfw.h"
#include "Libs/imgui_impl_opengl3.h"

GLFWwindow* current_window;

static int compile_shader(unsigned int type, const std::string& source) {
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int status;
    glGetShaderiv(id, GL_COMPILE_STATUS, &status);

    if (status = GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));

        glGetShaderInfoLog(id, length, &length, message);

        std::string smessage(message);

        Mogue::Warning((std::string)(type == GL_VERTEX_SHADER ? "Vertex" : "Fragment") + " Shader compilation failed! Error message: " + smessage);
        glDeleteShader(id);
        return 0;
    }

    return id;
}
static unsigned int create_shader(const std::string& vertex_shader, const std::string& fragment_shader) {
    unsigned int program = glCreateProgram();
    unsigned int vs = compile_shader(GL_VERTEX_SHADER, vertex_shader);
    unsigned int fs = compile_shader(GL_FRAGMENT_SHADER, fragment_shader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

unsigned int buffer;

std::shared_ptr<RenderObject> OpenGLRenderDevice::add_render_object(RenderObject* robj){
    std::shared_ptr<RenderObject> render_object(robj);
    render_objects.push_back(render_object);

    return render_object;
}


float verts[8] = {
    -0.5f, -0.5f,
     0.0f,  0.5f,
     0.5f, -0.5f
};

bool OpenGLRenderDevice::load_resources() {
    if (glewInit() != GLEW_OK) {
        Mogue::Error("Failed to initialize GLEW");
    } else {
        Mogue::Log("Initialized GLEW");
    }
    
    
    std::string vshader = 
    "#version 330 core\n"
    ""
    "layout(location = 0) in vec4 pos;\n"
    "void main() {\n"
    "gl_Position = pos;\n"
    "}";

    std::string fshader = 
    "#version 330 core\n"
    "layout(location = 0) out vec4 col;\n"
    "void main() {\n"
    "col = vec4(0.0, 1.0, 0.0, 1.0)\n"
    "}";

    
    unsigned int shader = create_shader(vshader, fshader);
    glUseProgram(shader);

	return true;
}

void OpenGLRenderDevice::render() {
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    for(auto& render_object : render_objects) {
        float* vert = &render_object->verticies[0];

        glGenBuffers(1, &buffer);
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glBufferData(GL_ARRAY_BUFFER, render_object->verticies.size() * sizeof(float), vert, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * render_object->render_method, 0);
        
        glDrawArrays(GL_TRIANGLES, 0, 12*3);
    }

    
    
    
}

void OpenGLRenderDevice::end_render(){
    
}

void OpenGLRenderDevice::unload_resources() {

}

OpenGLRenderDevice::OpenGLRenderDevice() {
    current_window = Mogue::ServerManager::get_window_server()->get_window();
}

OpenGLRenderDevice::~OpenGLRenderDevice() {
    unload_resources();
}