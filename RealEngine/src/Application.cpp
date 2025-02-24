#include "Application.h"

namespace Real
{

    Real::Real() 
    {

        Log::Log log;
        log.info("Starting RealEngine...");

        Core::CoreApplication* coreApplication = new Core::CoreApplication;

        coreApplication->run();

        //Renderer::Renderer renderer(VBO::VBO VBO, EBO::EBO EBO, VAO::VAO VAO);

        delete coreApplication;

    }

    Real::~Real()
    {

        Log::Log log;
        log.info("Ending RealEngine...");

    }

}

int main() {

    Real::Real real;

    return 0;
}