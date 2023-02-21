CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
	
ADD_SUBDIRECTORY(googletest)


ADD_EXECUTABLE	(Character
	header/Bard.h
	header/Character.h
	header/Fighter.h
	header/Item.hpp 
	header/Mage.h 
	header/Tank.h
	src/main.cpp
)

ADD_EXECUTABLE(characterTest
		header/Bard.h
		header/Character.h
		header/Fighter.h
		header/Item.hpp
		header/Mage.h 
		header/Tank.h
		tests/test2.cpp

)

ADD_EXECUTABLE(fantasma

    src/mainFile.cpp

    src/PerlinNoise.cpp
    src/Map.cpp
    src/Location.cpp
    src/Town.cpp
    src/Dungeon.cpp

    src/Item.cpp
    src/NameGenerator.cpp
    src/FightScreen.cpp
    src/Bandit.cpp
    src/Tank.cpp
    src/Fighter.cpp 
    src/Bard.cpp
    src/Character.cpp
    src/Boss.cpp
    src/Mage.cpp
)

ADD_EXECUTABLE(perlinTest
    tests/testSpace.cpp
    src/PerlinNoise.cpp
    src/Map.cpp
    src/Location.cpp
    src/Dungeon.cpp
    src/Town.cpp
    src/Item.cpp
    src/NameGenerator.cpp
)



ADD_EXECUTABLE(itemTest
    tests/itemTest.cpp
    header/Item.hpp
    header/fighterItem.hpp
    header/bardItem.hpp
    header/mageItem.hpp
    header/tankItem.hpp
    header/Bandit.hpp
    header/Boss.hpp
    )

    ADD_EXECUTABLE(fight

    header/Character.h
    src/FightTest.cpp
    header/Fighter.h
    header/Item.hpp
)



TARGET_LINK_LIBRARIES(characterTest gtest)
TARGET_COMPILE_DEFINITIONS(characterTest PRIVATE gtest_disabled_pthreads=ON)

TARGET_LINK_LIBRARIES(perlinTest gtest)
TARGET_COMPILE_DEFINITIONS(perlinTest PRIVATE gtest_disabled_pthreads=ON)

TARGET_LINK_LIBRARIES(itemTest gtest)
TARGET_COMPILE_DEFINITIONS(itemTest PRIVATE gtest_disabled_pthreads=ON)