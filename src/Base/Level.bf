namespace Mogue.Base
{
	class Level
	{
		Object[] objs;
		public void begin(){

		}

		public void tick(){
			for(int i = 0; i<objs.Count; i++){
				objs[i].tick();
			}
		}
	}
}
