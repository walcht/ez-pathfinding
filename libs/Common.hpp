/*
 *  This file encapsulates commonly used elements (structs, classes, enums, etc...)
 *  throughout this project. Thus this file is included in a lot of headers and source
 *  code files.
 *
 */
#ifndef COMMON_H
#define COMMON_H

struct Vector2D
{
  int x;
  int y;

  Vector2D(int pX, int pY) : x{pX}, y{pY} {}
  Vector2D() {}
  bool operator== (const Vector2D& other)
  {
    if (x != other.x) return false;
    if (y != other.y) return false;
    return true;
  }
};
#endif
