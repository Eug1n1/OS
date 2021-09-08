@echo off

REM change CHCP to UTF-8
CHCP 65001
CLS

echo -- текущий пользователь: %username%
echo -- текущие дата и время: %time%, %date%
echo -- имя компьютера: %computername%