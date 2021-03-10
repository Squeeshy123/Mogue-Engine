// Press F5 to compile and run program

using System;
using Mogue.Base;
using Mogue.Test;
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
			Level currentLevel = new TestLevel();


            Glfw.Init();

			GlfwWindow* window = Glfw.CreateWindow(640, 480, "OpenGL Test", null, null);

			Glfw.MakeContextCurrent(window);
			GL.Init(=> Glfw.GetProcAddress);

			currentLevel.begin()

			while (!Glfw.WindowShouldClose(window)) {
				GL.glClearColor(1, 0, 1, 1);
				GL.glClear(GL.GL_COLOR_BUFFER_BIT);
				//currentLevel.tick();
				Glfw.PollEvents();
				Glfw.SwapBuffers(window);
			}

			Glfw.DestroyWindow(window);
        }
    }
}