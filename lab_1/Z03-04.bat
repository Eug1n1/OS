@echo off

set /a sum = %1 + %2
set /a mul = %1 * %2
set /a div = %3 / %2
set /a sub = %2 - %1
set /a mulSub = %sub% * (%1 - %2)

echo Строка параметров: %*
echo Параметр 1: %1 
echo Параметр 2: %2 
echo Параметр 3: %3  


echo %1 + %2 = %sum%
echo %1 * %2 = %mul%
echo %3 / %2 = %div%
echo %2 - %1 = %sub%
echo (%2 - %1) * (%1 - %2) = %mulSub%