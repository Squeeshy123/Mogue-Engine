using Mogue.Base;
using Mogue.Components;
using Mogue.AssetTypes;

namespace Mogue.Test
{
	class TestLevel: Level
	{
		Object[] objs = new Object[1] (
			new Object(
				new Component[1](
						new LogComp("This is a log component!")
						)
					)
				);

		public this(){

		}
		public ~this(){
			for (let o in objs){
				o.~Object();
			}
		}

		public new void begin(){
			for (let o in objs){
				o.begin();
			}
		}

		public new void tick(){
			for (let o in objs){
				o.tick();
			}
		}

	}
}
