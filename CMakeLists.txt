# CMakeList.txt: проект CMake для CppStudy; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.

cmake_minimum_required (VERSION 3.10)
project ("CppStudy")

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

set(CMAKE_CXX_STANDARD 20)

add_executable(Fraction ${COMMON_SOURCES}
	"src/utils/Fraction.cpp"
)

add_executable(Animals ${COMMON_SOURCES}
	"src/animals/Main.cpp"
	"src/animals/Animal.cpp"
	"src/animals/Cat.cpp"
	"src/animals/Bird.cpp"
	"src/animals/Meowl.cpp"
)

#if (CMAKE_VERSION VERSION_GREATER 3.12)
#  set_property(TARGET Task1 PROPERTY CXX_STANDARD 20)
#endif()