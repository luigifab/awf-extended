/**
 * Forked  M/10/03/2020
 * Updated J/02/07/2026
 *
 * Copyright 2020-2026 | Fabrice Creuzot (luigifab) <code~luigifab~fr>
 * https://github.com/luigifab/awf-extended
 * https://www.luigifab.fr/gtkqt/awf-extended
 *
 * Forked from
 *  Copyright 2011-2017 | Valère Monseur (valr) <valere.monseur~ymail~com>
 *  https://github.com/valr/awf
 *
 * Forked from
 *  AWF is originally based on the code from The Widget Factory
 *  created by Richard Stellingwerff <remenic~gmail~com>
 *
 * This program is free software, you can redistribute it or modify
 * it under the terms of the GNU General Public License (GPL) as published
 * by the free software foundation, either version 3 of the license, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but without any warranty, without even the implied warranty of
 * merchantability or fitness for a particular purpose. See the
 * GNU General Public License (GPL) for more details.
 *
 *
 * Translations update:
 *  https://github.com/qt/qttranslations/blob/v6.11.0/translations/qtbase_fr.ts
 *  xgettext --keyword=_app -d awf -o src/awf.pot -k_ -s src/awf-*.c*
 *  msgmerge src/po/fr.po src/awf.pot -o src/po/fr.po
 *  msgfmt src/po/fr.po -o src/fr/LC_MESSAGES/awf.mo
 *
 * Tested with build.sh (via VirtualBox 7) with:
 *  Debian Testing 64                  (1536 MB) Qt 5.15/6.10
 *  Fedora Rawhide 64                  (1536 MB) Qt 5.15/6.11
 *  Ubuntu 26.04 Resolute Raccoon 64   (4096 MB) Qt 5.15/6.10
 *  Ubuntu 25.10 Questing Quokka 64    (4096 MB) Qt 5.15/6.9
 *  Ubuntu 25.04 Plucky Puffin 64      (4096 MB) Qt 5.15/6.8
 *  Ubuntu 24.10 Oracular Oriole 64    (4096 MB) Qt 5.15/6.6
 *  Ubuntu 24.04 Noble Numbat 64       (4096 MB) Qt 5.15/6.4
 *  Ubuntu 23.10 Mantic Minotaur 64    (3072 MB) Qt 5.15/6.4
 *  Ubuntu 23.04 Lunar Lobster 64      (3072 MB) Qt 5.15/6.4
 *  Ubuntu 22.10 Kinetic Kudu 64       (2176 MB) Qt 5.15/6.3
 *  Windows XP SP3 MinGW/msys          (2048 MB) Qt 5.3
 */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#if defined (Q_OS_WIN) || defined (_WIN32)
#include <functional>
#include <windows.h>
#include <QScreen>
#endif
#include <QAction>
#include <QActionGroup>
#include <QApplication>
#include <QButtonGroup>
#include <QCalendarWidget>
#include <QCheckBox>
#include <QClipboard>
#include <QColorDialog>
#include <QComboBox>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QDir>
#include <QDoubleSpinBox>
#include <QFileDialog>
#include <QFontComboBox>
#include <QFontDatabase>
#include <QFontDialog>
#include <QFrame>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QIcon>
#include <QKeyEvent>
#include <QKeySequence>
#include <QLabel>
#include <QLibraryInfo>
#include <QLineEdit>
#include <QLocale>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QObject>
#include <QPageSetupDialog>
#include <QPainter>
#include <QPrintDialog>
#include <QPrinter>
#include <QProgressBar>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QRadioButton>
#include <QSizePolicy>
#include <QSlider>
#include <QSpinBox>
#include <QSplitter>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QStandardPaths>
#include <QStatusBar>
#include <QString>
#include <QStyle>
#include <QStyledItemDelegate>
#include <QTabWidget>
#include <QTextEdit>
#include <QTextStream>
#include <QTime>
#include <QTimer>
#include <QToolBar>
#include <QToolButton>
#include <QTranslator>
#include <QTreeView>
#include <QVBoxLayout>
#include <QWidget>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <getopt.h>
#include <locale.h>
#include <libintl.h>
#if defined (Q_OS_UNIX)
#include <unistd.h>
#endif
#pragma GCC diagnostic pop

#define GETTEXT_PACKAGE "awf-qt6"

#define AWF_OPEN QStringLiteral("<AWF>/Test/Open")
#define AWF_SAVE QStringLiteral("<AWF>/Test/Save")
#define AWF_REFR QStringLiteral("<AWF>/Test/Refresh")
#define AWF_RECE QStringLiteral("<AWF>/Test/Recent")
#define AWF_CALE QStringLiteral("<AWF>/Test/Calendar")
#define AWF_SCAL QStringLiteral("<AWF>/Test/Scales")
#define AWF_PROP QStringLiteral("<AWF>/Test/Properties")
#define AWF_PRSE QStringLiteral("<AWF>/Test/PrintSetup")
#define AWF_PRIN QStringLiteral("<AWF>/Test/Print")
#define AWF_MCUT QStringLiteral("<AWF>/Test/More/Cut")
#define AWF_MCOP QStringLiteral("<AWF>/Test/More/Copy")
#define AWF_MPAS QStringLiteral("<AWF>/Test/More/Paste")
#define AWF_CLOS QStringLiteral("<AWF>/Test/Close")
#define AWF_QUIT QStringLiteral("<AWF>/Test/Quit")
#define AWF_INSP QStringLiteral("<AWF>/Test/Inspector")
#define AWF_ABOU QStringLiteral("<AWF>/Test/About")

#define AWF_ACCEL_OPEN QKeySequence(Qt::CTRL | Qt::Key_O)
#define AWF_ACCEL_SAVE QKeySequence(Qt::CTRL | Qt::Key_S)
#define AWF_ACCEL_REFR QKeySequence(Qt::Key_F5)
#define AWF_ACCEL_RECE QKeySequence()
#define AWF_ACCEL_CALE QKeySequence()
#define AWF_ACCEL_SCAL QKeySequence()
#define AWF_ACCEL_PROP QKeySequence(Qt::ALT | Qt::Key_Return)
#define AWF_ACCEL_PRSE QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_P)
#define AWF_ACCEL_PRIN QKeySequence(Qt::CTRL | Qt::Key_P)
#define AWF_ACCEL_MCUT QKeySequence(Qt::CTRL | Qt::Key_X)
#define AWF_ACCEL_MCOP QKeySequence(Qt::CTRL | Qt::Key_C)
#define AWF_ACCEL_MPAS QKeySequence(Qt::CTRL | Qt::Key_V)
#define AWF_ACCEL_CLOS QKeySequence(Qt::CTRL | Qt::Key_W)
#define AWF_ACCEL_QUIT QKeySequence(Qt::CTRL | Qt::Key_Q)
#define AWF_ACCEL_INSP QKeySequence(Qt::Key_F12)
#define AWF_ACCEL_ABOU QKeySequence(Qt::Key_F1)

// @see https://stackoverflow.com/a/10018581/2980105
#define _app(x) QString::fromUtf8(gettext(x)).replace('_', '&')
#define _qt(y, x) QCoreApplication::translate(y, x)

// global variables
static bool awf_debug = qEnvironmentVariableIsSet("AWF_DEBUG");
static bool awf_trace = qEnvironmentVariableIsSet("AWF_TRACE");
static bool awf_gqss  = false;
constexpr std::nullptr_t null = nullptr;
static QStringList list_system_theme;
static QStringList list_user_theme;
static QMainWindow *window = null;
static QDialog *inspector = null;
static QLineEdit *toolbarentry = null;
static QProgressBar *progress1 = null, *progress2 = null, *progress3 = null, *progress4 = null, *progress8 = null, *progress9 = null;
static QSlider *slider1 = null, *slider2 = null, *slider3 = null, *slider4 = null, *slider5 = null, *slider6 = null, *slider7 = null;
static QTabWidget *notebook1 = null, *notebook2 = null, *notebook3 = null, *notebook4 = null;
static int current_direction    = 0;
static QString current_theme    = "auto";
static QString opt_theme        = "auto";
static QString opt_screenshot   = "";
static QString original_style   = "";
static bool allow_update_values = true;
static bool must_save_accels    = false;

// gtk_style_context_to_string
static QString generateTooltipRecursive(QWidget *widget) {

	if (!widget)
		return "";

	QString tooltip = widget->metaObject()->className();

	if (widget->property("textVisible").isValid())
		tooltip += "[textVisible=bool]";
	if (widget->property("hasMenu").isValid())
		tooltip += "[hasMenu=bool]";
	if (widget->property("isInverted").isValid())
		tooltip += "[isInverted=bool]";

	if (widget->property("hasTicks").isValid())
		tooltip += "[hasTicks=" + widget->property("hasTicks").toString() + "]";

	if (!widget->objectName().isEmpty())
		tooltip += "#" + widget->objectName();
	if (widget->property("class").isValid())
		tooltip += "." + widget->property("class").toString();

	QString style = widget->styleSheet().trimmed();
	if (!style.isEmpty())
		tooltip += "\n" + style;

	for (QObject *child : widget->children()) {
		if (QWidget *childWidget = qobject_cast<QWidget*>(child))
			tooltip += "\n  " + generateTooltipRecursive(childWidget).replace("\n", "\n  ");
	}

	return tooltip;
}

class AwfHBox : public QHBoxLayout {
public:
	using QHBoxLayout::QHBoxLayout;
	void addWidget(QWidget *widget) {
		widget->setToolTip(generateTooltipRecursive(widget));
		QHBoxLayout::addWidget(widget);
	}
};

class AwfVBox : public QVBoxLayout {
public:
	using QVBoxLayout::QVBoxLayout;
	void addWidget(QWidget *widget) {
		widget->setToolTip(generateTooltipRecursive(widget));
		QVBoxLayout::addWidget(widget);
	}
};

class AwfToolBar : public QToolBar {
public:
	using QToolBar::QToolBar;
	QAction* addWidget(QWidget *widget) {
		widget->setToolTip(generateTooltipRecursive(widget));
		return QToolBar::addWidget(widget);
	}

protected:
	void keyPressEvent(QKeyEvent *e) override {
		if ((e->key() == Qt::Key_Return) || (e->key() == Qt::Key_Enter)) {
			if (auto *b = qobject_cast<QAbstractButton*>(focusWidget())) {
				b->click();
				return;
			}
		}
		QToolBar::keyPressEvent(e);
	}
};

// global functions
static QIcon get_icon(QString name);
static void awf_load_theme(QStringList& themes, QString directory);
static void update_text_direction(int direction);
static void update_theme(QString newTheme);
static void update_statusbar(QString message);
static void update_values(QAbstractSlider *range);
static void update_widgets();
static void display_notification();
static bool findAndCheckMenu(QList<QAction*> actions, QString search);
static void on_sighup(int signum);
static bool take_screenshot();
static void create_window();
static void create_widgets(AwfVBox *root);
static void create_toolbar(AwfToolBar *toolbar);
static void create_combos_entries(AwfVBox *root);
static void create_spinbuttons(AwfHBox *root);
static void create_checkbuttons(AwfVBox *root);
static void create_radiobuttons(AwfVBox *root);
static void create_otherbuttons(AwfVBox *root1, AwfHBox *root2, AwfHBox *root3, AwfHBox *root4, AwfHBox *root5);
static void create_progressbars(AwfVBox *root1, AwfHBox *root2, AwfHBox *root3, AwfVBox *root4);
static void create_labels(AwfHBox *root);
static void create_spinners(AwfHBox *root);
static void create_expander(AwfVBox *root);
static void create_frames(AwfHBox *root1, AwfHBox *root2);
static void create_notebooks(AwfHBox *root1, AwfHBox *root2);
static void create_notebook_tab(QTabWidget *notebook, QString text, QWidget *content, bool close);
static void create_treeview(AwfVBox *root);
static void create_sliders(QTabWidget *notebook, QString text, QSlider::TickPosition position);
static QSlider* create_horizontal_slider(int value, bool draw, bool inverted, QSlider::TickPosition position);
static QSlider* create_vertical_slider(int value, bool draw, bool inverted, QSlider::TickPosition position);
static void create_traditional_menubar(QMenuBar *root);
static void accels_load();
static bool accels_change(QObject *obj, QEvent *event);
static void accels_save();
static QAction* create_menuitem_check(QMenu *menu, QString text, bool chk, bool ist, bool dsb);
static QAction* create_menuitem_radio(QMenu *menu, QString text, bool chk, bool ist, bool dsb, QActionGroup *group);
static QAction* create_menuitem(QMenu *menu, QIcon icon, QString text, bool dsb, QKeySequence acl, QString kmp, std::function<void()> function);
static void dialog_open();
static void dialog_save();
static void dialog_message();
static void dialog_page_setup();
static void dialog_print();
static void dialog_about();
static void dialog_inspector();
static void dialog_calendar();
static void dialog_sliders();


// other

class AwfMainWindow : public QMainWindow {
	Q_OBJECT

public:
	bool eventFilter(QObject *obj, QEvent *event) override {
		// disable statusbar update on menubar hover
		if (event->type() == QEvent::StatusTip)
			return true;
		return QMainWindow::eventFilter(obj, event);
	}

protected:
	void changeEvent(QEvent *e) override {
		// check current theme in menus on desktop theme change from globalqss style plugin
		if (qEnvironmentVariableIsSet("GQSS_SIGNAL") && (e->type() == QEvent::StyleChange)) {
			QString newTheme = QString::fromUtf8(qgetenv("GQSS_THEME"));
			if (awf_debug)
				printf("\033[33m[debug]\033[00m SIGNAL_theme_update: %s\n", newTheme.toUtf8().constData());
			findAndCheckMenu(menuBar()->actions().mid(1), newTheme);
		}
		QMainWindow::changeEvent(e);
	}
};

class AwfTreeView : public QTreeView {
	Q_OBJECT
	Q_PROPERTY(QString columnWidths               READ getColumnWidths               WRITE setColumnWidths)
	Q_PROPERTY(QColor  sortedColumnColor          READ getSortedColumnColor          WRITE setSortedColumnColor)
	Q_PROPERTY(QColor  alternateSortedColumnColor READ getAlternateSortedColumnColor WRITE setAlternateSortedColumnColor)

	int m_sortedColumn = -1;
	QColor m_color;
	QColor m_altColor;

