namespace Mogue {
	class InputServer
	{
		public:    
			static InputServer* get_singleton();

		private:
			static InputServer *singleton;

			InputServer();

	};
}
