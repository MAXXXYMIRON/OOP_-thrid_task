# Класс Фигура - _`Shape`_  
![Фигуры][MainImage]  

[MainImage]: MainImage.jpg  

**Класс Фигура** - является абстрактным классом, имеющем трех   наследнеков: Четырёхугольник,
Треугольник и Окружность, а также агрегирующем класс Цвет.  

> Класс определен в файле -  _`Shape.h`_  

>## **Поля класса**  
>> Поле  |  Описание  
>> ------|------
>>_`ColorShape *Coloring;`_ | Агрегирует класс Цвет для предоставления его наследникам  

>## **Методы класса**  
>> Метод  |  Описание  
>> ------|------
>>	_`virtual float Area() = 0;`_  |  Поиск площади фигуры, переопределяется в наследнике
>>  _`virtual float Perimeter() = 0;`_  |  Поиск периметра фигуры, переопределяется в наследнике  


## Особенности файла - _`Shape.h`_  
---
Помимо определения класса _`Shape`_, данный файл содержит пречисление _`ERRORS`_ в котором определены
исключения всех наследников класса _`Shape`_.  
Название исключения  | Причины возникновения  
---  |  ---  
_`NotDifferentCoordinate`_ | Если среди заданых точек есть одинаковые  
_`OnOneStraight`_ | Если какие-то из заданных точек лежат на одной прямой  
_`PointPerpendicularOneAxes`_ | Если при заданных точках, пересекающая их прямая перпендикулярна оси Ох или Оу  
_`NotCornerPointFigure`_ | Если заданная точка не является угловой точкой фигуры(вершиной)  
_`NotLieBoundaryCircle`_ | Если заданная точка не лежит на границе окружности  
_`NotLieInCircle`_ | Если заданная точка не лежит внутри окружности  
_`NotASide`_ | Если номер указанной стороны фигуры больше кол-ва её сторон или меньше одного  
_`IncorrectTypeTriangle`_ | Если переданный тип треугольника не обрабатывается данным методом  
_`IncorrectAngle`_ | Если угол сегмента окружности больше 180 градусов  
_`IncorrectRadius`_ | Если заданный радиус меньше либо равен 0  
_`ChordLongerDiametr`_ | Если заданная хорда длиньше диаметнра окружности  
_`HeightSegLongerRadius`_ | Если заданная высота сегмента окружности длиньше её радиуса  



# Класс Цвет - _`ColorShape`_
![Цвета][Color]  

[Color]: Color.jpg  

**Класс цвет** - предоставляет окраску фигуры. Поле фигуры этого типа может не инициализираваться.  

> Класс определён в файле - _`Color.h`_  

> ## **Поля класса**  
>> Поле  |  Описание  
>> ------|------  
>> _`Color color;`_  |  Поле типа перечисление  

> ## **Конструкторы класса**  
>> Конструктор  |  Описание  
>> ------|------  
>> _`ColorShape(Color color);`_  |  Инициализирует поле класса  

> ## **Вложенные типы**  
>> Тип  |  Описание  
>> ------|------  
>> _`enum Color {Black, White, Red, Violet, Green, Blue, Yellow};`_  |  Является типом поля класса _`ColorShape`_  

# Класс Точка - _`Point`_  
![Точка][Point]  

[Point]: Point.jpg  

**Класс Точка** - является основной составляющей наследников класса _`Shape`_. Он представляет тип полей наследников класса _`Shape`_, и содержит методы необходимые для реализации методов этих наследников.  

> Класс определён в файле - _`Point.h`_ 

> ## **Поля класса**  
>> Поле  |  Описание  
>> ------|------  
>> _`float x, y;`_  |  Координаты точки на двумерной плоскости  

> ## **Конструкторы класса**  
>> Конструктор  |  Описание  
>> ------|------  
>> _`Point();`_  |  Инициализирует поля класса нулями 
>> _`Point(float _x, float _y);`_  |  Инициализирует поля класса соответствующими значениями  

