
target_include_directories(${PROJECT_NAME} PUBLIC  ${BULLET_PHYSICS_SOURCE_DIR}/src)
 target_precompile_headers(${PROJECT_NAME} PUBLIC  $<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/headers.hpp>) # TODO remove the $<$<COMPILE_LANGUAGE:CXX>:...> once we do not build any c libraries anymore (it only stops a c precompiled header from being generated)
     target_link_libraries(${PROJECT_NAME} PUBLIC  BulletCollision LinearMath) # BulletDynamics

     target_link_libraries(${PROJECT_NAME} PRIVATE mathematics-module)
            target_sources(${PROJECT_NAME} PRIVATE physics.cpp)