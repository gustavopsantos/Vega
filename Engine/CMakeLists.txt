add_library(Engine
    GameEngine.cpp
    GameEngine.h
    TimeManager.cpp
    TimeManager.h
    InputManager.cpp
    InputManager.h
    GameObject.cpp
    GameObject.h
    MapUtils.h
    Vector2.h
    Vector2.cpp
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