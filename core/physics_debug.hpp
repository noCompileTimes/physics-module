#pragma once

#include "btBulletCollisionCommon.h"

#include "core/vec3.hpp"

#include <vector>
#include <print>

namespace core
{
    // TODO move the implementations into a cpp file
    class PhysicsDebug : public btIDebugDraw
    {
    public:
        void drawLine(const btVector3& from, const btVector3& to, const btVector3& color) override
        {
            vertices.emplace_back(from.x(), from.y(), from.z());
            vertices.emplace_back(color.x(), color.y(), color.z());

            vertices.emplace_back(to.x(), to.y(), to.z());
            vertices.emplace_back(color.x(), color.y(), color.z());
        }

        void drawContactPoint(const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifeTime, const btVector3& color) override
        {
            std::println("draw_contact_point");
        }

        void reportErrorWarning(const char* warningString) override
        {
            std::println("draw_error_warning");
        }

        void draw3dText(const btVector3& location, const char* textString) override
        {
            std::println("draw_text3d");
        }

        void setDebugMode(int debugMode) override // TODO maybe deleted also from bullet interface?
        {
        }

        int getDebugMode() const override
        {
            return DBG_DrawAabb | DBG_DrawWireframe;
        }

        virtual void clearLines()
        {
            vertices.clear();
        }

        virtual void flushLines()
        {
            std::println("flush_lines");
        }

        std::vector<vec3> vertices;
    };
}