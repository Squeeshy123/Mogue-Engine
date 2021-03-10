using Mogue.Base;
using Mogue.AssetTypes;

namespace Mogue.Components
{
	class RenderComp: Component
	{
		RenderAsset cRA;
		public this(RenderAsset RA){
			cRA = RA; // Assigns the given Render asset so this class is able to use it.
		}
		public new void tick(){
			cRA.tick();
		}

	}
}
