cmake_minimum_required(VERSION 3.20)
project(dcimgui)

set(CMAKE_CXX_STANDARD 11)

set(GHPROXY https://gh-proxy.com)

set(ZIPS_DIR ${CMAKE_BINARY_DIR}/zips)
if(NOT EXISTS ${ZIPS_DIR})
    message(STATUS "Creating zips directory")
    file(MAKE_DIRECTORY ${ZIPS_DIR})
else()
    message(STATUS "zips directory already exists")
endif()

set(DEPENDS_DIR ${CMAKE_BINARY_DIR}/depends)
if(NOT EXISTS ${DEPENDS_DIR})
    message(STATUS "Creating zips directory")
    file(MAKE_DIRECTORY ${DEPENDS_DIR})
endif()


set(IMGUI_DIR ${DEPENDS_DIR}/imgui)
set(IMPLOT_DIR ${DEPENDS_DIR}/implot)
set(DCIMGUI_DIR ${DEPENDS_DIR}/dcimgui)

if(NOT EXISTS ${IMGUI_DIR}/imgui.cpp)
    include(FetchContent)
    FetchContent_Declare(
        imgui
        GIT_REPOSITORY ${GHPROXY}/https://github.com/ocornut/imgui.git
        GIT_TAG         v1.92.1-docking 
        SOURCE_DIR      ${IMGUI_DIR}
    )
    FetchContent_MakeAvailable(imgui)
endif()

if(NOT EXISTS ${IMPLOT_DIR}/implot.cpp)
    include(FetchContent)
    FetchContent_Declare(
        implot
        GIT_REPOSITORY ${GHPROXY}/https://github.com/epezent/implot.git
        GIT_TAG         master 
        SOURCE_DIR      ${IMPLOT_DIR}
    )
    FetchContent_MakeAvailable(implot)
endif()

if(NOT EXISTS ${DCIMGUI_DIR}/dcimgui_nodefaultargfunctions.cpp)

    file(DOWNLOAD
        ${GHPROXY}/https://github.com/dearimgui/dear_bindings/releases/download/DearBindings_v0.16_ImGui_v1.92.1-docking/DearBindings_v0.16_ImGui_v1.92.1-docking.zip
        ${ZIPS_DIR}/temp_dcimgui.zip
    )
    
    if(NOT EXISTS ${DCIMGUI_DIR})
        file(MAKE_DIRECTORY ${DCIMGUI_DIR})
    endif()

    execute_process(
        COMMAND ${CMAKE_COMMAND} -E tar xzf ${ZIPS_DIR}/temp_dcimgui.zip
        WORKING_DIRECTORY ${DCIMGUI_DIR}
        RESULT_VARIABLE result
    )
    
    if(NOT result EQUAL 0)
        message(FATAL_ERROR "Failed to extract dcimgui files")
    endif()
endif()

find_package(OpenGL REQUIRED)
find_package(Freetype REQUIRED)

include_directories(./)
include_directories(${IMGUI_DIR})
add_compile_definitions(IMGUI_USER_CONFIG=\"${CMAKE_CURRENT_SOURCE_DIR}/imconfig.h\")

add_library(imgui STATIC 
                ${IMGUI_DIR}/imgui.cpp
                ${IMGUI_DIR}/imgui_draw.cpp
                ${IMGUI_DIR}/imgui_demo.cpp
                ${IMGUI_DIR}/imgui_widgets.cpp
                ${IMGUI_DIR}/imgui_tables.cpp
                ${IMGUI_DIR}/misc/freetype/imgui_freetype.cpp)
target_link_libraries(imgui PRIVATE Freetype::Freetype)

add_library(dcimplot STATIC 
            ${IMPLOT_DIR}/implot.cpp
            ${IMPLOT_DIR}/implot_items.cpp
            dcimplot/dcimplot.cpp)

target_include_directories(dcimplot PUBLIC ${IMPLOT_DIR})
target_include_directories(dcimplot PUBLIC dcimplot)
target_link_libraries(dcimplot PRIVATE imgui)


add_library(dcimgui SHARED 
                ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
                ${DCIMGUI_DIR}/dcimgui_nodefaultargfunctions.cpp
                ${DCIMGUI_DIR}/dcimgui_nodefaultargfunctions_internal.cpp)

target_include_directories(dcimgui PUBLIC ${IMGUI_DIR})
target_include_directories(dcimgui PUBLIC ${IMGUI_DIR}/backends)
target_include_directories(dcimgui PUBLIC ${DCIMGUI_DIR})
target_link_libraries(dcimgui PRIVATE imgui)
target_link_libraries(dcimgui PRIVATE OpenGL::GL)
target_link_libraries(dcimgui PRIVATE
    -Wl,--whole-archive
    dcimplot
    -Wl,--no-whole-archive
)