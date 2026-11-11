#pragma once

#include "core/vec3.hpp"

namespace core
{
    // TODO move the implementations into a cpp file
    class PhysicsDebug final : public btIDebugDraw
    {
    public:
        auto drawLine(const btVector3& from, const btVector3& to, const btVector3& color) -> void override
        {
            vertices.emplace_back(from.x(), from.y(), from.z());
            vertices.emplace_back(color.x(), color.y(), color.z());

            vertices.emplace_back(to.x(), to.y(), to.z());
            vertices.emplace_back(color.x(), color.y(), color.z());
        }

        auto drawContactPoint(const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifeTime,
                              const btVector3& color) -> void override
        {
            std::println("draw_contact_point");
        }

        auto draw3dText(const btVector3& location, const char* textString) -> void override
        {
            std::println("draw_text3d");
        }

        auto getDebugMode() const -> int override
        {
            return DBG_DrawAabb | DBG_DrawWireframe;
        }

        auto clearLines() -> void override
        {
            vertices.clear();
        }

        std::vector<vec3> vertices;
    };
}

// TODO - add also the elements for the geometry, to avoid duplicate data
// TODO - be sure that you check if a vertex is already and use the right index/element when exsists - avoiding duplicates