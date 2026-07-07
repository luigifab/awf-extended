Name:          awf-qt5
Version:       4.2.0
Release:       0
Summary:       Theme preview application for Qt 5
Summary(fr):   Application d'aperçu de thème pour Qt 5
License:       GPL-3.0-or-later
URL:           https://github.com/luigifab/awf-extended
Source0:       %{url}/archive/v%{version}/%{name}-%{version}.tar.gz

BuildRequires: aspell-fr
BuildRequires: autoconf
BuildRequires: automake
BuildRequires: desktop-file-utils
BuildRequires: gcc-c++
BuildRequires: gettext
BuildRequires: hicolor-icon-theme
BuildRequires: libqt5-qtbase-devel
Requires:      libqt5-qtbase
Requires:      hicolor-icon-theme
Recommends:    libqt5-qtbase-platformtheme-gtk3
Recommends:    libqt5-qtsvg
Recommends:    qt5-globalqss
Suggests:      libnotify >= 0.7.0

%description %{expand:
A widget factory is a theme preview application for GTK and Qt. It
displays the various widget types in a single window allowing to see
the visual effect of the applied theme.

This package provides the program for Qt 5.}

%description -l fr %{expand:
La fabrique à widgets est une application d'aperçu de thème pour GTK
et Qt. Elle affiche les différents types de widgets dans une seule
fenêtre permettant de voir l'effet visuel du thème appliqué.

Ce paquet fournit le programme pour Qt 5.}


%prep
%setup -q -n awf-extended-%{version}

%build
autoreconf -fi
%configure --enable-only-qt5
%make_build

%install
%make_install
%find_lang %{name} --with-man

%files -f %{name}.lang
%license LICENSE
%doc README.md
%{_bindir}/%{name}
%{_datadir}/applications/%{name}.desktop
%{_datadir}/icons/hicolor/*/apps/%{name}.png
%{_datadir}/icons/hicolor/scalable/apps/%{name}.svg
%{_datadir}/bash-completion/completions/%{name}
%{_mandir}/man1/%{name}.1*


%changelog
* Tue Jul 07 2026 Fabrice Creuzot <code@luigifab.fr> - 4.2.0-1
- New upstream release
- Use make install

* Tue May 05 2026 Fabrice Creuzot <code@luigifab.fr> - 4.1.0-1
- New upstream release

* Tue Mar 03 2026 Fabrice Creuzot <code@luigifab.fr> - 4.0.0-1
- Initial openSUSE package release










































