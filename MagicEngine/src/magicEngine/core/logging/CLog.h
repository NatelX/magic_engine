#ifndef CLOG_H
#define CLOG_H

#include <spdlog/spdlog.h>
#include <magicEngine/core/Core.h>

namespace MagicEngine {

	class MAGICENGINE_API CLog {
	public:
		static void init();

		inline static CSharedPtr<spdlog::logger> getCoreLogger() {
			return m_coreLogger;
		}

		inline static CSharedPtr<spdlog::logger> getClientLogger() {
			return m_clientLogger;
		}

	private:
		static CSharedPtr<spdlog::logger> m_coreLogger;
		static CSharedPtr<spdlog::logger> m_clientLogger;
	};

}

//Core logging macros
#define MAGICENGINE_CORE_ERROR(...) ::MagicEngine::CLog::getCoreLogger()->error(__VA_ARGS__)
#define MAGICENGINE_CORE_WARN(...) ::MagicEngine::CLog::getCoreLogger()->warn(__VA_ARGS__)
#define MAGICENGINE_CORE_INFO(...) ::MagicEngine::CLog::getCoreLogger()->info(__VA_ARGS__)
#define MAGICENGINE_CORE_TRACE(...) ::MagicEngine::CLog::getCoreLogger()->trace(__VA_ARGS__)
#define MAGICENGINE_CORE_CRITICAL(...) ::MagicEngine::CLog::getCoreLogger()->critical(__VA_ARGS__)

//Client logging macros
#define MAGICENGINE_ERROR(...) ::MagicEngine::CLog::getClientLogger()->error(__VA_ARGS__)
#define MAGICENGINE_WARN(...) ::MagicEngine::CLog::getClientLogger()->warn(__VA_ARGS__)
#define MAGICENGINE_INFO(...) ::MagicEngine::CLog::getClientLogger()->info(__VA_ARGS__)
#define MAGICENGINE_TRACE(...) ::MagicEngine::CLog::getClientLogger()->trace(__VA_ARGS__)
#define MAGICENGINE_CRITICAL(...) ::MagicEngine::CLog::getClientLogger()->critical(__VA_ARGS__)

#endif

