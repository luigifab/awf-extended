Name:          awf-qt7
Version:       4.3.0
Release:       1%{?dist}
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
BuildRequires: qt7-qtbase-devel
Requires:      qt7-qtbase
Requires:      hicolor-icon-theme
#ecommends:    qt7-gtk-platformtheme = qt7-qtbase-gui
Recommends:    qt7-globalqss
Recommends:    qt7-qtsvg
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
%{bash_completions_dir}/%{name}
%{_mandir}/man1/%{name}.1*


%changelog
* Fri Jan 01 2027 Fabrice Creuzot <code@luigifab.fr> - 4.3.0-1
- Initial Fedora package release (Closes: rhbz#...)




















