>## **Методы класса**  
>> Метод  |  Описание  
>> ------|------  
>> 	_`bool operator == (Point dot); `_|  Сравнение координат точек  
>> 	_`bool operator != (Point dot);`_ |  Сравнение координат точек   
>>	_`Point operator + (Point dot);`_ |  Сложение координат точек  
>>	_`Point operator - (Point dot);`_ |  Вычитание координат точек  
>>	_`Point operator * (Point dot);`_ |  Умножение координат точек  
>>	_`void operator += (float Val);`_ |  Увеличение на заданное число координат точек  
>>	_`void operator -= (float Val);`_ |  Уменьшение на заданное число координат точек  
>>	_`void operator *= (float Val);`_ |  Умножение на заданное число координат точек  
>>	_`void operator ++ ();`_ |  Инкрементирование координат точек  
>>	_`void operator -- ();`_ |  Декрементирование коорлинат точек  

## Особенности файла - _`Point.h`_  
---  
Файл _`Point.h`_ помимо определения класса _`Point`_, содержит методы, для работы с двумя и более объектами класса _`Point`_.  

Название метода  | Назначение метода  
---  |  ---  
_`float CathetHorizontal(Point dot1, Point dot2);`_  |  Определить расстояние между точками по горизонтали  
_`float CathetVertical(Point dot1, Point dot2);`_  |  Определить расстояние между точками по вертикали  
_`float Length(Point dot1, Point dot2);`_  |  Определить расстояние между точками  
_`bool DifferentCoordinate(Point dot1, Point dot2, Point dot3, Point dot4);`_  |  Определить нет ли среди четырёх точек, хотя бы две одинаковые  
_`bool DifferentCoordinate(Point dot1, Point dot2, Point dot3);`_  |  Определить нет ли среди трех точек, хотя бы две одинаковые  
_`bool NotOnOneStraight(Point dot1, Point dot2, Point dot3, Point dot4);`_  |  Определить не лежат ли, какие-либо три из четырех точек на одной прямой  
_`bool NotOnOneStraight(Point dot1, Point dot2, Point dot3);`_  |  Определить лежат ли три точки на одной прямой  


# Класс Четырёхугольник - _`Quadrangle`_  
![Четырёхугольник][Quadrangle]  

[Quadrangle]: Quadrangle.jpg  

**Класс Четырехугольник** - является наследником класса _`Shape`_ и создается с использованием класса _`Point`_.  

> Класс определён в файле - _`Quadrangle.h`_  

> ## **Поля класса**  
>> Поле  |  Описание  
>> ------|------  
>> _`Point A, B, C, D;`_  |  Точки, являющиеся вершинами четырёхугольника

> ## **Конструкторы класса**  
>> Конструктор  |  Описание  |  Исключения
>> ------|------|------
>> _`Quadrangle();`_  |  Создаст квадрат с вершинами (0, 0), (0, 1),(1, 0), (1, 1).  |  Нет  
>> _`Quadrangle(Point _A, Point _B, Point _D, Point _C);`_  |  Создаст четырехугольник по заданным координатам вершин  |  NotDifferentCoordinate, OnOneStraight  
>> _`Quadrangle(Point _A, Point _B, Point _D);`_  |  Создаст четырехугольник, стороны которого попарно равны  |  NotDifferentCoordinate, OnOneStraight  
>> _`	Quadrangle(Point _A, Point _B);`_  |  Создаст квадрат |  OnOneStraight  

>## **Методы класса**  
>> Метод  |  Описание  |  Исключение
>> ------|--------|-------
>> 	_`Point GetA();`_  |  Получение точки A  |  Нет  
>> 	_`Point GetB();`_  |  Получение точки B  |  Нет  
>> 	_`Point GetC();`_  |  Получение точки C  |  Нет  
>> 	_`Point GetD();`_  |  Получение точки D  |  Нет  
>> 	_`void SetA(Point dot);`_  |  Установка точки А  |  NotDifferentCoordinate, OnOneStraight  
>> 	_`void SetB(Point dot);`_  |  Установка точки B  |  NotDifferentCoordinate, OnOneStraight  
>> 	_`void SetC(Point dot);`_  |  Установка точки C  |  NotDifferentCoordinate, OnOneStraight  
>> 	_`void SetD(Point dot);`_  |  Установка точки D  |  NotDifferentCoordinate, OnOneStraight  
>> 	_`void operator = (Quadrangle Q2);`_  |  Присваивание данного четырехугольника текущему  |  Нет  
>> 	_`float Area() override;`_  |  Переопределение метода поиска площади  |  Нет  
>> 	_`float Perimeter() override;`_  |  Переопределение метода поиска периметра  |  Нет  
>> 	_`float Diagonal(Point dot);`_  |  Поиск диагонали исходящей из данной точки  |  NotCornerPointFigure  
>> 	_`float Angle(Point dot);`_  |  Угол вершины четырёхугольника  |  NotCornerPointFigure  
>> 	_`float SideLen(char Num);`_  |  Длина стороны четырёхугольника  |  NotASide  
>> 	_`Triangle Trian(Point dot);`_  |  Возврат треугольника из данной вершины  |  NotCornerPointFigure
>> 	_`bool Belong(Point dot);`_  |  Проверка на вхождение данной точки в плоскость четырёхугольника  |  Нет  

