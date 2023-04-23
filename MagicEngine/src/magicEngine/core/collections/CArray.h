#ifndef CARRAY_H
#define CARRAY_H

#include <magicEngine/core/Core.h>
#include <vector>

namespace MagicEngine {

	template <typename T>
	class MAGICENGINE_API CArray : public std::vector<T> {
	};

}

#endif