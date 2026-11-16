# These checks cover the runnable skeleton, not the final acceptance scenarios.
add_test(NAME cli_help COMMAND vcslite --help)
set_tests_properties(cli_help PROPERTIES
    PASS_REGULAR_EXPRESSION "vcslite checkout <id>"
)

add_test(NAME cli_invalid_command
    COMMAND "${CMAKE_COMMAND}"
        "-DVCSLITE_EXECUTABLE=$<TARGET_FILE:vcslite>"
        -P "${CMAKE_CURRENT_SOURCE_DIR}/check_invalid_command.cmake"
)
