include_directories(${Qt5Gui_PRIVATE_INCLUDE_DIRS})

set(platformtheme_SRCS
    kdeplatformtheme.cpp
    kfontsettingsdata.cpp
    khintssettings.cpp
    main.cpp
)

add_library(KDEPlasmaPlatformThemeMini MODULE ${platformtheme_SRCS})

target_link_libraries(KDEPlasmaPlatformThemeMini
    PRIVATE
        Qt5::Widgets
        Qt5::DBus
        Qt5::X11Extras
        KF5::ConfigCore
        KF5::ConfigWidgets
        KF5::IconThemes
        ${X11_Xcursor_LIB}
)

install(TARGETS KDEPlasmaPlatformThemeMini DESTINATION ${KDE_INSTALL_QTPLUGINDIR}/platformthemes)
