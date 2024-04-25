#ifndef GRAPHICS_CORE_GFX_CONTEXT_HPP_
#define GRAPHICS_CORE_GFX_CONTEXT_HPP_

#include "commons.hpp"
#include "Viewport.hpp"
#include "../../window/Window.h"
#include "../../typedefs.h"

class Batch2D;
class Framebuffer;

class GfxContext {
    const GfxContext* parent;
    Viewport viewport;
    Batch2D* const g2d;
    Framebuffer* fbo = nullptr;
    bool depthMask = true;
    bool depthTest = false;
    bool cullFace = false;
    BlendMode blendMode = BlendMode::normal;
    int scissorsCount = 0;
public:
    GfxContext(const GfxContext* parent, const Viewport& viewport, Batch2D* g2d);
    ~GfxContext();
    
    Batch2D* getBatch2D() const;
    const Viewport& getViewport() const;
    GfxContext sub() const;

    void setViewport(const Viewport& viewport);
    void setFramebuffer(Framebuffer* fbo);
    void setDepthMask(bool flag);
    void setDepthTest(bool flag);
    void setCullFace(bool flag);
    void setBlendMode(BlendMode mode);
    void setScissors(glm::vec4 area);
};

#endif // GRAPHICS_CORE_GFX_CONTEXT_HPP_
