// Press F5 to compile and run program

using System;
using glfw_beef;
using opengl_beef;

namespace Mogue
{
    class Mogue
    {
		static void display(){

		}


        static void Main()
        {
            Glfw.Init();

			GlfwWindow* window = Glfw.CreateWindow(640, 480, "OpenGL Test", null, null);

			Glfw.MakeContextCurrent(window);
			GL.Init(=> Glfw.GetProcAddress);

			while (!Glfw.WindowShouldClose(window)) {
				GL.glClearColor(1, 0, 1, 1);
				GL.glClear(GL.GL_COLOR_BUFFER_BIT);
				display();
				Glfw.PollEvents();
				Glfw.SwapBuffers(window);
			}

			Glfw.DestroyWindow(window);
        }
    }
}