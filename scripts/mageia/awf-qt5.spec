Name:          awf-qt5
Version:       4.3.0
Release:       %mkrel 1
Summary:       Theme preview application for Qt 5
Summary(fr):   Application d'aperçu de thème pour Qt 5
License:       GPLv3+
Group:         Development/Basic
URL:           https://github.com/luigifab/awf-extended
Source0:       %{url}/archive/v%{version}/%{name}-%{version}.tar.gz

BuildRequires: aspell-fr
BuildRequires: autoconf
BuildRequires: automake
BuildRequires: desktop-file-utils
BuildRequires: gcc-c++
BuildRequires: gettext
BuildRequires: qt5-devel
Requires:      qt5
Requires:      hicolor-icon-theme
#ecommends:    qt5-gtk-platformtheme ?
Recommends:    qt5-globalqss
Recommends:    qtsvg5
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
* Fri Jan 01 2027 Fabrice Creuzot <code@luigifab.fr> - 4.3.0-1.mga
- New upstream release

* Tue Jul 07 2026 Fabrice Creuzot <code@luigifab.fr> - 4.2.0-1.mga
- New upstream release
- Use make install

* Tue May 05 2026 Fabrice Creuzot <code@luigifab.fr> - 4.1.0-1.mga
- New upstream release

* Tue Mar 03 2026 Fabrice Creuzot <code@luigifab.fr> - 4.0.0-1.mga
- Initial Mageia package release (Closes: mbz#32827)










































