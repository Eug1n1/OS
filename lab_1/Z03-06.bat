@echo off

echo -- Строка параметров: %*
echo -- режим: %1 
echo -- имя файла: %2 

if "%1" == "" (
    echo ---+ z03-06 режим файл
    echo ---++ режим {создать, удалить}
    echo ---++ файл = имя файла
    goto end
)

if "%2" == "" (
    echo ---+ не задано имя файла
    goto end
)

if "%1" == "создать" (
    if exist %2 (
        echo ---+ файл %2 уже существует
        goto end
    ) 
    type nul>%2
    echo ---+ файл %2 создан
    goto end
)

if "%1" == "удалить" (
    if not exist %2 (
        echo ---+ файл %2 не найден
        goto end
    ) 
    del %2
    echo ---+  файл %2 удален
    goto end
)

echo ---+ режим задан не корректно

:end