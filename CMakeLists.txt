cmake_minimum_required(VERSION 3.14)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
project(Auto-Correct-ish LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(
        malena
        GIT_REPOSITORY https://github.com/daversmith/Malena.git
        GIT_TAG v0.2.4
)
FetchContent_MakeAvailable(malena)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/Word.h
        src/Word.cpp
        src/WordSort.h
        src/WordSort.cpp
        src/FileReader.h
        src/FileReader.cpp        

)
target_link_libraries(${PROJECT_NAME} PRIVATE Malena::Malena)