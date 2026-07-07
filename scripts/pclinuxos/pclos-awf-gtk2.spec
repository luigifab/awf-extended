Name:          awf-gtk2
Version:       4.2.0
Release:       %mkrel 1
Summary:       Theme preview application for GTK 2
Summary(fr):   Application d'aperçu de thème pour GTK 2
License:       GPLv3+
Group:         Development/Basic
URL:           https://github.com/luigifab/awf-extended
Source0:       %{url}/archive/v%{version}/%{name}-%{version}.tar.gz

BuildRequires: aspell-fr
BuildRequires: autoconf
BuildRequires: automake
BuildRequires: desktop-file-utils
BuildRequires: libnotify-devel >= 0.7.0
BuildRequires: gcc
BuildRequires: gettext
BuildRequires: gtk2-devel >= 2.24.0
Requires:      gtk2 >= 2.24.0
Requires:      hicolor-icon-theme
Requires:      libnotify >= 0.7.0



%description %{expand:
A widget factory is a theme preview application for GTK and Qt. It
displays the various widget types in a single window allowing to see
the visual effect of the applied theme.

This package provides the program for GTK 2.}

%description -l fr %{expand:
La fabrique à widgets est une application d'aperçu de thème pour GTK
et Qt. Elle affiche les différents types de widgets dans une seule
fenêtre permettant de voir l'effet visuel du thème appliqué.

Ce paquet fournit le programme pour GTK 2.}


%prep
%autosetup -q -n awf-extended-%{version}

%build
autoreconf -fi
%configure --enable-only-gtk2
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

* Mon May 05 2025 Fabrice Creuzot <code@luigifab.fr> - 3.0.0-1
- Initial PCLinuxOS package release













































