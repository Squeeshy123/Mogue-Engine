namespace Mogue.Base
{
	class Object
	{
		Component[] comps;
		public void tick(){
			for(int i = 0; i<comps.Count; i++){
				comps[i].tick();
			}
		}
	}
}
