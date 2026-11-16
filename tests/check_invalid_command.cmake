execute_process(
    COMMAND "${VCSLITE_EXECUTABLE}" unknown-command
    RESULT_VARIABLE result
    OUTPUT_VARIABLE output
    ERROR_VARIABLE errors
)

if(NOT "${result}" STREQUAL "2")
    message(FATAL_ERROR "Expected exit code 2, got ${result}: ${errors}")
endif()
if(NOT errors MATCHES "Unknown command")
    message(FATAL_ERROR "Expected an explanation on stderr, got: ${errors}")
endif()
if(NOT output STREQUAL "")
    message(FATAL_ERROR "An invalid command unexpectedly wrote to stdout: ${output}")
endif()
