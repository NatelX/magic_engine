#ifndef CSTATICARRAY_H
#define CSTATICARRAY_H

//#include <array>

namespace MagicEngine {
	namespace Core {

		template <typename T, size_t size>
		class CStaticArray : public std::array<T, size> {
		};

	}
}

#endif