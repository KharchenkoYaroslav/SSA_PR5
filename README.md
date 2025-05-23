# SSA_PR5

# Технології та запуск

## Як середовище розробки було обрано Docker-контейнер на базі образу `debian:bullseye-slim` з таких причин:

### Прозорість — усі початкові умови для виконання завдання задані в `Dockerfile`, що дозволяє бачити весь процес виконання, а також гарантує стабільність роботи коду.

### Швидкість відтворення початкових умов — Docker-контейнер дозволяє легко змінювати необхідні пакети та конфігурації. Усі зміни можна відкрутити назад за кілька секунд, тоді як у віртуальній машині це займає певний час. Це особливо актуально для завдань, які потребують змін або видалення файлів.

### Зручність розробки — Docker дозволяє швидко змінювати архітектуру, копіювати файли з основної машини та автоматизувати повторювані команди, що значно пришвидшує розробку.

### Варіативність — якщо щось неможливо або складно реалізувати на базі одного образу, завжди можна замінити його на інший.

#### *У завданнях, які неможливо реалізувати як задумано без використання повноцінної системи, буде застосовано `VM`.*

## Запуск

### Всі необхідні команди для запуску контейнерів та виконання файлів описані в `Dockerfile`

# Звіт по завданням

## Завдання 2.1 (Варіант 22)

### Демонстрація порушення через "use-after-free", коли об’єкт передається у бібліотечну функцію (`pow`) після звільнення.

```
root@05e0866c1272:/app# gcc -g task.c -o task -lm
root@05e0866c1272:/app# valgrind ./task
==13== Memcheck, a memory error detector
==13== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==13== Using Valgrind-3.16.1 and LibVEX; rerun with -h for copyright info
==13== Command: ./task
==13==
==13== Invalid read of size 8
==13==    at 0x10919B: main (task.c:10)
==13==  Address 0x4b66040 is 0 bytes inside a block of size 8 free'd
==13==    at 0x48399AB: free (vg_replace_malloc.c:538)
==13==    by 0x109196: main (task.c:8)
==13==  Block was alloc'd at
==13==    at 0x483877F: malloc (vg_replace_malloc.c:307)
==13==    by 0x109176: main (task.c:6)
==13==
Result: 9.00
==13==
==13== HEAP SUMMARY:
==13==     in use at exit: 0 bytes in 0 blocks
==13==   total heap usage: 2 allocs, 2 frees, 1,032 bytes allocated
==13==
==13== All heap blocks were freed -- no leaks are possible   
==13==
==13== For lists of detected and suppressed errors, rerun with: -s
==13== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
