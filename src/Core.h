#pragma once


#define init_singleton(classname, ...) private:\
			static classname* singleton;\
		public:\
			static classname* get_singleton(...) {\
				if (!singleton)\
					singleton = new classname(...);\
				return singleton;\
			}\
			classname(...);\
