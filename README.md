## Задание:

В структурах хранится информация о студентах. Одним из элементов структуры является объединение, в котором, в зависимости от места жительства (иногородний студент или нет), информация задается в виде:
* а) Минск, ул. ..., д. ..., кв. ...;
* б) область, город ..., ул. ..., д. ..., кв. ...;
* в) область ..., район ..., город ..., ул. ..., д. ..., кв. ...;
* г) область ..., район ..., деревня ..., дом ... .
По запросу из командной строки, в зависимости от вида информации, вывести данные о тех или иных студентах, используя указатели на функции.

## Пользование программой

__./main [опции]__

* __-p__ - вывод всех студентов из базы данных

* __-t <тип>__ - вывод списка студентов с введённым типом проживания

* __-h__ - помощь

__Типы проживания студентов:__

* 1 - г. Минск
* 2 - областной центр
* 3 - районный центр
* 4 - деревня
