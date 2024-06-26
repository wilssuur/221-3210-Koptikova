# Экзаменационный проект

Программа представляет собой простое Qt-приложение с двумя основными страницами: авторизации и игрового поля. Пользователь сначала видит страницу авторизации с полем для ввода PIN-кода, который скрывается при вводе (маскирование). При правильном вводе PIN-кода происходит переход на страницу игры.

На странице игры отображается игровое поле 3x3, состоящее из 9 карт. Каждая карта имеет случайное число, которое может быть положительным или отрицательным. При нажатии на карту это число показывается, и оно добавляется к текущему счету, который отображается в специальном поле.

Если пользователь последовательно выбирает три карты, всплывающее окно показывает сумму значений выбранных карт. После закрытия окна или нажатия кнопки «Сброс» происходит обновление игрового поля: карты скрываются, и им присваиваются новые случайные числа. Программа также поддерживает сброс игрового поля при переходе с экрана авторизации.
Программа управляет состояниями между страницами, маскирует ввод PIN-кода, генерирует случайные числа и обрабатывает их отображение и суммирование на игровом поле.


Страница авторизации: Предназначена для ввода PIN-кода. Если PIN-код правильный, происходит переход на страницу игры.

![image](https://github.com/wilssuur/221-3210-Koptikova/assets/124897239/eb207e66-87dd-44b4-a0f7-d96ef71d46ed)

Страница игры: Включает игровое поле с 9 картами, кнопку сброса и поле для отображения очков. Карты имеют случайные числа, которые отображаются при нажатии и добавляются к текущему счету. При выборе трех карт отображается их сумма во всплывающем окне, после чего происходит сброс игрового поля.

![image](https://github.com/wilssuur/221-3210-Koptikova/assets/124897239/be3d97dd-f9d9-4b3f-bfa4-2bc8c8116204)

![image](https://github.com/wilssuur/221-3210-Koptikova/assets/124897239/c9792ac1-6ac9-4bf5-97bf-bc482071fd1a)
