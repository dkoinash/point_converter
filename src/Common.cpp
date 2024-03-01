#include <Common.h>

double
Distance(const Point& a, const Point& b)
{
  return std::sqrt(std::pow(b.x - a.x, 2) + std::pow(b.y - a.y, 2));
}

Line::Line(Point aPoint, Point bPoint)
{
  if (bPoint.x == aPoint.x) {
    angle = PI / 2;
    return;
  }

  angle = atan((bPoint.y - aPoint.y) / (bPoint.x - aPoint.x));
  offset = bPoint.y - tan(angle) * bPoint.x;
}

void
Line::SetAngle(double angle)
{
  angle = angle;
}
void
Line::SetOffset(double offset)
{
  offset = offset;
}
void
Line::SetParameters(double angle, double offset)
{
  angle = angle;
  offset = offset;
}

std::optional<Point>
Line::Intersection(const Line& other)
{
  if (angle == other.angle) return std::nullopt;

  Point point;
  point.x = (other.offset - offset) / (tan(angle) - tan(other.angle));
  point.y = tan(other.angle) * point.x + other.offset;

  return point;
}

Line
Line::GetParallelLine(const Point& point)
{
  Line line;
  if (angle == PI / 2)
    line.SetAngle(angle);
  else
    line.SetParameters(angle, point.y - tan(angle) * point.x);
  return line;
}