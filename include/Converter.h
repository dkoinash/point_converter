
#include <Common.h>
#include <cstdio>
#include <tuple>

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

  /**
   * @brief
   *
   * @param[in] aPoint Точка верхняя левая с условной координатой (0, 0)
   * @param[in] bPoint Точка верхняя правая с условной координатой (1, 0)
   * @param[in] cPoint Точка нижняя правая с условной координатой (1, 1)
   * @param[in] dPoint Точка нижняя левая с условной координатой (0, 1)
   * @param[in] kPoint Точка внутри четырёхугольника ABCD
   * @return Возвращает приведённые координаты точки K
   */
  static std::tuple<double, double> CulculateP(const Point aPoint,
                                               const Point bPoint,
                                               const Point cPoint,
                                               const Point dPoint,
                                               const Point kPoint);

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