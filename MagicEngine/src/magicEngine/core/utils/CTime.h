#ifndef CTIME_H
#define CTIME_H

#include <magicEngine/core/Core.h>

namespace MagicEngine {

    class MAGICENGINE_API CTime {
    public:
        static int128 currentTimeMillis();
        static int128 currentTimeNano();
    };

}

#endif