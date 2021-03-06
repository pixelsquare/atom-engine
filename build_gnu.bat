@ECHO OFF
SETLOCAL
PUSHD %~dp0

:: Create Obj Directory
CALL :CreateObjDir

:: Create Lib Directory
CALL :CreateLibDir

:: Set MingGW Path
CALL :SetMinGWPath

:: Set Make Path
CALL :SetMakePath

:: Set Msys Path
CALL :SetMsysPath

:: Set Ming32 Path
CALL :SetMing32Path

CALL :BuildGCC

PAUSE

:CreateObjDir
IF NOT EXIST obj MKDIR obj
EXIT /b 0

:RemoveObjDir
IF EXIST obj RMDIR obj
EXIT /b 0

:CreateLibDir
IF NOT EXIST lib MKDIR lib
EXIT /b 0

:RemoveLibDir
IF EXIST lib RMDIR lib
EXIT /b 0

:SetMinGWPath
SET MINGW_PATH=E:\MinGW\bin

IF NOT EXIST %MINGW_PATH% (
	ECHO MinGW Path does not exist.
	EXIT /b 0
)

SET PATH=%PATH%;%MINGW_PATH%
EXIT /b 0

:SetMakePath
SET MAKE_PATH=E:\Program Files (x86)\GnuWin32\bin

IF NOT EXIST "%MAKE_PATH%" (
	ECHO Make Path does not exist.
	EXIT /b 0
)

SET PATH=%PATH%;%MAKE_PATH%
EXIT /b 0

:SetMsysPath
SET MSYS_PATH=E:\MinGW\msys\1.0\bin

IF NOT EXIST "%MSYS_PATH%" (
	ECHO Make Path does not exist.
	EXIT /b 0
)

SET PATH=%PATH%;%MSYS_PATH%
EXIT /b 0

:SetMing32Path
SET MING32_PATH=E:\MinGW\mingw32\bin

IF NOT EXIST "%MING32_PATH%" (
	ECHO Make Path does not exist.
	EXIT /b 0
)

SET PATH=%PATH%;%MING32_PATH%
EXIT /b 0

:BuildGCC
ECHO Build started ..
ECHO.

CALL make compile
CALL make build
REM CALL make clean

ECHO.
IF ERRORLEVEL 1 (
	ECHO Build FAILED!
	CALL :RemoveObjDir
	CALL :RemoveLibDir
) ELSE (
	ECHO Build SUCCES!
)

ECHO.
EXIT /b 0

POPD
ENDLOCAL