# Framework Integration - **Unofficial** Mini Version

Integration of Qt application with KDE workspaces, mini version.

The systray and file dialog integration have been removed in order to
reduce dependencies. I use this platform theme plugin in AppImages
where I want KDE font settings, color scheme et.c. to be respected when
the image is run under a Plasma session, as the QGenericTheme that Qt
falls back to has its limitations.

The plugin installs itself as `KDEPlasmaPlatformThemeMini.so`, but
still declares itself with the key "kde" in its metadata, so that it
is picked up by the XCB platform plugin when running under a KDE
session.

This is a highly unoffical platform theme plugin and comes with no
guarantees/support. If you want full integration, use the official
integration.

The official integration package is at:

    https://cgit.kde.org/plasma-integration.git/
