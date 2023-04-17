#ifndef CSET_H
#define CSET_H

#include <unordered_set>

namespace MagicEngine {
	namespace Core {

		template <typename T>
		class CSet : public std::unordered_set<T> {
		};

	}
}

#endif