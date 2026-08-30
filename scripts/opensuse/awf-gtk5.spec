Name:          awf-gtk5
Version:       4.3.0
Release:       0
Summary:       Theme preview application for GTK 5
Summary(fr):   Application d'aperçu de thème pour GTK 5
License:       GPL-3.0-or-later
URL:           https://github.com/luigifab/awf-extended
Source0:       %{url}/archive/v%{version}/%{name}-%{version}.tar.gz

BuildRequires: aspell-fr
BuildRequires: autoconf
BuildRequires: automake
BuildRequires: desktop-file-utils
BuildRequires: libnotify-devel >= 0.7.0
BuildRequires: gcc
BuildRequires: gettext
BuildRequires: gtk5-devel
Requires:      gtk5
Requires:      hicolor-icon-theme
Requires:      libnotify >= 0.7.0




%description %{expand:
A widget factory is a theme preview application for GTK and Qt. It
displays the various widget types in a single window allowing to see
the visual effect of the applied theme.

This package provides the program for GTK 5.}

%description -l fr %{expand:
La fabrique à widgets est une application d'aperçu de thème pour GTK
et Qt. Elle affiche les différents types de widgets dans une seule
fenêtre permettant de voir l'effet visuel du thème appliqué.

Ce paquet fournit le programme pour GTK 5.}


%prep
%setup -q -n awf-extended-%{version}

%build
autoreconf -fi
%configure --enable-only-gtk5
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




















































