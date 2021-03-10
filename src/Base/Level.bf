namespace Mogue.Base
{
	class Level
	{
		Object[] objs;
		void load(){

		}

		void tick(){
			for(int i = 0; i<objs.Count; i++){
				objs[i].tick();
			}
		}
	}
}
