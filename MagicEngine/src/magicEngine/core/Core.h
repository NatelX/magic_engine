#ifndef CORE_H
#define CORE_H

#include <memory>
#include <tuple>
#include "strings/CString.h"
#include "strings/CWString.h"
#include "collections/CMap.h"
#include "collections/CSet.h"
#include "collections/CArray.h"
#include "collections/CStaticArray.h"

#ifdef MAGICENGINE_PLATFORM_WINDOWS
#ifdef MAGICENGINE_BUILD_DLL
#define MAGICENGINE_API __declspec(dllexport)
#else
#define MAGICENGINE_API __declspec(dllimport)
#endif
#else
#error Magic Engine only supports Windows for now!
#endif

typedef unsigned char u_int8;
typedef char int8;
typedef unsigned short u_int16;
typedef short int16;
typedef unsigned int u_int32;
typedef int int32;
typedef unsigned long uint64;
typedef long int64;
typedef unsigned long long uint128;
typedef long long int128;
typedef long int64;
typedef float float32;
typedef double float64;

#define BIT(x) (1 << x)

template<typename T>
using CUniquePtr = std::unique_ptr<T>;
template<typename T, typename ... Args>
constexpr CUniquePtr<T> createUniquePtr(Args&& ... args)
{
	return std::make_unique<T>(std::forward<Args>(args)...);
}

template<typename T>
using CSharedPtr = std::shared_ptr<T>;
template<typename T, typename ... Args>
constexpr CSharedPtr<T> createSharedPtr(Args&& ... args)
{
	return std::make_shared<T>(std::forward<Args>(args)...);
}

#include <mutex>
typedef std::recursive_mutex CSynchronizedMutex;
#define synchronized(m) \
    for(std::unique_lock<CSynchronizedMutex> lk(m); lk; lk.unlock())

#endif
