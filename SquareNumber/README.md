### **Приложение «Возведение числа в квадрат» на фреймворке QT**

В момент запуска приложения кнопка Следующее не активна, поскольку нажатие
на нее бессмысленно. При выдаче результата эта кнопка становится доступной, но строч-
ный редактор, используемый для ввода значения, – блокируется, чтобы предотвратить из-
менение исходных данных и, как следствие, демонстрации на экране результата, не свя-
занного с исходными данными.
Ввод будем считать завершенным, если пользователь нажимает клавиши Enter или
Tab клавиатуры или щелкает мышью вне поля ввода. При этом строчный редактор теряет
фокус ввода. При вводе неправильных (например, буквенных) исходных данных прило-
жение должно выдавать сообщение об ошибке в специальном окне.