#include <Converter.h>

std::tuple<double, double>
Converter::CulculateP(const Point aPoint,
                      const Point bPoint,
                      const Point cPoint,
                      const Point dPoint,
                      const Point kPoint)
{
#if DEPRECATED
  /// Уравнение прямой через отрезок AB y=k*x+b
  double kAB = (bPoint.y - aPoint.y) / (bPoint.x - aPoint.x);
  double bAB = aPoint.y + kAB * aPoint.x;

  /// Уравнение прямой через отрезок BC y=k*x+b
  double kBC = (cPoint.y - bPoint.y) / (cPoint.x - bPoint.x);
  double bBC = cPoint.y + kBC * cPoint.x;

  /// Уравнение прямой через отрезок CD y=k*x+b
  double kCD = (dPoint.y - cPoint.y) / (dPoint.x - cPoint.x);
  double bCD = dPoint.y + kAB * dPoint.x;

  /// Уравнение прямой через отрезок DA y=k*x+b
  double kDA = (aPoint.y - dPoint.y) / (aPoint.x - dPoint.x);
  double bDA = aPoint.y + kDA * aPoint.x;

  /// Точка J пересечения прямых AB и CD
  Point jPoint;
  jPoint.x = (bCD - bAB) / (kAB - kCD);
  jPoint.y = kAB * jPoint.x + bAB;

  /// Уравнение прямой через отрезок JK y=k*x+b
  double kJK = (jPoint.y - kPoint.y) / (jPoint.x - kPoint.x);
  double bJK = jPoint.y + kJK * jPoint.x;

  /// Точка F пересечения прямых JK и BC
  Point fPoint;
  fPoint.x = (bBC - bJK) / (kJK - kBC);
  fPoint.y = kJK * jPoint.x + bJK;
#endif // DEPRECATED
  double resultX;
  double resultY;
  /// Уравнение прямой через отрезок AB y=k*x+b
  Line lAB(aPoint, bPoint);
  /// Уравнение прямой через отрезок BC y=k*x+b
  Line lBC(bPoint, cPoint);
  /// Уравнение прямой через отрезок CD y=k*x+b
  Line lCD(cPoint, dPoint);
  /// Уравнение прямой через отрезок DA y=k*x+b
  Line lDA(dPoint, aPoint);
#pragma region "Вычисление отностительной координаты по оси X"
  /// Точка G пересечения прямых BC и DA
  Line lGK;
  if (lBC.Intersection(lDA)) {
    Point gPoint = lBC.Intersection(lDA).value();
    /// Уравнение прямой через отрезок GK y=k*x+b
    lGK = Line(gPoint, kPoint);
  } else {
    // BC и DA параллельны => GK || BC
    lGK = Line(lBC.GetParallelLine(kPoint));
  }

  /// Точка H пересечения прямых GK и AB
  if (lAB.Intersection(lGK)) {
    Point hPoint = lAB.Intersection(lGK).value();

    /// Длина отрезка AB
    double distAB = Distance(aPoint, bPoint);
    /// Длина отрезка BH
    double distAH = Distance(aPoint, hPoint);

    ///! Значение отностительной координаты по оси Y

    if (distAB == 0.0)
      resultX = 0.0; // FixMe уточнить
    else
      resultX = distAH / distAB;

  } else {
    // FixMe Что если ошибка и все точки на одной прямой?
  }

#pragma endregion
#pragma region "Вычисление отностительной координаты по оси Y"
  /// Точка J пересечения прямых AB и CD
  Line lJK;
  if (lAB.Intersection(lCD)) {
    Point jPoint = lAB.Intersection(lCD).value();
    /// Уравнение прямой через отрезок JK y=k*x+b
    lJK = Line(jPoint, kPoint);
  } else {
    // AB и CD параллельны => JK || AB
    lJK = Line(lAB.GetParallelLine(kPoint));
  }

  /// Точка F пересечения прямых JK и BC
  if (lBC.Intersection(lJK)) {
    Point fPoint = lBC.Intersection(lJK).value();

    /// Длина отрезка BC
    double distBC = Distance(bPoint, cPoint);
    /// Длина отрезка BF
    double distBF = Distance(bPoint, fPoint);

    ///! Значение отностительной координаты по оси Y

    if (distBC == 0.0)
      resultY = 0.0; // FixMe уточнить
    else
      resultY = distBF / distBC;

  } else {
    // FixMe Что если ошибка и все точки на одной прямой?
  }
#pragma endregion

  return std::make_tuple(resultX, resultY);
}