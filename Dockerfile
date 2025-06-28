FROM ubuntu:24.04

# Установка необходимых пакетов
RUN apt-get update && \
    apt-get install -y g++ make

# Создание рабочей директории
WORKDIR /ex_khomutov

# Копирование всех файлов проекта в контейнер
COPY . .

# Компиляция проекта
RUN g++ audiomanager.cpp main.cpp -o my_Program

# Установка значения параметра программы по умолчанию (пример: имя файла)
ENV PARAM_DEFAULT=test

# Запуск программы с параметром (используется переменная окружения)
CMD ["./my_Program", "test"]