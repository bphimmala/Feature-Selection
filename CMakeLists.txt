CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
project(Project2)

ADD_EXECUTABLE(run
    src/main.cpp
    src/printMenu.cpp
    src/node.cpp
    src/Search.cpp
)

# ADD_EXECUTABLE(nodeTest
#     src/test.cpp
#     src/node.cpp
# )