## Пояснения к некоторым методам класса _`Quadrangle`_  
---  
> 	_`float Diagonal(Point dot);`_  
> ![Четырёхугольник: Диагональ][DiagonalQuad]  
> 
> [DiagonalQuad]: DiagonalQuad.jpg 

> 	_`float Angle(Point dot);`_  
> ![Четырёхугольник: Угол][AngleQuad]  
> 
> [AngleQuad]: AngleQuad.jpg 

> 	_`float SideLen(char Num);`_  
> ![Четырёхугольник: Сторона][SideQuad]  
> 
> [SideQuad]: SideQuad.jpg 

> 	_`Triangle Trian(Point dot);`_  
> ![Четырёхугольник: Треугольник][TriangleQuad]  
> 
> [TriangleQuad]: TriangleQuad.jpg  

# Класс Треугольник - _`Triangle`_  
![Треугольник][Triangle]  

[Triangle]: Triangle.jpg  

**Класс Треугольник** - является наследником класса _`Shape`_ и создается с использованием класса _`Point`_.  

> Класс определён в файле - _`Triangle.h`_

> ## **Поля класса**  
>> Поле  |  Описание  
>> ------|------  
>> _`Point A, B, C;`_  |  Точки, являющиеся вершинами треугольника  

> ## **Конструкторы класса**  
>> Конструктор  |  Описание  |  Исключения
>> ------|------|------
>> _`Triangle();`_  |  Создаст треугольник с вершинами (0, 0), (0, 2),(1, 2).  |  Нет  
>> _`Triangle(Point _A, Point _B, Point _C);`_  |  Создаст треугольник по заданным координатам вершин  |  NotDifferentCoordinate, OnOneStraight  
>> _`Triangle(Point _A, Point _B, std::string TypeTriangle);`_  |  Создаст прямоугольный или равнобедренный треугольник  |  NotDifferentCoordinate, PointPerpendicularOneAxes, IncorrectTypeTriangle  

>## **Методы класса**  
>> Метод  |  Описание  |  Исключение
>> ------|--------|-------
>> 	_`Point GetA();`_  |  Получение точки A  |  Нет  
>> 	_`Point GetB();`_  |  Получение точки B  |  Нет  
>> 	_`Point GetC();`_  |  Получение точки C  |  Нет  
>> 	_`void SetA(Point dot);`_  |  Установка точки А  |  NotDifferentCoordinate, OnOneStraight  
>> 	_`void SetB(Point dot);`_  |  Установка точки B  |  NotDifferentCoordinate, OnOneStraight  
>> 	_`void SetC(Point dot);`_  |  Установка точки C  |  NotDifferentCoordinate, OnOneStraight  
>> 	_`void operator = (Triangle T2);`_  |  Присваивание данного треугольника текущему  |  Нет  
>> 	_`float Area() override;`_  |  Переопределение метода поиска площади  |  Нет  
>> 	_`float Perimeter() override;`_  |  Переопределение метода поиска периметра  |  Нет   
>>  _`float Median(Point dot);`_  |  Длина медианы треугольника, проведенной из данной точки  |  NotCornerPointFigure  
>>  _`float Height(Point dot);`_  |  Длина высоты треугольника, проведенной из данной точки  |  NotCornerPointFigure  
>>  _`float Bisector(Point dot);`_  |  Длина биссектрисы треугольника, проведенной из данной точки  |  NotCornerPointFigure  
>> 	_`float Angle(Point dot);`_  |  Угол вершины треугольника  |  NotCornerPointFigure  
>> 	_`float SideLen(char Num);`_  |  Длина стороны треугольника  |  NotASide  
>> _`Quadrangle Quad(char Num);`_  |  Возврат четырёхугольника, диагональ которого данная сторона треугольника  |  NotASide  
>> 	_`bool Belong(Point dot);`_  |  Проверка на вхождение данной точки в плоскость треугольника  |  Нет  

