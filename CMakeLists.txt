cmake_minimum_required(VERSION 2.8.12)

project(PlasmaIntegration)
project(PlasmaIntegrationMini)
set(PROJECT_VERSION "5.12.7")
set(PROJECT_VERSION_MAJOR 5)

include(FeatureSummary)
find_package(ECM 5.17.0  NO_MODULE)
set_package_properties(ECM PROPERTIES TYPE REQUIRED DESCRIPTION "Extra CMake Modules."
                       URL "https://projects.kde.org/projects/kdesupport/extra-cmake-modules")
feature_summary(WHAT REQUIRED_PACKAGES_NOT_FOUND FATAL_ON_MISSING_REQUIRED_PACKAGES)

set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR})

include(GenerateExportHeader)
include(ECMPackageConfigHelpers)
include(ECMSetupVersion)
include(ECMGenerateHeaders)

include(KDEInstallDirs)
include(KDEFrameworkCompilerSettings NO_POLICY_SCOPE)
include(KDECMakeSettings)

set(REQUIRED_QT_VERSION 5.9.0)
find_package(Qt5 ${REQUIRED_QT_VERSION} CONFIG REQUIRED Widgets DBus X11Extras)

set(KF5_DEP_VERSION "5.33.0")

find_package(KF5 ${KF5_DEP_VERSION} REQUIRED COMPONENTS
                Config ConfigWidgets I18n IconThemes
                WidgetsAddons WindowSystem ConfigWidgets
)

find_package(X11 REQUIRED)

add_subdirectory(src)

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)