	// to have the same display as awf-gtk - alternateSortedColumnColor does not work
	// AwfTreeView { qproperty-sortedColumnColor:#EEE;  qproperty-alternateSortedColumnColor:#DDD; }
protected:
	void drawRow(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override {
		if (m_color.isValid() && m_altColor.isValid() && (m_sortedColumn >= 0)) {
			QColor c = (index.row() % 2 != 0) ? m_altColor : m_color;
			painter->fillRect(visualRect(index.sibling(index.row(), m_sortedColumn)), c);
		}
		QTreeView::drawRow(painter, option, index);
	}

public:
	explicit AwfTreeView(QWidget* parent = null) : QTreeView(parent) {
		connect(header(), &QHeaderView::sortIndicatorChanged, this, [this](int column, Qt::SortOrder) {
			m_sortedColumn = column;
			viewport()->update();
		});
	}

	QColor getSortedColumnColor() { return m_color; }
	QColor getAlternateSortedColumnColor() { return m_altColor; }
	void setSortedColumnColor(QColor color) { m_color = color; }
	void setAlternateSortedColumnColor(QColor color) { m_altColor = color; }

	// to have the same display as awf-gtk
	// AwfTreeView { qproperty-columnWidths:"10,20..." }
	QString getColumnWidths() {
		QStringList list;
		for (int i = 0; i < 11; ++i)
			list << QString::number(columnWidth(i));
		return list.join(",");
	}

	void setColumnWidths(QString widths) {
		QTimer::singleShot(0, this, [this, widths]() { // QTimer mainly for Qt 6.6/6.9
			QStringList list = widths.split(",", Qt::SkipEmptyParts);
			for (int i = 0; i < list.size() && i < 11; ++i)
				setColumnWidth(i, list[i].trimmed().toInt());
		});
	}
};

class AwfProgressDelegate : public QStyledItemDelegate {
public:
	AwfProgressDelegate(QAbstractItemView* view) : QStyledItemDelegate(view) {
		m_view = view;
		m_pbar = new QProgressBar(m_view->viewport());
		m_pbar->setOrientation(Qt::Horizontal);
		m_pbar->setMinimum(0);
		m_pbar->setMaximum(100);
		m_pbar->setTextVisible(true);
		m_pbar->hide();
	}

	void paint(QPainter *painter, const QStyleOptionViewItem &opt, const QModelIndex &idx) const override {

		opt.widget->style()->drawPrimitive(QStyle::PE_PanelItemViewItem, &opt, painter, opt.widget);

		if (!(opt.state & QStyle::State_Selected)) {
			QColor bg = idx.data(Qt::BackgroundRole).value<QColor>();
			if (bg.isValid())
				painter->fillRect(opt.rect, bg);
		}

		QLocale locale;
		bool isfr = (locale.language() == QLocale::French) && (locale.territory() == QLocale::France);

		QStyleOptionProgressBar option;
		option.initFrom(m_pbar);
		option.rect = opt.rect;
		option.minimum = m_pbar->minimum();
		option.maximum = m_pbar->maximum();
		option.progress = idx.data().toInt();
		option.textVisible = m_pbar->isTextVisible();
		option.text = QString::number(idx.data().toInt()) + (isfr ? " %" : "%");

		option.state |= QStyle::StateFlag::State_Horizontal;
		if (!idx.flags().testFlag(Qt::ItemIsEnabled))
			option.state &= ~QStyle::State_Enabled;
		if (opt.state & QStyle::State_Selected)
			option.state |= QStyle::State_Selected;

		m_pbar->style()->drawControl(QStyle::CE_ProgressBar, &option, painter, m_pbar);
	}

private:
	QAbstractItemView* m_view;
	QProgressBar* m_pbar;
};

class AwfRadioDelegate : public QStyledItemDelegate {
public:
	AwfRadioDelegate(QAbstractItemView* view) : QStyledItemDelegate(view) {
		m_view  = view;
		m_radio = new QRadioButton(m_view->viewport());
		m_radio->hide();
	}

	void paint(QPainter *painter, const QStyleOptionViewItem &opt, const QModelIndex &idx) const override {

		opt.widget->style()->drawPrimitive(QStyle::PE_PanelItemViewItem, &opt, painter, opt.widget);

		if (!(opt.state & QStyle::State_Selected)) {
			QColor bg = idx.data(Qt::BackgroundRole).value<QColor>();
			if (bg.isValid())
				painter->fillRect(opt.rect, bg);
		}

		QStyleOptionButton option;
		option.initFrom(m_radio);
		option.rect = opt.rect;

		option.state |= (idx.data(Qt::CheckStateRole).toInt() == Qt::Checked) ? QStyle::State_On : QStyle::State_Off;
		if (!idx.flags().testFlag(Qt::ItemIsEnabled))
			option.state &= ~QStyle::State_Enabled;
		if (opt.state & QStyle::State_Selected)
			option.state |= QStyle::State_Selected;

		m_radio->style()->drawControl(QStyle::CE_RadioButton, &option, painter, m_radio);
	}

private:
	QAbstractItemView* m_view;
	QRadioButton* m_radio;
};

class AwfShortcutFilter : public QObject {
public:
	explicit AwfShortcutFilter(QObject *parent) : QObject(parent) {}

	bool eventFilter(QObject *obj, QEvent *event) override {
		return accels_change(obj, event) ? true : QObject::eventFilter(obj, event);
	}
};


// run run run

int main(int argc, char **argv) {

	if (awf_trace)
		printf("\033[36m[trace]\033[00m main()\n");

	int opt = 0, status = 0;
	QApplication app(argc, argv);
	awf_gqss = qEnvironmentVariableIsSet("GQSS_SET");

	if (awf_gqss) {

		// load available system themes (/usr/local/share/themes && /usr/share/themes)
		for (QString dir : QStandardPaths::standardLocations(QStandardPaths::GenericDataLocation))
			awf_load_theme(list_system_theme, QDir(dir).filePath("themes"));
		list_system_theme.sort(Qt::CaseInsensitive);
		list_system_theme.push_front("None");

		// load available user themes (HOME/.local/share/themes && HOME/.themes)
		awf_load_theme(list_user_theme, QDir(QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation)).filePath("themes"));
		awf_load_theme(list_user_theme, QDir(QDir::homePath()).filePath(".themes"));
		list_user_theme.sort(Qt::CaseInsensitive);
	}

	// locale
	QString appDir = QCoreApplication::applicationDirPath();
	QLocale::setDefault(QLocale::system());

	QTranslator *qtTr = new QTranslator(qApp);
	if (qtTr->load("qt_" + QLocale::system().name(), QLibraryInfo::path(QLibraryInfo::TranslationsPath)))
		qApp->installTranslator(qtTr);
	else if (qtTr->load("qt_" + QLocale::system().name(), appDir + "/translations"))
		qApp->installTranslator(qtTr);

	QTranslator *qtBaseTr = new QTranslator(qApp);
	if (qtBaseTr->load("qtbase_" + QLocale::system().name(), QLibraryInfo::path(QLibraryInfo::TranslationsPath)))
		qApp->installTranslator(qtBaseTr);
	else if (qtBaseTr->load("qtbase_" + QLocale::system().name(), appDir + "/translations"))
		qApp->installTranslator(qtBaseTr);

	setlocale(LC_ALL, "");
	#if defined (Q_OS_WIN) || defined (_WIN32)
		bindtextdomain(GETTEXT_PACKAGE, (appDir + "/share/locale").toLocal8Bit().constData());
	#endif
	bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
	textdomain(GETTEXT_PACKAGE);

	// init
	static struct option options[] = {
		{"help",        no_argument, null, 'x'},
		{"version",     no_argument, null, 'v'},
		{"list",        no_argument, null, 'l'},
		{"theme",       required_argument, null, 't'},
		{"screenshot",  required_argument, null, 's'},
		{"ltr",         no_argument, null, 'y'},
		{"rtl",         no_argument, null, 'z'},
		{null, 0, null, 0}
	};

	QString cppVersion;
	while ((opt = getopt_long(argc, argv, "hvlt:s:xyz", options, null)) != -1) {
		switch (opt) {
			// --version -v
			case 'v':
				printf("%s\n", VERSION);
				return status;
			// --list -l
			case 'l':
				for (QString theme : list_system_theme)
					printf("%s\n", theme.toUtf8().constData());
				for (QString theme : list_user_theme)
					printf("%s\n", theme.toUtf8().constData());
				return status;
			// --theme <theme> -t <theme>
			case 't':
				if (list_system_theme.contains(optarg) || list_user_theme.contains(optarg))
					opt_theme = optarg;
				break;
			// --screenshot <filename> -s <filename>
			case 's':
				opt_screenshot = optarg;
				break;
			// --ltr
			case 'y':
				current_direction = 1; // Qt::LeftToRight
				break;
			// --rtl
			case 'z':
				current_direction = 2; // Qt::RightToLeft
				break;
			// --help -h
			case 'x':
			case 'h':
			default:
				switch (__cplusplus) {
					case 199711L: cppVersion = "C++98";  break;
					case 201103L: cppVersion = "C++11";  break;
					case 201402L: cppVersion = "C++14";  break;
					case 201703L: cppVersion = "C++17";  break;
					case 202002L: cppVersion = "C++20";  break;
					case 202302L: cppVersion = "C++23";  break;
					default:      cppVersion = "C++ (" + QString::number(__cplusplus) + ")"; break;
				}
				printf("%s\n\n  %s %s\n  %s %s\n  %s %s\n  %s %s\n  %s %s\n  %s %s\n\n%s\n%s\n",
					qPrintable(QString(_app("A widget factory - Qt %1.%2")).arg(QT_VERSION_MAJOR).arg(QT_VERSION_MINOR)),
					"-v            ", qPrintable(_app("Show version number.")),
					"-l            ", qPrintable(_app("List available themes.")),
					"-t <theme>    ", qPrintable(_app("Run with the specified theme.")),
					"-s <filename> ", qPrintable(QString(_app("Run and save a screenshot on %1 (PNG).")).arg("SIGHUP")),
					"--ltr         ", qPrintable(_app("Run with text from left to right (Left-To-Right).")),
					"--rtl         ", qPrintable(_app("Run with text from right to left (Right-To-Left).")),
					qPrintable(QString(_app("compiled in %1 with qt %2.%3.%4")).arg(cppVersion).arg(QT_VERSION_MAJOR).arg(QT_VERSION_MINOR).arg(QT_VERSION_PATCH)),
					qPrintable(QString(_app(" started with qt %1")).arg(qVersion())));
				return status;
		}
	}

	// --rtl via -reverse/--reverse
	if ((current_direction == 0) && (qApp->layoutDirection() == Qt::RightToLeft))
		current_direction = 3;

	// create and show window
	QCommandLineParser parser;
	parser.setApplicationDescription(_app("A widget factory - Qt %1.%2").arg(QT_VERSION_MAJOR).arg(QT_VERSION_MINOR));
	parser.addHelpOption();
	parser.addVersionOption(); // << "v" << "version", _app("Show version number.")));
	parser.addOption(QCommandLineOption(QStringList() << "l" << "list", _app("List available themes.")));
	parser.addOption(QCommandLineOption(QStringList() << "t" << "theme", _app("Run with the specified theme."), "theme"));
	parser.addOption(QCommandLineOption(QStringList() << "s" << "screenshot", QString(_app("Run and save a screenshot on %1 (PNG).").arg("SIGHUP")), "filename"));
	parser.addOption(QCommandLineOption(QStringList() << "y" << "ltr", _app("Run with text from left to right (Left-To-Right).")));
	parser.addOption(QCommandLineOption(QStringList() << "z" << "rtl", _app("Run with text from right to left (Right-To-Left).")));
	parser.process(app);

	create_window();
	return app.exec();
}

static QIcon get_icon(QString name) {

	static const QHash<QString, QStyle::StandardPixmap> map = {
		{"application-exit",   QStyle::SP_DialogCloseButton},
		{"dialog-close",       QStyle::SP_DialogCloseButton},
		{"dialog-information", QStyle::SP_MessageBoxInformation},
		{"document-open",      QStyle::SP_DialogOpenButton},
		{"document-save",      QStyle::SP_DialogSaveButton},
		{"help-about",         QStyle::SP_MessageBoxQuestion},
		{"help-browser",       QStyle::SP_MessageBoxQuestion},
		{"view-refresh",       QStyle::SP_BrowserReload},
		{"window-close",       QStyle::SP_DialogCloseButton},
	};

	QIcon icon = QIcon::fromTheme(name);
	if (icon.isNull())
		icon = qApp->style()->standardIcon(map.value(name, QStyle::SP_FileIcon));

	return icon;
}

static void awf_load_theme(QStringList& themes, QString directory) {

	if (awf_trace)
		printf("\033[36m[trace]\033[00m awf_load_theme(%s)\n", directory.toUtf8().constData());

	QDir dir(directory);
	if (dir.exists()) {

		if (awf_debug)
			printf("\033[33m[debug]\033[00m themes_dir: %s\n", directory.toUtf8().constData());

		QStringList entries = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
		for (QString theme : entries) {
			if (QDir(QDir(dir.filePath(theme)).filePath("qt6")).exists())
				themes.append(theme);
		}
	}
}

static void update_text_direction(int direction) { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m update_text_direction()\n");

	if ((direction == 1) && (qApp->layoutDirection() != Qt::LeftToRight)) {
		current_direction = 1;
		notebook3->setTabPosition(QTabWidget::West);
		notebook4->setTabPosition(QTabWidget::East);
		qApp->setLayoutDirection(Qt::LeftToRight);
		update_theme("refresh");
	}
	else if ((direction == 2) && (qApp->layoutDirection() != Qt::RightToLeft) || (direction == 3)) {
		current_direction = 2;
		notebook3->setTabPosition(QTabWidget::East);
		notebook4->setTabPosition(QTabWidget::West);
		qApp->setLayoutDirection(Qt::RightToLeft);
		update_theme("refresh");
	}
}

