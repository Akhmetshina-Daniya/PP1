import threading
import time
import random

# Параметры задачи
num_books = random.randint(4, 7)  # Количество книг
num_students = random.randint(11, 15)  # Количество студентов
max_books_per_student = 3  # Максимальное количество книг, которые может взять студент

# Генерация случайного количества экземпляров для каждой книги
book_copies = [random.randint(2, 4) for _ in range(num_books)]

# Мьютексы и условные переменные для каждой книги
book_locks = [threading.Lock() for _ in range(num_books)]
book_conditions = [threading.Condition(lock) for lock in book_locks]

# Функция для студента
def student(student_id):
    while True:
        # Случайный выбор 3 книг
        requested_books = random.sample(range(num_books), max_books_per_student)

        # Проверка доступности книг
        available = True
        for book in requested_books:
            with book_locks[book]:
                if book_copies[book] <= 0:
                    available = False
                    break

        if available:
            # Взятие книг
            for book in requested_books:
                with book_locks[book]:
                    book_copies[book] -= 1
                    print(f"Студент {student_id} взял книгу {book}")

            # Работа со книгами
            time.sleep(random.uniform(1, 3))

            # Возврат книг
            for book in requested_books:
                with book_locks[book]:
                    book_copies[book] += 1
                    print(f"Студент {student_id} вернул книгу {book}")
                    book_conditions[book].notify_all()

            break
        else:
            # Ожидание, если книги недоступны
            print(f"Студент {student_id} ждет книги")
            time.sleep(1)

# Создание и запуск потоков для студентов
threads = []
for i in range(num_students):
    thread = threading.Thread(target=student, args=(i,))
    threads.append(thread)
    thread.start()

# Ожидание завершения всех потоков
for thread in threads:
    thread.join()

print("Все студенты завершили работу.")
