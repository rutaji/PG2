WINDOWS: 

Download from https://opencv.org/releases/ 

Extract opencv-4.6.0-vc14_vc15.exe to C:\

Add user specific variable:
 Ovladaci panely -> uzivatelske ucty -> Student -> Zmenit promenne prostredi
(Control panel   -> User accounts    -> Student -> Change system variables)

OPENCV_DIR=C:\opencv\build

Change default path
PATH=%PATH%;%OPENCV_DIR%\x64\vc15\bin
-------------------------------------------------------------------------------
VISUAL STUDIO

Platform: X64, C++ console project

project - properties - configuration properties - VC++ directories 
select "ALL CONFIGURATIONS"
     - executable - $(OPENCV_DIR)\x64\vc15\bin
     - include    - $(OPENCV_DIR)\include
     - libraries  - $(OPENCV_DIR)\x64\vc15\bin
                    $(OPENCV_DIR)\x64\vc15\lib

select ALL CONFIGURATIONS:
      project - properties - configuration properties - general - C++ language standard - ISO C++17 standard

select DEBUG config:
      project - properties - configuration properties - linker - input - additional dependencies - opencv_world460d.lib 

select RELEASE config: 
      project - properties - configuration properties - linker - input - additional dependencies - opencv_world460.lib


(OPTIONAL: project - properties - configuration properties - C/C++ - Advanced - Disable specific warnings - 4996,4793,...)

((should not happen) In case, that your app can not find DLLs (this should not happen), copy those missing from $(OPENCV_DIR)\x64\vc15\bin to your project directory near your .CPP file)

-------------------------------------------------------------------------------