static void update_theme(QString newTheme) { // ok

	if (awf_gqss) {

		if (awf_trace)
			printf("\033[36m[trace]\033[00m update_theme(%s)*\n", newTheme.toUtf8().constData());
		if (awf_debug)
			printf("\033[33m[debug]\033[00m update_theme_before: %s » %s\n", current_theme.toUtf8().constData(), newTheme.toUtf8().constData());

		if (newTheme == "refresh") {

			qputenv("GQSS_RELOAD", "yes");
			QApplication::style()->polish(qApp);
			QApplication::processEvents();
			window->adjustSize();

			if (!opt_screenshot.isEmpty()) {
				if (take_screenshot())
					update_statusbar(_app("Theme %1 reloaded, then screenshot saved (%2).").arg(current_theme).arg(opt_screenshot));
				else
					update_statusbar(_app("Theme %1 reloaded (error saving screenshot).").arg(current_theme));
			}
			else {
				update_statusbar(_app("Theme %1 reloaded.").arg(current_theme));
			}

			if (awf_debug)
				printf("\033[33m[debug]\033[00m update_theme_after1: %s\n", current_theme.toUtf8().constData());
		}
		else if (newTheme == "auto") {

			current_theme = QString::fromUtf8(qgetenv("GQSS_THEME"));
			window->adjustSize();

			if (awf_debug)
				printf("\033[33m[debug]\033[00m update_theme_after2: %s\n", current_theme.toUtf8().constData());
		}
		else if (current_theme != newTheme) {

			current_theme = newTheme;

			qputenv("GQSS_RELOAD", "yes");
			qputenv("GQSS_THEME", newTheme.toUtf8());
			if (!qEnvironmentVariableIsSet("GQSS_SIGNAL")) { // useless for changeEvent (notify_updated_gtktheme)
				QApplication::style()->polish(qApp);
				QApplication::processEvents();
			}

			window->adjustSize();
			update_statusbar(_app("Theme %1 loaded.").arg(current_theme));

			if (awf_debug)
				printf("\033[33m[debug]\033[00m update_theme_after3: %s\n", current_theme.toUtf8().constData());
		}

		original_style = "!^!";
	}
}

static void update_statusbar(QString message) { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m update_statusbar(%s)\n", message.toUtf8().constData());

	if (window && window->statusBar()) {

		QStatusBar *statusbar = window->statusBar();
		statusbar->showMessage(QTime::currentTime().toString("HH:mm:ss") + " - " + message, 0);

		QVariantAnimation *anim = new QVariantAnimation(statusbar);
		anim->setStartValue(QColor(255,255,0,255)); // yellow
		anim->setEndValue(window->palette().color(QPalette::Window));
		anim->setDuration(1000);
		QObject::connect(anim, &QVariantAnimation::valueChanged, [statusbar](const QVariant &value) {
			QColor c = value.value<QColor>();
			statusbar->setStyleSheet(QString("background-color:rgba(%1,%2,%3,%4);").arg(c.red()).arg(c.green()).arg(c.blue()).arg(c.alpha()));
		});
		QObject::connect(anim, &QVariantAnimation::finished, [statusbar]() {
			statusbar->setStyleSheet("");
		});
		anim->start(QAbstractAnimation::DeleteWhenStopped);
	}
}

static void update_values(QAbstractSlider *range) { // ok

	if (allow_update_values) {

		// range(0..100)
		allow_update_values = false;
		int value = range->value();
		//if (awf_trace)
		//	printf("\033[36m[trace]\033[00m update_values(%d)*\n", value);

		progress1->setValue(value);
		progress2->setValue(value);
		progress3->setValue(value);
		progress4->setValue(value);
		progress8->setValue(value);
		progress9->setValue(value);

		if (slider1 != range) slider1->setValue(value);
		if (slider2 != range) slider2->setValue(value);
		if (slider3 != range) slider3->setValue(value);
		if (slider4 != range) slider4->setValue(value);
		if (slider5 != range) slider5->setValue(value);
		if (slider6 != range) slider6->setValue(value);
		if (slider7 != range) slider7->setValue(value);

		// text
		progress8->setTextVisible(value > 50);
		progress8->setProperty("textVisible", value > 50);
		progress8->style()->polish(progress8);
		progress8->updateGeometry();

		progress9->setTextVisible(value > 50);
		progress9->setProperty("textVisible", value > 50);
		progress9->style()->polish(progress9);
		progress9->updateGeometry();

		allow_update_values = true;
	}
}

static void update_widgets() { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m update_widgets()\n");

	// function called when user click on [+] toolbar button
	// when toggle = true, the [+] toolbar button is NOT checked
	int width1, width2, height1, height2;
	bool toggle = notebook1->tabBar()->usesScrollButtons();

	// show progressbar in toolbar and statusbar when [+] toolbar button is NOT checked
	if (toggle) {
		qobject_cast<QAction*>(progress8->property("action").value<QObject*>())->setVisible(false);
		progress9->setVisible(false);
		qobject_cast<QAction*>(toolbarentry->property("action").value<QObject*>())->setVisible(false);
	}
	else {
		progress8->setValue(0);
		progress9->setValue(0);
		qobject_cast<QAction*>(progress8->property("action").value<QObject*>())->setVisible(true);
		progress9->setVisible(true);
		qobject_cast<QAction*>(toolbarentry->property("action").value<QObject*>())->setVisible(true);
	}

	// enabled or not
	slider2->setEnabled(toggle);
	slider4->setEnabled(toggle);
	slider6->setEnabled(toggle);
	slider7->setEnabled(toggle);
	progress2->setEnabled(toggle);
	progress4->setEnabled(toggle);

	// text or not
	progress1->setTextVisible(!toggle);
	progress1->setProperty("textVisible", !toggle);
	progress1->style()->polish(progress1);
	progress1->updateGeometry();

	progress2->setTextVisible(!toggle);
	progress2->setProperty("textVisible", !toggle);
	progress2->style()->polish(progress2);
	progress2->updateGeometry();

	progress3->setTextVisible(!toggle);
	progress3->setProperty("textVisible", !toggle);
	progress3->style()->polish(progress3);
	progress3->updateGeometry();

	progress4->setTextVisible(!toggle);
	progress4->setProperty("textVisible", !toggle);
	progress4->style()->polish(progress4);
	progress4->updateGeometry();

	progress8->setTextVisible(false);
	progress8->setProperty("textVisible", false);
	progress8->style()->polish(progress8);
	progress8->updateGeometry();

	progress9->setTextVisible(false);
	progress9->setProperty("textVisible", false);
	progress9->style()->polish(progress9);
	progress9->updateGeometry();

	// scrollable or not
	if (toggle) {
		notebook1->tabBar()->setUsesScrollButtons(false);
		notebook2->tabBar()->setUsesScrollButtons(false);
		notebook3->tabBar()->setUsesScrollButtons(false);
		notebook4->tabBar()->setUsesScrollButtons(false);
		notebook1->setMinimumWidth(width1 = notebook1->tabBar()->sizeHint().width());
		notebook2->setMinimumWidth(width2 = notebook2->tabBar()->sizeHint().width());
		notebook3->setMinimumHeight(height1 = notebook3->tabBar()->sizeHint().height());
		notebook4->setMinimumHeight(height2 = notebook4->tabBar()->sizeHint().height());
	}
	else {
		notebook1->setMinimumWidth(width1 = notebook1->tabBar()->sizeHint().width() / 2);
		notebook2->setMinimumWidth(width2 = notebook2->tabBar()->sizeHint().width() / 2);
		notebook3->setMinimumHeight(height1 = notebook3->tabBar()->sizeHint().height() / 2);
		notebook4->setMinimumHeight(height2 = notebook4->tabBar()->sizeHint().height() / 2);
		notebook1->tabBar()->setUsesScrollButtons(true);
		notebook2->tabBar()->setUsesScrollButtons(true);
		notebook3->tabBar()->setUsesScrollButtons(true);
		notebook4->tabBar()->setUsesScrollButtons(true);
	}

	// auto width and height @todo
	notebook1->updateGeometry();
	notebook2->updateGeometry();
	notebook3->updateGeometry();
	notebook4->updateGeometry();

	QSplitter *hpane, *vpane;
	QWidget *widget = notebook1->parentWidget();
	while (widget) {
		hpane = qobject_cast<QSplitter *>(widget);
		if (hpane)
			break;
		widget = widget->parentWidget();
	}
	hpane->setSizes({qMax(width1, width2), 10000});
	hpane->updateGeometry();

	widget = widget->parentWidget();
	while (widget) {
		vpane = qobject_cast<QSplitter *>(widget);
		if (vpane)
			break;
		widget = widget->parentWidget();
	}
	QList<int> sizes = vpane->sizes();
	sizes[1] = qMax(height1, height2);
	vpane->setSizes(sizes);
	vpane->updateGeometry();

	window->setMinimumHeight(0);
	window->setMinimumWidth(0);
	window->adjustSize();
}

static void display_notification() { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m display_notification()\n");

	#if defined (Q_OS_UNIX)
		signal(SIGCHLD, SIG_IGN);
		if (fork() == 0) {
			execlp("notify-send", "notify-send", "-i", "dialog-information", "-t", "50000", "--action", _qt("QShortcut", "Close").toUtf8().constData(), GETTEXT_PACKAGE, _app("A widget factory is a theme preview application for GTK and Qt. It displays the various widget types in a single window allowing to see the visual effect of the applied theme.").toUtf8().constData(), null);
			_exit(1);
		}
	#endif
}

static bool findAndCheckMenu(QList<QAction*> actions, QString search) { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m findAndCheckMenu()\n");

	for (QAction *action : actions) {
		if (action->menu()) {
			// process submenu
			if (findAndCheckMenu(action->menu()->actions(), search))
				return true;
		}
		else if (action->isEnabled() && (action->text() == search)) {
			// check menuitem
			action->trigger(); // set state checked and activate action
			return true;
		}
	}

	return false;
}

static void on_sighup(int signum) { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m on_sighup()\n");

	QMetaObject::invokeMethod(qApp, [](){ update_theme("refresh"); }, Qt::QueuedConnection);
}

static bool take_screenshot() { // ok (without window borders)

	if (awf_trace)
		printf("\033[36m[trace]\033[00m take_screenshot()\n");

	QPixmap pixmap = window->grab();
	return pixmap.save(opt_screenshot, "PNG", 0); // 0 = 9
}


// layout and widgets

static void create_window() {

	if (awf_trace)
		printf("\033[36m[trace]\033[00m create_window()\n");

	// window
	QApplication::setApplicationName("awf");
	window = new AwfMainWindow;
	window->setWindowTitle(_app("A widget factory - Qt %1.%2").arg(QT_VERSION_MAJOR).arg(QT_VERSION_MINOR));
	window->setObjectName("AwfMainWindow");
	window->installEventFilter(window);

	#if defined (Q_OS_UNIX)
		QApplication::setWindowIcon(QIcon::fromTheme(GETTEXT_PACKAGE));
		window->setWindowIcon(QIcon::fromTheme(GETTEXT_PACKAGE));
	#elif defined (Q_OS_WIN) || defined (_WIN32)
		HICON hIcon = (HICON) LoadImage(GetModuleHandle(nullptr), "IDI_ICON1", IMAGE_ICON, 48, 48, LR_DEFAULTSIZE);
		QPixmap pixmap = QPixmap::fromImage(QImage::fromHICON(hIcon));
		QApplication::setWindowIcon(QIcon(pixmap));
		window->setWindowIcon(QIcon(pixmap));
		DestroyIcon(hIcon);
	#endif

	// theme auto or from command line
	if (awf_gqss)
		update_theme((current_theme == opt_theme) ? current_theme : opt_theme);

	if (current_direction == 0)
		current_direction = (qApp->layoutDirection() == Qt::LeftToRight) ? 1 : 2;

	// layout
	AwfVBox *layout = new AwfVBox;
	QWidget *central = new QWidget;
	window->setCentralWidget(central);
		layout->setSpacing(0);
		layout->setContentsMargins(0,0,0,0);
		create_widgets(layout);
		central->setLayout(layout);

	QMenuBar *menubar = window->menuBar();
	menubar->setContextMenuPolicy(Qt::PreventContextMenu);
	create_traditional_menubar(menubar);

	AwfToolBar *toolbar = new AwfToolBar;
	toolbar->setMovable(false);
	toolbar->setFloatable(false);
	toolbar->setContextMenuPolicy(Qt::PreventContextMenu);
	create_toolbar(toolbar);
	window->addToolBar(toolbar);

	update_statusbar(_app("Theme %1 loaded.").arg(current_theme));
	progress9 = new QProgressBar;
	progress9->setMaximumWidth(140);
	progress9->setFixedHeight(16);
	progress9->setAttribute(Qt::WA_StyledBackground, true); // @todo not working
	progress9->setVisible(false);
	window->statusBar()->addPermanentWidget(progress9);

	QLocale locale;
	if ((locale.language() == QLocale::French) && (locale.territory() == QLocale::France))
		progress9->setFormat("%p %");

	// go go go
	update_text_direction(current_direction);

	#if defined (Q_OS_UNIX)
		if (awf_gqss)
			std::signal(SIGHUP, on_sighup);
	#endif

	window->show();
	window->setAttribute(Qt::WA_DeleteOnClose);
	toolbar->widgetForAction(toolbar->actions().constFirst())->setFocus(Qt::TabFocusReason); // focus on the first toolbar button
	QObject::connect(qApp, &QCoreApplication::aboutToQuit, accels_save);

	#if defined (Q_OS_WIN) || defined (_WIN32)
		window->move(QGuiApplication::primaryScreen()->availableGeometry().center() - window->rect().center());
	#endif
}

