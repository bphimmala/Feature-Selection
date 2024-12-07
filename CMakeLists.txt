CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
project(Project2)

ADD_EXECUTABLE(run
    src/main.cpp
    src/printMenu.cpp
    src/node.cpp
    src/Search.cpp
    src/validator.cpp
    src/readDataset.cpp
)

ADD_EXECUTABLE(runPartTwo
    src/mainPartTwo.cpp
    src/validator.cpp
    src/readDataset.cpp
)