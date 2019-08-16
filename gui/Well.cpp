//
// Copyright (C) Wojciech Jarosz <wjarosz@gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style license that can
// be found in the LICENSE.txt file.
//

#include "Well.h"
#include <nanogui/opengl.h>

using namespace nanogui;

Well::Well(Widget* parent, float radius, const Color& inner, const Color& outer)
    : Widget(parent), m_radius(radius), m_innerColor(inner), m_outerColor(outer)
{
}

void Well::draw(NVGcontext* ctx)
{
    NVGpaint paint = nvgBoxGradient(ctx, mPos.x() + 1, mPos.y() + 1,
                                    mSize.x() - 2, mSize.y() - 2, m_radius,
                                    m_radius + 1, m_innerColor, m_outerColor);
    nvgBeginPath(ctx);
    nvgRoundedRect(ctx, mPos.x(), mPos.y(), mSize.x(), mSize.y(), m_radius);
    nvgFillPaint(ctx, paint);
    nvgFill(ctx);

    Widget::draw(ctx);
}