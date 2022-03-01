project "Client"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"**.h",
		"**.hpp",
		"**.cpp",
		"**.c",
		"%{wks.location}/PNet/**.h",
		"%{wks.location}/PNet/**.hpp",
		"%{wks.location}/PNet/**.cpp",
		"%{wks.location}/PNet/**.c",
	}

	includedirs
	{
		"%{wks.location}"
	}

	defines 
	{ 
		"_CRT_SECURE_NO_WARNINGS"
	}

	filter "system:windows"
		systemversion "latest"

		links
		{
			"ws2_32.lib"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"
		
	filter "configurations:Release"
		runtime "Release"
		optimize "on"
