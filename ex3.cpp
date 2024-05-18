#include <iostream>
#include <fstream>

// Класс дороги
class Road {
private:
  int length; // Длина дороги в метрах
  int lanes; // Количество полос на дороге

public:
  // Конструктор без параметров
  Road() {}

  // Метод для установки значений полей из файла
  void setValuesFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
      file >> length;
      file >> lanes;
      file.close();
    } else {
      std::cout << "Не удалось открыть файл: " << filename << std::endl;
    }
  }

  // Метод для получения длины дороги
  int getLength() {
    return length;
  }

  // Метод для получения количества полос на дороге
  int getLanes() {
    return lanes;
  }
};

int main() {
  // Создаем объект дороги
  Road road;

  // Устанавливаем значения полей из файла
  road.setValuesFromFile("input.txt");

  // Выводим информацию о дороге
  std::cout << "Длина дороги: " << road.getLength() << " метров" << std::endl;
  std::cout << "Количество полос: " << road.getLanes() << std::endl;

  return 0;
}
