
target_include_directories(${PROJECT_NAME} PUBLIC  ${BULLET_PHYSICS_SOURCE_DIR}/src)
     target_link_libraries(${PROJECT_NAME} PUBLIC  BulletCollision LinearMath) # BulletDynamics

     target_link_libraries(${PROJECT_NAME} PRIVATE mathematics-module)
            target_sources(${PROJECT_NAME} PRIVATE physics.cpp)