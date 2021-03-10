using System;
using opengl_beef;

namespace Mogue.AssetTypes
{
	class RenderAsset
	{
		public this(){
			float[] vertices = new float[12] (
			     0.5f,  0.5f, 0.0f,  // top right
			     0.5f, -0.5f, 0.0f,  // bottom right
			    -0.5f, -0.5f, 0.0f,  // bottom left
			    -0.5f,  0.5f, 0.0f   // top left 
			);
			int[] indices = new int[6] ( 
			    0, 1, 3,  // first Triangle
			    1, 2, 3   // second Triangle
			);
			uint32 VBO = ?, VAO = ?, EBO = ?;
			GL.glGenVertexArrays(1, &VAO);
			GL.glGenBuffers(1, &VBO);
			GL.glGenBuffers(1, &EBO);
			// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
			GL.glBindVertexArray(VAO);

			GL.glBindBuffer(GL.GL_ARRAY_BUFFER, VBO);
			GL.glBufferData(GL.GL_ARRAY_BUFFER, vertices.Count, vertices, GL.GL_STATIC_DRAW);

			GL.glBindBuffer(GL.GL_ELEMENT_ARRAY_BUFFER, EBO);
			GL.glBufferData(GL.GL_ELEMENT_ARRAY_BUFFER, indices.Count, indices, GL.GL_STATIC_DRAW);

			GL.glVertexAttribPointer(0, 3, GL.GL_FLOAT, GL.GL_FALSE, 3 * sizeof(float), (void*)0);
			GL.glEnableVertexAttribArray(0);

			// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
			GL.glBindBuffer(GL.GL_ARRAY_BUFFER, 0); 

			// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
			//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

			// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
			// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
			GL.glBindVertexArray(0);
		}
		void tick(){
			
			
		}
	}
}
