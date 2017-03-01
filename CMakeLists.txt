cmake_minimum_required (VERSION 2.6)
project (UE4)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -std=gnu++11\n")

include("D:/Storage/Unreal/FpsCpp/Intermediate/ProjectFiles/IncludeDirectories.cmake")
include("D:/Storage/Unreal/FpsCpp/Intermediate/ProjectFiles/Definitions.cmake")
include("D:/Storage/Unreal/FpsCpp/Intermediate/ProjectFiles/UE4Editor.cmake")

# Custom target for UE4Editor project, DebugGame configuration
set(MONO_ROOT_PATH "C:/Program Files/Epic Games/UE_4.15.old/Engine/Binaries/DotNET")
set(BUILD cd "${MONO_ROOT_PATH}")

add_custom_target(UE4Editor-Mac-DebugGame ${BUILD} && UnrealBuildTool.exe UE4Editor Win64 DebugGame -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -game)
add_custom_target(UE4Editor-Mac-DebugGame-clean ${BUILD} && UnrealBuildTool.exe UE4Editor Win64 DebugGame -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -clean)


# Custom target for UE4Editor project, Development configuration
add_custom_target(UE4Editor ${BUILD} && UnrealBuildTool.exe UE4Editor Win64 Development -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -game)
add_custom_target(UE4Editor-clean ${BUILD} && UnrealBuildTool.exe UE4Editor Win64 Development -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -clean)


# Custom target for UE4Editor project, Shipping configuration
add_custom_target(UE4Editor-Mac-Shipping ${BUILD} && UnrealBuildTool.exe UE4Editor Win64 Shipping -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -game)
add_custom_target(UE4Editor-Mac-Shipping-clean ${BUILD} && UnrealBuildTool.exe UE4Editor Win64 Shipping -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -clean)

include("D:/Storage/Unreal/FpsCpp/Intermediate/ProjectFiles/UE4Game.cmake")

# Custom target for UE4Game project, DebugGame configuration
set(MONO_ROOT_PATH "C:/Program Files/Epic Games/UE_4.15.old/Engine/Binaries/DotNET")
set(BUILD cd "${MONO_ROOT_PATH}")

add_custom_target(UE4Game-Mac-DebugGame ${BUILD} && UnrealBuildTool.exe UE4Game Win64 DebugGame -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -game)
add_custom_target(UE4Game-Mac-DebugGame-clean ${BUILD} && UnrealBuildTool.exe UE4Game Win64 DebugGame -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -clean)


# Custom target for UE4Game project, Development configuration
add_custom_target(UE4Game ${BUILD} && UnrealBuildTool.exe UE4Game Win64 Development -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -game)
add_custom_target(UE4Game-clean ${BUILD} && UnrealBuildTool.exe UE4Game Win64 Development -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -clean)


# Custom target for UE4Game project, Shipping configuration
add_custom_target(UE4Game-Mac-Shipping ${BUILD} && UnrealBuildTool.exe UE4Game Win64 Shipping -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -game)
add_custom_target(UE4Game-Mac-Shipping-clean ${BUILD} && UnrealBuildTool.exe UE4Game Win64 Shipping -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -clean)

include("D:/Storage/Unreal/FpsCpp/Intermediate/ProjectFiles/FpsCpp.cmake")

# Custom target for FpsCpp project, DebugGame configuration
set(MONO_ROOT_PATH "C:/Program Files/Epic Games/UE_4.15.old/Engine/Binaries/DotNET")
set(BUILD cd "${MONO_ROOT_PATH}")

add_custom_target(FpsCpp-Mac-DebugGame ${BUILD} && UnrealBuildTool.exe FpsCpp Win64 DebugGame -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -game)
add_custom_target(FpsCpp-Mac-DebugGame-clean ${BUILD} && UnrealBuildTool.exe FpsCpp Win64 DebugGame -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -clean)


# Custom target for FpsCpp project, Development configuration
add_custom_target(FpsCpp ${BUILD} && UnrealBuildTool.exe FpsCpp Win64 Development -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -game)
add_custom_target(FpsCpp-clean ${BUILD} && UnrealBuildTool.exe FpsCpp Win64 Development -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -clean)


# Custom target for FpsCpp project, Shipping configuration
add_custom_target(FpsCpp-Mac-Shipping ${BUILD} && UnrealBuildTool.exe FpsCpp Win64 Shipping -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -game)
add_custom_target(FpsCpp-Mac-Shipping-clean ${BUILD} && UnrealBuildTool.exe FpsCpp Win64 Shipping -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -clean)

include("D:/Storage/Unreal/FpsCpp/Intermediate/ProjectFiles/FpsCppEditor.cmake")

# Custom target for FpsCppEditor project, DebugGame configuration
set(MONO_ROOT_PATH "C:/Program Files/Epic Games/UE_4.15.old/Engine/Binaries/DotNET")
set(BUILD cd "${MONO_ROOT_PATH}")

add_custom_target(FpsCppEditor-Mac-DebugGame ${BUILD} && UnrealBuildTool.exe FpsCppEditor Win64 DebugGame -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -game)
add_custom_target(FpsCppEditor-Mac-DebugGame-clean ${BUILD} && UnrealBuildTool.exe FpsCppEditor Win64 DebugGame -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -clean)


# Custom target for FpsCppEditor project, Development configuration
add_custom_target(FpsCppEditor ${BUILD} && "C:/Program Files/Epic Games/UE_4.15.old/Engine/Binaries/DotNET/UnrealBuildTool.exe" FpsCppEditor Win64 Development -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -game)
add_custom_target(FpsCppEditor-clean ${BUILD} && UnrealBuildTool.exe FpsCppEditor Win64 Development -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -clean)


# Custom target for FpsCppEditor project, Shipping configuration
add_custom_target(FpsCppEditor-Mac-Shipping ${BUILD} && UnrealBuildTool.exe FpsCppEditor Win64 Shipping -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -game)
add_custom_target(FpsCppEditor-Mac-Shipping-clean ${BUILD} && UnrealBuildTool.exe FpsCppEditor Win64 Shipping -project="D:/Storage/Unreal/FpsCpp/FpsCpp.uproject" -clean)


add_executable(FpsCppEditorFake ${FpsCppEditor_FILES})
