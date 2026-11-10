#pragma once

#include "physics_debug.hpp"

#include <memory>

namespace core
{
    class Physics
    {
    public:
        auto    init()       -> void;
        auto  update() const -> void;
        auto release() const -> void;

        auto raycast(const vec3& origin, const vec3& direction) const -> const btCollisionObject*;

        auto add_collision_object(btCollisionObject* collision_object) const -> void;

        auto debug() const -> PhysicsDebug*;

    private:
        std::unique_ptr<btCollisionConfiguration> _configuration;
        std::unique_ptr<btBroadphaseInterface>    _broadphase;

        std::unique_ptr<btDispatcher> _dispatcher;
        std::unique_ptr<btCollisionWorld>  _world;

        std::unique_ptr<PhysicsDebug> _debug;
    };
}

// TODO - enable at some point if necesary (BT_USE_SSE_IN_API) or (BT_USE_SSE)