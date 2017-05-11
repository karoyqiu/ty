# - UseAnalyze: 使用 clang-check 对代码进行静态分析。

find_program(CLANG_CHECK_PATH NAMES "clang-check"
    DOC "The path of clang-check."
)

if(NOT CLANG_CHECK_PATH)
    message(STATUS "clang-check is not found.")
else()
    add_custom_target(analyze COMMENT "Running clang-check on targets...")
endif()

function(analyze target)
    if(NOT CLANG_CHECK_PATH)
        return()
    endif()

    get_target_property(srcs ${target} SOURCES)

    if(srcs STREQUAL "NOTFOUND")
        return()
    endif()

    set(full_srcs)

    foreach(src ${srcs})
        get_source_file_property(loc ${src} LOCATION)
        if(loc MATCHES ".+\\.cpp")
            list(APPEND full_srcs ${loc})
        endif()
    endforeach()

    add_custom_target(analyze-${target}
        COMMAND ${CLANG_CHECK_PATH} -p ${CMAKE_BINARY_DIR} ${full_srcs}
        COMMENT "Analyzing ${target}..."
        VERBATIM
    )
    add_dependencies(analyze analyze-${target})
endfunction()
