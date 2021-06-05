#pragma once

#include <string>
#include <stdio.h>
#include <memory>
#include <stdlib.h>

namespace Mogue {
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
}