#pragma once

#include <string>
#include <stdio.h>
#include <memory>
#include <stdlib.h>
#include <limits>


#define callfunc(func, ...) func(__VA_ARGS__)



namespace Mogue {
	 // Logging functions
		inline void Error(std::string error) {
			std::string final = "Error: " + error + "\n";
			printf(final.c_str());
			exit(0);
		}
		inline void Log(std::string log) {
			std::string final = "Engine Log: " + log + "\n";
			printf(final.c_str());
		}
		inline void Warning(std::string warning) {
			std::string final = "Engine Warning: " + warning + "\n";
			printf(final.c_str());
		}
	
	template<typename T, typename... Args>
	std::unique_ptr<T> make_unique(Args&&... args)
	{
		return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
	}

	template<typename T>
	T min_of_num_type() {
		return numeric_limits<T>::min();
	}
	template<typename T>
	T max_of_num_type() {
		return numeric_limits<T>::max();
	}
}