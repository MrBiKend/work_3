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

    float calculateTravelTime(float averageSpeed) const {
        if (averageSpeed <= 0) {
            std::cerr << "Средняя скорость должна быть положительной." << std::endl;
            return -1.0f;
        }
        return static_cast<float>(length) / averageSpeed;
    }

    float calculateThroughput() const {
        if (lanes == 0) {
            std::cerr << "Количество полос не может быть нулевым." << std::endl;
            return -1.0f;
        }
        return lanes * 3600.0f / length;
    }

    void visualizeRoad() const {
        std::cout << "Визуализация дороги:\n";
        std::cout << std::string(length, '-') << "\n";
        for (int i = 0; i < lanes; ++i) {
            std::cout << std::string(length, '|') << "\n";
        }
        std::cout << std::endl;
    }

    std::string getRoadType() const {
        if (length > 5000 && lanes >= 4) {
            return "Автомагистраль";
        } else if (length < 5000 && lanes == 2) {
            return "Городская улица";
        } else {
            return "Обычная дорога";
        }
    }

    float calculateTravelTimeWithDelay(float averageSpeed, float delayTime) const {
        if (averageSpeed <= 0) {
            std::cerr << "Средняя скорость должна быть положительной." << std::endl;
            return -1.0f;
        }
        return static_cast<float>(length) / averageSpeed + delayTime;
    }

    void analyzeThroughput(std::string timeOfDay, float trafficDensity) const {
        std::cout << "Анализ пропускной способности дороги в " << timeOfDay << ":\n";
        if (trafficDensity <= 0.5) {
            std::cout << "Пропускная способность дороги высокая. Рекомендуется использовать эту дорогу.\n";
        } else if (trafficDensity > 0.5 && trafficDensity <= 0.8) {
            std::cout << "Пропускная способность дороги средняя. Рекомендуется осторожно выбирать эту дорогу.\n";
        } else {
            std::cout << "Пропускная способность дороги низкая. Рекомендуется по возможности избегать этой дороги.\n";
        }
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

float averageSpeed, delayTime;
std::string timeOfDay;
float trafficDensity;

std::cout << "Введите время суток (утро, день, вечер, ночь): ";
std::cin >> timeOfDay;
std::cout << "Введите плотность движения на дороге (от 0 до 1): ";
std::cin >> trafficDensity;

road.analyzeThroughput(timeOfDay, trafficDensity);

return 0;
}
