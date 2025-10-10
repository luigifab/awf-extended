# AWF - A widget factory (extended)

A widget factory is a theme preview application for GTK. It displays the various widget types provided by GTK in a single window allowing to see the visual effect of the applied theme.

## Screenshots

GTK 2.24 (Pango 1.56)\
[<img alt="Preview with GTK 2 - Main window" src="images/thumbs/gtk2.png?raw=true" width="200" />](images/gtk2.png?raw=true)
[<img alt="Preview with GTK 2 - Main window with menu" src="images/thumbs/gtk2-menu.png?raw=true" width="200" />](images/gtk2-menu.png?raw=true)
[<img alt="Preview with GTK 2 - RTL Main window with menu" src="images/thumbs/gtk2-rtl-menu.png?raw=true" width="200" />](images/gtk2-rtl-menu.png?raw=true)
[<img alt="Preview with GTK 2 - RTL Main window" src="images/thumbs/gtk2-rtl.png?raw=true" width="200" />](images/gtk2-rtl.png?raw=true)

GTK 3.24-classic (Pango 1.56)\
[<img alt="Preview with GTK 3 - Main window" src="images/thumbs/gtk3.png?raw=true" width="200" />](images/gtk3.png?raw=true)
[<img alt="Preview with GTK 3 - Main window with menu" src="images/thumbs/gtk3-menu.png?raw=true" width="200" />](images/gtk3-menu.png?raw=true)
[<img alt="Preview with GTK 3 - CSD main window" src="images/thumbs/gtk3-csd.png?raw=true" width="200" />](images/gtk3-csd.png?raw=true)
[<img alt="Preview with GTK 3 - Main window with plus button" src="images/thumbs/gtk3-plus.png?raw=true" width="200" />](images/gtk3-plus.png?raw=true)

GTK 4.12..4.20-classic (Pango 1.56)\
[<img alt="Preview with GTK 4 - Main window" src="images/thumbs/gtk4.png?raw=true" width="200" />](images/gtk4.png?raw=true)
[<img alt="Preview with GTK 4 - Main window with menu" src="images/thumbs/gtk4-menu.png?raw=true" width="200" />](images/gtk4-menu.png?raw=true)

GTK 5.0 (Pango 1.56)\
_GtkWindow will be probably deprecated... lol_

