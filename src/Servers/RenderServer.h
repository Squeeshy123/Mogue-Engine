#pragma once

class RenderServer {
    // Singleton
        public:					     
			static RenderServer* get_singleton();

            void initialize();
            void tick();
            
            ~RenderServer();
		private:
			static RenderServer* singleton;
			
            GLFWwindow* window;
        
            
            RenderServer();
}