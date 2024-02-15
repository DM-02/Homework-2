//
//  main.cpp
//  Домашняя работа №2
//
//  Created by Дмитрий Сергеевич on 31.01.2024.
//

#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // Конструктор по умолчанию
    Person() : name(""), age(0) {}

    // Конструктор с параметрами
    Person(const std::string &name, int age) : name(name), age(age) {}

    // Конструктор копирования
    Person(const Person &person) : name(person.name), age(person.age) {}

    // Функция отображения информации о человеке
    void display() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

    // Деструктор
    ~Person() {
        // Нет необходимости в дополнительной очистке памяти, так как используются только стандартные типы данных
    }
};

class Apartment {
private:
    int number;
    Person *occupants;  // Динамический массив объектов Person
    int occupantsCount;

public:
    // Конструктор по умолчанию
    Apartment() : number(0), occupants(nullptr), occupantsCount(0) {}

    // Конструктор с параметрами
    Apartment(int number, int capacity) : number(number), occupants(new Person[capacity]), occupantsCount(0) {}

    // Добавление жильца в квартиру
    void addOccupant(const Person &person) {
        occupants[occupantsCount] = person;
        occupantsCount++;
    }

    // Отображение информации о жильцах квартиры
    void displayOccupants() {
        std::cout << "Apartment " << number << " Occupants:" << std::endl;
        for (int i = 0; i < occupantsCount; i++) {
            occupants[i].display();
        }
        std::cout << std::endl;
    }

    // Деструктор
    ~Apartment() {
        delete[] occupants;  // Освобождение памяти для массива occupants
    }
};

class House {
private:
    Apartment *apartments;  // Массив объектов Apartment
    int apartmentCount;

public:
    // Конструктор с параметрами
    House(int apartmentCount) : apartments(new Apartment[apartmentCount]), apartmentCount(apartmentCount) {}

    // Добавление квартиры в дом
    void addApartment(int index, const Apartment &apartment) {
        apartments[index] = apartment;
    }

    // Получение квартиры по индексу
    Apartment &getApartment(int index) {
        return apartments[index];
    }

    // Отображение информации о квартирах
    void displayApartments() {
        std::cout << "House Apartments:" << std::endl;
        for (int i = 0; i < apartmentCount; i++) {
            std::cout << "Apartment " << i + 1 << std::endl;
            apartments[i].displayOccupants();
        }
    }

    // Деструктор
    ~House() {
        delete[] apartments;  // Освобождение памяти для массива apartments
    }
};

int main() {
    // Создание объектов класса Person
    Person person1("Alice", 25);
    Person person2("Bob", 30);
    Person person3("Charlie", 28);
    Person person4("Diana", 27);

    // Создание объектов класса Apartment
    Apartment apartment1(101, 2);
    apartment1.addOccupant(person1);
    apartment1.addOccupant(person2);

    Apartment apartment2(102, 2);
    apartment2.addOccupant(person3);
    apartment2.addOccupant(person4);

    // Создание объекта класса House
    House house(2);
    house.addApartment(0, apartment1);
    house.addApartment(1, apartment2);

    // Отображение информации о квартирах и их жильцах
    house.displayApartments();

    return 0;
}
