using System;
using opengl_beef;
namespace Mogue.AssetTypes
{
	class TriangleRenderAsset: RenderAsset
	{
		float[] g_vertex_buffer_data = new float[9] (
			-1.0f, -1.0f, 0.0f,
   			1.0f, -1.0f, 0.0f,
   			0.0f,  1.0f, 0.0f
			);
		uint32 vertexbuffer = 0;

		public this(){
			uint32 VertexArrayID = ?;
			GL.glGenVertexArrays(1, &VertexArrayID);
			GL.glBindVertexArray(VertexArrayID);

			// This will identify our vertex buffer
			
			// Generate 1 buffer, put the resulting identifier in vertexbuffer
			GL.glGenBuffers(1, &vertexbuffer);
			// The following commands will talk about our 'vertexbuffer' buffer
			GL.glBindBuffer(GL.GL_ARRAY_BUFFER, vertexbuffer);
			// Give our vertices to OpenGL.
			GL.glBufferData(GL.GL_ARRAY_BUFFER, g_vertex_buffer_data.Count, null, GL.GL_STATIC_DRAW);
			
		}
		void tick(){
			// 1st attribute buffer : vertices
			GL.glEnableVertexAttribArray(0);
			GL.glBindBuffer(GL.GL_ARRAY_BUFFER, vertexbuffer);
			GL.glVertexAttribPointer(
			   0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			   3,                  // size
			   GL.GL_FLOAT,           // type
			   GL.GL_FALSE,           // normalized?
			   0,                  // stride
			   (void*)0            // array buffer offset
			);
			// Draw the triangle !
			GL.glDrawArrays(GL.GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
			GL.glDisableVertexAttribArray(0);
			
		}
	}
}