static void create_widgets(AwfVBox *root) { // todo

	if (awf_trace)
		printf("\033[36m[trace]\033[00m create_widgets()\n");

	AwfHBox *hboxColumns = new AwfHBox;
	hboxColumns->setSpacing(0);    hboxColumns->setContentsMargins(0,0,0,0);

	AwfVBox *vboxColumn1 = new AwfVBox, *vboxComboEntry = new AwfVBox, *vboxCheck = new AwfVBox, *vboxRadio = new AwfVBox;
	AwfHBox *hboxSpin = new AwfHBox, *hboxCheckRadio = new AwfHBox;
	vboxColumn1->setSpacing(0);    vboxColumn1->setContentsMargins(5,5,5,5);
	vboxComboEntry->setSpacing(3); vboxComboEntry->setContentsMargins(5,5,5,5);
	hboxSpin->setSpacing(0);       hboxSpin->setContentsMargins(5,5,5,5);
	hboxCheckRadio->setSpacing(0); hboxCheckRadio->setContentsMargins(5,5,5,5);
	vboxCheck->setSpacing(0);      vboxCheck->setContentsMargins(0,0,0,0);
	vboxRadio->setSpacing(0);      vboxRadio->setContentsMargins(0,0,0,0);

	AwfVBox *vboxColumn2 = new AwfVBox, *vboxButtons = new AwfVBox;
	AwfHBox *hboxBtns1 = new AwfHBox, *hboxBtns2 = new AwfHBox, *hboxBtns3 = new AwfHBox, *hboxBtns4 = new AwfHBox;
	vboxColumn2->setSpacing(0);    vboxColumn2->setContentsMargins(5,5,5,5);
	vboxButtons->setSpacing(3);    vboxButtons->setContentsMargins(5,5,5,5);
	hboxBtns1->setSpacing(3);      hboxBtns1->setContentsMargins(5,5,5,5);
	hboxBtns2->setSpacing(3);      hboxBtns2->setContentsMargins(5,5,5,5);
	hboxBtns3->setSpacing(3);      hboxBtns3->setContentsMargins(5,5,5,5);
	hboxBtns4->setSpacing(3);      hboxBtns4->setContentsMargins(5,5,5,5);

	AwfVBox *vboxColumn3 = new AwfVBox, *vboxProgress1 = new AwfVBox, *vboxProgress2 = new AwfVBox;
	AwfHBox *hboxProgress1 = new AwfHBox, *hboxProgress2 = new AwfHBox;
	vboxColumn3->setSpacing(0);    vboxColumn3->setContentsMargins(5,5,5,5);
	vboxProgress1->setSpacing(10); vboxProgress1->setContentsMargins(6,6,6,6);
	vboxProgress2->setSpacing(10); vboxProgress2->setContentsMargins(5,5,5,5);
	hboxProgress1->setSpacing(10); hboxProgress1->setContentsMargins(5,5,5,5);
	hboxProgress2->setSpacing(10); hboxProgress2->setContentsMargins(5,5,5,5);

	AwfVBox *vboxColumn4 = new AwfVBox, *vboxOthers = new AwfVBox;
	AwfHBox *hboxLabel = new AwfHBox, *hboxSpinner = new AwfHBox;
	vboxColumn4->setSpacing(0);    vboxColumn4->setContentsMargins(5,5,5,5);
	vboxOthers->setSpacing(3);     vboxOthers->setContentsMargins(5,5,5,5);
	hboxLabel->setSpacing(0);      hboxLabel->setContentsMargins(5,5,5,5);
	hboxSpinner->setSpacing(0);    hboxSpinner->setContentsMargins(5,5,5,5);

	QSplitter *vpane = new QSplitter(Qt::Vertical), *hpane1 = new QSplitter(Qt::Horizontal), *hpane2 = new QSplitter(Qt::Horizontal);
	vpane->setContentsMargins(0,0,0,0);
	hpane1->setContentsMargins(0,0,0,0);
	hpane2->setContentsMargins(0,0,0,0);

	QWidget *wboxFrame1 = new QWidget, *wboxFrame2 = new QWidget, *wboxNotebook1 = new QWidget, *wboxNotebook2 = new QWidget;
	wboxFrame1->setContentsMargins(0,0,0,0);
	wboxFrame2->setContentsMargins(0,0,0,0);
	wboxNotebook1->setContentsMargins(0,0,0,0);
	wboxNotebook2->setContentsMargins(0,0,0,0);

	AwfHBox *hboxFrame1 = new AwfHBox, *hboxFrame2 = new AwfHBox, *hboxNotebook1 = new AwfHBox, *hboxNotebook2 = new AwfHBox;
	hboxFrame1->setSpacing(3);     hboxFrame1->setContentsMargins(10,10,10,10);
	hboxFrame2->setSpacing(3);     hboxFrame2->setContentsMargins(10,10,10,10);
	hboxNotebook1->setSpacing(3);  hboxNotebook1->setContentsMargins(10,10,10,10);
	hboxNotebook2->setSpacing(3);  hboxNotebook2->setContentsMargins(10,10,10,10);

	QFrame *sep1 = new QFrame, *sep2 = new QFrame, *sep3 = new QFrame, *sep4 = new QFrame;
	sep1->setFrameShape(awf_gqss ? QFrame::NoFrame : QFrame::VLine);
	sep1->setFrameShadow(QFrame::Plain);
	sep1->setProperty("class", "separator vertical");
	sep2->setFrameShape(awf_gqss ? QFrame::NoFrame : QFrame::VLine);
	sep2->setFrameShadow(QFrame::Plain);
	sep2->setProperty("class", "separator vertical");
	sep3->setFrameShape(awf_gqss ? QFrame::NoFrame : QFrame::VLine);
	sep3->setFrameShadow(QFrame::Plain);
	sep3->setProperty("class", "separator vertical");
	sep4->setFrameShape(awf_gqss ? QFrame::NoFrame : QFrame::HLine);
	sep4->setFrameShadow(QFrame::Plain);
	sep4->setProperty("class", "separator horizontal");

	// columns layout
	root->addLayout(hboxColumns);

		// column 1
		hboxColumns->addLayout(vboxColumn1);
			vboxColumn1->addLayout(vboxComboEntry);
				create_combos_entries(vboxComboEntry);
			vboxColumn1->addLayout(hboxSpin);
				create_spinbuttons(hboxSpin);
			vboxColumn1->addLayout(hboxCheckRadio);
				hboxCheckRadio->addLayout(vboxCheck);
					create_checkbuttons(vboxCheck);
				hboxCheckRadio->addLayout(vboxRadio);
					create_radiobuttons(vboxRadio);
			vboxColumn1->addStretch();
		hboxColumns->addWidget(sep1);

		// column 2
		hboxColumns->addLayout(vboxColumn2);
			vboxColumn2->addLayout(vboxButtons);
			vboxColumn2->addLayout(hboxBtns1);
			vboxColumn2->addLayout(hboxBtns2);
			vboxColumn2->addLayout(hboxBtns3);
			vboxColumn2->addLayout(hboxBtns4);
				create_otherbuttons(vboxButtons, hboxBtns1, hboxBtns2, hboxBtns3, hboxBtns4);
			vboxColumn2->addStretch();
		hboxColumns->addWidget(sep2);

		// column 3
		hboxColumns->addLayout(vboxColumn3);
			vboxColumn3->addLayout(vboxProgress1);
			vboxColumn3->addLayout(hboxProgress1);
			vboxColumn3->addLayout(hboxProgress2);
			vboxColumn3->addLayout(vboxProgress2);
				create_progressbars(vboxProgress1, hboxProgress1, hboxProgress2, vboxProgress2);
			vboxColumn3->addStretch();
		hboxColumns->addWidget(sep3);

		// column 4
		hboxColumns->addLayout(vboxColumn4);
			vboxColumn4->addLayout(vboxOthers);
				create_treeview(vboxOthers);
				vboxOthers->addLayout(hboxLabel);
					create_labels(hboxLabel);
				vboxOthers->addLayout(hboxSpinner);
					create_spinners(hboxSpinner);
				create_expander(vboxOthers);
			vboxColumn4->addStretch();

	root->addWidget(sep4);

	// paned layout
	root->addWidget(vpane);

		vpane->addWidget(hpane1);

			wboxFrame1->setMinimumHeight(70); // The 70
			wboxFrame1->setLayout(hboxFrame1);
			hpane1->addWidget(wboxFrame1);

			wboxFrame2->setMinimumHeight(70); // The 70
			wboxFrame2->setLayout(hboxFrame2);
			hpane1->addWidget(wboxFrame2);

			create_frames(hboxFrame1, hboxFrame2);

		vpane->addWidget(hpane2);

			//wboxNotebook1->setMinimumHeight(120); // The 120
			wboxNotebook1->setLayout(hboxNotebook1);
			hpane2->addWidget(wboxNotebook1);

			//wboxNotebook2->setMinimumHeight(120); // The 120
			wboxNotebook2->setLayout(hboxNotebook2);
			hpane2->addWidget(wboxNotebook2);

			create_notebooks(hboxNotebook1, hboxNotebook2);
			hpane2->setSizes({wboxNotebook1->sizeHint().width(), 10000});
}

static void create_toolbar(AwfToolBar *toolbar) { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m create_toolbar()\n");

	QToolButton *tool1, *tool2, *tool3, *tool4, *tool5, *tool6, *tool7, *tool8, *tool9;
	QAction *action1, *action2;
	QWidget *spacer;
	QMenu *menu;

	// QToolButton
	tool1 = new QToolButton;
	menu = new QMenu(tool1);
	menu->addAction("Menu item 1");
	menu->addAction("Menu item 2");
	menu->addAction("Menu item 3");
	tool1->setMenu(menu);
	tool1->setIcon(get_icon("document-open"));
	tool1->setPopupMode(QToolButton::MenuButtonPopup);
	tool1->setProperty("hasMenu", true);
	QObject::connect(tool1, &QToolButton::clicked, dialog_open);

	tool2 = new QToolButton;
	tool2->setIcon(get_icon("document-open"));
	tool2->setPopupMode(QToolButton::MenuButtonPopup);
	tool2->setProperty("hasMenu", true);
	tool2->setEnabled(false);

	tool3 = new QToolButton;
	tool3->setIcon(get_icon("document-save"));
	QObject::connect(tool3, &QToolButton::clicked, dialog_save);

	tool4 = new QToolButton;
	tool4->setIcon(get_icon("view-refresh"));
	tool4->setEnabled(awf_gqss);
	QObject::connect(tool4, &QToolButton::clicked, [](){ on_sighup(0); });

	tool5 = new QToolButton;
	tool5->setIcon(get_icon("camera-photo"));
	tool5->setEnabled(opt_screenshot.isEmpty() ? false : true);
	QObject::connect(tool5, &QToolButton::clicked, take_screenshot);

	tool6 = new QToolButton;
	tool6->setIcon(get_icon("dialog-information"));
	QObject::connect(tool6, &QToolButton::clicked, display_notification);
	#if defined (Q_OS_WIN) || defined (_WIN32)
		tool6->setEnabled(false);
	#endif

	tool7 = new QToolButton;
	tool7->setCheckable(true);
	tool7->setChecked(true);
	tool7->setIcon(get_icon("list-add"));
	QObject::connect(tool7, &QToolButton::clicked, update_widgets);

	tool8 = new QToolButton;
	tool8->setCheckable(true);
	tool8->setChecked(false);
	tool8->setIcon(get_icon("list-remove"));
	QObject::connect(tool8, &QToolButton::clicked, update_widgets);

	tool9 = new QToolButton;
	tool9->setCheckable(true);
	tool9->setChecked(false);
	tool9->setIcon(get_icon("window-close"));
	tool9->setEnabled(false);

	toolbarentry = new QLineEdit;
	toolbarentry->setPlaceholderText("...");
	toolbarentry->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

	spacer = new QWidget;
	spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

	progress8 = new QProgressBar;
	progress8->setValue(0);
	progress8->setOrientation(Qt::Horizontal);
	progress8->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

	QLocale locale;
	if ((locale.language() == QLocale::French) && (locale.territory() == QLocale::France))
		progress8->setFormat("%p %");

	// layout
	toolbar->addWidget(tool1);
	toolbar->addWidget(tool2);
	toolbar->addWidget(tool3);
	toolbar->addSeparator();
	toolbar->addWidget(tool4);
	toolbar->addWidget(tool5);
	toolbar->addWidget(tool6);
	toolbar->addSeparator();
	toolbar->addWidget(tool7);
	toolbar->addWidget(tool8);
	toolbar->addWidget(tool9);
	action1 = toolbar->addWidget(toolbarentry);
	toolbar->addWidget(spacer);
	action2 = toolbar->addWidget(progress8);

	// links
	action1->setVisible(false);
	toolbarentry->setProperty("action", QVariant::fromValue<QObject*>(action1));

	action2->setVisible(false);
	progress8->setProperty("action", QVariant::fromValue<QObject*>(action2));
}

static void create_combos_entries(AwfVBox *root) { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m create_combos_entries()\n");

	QComboBox *combo1, *combo2, *combo3, *combo4;
	QLineEdit *entry1, *entry2, *entry3, *entry4;

	// QComboBox
	combo1 = new QComboBox;
	combo1->setEditable(true);
	combo1->addItem("Combo box entry 1");
	combo1->addItem("Combo box entry 2");

	combo2 = new QComboBox;
	combo2->setEditable(true);
	combo2->addItem("Combo box entry 1");
	combo2->addItem("Combo box entry 2");
	combo2->setDisabled(true);

	combo3 = new QComboBox;
	combo3->addItem("Combo box 1");
	combo3->addItem("Combo box 2");

	combo4 = new QComboBox;
	combo4->addItem("Combo box 1");
	combo4->addItem("Combo box 2");
	combo4->setDisabled(true);

	// QLineEdit
	entry1 = new QLineEdit;
	entry1->setText("Entry");
	entry1->setPlaceholderText("Placeholder");

	entry2 = new QLineEdit;
	entry2->setText("Entry");
	entry2->setEnabled(false);

	entry3 = new QLineEdit;
	entry3->setText("Entry");
	entry3->setClearButtonEnabled(true);
	entry3->setPlaceholderText("Placeholder");

	entry4 = new QLineEdit;
	entry4->setText("Entry");
	entry4->setClearButtonEnabled(true);
	entry4->setEnabled(false);

	// layout
	root->addWidget(combo1);
	root->addWidget(combo2);
	root->addWidget(combo3);
	root->addWidget(combo4);
	root->addWidget(entry1);
	root->addWidget(entry2);
	root->addWidget(entry3);
	root->addWidget(entry4);
}

static void create_spinbuttons(AwfHBox *root) { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m create_spinbuttons()\n");

	QSpinBox *spinbutton1, *spinbutton2;

	// QSpinBox
	spinbutton1 = new QSpinBox;
	spinbutton1->setRange(-100, 100);
	spinbutton1->setSingleStep(1);
	spinbutton1->setValue(1);
	spinbutton1->setFixedWidth(58); // like gtk2
	spinbutton1->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	spinbutton2 = new QSpinBox;
	spinbutton2->setRange(-100, 100);
	spinbutton2->setSingleStep(1);
	spinbutton2->setValue(1);
	spinbutton2->setFixedWidth(58); // like gtk2
	spinbutton2->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	spinbutton2->setEnabled(false);

	// layout
	root->addWidget(spinbutton1);
	root->addStretch();
	root->addWidget(spinbutton2);
}

