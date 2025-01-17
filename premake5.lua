workspace "RealEngine"
    configurations { "Debug", "Release" }
    platforms { "x64" }  -- Only supporting x64
    startproject "RealEngine"

project "RealEngine"
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"

    files { "src/**.cpp", "include/**.h" }

    includedirs { "include" }

    links { "opengl32", "glfw3", "imgui" }

    filter "configurations:Debug"
        symbols "On"
        optimize "Off"

    filter "configurations:Release"
        optimize "On"