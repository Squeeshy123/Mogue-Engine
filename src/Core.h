#pragma once

#include <string>
#include <stdio.h>

#define init_singleton_h(classname, ...)             \
		public:									     \
			static classname* get_singleton();		 \
												     \
		private:								     \
			static classname *singleton;			 \
			classname(__VA_ARGS__)					 \

#define init_singleton_cpp(classname, ...)  		 \
			classname* classname::get_singleton()	 \
			{	     					    		 \
				return singleton;		   			 \
			}										 \
			classname::classname(__VA_ARGS__)		 \
			{										 \
				singleton = this;					 \

namespace Mogue {
	inline void Error(std::string error) {
		std::string final = "Error: " + error + "\n";
		printf(final.c_str());
	}
}