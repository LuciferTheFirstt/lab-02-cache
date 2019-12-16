# Лабораторная работа №2

[![Build Status](https://travis-ci.org/LuciferTheFirstt/lab-02-cache.svg?branch=master)](https://travis-ci.org/LuciferTheFirstt/lab-02-cache)

> Кэш - промежуточный буфер с быстрым доступом, содержащий информацию, которая может быть запрошена с наибольшей вероятностью. Доступ к данным в кэше осуществляется быстрее, чем выборка исходных данных из более медленной памяти или удаленного источника, однако её объём существенно ограничен по сравнению с хранилищем исходных данных.

### Задача

Для каждого из вариантов проходов (*прямой*, *обратный* и *случайный*) целочисленного массива 
провести исследование зависимости времени от размера.

Каждое исследование включает в себя серию эксперементов c определенными размерами.

Количество экспериментов в серии определяется следующим образом:

```cpp
1/2 * cache_sizes['1'] < 2^x < 2^(x+1) < ... < 2^(x+n) < 3/2 * cache_sizes['max']
```

### Пример

В примере ниже показано, что для процессора с тремя уровнями кэша (`2mb`, `4mb`, `8mb`)
необходимо провести серию из 5 эксперементов.

```cpp
cache_size['1'] = 2 mb;
cache_size['2'] = 4 mb;
cache_size['3'] = 8 mb;

// 1mb < 2mb < 4mb < 8mb < 12mb
```

### Эксперимент

Каждый эксперемент состоит из 3 шагов:

```cpp
1. Создание буфера
2. Прогревание кэша
// <-- время начала эксперемнта
3. Циклический проход (1000 итераций)
// <-- время окончание эксперемента
```

#### Шаг 1

Инициализация буфера может происходит, как с помощью чтения данных из файла в выделенную область памяти,
так и с помощью случайного заполнения с использованием генератора случайных чисел.

#### Шаг 2

Данный шаг необходимо выполнить для получения репрезентативных данных, т.к. кэш-память еще не заполнена.

#### Шаг 3

Для получения времени обхода от размера массива процедуру прохода необходимо многократно повторить (порядка 1000 раз).

### Результаты

Ниже представлен формат и пример отчета:

```yaml
investigation:                                       |  investigaion:
  travel_variant: <вариант_прохода>                  |    travel_order: "direction"
  experiments:                                       |    experiments:
  - experiment:                                      |    - experiment:
      number:                                        |        number: 1
      input_data:                                    |        input_data:
        buffer_size: <размер_буфера>                 |          buffer_size: "1mb"
      results:                                       |        results:
        duration: <продолжительность>                |          duration: "1ns"
  - experiment:                                      |    - experiment:
      number: <номер_эксперимента>                   |        number: 2
      input_data:                                    |        input_data:
        buffer_size: <размер_буфера>                 |          buffer_size: "2mb"
      results:                                       |        results:
        duration: <продолжительность>                |          duration: "2ns"
                                                     |
investigation:                                       |  investigation:
...                                                  |  ...
```

⚠️ В отчет также необходимо добавить общий график с результатами всех исследований. ⚠️

[Прямой проход](http://yotx.ru/#!1/3_qwiC/YP9rYODg4N9I4bwv7b/dL9/sH@w7yel1vY3tnZgvIPdjZ2zU97B7sbZ1g7vYHdj62AHxDvY3dg5AMF4W7sboIPLU97O7gZs63KHB9rd2NrZgcF4p7v7O/skGnZj55TxeLrFeNy6vNjd39rfBwU=)

[Обратный проход](http://yotx.ru/#!1/3_qwiC/YP9rYODg4N9I4bwv7b/dL9/sH@w7yel1vY3tnZgvIPdjZ2zU97B7sbZ1g7vYHdj62AHxDvY3dg5AMF4W7sboIPLU97O7gZs63KHd7a7sbWzA4PxYLv7O/skGnZj63KL8bh1cMl43LnY2d3f2t8HBQ==)

[Случайный проход](http://yotx.ru/#!1/3_qwiC/YP9rYODg4N9I4bwv7b/dL9/sH@w7yel1vY3tnZgvJ3djZ2zU97Z7sbZ1g5va2t3Y@tgB8TbAe1u7ByAYLyznd0N0MHlKW9rC7S7Adu63OHtwBC7G1s7OzAYD3R5ubu/s0@iYTe2YAjG4wHj8WB3f2t/HwM=)

[Сравнение графиков](http://yotx.ru/#!1/3_qwiC/YP9rYODg4N9I4bwv7b/dL9/sH@w7yel1vY3tnZgvIPdjZ2zU97B7sbZ1g7vYHdj62AHxDvY3dg5AMF4W7sboIPLU97O7gZs63KHB9rd2NrZgcF4p7v7O/skGnZjC4ZgPB4wHg9297f29ze2dmC8g92NnbNT3sHuxtnWDu9gd2PrYAfEO9jd2DkAwXhbuxugg8tT3s7uBmzrcod3truxtbMDg/Fgu/s7@yQadmPnlPF4usV43Lq82N3f2t/f2NqB8XZ2N3bOTnlnuxtnWzu8ra3dja2DHRBvB7S7sXMAgvHOdnY3QAeXp7ytLdDuBmzrcoe3A0Psbmzt7MBgPNDl5e7@zj6Jht3YOWU8nm4xHrcuL3b3t/b3AQc=)

### Таблица ###
| Номер  | Размер буффера | Прямой(мс)| Обратный (мс) | Случайный (мс) |
|--------|----------------|-----------|---------------|----------------|
| 1      | 128            | 0         | 0             | 2              |
| 2      | 256            | 0         | 0             | 5              |
| 3      | 512            | 0         | 0             | 11             |
| 4      | 1024           | 0         | 0             | 24             |
| 5      | 2048           | 1         | 1             | 52             |
| 6      | 4096           | 2         | 2             | 114            |
| 7      | 8191           | 4         | 5             | 287            |
| 8      | 8191           | 6         | 8             | 499            |


