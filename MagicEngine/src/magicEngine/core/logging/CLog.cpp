#include "mepch.h"

#include "CLog.h"
#include <spdlog/sinks/stdout_color_sinks.h>
#include "spdlog/sinks/basic_file_sink.h"
#include <magicEngine/core/utils/static_block.h>

namespace MagicEngine {

	CSharedPtr<spdlog::logger> CLog::m_coreLogger;
	CSharedPtr<spdlog::logger> CLog::m_clientLogger;

	STATIC_BLOCK {
		CLog::init();
		return 0;
	}();

	void CLog::init() {
		spdlog::set_pattern("[%Y-%m-%d %H:%M:%S] [thread %t] %v");
		m_coreLogger = CSharedPtr<spdlog::logger>(
			spdlog::basic_logger_mt("MagicEngine", "logs/coreLogs.txt"));
		m_coreLogger->set_level(spdlog::level::trace);

		m_clientLogger = CSharedPtr<spdlog::logger>(
			spdlog::stdout_color_mt("App"));
		m_clientLogger->set_level(spdlog::level::trace);
	}

}
