// Copyright 2022 Citra Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "tas/touch_widget.h"

#include <algorithm>
#include <cmath>

#include <QMouseEvent>
#include <QPainter>

#include "common/common_types.h"

constexpr int PADDING = 1;

TouchWidget::TouchWidget(QWidget* parent) : QWidget(parent)
{
  setMouseTracking(false);
  setToolTip(tr("Left click to set the Touch value.\n"
                "Right click to re-center it."));

  // If the widget gets too small, it will get deformed.
  setMinimumSize(QSize(64, 48));
}

void TouchWidget::SetX(u16 x)
{
  m_x = std::min(touch_max_x, x);

  update();
}

void TouchWidget::SetY(u16 y)
{
  m_y = std::min(touch_max_y, y);

  update();
}

void TouchWidget::paintEvent(QPaintEvent* event)
{
  QPainter painter(this);

  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setRenderHint(QPainter::SmoothPixmapTransform, true);

  const int w = width() - PADDING * 2;
  const int h = height() - PADDING * 2;

  painter.setBrush(Qt::white);
  painter.drawRect(PADDING, PADDING, w, h);

  painter.drawLine(PADDING, PADDING + h / 2, PADDING + w, PADDING + h / 2);
  painter.drawLine(PADDING + w / 2, PADDING, PADDING + w / 2, PADDING + h);

  // convert from value space to widget space
  u16 x = PADDING + (w - (m_x * w) / touch_max_x);
  u16 y = PADDING + ((m_y * h) / touch_max_y);

  painter.drawLine(PADDING + w / 2, PADDING + h / 2, x, y);

  painter.setBrush(Qt::blue);
  int wh_avg = (w + h) / 2;
  int radius = wh_avg / 30;
  painter.drawEllipse(x - radius, y - radius, radius * 2, radius * 2);
}

void TouchWidget::mousePressEvent(QMouseEvent* event)
{
  handleMouseEvent(event);
  m_ignore_movement = event->button() == Qt::RightButton;
}

void TouchWidget::mouseMoveEvent(QMouseEvent* event)
{
  if (!m_ignore_movement)
    handleMouseEvent(event);
}

void TouchWidget::handleMouseEvent(QMouseEvent* event)
{
  if (event->button() == Qt::RightButton)
  {
    m_x = std::round(touch_max_x / 2.);
    m_y = std::round(touch_max_y / 2.);
  }
  else
  {
    // convert from widget space to value space
    int new_x = touch_max_x - (event->x() * touch_max_x) / width();
    int new_y = (event->y() * touch_max_y) / height();

    m_x = std::max(0, std::min(static_cast<int>(touch_max_x), new_x));
    m_y = std::max(0, std::min(static_cast<int>(touch_max_y), new_y));
  }

  emit ChangedX(m_x);
  emit ChangedY(m_y);
  update();
}