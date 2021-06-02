#pragma once

#include <string>
#include <stdio.h>

namespace Mogue {
	inline void Error(std::string error) {
		std::string final = "Error: " + error + "\n";
		printf(final.c_str());
	}
}