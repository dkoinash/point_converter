#include <Converter.h>

std::tuple<double, double>
Converter::CulculateP(const Point aPoint,
                      const Point bPoint,
                      const Point cPoint,
                      const Point dPoint,
                      const Point kPoint)
{

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
    lGK = lBC.GetParallelLine(kPoint);
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
  if (lDA.Intersection(lJK)) {
    Point fPoint = lDA.Intersection(lJK).value();

    /// Длина отрезка DA
    double distDA = Distance(aPoint, dPoint);
    /// Длина отрезка BF
    double distAF = Distance(aPoint, fPoint);

    ///! Значение отностительной координаты по оси Y

    if (distDA == 0.0)
      resultY = 0.0; // FixMe уточнить
    else
      resultY = distAF / distDA;

  } else {
    // FixMe Что если ошибка и все точки на одной прямой?
  }
#pragma endregion

  return std::make_tuple(resultX, resultY);
}