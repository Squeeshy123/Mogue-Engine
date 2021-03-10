namespace Mogue.Base
{
	class Object
	{
		Component[] comps;

		public this(Component[] components){
			comps = components;
		}
		public void begin(){
			for(int i = 0; i<comps.Count; i++){
				comps[i].begin();
			}
		}
		public void tick(){
			for(int i = 0; i<comps.Count; i++){
				comps[i].tick();
			}
		}
	}
}
