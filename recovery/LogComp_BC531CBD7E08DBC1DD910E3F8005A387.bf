using Mogue.Base;
using System;
namespace Mogue.Components
{
	class LogComp: Component
	{
		public String clog = "Log Component";
		public this(String log = "This is a Log Component"){
			clog = log;
		}
		public new void begin(){
			Console.WriteLine("");
		}
	}
}