static void create_checkbuttons(AwfVBox *root) { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m create_checkbuttons()\n");

	QCheckBox *checkbutton1, *checkbutton2, *checkbutton3, *checkbutton4, *checkbutton5, *checkbutton6;

	// QCheckBox
	checkbutton1 = new QCheckBox("Check btn 1");

	checkbutton2 = new QCheckBox("Check btn 2");
	checkbutton2->setChecked(true);

	checkbutton3 = new QCheckBox("Check btn 3");
	checkbutton3->setTristate(true);
	checkbutton3->setCheckState(Qt::PartiallyChecked);

	checkbutton4 = new QCheckBox("Check btn 4");
	checkbutton4->setEnabled(false);

	checkbutton5 = new QCheckBox("Check btn 5");
	checkbutton5->setChecked(true);
	checkbutton5->setEnabled(false);

	checkbutton6 = new QCheckBox("Check btn 6");
	checkbutton6->setTristate(true);
	checkbutton6->setCheckState(Qt::PartiallyChecked);
	checkbutton6->setEnabled(false);

	// layout
	root->addWidget(checkbutton1);
	root->addWidget(checkbutton2);
	root->addWidget(checkbutton3);
	root->addWidget(checkbutton4);
	root->addWidget(checkbutton5);
	root->addWidget(checkbutton6);
}

static void create_radiobuttons(AwfVBox *root) { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m create_radiobuttons()\n");

	QRadioButton *radiobutton1, *radiobutton2, *radiobutton3, *radiobutton4, *radiobutton5, *radiobutton6;
	QButtonGroup *group1, *group2;

	// QRadioButton
	radiobutton1 = new QRadioButton("Radio btn 1");

	radiobutton2 = new QRadioButton("Radio btn 2");
	radiobutton2->setChecked(true);

	radiobutton3 = new QRadioButton("Radio btn 3");
	radiobutton3->setCheckable(true);

	radiobutton4 = new QRadioButton("Radio btn 4");
	radiobutton4->setEnabled(false);

	radiobutton5 = new QRadioButton("Radio btn 5");
	radiobutton5->setChecked(true);
	radiobutton5->setEnabled(false);

	radiobutton6 = new QRadioButton("Radio btn 6");
	radiobutton6->setCheckable(true);
	radiobutton6->setEnabled(false);

	// QButtonGroup
	group1 = new QButtonGroup(root);
	group1->addButton(radiobutton1);
	group1->addButton(radiobutton2);
	group1->addButton(radiobutton3);

	group2 = new QButtonGroup(root);
	group2->addButton(radiobutton4);
	group2->addButton(radiobutton5);
	group2->addButton(radiobutton6);

	// layout
	root->addWidget(radiobutton1);
	root->addWidget(radiobutton2);
	root->addWidget(radiobutton3);
	root->addWidget(radiobutton4);
	root->addWidget(radiobutton5);
	root->addWidget(radiobutton6);
}

static void create_otherbuttons(AwfVBox *root1, AwfHBox *root2, AwfHBox *root3, AwfHBox *root4, AwfHBox *root5) { //ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m create_otherbuttons()\n");

	// QPushButton
	QPushButton *button1, *button2, *button3, *button4;

	button1 = new QPushButton("Button 1");

	button2 = new QPushButton("Button 2");
	button2->setEnabled(false);

	button3 = new QPushButton("Button 3");
	button3->setCheckable(true);
	button3->setChecked(true);

	button4 = new QPushButton("Button 4");
	button4->setCheckable(true);
	button4->setChecked(true);
	button4->setEnabled(false);

	// QPushButton for dialogs
	QPushButton *button5, *button6, *button7, *button8;

	button5 = new QPushButton(_app("Choose a color"));
	button5->setMinimumWidth(186); // The 186
	button5->setProperty("class", "awf-cheatcode-colorbtn");
	QObject::connect(button5, &QPushButton::clicked, [=](){
		QColorDialog::getColor(QColor("#7796ba"), window, "QColorDialog");
	});

	button6 = new QPushButton(_app("Choose a font"));
	button6->setMinimumWidth(186); // The 186
	button6->setProperty("class", "awf-cheatcode-fontbtn");
	QObject::connect(button6, &QPushButton::clicked, [=](){
		bool ok;
		QFontDialog::getFont(&ok, QFont(), window, "QFontDialog");
	});

	button7 = new QPushButton(_app("Choose a file"));
	button7->setMinimumWidth(186); // The 186
	button7->setProperty("class", "awf-cheatcode-filebtn");
	QObject::connect(button7, &QPushButton::clicked, [=](){
		QFileDialog::getOpenFileName(window, "QFileDialog:Open");
	});

	button8 = new QPushButton(_app("Choose a folder"));
	button8->setMinimumWidth(186); // The 186
	button8->setProperty("class", "awf-cheatcode-folderbtn");
	QObject::connect(button8, &QPushButton::clicked, [=](){
		QFileDialog::getExistingDirectory(window, "QFileDialog:Open");
	});

	// Other
	QFontComboBox *button9;
	QDoubleSpinBox *button10;

	button9 = new QFontComboBox;
	button9->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLengthWithIcon);
	button9->setMinimumContentsLength(8);

	button10 = new QDoubleSpinBox;
	button10->setRange(-100, 100);
	button10->setSingleStep(1);
	button10->setValue(1);
	button10->setSuffix(" mm");
	button10->setPrefix("± ");

	// layout
	root1->addWidget(button1);
	root1->addWidget(button2);
	root1->addWidget(button3);
	root1->addWidget(button4);
	root1->addWidget(button5);
	root1->addWidget(button6);
	root1->addWidget(button7);
	root1->addWidget(button8);
	root2->addWidget(button9);
	root3->addWidget(button10);
	root4->addStretch();
	root5->addStretch();
}

static void create_progressbars(AwfVBox *root1, AwfHBox *root2, AwfHBox *root3, AwfVBox *root4) { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m create_progressbars()\n");

	// QProgressBar
	progress1 = new QProgressBar;
	progress1->setOrientation(Qt::Horizontal);
	progress1->setTextVisible(false);
	progress1->setValue(50);

	progress2 = new QProgressBar;
	progress2->setOrientation(Qt::Horizontal);
	progress2->setTextVisible(false);
	progress2->setValue(50);
	progress2->setInvertedAppearance(true);
	progress2->setProperty("isInverted", true);

	progress3 = new QProgressBar;
	progress3->setOrientation(Qt::Vertical);
	progress3->setTextVisible(false);
	progress3->setValue(50);
	progress3->setFixedHeight(100);
	progress3->setInvertedAppearance(true);
	progress3->setProperty("isInverted", true);

	progress4 = new QProgressBar;
	progress4->setOrientation(Qt::Vertical);
	progress4->setTextVisible(false);
	progress4->setValue(50);
	progress4->setFixedHeight(100);

	QLocale locale;
	if ((locale.language() == QLocale::French) && (locale.territory() == QLocale::France)) {
		progress1->setFormat("%p %");
		progress2->setFormat("%p %");
		progress3->setFormat("%p %");
		progress4->setFormat("%p %");
	}

	// QSlider
	slider1 = create_horizontal_slider(50, false, false, QSlider::NoTicks);
	QObject::connect(slider1, &QSlider::valueChanged, [=](){ update_values(slider1); });

	slider2 = create_horizontal_slider(50, false, true, QSlider::NoTicks);
	QObject::connect(slider2, &QSlider::valueChanged, [=](){ update_values(slider2); });

	slider3 = create_vertical_slider(50, false, !false, QSlider::NoTicks);
	QObject::connect(slider3, &QSlider::valueChanged, [=](){ update_values(slider3); });

	slider4 = create_vertical_slider(50, false, !true, QSlider::NoTicks);
	QObject::connect(slider4, &QSlider::valueChanged, [=](){ update_values(slider4); });

	slider5 = create_vertical_slider(50, false, !false, QSlider::TicksAbove);
	QObject::connect(slider5, &QSlider::valueChanged, [=](){ update_values(slider5); });

	slider6 = create_vertical_slider(50, false, !true, QSlider::TicksBelow);
	QObject::connect(slider6, &QSlider::valueChanged, [=](){ update_values(slider6); });

	slider7 = create_vertical_slider(50, false, !true, QSlider::TicksBothSides);
	QObject::connect(slider7, &QSlider::valueChanged, [=](){ update_values(slider7); });

	// layout
	root1->addWidget(progress1);
	root1->addWidget(progress2);
	root1->addWidget(slider1);
	root1->addWidget(slider2);
	root2->addWidget(progress3);
	root2->addWidget(progress4);
	root2->addStretch();
	root3->addWidget(slider3);
	root3->addWidget(slider5);
	root3->addWidget(slider6);
	root3->addWidget(slider4);
	root3->addWidget(slider7);
	root3->addStretch();
	root4->addStretch();
}

static void create_labels(AwfHBox *root) { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m create_labels()\n");

	QLabel *label1, *label2;

	// QLabel
	label1 = new QLabel("Label 1");

	label2 = new QLabel("Label 2");
	label2->setEnabled(false);

	// layout
	root->addWidget(label1);
	root->addStretch();
	root->addWidget(label2);
	root->addStretch();
}

static void create_spinners(AwfHBox *root) {

}

static void create_expander(AwfVBox *root) { // todo

	if (awf_trace)
		printf("\033[36m[trace]\033[00m create_expander()\n");

	QGroupBox *expander;
	QTextEdit *text;

	// QGroupBox
	expander = new QGroupBox(_app("More..."));
	expander->setCheckable(true);
	expander->setChecked(true);

	// QTextEdit
	text = new QTextEdit;
	text->setFixedHeight(120);
	text->setMinimumWidth(160);
	text->setWordWrapMode(QTextOption::WordWrap);
	text->setText(_app("A widget factory is a theme preview application for GTK and Qt. It displays the various widget types in a single window allowing to see the visual effect of the applied theme.") + " " + _app("A widget factory is a theme preview application for GTK and Qt. It displays the various widget types in a single window allowing to see the visual effect of the applied theme."));

	// layout
	AwfVBox *expanderLayout = new AwfVBox(expander);
	expanderLayout->addWidget(text);
	root->addWidget(expander);
}

static void create_frames(AwfHBox *root1, AwfHBox *root2) { // todo

	if (awf_trace)
		printf("\033[36m[trace]\033[00m create_frames()\n");

	QGroupBox *frame1, *frame2, *frame3, *frame4;

	// QGroupBox
	frame1 = new QGroupBox("Frame (shadow in)");
	frame1->setProperty("class", "border-inset");

	frame2 = new QGroupBox("Frame (shadow out)");
	frame2->setProperty("class", "border-outset");

	frame3 = new QGroupBox("Frame (shadow etched in)");
	frame3->setProperty("class", "border-groove");

	frame4 = new QGroupBox("Frame (shadow etched out)");
	frame4->setProperty("class", "border-ridge");
	frame4->setEnabled(false);

	// layout
	root1->addWidget(frame1);
	root1->addWidget(frame2);
	root2->addWidget(frame3);
	root2->addWidget(frame4);
}

static void create_notebooks(AwfHBox *root1, AwfHBox *root2) { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m create_notebooks()\n");

	// QTabWidget
	notebook1 = new QTabWidget;
	notebook1->setTabPosition(QTabWidget::North);
	notebook1->setTabsClosable(false);
	notebook1->setUsesScrollButtons(false);
	notebook1->tabBar()->setExpanding(false);
	notebook1->tabBar()->setMovable(true);
		create_notebook_tab(notebook1, "Tab1", null, false);
		create_notebook_tab(notebook1, "Tab2", null, false);
		create_notebook_tab(notebook1, "Tab3", null, true);
		create_notebook_tab(notebook1, "Tab4", null, true);

	notebook2 = new QTabWidget;
	notebook2->setTabPosition(QTabWidget::South);
	notebook2->setTabsClosable(false);
	notebook2->setUsesScrollButtons(false);
	notebook2->tabBar()->setExpanding(false);
	notebook2->tabBar()->setMovable(true);
		create_notebook_tab(notebook2, "Tab1", null, false);
		create_notebook_tab(notebook2, "Tab2", null, false);
		create_notebook_tab(notebook2, "Tab3", null, true);
		create_notebook_tab(notebook2, "Tab4", null, true);

	notebook3 = new QTabWidget;
	notebook3->setTabPosition(QTabWidget::West);
	notebook3->setTabsClosable(false);
	notebook3->setUsesScrollButtons(false);
	notebook3->tabBar()->setExpanding(false);
	notebook3->tabBar()->setMovable(true);
		create_notebook_tab(notebook3, "T1", null, false);
		create_notebook_tab(notebook3, "Tab2", null, false);
		create_notebook_tab(notebook3, "T3b", null, true);
		create_notebook_tab(notebook3, "T4", null, true);

	notebook4 = new QTabWidget;
	notebook4->setTabPosition(QTabWidget::East);
	notebook4->setTabsClosable(false);
	notebook4->setUsesScrollButtons(false);
	notebook4->tabBar()->setExpanding(false);
	notebook4->tabBar()->setMovable(true);
		create_notebook_tab(notebook4, "T1", null, false);
		create_notebook_tab(notebook4, "Tab2", null, false);
		create_notebook_tab(notebook4, "T3b", null, true);
		create_notebook_tab(notebook4, "T4", null, true);

	// layout
	notebook1->setMinimumWidth(notebook1->tabBar()->sizeHint().width());
	notebook2->setMinimumWidth(notebook2->tabBar()->sizeHint().width());
	notebook3->setMinimumHeight(notebook3->tabBar()->sizeHint().height());
	notebook4->setMinimumHeight(notebook4->tabBar()->sizeHint().height());
	root1->addWidget(notebook1);
	root1->addWidget(notebook2);
	root2->addWidget(notebook3);
	root2->addWidget(notebook4);
}

