workspace "MagicEngineCpp"
	startproject "MagicEditor"
	architecture "x64"
	
	configurations {
		"Debug",
		"Release"
	}
	
outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "MagicEngine"
	location "MagicEngine"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")
	
	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs {
		"%{prj.name}/vendor/spdlog/include"
	}
	
	cppdialect "C++17"
	
	filter "system:windows"
		staticruntime "On"
		systemversion "10.0"
		defines {
			"MAGICENGINE_PLATFORM_WINDOWS",
			"MAGICENGINE_BUILD_DLL",
		}
		
		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "MagicEditor")
		}
		
	filter "configurations:Debug"
		defines "MAGICENGINE_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "MAGICENGINE_RELEASE"
		symbols "On"
		
project "MagicEditor"
	location "MagicEditor"
	kind "WindowedApp"
	language "C++"
	
	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")
	
	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	wxWidgetsDirectory = "%{prj.name}/vendor/wxWidgets/"
	
	includedirs {
		wxWidgetsDirectory .. "include/msvc",
		wxWidgetsDirectory .. "include/"
	}
	
	libdirs {
		wxWidgetsDirectory .. "lib/vc_x64_lib"
	}
	
	cppdialect "C++17"
	
	filter "system:windows"
		staticruntime "Off"
		systemversion "10.0"
		defines {
			"MAGICENGINE_PLATFORM_WINDOWS",
			"MAGICENGINE_API"
		}
		
	filter "configurations:Debug"
		defines "MAGICEDITOR_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "MAGICEDITOR_RELEASE"
		symbols "On"