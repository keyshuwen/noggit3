// This file is part of Noggit3, licensed under GNU General Public License (version 3).

#include <noggit/Settings.h>
#include <noggit/Video.h>
#include <opengl/matrix.hpp>

Video video;

void Video::resize(int xres_, int yres_)
{
  _xres = xres_;
  _yres = yres_;
}

void Video::init(int xres_, int yres_)
{
  resize (xres_, yres_);
}
