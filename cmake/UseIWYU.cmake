# - UseIWYU: 使用 include-what-you-use。

find_program(IWYU_TOOL_PATH NAMES "iwyu_tool"
    DOC "The path of iwyu_tool."
)

if(NOT IWYU_TOOL_PATH)
    message(STATUS "Include-what-you-use is not found.")
else()
    add_custom_target(iwyu COMMENT "Running iwyu_tool on targets...")
endif()

function(iwyu target)
    if(NOT IWYU_TOOL_PATH)
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

    add_custom_target(iwyu-${target}
        COMMAND ${IWYU_TOOL_PATH} -p ${CMAKE_BINARY_DIR} ${full_srcs}
        COMMENT "Running iwyu_tool on ${target}..."
        VERBATIM
    )
    add_dependencies(iwyu iwyu-${target})
endfunction()
