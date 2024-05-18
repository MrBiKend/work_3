#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <format>
#include <cmath>

class Road {
private:
    int length;
    int lanes;

public:
    Road() : length(0), lanes(0) {}

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

    void setValues(int len, int ln) {
        length = len;
        lanes = ln;
    }

    int getLength() const {
        return length;
    }

    int getLanes() const {
        return lanes;
    }

    void printInfo() const {
        std::cout << std::format("Информация о дороге:\nДлина: {} м\nКоличество полос: {}\n", length, lanes);
    }

    bool isRoadSafe() const {
        return (length > 1000 && lanes >= 2);
    }

    float calculateTrafficDensity() const {
        if (length == 0 || lanes == 0) {
            return 0.0f;
        }
        return static_cast<float>(lanes) / length;
    }

    void updateLength(int newLength) {
        length = newLength;
    }

    void updateLanes(int newLanes) {
        lanes = newLanes;
    }

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

    // Новая функция: Расчет времени проезда
    float calculateTravelTime(float averageSpeed) const {
        if (averageSpeed <= 0) {
            std::cerr << "Средняя скорость должна быть положительной." << std::endl;
            return -1.0f;
        }
        return static_cast<float>(length) / averageSpeed;
    }
};

int main() {
    Road road;
    road.setValuesFromFile("input.txt");
    road.printInfo();

    if (road.isRoadSafe()) {
        std::cout << "Дорога безопасна для движения." << std::endl;
    } else {
        std::cout << "Дорога не безопасна для движения." << std::endl;
    }

    std::cout << "Плотность движения: " << road.calculateTrafficDensity() << " полос на метр" << std::endl;

    road.updateLength(1500);
    road.updateLanes(3);

    std::cout << "\nОбновленная информация о дороге:" << std::endl;
    road.printInfo();

    road.saveToFile("output.txt");

    // Добавим расчет времени проезда
    float averageSpeed;
    std::cout << "Введите среднюю скорость движения (км/ч): ";
    std::cin >> averageSpeed;

    float travelTime = road.calculateTravelTime(averageSpeed);
    if (travelTime >= 0) {
        std::cout << "Время проезда по дороге: " << travelTime << " часа(ов)" << std::endl;
    }

    return 0;
}
