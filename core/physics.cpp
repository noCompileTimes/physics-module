#include "physics.hpp"

namespace core
{
    auto Physics::init() -> void
    {
        _debug = std::make_unique<PhysicsDebug>();

        _configuration = std::make_unique<btDefaultCollisionConfiguration>();
           _dispatcher = std::make_unique<btCollisionDispatcher>(_configuration.get());
           _broadphase = std::make_unique<btDbvtBroadphase>();
                _world = std::make_unique<btCollisionWorld>(_dispatcher.get(), _broadphase.get(), _configuration.get());

        _world->setDebugDrawer(_debug.get());
    }

    auto Physics::release() const -> void
    {
    }

    auto Physics::raycast(const vec3& origin, const vec3& direction) const -> const btCollisionObject*
    {
        btVector3 bt_origin    { origin.x, origin.y, origin.z };
        btVector3 bt_direction { direction.x, direction.y, direction.z };

        btVector3 bt_end = bt_origin + bt_direction * 1000.0f;

        btCollisionWorld::ClosestRayResultCallback result(bt_origin, bt_end);

        _world->rayTest(bt_origin, bt_end, result);

        return result.m_collisionObject;
    }

    auto Physics::add_collision_object(btCollisionObject* collision_object) const -> void
    {
        _world->addCollisionObject(collision_object);
    }

    auto Physics::debug() const -> PhysicsDebug*
    {
        return _debug.get();
    }

    auto Physics::update() const -> void
    {
        _world->updateAabbs();
        _world->debugDrawWorld();
    }
}