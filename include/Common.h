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
   * @brief Устанавливает угол в радианах
   *
   * @param[in] angle Угол в радианах
   */
  void SetAngle(double angle);

  /**
   * @brief Устанавливает смещение
   *
   * @param[in] offset Смещение
   */
  void SetOffset(double offset);

  /**
   * @brief Устанавливает параметры прямой
   *
   * @param[in] angle  Угол в радианах
   * @param[in] offset Смещение
   */
  void SetParameters(double angle, double offset);

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
  /// Угол между прямой и осью Х
  double angle = 0;
  /// Отступ по оси Y
  double offset = 0;
};