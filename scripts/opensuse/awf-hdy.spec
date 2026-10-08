Name:          awf-hdy
Version:       4.3.0
Release:       0
Summary:       Theme preview application for Handy
Summary(fr):   Application d'aperçu de thème pour Handy
License:       GPL-3.0-or-later
URL:           https://github.com/luigifab/awf-extended
Source0:       %{url}/archive/v%{version}/%{name}-%{version}.tar.gz

BuildRequires: aspell-fr
BuildRequires: autoconf
BuildRequires: automake
BuildRequires: desktop-file-utils
BuildRequires: dejavu-fonts
BuildRequires: libnotify-devel >= 0.7.0
BuildRequires: rsvg-convert
BuildRequires: gcc
BuildRequires: gettext
BuildRequires: gtk3-devel >= 3.24.1
BuildRequires: libhandy-devel
Requires:      gtk3 >= 3.24.1
Requires:      libhandy-1-0
Requires:      hicolor-icon-theme
Requires:      libnotify >= 0.7.0


%description %{expand:
A widget factory is a theme preview application for GTK and Qt. It
displays the various widget types in a single window allowing to see
the visual effect of the applied theme.

This package provides the program for Handy.}

%description -l fr %{expand:
La fabrique à widgets est une application d'aperçu de thème pour GTK
et Qt. Elle affiche les différents types de widgets dans une seule
fenêtre permettant de voir l'effet visuel du thème appliqué.

Ce paquet fournit le programme pour Handy.}


%prep
%setup -q -n awf-extended-%{version}

%build
autoreconf -fi
%configure --enable-only-hdy
%make_build

%install
%make_install
%find_lang %{name} --with-man

%files -f %{name}.lang
%license LICENSE
%doc README.md
%{_bindir}/%{name}
%{_datadir}/applications/%{name}.desktop
%{_datadir}/metainfo/fr.luigifab.awfhdy.metainfo.xml
%{_datadir}/icons/hicolor/*/apps/%{name}.png
%{_datadir}/icons/hicolor/scalable/apps/%{name}.svg
%{_datadir}/bash-completion/completions/%{name}
%{_mandir}/man1/%{name}.1*


%changelog
* Fri Jan 01 2027 Fabrice Creuzot <code@luigifab.fr> - 4.3.0-1
- Initial openSUSE package release




















































