#*! ***********************************************************************************************
#
# \file        CMakeLists.txt
# \brief       Project ty 主 CMakeLists。
#
# \version     0.1
# \date        2017/5/10
#
# \author      仇道林 <karoyqiu@gmail.com>
# \copyright   © 2017 仇道林。
#
#*************************************************************************************************/
cmake_minimum_required(VERSION 3.6)

# 设置全局变量
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_C_VISIBILITY_PRESET "hidden")
set(CMAKE_CXX_VISIBILITY_PRESET "hidden")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_POLICY_DEFAULT_CMP0054 NEW)
set(CMAKE_POLICY_DEFAULT_CMP0063 NEW)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_USER_MAKE_RULES_OVERRIDE_C    ${CMAKE_SOURCE_DIR}/cmake/CFlagOverrides.cmake)
set(CMAKE_USER_MAKE_RULES_OVERRIDE_CXX  ${CMAKE_SOURCE_DIR}/cmake/CXXFlagOverrides.cmake)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)
set(CMAKE_SKIP_BUILD_RPATH OFF)
set(CMAKE_BUILD_WITH_INSTALL_RPATH OFF)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "Enable/disable output of compile commands during generation." FORCE)

set(CMAKE_BUILD_TYPE Debug CACHE STRING
    "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel.")
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS Debug Release RelWithDebInfo MinSizeRel)

# Project ty
project(ty)

# 判断目标架构
include(TargetArch)
include(UseLsbRelease)
lsb_release(ID distro_id RELEASE distro_release)
target_architecture(TY_TARGET_ARCH)
message(STATUS "Target distribution: ${distro_id} ${distro_release} ${TY_TARGET_ARCH}")

# 检查编译器警告选项
include(WarningFlags)
check_warning_flags(TY_WARNING_FLAGS)

# 编译第三方库
set_directory_properties(PROPERTIES
    INTERPROCEDURAL_OPTIMIZAITON_RELEASE ON
    INTERPROCEDURAL_OPTIMIZAITON_RELWITHDEBINFO ON
)
set(CMAKE_THREAD_PREFER_PTHREAD ON)
find_package(Threads REQUIRED)
find_library(LIBRT rt)
if(NOT LIBRT)
    unset(LIBRT)
endif()

include(AddSubdirectories)
add_subdirectories("third_party")

# 源代码
#include(cotire)
include(UseIWYU)
include(UseAnalyze)
set_directory_properties(src test PROPERTIES
    COTIRE_ADD_UNITY_BUILD FALSE
    COTIRE_PREFIX_HEADER_IGNORE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src"
    COTIRE_PREFIX_HEADER_INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/third_party"
)
#add_subdirectory("src")

# 打包，提前设置供安装库使用。
set(CPACK_PACKAGE_NAME "ty")
set(CPACK_PACKAGE_VENDOR "karoyqiu")
set(CPACK_PACKAGE_VERSION_MAJOR 1)
set(CPACK_PACKAGE_VERSION_MINOR 0)
set(CPACK_PACKAGE_VERSION_PATCH 0)
set(CPACK_SYSTEM_NAME "${distro_id}-${distro_release}-${TY_TARGET_ARCH}")

# 打包
set(CPACK_PACKAGE_CHECKSUM SHA256)
set(CPACK_SET_DESTDIR ON)
set(CPACK_VERBATIM_VARIABLES ON)
set(CPACK_STRIP_FILES ON)
set(CPACK_GENERATOR "TGZ")
set(CPACK_SOURCE_STRIP_FILES ON)
set(CPACK_SOURCE_GENERATOR ${CPACK_GENERATOR})
set(CPACK_SOURCE_IGNORE_FILES "/\.svn/;/\.git/")
include(CPack)
