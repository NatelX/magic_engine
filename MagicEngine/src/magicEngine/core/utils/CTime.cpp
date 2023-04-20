#include "mepch.h"

#include "CTime.h"
#include <chrono>

namespace MagicEngine {

	int128 CTime::currentTimeMillis() {
		std::chrono::milliseconds ms =
			std::chrono::duration_cast<std::chrono::milliseconds>(
				std::chrono::system_clock::now().time_since_epoch());
		return ms.count();
	}

	int128 CTime::currentTimeNano() {
		std::chrono::nanoseconds ns =
			std::chrono::duration_cast<std::chrono::nanoseconds>(
				std::chrono::system_clock::now().time_since_epoch());
		return ns.count();
	}

}
