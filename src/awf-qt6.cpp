/**
 * Forked  M/10/03/2020
 * Updated D/01/03/2026
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
 *  https://github.com/qt/qttranslations/blob/v6.10.1/translations/qtbase_fr.ts
 *  xgettext --keyword=_app -d awf -o src/awf.pot -k_ -s src/awf-*.c*
 *  msgmerge src/po/fr.po src/awf.pot -o src/po/fr.po
 *  msgfmt src/po/fr.po -o src/fr/LC_MESSAGES/awf.mo
 *
 * Tested with build.sh (via VirtualBox 7) with:
 *  Debian Testing 64                  (1536 MB) Qt 5.15/6.9
 *  Fedora Rawhide 64                  (1536 MB) Qt 5.15/6.10
 *  Ubuntu 25.10 Questing Quokka 64    (4096 MB) Qt 5.15/6.9
 *  Ubuntu 25.04 Plucky Puffin 64      (4096 MB) Qt 5.15/6.8
 *  Ubuntu 24.10 Oracular Oriole 64    (4096 MB) Qt 5.15/6.6
 *  Ubuntu 24.04 Noble Numbat 64       (4096 MB) Qt 5.15/6.4
 *  Ubuntu 23.10 Mantic Minotaur 64    (3072 MB) Qt 5.15/6.4*
 *  Ubuntu 23.04 Lunar Lobster 64      (3072 MB) Qt 5.15/6.4*
 *  Ubuntu 22.10 Kinetic Kudu 64       (2176 MB) Qt 5.15/6.3
 *  Ubuntu 22.04 Jammy Jellyfish 64    (2176 MB) Qt 5.15/6.2 (ko)
 */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#include <QAction>
#include <QActionGroup>
#include <QApplication>
#include <QButtonGroup>
#include <QCheckBox>
#include <QClipboard>
#include <QColorDialog>
#include <QComboBox>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QCommandLinkButton>
#include <QDir>
#include <QFileDialog>
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
#include <QStyleFactory>
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
#include <unistd.h>
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
static QStringList list_system_theme;
static QStringList list_user_theme;
static QMainWindow *window = nullptr;
static QLineEdit *toolbarentry = nullptr;
static QProgressBar *progressbar1 = nullptr, *progressbar2 = nullptr, *progressbar3 = nullptr, *progressbar4 = nullptr, *progressbar8 = nullptr, *progressbar9 = nullptr;
static QSlider *scale1 = nullptr, *scale2 = nullptr, *scale3 = nullptr, *scale4 = nullptr, *scale5 = nullptr, *scale6 = nullptr, *scale7 = nullptr;
static QTabWidget *notebook1 = nullptr, *notebook2 = nullptr, *notebook3 = nullptr, *notebook4 = nullptr;
static QWidget *inspector = nullptr;
static int current_direction  = 0;
static QString current_theme  = "auto";
static QString opt_theme      = "auto";
static QString opt_screenshot = nullptr;
static QString original_style = "";
static bool must_save_accels  = false;

// special (gtk_style_context_to_string)
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

class QHBoxLayoutt : public QHBoxLayout {
public:
	using QHBoxLayout::QHBoxLayout;
	void addWidget(QWidget *widget) {
		widget->setToolTip(generateTooltipRecursive(widget));
		QHBoxLayout::addWidget(widget);
	}
};

class QVBoxLayoutt : public QVBoxLayout {
public:
	using QVBoxLayout::QVBoxLayout;
	void addWidget(QWidget *widget) {
		widget->setToolTip(generateTooltipRecursive(widget));
		QVBoxLayout::addWidget(widget);
	}
};

// global functions
static void awf_load_theme(QStringList& themes, QString directory);
static void update_text_direction(int direction);
static void update_theme(QString new_theme);
static void update_statusbar(QString message);
static void update_values(QAbstractSlider *range);
static void update_widgets();
static void display_notification();
static void on_sighup(int signal);
static void take_screenshot();
static void create_window();
static void create_widgets(QVBoxLayoutt *root);
static void create_toolbar(QToolBar *toolbar);
static void create_combos_entries(QVBoxLayoutt *root);
static void create_spinbuttons(QHBoxLayoutt *root);
static void create_checkbuttons(QVBoxLayoutt *root);
static void create_radiobuttons(QVBoxLayoutt *root);
static void create_otherbuttons(QVBoxLayoutt *root1, QHBoxLayoutt *root2, QHBoxLayoutt *root3, QHBoxLayoutt *root4, QHBoxLayoutt *root5);
static void create_progressbars(QVBoxLayoutt *root1, QHBoxLayoutt *root2, QHBoxLayoutt *root3, QVBoxLayoutt *root4);
static void create_labels(QHBoxLayoutt *root);
static void create_spinners(QHBoxLayoutt *root);
static void create_expander(QVBoxLayoutt *root);
static void create_frames(QHBoxLayoutt *root1, QHBoxLayoutt *root2);
static void create_notebooks(QHBoxLayoutt *root1, QHBoxLayoutt *root2);
static void create_notebook_tab(QTabWidget *notebook, QString text, QWidget *content, bool close);
static void create_treview(QVBoxLayoutt *root);
static void create_scales();
static QSlider* create_horizontal_scale(int value, bool draw, bool inverted, QSlider::TickPosition position);
static QSlider* create_vertical_scale(int value, bool draw, bool inverted, QSlider::TickPosition position);
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
static void dialog_scales();


// other

class AwfTreeView : public QTreeView {
	Q_OBJECT
	Q_PROPERTY(QString columnWidths READ getColumnWidths WRITE setColumnWidths)

public:
	explicit AwfTreeView(QWidget* parent = nullptr) : QTreeView(parent) {

		/* connect(header(), &QHeaderView::sortIndicatorChanged, this, [this](int column, Qt::SortOrder) {

			QString normalColor = getSortedColumnColor(), altColor = getAlternateSortedColumnColor();
			if (!normalColor.isEmpty()) {

				QAbstractItemModel* m = model();
				QVariant color;

				for (int c = 0; c < m->columnCount(); ++c)
					for (int r = 0; r < m->rowCount(); ++r)
						m->setData(m->index(r, c), QVariant(), Qt::BackgroundRole);

				for (int r = 0; r < m->rowCount(); ++r) {
					color = QVariant(QColor(altColor.isEmpty() ? normalColor : ((r % 2 == 0) ? normalColor : altColor)));
					m->setData(m->index(r, column), color, Qt::BackgroundRole);
				}
			}
		}); */
	}

	QString getColumnWidths() {
		QStringList list;
		for (int i = 0; i < 11; ++i)
			list << QString::number(columnWidth(i));
		return list.join(",");
	}

	void setColumnWidths(QString widths) {
		QStringList list = widths.split(",", Qt::SkipEmptyParts);
		for (int i = 0; i < list.size() && i < 11; ++i)
			setColumnWidth(i, list[i].trimmed().toInt());
	}
};