static void create_notebook_tab(QTabWidget *notebook, QString text, QWidget *content, bool close) { // todo

	if (!content)
		content = new QWidget;

	content->setAutoFillBackground(true);

	if ((notebook->tabPosition() == QTabWidget::West) || (notebook->tabPosition() == QTabWidget::East)) {
		// @todo force horizontal tab for vertical tabs bar
		if (close) {
			QWidget *layout = new QWidget;
			layout->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

			QToolButton *btn = new QToolButton;
			btn->setIcon(get_icon("window-close"));
			btn->setIconSize(QSize(16, 16));
			btn->setAutoRaise(true); // flat

			AwfHBox *hbox = new AwfHBox(layout);
			hbox->setContentsMargins(0, 0, 0, 0);
			hbox->addWidget(new QLabel(text));
			hbox->addWidget(btn);

			layout->setLayout(hbox);
			notebook->tabBar()->setTabButton(notebook->addTab(content, ""), QTabBar::LeftSide, layout);
		}
		else {
			notebook->tabBar()->setTabButton(notebook->addTab(content, ""), QTabBar::LeftSide, new QLabel(text));
		}
	}
	else if (close) {
		QToolButton *btn = new QToolButton;
		btn->setIcon(get_icon("window-close"));
		btn->setIconSize(QSize(16, 16));
		btn->setAutoRaise(true); // flat
		notebook->tabBar()->setTabButton(notebook->addTab(content, text), QTabBar::RightSide, btn);
	}
	else {
		notebook->addTab(content, text);
	}
}

static void create_treeview(AwfVBox *root) { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m create_treeview()\n");

	QStandardItemModel *model = new QStandardItemModel;
	model->setColumnCount(11);
	model->setHorizontalHeaderLabels({ "i", "c", "r", "Text", "Progress", "Progress", "Text", "Icon", "Icon", "c", "r" });

	auto addRow = [&](int a, bool b, bool c, QString d, int e, int f, QString g, QString h, QString i, bool j, bool k) {
		QList<QStandardItem*> items;
		auto it0  = new QStandardItem; it0->setData(a, Qt::DisplayRole);
		auto it1  = new QStandardItem; it1->setData(b ? Qt::Checked : Qt::Unchecked, Qt::CheckStateRole); it1->setEditable(false);
		auto it2  = new QStandardItem; it2->setData(c ? Qt::Checked : Qt::Unchecked, Qt::CheckStateRole); it2->setEditable(false);
		auto it3  = new QStandardItem; it3->setData(d, Qt::DisplayRole);
		auto it4  = new QStandardItem; it4->setData(e, Qt::DisplayRole); it4->setEditable(false);
		auto it5  = new QStandardItem; it5->setData(f, Qt::DisplayRole); it5->setEditable(false); it5->setEnabled(false);
		auto it6  = new QStandardItem; it6->setData(g, Qt::DisplayRole); it6->setEditable(false); it6->setEnabled(false);
		auto it7  = new QStandardItem; it7->setIcon(get_icon(h)); it7->setEditable(false);
		auto it8  = new QStandardItem; it8->setIcon(get_icon(i)); it8->setEditable(false); it8->setEnabled(false);
		auto it9  = new QStandardItem;  it9->setData(j ? Qt::Checked : Qt::Unchecked, Qt::CheckStateRole);  it9->setEditable(false);  it9->setEnabled(false);
		auto it10 = new QStandardItem; it10->setData(k ? Qt::Checked : Qt::Unchecked, Qt::CheckStateRole); it10->setEditable(false); it10->setEnabled(false);
		items << it0 << it1 << it2 << it3 << it4 << it5 << it6 << it7 << it8 << it9 << it10;
		model->appendRow(items);
	};

	addRow(1,  false, false, "Text 1.1",  0,   0,   "Text 1.2",  "document-open",    "document-open",    false, false);
	addRow(2,  true,  true,  "Text 2.1",  10,  10,  "Text 2.2",  "document-save",    "document-save",    true,  true);
	addRow(3,  false, false, "Text 3.1",  20,  20,  "Text 3.2",  "document-save-as", "document-save-as", false, false);
	addRow(4,  true,  true,  "Text 4.1",  30,  30,  "Text 4.2",  "view-refresh",     "view-refresh",     true,  true);
	addRow(5,  false, false, "Text 5.1",  40,  40,  "Text 5.2",  "edit-cut",         "edit-cut",         false, false);
	addRow(6,  true,  true,  "Text 6.1",  50,  50,  "Text 6.2",  "help-browser",     "help-browser",     true,  true);
	addRow(7,  false, false, "Text 7.1",  60,  60,  "Text 7.2",  "document-open",    "document-open",    false, false);
	addRow(8,  true,  true,  "Text 8.1",  70,  70,  "Text 8.2",  "document-save",    "document-save",    true,  true);
	addRow(9,  false, false, "Text 9.1",  80,  80,  "Text 9.2",  "document-save-as", "document-save-as", false, false);
	addRow(10, true,  true,  "Text 10.1", 90,  90,  "Text 10.2", "view-refresh",     "view-refresh",     true,  true);
	addRow(11, false, false, "Text 11.1", 100, 100, "Text 11.2", "edit-cut",         "edit-cut",         false, false);

	// QTreeView
	AwfTreeView *view = new AwfTreeView; // same as QTreeView *view = new QTreeView; but with QSS columns width support
	view->setFixedHeight(200); // The 200
	view->setMinimumWidth(200); // The 200
	model->setParent(view);
	view->setModel(model);
	view->setSortingEnabled(true);
	view->setRootIsDecorated(false);
	view->setItemsExpandable(false);
	view->setAlternatingRowColors(true);
	view->sortByColumn(0, Qt::AscendingOrder);
	view->setItemDelegateForColumn(2, new AwfRadioDelegate(view));
	view->setItemDelegateForColumn(4, new AwfProgressDelegate(view));
	view->setItemDelegateForColumn(5, new AwfProgressDelegate(view));
	view->setItemDelegateForColumn(10, new AwfRadioDelegate(view));
	view->header()->setStretchLastSection(false);
	view->header()->setMinimumSectionSize(16);

	for (int c = 0; c < model->columnCount(); ++c)
		view->resizeColumnToContents(c);
	view->header()->setSectionResizeMode(QHeaderView::Interactive);

	root->addWidget(view);
}

static void create_sliders(QTabWidget *notebook, QString text, QSlider::TickPosition position) { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m create_sliders()\n");

	AwfHBox *hbox = new AwfHBox;
	AwfVBox *vbox1 = new AwfVBox, *vbox2 = new AwfVBox, *vbox3 = new AwfVBox;
	AwfHBox *hboxa = new AwfHBox, *hboxb = new AwfHBox;
	QSlider *slider1v, *slider2v, *slider3v, *slider4v, *slider5v, *slider6v, *slider7v, *slider8v, *slider9v, *slider10v, *slider11v, *slider12v;
	QSlider *slider1h, *slider2h, *slider3h, *slider4h, *slider5h, *slider6h, *slider7h, *slider8h, *slider9h, *slider10h, *slider11h, *slider12h;
	int value = slider1->value();

	// vertical sliders
	slider1v = create_vertical_slider(value, false, false, position);
	slider2v = create_vertical_slider(value, false, false, position);
	slider3v = create_vertical_slider(value, false, false, position);
	slider4v = create_vertical_slider(value, true, false, position);
	slider5v = create_vertical_slider(value, true, false, position);
	slider6v = create_vertical_slider(value, true, false, position);
	slider7v = create_vertical_slider(value, false, true, position);
	slider8v = create_vertical_slider(value, false, true, position);
	slider9v = create_vertical_slider(value, false, true, position);
	slider10v = create_vertical_slider(value, true, true, position);
	slider11v = create_vertical_slider(value, true, true, position);
	slider12v = create_vertical_slider(value, true, true, position);

	// horizontal sliders
	slider1h = create_horizontal_slider(value, false, false, position);
	slider2h = create_horizontal_slider(value, false, false, position);
	slider3h = create_horizontal_slider(value, false, false, position);
	slider4h = create_horizontal_slider(value, true, false, position);
	slider5h = create_horizontal_slider(value, true, false, position);
	slider6h = create_horizontal_slider(value, true, false, position);
	slider7h = create_horizontal_slider(value, false, true, position);
	slider8h = create_horizontal_slider(value, false, true, position);
	slider9h = create_horizontal_slider(value, false, true, position);
	slider10h = create_horizontal_slider(value, true, true, position);
	slider11h = create_horizontal_slider(value, true, true, position);
	slider12h = create_horizontal_slider(value, true, true, position);

	// layout
	hbox->addLayout(vbox1);
		vbox1->addWidget(slider1h);
		vbox1->addWidget(slider2h);
		vbox1->addWidget(slider3h);
		vbox1->addWidget(slider4h);
		vbox1->addWidget(slider5h);
		vbox1->addWidget(slider6h);
	hbox->addLayout(vbox2);
		vbox2->addLayout(hboxa);
			hboxa->addWidget(slider1v);
			hboxa->addWidget(slider2v);
			hboxa->addWidget(slider3v);
			hboxa->addWidget(slider7v);
			hboxa->addWidget(slider8v);
			hboxa->addWidget(slider9v);
		vbox2->addLayout(hboxb);
			hboxb->addWidget(slider4v);
			hboxb->addWidget(slider5v);
			hboxb->addWidget(slider6v);
			hboxb->addWidget(slider10v);
			hboxb->addWidget(slider11v);
			hboxb->addWidget(slider12v);
	hbox->addLayout(vbox3);
		vbox3->addWidget(slider7h);
		vbox3->addWidget(slider8h);
		vbox3->addWidget(slider9h);
		vbox3->addWidget(slider10h);
		vbox3->addWidget(slider11h);
		vbox3->addWidget(slider12h);

	QWidget *container = new QWidget;
	container->setLayout(hbox);
	create_notebook_tab(notebook, text, container, false);
}

static QSlider* create_horizontal_slider(int value, bool draw, bool inverted, QSlider::TickPosition position) { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m create_horizontal_slider()\n");

	QSlider *slider = new QSlider(Qt::Horizontal);

	slider->setRange(0, 100);
	slider->setValue(value);
	slider->setInvertedAppearance(inverted);
	if (inverted)
		slider->setProperty("isInverted", true);
	// draw does not exists
	slider->setTickPosition(position);
	slider->setFixedWidth(186); // The 186
	slider->setTracking(true);

	switch (position) {
		case QSlider::NoTicks:        slider->setProperty("hasTicks", "NoTicks"); break;
		case QSlider::TicksAbove:     slider->setProperty("hasTicks", "TicksAbove"); break;
		case QSlider::TicksBelow:     slider->setProperty("hasTicks", "TicksBelow"); break;
		case QSlider::TicksBothSides: slider->setProperty("hasTicks", "TicksBothSides"); break;
	}

	return slider;
}

static QSlider* create_vertical_slider(int value, bool draw, bool inverted, QSlider::TickPosition position) { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m create_vertical_slider()\n");

	QSlider *slider = new QSlider(Qt::Vertical);

	slider->setRange(0, 100);
	slider->setValue(value);
	slider->setInvertedAppearance(inverted);
	if (inverted)
		slider->setProperty("isInverted", true);
	// draw does not exists
	slider->setTickPosition(position);
	slider->setFixedHeight(100); // The 100
	slider->setTracking(true);

	switch (position) {
		case QSlider::NoTicks:        slider->setProperty("hasTicks", "NoTicks"); break;
		case QSlider::TicksAbove:     slider->setProperty("hasTicks", "TicksAbove"); break;
		case QSlider::TicksBelow:     slider->setProperty("hasTicks", "TicksBelow"); break;
		case QSlider::TicksBothSides: slider->setProperty("hasTicks", "TicksBothSides"); break;
	}

	return slider;
}


// traditional menu

