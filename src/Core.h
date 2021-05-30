#pragma once


#define init_singleton(classname, args) private:\
			static classname* singleton;\
		public:\
			static classname* get_singleton(args) {\
				if (!singleton)\
					singleton = new classname(args);\
				return singleton;\
			}\

			classname(args);\