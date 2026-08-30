Name:          awf-qt7
Version:       4.3.0
Release:       0
Summary:       Theme preview application for Qt 7
Summary(fr):   Application d'aperçu de thème pour Qt 7
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
BuildRequires: qt7-base-devel
Requires:      qt7-base
Requires:      hicolor-icon-theme
Recommends:    qt7-platformtheme-gtk3
Recommends:    qt7-globalqss
Recommends:    qt7-svg
Suggests:      libnotify >= 0.7.0

%description %{expand:
A widget factory is a theme preview application for GTK and Qt. It
displays the various widget types in a single window allowing to see
the visual effect of the applied theme.

This package provides the program for Qt 7.}

%description -l fr %{expand:
La fabrique à widgets est une application d'aperçu de thème pour GTK
et Qt. Elle affiche les différents types de widgets dans une seule
fenêtre permettant de voir l'effet visuel du thème appliqué.

Ce paquet fournit le programme pour Qt 7.}


%prep
%setup -q -n awf-extended-%{version}

%build
autoreconf -fi
%configure --enable-only-qt7
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
* Fri Jan 01 2027 Fabrice Creuzot <code@luigifab.fr> - 4.3.0-1
- Initial openSUSE package release




















