static void create_traditional_menubar(QMenuBar *root) {

	if (awf_trace)
		printf("\033[36m[trace]\033[00m create_traditional_menubar()\n");

	static AwfShortcutFilter *shortcutFilter = new AwfShortcutFilter(window);
	QMenu *menu, *submenu, *base;
	QActionGroup *group;
	QAction *menuitem;
	bool ok, noRefresh = !awf_gqss, noPrint = false;

	#if ! defined (QT_PRINTSUPPORT_LIB)
		noPrint = true;
	#endif

	// options
	menu = root->addMenu(_app("_Options"));
	menu->installEventFilter(shortcutFilter);

		// @todo option command line?
		if (qEnvironmentVariableIsSet("AWF_TEAROFF"))
			menu->setTearOffEnabled(true);

		create_menuitem(menu, get_icon("document-open"), _qt("QFileDialog", "&Open"), false, AWF_ACCEL_OPEN, AWF_OPEN, dialog_open);
		create_menuitem(menu, QIcon(), _app("Open recent file"), true, AWF_ACCEL_RECE, AWF_RECE, null);
		create_menuitem(menu, get_icon("document-save"), _qt("QFileDialog", "&Save"), false, AWF_ACCEL_SAVE, AWF_SAVE, dialog_save);
		create_menuitem(menu, get_icon("view-refresh"), _app("_Refresh"), noRefresh, AWF_ACCEL_REFR, AWF_REFR, [](){ on_sighup(0); });
		create_menuitem(menu, QIcon(), _app("Calendar"), false, AWF_ACCEL_CALE, AWF_CALE, dialog_calendar);
		create_menuitem(menu, QIcon(), "Sliders", false, AWF_ACCEL_SCAL, AWF_SCAL, dialog_sliders);
		create_menuitem(menu, get_icon("document-properties"), _app("Properties"), false, AWF_ACCEL_PROP, AWF_PROP, dialog_message);
		create_menuitem(menu, get_icon("document-page-setup"),_app("Page Set&up"), noPrint, AWF_ACCEL_PRSE, AWF_PRSE, dialog_page_setup);
		create_menuitem(menu, get_icon("document-print"), _qt("QPrintDialog", "&Print"), noPrint, AWF_ACCEL_PRIN, AWF_PRIN, dialog_print);

		submenu = menu->addMenu(_app("More..."));
		submenu->installEventFilter(shortcutFilter);

			create_menuitem(submenu, get_icon("edit-cut"), _qt("QLineEdit", "Cu&t"), false, AWF_ACCEL_MCUT, AWF_MCUT, null);
			create_menuitem(submenu, get_icon("edit-copy"), _qt("QLineEdit", "&Copy"), false, AWF_ACCEL_MCOP, AWF_MCOP, null);
			create_menuitem(submenu, get_icon("edit-paste"), _qt("QLineEdit", "&Paste"), false, AWF_ACCEL_MPAS, AWF_MPAS, null);

		submenu = menu->addMenu(_app("Less..."));
		submenu->setEnabled(false);

		menu->addSeparator();

			create_menuitem_check(menu, QString("Check 1 %1").arg(_app("(unchecked)")), false, false, false);
			create_menuitem_check(menu, QString("Check 2 %1").arg(_app("(checked)")), true, false, false);
			create_menuitem_check(menu, QString("Check 3 %1").arg(_app("(inconsistent)")), false, true, false);

			create_menuitem_check(menu, QString("Check 1 %1").arg(_app("(unchecked)")), false, false, true);
			create_menuitem_check(menu, QString("Check 2 %1").arg(_app("(checked)")), true, false, true);
			create_menuitem_check(menu, QString("Check 3 %1").arg(_app("(inconsistent)")), false, true, true);

		menu->addSeparator();

			group = new QActionGroup(window);
			group->setExclusive(true);

			create_menuitem_radio(menu, QString("Radio 1 %1").arg(_app("(unchecked)")), false, false, false, group);
			create_menuitem_radio(menu, QString("Radio 2 %1").arg(_app("(checked)")), true, false, false, group);
			create_menuitem_radio(menu, QString("Radio 3 %1").arg(_app("(inconsistent)")), false, true, false, group);

			group = new QActionGroup(window);
			group->setExclusive(true);

			create_menuitem_radio(menu, QString("Radio 1 %1").arg(_app("(unchecked)")), false, false, true, group);
			create_menuitem_radio(menu, QString("Radio 2 %1").arg(_app("(checked)")), true, false, true, group);
			create_menuitem_radio(menu, QString("Radio 3 %1").arg(_app("(inconsistent)")), false, true, true, group);

		menu->addSeparator();

			create_menuitem(menu, get_icon("window-close"), _qt("QMdiSubWindow", "&Close"), true, AWF_ACCEL_CLOS, AWF_CLOS, null);
			create_menuitem(menu, get_icon("application-exit"), _qt("QCocoaMenuItem", "Quit"), false, AWF_ACCEL_QUIT, AWF_QUIT, qApp->quit);

	// system themes
	ok = false;
	group = new QActionGroup(window);
	group->setExclusive(true);
	menu  = root->addMenu(_app("_System themes"));
	for (QString theme : list_system_theme) {

		if (theme == "Azertyuiop") {
			submenu = menu->addMenu(theme);
			base = submenu;
			ok = true;
		}
		else if (ok && theme.startsWith("Azertyuiop")) {
			base = submenu;
		}
		else {
			base = menu;
			ok = false;
		}

		if (list_user_theme.contains(theme)) {
			menuitem = create_menuitem_radio(base, theme, false, false, true, group);
			if (theme == current_theme)
				menuitem->setChecked(true);
			QObject::connect(menuitem, &QAction::triggered, [theme](){ update_theme(theme); });
		}
		else {
			menuitem = create_menuitem_radio(base, theme, false, false, false, group);
			if (theme == current_theme)
				menuitem->setChecked(true);
			QObject::connect(menuitem, &QAction::triggered, [theme](){ update_theme(theme); });
		}
	}

	if (noRefresh)
		create_menuitem(menu, QIcon(), _app("GlobalQSS not available"), true, QKeySequence(), null, null);
	else if (list_system_theme.isEmpty())
		create_menuitem(menu, QIcon(), _app("No themes found"), true, QKeySequence(), null, null);

	// user themes
	ok = false;
	menu = root->addMenu(_app("_User themes"));
	for (QString theme : list_user_theme) {

		if (theme == "Azertyuiop") {
			submenu = menu->addMenu(theme);
			base = submenu;
			ok = true;
		}
		else if (ok && theme.startsWith("Azertyuiop")) {
			base = submenu;
		}
		else {
			base = menu;
			ok = false;
		}

		menuitem = create_menuitem_radio(base, theme, false, false, false, group);
		if (theme == current_theme)
			menuitem->setChecked(true);
		QObject::connect(menuitem, &QAction::triggered, [theme](){ update_theme(theme); });
	}

	if (noRefresh)
		create_menuitem(menu, QIcon(), _app("GlobalQSS not available"), true, QKeySequence(), null, null);
	else if (list_user_theme.isEmpty())
		create_menuitem(menu, QIcon(), _app("No themes found"), true, QKeySequence(), null, null);

	// text direction
	menu = root->addMenu(_app("_Text direction"));

		group = new QActionGroup(window);
		group->setExclusive(true);

		menuitem = create_menuitem_radio(menu, _app("Left to Right (LTR)"), false, false, false, group);
		if (current_direction == 1)
			menuitem->setChecked(true);
		QObject::connect(menuitem, &QAction::triggered, [](){ update_text_direction(1); }); // Qt::LeftToRight

		menuitem = create_menuitem_radio(menu, _app("Right to Left (RTL)"), false, false, false, group);
		if (current_direction == 2)
			menuitem->setChecked(true);
		QObject::connect(menuitem, &QAction::triggered, [](){ update_text_direction(2); }); // Qt::RightToLeft

	// help
	menu = root->addMenu(_qt("QWizard", "&Help"));
	menu->installEventFilter(shortcutFilter);

		create_menuitem(menu, QIcon(), "QtInspector", false, AWF_ACCEL_INSP, AWF_INSP, dialog_inspector);
		create_menuitem(menu, get_icon("help-about"), _qt("QCocoaMenuItem", "About"), false, AWF_ACCEL_ABOU, AWF_ABOU, dialog_about);

	// gtk-can-change-accels for Qt | so same GTK 2.24 3.x 4.x & Qt 5.x 6.x
	accels_load();
}

static QAction* create_menuitem_check(QMenu *menu, QString text, bool chk, bool ist, bool dsb) {

	if (awf_trace)
		printf("\033[36m[trace]\033[00m create_menuitem_check(%s)\n", text.toUtf8().constData());

	QAction *menuitem;

	menuitem = new QAction(text, window);
	menuitem->setCheckable(true);
	menuitem->setChecked(chk);
	// @todo inconsistent (ist)
	menuitem->setEnabled(!dsb);
	menu->addAction(menuitem);

	return menuitem;
}

static QAction* create_menuitem_radio(QMenu *menu, QString text, bool chk, bool ist, bool dsb, QActionGroup *group) {

	if (awf_trace)
		printf("\033[36m[trace]\033[00m create_menuitem_radio(%s)\n", text.toUtf8().constData());

	QAction *menuitem;

	menuitem = new QAction(text, group);
	menuitem->setCheckable(true);
	menuitem->setChecked(chk);
	// @todo inconsistent (ist)
	menuitem->setEnabled(!dsb);
	menu->addAction(menuitem);

	return menuitem;
}

static QAction* create_menuitem(QMenu *menu, QIcon icon, QString text, bool dsb, QKeySequence acl, QString kmp, std::function<void()> function) {

	if (awf_trace)
		printf("\033[36m[trace]\033[00m create_menuitem(%s)\n", text.toUtf8().constData());

	QAction *menuitem;

	menuitem = new QAction(icon, text, window);
	menuitem->setShortcut(acl);
	menuitem->setEnabled(!dsb);

	if (!kmp.isEmpty())
		menuitem->setObjectName(kmp);
	if (function)
		QObject::connect(menuitem, &QAction::triggered, function);

	menu->addAction(menuitem);

	return menuitem;
}

static void accels_load() { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m accels_load()\n");

	QString oldPath = QDir::homePath() + "/.awf-gtk-accels";
	if (QFile::exists(oldPath))
		QFile::rename(oldPath, QDir::homePath() + "/.awf-accels");

	// gtk-can-change-accels for Qt | so same GTK 2.24 3.x 4.x & Qt 5.x 6.x
	QFile f(QDir::homePath() + QStringLiteral("/.awf-accels"));

	if (f.exists() && f.open(QIODevice::ReadOnly | QIODevice::Text)) {

		QMap<QString, QString> accels;
		QMap<QString, QAction*> actions;
		QString kmp, acl;

		auto parseModifiers = [](QString mod) {
			Qt::KeyboardModifiers m = Qt::NoModifier;
			if (mod.contains("Primary")) m |= static_cast<Qt::KeyboardModifier>(Qt::CTRL);
			if (mod.contains("Shift"))   m |= static_cast<Qt::KeyboardModifier>(Qt::SHIFT);
			if (mod.contains("Alt"))     m |= static_cast<Qt::KeyboardModifier>(Qt::ALT);
			if (mod.contains("Meta"))    m |= static_cast<Qt::KeyboardModifier>(Qt::META);
			return m;
		};

		auto parseKey = [](QString keyStr) {
			if (keyStr.length() == 1) return static_cast<Qt::Key>(keyStr.toUpper().at(0).unicode());
			if ((keyStr.compare("Delete", Qt::CaseInsensitive) == 0) || (keyStr.compare("Del", Qt::CaseInsensitive) == 0)) return Qt::Key_Delete;
			if (keyStr.compare("Return", Qt::CaseInsensitive) == 0) return Qt::Key_Return;
			if (keyStr.compare("F1", Qt::CaseInsensitive) == 0)  return Qt::Key_F1;
			if (keyStr.compare("F2", Qt::CaseInsensitive) == 0)  return Qt::Key_F2;
			if (keyStr.compare("F3", Qt::CaseInsensitive) == 0)  return Qt::Key_F3;
			if (keyStr.compare("F4", Qt::CaseInsensitive) == 0)  return Qt::Key_F4;
			if (keyStr.compare("F5", Qt::CaseInsensitive) == 0)  return Qt::Key_F5;
			if (keyStr.compare("F6", Qt::CaseInsensitive) == 0)  return Qt::Key_F6;
			if (keyStr.compare("F7", Qt::CaseInsensitive) == 0)  return Qt::Key_F7;
			if (keyStr.compare("F8", Qt::CaseInsensitive) == 0)  return Qt::Key_F8;
			if (keyStr.compare("F9", Qt::CaseInsensitive) == 0)  return Qt::Key_F9;
			if (keyStr.compare("F10", Qt::CaseInsensitive) == 0) return Qt::Key_F10;
			if (keyStr.compare("F11", Qt::CaseInsensitive) == 0) return Qt::Key_F11;
			if (keyStr.compare("F12", Qt::CaseInsensitive) == 0) return Qt::Key_F12;
			return Qt::Key_unknown;
		};

		// read file
		// QMap<QString=kmp, QString=acl> accels
		QTextStream in(&f);

		while (!in.atEnd()) {

			//; (gtk_accel_path "<AWF>/Test/Print" "<Primary>p")
			QString l = in.readLine().trimmed();

			if (l.isEmpty() || l.startsWith(';'))
				continue;

			int a = l.indexOf('"');
			if (a < 0)
				continue;

			int b = l.indexOf('"', a + 1);
			if (b < 0)
				continue;

			int c = l.indexOf('"', b + 1);
			if (c < 0)
				continue;

			int d = l.indexOf('"', c + 1);
			if (d < 0)
				continue;

			kmp = l.mid(a + 1, b - a - 1);
			acl = l.mid(c + 1, d - c - 1);

			if (kmp.isEmpty())
				continue;

			if (awf_debug)
				printf("\033[33m[debug]\033[00m accels_foundInFile: %s %s\n", kmp.toUtf8().constData(), acl.toUtf8().constData());

			accels.insert(kmp, acl);
		}

		f.close();

		// find all QAction in submenus and menus
		// QMap<QString=kmp, QAction*=action> actions
		for (QAction *menuAction : window->menuBar()->actions()) {

			QMenu *menu = menuAction->menu();
			if (!menu)
				continue;

			for (QAction *action : menu->actions()) {
				QMenu *subMenu = action->menu();
				if (subMenu) {
					for (QAction *subAction : subMenu->actions()) {
						kmp = subAction->objectName();
						if (accels.contains(kmp))
							actions.insert(kmp, subAction);
					}
				}
				else {
					kmp = action->objectName();
					if (accels.contains(kmp))
						actions.insert(kmp, action);
				}
			}
		}

		// apply shortcuts
		for (QString tmp : actions.keys()) {

			kmp = tmp;
			acl = accels.value(kmp);

			if (awf_debug)
				printf("\033[33m[debug]\033[00m accels_foundInMenu: %s %s\n", kmp.toUtf8().constData(), acl.toUtf8().constData());

			if (acl.isEmpty()) {
				actions.value(kmp)->setProperty("shortcutModified", true);
				actions.value(kmp)->setShortcut(QKeySequence());
			}
			else {
				Qt::KeyboardModifiers mods = parseModifiers(acl);
				acl.remove(QRegularExpression("<.*>"));
				Qt::Key key = parseKey(acl);

				if (key == Qt::Key_unknown) {
					printf("\033[33m[debug]\033[00m accels_foundInMenu: %s %s » unknown key\n", kmp.toUtf8().constData(), acl.toUtf8().constData());
				}
				else {
					actions.value(kmp)->setProperty("shortcutModified", true);
					actions.value(kmp)->setShortcut(QKeySequence(key | mods));
				}
			}
		}
	}
}

static bool accels_change(QObject *obj, QEvent *event) { // ok

	// gtk-can-change-accels for Qt | so same GTK 2.24 3.x 4.x & Qt 5.x 6.x
	if (event->type() != QEvent::KeyPress)
		return false;

	QMenu *menu = qobject_cast<QMenu*>(obj);
	if (!menu || !menu->activeAction())
		return false;

	QAction *menuitem = menu->activeAction();
	if (menuitem->objectName().isEmpty())
		return false;

	QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
	int key = keyEvent->key();
	if ((key == Qt::Key_Control) || (key == Qt::Key_Shift) || (key == Qt::Key_Meta) || (key == Qt::Key_Alt))
		return false;

	if (awf_trace)
		printf("\033[36m[trace]\033[00m accels_change()\n");

	Qt::KeyboardModifiers mods = keyEvent->modifiers();
	bool del = (key == Qt::Key_Delete) || (key == Qt::Key_Backspace);
	if (
		del ||
		// f1..12
		((key >= Qt::Key_F1) && (key <= Qt::Key_F12)) ||
		// ctrl/shift/super/alt + ?
		mods
	) {
		must_save_accels = true;
		QKeySequence seq = del ? QKeySequence() : QKeySequence(mods | key);

		// check and remove existing keyboard shortcut
		if (!del) {
			for (QAction *menuAction : window->menuBar()->actions()) {

				QMenu *menu = menuAction->menu();
				if (!menu)
					continue;

				for (QAction *action : menu->actions()) {
					if ((action != menuitem) && (action->shortcut() == seq)) {
						action->setProperty("shortcutModified", true);
						action->setShortcut(QKeySequence());
					}
				}
			}
		}

		// set new keyboard shortcut
		menuitem->setProperty("shortcutModified", true);
		menuitem->setShortcut(seq);

		if (awf_debug)
			printf("\033[33m[debug]\033[00m new_shortcut: %s\n", del ? "none" : seq.toString(QKeySequence::PortableText).toUtf8().constData());

		return true;
	}

	return false;
}

