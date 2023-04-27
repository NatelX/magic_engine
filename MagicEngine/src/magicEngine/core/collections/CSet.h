#ifndef CSET_H
#define CSET_H

#include <magicEngine/core/Core.h>
#include <unordered_set>

namespace MagicEngine {

	template<typename T>
	using CSet = std::unordered_set<T>;

}

#endif