## Пояснения к некоторым методам класса _`Triangle`_  
---  
> 	_`float SideLen(char Num);`_   
> ![Треугольник: Сторона][SideTrian]  
> 
> [SideTrian]: SideTrian.jpg  

> 	_`Quadrangle Quad(char Num);`_   
> ![Треугольник: Четырехугольгник][QuadTrian]  
> 
> [QuadTrian]: QuadTrian.jpg  

> 	_`Triangle(Point _A, Point _B, std::string TypeTriangle);`_  
Константы определены в классе _`Triangle`_, параметр метода сравнивается с ними  
>> _`const std::string RECT = "Rectengular";`_  
>> _`const std::string ISO = "Isosceles";`_  

# Класс Окружность - _`Circle`_  
![Окружность][Circle]  

[Circle]: Circle.jpg   

**Класс Окружность** - является наследником класса _`Shape`_ и создается с использованием класса _`Point`_.  

> Класс определён в файле - _`Circle.h`_

> ## **Поля класса**  
>> Поле  |  Описание  
>> ------|------  
>> 	_`float R;`_  |  Радиус окружности  
>>	_`Point O;`_  |  Точка центра окружности  

> ## **Конструкторы класса**  
>> Конструктор  |  Описание  |  Исключения
>> ------|------|------
>> 	_`Circle();`_  |  Создаст окружность с центром в точке (0, 0) и радиусом 1  |  Нет
>> 	_`Circle(float _R, Point _O);`_  |  Создаст окружность с центром в точке _О и радиусом _R  |  IncorrectRadius  

>## **Методы класса**  
>> Метод  |  Описание  |  Исключение
>> ------|--------|-------
>> 	_`float GetR();`_  |  Получить радиус окружности  |  Нет  
>> 	_`Point GetO();`_  |  Получить точку центра окружности  |  Нет
>> 	_`void SetR(float _R);`_  |  Установить радиус окружности  |  IncorrectRadius  
>> 	_`void SetO(Point _O);`_  |  Установить точку центра окружности  |  Нет  
>>  _`void operator = (Circle C2);`_  |  Присвоит данную окружность  текущей  |  Нет
>> 	_`float Area() override;`_  |  Переопределение метода поиска площади  |  Нет  
>> 	_`float Perimeter() override;`_  |  Переопределение метода поиска периметра  |  Нет   
>> 	_`float HalfArea();`_  |  Полуплощадь окружности  |  Нет
>> 	_`float HalfPerimeter();`_  |  Полупериметр окружности  |  Нет
>> 	_`float Diameter();`_  |  Диаметр окружности  |  Нет
>> 	_`float LenChord(Point dot);`_  |  Длина хорды, проведённой препендикулярно радиусу, через данную точку  |  NotLieInCircle  
>> 	_`float LenChord(Point dot1, Point dot2);`_  |  Длина хорды, проведённой через точки, лежащие на границе окружности  |  NotLieBoundaryCircle  
>> 	_`float LenChord(float Angle);`_  |  Длина хорды данного угла сегмента  |  IncorrectAngle  
>> 	_`float LenChord(float Height, char flag);`_  |  Длина хорды сегмента с данной высотой  |  HeightSegLongerRadius  
>> 	_`float LenArc(float LenChord);`_  |  Длина дуги данной хорды  |  ChordLongerDiametr  
>> 	_`float AreaSeg(float LenChord);`_  |  Площадь сегмента данной хорды  |  ChordLongerDiametr  
>> 	_`float PerimetrSeg(float LenChord);`_  |  Периметр сегмента данной хорды  |  ChordLongerDiametr  
>> 	_`float AngleSeg(float LenChord);`_  |  Угол сегмента данной хорды  |  ChordLongerDiametr  
>> 	_`float HeightSeg(float LenChord)`_;  |  Высота сегмента данной хорды  |  ChordLongerDiametr  
>> 	_`bool Belong(Point dot);`_  |  Определить принадлежность точки окружности  |  Нет  

## Пояснения к некоторым методам класса _`Circle`_  
---  
> 	_`float LenChord(Point dot);`_  
> ![Окружность: Хорда][ChordCircle]  
> 
> [ChordCircle]: ChordCircle.jpg  

# UML 

![UML - диаграмма][ShapesUML]  

[ShapesUML]: ShapesUML.jpg  