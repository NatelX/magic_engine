#ifndef CARRAY_H
#define CARRAY_H

#include <vector>

namespace MagicEngine {
	namespace Core {

		template <typename T>
		class CArray : public std::vector<T> {
		};

	}
}

#endif