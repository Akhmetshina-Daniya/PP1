# Проект часть 1 – Проектирование потокобезопасных приложений, содержащих параллельные операции, с использованием средствсинхронизации

## Состав бригады
- КС-43: Ахметшина Д.

## Вариант 10

## Текст задания
 - Имеется 3<n<8 различных книг каждая в 1<pn<4 экземплярах. Предположим, что 10<m<16
студентам необходимо получить заданный одинаковый список книг, поработать с ними в зале и
вернуть. Смоделировать процесс доступа к ресурсам библиотеки при условии, что читатель
может взять на руки не более 3 книг, книги студент берет в произвольном порядке. Если одна из
книг занята, студент думает 1 секунду и просит снова 3 случайные книги.

- Смоделировать ситуацию с использованием потоков в качестве
акторов задачи, мьютексов, и, где надо, – условных переменных. Оценивается
соответствие заданию, правильность выбора и оптимальность числа средств
синхронизации, и потокобезопасность. Возможное непотокобезопасное исполнение
кода наиболее сильно снижает оценку (например, использование общего для
потоков счетчика без мьютекса)
