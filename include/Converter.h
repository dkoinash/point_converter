
#include <cstdio>

/**
 * @brief Структура точки
 */
struct Point
{
  double x;
  double y;
};

/**
 * @brief Класс преобразователь
 */
class Converter
{
public:
  /**
   * @brief
   *
   * @param aPoint     Точка верхняя левая с условной координатой (0, 0)
   * @param bPoint     Точка верхняя правая с условной координатой (1, 0)
   * @param cPoint     Точка нижняя правая с условной координатой (1, 1)
   * @param dPoint     Точка нижняя левая с условной координатой (0, 1)
   * @param kPoint     Точка внутри четырёхугольника ABCD
   * @param k_sh  Точка с прведёнными координатаим из точки K
   */
  void CulculateP(const Point aPoint,
                  const Point bPoint,
                  const Point cPoint,
                  const Point dPoint,
                  const Point kPoint,
                  Point& k_sh)
  {
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
  }

private:
  /**
   * @brief Construct aPoint new Converter object
   */
  Converter() = default;

  /**
   * @brief Destroy the Converter object
   */
  ~Converter() = default;
};