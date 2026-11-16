add_library(vcslite_core STATIC
    repository.cpp
    metadata_store.cpp
    file_store.cpp
)
target_include_directories(vcslite_core PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
)
target_compile_features(vcslite_core PUBLIC cxx_std_17)

add_library(vcslite_cli STATIC cli.cpp)
target_link_libraries(vcslite_cli PUBLIC vcslite_core)

add_executable(vcslite main.cpp)
target_link_libraries(vcslite PRIVATE vcslite_cli)

foreach(target IN ITEMS vcslite_core vcslite_cli vcslite)
    if(MSVC)
        target_compile_options(${target} PRIVATE /W4 /utf-8 /permissive-)
    else()
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endforeach()

install(TARGETS vcslite RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}")
