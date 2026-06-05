add_library(Engine
    GameEngine.cpp
    GameEngine.h
    AGameObject.cpp
    AGameObject.h
)

target_include_directories(Engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/Thirdparty/SDL3/include
)

target_link_libraries(Engine
    PUBLIC
        "${CMAKE_SOURCE_DIR}/Thirdparty/SDL3/lib/x64/SDL3.lib"
)