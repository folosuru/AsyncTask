cmake_minimum_required(VERSION 3.21)
set(project_name_ AsyncTask)

project(${project_name_})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Release)

file(GLOB_RECURSE SRC_FILES_DIR
    ${${project_name_}_SOURCE_DIR}/src/*.c
    ${${project_name_}_SOURCE_DIR}/src/*.cpp
    ${${project_name_}_SOURCE_DIR}/src/*.cpp
    ${${project_name_}_SOURCE_DIR}/src/*.h
)

add_library(${project_name_} SHARED ${SRC_FILES_DIR})

target_include_directories(${project_name_}
		PRIVATE ${CMAKE_SOURCE_DIR}/SDK/include
		)

target_link_directories(${project_name_}
		PRIVATE ${CMAKE_SOURCE_DIR}/SDK/lib
		)

target_compile_definitions(${project_name_}
		PRIVATE -D"NDEBUG"
		PRIVATE -D"NOMINMAX"
		PRIVATE -D"TEMPLATE_EXPORTS"
		PRIVATE -D"UNICODE"
		PRIVATE -D"WIN32_LEAN_AND_MEAN"
		PRIVATE -D"_AMD64_"
		PRIVATE -D"_CRT_SECURE_NO_WARNINGS"
		PRIVATE -D"_UNICODE"
		PRIVATE -D"_USRDLL"
		PRIVATE -D"_WINDLL"
		PRIVATE -D"_WINDOWS"
		)

target_compile_options(${project_name_}
		PRIVATE /diagnostics:column
		PRIVATE /EHsc
		PRIVATE /FC
		PRIVATE /GL
		PRIVATE /MD
		PRIVATE /nologo
		PRIVATE /permissive-
		PRIVATE /sdl
		PRIVATE /utf-8
		PRIVATE /Zc:inline
		PRIVATE /Zi
		)

target_link_options(${project_name_}
		PRIVATE /DEBUG
		PRIVATE /DELAYLOAD:"bedrock_server.dll"
		PRIVATE /DLL
		PRIVATE /IGNORE:4199
		PRIVATE /INCREMENTAL:NO
		PRIVATE /LTCG:INCREMENTAL
		PRIVATE /MANIFESTUAC:NO
		PRIVATE /MACHINE:X64
		PRIVATE /NOLOGO
		PRIVATE /OPT:ICF
		PRIVATE /OPT:REF
		PRIVATE /SUBSYSTEM:CONSOLE
		)
target_link_libraries(${CMAKE_PROJECT_NAME} 
	"${CMAKE_SOURCE_DIR}/SDK/lib/LiteLoader.lib"
	"${CMAKE_SOURCE_DIR}/SDK/lib/bedrock_server_api.lib"
	"${CMAKE_SOURCE_DIR}/SDK/lib/bedrock_server_var.lib"
	"${CMAKE_SOURCE_DIR}/SDK/lib/SymDBHelper.lib"
)
target_include_directories(${project_name_} PRIVATE
		${${project_name_}_SOURCE_DIR}/include/
)

add_custom_command(TARGET ${CMAKE_PROJECT_NAME} PRE_BUILD
    COMMAND cmd /c ${PROJECT_SOURCE_DIR}/prepare_libraries.cmd ${PROJECT_SOURCE_DIR}
)
