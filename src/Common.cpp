#include <Common.h>

double
Distance(const Point& a, const Point& b)
{
  return std::sqrt(std::pow(b.x - a.x, 2) + std::pow(b.y - a.y, 2));
}

Line::Line(Point aPoint, Point bPoint)
{
  if (bPoint.x == aPoint.x) {
    isVertical = true;
    x = bPoint.x;
    return;
  }

  k = (bPoint.y - aPoint.y) / (bPoint.x - aPoint.x);
  b = bPoint.y - k * bPoint.x;
}

void
Line::SetK(double _k)
{
  k = _k;
  isVertical = false;
}
void
Line::SetB(double _b)
{
  b = _b;
  isVertical = false;
}
void
Line::SetParameters(double _k, double _b)
{
  SetK(_k);
  SetB(_b);
}
void
Line::SetVertical(double _x)
{
  isVertical = true;
  x = _x;
}

std::optional<Point>
Line::Intersection(const Line& other)
{
  if (k == other.k) return std::nullopt;
  if (this->isVertical && other.isVertical) return std::nullopt;
  if (this->isVertical) {
    return Point{ this->x, this->x * other.k + other.b };
  }
  if (other.isVertical) {
    return Point{ other.x, other.x * this->k + this->b };
  }

  Point point;
  point.x = (other.b - b) / (k - other.k);
  point.y = other.k * point.x + other.b;

  return point;
}

Line
Line::GetParallelLine(const Point& point)
{
  Line line;
  if (isVertical)
    line.SetVertical(point.x);
  else
    line.SetParameters(k, point.y - k * point.x);

  return line;
}