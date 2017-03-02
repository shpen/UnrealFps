cmake_minimum_required (VERSION 2.6)
project (UE4)
set(CMAKE_CXX_STANDARD 11)

include("D:/Storage/Unreal/FpsCpp 4.15/Intermediate/ProjectFiles/IncludeDirectories.cmake")
include("D:/Storage/Unreal/FpsCpp 4.15/Intermediate/ProjectFiles/Definitions.cmake")
include("D:/Storage/Unreal/FpsCpp 4.15/Intermediate/ProjectFiles/FpsCpp.cmake")

# Custom target for FpsCpp project, Debug configuration
set(MONO_ROOT_PATH "D:/Epic Games/UnrealEngine/Engine/Binaries/DotNET")
set(BUILD cd "${MONO_ROOT_PATH}")

add_custom_target(FpsCpp-Mac-Debug ${BUILD} && UnrealBuildTool.exe FpsCpp Win64 Debug -project="D:/Storage/Unreal/FpsCpp 4.15/FpsCpp.uproject" -game)
add_custom_target(FpsCpp-Mac-Debug-clean ${BUILD} && UnrealBuildTool.exe FpsCpp Win64 Debug -project="D:/Storage/Unreal/FpsCpp 4.15/FpsCpp.uproject" -clean)


# Custom target for FpsCpp project, DebugGame configuration
add_custom_target(FpsCpp-Mac-DebugGame ${BUILD} && UnrealBuildTool.exe FpsCpp Win64 DebugGame -project="D:/Storage/Unreal/FpsCpp 4.15/FpsCpp.uproject" -game)
add_custom_target(FpsCpp-Mac-DebugGame-clean ${BUILD} && UnrealBuildTool.exe FpsCpp Win64 DebugGame -project="D:/Storage/Unreal/FpsCpp 4.15/FpsCpp.uproject" -clean)


# Custom target for FpsCpp project, Development configuration
add_custom_target(FpsCpp ${BUILD} && UnrealBuildTool.exe FpsCpp Win64 Development -project="D:/Storage/Unreal/FpsCpp 4.15/FpsCpp.uproject" -game)
add_custom_target(FpsCpp-clean ${BUILD} && UnrealBuildTool.exe FpsCpp Win64 Development -project="D:/Storage/Unreal/FpsCpp 4.15/FpsCpp.uproject" -clean)


# Custom target for FpsCpp project, Shipping configuration
add_custom_target(FpsCpp-Mac-Shipping ${BUILD} && UnrealBuildTool.exe FpsCpp Win64 Shipping -project="D:/Storage/Unreal/FpsCpp 4.15/FpsCpp.uproject" -game)
add_custom_target(FpsCpp-Mac-Shipping-clean ${BUILD} && UnrealBuildTool.exe FpsCpp Win64 Shipping -project="D:/Storage/Unreal/FpsCpp 4.15/FpsCpp.uproject" -clean)


# Custom target for FpsCpp project, Test configuration
add_custom_target(FpsCpp-Mac-Test ${BUILD} && UnrealBuildTool.exe FpsCpp Win64 Test -project="D:/Storage/Unreal/FpsCpp 4.15/FpsCpp.uproject" -game)
add_custom_target(FpsCpp-Mac-Test-clean ${BUILD} && UnrealBuildTool.exe FpsCpp Win64 Test -project="D:/Storage/Unreal/FpsCpp 4.15/FpsCpp.uproject" -clean)

include("D:/Storage/Unreal/FpsCpp 4.15/Intermediate/ProjectFiles/FpsCppEditor.cmake")

# Custom target for FpsCppEditor project, Debug configuration
set(MONO_ROOT_PATH "D:/Epic Games/UnrealEngine/Engine/Binaries/DotNET")
set(BUILD cd "${MONO_ROOT_PATH}")

add_custom_target(FpsCppEditor-Mac-Debug ${BUILD} && UnrealBuildTool.exe FpsCppEditor Win64 Debug -project="D:/Storage/Unreal/FpsCpp 4.15/FpsCpp.uproject" -game)
add_custom_target(FpsCppEditor-Mac-Debug-clean ${BUILD} && UnrealBuildTool.exe FpsCppEditor Win64 Debug -project="D:/Storage/Unreal/FpsCpp 4.15/FpsCpp.uproject" -clean)


# Custom target for FpsCppEditor project, DebugGame configuration
add_custom_target(FpsCppEditor-Mac-DebugGame ${BUILD} && UnrealBuildTool.exe FpsCppEditor Win64 DebugGame -project="D:/Storage/Unreal/FpsCpp 4.15/FpsCpp.uproject" -game)
add_custom_target(FpsCppEditor-Mac-DebugGame-clean ${BUILD} && UnrealBuildTool.exe FpsCppEditor Win64 DebugGame -project="D:/Storage/Unreal/FpsCpp 4.15/FpsCpp.uproject" -clean)


# Custom target for FpsCppEditor project, Development configuration
add_custom_target(FpsCppEditor ${BUILD} && UnrealBuildTool.exe FpsCppEditor Win64 Development -project="D:/Storage/Unreal/FpsCpp 4.15/FpsCpp.uproject" -game)
add_custom_target(FpsCppEditor-clean ${BUILD} && UnrealBuildTool.exe FpsCppEditor Win64 Development -project="D:/Storage/Unreal/FpsCpp 4.15/FpsCpp.uproject" -clean)


# Custom target for FpsCppEditor project, Shipping configuration
add_custom_target(FpsCppEditor-Mac-Shipping ${BUILD} && UnrealBuildTool.exe FpsCppEditor Win64 Shipping -project="D:/Storage/Unreal/FpsCpp 4.15/FpsCpp.uproject" -game)
add_custom_target(FpsCppEditor-Mac-Shipping-clean ${BUILD} && UnrealBuildTool.exe FpsCppEditor Win64 Shipping -project="D:/Storage/Unreal/FpsCpp 4.15/FpsCpp.uproject" -clean)


# Custom target for FpsCppEditor project, Test configuration
add_custom_target(FpsCppEditor-Mac-Test ${BUILD} && UnrealBuildTool.exe FpsCppEditor Win64 Test -project="D:/Storage/Unreal/FpsCpp 4.15/FpsCpp.uproject" -game)
add_custom_target(FpsCppEditor-Mac-Test-clean ${BUILD} && UnrealBuildTool.exe FpsCppEditor Win64 Test -project="D:/Storage/Unreal/FpsCpp 4.15/FpsCpp.uproject" -clean)


add_executable(FpsCppEditorFake ${FpsCppEditor_FILES})
