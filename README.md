# AWF - A widget factory (extended)

A widget factory is a theme preview application for GTK and Qt. It displays the various widget types in a single window allowing to see the visual effect of the applied theme.

## Screenshots

GTK 2.24 (Pango 1.57)\
[<img alt="Preview with GTK 2 - Main window" src="images/thumbs/gtk2.png?raw=true" width="200" />](images/gtk2.png?raw=true)
[<img alt="Preview with GTK 2 - Main window with menu" src="images/thumbs/gtk2-menu.png?raw=true" width="200" />](images/gtk2-menu.png?raw=true)
[<img alt="Preview with GTK 2 - RTL Main window with menu" src="images/thumbs/gtk2-rtl-menu.png?raw=true" width="200" />](images/gtk2-rtl-menu.png?raw=true)
[<img alt="Preview with GTK 2 - RTL Main window" src="images/thumbs/gtk2-rtl.png?raw=true" width="200" />](images/gtk2-rtl.png?raw=true)

GTK 3.24-classic (Pango 1.57)\
[<img alt="Preview with GTK 3 - Main window" src="images/thumbs/gtk3.png?raw=true" width="200" />](images/gtk3.png?raw=true)
[<img alt="Preview with GTK 3 - Main window with menu" src="images/thumbs/gtk3-menu.png?raw=true" width="200" />](images/gtk3-menu.png?raw=true)
[<img alt="Preview with GTK 3 - CSD main window" src="images/thumbs/gtk3-csd.png?raw=true" width="200" />](images/gtk3-csd.png?raw=true)
[<img alt="Preview with GTK 3 - Main window with plus button" src="images/thumbs/gtk3-plus.png?raw=true" width="200" />](images/gtk3-plus.png?raw=true)

GTK 4.12..4.23-classic (Pango 1.57)\
[<img alt="Preview with GTK 4 - Main window" src="images/thumbs/gtk4.png?raw=true" width="200" />](images/gtk4.png?raw=true)
[<img alt="Preview with GTK 4 - Main window with menu" src="images/thumbs/gtk4-menu.png?raw=true" width="200" />](images/gtk4-menu.png?raw=true)
[<img alt="Preview with GTK 4 - RTL Main window with menu" src="images/thumbs/gtk4-rtl-menu.png?raw=true" width="200" />](images/gtk4-rtl-menu.png?raw=true)
[<img alt="Preview with GTK 4 - RTL Main window" src="images/thumbs/gtk4-rtl.png?raw=true" width="200" />](images/gtk4-rtl.png?raw=true)

GTK 5.0 (Pango 1.57)\
_GtkWindow will be probably deprecated... lol_

Qt 5.15\
[<img alt="Preview with Qt 5 - Main window" src="images/thumbs/qt5.png?raw=true" width="200" />](images/qt5.png?raw=true)
[<img alt="Preview with Qt 5 - Main window with menu" src="images/thumbs/qt5-menu.png?raw=true" width="200" />](images/qt5-menu.png?raw=true)
[<img alt="Preview with Qt 5 - RTL Main window with menu" src="images/thumbs/qt5-rtl-menu.png?raw=true" width="200" />](images/qt5-rtl-menu.png?raw=true)
[<img alt="Preview with Qt 5 - RTL Main window" src="images/thumbs/qt5-rtl.png?raw=true" width="200" />](images/qt5-rtl.png?raw=true)

Qt 6.10\
[<img alt="Preview with Qt 6 - Main window" src="images/thumbs/qt6.png?raw=true" width="200" />](images/qt6.png?raw=true)
[<img alt="Preview with Qt 6 - Main window with menu" src="images/thumbs/qt6-menu.png?raw=true" width="200" />](images/qt6-menu.png?raw=true)
[<img alt="Preview with Qt 6 - RTL Main window with menu" src="images/thumbs/qt6-rtl-menu.png?raw=true" width="200" />](images/qt6-rtl-menu.png?raw=true)
[<img alt="Preview with Qt 6 - RTL Main window" src="images/thumbs/qt6-rtl.png?raw=true" width="200" />](images/qt6-rtl.png?raw=true)