static void accels_save() { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m accels_save()\n");

	// gtk-can-change-accels for Qt | so same GTK 2.24 3.x 4.x & Qt 5.x 6.x
	// gtk_accel_map_save
	if (must_save_accels) {

		QFile f(QDir::homePath() + QStringLiteral("/.awf-accels"));

		if (f.open(QIODevice::WriteOnly | QIODevice::Text)) {

			QMap<QString, QAction*> actions;
			QString kmp, acl;
			QAction *act;

			auto parseModifiers = [](Qt::KeyboardModifiers m) {
				QString s;
				if (m & Qt::CTRL)  s += QString("<Primary>");
				if (m & Qt::SHIFT) s += QString("<Shift>");
				if (m & Qt::ALT)   s += QString("<Alt>");
				if (m & Qt::META)  s += QString("<Meta>");
				return s;
			};

			auto parseKey = [](Qt::Key k) {
				if ((k >= Qt::Key_A) && (k <= Qt::Key_Z)) return QString(QChar('a' + (k - Qt::Key_A)));
				if (k == Qt::Key_Delete) return QString("Delete");
				if (k == Qt::Key_Return) return QString("Return");
				if (k == Qt::Key_F1)  return QString("F1");
				if (k == Qt::Key_F2)  return QString("F2");
				if (k == Qt::Key_F3)  return QString("F3");
				if (k == Qt::Key_F4)  return QString("F4");
				if (k == Qt::Key_F5)  return QString("F5");
				if (k == Qt::Key_F6)  return QString("F6");
				if (k == Qt::Key_F7)  return QString("F7");
				if (k == Qt::Key_F8)  return QString("F8");
				if (k == Qt::Key_F9)  return QString("F9");
				if (k == Qt::Key_F10) return QString("F10");
				if (k == Qt::Key_F11) return QString("F11");
				if (k == Qt::Key_F12) return QString("F12");
				return QString();
			};

			// find all QAction in submenus and menus
			// QMap<QString=kmp, QAction*=action> actions
			for (QAction *menuAction : window->menuBar()->actions()) {

				QMenu *menu = menuAction->menu();
				if (!menu)
					continue;

				for (QAction *action : menu->actions()) {
					QMenu *subMenu = action->menu();
					if (subMenu) {
						for (QAction *subAction : subMenu->actions()) {
							kmp = subAction->objectName();
							if (!kmp.isEmpty())
								actions.insert(kmp, subAction);
						}
					}
					else {
						kmp = action->objectName();
						if (!kmp.isEmpty())
							actions.insert(kmp, action);
					}
				}
			}

			// save file
			QTextStream out(&f);
			out << "; awf-qt" << QT_VERSION_MAJOR << " GtkAccelMap rc-file         -*- scheme -*-\n";
			out << "; this file is an automated accelerator map dump\n";
			out << ";\n";

			for (QString tmp : actions.keys()) {

				kmp = tmp;
				act = actions.value(kmp);
				acl = act->shortcut().toString();

				if (!acl.isEmpty()) {
					const QKeyCombination kc = act->shortcut()[0];
					Qt::Key key = kc.key();
					Qt::KeyboardModifiers mods = kc.keyboardModifiers();
					acl = parseModifiers(mods) + parseKey(key);
				}

				out << (act->property("shortcutModified").toBool() ? "" : "; ") << "(gtk_accel_path \"" << kmp << "\" \"" << acl << "\")\n";
			}

			out << "\n";
			f.close();
		}
	}
}


// dialogs

static void dialog_open() { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m dialog_open()\n");

	QFileDialog::getOpenFileNames(window,
		QString("%1 - Qt %2.%3").arg("QFileDialog:Open").arg(QT_VERSION_MAJOR).arg(QT_VERSION_MINOR),
		QDir::homePath());
}

static void dialog_save() { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m dialog_save()\n");

	QFileDialog::getSaveFileName(window,
		QString("%1 - Qt %2.%3").arg("QFileDialog:Save").arg(QT_VERSION_MAJOR).arg(QT_VERSION_MINOR),
		QDir::homePath());
}

static void dialog_message() { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m dialog_message()\n");

	QMessageBox msgBox(window);
	msgBox.setIcon(QMessageBox::Information);
	msgBox.setWindowTitle(QString("%1 - Qt %2.%3").arg("QMessageBox").arg(QT_VERSION_MAJOR).arg(QT_VERSION_MINOR));
	msgBox.setText("QMessageBox");
	msgBox.setInformativeText(_app("A widget factory is a theme preview application for GTK and Qt. It displays the various widget types in a single window allowing to see the visual effect of the applied theme."));
	msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	msgBox.exec();
}

static void dialog_page_setup() { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m dialog_page_setup()\n");

	QPrinter printer;
	QPageSetupDialog(&printer, window).exec();
}

static void dialog_print() { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m dialog_print()\n");

	QPrinter printer;
	QPrintDialog(&printer, window).exec();
}

static void dialog_about() { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m dialog_about()\n");

	QString cppVersion;
	switch (__cplusplus) {
		case 199711L: cppVersion = "C++98";  break;
		case 201103L: cppVersion = "C++11";  break;
		case 201402L: cppVersion = "C++14";  break;
		case 201703L: cppVersion = "C++17";  break;
		case 202002L: cppVersion = "C++20";  break;
		case 202302L: cppVersion = "C++23";  break;
		default:      cppVersion = "C++ (" + QString::number(__cplusplus) + ")"; break;
	}

	QString t1 = QString("%1<br><br>%2 %3<br><br>%4<br>%5<br><i><small>QT_QPA_PLATFORMTHEME=%6 QT_STYLE_OVERRIDE=%7</small></i>")
		.arg(_app("A widget factory is a theme preview application for GTK and Qt. It displays the various widget types in a single window allowing to see the visual effect of the applied theme."))
		.arg(QString(_app("Remove %1 file")).arg("~/.awf-accels"))
		.arg(_app("to reset keyboard shortcuts."))
		.arg(QString(_app("compiled in %1 with qt %2.%3.%4")).arg(cppVersion).arg(QT_VERSION_MAJOR).arg(QT_VERSION_MINOR).arg(QT_VERSION_PATCH))
		.arg(QString(_app(" started with qt %1")).arg(qVersion()))
		.arg(QString::fromUtf8(qgetenv("QT_QPA_PLATFORMTHEME")))
		.arg(QString::fromUtf8(qgetenv("QT_STYLE_OVERRIDE")));

	QString t2 = QString("<b>awf-qt%1 / %2</b><br><br>%3<br><br>%4<br><br><small>%5</small><br><br><small>%6</small>")
		.arg(QT_VERSION_MAJOR)
		.arg(VERSION)
		.arg(t1)
		.arg("<a href=\"https://github.com/luigifab/awf-extended\">https://github.com/luigifab/awf-extended</a>")
		.arg("Copyright © 2020-2026 Fabrice Creuzot (luigifab)<br>Copyright © 2011-2017 Valère Monseur (valr)")
		.arg(_app("A widget factory is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the free software foundation, either version 3 of the license, or (at your option) any later version."));

	QMessageBox::about(window, _qt("QCocoaMenuItem", "About"), t2);
}

static void dialog_inspector() { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m dialog_inspector()\n");

	if (inspector) {
		inspector->raise();
		inspector->activateWindow();
	}
	else {
		inspector = new QDialog(window, Qt::Window);
		inspector->setAttribute(Qt::WA_DeleteOnClose);
		inspector->setWindowTitle(QString("%1 - Qt %2.%3").arg("QtInspector").arg(QT_VERSION_MAJOR).arg(QT_VERSION_MINOR));
		inspector->resize(500, 400);

		QTextEdit *textEdit = new QTextEdit;
		textEdit->setAcceptRichText(false);
		textEdit->setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));
		textEdit->setPlaceholderText(_app("Write QSS here..."));
		textEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

		QPushButton *btnCopy = new QPushButton(_qt("QShortcut", "Copy"));
		btnCopy->setIcon(get_icon("edit-copy"));
		QPushButton *btnClear = new QPushButton(_qt("QShortcut", "Clear"));
		btnClear->setIcon(get_icon("edit-clear"));
		QPushButton *btnClose = new QPushButton(_qt("QMdiSubWindow", "&Close"));
		btnClose->setIcon(get_icon("dialog-close"));

		AwfHBox *buttonLayout = new AwfHBox;
		buttonLayout->addWidget(btnCopy);
		buttonLayout->addWidget(btnClear);
		buttonLayout->addWidget(btnClose);

		AwfVBox *mainLayout = new AwfVBox;
		mainLayout->addWidget(textEdit);
		mainLayout->addLayout(buttonLayout);
		inspector->setLayout(mainLayout);

		QTimer* counter = new QTimer(inspector);
		counter->setSingleShot(true);

		QObject::connect(textEdit, &QTextEdit::textChanged, counter, [=](){
			counter->start(1000);
		});

		QObject::connect(btnClose, &QPushButton::clicked, inspector, [=](){
			inspector->close();
		});

		QObject::connect(btnCopy, &QPushButton::clicked, inspector, [=](){
			QString text = textEdit->toPlainText();
			if (!text.isEmpty())
				QApplication::clipboard()->setText(text);
			textEdit->setFocus();
		});

		QObject::connect(btnClear, &QPushButton::clicked, inspector, [=](){

			if (awf_gqss && (original_style == "!^!"))
				original_style = qApp->styleSheet();

			qApp->setStyleSheet(original_style);
			if (awf_gqss)
				original_style = "!^!";

			QSignalBlocker blocker(textEdit);
			textEdit->clear();
			textEdit->setFocus();
		});

		QObject::connect(inspector, &QWidget::destroyed, window, [=](){

			if (awf_gqss && (original_style == "!^!"))
				original_style = qApp->styleSheet();

			qApp->setStyleSheet(original_style);
			if (awf_gqss)
				original_style = "!^!";

			inspector = null;
		});

		QObject::connect(window, &QWidget::destroyed, inspector, &QWidget::close);

		QObject::connect(counter, &QTimer::timeout, inspector, [=](){

			if (awf_gqss && (original_style == "!^!"))
				original_style = qApp->styleSheet();

			#if defined (Q_OS_UNIX)
				int savedFd = dup(fileno(stderr));
				FILE* ignored = freopen("/dev/null", "w", stderr);
				qApp->setStyleSheet(original_style + "\n\n" + textEdit->toPlainText());
				fflush(stderr);
				dup2(savedFd, fileno(stderr));
				close(savedFd);
			#else
				qApp->setStyleSheet(original_style + "\n\n" + textEdit->toPlainText());
			#endif
		});

		inspector->show();
	}
}

static void dialog_calendar() { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m dialog_calendar()\n");

	QWidget *dialog = new QDialog(window, Qt::Window | Qt::Dialog);
	dialog->setWindowModality(Qt::ApplicationModal);
	dialog->setAttribute(Qt::WA_DeleteOnClose);
	dialog->setWindowTitle(QString("%1 - Qt %2.%3").arg("QDialog").arg(QT_VERSION_MAJOR).arg(QT_VERSION_MINOR));
	dialog->setObjectName("AwfDialogWindow");

	// QCalendar
	QCalendarWidget *calendar = new QCalendarWidget;
	calendar->setGridVisible(true);

	QPushButton *btnClose = new QPushButton(_qt("QMdiSubWindow", "&Close"));
	btnClose->setIcon(get_icon("dialog-close"));
	QObject::connect(btnClose, &QPushButton::clicked, dialog, [=](){
		dialog->close();
	});

	AwfHBox *buttonLayout = new AwfHBox;
	buttonLayout->addStretch();
	buttonLayout->addWidget(btnClose);

	AwfVBox *mainLayout = new AwfVBox;
	mainLayout->addWidget(calendar);
	mainLayout->addLayout(buttonLayout);
	dialog->setLayout(mainLayout);

	dialog->show();
}

static void dialog_sliders() { // ok

	if (awf_trace)
		printf("\033[36m[trace]\033[00m dialog_sliders()\n");

	QWidget *dialog = new QDialog(window, Qt::Window | Qt::Dialog);
	dialog->setWindowModality(Qt::ApplicationModal);
	dialog->setAttribute(Qt::WA_DeleteOnClose);
	dialog->setWindowTitle(QString("%1 - Qt %2.%3").arg("QDialog").arg(QT_VERSION_MAJOR).arg(QT_VERSION_MINOR));
	dialog->setObjectName("AwfDialogWindow");

	// QTabWidget
	QTabWidget *notebook = new QTabWidget;
	notebook->setTabPosition(QTabWidget::North);
	notebook->setTabsClosable(false);
	notebook->setUsesScrollButtons(false);
	notebook->tabBar()->setExpanding(false);
	notebook->tabBar()->setMovable(false);
		create_sliders(notebook, "top/left", QSlider::TicksAbove);
		create_sliders(notebook, "bottom/right", QSlider::TicksBelow);

	QPushButton *btnClose = new QPushButton(_qt("QMdiSubWindow", "&Close"));
	btnClose->setIcon(get_icon("dialog-close"));
	QObject::connect(btnClose, &QPushButton::clicked, dialog, [=](){
		dialog->close();
	});

	AwfHBox *buttonLayout = new AwfHBox;
	buttonLayout->addStretch();
	buttonLayout->addWidget(btnClose);

	AwfVBox *mainLayout = new AwfVBox;
	mainLayout->addWidget(notebook);
	mainLayout->addLayout(buttonLayout);
	dialog->setLayout(mainLayout);

	dialog->show();
}


#include "awf-qt6.moc"