class ProgressDelegate : public QStyledItemDelegate {
public:
	ProgressDelegate(QAbstractItemView* view) : QStyledItemDelegate(view) {
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

class RadioDelegate : public QStyledItemDelegate {
public:
	RadioDelegate(QAbstractItemView* view) : QStyledItemDelegate(view) {
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

class ShortcutFilter : public QObject {
public:
	bool eventFilter(QObject *obj, QEvent *event) override {
		if (accels_change(obj, event))
			return true;
		return QObject::eventFilter(obj, event);
	}
};


// run run run

int main(int argc, char **argv) {

	int opt = 0, status = 0;
	QApplication app(argc, argv);

	if (qEnvironmentVariableIsSet("GQSS_SET")) {

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
	QLocale::setDefault(QLocale::system());

	QTranslator *qtTr = new QTranslator(qApp);
	if (qtTr->load("qt_" + QLocale::system().name(), QLibraryInfo::path(QLibraryInfo::TranslationsPath)))
		qApp->installTranslator(qtTr);

	QTranslator *qtBaseTr = new QTranslator(qApp);
	if (qtBaseTr->load("qtbase_" + QLocale::system().name(), QLibraryInfo::path(QLibraryInfo::TranslationsPath)))
		qApp->installTranslator(qtBaseTr);

	setlocale(LC_ALL, "");
	if (QDir("/usr/share/locale").exists())
		bindtextdomain(GETTEXT_PACKAGE, "/usr/share/locale");
	bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
	textdomain(GETTEXT_PACKAGE);

	// init
	static struct option long_options[] = {
		{"version",     no_argument, nullptr, 'v'},
		{"list-themes", no_argument, nullptr, 'l'},
		{"theme",       required_argument, nullptr, 't'},
		{"screenshot",  required_argument, nullptr, 's'},
		{"help",        no_argument, nullptr, 'x'},
		{"ltr",         no_argument, nullptr, 'y'},
		{"rtl",         no_argument, nullptr, 'z'},
		{nullptr, 0, nullptr, 0}
	};

	while ((opt = getopt_long(argc, argv, "vlt:s:hxyz", long_options, nullptr)) != -1) {
		switch (opt) {
			// --version -v
			case 'v':
				printf("%s\n", VERSION);
				return status;
			// --list-themes -l
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
				printf("%s\n\n  %s %s\n  %s %s\n  %s %s\n  %s %s\n  %s %s\n  %s %s\n\n%s\n%s\n",
					qPrintable(QString(_app("A widget factory - Qt %1.%2")).arg(QT_VERSION_MAJOR).arg(QT_VERSION_MINOR)),
					"-v            ", qPrintable(_app("Show version number.")),
					"-l            ", qPrintable(_app("List available themes.")),
					"-t <theme>    ", qPrintable(_app("Run with the specified theme.")),
					"-s <filename> ", qPrintable(QString(_app("Run and save a png screenshot on %1.")).arg("SIGHUP")),
					"--ltr         ", qPrintable(_app("Start with text from left to right (Left-To-Right).")),
					"--rtl         ", qPrintable(_app("Start with text from right to left (Right-To-Left).")),
					qPrintable(QString(_app("compiled with qt %1.%2.%3")).arg(QT_VERSION_MAJOR).arg(QT_VERSION_MINOR).arg(QT_VERSION_PATCH)),
					qPrintable(QString(_app(" started with qt %1")).arg(qVersion())));
				return status;
		}
	}

	// create and show window
	std::signal(SIGHUP, on_sighup);

	QCommandLineParser parser;
	parser.setApplicationDescription(_app("A widget factory - Qt %1.%2").arg(QT_VERSION_MAJOR).arg(QT_VERSION_MINOR));
	parser.addHelpOption();
	parser.addVersionOption(); // << "v" << "version", _app("Show version number.")));
	parser.addOption(QCommandLineOption(QStringList() << "l" << "list-themes", _app("List available themes.")));
	parser.addOption(QCommandLineOption(QStringList() << "t" << "theme", _app("Run with the specified theme."), "theme"));
	parser.addOption(QCommandLineOption(QStringList() << "s" << "screenshot", QString(_app("Run and save a png screenshot on %1.").arg("SIGHUP")), "filename"));
	parser.addOption(QCommandLineOption(QStringList() << "y" << "ltr", _app("Start with text from left to right (Left-To-Right).")));
	parser.addOption(QCommandLineOption(QStringList() << "z" << "rtl", _app("Start with text from right to left (Right-To-Left).")));
	parser.process(app);

	create_window();
	return app.exec();
}

static void awf_load_theme(QStringList& themes, QString directory) {

	QDir dir(directory);
	if (dir.exists()) {

		if (qEnvironmentVariableIsSet("AWF_DEBUG"))
			printf("themes dir: %s\n", directory.toUtf8().constData());

		QStringList entries = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
		for (QString theme : entries) {
			if (QDir(QDir(dir.filePath(theme)).filePath("qt6")).exists())
			    themes.append(theme);
		}
	}
}

static void update_text_direction(int direction) { // ok

	if ((direction == 1) && (qApp->layoutDirection() != Qt::LeftToRight)) {
		current_direction = 1;
		notebook3->setTabPosition(QTabWidget::West);
		notebook4->setTabPosition(QTabWidget::East);
		qApp->setLayoutDirection(Qt::LeftToRight);
	}
	else if ((direction == 2) && (qApp->layoutDirection() != Qt::RightToLeft)) {
		current_direction = 2;
		notebook3->setTabPosition(QTabWidget::East);
		notebook4->setTabPosition(QTabWidget::West);
		qApp->setLayoutDirection(Qt::RightToLeft);
	}
}

static void update_theme(QString new_theme) { // ok

	if (qEnvironmentVariableIsSet("GQSS_SET")) {

		if (new_theme == "refresh") {

			qputenv("GQSS_RELOAD", "yes");

			QApplication::setStyle(QStyleFactory::create("GlobalQSS"));
			update_statusbar(_app("Theme %1 reloaded.").arg(current_theme));
			window->adjustSize();

			if (!opt_screenshot.isEmpty())
				QTimer::singleShot(1000, take_screenshot);
		}
		else if (new_theme == "auto") {
			current_theme = QString::fromUtf8(qgetenv("GQSS_THEME"));
		}
		else if (current_theme != new_theme) {

			qputenv("GQSS_RELOAD", "yes");
			qputenv("GQSS_THEME", new_theme.toUtf8());

			current_theme = new_theme;
			QApplication::setStyle(QStyleFactory::create("GlobalQSS"));
			update_statusbar(_app("Theme %1 loaded.").arg(current_theme));
			window->adjustSize();
		}

		original_style = "";
	}
}

static void update_statusbar(QString message) { // ok

	if (window && window->statusBar())
		window->statusBar()->showMessage(QTime::currentTime().toString("HH:mm:ss") + " - " + message, 0);
}

static void update_values(QAbstractSlider *range) { // ok

	// range(0..100)
	int value = range->value();

	progressbar1->setValue(value);
	progressbar2->setValue(value);
	progressbar3->setValue(value);
	progressbar4->setValue(value);
	progressbar8->setValue(value);
	progressbar9->setValue(value);

	if (scale1 != range) scale1->setValue(value);
	if (scale2 != range) scale2->setValue(value);
	if (scale3 != range) scale3->setValue(value);
	if (scale4 != range) scale4->setValue(value);
	if (scale5 != range) scale5->setValue(value);
	if (scale6 != range) scale6->setValue(value);
	if (scale7 != range) scale7->setValue(value);

	// text
	progressbar8->setTextVisible(value > 50);
	progressbar8->setProperty("textVisible", value > 50);
	progressbar8->style()->polish(progressbar8);
	progressbar8->updateGeometry();

	progressbar9->setTextVisible(value > 50);
	progressbar9->setProperty("textVisible", value > 50);
	progressbar9->style()->polish(progressbar9);
	progressbar9->updateGeometry();
}

static void update_widgets() { // ok

	// function called when user click on [+] toolbar button
	// when toggle = true, the [+] toolbar button is NOT checked
	int width1, width2, height1, height2;
	bool toggle = notebook1->tabBar()->usesScrollButtons();

	// show progressbar in toolbar and statusbar when [+] toolbar button is NOT checked
	if (toggle) {
		qobject_cast<QAction*>(progressbar8->property("action").value<QObject*>())->setVisible(false);
		progressbar9->setVisible(false);
		qobject_cast<QAction*>(toolbarentry->property("action").value<QObject*>())->setVisible(false);
	}
	else {
		progressbar8->setValue(0);
		progressbar9->setValue(0);
		qobject_cast<QAction*>(progressbar8->property("action").value<QObject*>())->setVisible(true);
		progressbar9->setVisible(true);
		qobject_cast<QAction*>(toolbarentry->property("action").value<QObject*>())->setVisible(true);
	}

	// enabled or not
	scale2->setEnabled(toggle);
	scale4->setEnabled(toggle);
	scale6->setEnabled(toggle);
	scale7->setEnabled(toggle);
	progressbar2->setEnabled(toggle);
	progressbar4->setEnabled(toggle);

	// text or not
	progressbar1->setTextVisible(!toggle);
	progressbar1->setProperty("textVisible", !toggle);
	progressbar1->style()->polish(progressbar1);
	progressbar1->updateGeometry();

	progressbar2->setTextVisible(!toggle);
	progressbar2->setProperty("textVisible", !toggle);
	progressbar2->style()->polish(progressbar2);
	progressbar2->updateGeometry();

	progressbar3->setTextVisible(!toggle);
	progressbar3->setProperty("textVisible", !toggle);
	progressbar3->style()->polish(progressbar3);
	progressbar3->updateGeometry();

	progressbar4->setTextVisible(!toggle);
	progressbar4->setProperty("textVisible", !toggle);
	progressbar4->style()->polish(progressbar4);
	progressbar4->updateGeometry();

	progressbar8->setTextVisible(false);
	progressbar8->setProperty("textVisible", false);
	progressbar8->style()->polish(progressbar8);
	progressbar8->updateGeometry();

	progressbar9->setTextVisible(false);
	progressbar9->setProperty("textVisible", false);
	progressbar9->style()->polish(progressbar9);
	progressbar9->updateGeometry();

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

	if (fork() == 0) {
		execlp("notify-send", "notify-send", "-i", "dialog-information", "-t", "50000", "--action", _qt("QShortcut", "Close").toUtf8().constData(), GETTEXT_PACKAGE, _app("A widget factory is a theme preview application for GTK and Qt. It displays the various widget types in a single window allowing to see the visual effect of the applied theme.").toUtf8().constData(), nullptr);
		_exit(1);
	}
}

static void on_sighup(int signal) { // ok
	update_theme("refresh");
}

static void take_screenshot() { // ok (without window borders)

	QPixmap pixmap = window->grab();
	pixmap.save(opt_screenshot, "PNG", 100);
	update_statusbar(QString(_app("Theme reloaded, then screenshot saved (%1).")).arg(opt_screenshot));
}


// layout and widgets

static void create_window() {

	// window
	QApplication::setApplicationName("awf");
	QApplication::setWindowIcon(QIcon::fromTheme(GETTEXT_PACKAGE));

	window = new QMainWindow;
	window->setWindowTitle(_app("A widget factory - Qt %1.%2").arg(QT_VERSION_MAJOR).arg(QT_VERSION_MINOR));
	window->setWindowIcon(QIcon::fromTheme(GETTEXT_PACKAGE));
	window->setObjectName("AwfMainWindow");

	// theme auto or from command line
	if (qEnvironmentVariableIsSet("GQSS_SET"))
		update_theme((current_theme != opt_theme) ? opt_theme : current_theme);

	if (current_direction == 0)
		current_direction = (qApp->layoutDirection() == Qt::LeftToRight) ? 1 : 2;

	// layout
	QVBoxLayoutt *layout = new QVBoxLayoutt;
	QWidget *central = new QWidget;
	window->setCentralWidget(central);
		layout->setSpacing(0);
		layout->setContentsMargins(0,0,0,0);
		create_widgets(layout);
		central->setLayout(layout);

	QMenuBar *menubar = window->menuBar();
	menubar->setContextMenuPolicy(Qt::PreventContextMenu);
	create_traditional_menubar(menubar);

	QToolBar *toolbar = new QToolBar;
	toolbar->setMovable(false);
	toolbar->setFloatable(false);
	toolbar->setContextMenuPolicy(Qt::PreventContextMenu);
	create_toolbar(toolbar);
	window->addToolBar(toolbar);

	update_statusbar(_app("Theme %1 loaded.").arg(current_theme));
	progressbar9 = new QProgressBar;
	progressbar9->setMaximumWidth(140);
	progressbar9->setFixedHeight(16);
	progressbar9->setVisible(false);
	window->statusBar()->addPermanentWidget(progressbar9);

	QLocale locale;
	if ((locale.language() == QLocale::French) && (locale.territory() == QLocale::France))
		progressbar9->setFormat("%p %");

	// go go go
	update_text_direction(current_direction);
	window->show();
	QObject::connect(qApp, &QCoreApplication::aboutToQuit, []() {
		accels_save();
	});
}

static void create_widgets(QVBoxLayoutt *root) { // todo

	auto *hbox_columns = new QHBoxLayoutt;
	hbox_columns->setSpacing(0);         hbox_columns->setContentsMargins(0,0,0,0);

	auto *vbox_column1 = new QVBoxLayoutt, *vbox_combo_entry = new QVBoxLayoutt, *vbox_check = new QVBoxLayoutt, *vbox_radio = new QVBoxLayoutt;
	auto *hbox_spin = new QHBoxLayoutt, *hbox_check_radio = new QHBoxLayoutt;
	vbox_column1->setSpacing(0);         vbox_column1->setContentsMargins(5,5,5,5);
	vbox_combo_entry->setSpacing(3);     vbox_combo_entry->setContentsMargins(5,5,5,5);
	hbox_spin->setSpacing(0);            hbox_spin->setContentsMargins(5,5,5,5);
	hbox_check_radio->setSpacing(0);     hbox_check_radio->setContentsMargins(5,5,5,5);
	vbox_check->setSpacing(0);           vbox_check->setContentsMargins(0,0,0,0);
	vbox_radio->setSpacing(0);           vbox_radio->setContentsMargins(0,0,0,0);

	auto *vbox_column2 = new QVBoxLayoutt, *vbox_buttons = new QVBoxLayoutt;
	auto *hbox_btns1 = new QHBoxLayoutt, *hbox_btns2 = new QHBoxLayoutt, *hbox_btns3 = new QHBoxLayoutt, *hbox_btns4 = new QHBoxLayoutt;
	vbox_column2->setSpacing(0);         vbox_column2->setContentsMargins(5,5,5,5);
	vbox_buttons->setSpacing(3);         vbox_buttons->setContentsMargins(5,5,5,5);
	hbox_btns1->setSpacing(3);           hbox_btns1->setContentsMargins(5,5,5,5);
	hbox_btns2->setSpacing(3);           hbox_btns2->setContentsMargins(5,5,5,5);
	hbox_btns3->setSpacing(3);           hbox_btns3->setContentsMargins(5,5,5,5);
	hbox_btns4->setSpacing(3);           hbox_btns4->setContentsMargins(5,5,5,5);

	auto *vbox_column3 = new QVBoxLayoutt, *vbox_progressbar1 = new QVBoxLayoutt, *vbox_progressbar2 = new QVBoxLayoutt;
	auto *hbox_progressbar1 = new QHBoxLayoutt, *hbox_progressbar2 = new QHBoxLayoutt;
	vbox_column3->setSpacing(0);         vbox_column3->setContentsMargins(5,5,5,5);
	vbox_progressbar1->setSpacing(10);   vbox_progressbar1->setContentsMargins(6,6,6,6);
	vbox_progressbar2->setSpacing(10);   vbox_progressbar2->setContentsMargins(5,5,5,5);
	hbox_progressbar1->setSpacing(10);   hbox_progressbar1->setContentsMargins(5,5,5,5);
	hbox_progressbar2->setSpacing(10);   hbox_progressbar2->setContentsMargins(5,5,5,5);

	auto *vbox_column4 = new QVBoxLayoutt, *vbox_others = new QVBoxLayoutt;
	auto *hbox_label = new QHBoxLayoutt, *hbox_spinner = new QHBoxLayoutt;
	vbox_column4->setSpacing(0);         vbox_column4->setContentsMargins(5,5,5,5);
	vbox_others->setSpacing(3);          vbox_others->setContentsMargins(5,5,5,5);
	hbox_label->setSpacing(0);           hbox_label->setContentsMargins(5,5,5,5);
	hbox_spinner->setSpacing(0);         hbox_spinner->setContentsMargins(5,5,5,5);

	auto *vpane = new QSplitter(Qt::Vertical), *hpane1 = new QSplitter(Qt::Horizontal), *hpane2 = new QSplitter(Qt::Horizontal);
	vpane->setContentsMargins(0,0,0,0);
	hpane1->setContentsMargins(0,0,0,0);
	hpane2->setContentsMargins(0,0,0,0);

	auto *wbox_frame1 = new QWidget, *wbox_frame2 = new QWidget, *wbox_notebook1 = new QWidget, *wbox_notebook2 = new QWidget;
	wbox_frame1->setContentsMargins(0,0,0,0);
	wbox_frame2->setContentsMargins(0,0,0,0);
	wbox_notebook1->setContentsMargins(0,0,0,0);
	wbox_notebook2->setContentsMargins(0,0,0,0);

	auto *hbox_frame1 = new QHBoxLayoutt, *hbox_frame2 = new QHBoxLayoutt, *hbox_notebook1 = new QHBoxLayoutt, *hbox_notebook2 = new QHBoxLayoutt;
	hbox_frame1->setSpacing(3);          hbox_frame1->setContentsMargins(10,10,10,10);
	hbox_frame2->setSpacing(3);          hbox_frame2->setContentsMargins(10,10,10,10);
	hbox_notebook1->setSpacing(3);       hbox_notebook1->setContentsMargins(10,10,10,10);
	hbox_notebook2->setSpacing(3);       hbox_notebook2->setContentsMargins(10,10,10,10);

	QFrame *sep1 = new QFrame, *sep2 = new QFrame, *sep3 = new QFrame, *sep4 = new QFrame;
	sep1->setFrameShape(qEnvironmentVariableIsSet("GQSS_SET") ? QFrame::NoFrame : QFrame::VLine);
	sep1->setFrameShadow(QFrame::Plain);
	sep1->setProperty("class", "separator vertical");
	sep2->setFrameShape(qEnvironmentVariableIsSet("GQSS_SET") ? QFrame::NoFrame : QFrame::VLine);
	sep2->setFrameShadow(QFrame::Plain);
	sep2->setProperty("class", "separator vertical");
	sep3->setFrameShape(qEnvironmentVariableIsSet("GQSS_SET") ? QFrame::NoFrame : QFrame::VLine);
	sep3->setFrameShadow(QFrame::Plain);
	sep3->setProperty("class", "separator vertical");
	sep4->setFrameShape(qEnvironmentVariableIsSet("GQSS_SET") ? QFrame::NoFrame : QFrame::HLine);
	sep4->setFrameShadow(QFrame::Plain);
	sep4->setProperty("class", "separator horizontal");

	// columns layout
	root->addLayout(hbox_columns);

		// column 1
		hbox_columns->addLayout(vbox_column1);
			vbox_column1->addLayout(vbox_combo_entry);
				create_combos_entries(vbox_combo_entry);
			vbox_column1->addLayout(hbox_spin);
				create_spinbuttons(hbox_spin);
			vbox_column1->addLayout(hbox_check_radio);
				hbox_check_radio->addLayout(vbox_check);
					create_checkbuttons(vbox_check);
				hbox_check_radio->addLayout(vbox_radio);
					create_radiobuttons(vbox_radio);
			vbox_column1->addStretch();
		hbox_columns->addWidget(sep1);

		// column 2
		hbox_columns->addLayout(vbox_column2);
			vbox_column2->addLayout(vbox_buttons);
			vbox_column2->addLayout(hbox_btns1);
			vbox_column2->addLayout(hbox_btns2);
			vbox_column2->addLayout(hbox_btns3);
			vbox_column2->addLayout(hbox_btns4);
				create_otherbuttons(vbox_buttons, hbox_btns1, hbox_btns2, hbox_btns3, hbox_btns4);
			vbox_column2->addStretch();
		hbox_columns->addWidget(sep2);

		// column 3
		hbox_columns->addLayout(vbox_column3);
			vbox_column3->addLayout(vbox_progressbar1);
			vbox_column3->addLayout(hbox_progressbar1);
			vbox_column3->addLayout(hbox_progressbar2);
			vbox_column3->addLayout(vbox_progressbar2);
				create_progressbars(vbox_progressbar1, hbox_progressbar1, hbox_progressbar2, vbox_progressbar2);
			vbox_column3->addStretch();
		hbox_columns->addWidget(sep3);

		// column 4
		hbox_columns->addLayout(vbox_column4);
			vbox_column4->addLayout(vbox_others);
				create_treview(vbox_others);
				vbox_others->addLayout(hbox_label);
					create_labels(hbox_label);
				vbox_others->addLayout(hbox_spinner);
					create_spinners(hbox_spinner);
				create_expander(vbox_others);
			vbox_column4->addStretch();

	root->addWidget(sep4);

	// paned layout
	root->addWidget(vpane);

		vpane->addWidget(hpane1);

			wbox_frame1->setMinimumHeight(70); // The 70
			wbox_frame1->setLayout(hbox_frame1);
			hpane1->addWidget(wbox_frame1);

			wbox_frame2->setMinimumHeight(70); // The 70
			wbox_frame2->setLayout(hbox_frame2);
			hpane1->addWidget(wbox_frame2);

			create_frames(hbox_frame1, hbox_frame2);

		vpane->addWidget(hpane2);

			//wbox_notebook1->setMinimumHeight(120); // The 120
			wbox_notebook1->setLayout(hbox_notebook1);
			hpane2->addWidget(wbox_notebook1);

			//wbox_notebook2->setMinimumHeight(120); // The 120
			wbox_notebook2->setLayout(hbox_notebook2);
			hpane2->addWidget(wbox_notebook2);

			create_notebooks(hbox_notebook1, hbox_notebook2);
			hpane2->setSizes({wbox_notebook1->sizeHint().width(), 10000});
}

static void create_toolbar(QToolBar *toolbar) { // ok

	QToolButton *tool1, *tool2, *tool3, *tool4, *tool5, *tool6, *tool8, *tool9, *tool10;
	QAction *action1, *action2;
	QWidget *spacer;
	QMenu *menu;

	// QToolButton
	menu = new QMenu;
	menu->addAction("Menu item 1");
	menu->addAction("Menu item 2");
	menu->addAction("Menu item 3");
	tool1 = new QToolButton;
	tool1->setMenu(menu);
	tool1->setIcon(QIcon::fromTheme("document-open"));
	tool1->setPopupMode(QToolButton::MenuButtonPopup);
	tool1->setProperty("hasMenu", true);
	QObject::connect(tool1, &QToolButton::clicked, dialog_open);

	tool2 = new QToolButton;
	tool2->setIcon(QIcon::fromTheme("document-open"));
	tool2->setPopupMode(QToolButton::MenuButtonPopup);
	tool2->setProperty("hasMenu", true);
	tool2->setEnabled(false);

	tool3 = new QToolButton;
	tool3->setIcon(QIcon::fromTheme("document-save"));
	QObject::connect(tool3, &QToolButton::clicked, dialog_save);

	tool4 = new QToolButton;
	tool4->setIcon(QIcon::fromTheme("view-refresh"));
	tool4->setEnabled(qEnvironmentVariableIsSet("GQSS_SET"));
	QObject::connect(tool4, &QToolButton::clicked, [](){ update_theme("refresh"); });

	tool5 = new QToolButton;
	tool5->setIcon(QIcon::fromTheme("camera-photo"));
	tool5->setEnabled(opt_screenshot.isEmpty() ? false : true);
	QObject::connect(tool5, &QToolButton::clicked, take_screenshot);

	tool6 = new QToolButton;
	tool6->setIcon(QIcon::fromTheme("dialog-information"));
	QObject::connect(tool6, &QToolButton::clicked, display_notification);

	tool8 = new QToolButton;
	tool8->setCheckable(true);
	tool8->setChecked(true);
	tool8->setIcon(QIcon::fromTheme("list-add"));
	QObject::connect(tool8, &QToolButton::clicked, update_widgets);

	tool9 = new QToolButton;
	tool9->setCheckable(true);
	tool9->setChecked(false);
	tool9->setIcon(QIcon::fromTheme("list-remove"));
	QObject::connect(tool9, &QToolButton::clicked, update_widgets);

	tool10 = new QToolButton;
	tool10->setCheckable(true);
	tool10->setChecked(false);
	tool10->setIcon(QIcon::fromTheme("window-close"));
	tool10->setEnabled(false);

	toolbarentry = new QLineEdit;
	toolbarentry->setPlaceholderText("...");
	toolbarentry->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

	spacer = new QWidget;
	spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

	progressbar8 = new QProgressBar;
	progressbar8->setValue(0);
	progressbar8->setOrientation(Qt::Horizontal);
	progressbar8->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

	QLocale locale;
	if ((locale.language() == QLocale::French) && (locale.territory() == QLocale::France))
		progressbar8->setFormat("%p %");

	// layout
	toolbar->addWidget(tool1);
	toolbar->addWidget(tool2);
	toolbar->addWidget(tool3);
	toolbar->addSeparator();
	toolbar->addWidget(tool4);
	toolbar->addWidget(tool5);
	toolbar->addWidget(tool6);
	toolbar->addSeparator();
	toolbar->addWidget(tool8);
	toolbar->addWidget(tool9);
	toolbar->addWidget(tool10);
	action1 = toolbar->addWidget(toolbarentry);
	toolbar->addWidget(spacer);
	action2 = toolbar->addWidget(progressbar8);

	// links
	action1->setVisible(false);
	toolbarentry->setProperty("action", QVariant::fromValue<QObject*>(action1));

	action2->setVisible(false);
	progressbar8->setProperty("action", QVariant::fromValue<QObject*>(action2));
}

static void create_combos_entries(QVBoxLayoutt *root) { // ok

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

static void create_spinbuttons(QHBoxLayoutt *root) { // ok

	QSpinBox *spinbutton1, *spinbutton2;

	// QSpinBox
	spinbutton1 = new QSpinBox;
	spinbutton1->setRange(-100, 100);
	spinbutton1->setSingleStep(1);
	spinbutton1->setValue(1);
	spinbutton1->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	spinbutton2 = new QSpinBox;
	spinbutton2->setRange(-100, 100);
	spinbutton2->setSingleStep(1);
	spinbutton2->setValue(1);
	spinbutton2->setEnabled(false);
	spinbutton2->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	// layout
	root->addWidget(spinbutton1);
	root->addStretch();
	root->addWidget(spinbutton2);
}

static void create_checkbuttons(QVBoxLayoutt *root) { // ok

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

static void create_radiobuttons(QVBoxLayoutt *root) { // ok

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
	group1 = new QButtonGroup;
	group1->addButton(radiobutton1);
	group1->addButton(radiobutton2);
	group1->addButton(radiobutton3);

	group2 = new QButtonGroup;
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

static void create_otherbuttons(QVBoxLayoutt *root1, QHBoxLayoutt *root2, QHBoxLayoutt *root3, QHBoxLayoutt *root4, QHBoxLayoutt *root5) { // ok

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
		QColorDialog::getColor(QColor("#7796ba"), nullptr, "QColorDialog");
	});

	button6 = new QPushButton(_app("Choose a font"));
	button6->setMinimumWidth(186); // The 186
	button6->setProperty("class", "awf-cheatcode-fontbtn");
	QObject::connect(button6, &QPushButton::clicked, [=](){
		bool ok;
		QFontDialog::getFont(&ok, QFont(), nullptr, "QFontDialog");
	});

	button7 = new QPushButton(_app("Choose a file"));
	button7->setMinimumWidth(186); // The 186
	button7->setProperty("class", "awf-cheatcode-filebtn");
	QObject::connect(button7, &QPushButton::clicked, [=](){
		QFileDialog::getOpenFileName(nullptr, "QFileDialog:Open", QString());
	});

	button8 = new QPushButton(_app("Choose a folder"));
	button8->setMinimumWidth(186); // The 186
	button8->setProperty("class", "awf-cheatcode-folderbtn");
	QObject::connect(button8, &QPushButton::clicked, [=](){
		QFileDialog::getExistingDirectory(nullptr, "QFileDialog:Open", QString());
	});

	// layout
	root1->addWidget(button1);
	root1->addWidget(button2);
	root1->addWidget(button3);
	root1->addWidget(button4);
	root1->addWidget(button5);
	root1->addWidget(button6);
	root1->addWidget(button7);
	root1->addWidget(button8);
	root2->addStretch();
	root3->addStretch();
	root4->addStretch();
	root5->addStretch();
}

static void create_progressbars(QVBoxLayoutt *root1, QHBoxLayoutt *root2, QHBoxLayoutt *root3, QVBoxLayoutt *root4) { // ok

	// QProgressBar
	progressbar1 = new QProgressBar;
	progressbar1->setOrientation(Qt::Horizontal);
	progressbar1->setTextVisible(false);
	progressbar1->setValue(50);

	progressbar2 = new QProgressBar;
	progressbar2->setOrientation(Qt::Horizontal);
	progressbar2->setTextVisible(false);
	progressbar2->setValue(50);
	progressbar2->setInvertedAppearance(true);
	progressbar2->setProperty("class", "awf-cheatcode-prbr2");
	progressbar2->setProperty("isInverted", true);

	progressbar3 = new QProgressBar;
	progressbar3->setOrientation(Qt::Vertical);
	progressbar3->setTextVisible(false);
	progressbar3->setValue(50);
	progressbar3->setInvertedAppearance(true);
	progressbar3->setFixedHeight(100);
	progressbar3->setProperty("isInverted", true);

	progressbar4 = new QProgressBar;
	progressbar4->setOrientation(Qt::Vertical);
	progressbar4->setTextVisible(false);
	progressbar4->setValue(50);
	progressbar4->setFixedHeight(100);

	QLocale locale;
	if ((locale.language() == QLocale::French) && (locale.territory() == QLocale::France)) {
		progressbar1->setFormat("%p %");
		progressbar2->setFormat("%p %");
		progressbar3->setFormat("%p %");
		progressbar4->setFormat("%p %");
	}

	// QSlider
	scale1 = create_horizontal_scale(50, false, false, QSlider::NoTicks);
	QObject::connect(scale1, &QSlider::valueChanged, [=](int){ update_values(scale1); });

	scale2 = create_horizontal_scale(50, false, true, QSlider::NoTicks);
	scale2->setProperty("isInverted", true);
	QObject::connect(scale2, &QSlider::valueChanged, [=](int){ update_values(scale2); });

	scale3 = create_vertical_scale(50, false, false, QSlider::NoTicks);
	QObject::connect(scale3, &QSlider::valueChanged, [=](int){ update_values(scale3); });

	scale4 = create_vertical_scale(50, false, true, QSlider::NoTicks);
	scale4->setProperty("isInverted", true);
	QObject::connect(scale4, &QSlider::valueChanged, [=](int){ update_values(scale4); });

	scale5 = create_vertical_scale(50, false, false, QSlider::TicksAbove);
	scale5->setProperty("hasTicks", "TicksAbove");
	QObject::connect(scale5, &QSlider::valueChanged, [=](int){ update_values(scale5); });

	scale6 = create_vertical_scale(50, false, true, QSlider::TicksBelow);
	scale6->setProperty("hasTicks", "TicksBelow");
	scale6->setProperty("isInverted", true);
	QObject::connect(scale6, &QSlider::valueChanged, [=](int){ update_values(scale6); });

	scale7 = create_vertical_scale(50, false, true, QSlider::TicksBothSides);
	scale7->setProperty("hasTicks", "TicksBothSides");
	QObject::connect(scale7, &QSlider::valueChanged, [=](int){ update_values(scale7); });

	// layout
	root1->addWidget(progressbar1);
	root1->addWidget(progressbar2);
	root1->addWidget(scale1);
	root1->addWidget(scale2);
	root2->addWidget(progressbar3);
	root2->addWidget(progressbar4);
	root2->addStretch();
	root3->addWidget(scale3);
	root3->addWidget(scale5);
	root3->addWidget(scale6);
	root3->addWidget(scale4);
	root3->addWidget(scale7);
	root3->addStretch();
	root4->addStretch();
}

static void create_labels(QHBoxLayoutt *root) { // ok

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

static void create_spinners(QHBoxLayoutt *root) {

}

static void create_expander(QVBoxLayoutt *root) { // todo

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
	QVBoxLayoutt *expanderLayout = new QVBoxLayoutt(expander);
	expanderLayout->addWidget(text);
	root->addWidget(expander);
}

static void create_frames(QHBoxLayoutt *root1, QHBoxLayoutt *root2) { // todo

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

static void create_notebooks(QHBoxLayoutt *root1, QHBoxLayoutt *root2) { // ok

	// QTabWidget
	notebook1 = new QTabWidget;
	notebook1->setTabPosition(QTabWidget::North);
	notebook1->setTabsClosable(false);
	notebook1->setUsesScrollButtons(false);
	notebook1->tabBar()->setExpanding(false);
	notebook1->tabBar()->setMovable(true);
		create_notebook_tab(notebook1, "Tab1", nullptr, false);
		create_notebook_tab(notebook1, "Tab2", nullptr, false);
		create_notebook_tab(notebook1, "Tab3", nullptr, true);
		create_notebook_tab(notebook1, "Tab4", nullptr, true);

	notebook2 = new QTabWidget;
	notebook2->setTabPosition(QTabWidget::South);
	notebook2->setTabsClosable(false);
	notebook2->setUsesScrollButtons(false);
	notebook2->tabBar()->setExpanding(false);
	notebook2->tabBar()->setMovable(true);
		create_notebook_tab(notebook2, "Tab1", nullptr, false);
		create_notebook_tab(notebook2, "Tab2", nullptr, false);
		create_notebook_tab(notebook2, "Tab3", nullptr, true);
		create_notebook_tab(notebook2, "Tab4", nullptr, true);

	notebook3 = new QTabWidget;
	notebook3->setTabPosition(QTabWidget::West);
	notebook3->setTabsClosable(false);
	notebook3->setUsesScrollButtons(false);
	notebook3->tabBar()->setExpanding(false);
	notebook3->tabBar()->setMovable(true);
		create_notebook_tab(notebook3, "T1", nullptr, false);
		create_notebook_tab(notebook3, "Tab2", nullptr, false);
		create_notebook_tab(notebook3, "T3b", nullptr, true);
		create_notebook_tab(notebook3, "T4", nullptr, true);

	notebook4 = new QTabWidget;
	notebook4->setTabPosition(QTabWidget::East);
	notebook4->setTabsClosable(false);
	notebook4->setUsesScrollButtons(false);
	notebook4->tabBar()->setExpanding(false);
	notebook4->tabBar()->setMovable(true);
		create_notebook_tab(notebook4, "T1", nullptr, false);
		create_notebook_tab(notebook4, "Tab2", nullptr, false);
		create_notebook_tab(notebook4, "T3b", nullptr, true);
		create_notebook_tab(notebook4, "T4", nullptr, true);

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
			btn->setIcon(QIcon::fromTheme("window-close"));
			btn->setIconSize(QSize(16, 16));
			btn->setAutoRaise(true); // flat

			QHBoxLayoutt *hbox = new QHBoxLayoutt(layout);
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
		btn->setIcon(QIcon::fromTheme("window-close"));
		btn->setIconSize(QSize(16, 16));
		btn->setAutoRaise(true); // flat
		notebook->tabBar()->setTabButton(notebook->addTab(content, text), QTabBar::RightSide, btn);
	}
	else {
		notebook->addTab(content, text);
	}
}

static void create_treview(QVBoxLayoutt *root) { // ok

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
		auto it7  = new QStandardItem; it7->setIcon(QIcon::fromTheme(h)); it7->setEditable(false);
		auto it8  = new QStandardItem; it8->setIcon(QIcon::fromTheme(i)); it8->setEditable(false); it8->setEnabled(false);
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
	view->setItemDelegateForColumn(2, new RadioDelegate(view));
	view->setItemDelegateForColumn(4, new ProgressDelegate(view));
	view->setItemDelegateForColumn(5, new ProgressDelegate(view));
	view->setItemDelegateForColumn(10, new RadioDelegate(view));
	view->header()->setStretchLastSection(false);
	view->header()->setMinimumSectionSize(16);

	for (int c = 0; c < model->columnCount(); ++c)
		view->resizeColumnToContents(c);
	view->header()->setSectionResizeMode(QHeaderView::Interactive);

	//view->setStyle(view->style()); // for QSS columns width support - @todo crash on theme reload or change

	root->addWidget(view);
}

static void create_scales() {

}

static QSlider* create_horizontal_scale(int value, bool draw, bool inverted, QSlider::TickPosition position) { // todo

	QSlider *scale = new QSlider(Qt::Horizontal);

	scale->setRange(0, 100);
	scale->setValue(value);
	scale->setInvertedAppearance(inverted);
	// @todo draw
	scale->setTickPosition(position);
	scale->setFixedWidth(186); // The 186
	scale->setTracking(true);

	return scale;
}

static QSlider* create_vertical_scale(int value, bool draw, bool inverted, QSlider::TickPosition position) { // todo

	QSlider *scale = new QSlider(Qt::Vertical);

	scale->setRange(0, 100);
	scale->setValue(value);
	scale->setInvertedAppearance(inverted);
	// @todo draw
	scale->setTickPosition(position);
	scale->setFixedHeight(100); // The 100
	scale->setTracking(true);

	return scale;
}


// traditional menu

static void create_traditional_menubar(QMenuBar *root) {

	static ShortcutFilter *g_shortcutFilter = new ShortcutFilter();
	QMenu *menu, *submenu, *base;
	QActionGroup *group;
	QAction *menuitem;
	bool ok = false, refresh = !qEnvironmentVariableIsSet("GQSS_SET");

	// options
	menu = root->addMenu(_app("_Options"));
	menu->installEventFilter(g_shortcutFilter);

		// @todo option command line?
		if (qEnvironmentVariableIsSet("AWF_TEAROFF"))
			menu->setTearOffEnabled(true);

		create_menuitem(menu, QIcon::fromTheme("document-open"), _qt("QFileDialog", "&Open"), false, AWF_ACCEL_OPEN, AWF_OPEN, dialog_open);
		create_menuitem(menu, QIcon(), _app("Open recent file"), true, AWF_ACCEL_RECE, AWF_RECE, nullptr);
		create_menuitem(menu, QIcon::fromTheme("document-save"), _qt("QFileDialog", "&Save"), false, AWF_ACCEL_SAVE, AWF_SAVE, dialog_save);
		create_menuitem(menu, QIcon::fromTheme("view-refresh"), _app("_Refresh"), refresh, AWF_ACCEL_REFR, AWF_REFR, [](){ on_sighup(0); });
		create_menuitem(menu, QIcon(), _app("Calendar"), false, AWF_ACCEL_CALE, AWF_CALE, dialog_calendar);
		create_menuitem(menu, QIcon(), "QSliders", false, AWF_ACCEL_SCAL, AWF_SCAL, dialog_scales);
		create_menuitem(menu, QIcon::fromTheme("document-properties"), _app("Properties"), false, AWF_ACCEL_PROP, AWF_PROP, dialog_message);
		create_menuitem(menu, QIcon::fromTheme("document-page-setup"),_app("Page Set&up"), false, AWF_ACCEL_PRSE, AWF_PRSE, dialog_page_setup);
		create_menuitem(menu, QIcon::fromTheme("document-print"), _qt("QPrintDialog", "&Print"), false, AWF_ACCEL_PRIN, AWF_PRIN, dialog_print);

		submenu = menu->addMenu(_app("More..."));

			create_menuitem(submenu, QIcon::fromTheme("edit-cut"), _qt("QLineEdit", "Cu&t"), false, AWF_ACCEL_MCUT, AWF_MCUT, nullptr);
			create_menuitem(submenu, QIcon::fromTheme("edit-copy"), _qt("QLineEdit", "&Copy"), false, AWF_ACCEL_MCOP, AWF_MCOP, nullptr);
			create_menuitem(submenu, QIcon::fromTheme("edit-paste"), _qt("QLineEdit", "&Paste"), false, AWF_ACCEL_MPAS, AWF_MPAS, nullptr);

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

			create_menuitem(menu, QIcon::fromTheme("window-close"), _qt("QMdiSubWindow", "&Close"), true, AWF_ACCEL_CLOS, AWF_CLOS, nullptr);
			create_menuitem(menu, QIcon::fromTheme("application-exit"), _qt("QCocoaMenuItem", "Quit"), false, AWF_ACCEL_QUIT, AWF_QUIT, qApp->quit);

	// system themes
	group = new QActionGroup(window);
	group->setExclusive(true);
	menu  = root->addMenu(_app("_System themes"));
	for (QString theme : list_system_theme) {

		if (theme == "Azertyuiop") {
			submenu = menu->addMenu(theme);
			base = submenu;
			ok = true;
		}
		else if (ok && (theme == "Azertyuiop")) {
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

	if (!qEnvironmentVariableIsSet("GQSS_SET"))
		create_menuitem(menu, QIcon(), _app("GlobalQSS not available"), true, QKeySequence(), nullptr, nullptr);
	else if (list_system_theme.isEmpty())
		create_menuitem(menu, QIcon(), _app("No themes found"), true, QKeySequence(), nullptr, nullptr);

	// user themes
	menu = root->addMenu(_app("_User themes"));
	for (QString theme : list_user_theme) {

		if (theme == "Azertyuiop") {
			submenu = menu->addMenu(theme);
			base = submenu;
			ok = true;
		}
		else if (ok && (theme == "Azertyuiop")) {
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

	if (!qEnvironmentVariableIsSet("GQSS_SET"))
		create_menuitem(menu, QIcon(), _app("GlobalQSS not available"), true, QKeySequence(), nullptr, nullptr);
	else if (list_user_theme.isEmpty())
		create_menuitem(menu, QIcon(), _app("No themes found"), true, QKeySequence(), nullptr, nullptr);

	// text direction
	menu = root->addMenu(_app("_Text direction"));

		group = new QActionGroup(window);
		group->setExclusive(true);

		menuitem = create_menuitem_radio(menu, _app("Left to Right (LTR)"), false, false, false, group);
		if (current_direction == 1)
			menuitem->setChecked(true);
		QObject::connect(menuitem, &QAction::triggered, [=](){ update_text_direction(1); }); // Qt::LeftToRight

		menuitem = create_menuitem_radio(menu, _app("Right to Left (RTL)"), false, false, false, group);
		if (current_direction == 2)
			menuitem->setChecked(true);
		QObject::connect(menuitem, &QAction::triggered, [=](){ update_text_direction(2); }); // Qt::RightToLeft

	// help
	menu = root->addMenu(_qt("QWizard", "&Help"));
	menu->installEventFilter(g_shortcutFilter);

		create_menuitem(menu, QIcon(), "QtInspector", !qEnvironmentVariableIsSet("GQSS_SET"), AWF_ACCEL_INSP, AWF_INSP, dialog_inspector);
		create_menuitem(menu, QIcon::fromTheme("help-about"), _qt("QCocoaMenuItem", "About"), false, AWF_ACCEL_ABOU, AWF_ABOU, dialog_about);

	// gtk-can-change-accels for Qt | so same GTK 2.24 3.x 4.x & Qt 5.15 6.x
	accels_load();
}

static QAction* create_menuitem_check(QMenu *menu, QString text, bool chk, bool ist, bool dsb) {

	QAction *menuitem;

	menuitem = new QAction(text);
	menuitem->setCheckable(true);
	menuitem->setChecked(chk);
	// @todo inconsistent (ist)
	menuitem->setEnabled(!dsb);
	menu->addAction(menuitem);

	return menuitem;
}

static QAction* create_menuitem_radio(QMenu *menu, QString text, bool chk, bool ist, bool dsb, QActionGroup *group) {

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

	QString oldPath = QDir::homePath() + "/.awf-gtk-accels";
	if (QFile::exists(oldPath))
		QFile::rename(oldPath, QDir::homePath() + "/.awf-accels");

	// gtk-can-change-accels for Qt | so same GTK 2.24 3.x 4.x & Qt 5.15 6.x
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

			if (qEnvironmentVariableIsSet("AWF_DEBUG"))
				printf("accels foundInFile: %s %s\n", kmp.toUtf8().constData(), acl.toUtf8().constData());

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
		for (QString key : actions.keys()) {

			kmp = key;
			acl = accels.value(kmp);

			if (qEnvironmentVariableIsSet("AWF_DEBUG"))
				printf("accels foundInMenu: %s %s\n", kmp.toUtf8().constData(), acl.toUtf8().constData());

			if (acl.isEmpty()) {
				actions.value(kmp)->setProperty("shortcutModified", true);
				actions.value(kmp)->setShortcut(QKeySequence());
			}
			else {
				Qt::KeyboardModifiers mods = parseModifiers(acl);
				acl.remove(QRegularExpression("<.*>"));
				Qt::Key key = parseKey(acl);

				if (key == Qt::Key_unknown) {
					printf("accels foundInMenu: %s %s » unknown key\n", kmp.toUtf8().constData(), acl.toUtf8().constData());
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

	// gtk-can-change-accels for Qt | so same GTK 2.24 3.x 4.x & Qt 5.15 6.x
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

	Qt::KeyboardModifiers mods = keyEvent->modifiers();
	bool del = (key == Qt::Key_Delete) || (key == Qt::Key_Backspace);
	if (
		del ||
		// f1..12
		((key >= Qt::Key_F1) && (key <= Qt::Key_F12)) ||
		// crtl/shift/super/alt + ?
		mods
	) {
		must_save_accels = true;
		QKeySequence seq = del ? QKeySequence() : QKeySequence(mods | key);
		menuitem->setProperty("shortcutModified", true);
		menuitem->setShortcut(seq);
		return true;
	}

	return false;
}

static void accels_save() { // ok

	// gtk-can-change-accels for Qt | so same GTK 2.24 3.x 4.x & Qt 5.15 6.x
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

			for (QString key : actions.keys()) {

				kmp = key;
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
	QFileDialog::getOpenFileNames(window, "QFileDialog:Open");
}

static void dialog_save() { // ok
	QFileDialog::getSaveFileName(window, "QFileDialog:Save");
}

static void dialog_message() { // ok

	QMessageBox msgBox(window);
	msgBox.setIcon(QMessageBox::Information);
	msgBox.setWindowTitle("QMessageBox");
	msgBox.setText("QMessageBox");
	msgBox.setInformativeText(_app("A widget factory is a theme preview application for GTK and Qt. It displays the various widget types in a single window allowing to see the visual effect of the applied theme."));
	msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	msgBox.exec();
}

static void dialog_page_setup() { // ok
	QPrinter printer;
	QPageSetupDialog(&printer, window).exec();
}

static void dialog_print() { // ok
	QPrinter printer;
	QPrintDialog(&printer, window).exec();
}

static void dialog_about() { // ok

	QString t1 = QString("%1<br><br>%2 %3<br><br>%4<br>%5<br><i><small>QT_QPA_PLATFORMTHEME=%6 QT_STYLE_OVERRIDE=%7</small></i>")
		.arg(_app("A widget factory is a theme preview application for GTK and Qt. It displays the various widget types in a single window allowing to see the visual effect of the applied theme."))
		.arg(QString(_app("Remove %1 file")).arg("~/.awf-accels"))
		.arg(_app("to reset keyboard shortcuts."))
		.arg(QString(_app("compiled with qt %1.%2.%3")).arg(QT_VERSION_MAJOR).arg(QT_VERSION_MINOR).arg(QT_VERSION_PATCH))
		.arg(QString(_app(" started with qt %1")).arg(qVersion()))
		.arg(QString::fromUtf8(qgetenv("QT_QPA_PLATFORMTHEME")))
		.arg(QString::fromUtf8(qgetenv("QT_STYLE_OVERRIDE")));

	QString t2 = QString("<b>awf-qt%1 / %2</b><br><br>%3<br><br>%4<br><br><small>%5</small><br><br><small>%6</small>")
		.arg(QT_VERSION_MAJOR)
		.arg(VERSION)
		.arg(t1)
		.arg("<a href=\"https://github.com/luigifab/awf-extended\">https://github.com/luigifab/awf-extended</a>")
		.arg("Copyright © 2020-2026 Fabrice Creuzot (luigifab)<br>Copyright © 2011-2017 Valère Monseur (valr)")
		.arg("A widget factory is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.");

	QMessageBox::about(window, _qt("QCocoaMenuItem", "About"), t2);
}

static void dialog_inspector() { // ok

	if (inspector) {
		inspector->raise();
		inspector->activateWindow();
	}
	else {
		inspector = new QDialog(window, Qt::Window);
		inspector->setAttribute(Qt::WA_DeleteOnClose);
		inspector->setWindowTitle("QtInspector");
		inspector->resize(500, 400);

		QTextEdit *textEdit = new QTextEdit;
		textEdit->setAcceptRichText(false);
		textEdit->setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));
		textEdit->setPlaceholderText(_app("Write QSS here... The style is applied immediately on top of the current theme."));
		textEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

		QPushButton *btnCopy = new QPushButton(_qt("QShortcut", "Copy"));
		btnCopy->setIcon(QIcon::fromTheme("edit-copy"));
		QPushButton *btnClear = new QPushButton(_qt("QShortcut", "Clear"));
		btnClear->setIcon(QIcon::fromTheme("edit-clear"));
		QPushButton *btnClose = new QPushButton(_qt("QMdiSubWindow", "&Close"));
		btnClose->setIcon(QIcon::fromTheme("dialog-close"));

		QHBoxLayoutt *buttonLayout = new QHBoxLayoutt;
		buttonLayout->addWidget(btnCopy);
		buttonLayout->addWidget(btnClear);
		buttonLayout->addWidget(btnClose);

		QVBoxLayoutt *mainLayout = new QVBoxLayoutt;
		mainLayout->addWidget(textEdit);
		mainLayout->addLayout(buttonLayout);
		inspector->setLayout(mainLayout);

		QObject::connect(window, &QWidget::destroyed, inspector, &QWidget::close);

		QObject::connect(textEdit, &QTextEdit::textChanged, [=](){

			if (original_style.isEmpty())
				original_style = qApp->styleSheet();

			FILE *oldStderr = stderr;
			stderr = fopen("/dev/null", "w");
			qApp->setStyleSheet(original_style + "\n" + textEdit->toPlainText());
			fclose(stderr);
			stderr = oldStderr;
		});

		QObject::connect(btnCopy, &QPushButton::clicked, [=](){
			QClipboard *clipboard = QApplication::clipboard();
			clipboard->setText(textEdit->toPlainText());
		});

		QObject::connect(btnClear, &QPushButton::clicked, [=](){
			textEdit->clear();
			if (!original_style.isEmpty())
				qApp->setStyleSheet(original_style);
			original_style = "";
		});

		QObject::connect(btnClose, &QPushButton::clicked, [=](){
			inspector->close();
		});

		QObject::connect(inspector, &QWidget::destroyed, [&](){
			inspector = nullptr;
			if (!original_style.isEmpty())
				qApp->setStyleSheet(original_style);
			original_style = "";
		});

		inspector->show();
	}
}

static void dialog_calendar() {

}

static void dialog_scales() {

}


#include "awf-qt6.moc"