#include <vector>
#include <functional>
#include <iostream>

#include "candle.h"
// #include "tests.h"

//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;


// тесты для метода body_contains
// среднее значение
bool test_candle_body_contains1()
{
  Candle candle{ 0.0, 3.0, 3.0, 3.0 };

  return candle.body_contains(1.0);
}

// минимальное значение
bool test_candle_body_contains2()
{
  Candle candle{ 0.0, 3.0, 3.0, 3.0 };
  return candle.body_contains(0.0);
}

// максимальное значение
bool test_candle_body_contains3()
{
  Candle candle{ 0.0, 3.0, 3.0, 3.0 };
  return candle.body_contains(3.0);
}

//тесты для метода contains
// среднее значение
bool test_candle_contains1()
{
  Candle candle{ 0.0, 3.0, 1.0, 3.0 };
  return candle.contains(2.0);
}
// минимальное значение
bool test_candle_contains2()
{
  Candle candle{ 0.0, 3.0, 1.0, 3.0 };
  return candle.contains(1.0);
}

// максимальное значение
bool test_candle_contains3()
{
  Candle candle{ 0.0, 3.0, 1.0, 3.0 };
  return candle.contains(3.0);
}



void initTests()
{
  tests.push_back(test_candle_body_contains1);
  tests.push_back(test_candle_body_contains2);
  tests.push_back(test_candle_body_contains3);
  tests.push_back(test_candle_contains1);
  tests.push_back(test_candle_contains2);
  tests.push_back(test_candle_contains3);
}

int launchTests()
{
  int total = 0;
  int passed = 0;

  for (const auto& test : tests)
  {
    std::cout << "test #" << (total + 1);
    if (test())
    {
      passed += 1;
      std::cout << " passed\n";
    }
    else
    {
      std::cout << " failed\n";
    }
    total += 1;
  }

  std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

  //0 = success
  return total - passed;
}

int main()
{
  initTests();
  return launchTests();
}
