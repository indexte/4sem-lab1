# 4sem-lab1
Перша лабораторна 4 семестру. Початковий проект - https://github.com/indexte/notepad-renewed

Опис початкового проекту
Представляє собою программу "Текстовий редактор".
Основні можливості для роботи з файлами ("File"):
1) New - cтворення нового текстового файлу;
2) Open - Відкриття раніше створеного файлу для його редагування;
3) Save as - Збереження поточного текстового файлу;
4) Print - Друкування поточного файлу;
5) Exit - Вихід з программи.

Для редагування тексту ("Edit") программа має такі можливості:
1) Copy - копіювання тексту;
2) Paste - вставлення тексту;
3) Cut - вирізання тексту;
4) Undo - скасувати дію;
5) Redo - відновити дію.

В якості модернізації программи були реалізовані такі зміни:
1. Можливість перегляду та редагування не тільки одного поточного файлу, а й декількох. Для цього була реалізована локальна база даних SQLite для одночасної роботи з декількома файлами. В результаті, ми маємо QListWidget, де ми можемо перемикатися між відкритими файлами. Також нижче цього списку була реалізована кнопка "Remove" для того, щоб була можливість закривати файли, робота з якими вже завершена. 
2. Можливість сортування відкритих файлів за ім'ям (в алфавітному порядку) та за датою створення файлу. Сортування відбуваєтся за допомогою qSort.
3. Для зручності роботи з файлами, була реалізована можливість створювати Розділи. Вони зберігаються в базі даних, та відображаються в об'екті listSections за допомогою класу QListWidget. За замовчуванням всі створені і відкриті файли відкриваютmся у розділі "Main". Для того, щоб створити новий розділ, потрібно натиснути кнопку "New..." і у відкритому діалоговому вікні ввести назву нового розділу. Розділи, як і файли, можна прибирати за допомогою кнопки "Remove".
4. Для зручності роботи з файлами також були додані так звані Hotkeys:
  1) Ctrl+N - для створення нового текстового файлу;
  2) Ctrl+O - відкриття файлу;
  3) Ctrl+S - для збереження файлу;
  4) Ctrl+P - друкування файлу;
  5) Ctrl+Q - виходу з програми.
5. Реалізована можливість зміни шрифту текстового файлу. Можливі такі варіанти шрифту "Bold", "Italic", "Bold Italic" та повернення до стандартного шрифту "Standart".

6. Реалізовані Unit tests для перевірки роботи бази даних.
