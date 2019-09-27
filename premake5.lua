workspace "Vin"
	architecture "x64"
	configurations
	{
		"Debug",
		"Release",
		"Distribution"
	}

outputdir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}"

project "Vin"
	location "Vin"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin_int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"VIN_PLATFORM_WINDOWS",
			"VIN_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines
		{
			"VIN_CONFIGURATION_DEBUG"
		}

		symbols "On"

	filter "configurations:Release"
		defines
		{
			"VIN_CONFIGURATION_RELEASE"
		}

		optimize "On"
	
	filter "configurations:Distribution"
		defines
		{
			"VIN_CONFIGURATION_DIST"
		}

		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin_int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Vin/vendor/spdlog/include",
		"Vin/src"
	}

	links
	{
		"Vin"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"VIN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines
		{
			"VIN_CONFIGURATION_DEBUG"
		}

		symbols "On"

	filter "configurations:Release"
		defines
		{
			"VIN_CONFIGURATION_RELEASE"
		}

		optimize "On"
	
	filter "configurations:Distribution"
		defines
		{
			"VIN_CONFIGURATION_DIST"
		}

		optimize "On"