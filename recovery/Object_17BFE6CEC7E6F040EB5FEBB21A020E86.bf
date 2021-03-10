namespace Mogue.Base
{
	class Object
	{
		Component[] comps;

		public this(Component[] components){
			comps = components;
		}
		public ~this(){
			for(let c in comps){
				delete c;
			}
		}
		public void begin(){
			for(let c in comps){
				c.begin();
			}
		}
		public void tick(){
			for(let c in comps){
				c.tick();
			}
		}
	}
}
