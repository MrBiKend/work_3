#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <format>

// Класс дороги
class Road {
private:
    int length; // Длина дороги в метрах
    int lanes; // Количество полос на дороге

public:
    // Конструктор без параметров
    Road() : length(0), lanes(0) {}

    // Метод для установки значений полей из файла
    void setValuesFromFile(const std::string& filename) {
        std::ifstream file(filename);
        std::string line;

        if (file.is_open()) {
            if (std::getline(file, line)) {
                std::stringstream ss(line);
                ss >> length;
            }
            if (std::getline(file, line)) {
                std::stringstream ss(line);
                ss >> lanes;
            }
            file.close();
        } else {
            std::cout << "Не удалось открыть файл: " << filename << std::endl;
        }
    }

    // Метод для установки значений длины и количества полос
    void setValues(int len, int ln) {
        length = len;
        lanes = ln;
    }

    // Метод для получения длины дороги
    int getLength() const {
        return length;
    }

    // Метод для получения количества полос на дороге
    int getLanes() const {
        return lanes;
    }

    // Метод для вывода информации о дороге
    void printInfo() const {
        std::cout << std::format("Информация о дороге:\nДлина: {} м\nКоличество полос: {}\n", length, lanes);
    }

    // Метод для проверки безопасности дороги
    bool isRoadSafe() const {
        return (length > 1000 && lanes >= 2); // Пример условия для безопасности дороги
    }

    // Метод для расчета плотности движения на дороге
    float calculateTrafficDensity() const {
        if (length == 0 || lanes == 0) {
            return 0.0f;
        }
        return static_cast<float>(lanes) / length; // Простой расчет плотности
    }

    // Метод для обновления длины дороги
    void updateLength(int newLength) {
        length = newLength;
    }

    // Метод для обновления количества полос на дороге
    void updateLanes(int newLanes) {
        lanes = newLanes;
    }

    // Метод для сохранения информации о дороге в файл
    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << length << std::endl;
            file << lanes << std::endl;
            file.close();
            std::cout << "Информация о дороге успешно сохранена в файл: " << filename << std::endl;
        } else {
            std::cout << "Не удалось открыть файл для сохранения: " << filename << std::endl;
        }
    }
};

int main() {
    // Создаем объект дороги
    Road road;

    // Устанавливаем значения полей из файла
    road.setValuesFromFile("input.txt");

    // Выводим информацию о дороге
    road.printInfo();

    // Проверяем безопасность дороги
    if (road.isRoadSafe()) {
        std::cout << "Дорога безопасна для движения." << std::endl;
    } else {
        std::cout << "Дорога не безопасна для движения." << std::endl;
    }

    // Рассчитываем плотность движения
    std::cout << "Плотность движения: " << road.calculateTrafficDensity() << " полос на метр" << std::endl;

    // Обновляем информацию о дороге
    road.updateLength(1500);
    road.updateLanes(3);

    // Выводим обновленную информацию о дороге
    std::cout << "\nОбновленная информация о дороге:" << std::endl;
    road.printInfo();

    // Сохраняем информацию о дороге в файл
    road.saveToFile("output.txt");

    return 0;
}
