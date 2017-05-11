#.rst
# CheckSymbolsExist
# -----------------
#
# 检查指定的符号（函数、变量或宏）是否存在。
#
# CHECK_SYMBOLS_EXIST(SYMBOLS symbols... FILES files...)
#
include(CheckSymbolExists)
include(CMakeParseArguments)
include(VariableNameForSymbol)

function(CHECK_SYMBOLS_EXIST)
    set(multiValueArgs SYMBOLS FILES)
    cmake_parse_arguments(CSE "" "" "${multiValueArgs}" ${ARGN})
    foreach(_sym ${CSE_SYMBOLS})
        VARNAME_FOR_SYMBOL(${_sym} _var)
        CHECK_SYMBOL_EXISTS(${_sym} "${CSE_FILES}" ${_var})

        if(${_var})
            set(${_var} ${${_var}} PARENT_SCOPE)
        endif()
    endforeach()
endfunction()
