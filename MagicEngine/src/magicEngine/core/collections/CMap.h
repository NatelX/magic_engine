#ifndef CMAP_H
#define CMAP_H

#include <unordered_map>

namespace MagicEngine {
	namespace Core {

		template <typename T, typename K>
		class CMap : public std::unordered_map<T, K> {
		};

	}
}

#endif