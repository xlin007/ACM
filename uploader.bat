@echo off

set uploaddir=python

( 
    echo ===============================================================
    echo  WallProxy����˲������, ��ʼ�ϴ�%uploaddir%�����
    echo ===============================================================
rem     echo.
rem     echo ����������appid, ���appid����^|�Ÿ���
) && (
    @cd /d "%~dp0" 
) && (
    "..\local\python.exe" uploader
) && (
    echo.
    echo �ϴ��ɹ�����༭proxy.ini�����appid���ȥ��лл���밴������˳�����
)

@pause>NUL

@echo off
