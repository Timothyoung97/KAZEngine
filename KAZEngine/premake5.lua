workspace "KAZEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}}"

-- include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "KAZEngine/vendor/GLFW/include"

include "KAZEngine/vendor/GLFW"

project "KAZEngine"
    location "KAZEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "kepch.h"
    pchsource "KAZEngine/src/kepch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect = "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "KE_PLATFORM_WINDOWS",
            "KE_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "KE_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "KE_RELEASE"
        optimize "On"
        
    filter "configurations:Dist"
        defines "KE_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "KAZEngine/src",
        "KAZEngine/vendor/spdlog/include"
    }

    links
    {
        "KAZEngine"
    }

    filter "system:windows"
        cppdialect = "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "KE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "KE_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "KE_RELEASE"
        optimize "On"
        
    filter "configurations:Dist"
        defines "KE_DIST"
        optimize "On"