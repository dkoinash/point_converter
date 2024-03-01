#pragma once
#include <cmath>
#include <optional>

const double PI = acos(-1.0);

/**
 * @brief Структура точки
 */
struct Point
{
  double x;
  double y;
};

/**
 * @brief Получает длину отрезка между точками
 *
 * @param[in] a Точка A
 * @param[in] b Точка B
 * @return Возвращает длину отрезка между точками
 */
double
Distance(const Point& a, const Point& b);

/**
 * @brief Класс линии
 */
class Line
{
public:
  /**
   * @brief Конструктор
   */
  Line() = default;

  /**
   * @brief Конструктор по двум точкам
   *
   * @param[in] a Точка А
   * @param[in] b Точка B
   */
  Line(Point a, Point b);
  /**
   * @brief Деструктор
   */
  ~Line() = default;

  /**
   * @brief Устанавливает угловой коэффициент
   *
   * @param[in] k Угловой коэффициент
   */
  void SetK(double k);

  /**
   * @brief Устанавливает ординату точки пересечения прямой с осью Y
   *
   * @param[in] b Ордината точки пересечения прямой с осью Y
   */
  void SetB(double b);

  /**
   * @brief Устанавливает параметры прямой
   *
   * @param[in] k  Угловой коэффициент
   * @param[in] b  Ордината точки пересечения прямой с осью Y
   */
  void SetParameters(double k, double b);

/**
 * @brief Устанавливает прямую вертикально
 * 
 * @param[in] x Координата оси точки пересечения прямой и оси абсцисс
 */
  void SetVertical(double x);

/**
 * @brief Получает точку пересечения прямых если она есть
 * 
 * @param[in] other Пересекаемая прямая
 * @return Возвращает точку пересечения прямых если она есть
 */
  std::optional<Point> Intersection(const Line& other);

  /**
   * @brief Получает прямую параллельную this проходящую через точку point
   *
   * @param[in] point Точка через которую нужно построить параллельную прямую
   * @return Возвращает прямую, параллельную this проходящую через точку point
   */
  Line GetParallelLine(const Point& point);

private:
  /// Признак  вертикальной прямой
  bool isVertical = false;
  /// Значение абсциссы для вертикальной прямой
  double x = 0.;
  /// Угловой коэффициент
  double k = 0.;
  /// Ордината точки пересечения прямой с осью Y
  double b = 0.;
};