Theme used for the screenshots is available [here](https://github.com/luigifab/human-theme).

## Tricks

* Some options are available from command line (read `-h`, `--help` or man page).
* Options menu allow to display some standard dialogs.
* System and user themes menu allow to set current theme.
* Text direction menu allow to change text direction (LTR/RTL).
* Info toolbar button allow to display a notification.
* Plus/minus toolbar buttons allow to show or hide: notebooks arrows, marks on progress bars and scales...
* Refresh toolbar button and refresh menu item allow to reload the current theme (like `SIGHUP` signal).
* Menu keyboard shortcuts can be updated on hover (GTK 2.24 and 3.x, *gtk-can-change-accels*).
* Notebooks tabs are scrollable (GTK 3.x and 4.x, *gtk-scroll-tabs*, like with GTK 2.24).
* With Ubuntu, menu keyboard shortcuts can also be updated on hover with: `UBUNTU_MENUPROXY= awf-gtk3`
* Use `GTK_CSD=1` to enable CSD window
* Use `GTK_OVERLAY_SCROLLING=0` to set scrollbars always visible

## Installation

It require **GTK 2.24** or **GTK 3.0+** *(including 3.24)* or **GTK 4.0+** *(including 4.20)*, *GLIB 2.28+*, *libnotify 0.7+*.

#### Installation for Debian, Devuan, Ubuntu, Trisquel, Linux Mint, MX Linux

* `sudo apt install awf-gtk2 awf-gtk3 awf-gtk4`

#### Installation for Fedora, OpenMandriva

* `sudo dnf install awf-gtk2 awf-gtk3 awf-gtk4`

#### Installation for openSUSE

* `sudo zypper install awf-gtk2 awf-gtk3 awf-gtk4`

#### Installation for Mageia

* `sudo urpmi awf-extended-gtk2 awf-extended-gtk3 awf-extended-gtk4`

#### Building from source

* To compile with all available major versions of GTK run: `build.sh`
* To compile and create DEB packages for Debian & Ubuntu run: `scripts/debian[-gtkx]/deb.sh`
* To compile and create RPM packages for Fedora run: `scripts/fedora/rpm-gtkx.sh`
* To compile and create RPM packages for Mageia run: `scripts/mageia/rpm-gtkx.sh`
* To compile and create RPM packages for openSUSE run: `scripts/opensuse/rpm-gtkx.sh`
* To compile and create RPM packages for OpenMandriva run: `scripts/openmandriva/rpm-gtkx.sh`

#### Alternative installation for Debian, Devuan, Ubuntu, Trisquel, Linux Mint, MX Linux

```bash
# PPA: https://launchpad.net/~luigifab/+archive/ubuntu/packages
# from Debian 12 you can use noble/plucky/questing (unix.stackexchange.com/a/669008/364800)
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
sudo apt install awf-gtk2 awf-gtk3 awf-gtk4
# or
sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys FFE5BD439356DF7D
echo "deb http://ppa.launchpad.net/luigifab/packages/ubuntu focal main" | sudo tee -a /etc/apt/sources.list
sudo apt update
sudo apt install awf-gtk2 awf-gtk3 awf-gtk4
# or
sudo wget -O /etc/apt/trusted.gpg.d/luigifab.gpg https://www.luigifab.fr/apt.gpg
echo "deb http://ppa.launchpad.net/luigifab/packages/ubuntu focal main" | sudo tee -a /etc/apt/sources.list
sudo apt update
sudo apt install awf-gtk2 awf-gtk3 awf-gtk4
# or
wget -qO - https://www.luigifab.fr/apt.gpg | sudo gpg --dearmor -o /etc/apt/trusted.gpg.d/luigifab.gpg
echo "deb http://ppa.launchpad.net/luigifab/packages/ubuntu focal main" | sudo tee -a /etc/apt/sources.list
sudo apt update
sudo apt install awf-gtk2 awf-gtk3 awf-gtk4

# sha256sum /etc/apt/trusted.gpg.d/luigifab.gpg
578c89a677048e38007462d543686b53587efba9f93814601169253c45ff9213
# apt-key list
/etc/apt/trusted.gpg.d/luigifab.gpg
pub   rsa4096 2020-10-31 [SC]
      458B 0C46 D024 FD8C B8BC  99CD FFE5 BD43 9356 DF7D
```

## Known issues

#### GTK 4

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

## Customize

Use `~/.config/gtk-3.0/gtk.css` and `~/.config/gtk-4.0/gtk.css` files.

## Dev

To reload theme when source files change, you can use [Entr](https://github.com/eradman/entr) with the `SIGHUP` signal:
```
sudo apt install entr  or  sudo dnf install entr  or  sudo zypper install entr  or  ...
ls ~/.themes/yourtheme/gtk-3*/*.css | entr killall -s SIGHUP awf-gtk3
```

## Copyright

- Current version: 3.2.0 (10/10/2025)
- Compatibility: GTK 2.24 / 3.0..3.24 / 4.0..4.20
- Links: [luigifab.fr](https://www.luigifab.fr/gtk/awf-extended) - [github.com](https://github.com/luigifab/awf-extended) - [ppa/dpa](https://launchpad.net/~luigifab/+archive/ubuntu/packages)

This program is provided under the terms of the **GNU GPLv3+** license.\
If you like, take some of your time to improve the translations, go to https://bit.ly/2HyCCEc.

## Packages in official distros repositories

[![Packages status](https://repology.org/badge/vertical-allrepos/awf-widget-factory.svg?header=awf-gtk&minversion=2.0.0&columns=3)](https://repology.org/project/awf-widget-factory/versions)

## Credits

Forked from [awf](https://github.com/valr/awf) by Valère Monseur (valr).