Theme used for the screenshots is available [here](https://github.com/luigifab/human-theme).

## Tricks

* Some options are available from the command line (see `-h`, `--help`, or the man page)
* The _Options_ menu allows you to display some standard dialogs
* The _System_ and _User Themes_ menu allows you to set the current theme
* The _Text Direction_ menu allows you to change the text direction (LTR/RTL)
* The _Info_ toolbar button allows you to display a notification
* The _Plus/Minus_ toolbar buttons allow you to show/hide notebook arrows, marks on progress bars and scales...
* The _Refresh_ toolbar button and menu item allow you to reload the current theme (like the `SIGHUP` signal)
* Notebook tabs are scrollable (GTK 3.x & 4.x, *gtk-scroll-tabs*, like with GTK 2.24 + Qt 5.x & 6.x)
* Menu keyboard shortcuts can be updated on hover (GTK 2.24 & 3.x + Qt 5.x & 6.x, *gtk-can-change-accels*)
* Use `UBUNTU_MENUPROXY=` on Ubuntu to allow updating menu keyboard shortcuts on hover
* Use `AWF_DEBUG=1` and `AWF_TRACE=1` to enable some debug messages
* Use `AWF_TEAROFF=1` to add a tear-off item to the Options menu (GTK 2.24 & 3.x + Qt 5.x & 6.x)
* Use `GTK_OVERLAY_SCROLLING=0` to make scrollbars always visible (GTK 3.16+ & 4.x)
* Use `GTK_CSD=1` to enable CSD windows (GTK 3.12+ & 4.x)

## Broadway

Start the server with `broadwayd &` and run `GDK_BACKEND=broadway awf-gtk3`, then go to http://localhost:8080/ (*libgtk-3-bin*).

## Installation

For GTK, it requires **GTK 2.24** or **GTK 3.0+** *(including 3.24)* or **GTK 4.0+** *(including 4.23)*, *GLIB 2.28+*, *libnotify 0.7+*.

For Qt, it requires **Qt 5.0+** *(including 5.15)* or **Qt 6.0+** *(including 6.11)*, *[GlobalQSS](https://github.com/luigifab/globalqss)* for theme support.

#### Installation for Debian, Devuan, Ubuntu, Trisquel, Linux Mint, MX Linux

* `sudo apt install awf-gtk2 awf-gtk3 awf-gtk4 awf-qt5 awf-qt6`

#### Installation for Fedora

* `sudo dnf install awf-gtk2 awf-gtk3 awf-gtk4 awf-qt5 awf-qt6`

#### Installation for openSUSE

* `sudo zypper install awf-gtk2 awf-gtk3 awf-gtk4 awf-qt5 awf-qt6`

#### Installation for Mageia

* `sudo urpmi awf-extended-gtk2 awf-extended-gtk3 awf-extended-gtk4 awf-extended-qt5 awf-extended-qt6`

#### Installation with MSYS2

* `sudo pacman -S awf-gtk2 awf-gtk3 awf-gtk4 awf-qt5 awf-qt6`

#### Building from source

* To compile with all available major versions of GTK and Qt available run: `build.sh`
* To compile and create DEB packages for Debian & Ubuntu run: `scripts/debian-[gtkx|qtx]/deb.sh`
* To compile and create RPM packages for Fedora run: `scripts/fedora/rpm-[gtkx|qtx].sh`
* To compile and create RPM packages for Mageia run: `scripts/mageia/rpm-[gtkx|qtx].sh`
* To compile and create RPM packages for openSUSE run: `scripts/opensuse/rpm-[gtkx|qtx].sh`
* To compile and create EXE for Windows (XP) run: `scripts/windows/zip.sh`

#### Alternative installation for Debian, Devuan, Ubuntu, Trisquel, Linux Mint, MX Linux

```bash
# PPA: https://launchpad.net/~luigifab/+archive/ubuntu/packages
# from Debian 12 you can use noble/questing (unix.stackexchange.com/a/669008/364800)
#     Debian: focal for 10/buster, jammy for 11/bullseye, noble for 12/bookworm,
#              plucky for 13/trixie, questing for 14/forky and 15/duke
#     Devuan: focal for 3/beowulf, jammy for 4/chimaera, noble for 5/daedalus,
#              plucky for 6/excalibur, questing for 7/freia and 8/gryphon and ceres
# Linux Mint: focal for 20.x and 4/debbie, jammy for 21.x and 5/elsie,
#              noble for 22.x and 6/faye, plucky for 7/gigi
#   MX Linux: focal for 19.x, jammy for 21.x, noble for 23.x, questing for 25.x
#   Trisquel: focal for nabia, jammy for aramo
# Kali Linux: questing

sudo add-apt-repository ppa:luigifab/packages
sudo apt update
sudo apt install awf-gtk2 awf-gtk3 awf-gtk4 awf-qt5 awf-qt6
# or
sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys FFE5BD439356DF7D
echo "deb http://ppa.launchpad.net/luigifab/packages/ubuntu focal main" | sudo tee -a /etc/apt/sources.list
sudo apt update
sudo apt install awf-gtk2 awf-gtk3 awf-gtk4 awf-qt5 awf-qt6
# or
sudo wget -O /etc/apt/trusted.gpg.d/luigifab.gpg https://www.luigifab.fr/apt.gpg
echo "deb http://ppa.launchpad.net/luigifab/packages/ubuntu focal main" | sudo tee -a /etc/apt/sources.list
sudo apt update
sudo apt install awf-gtk2 awf-gtk3 awf-gtk4 awf-qt5 awf-qt6
# or
wget -qO - https://www.luigifab.fr/apt.gpg | sudo gpg --dearmor -o /etc/apt/trusted.gpg.d/luigifab.gpg
echo "deb http://ppa.launchpad.net/luigifab/packages/ubuntu focal main" | sudo tee -a /etc/apt/sources.list
sudo apt update
sudo apt install awf-gtk2 awf-gtk3 awf-gtk4 awf-qt5 awf-qt6

# ... and for full installation
sudo apt install qt5-gtk-platformtheme qt5-style-globalqss qttranslations5-l10n qt6-gtk-platformtheme qt6-style-globalqss qt6-svg-plugins qt6-translations-l10n libnotify-bin

# sha256sum /etc/apt/trusted.gpg.d/luigifab.gpg
578c89a677048e38007462d543686b53587efba9f93814601169253c45ff9213
# apt-key list
/etc/apt/trusted.gpg.d/luigifab.gpg
pub   rsa4096 2020-10-31 [SC]
      458B 0C46 D024 FD8C B8BC  99CD FFE5 BD43 9356 DF7D
```

## Known issues

#### GTK 3

For better results, use gtk3-classic.

#### GTK 4

For better results, use gtk4-classic.

If font rendering is bad, try to add in `~/.config/gtk-4.0/settings.ini`:

```
[Settings]
gtk-font-rendering=manual
gtk-hint-font-metrics=1
gtk-xft-hintstyle=hintfull
gtk-xft-antialias=0
gtk-xft-hinting=1
```

#### GTK 5

From [migrating guide](https://docs.gtk.org/gtk4/migrating-4to5.html#non-standard-css-extensions-are-going-away): _non-standard CSS extensions are going away [...] @define-color should be replaced [...] the color functions can all be replaced by combinations of calc() and color-mix()_.

I think it would be nice to create a patch to fix this GTK regression.

#### Qt 5 & 6

Not everything is working yet.

On Fedora with Qt 5, the GTK 3 platform theme _(qt5-qtbase-gui)_ works better than on Debian _(qt5-gtk-platformtheme)_, but the fonts remain blurry, see [bug 2459509](https://bugzilla.redhat.com/show_bug.cgi?id=2459509).

## Customize

For GTK, use `~/.config/gtk-3.0/gtk.css` and `~/.config/gtk-4.0/gtk.css` files.

For Qt, with [GlobalQSS](https://github.com/luigifab/globalqss), use `~/.config/qt5/qt.qss` and `~/.config/qt6/qt.qss` files.

```css
#AwfMainWindow { }
#AwfDialogWindow { }
AwfTreeView { qproperty-columnWidths:"1,2,3,4,5,6,7,8,9,10,11"; /* qt */ }
.awf-cheatcode-colorbtn { background:red; /* qt */ }
.awf-cheatcode-fontbtn { background:red; /* qt */ }
.awf-cheatcode-filebtn { background:red; /* qt + gtk 4 */ }
.awf-cheatcode-folderbtn { background:red; /* qt + gtk 4 */ }
```

## Dev

To reload theme when source files change, you can use [Entr](https://github.com/eradman/entr) with the `SIGHUP` signal:
```
sudo apt install entr  or  sudo dnf install entr  or  sudo zypper install entr  or  ...
ls ~/.themes/yourtheme/gtk-3*/*.css | entr killall -s SIGHUP awf-gtk3
ls ~/.themes/yourtheme/qt6/*.qss | entr killall -s SIGHUP awf-qt6
```

## Copyright

- Current version: 4.1.0 (05/05/2026)
- Compatibility: GTK 2.24 / 3.0..3.24 / 4.0..4.23, Qt 5.0..5.15 / 6.0..6.11
- Links: [luigifab.fr](https://www.luigifab.fr/gtkqt/awf-extended) - [github.com](https://github.com/luigifab/awf-extended) - [ppa/dpa](https://launchpad.net/~luigifab/+archive/ubuntu/packages)

This program is provided under the terms of the **GNU GPLv3+** license.\
If you like, take some of your time to improve the translations, go to https://bit.ly/2HyCCEc.

## Packages in official distros repositories

[![Packages status](https://repology.org/badge/vertical-allrepos/awf-widget-factory.svg?header=awf-gtk+awf-qt&minversion=2.0.0&columns=3)](https://repology.org/project/awf-widget-factory/versions)

## Credits

Forked from [awf](https://github.com/valr/awf) by Valère Monseur (valr).
