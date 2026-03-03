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
 *  https://github.com/GNOME/gtk/blob/3.24.50/po/fr.po
 *  xgettext --keyword=_app -d awf -o src/awf.pot -k_ -s src/awf-*.c*
 *  msgmerge src/po/fr.po src/awf.pot -o src/po/fr.po
 *  msgfmt src/po/fr.po -o src/fr/LC_MESSAGES/awf.mo
 *
 * Tested with build.sh (via VirtualBox 7) with:
 *  Debian Testing 64                  (1536 MB) GTK 2.24/3.24/4.21 + GLIB 2.87 + Pango 1.57
 *  Fedora Rawhide 64                  (1536 MB) GTK 2.24/3.24/4.21 + GLIB 2.86 + Pango 1.57
 *  Ubuntu 25.10 Questing Quokka 64    (4096 MB) GTK 2.24/3.24/4.20 + GLIB 2.86 + Pango 1.56
 *  Ubuntu 25.04 Plucky Puffin 64      (4096 MB) GTK 2.24/3.24/4.18 + GLIB 2.84 + Pango 1.56
 *  Ubuntu 24.10 Oracular Oriole 64    (4096 MB) GTK 2.24/3.24/4.16 + GLIB 2.82 + Pango 1.54
 *  Ubuntu 24.04 Noble Numbat 64       (4096 MB) GTK 2.24/3.24/4.14 + GLIB 2.80 + Pango 1.52
 *  Ubuntu 23.10 Mantic Minotaur 64    (3072 MB) GTK 2.24/3.24/4.12 + GLIB 2.78 + Pango 1.51
 *  Ubuntu 23.04 Lunar Lobster 64      (3072 MB) GTK 2.24/3.24/4.10 + GLIB 2.76 + Pango 1.50
 *  Ubuntu 22.10 Kinetic Kudu 64       (2176 MB) GTK 2.24/3.24/4.8  + GLIB 2.74 + Pango 1.50
 *  Ubuntu 22.04 Jammy Jellyfish 64    (2176 MB) GTK 2.24/3.24/4.6  + GLIB 2.72 + Pango 1.50
 *  Ubuntu 21.10 Impish Indri 64       (2176 MB) GTK 2.24/3.24/4.4  + GLIB 2.68 + Pango 1.48
 *  Ubuntu 21.04 Hirsute Hippo 64      (2176 MB) GTK 2.24/3.24/4.0  + GLIB 2.68 + Pango 1.48
 *  Ubuntu 17.04 Zesty Zapus 32        (1536 MB) GTK 2.24/3.22 + GLIB 2.52 + Pango 1.40
 *  Ubuntu 16.10 Yakkety Yak 32        (1536 MB) GTK 2.24/3.20 + GLIB 2.50 + Pango 1.40
 *  Ubuntu 16.04 Xenial Xerus 32       (1536 MB) GTK 2.24/3.18 + GLIB 2.48 + Pango 1.38
 *  Ubuntu 15.10 Wily Werewolf 32      (1024 MB) GTK 2.24/3.16 + GLIB 2.46 + Pango 1.36
 *  Ubuntu 15.04 Vivid Vervet 32       (1024 MB) GTK 2.24/3.14 + GLIB 2.44 + Pango 1.36
 *  Ubuntu 14.10 Utopic Unicorn 32     (1024 MB) GTK 2.24/3.12 + GLIB 2.42 + Pango 1.36
 *  Ubuntu 14.04 Trusty Tahr 32        (1024 MB) GTK 2.24/3.10 + GLIB 2.40 + Pango 1.36
 *  Ubuntu 13.10 Saucy Salamander 32   (1024 MB) GTK 2.24/3.8  + GLIB 2.38 + Pango 1.32
 *  Ubuntu 13.04 Raring Ringtail 32    (1024 MB) GTK 2.24/3.6  + GLIB 2.36 + Pango 1.32
 *  Ubuntu 12.04 Precise Pangolin 32   (1024 MB) GTK 2.24/3.4  + GLIB 2.32 + Pango 1.30
 *  Ubuntu 11.10 Oneiric Ocelot 32     (1024 MB) GTK 2.24/3.2  + GLIB 2.30 + Pango 1.29
 *  Ubuntu 11.04 Natty Narwhal 32      (1024 MB) GTK 2.24/3.0  + GLIB 2.28 + Pango 1.28
 */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#include <gdk/gdk.h>
#include <getopt.h>
#include <glib/gi18n.h>
#include <glib/gprintf.h>
#include <glib/gstdio.h>
#include <gtk/gtk.h>
#include <gtk/gtkunixprint.h>
#include <libnotify/notify.h>
#include <locale.h>
#include <time.h>
#if GLIB_CHECK_VERSION (2,30,0)
	#include <glib-unix.h>
#endif
#pragma GCC diagnostic pop

#define GTK_DIRNAME "gtk-4.0"
#define GETTEXT_PACKAGE "awf-gtk4"
#define BOXH (gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0))
#define BOXV (gtk_box_new (GTK_ORIENTATION_VERTICAL, 0))
#define SEPH (gtk_separator_new (GTK_ORIENTATION_HORIZONTAL))
#define SEPV (gtk_separator_new (GTK_ORIENTATION_VERTICAL))
#define PANEH (gtk_paned_new (GTK_ORIENTATION_HORIZONTAL))
#define PANEV (gtk_paned_new (GTK_ORIENTATION_VERTICAL))

#define AWF_OPEN "<AWF>/Test/Open"
#define AWF_SAVE "<AWF>/Test/Save"
#define AWF_REFR "<AWF>/Test/Refresh"
#define AWF_RECE "<AWF>/Test/Recent"
#define AWF_CALE "<AWF>/Test/Calendar"
#define AWF_SCAL "<AWF>/Test/Scales"
#define AWF_PROP "<AWF>/Test/Properties"
#define AWF_PRSE "<AWF>/Test/PrintSetup"
#define AWF_PRIN "<AWF>/Test/Print"
#define AWF_MCUT "<AWF>/Test/More/Cut"
#define AWF_MCOP "<AWF>/Test/More/Copy"
#define AWF_MPAS "<AWF>/Test/More/Paste"
#define AWF_CLOS "<AWF>/Test/Close"
#define AWF_QUIT "<AWF>/Test/Quit"
#define AWF_INSP "<AWF>/Test/Inspector"
#define AWF_ABOU "<AWF>/Test/About"

#define AWF_ACCEL_OPEN "<Control>O"
#define AWF_ACCEL_SAVE "<Control>S"
#define AWF_ACCEL_REFR "F5"
#define AWF_ACCEL_RECE NULL
#define AWF_ACCEL_CALE NULL
#define AWF_ACCEL_SCAL NULL
#define AWF_ACCEL_PROP "<Alt>Return"
#define AWF_ACCEL_PRSE "<Control><Shift>P"
#define AWF_ACCEL_PRIN "<Control>P"
#define AWF_ACCEL_MCUT "<Control>X"
#define AWF_ACCEL_MCOP "<Control>C"
#define AWF_ACCEL_MPAS "<Control>V"
#define AWF_ACCEL_CLOS "<Control>W"
#define AWF_ACCEL_QUIT "<Control>Q"
#define AWF_ACCEL_INSP "F12"
#define AWF_ACCEL_ABOU "F1"

// @see https://stackoverflow.com/a/10018581/2980105
#define _app(x) dgettext(GETTEXT_PACKAGE, x)
#define _gtk(x) dgettext("gtk40", x)

// global variables
static GHashTable *hash_system_theme = NULL;
static GHashTable *hash_user_theme = NULL;
static GList *list_system_theme = NULL;
static GList *list_user_theme = NULL;
static GtkWidget *window = NULL, *toolbar = NULL, *toolbarentry = NULL, *toolbarend = NULL, *statusbar = NULL;
static GtkWidget *headbarCloseLeft = NULL, *headbarCloseRight = NULL, *button15 = NULL, *button16 = NULL;
static GtkWidget *progressbar1 = NULL, *progressbar2 = NULL, *progressbar3 = NULL, *progressbar4 = NULL, *progressbar8 = NULL, *progressbar9 = NULL;
static GtkWidget *scale1 = NULL, *scale2 = NULL, *scale3 = NULL, *scale4 = NULL, *scale5 = NULL, *scale6 = NULL;
static GtkWidget *levelbar1 = NULL, *levelbar2 = NULL, *levelbar3 = NULL, *levelbar4 = NULL;
static GtkWidget *levelbar5 = NULL, *levelbar6 = NULL, *levelbar7 = NULL, *levelbar8 = NULL;
static GtkWidget *notebook1 = NULL, *notebook2 = NULL, *notebook3 = NULL, *notebook4 = NULL;
static int current_direction       = 0; // GTK_TEXT_DIR_NONE
static gchar *current_theme        = "auto";
static gchar *opt_theme            = "auto";
static gchar *opt_screenshot       = NULL;
static gboolean allow_update_theme = TRUE;
//atic gboolean must_save_accels   = FALSE;

// global functions
static void awf_load_theme(GHashTable* hashtable, gchar *directory);
static inline int awf_compare_theme(gconstpointer theme1, gconstpointer theme2);
static void notify_updated_gtktheme(GSettings *settings, gchar *key, gpointer userdata);
static void update_text_direction(int direction);
static void update_theme(gchar *new_theme);
static void update_statusbar(gchar *message);
static void update_values(GtkRange *range);
static void update_widgets();
static void update_marks(GtkScale *scale, gboolean value, int position);
static void display_notification();
static void find_and_update_labels(GtkWidget *widget, gboolean special);
static gboolean find_and_check_menuradio(GMenuModel *model, gchar *search);
static gboolean on_notification_action(void *data);
static gboolean on_sighup(void *data);
static gboolean take_screenshot(void *data);
static void create_window(gpointer app);
static void create_widgets(GtkWidget *root);
static void add_to(GtkBox *box, GtkWidget *widget, gboolean fill, gboolean expand, guint padding, guint spacing);
static void add_progressbar_and_entrybar();
static void create_toolbar(GtkWidget *root);
static void create_combos_entries(GtkWidget *root);
static void create_spinbuttons(GtkWidget *root);
static void create_checkbuttons(GtkWidget *root);
static void create_radiobuttons(GtkWidget *root);
static void create_otherbuttons(GtkWidget *root1, GtkWidget *root2, GtkWidget *root3, GtkWidget *root4, GtkWidget *root5);
static void create_progressbars(GtkWidget *root1, GtkWidget *root2, GtkWidget *root3, GtkWidget *root4);
static void create_labels(GtkWidget *root);
static void create_spinners(GtkWidget *root);
static void create_expander(GtkWidget *root);
static void create_frames(GtkWidget *root1, GtkWidget *root2);
static void create_notebooks(GtkWidget *root1, GtkWidget *root2);
static void create_notebook_tab(GtkWidget *notebook, gchar *text, GtkWidget *content, gboolean close);
static void create_treview(GtkWidget *root);
static void create_scales(GtkWidget *notebook, gchar *text, int position);
static GtkWidget* create_horizontal_scale(gdouble value, gboolean draw, gboolean inverted, int position);
static GtkWidget* create_vertical_scale(gdouble value, gboolean draw, gboolean inverted, int position);
static void create_traditional_menubar(GtkApplication *app, GMenu *root);
static GMenuItem* create_menuitem_radio(GMenu *menu, gchar *text, gboolean free1, gchar *group, gboolean free2);
static GMenuItem* create_menuitem(GtkApplication *app, GMenu *menu, gchar *text, gchar *acl, gchar *kmp, gchar *icon, GCallback function);
static void activate_action(GSimpleAction *action, GVariant *parameter, gpointer data);
static void accels_load(GtkApplication *app);
static void accels_change(GtkEventControllerKey *controller, guint keyval, guint keycode, GdkModifierType state);
static void accels_save();
static void dialog_open();
static void dialog_save();
static void dialog_message();
static void dialog_page_setup();
static void dialog_print();
static void dialog_about();
static void dialog_inspector();
static void dialog_calendar();
static void dialog_scales();
static gboolean on_scrolltabs(GtkEventControllerScroll *event, double dx, double dy, GtkWidget *widget);


// run run run

int main(int argc, gchar **argv) {

	int opt = 0, status = 0;
	hash_system_theme = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
	hash_user_theme = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
	GList *iterator = NULL;
	gchar *directory;

	// load available system themes (/usr/local/share/themes && /usr/share/themes)
	const char *const *dirs = g_get_system_data_dirs();
	for (opt = 0; dirs[opt]; opt++) {
		directory = g_build_filename(dirs[opt], "themes", NULL);
		awf_load_theme(hash_system_theme, directory);
		g_free(directory);
	}

	g_hash_table_replace(hash_system_theme, g_strdup("Adwaita"), g_strdup("Adwaita")); // bolos
	g_hash_table_remove(hash_system_theme, "Default");
	g_hash_table_remove(hash_system_theme, "Emacs");
	list_system_theme = g_list_sort(g_hash_table_get_keys(hash_system_theme), (GCompareFunc) awf_compare_theme);

	// load available user themes (HOME/.local/share/themes && HOME/.themes)
	directory = g_build_filename(g_get_user_data_dir(), "themes", NULL);
	awf_load_theme(hash_user_theme, directory);
	g_free(directory);

	directory = g_build_filename(g_get_home_dir(), ".themes", NULL);
	awf_load_theme(hash_user_theme, directory);
	g_free(directory);

	list_user_theme = g_list_sort(g_hash_table_get_keys(hash_user_theme), (GCompareFunc) awf_compare_theme);

	// locale
	setlocale(LC_ALL, "");
	if (g_file_test("/usr/share/locale", G_FILE_TEST_IS_DIR))
		bindtextdomain(GETTEXT_PACKAGE, "/usr/share/locale");
	bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
	textdomain(GETTEXT_PACKAGE);

	// init
	static struct option long_options[] = {
		{"version",     no_argument, NULL, 'v'},
		{"list-themes", no_argument, NULL, 'l'},
		{"theme",       required_argument, NULL, 't'},
		{"screenshot",  required_argument, NULL, 's'},
		{"help",        no_argument, NULL, 'x'},
		{"ltr",         no_argument, NULL, 'y'},
		{"rtl",         no_argument, NULL, 'z'},
		{NULL, 0, NULL, 0}
	};

	gchar *t1, *t2, *t3, *t4;
	while ((opt = getopt_long(argc, argv, "vlt:s:hxyz", long_options, NULL)) != -1) {
		switch (opt) {
			// --version -v
			case 'v':
				g_printf("%s\n", VERSION);
				return status;
			// --list-themes -l
			case 'l':
				for (iterator = list_system_theme; iterator; iterator = iterator->next)
					g_printf("%s\n", (gchar*) iterator->data);
				for (iterator = list_user_theme; iterator; iterator = iterator->next)
					g_printf("%s\n", (gchar*) iterator->data);
				return status;
			// --theme <theme> -t <theme>
			case 't':
				if (g_hash_table_lookup(hash_system_theme, optarg) || g_hash_table_lookup(hash_user_theme, optarg))
					opt_theme = (gchar*) optarg;
				break;
			// --screenshot <filename> -s <filename>
			case 's':
				opt_screenshot = optarg;
				break;
			// --ltr
			case 'y':
				current_direction = 1; // GTK_TEXT_DIR_LTR
				break;
			// --rtl
			case 'z':
				current_direction = 2; // GTK_TEXT_DIR_RTL
				break;
			// --help (via GtkApplication) -h
			case 'x':
			case 'h':
			default:
				if (opt == 'x')
					break;
				g_printf("%s\n\n  %s %s\n  %s %s\n  %s %s\n  %s %s\n  %s %s\n  %s %s\n\n%s\n%s\n",
					t1 = g_strdup_printf(_app("A widget factory - GTK %d.%d"), GTK_MAJOR_VERSION, GTK_MINOR_VERSION),
					"-v            ", _app("Show version number."),
					"-l            ", _app("List available themes."),
					"-t <theme>    ", _app("Run with the specified theme."),
					"-s <filename> ", t2 = g_strdup_printf(_app("Run and save a png screenshot on %s."), "SIGHUP"),
					"--ltr         ", _app("Start with text from left to right (Left-To-Right)."),
					"--rtl         ", _app("Start with text from right to left (Right-To-Left)."),
					t3 = g_strdup_printf(_app("compiled with gtk %d.%d.%d and glib %d.%d.%d and pango %s"),
						GTK_MAJOR_VERSION, GTK_MINOR_VERSION, GTK_MICRO_VERSION,
						GLIB_MAJOR_VERSION, GLIB_MINOR_VERSION, GLIB_MICRO_VERSION,
						PANGO_VERSION_STRING),
					t4 = g_strdup_printf(_app(" started with gtk %d.%d.%d and glib %d.%d.%d and pango %s"),
						gtk_get_major_version(), gtk_get_minor_version(), gtk_get_micro_version(),
						glib_major_version, glib_minor_version, glib_micro_version,
						pango_version_string())
				);
				g_free(t1);
				g_free(t2);
				g_free(t3);
				g_free(t4);
				return status;
		}
	}

	// create and show window
	g_unix_signal_add(SIGHUP, on_sighup, NULL);
	GtkApplication *app = gtk_application_new("org.gtk.awf", G_APPLICATION_NON_UNIQUE);
	g_signal_connect(app, "activate", G_CALLBACK(create_window), NULL);

	// --version -v
	g_application_add_main_option(G_APPLICATION(app), "version", 'v', G_OPTION_FLAG_IN_MAIN, G_OPTION_ARG_NONE,
		_app("Show version number."), NULL);

	// --list-themes -l
	g_application_add_main_option(G_APPLICATION(app), "list-themes", 'l', G_OPTION_FLAG_IN_MAIN, G_OPTION_ARG_NONE,
		_app("List available themes."), NULL);

	// --theme <theme> -t <theme>
	g_application_add_main_option(G_APPLICATION(app), "theme", 't', G_OPTION_FLAG_IN_MAIN, G_OPTION_ARG_STRING,
		_app("Run with the specified theme."), "<theme>");

	// --screenshot <filename> -s <filename>
	gchar *text = g_strdup_printf(_app("Run and save a png screenshot on %s."), "SIGHUP");
	g_application_add_main_option(G_APPLICATION(app), "screenshot", 's', G_OPTION_FLAG_IN_MAIN, G_OPTION_ARG_STRING,
		text, "<filename>");
	g_free(text);

	// --ltr
	g_application_add_main_option(G_APPLICATION(app), "ltr", 'y', G_OPTION_FLAG_IN_MAIN, G_OPTION_ARG_NONE,
		_app("Start with text from left to right (Left-To-Right)."), NULL);

	// --rtl
	g_application_add_main_option(G_APPLICATION(app), "rtl", 'z', G_OPTION_FLAG_IN_MAIN, G_OPTION_ARG_NONE,
		_app("Start with text from right to left (Right-To-Left)."), NULL);

	g_application_register(G_APPLICATION(app), NULL, NULL);
	return g_application_run(G_APPLICATION(app), argc, argv);
}

static void quit() {
	accels_save();
	exit(0);
}

static void awf_load_theme(GHashTable* hashtable, gchar *directory) {

	if (g_file_test(directory, G_FILE_TEST_IS_DIR)) {

		if (g_getenv("AWF_DEBUG") != NULL)
			g_printf("themes dir: %s\n", directory);

		GDir *dir = g_dir_open(directory, 0, NULL);
		if (dir) {
			const gchar *theme;
			while ((theme = g_dir_read_name(dir)) != NULL) {
				gchar *theme_path = g_build_filename(directory, theme, GTK_DIRNAME, NULL);
				if (g_file_test(theme_path, G_FILE_TEST_IS_DIR))
					g_hash_table_replace(hashtable, g_strdup(theme), g_strdup(theme));
				g_free(theme_path);
			}
			g_dir_close(dir);
		}
	}
}

static inline int awf_compare_theme(gconstpointer theme1, gconstpointer theme2) {
	return g_ascii_strcasecmp((const gchar *)theme1, (const gchar *)theme2);
	//return g_strcmp0((gchar*) theme1, (gchar*) theme2);
}

static void notify_updated_gtktheme(GSettings *settings, gchar *key, gpointer userdata) {

	if (g_strcmp0("gtk-theme", (gchar*) userdata) == 0) {

		gchar *new_theme = g_settings_get_string(settings, "gtk-theme");
		g_usleep(G_USEC_PER_SEC / 2);

		update_theme(new_theme);
		find_and_check_menuradio(gtk_application_get_menubar(GTK_APPLICATION(g_application_get_default())), new_theme);
		g_free(new_theme);
	}
	else if (headbarCloseLeft && headbarCloseRight) {

		gboolean closeLeft = FALSE, closeRight = FALSE; // minimize, maximize, close, icon, menu
		gchar *tokens = g_settings_get_string(settings, (gchar*) userdata);
		if (tokens) {
			if (g_str_has_prefix(tokens, "icon") || g_str_has_prefix(tokens, "menu"))
				closeLeft = TRUE;
			else if (g_str_has_suffix(tokens, "icon") || g_str_has_suffix(tokens, "menu"))
				closeRight = TRUE;
			if (g_getenv("AWF_DEBUG") != NULL)
				g_printf("headerbar tokens: %s %d %d\n", tokens, closeLeft, closeRight);
			g_free(tokens);
		}

		gtk_widget_set_visible(headbarCloseLeft, closeLeft);
		gtk_widget_set_visible(headbarCloseRight, closeRight);
	}
}

static void update_text_direction(int direction) { // okk

	// we must ignore the activate signal when menubar is created
	if (!allow_update_theme)
		return;

	if ((direction == 1) && (gtk_widget_get_direction(window) != GTK_TEXT_DIR_LTR)) {

		gboolean toggle = gtk_notebook_get_scrollable(GTK_NOTEBOOK(notebook1));

		current_direction = 1;
		gtk_widget_set_default_direction(current_direction);

		gtk_scale_clear_marks(GTK_SCALE(scale5));
		update_marks(GTK_SCALE(scale5), toggle, GTK_POS_LEFT);

		gtk_scale_clear_marks(GTK_SCALE(scale6));
		update_marks(GTK_SCALE(scale6), toggle, GTK_POS_RIGHT);
	}
	else if ((direction == 2) && (gtk_widget_get_direction(window) != GTK_TEXT_DIR_RTL)) {

		gboolean toggle = gtk_notebook_get_scrollable(GTK_NOTEBOOK(notebook1));

		gtk_scale_clear_marks(GTK_SCALE(scale5));
		update_marks(GTK_SCALE(scale5), toggle, GTK_POS_RIGHT);

		gtk_scale_clear_marks(GTK_SCALE(scale6));
		update_marks(GTK_SCALE(scale6), toggle, GTK_POS_LEFT);

		current_direction = 2;
		gtk_widget_set_default_direction(current_direction);
	}
}

static void update_theme(gchar *new_theme) {

	// we must ignore the activate signal when menubar is created
	if (!allow_update_theme || !new_theme)
		return;
	// we can ignore the signal when the menuitem is deselected
	// @todo?

	if (strcmp((gchar*) new_theme, "refresh") == 0) {

		gchar *default_theme = "None";
		if (g_hash_table_lookup(hash_system_theme, "Default"))
			default_theme = "Default";
		else if (g_hash_table_lookup(hash_system_theme, "Raleigh"))
			default_theme = "Raleigh";

		g_object_set(gtk_settings_get_default(), "gtk-theme-name", default_theme, NULL);
		g_usleep(G_USEC_PER_SEC / 2);
		g_object_set(gtk_settings_get_default(), "gtk-theme-name", current_theme, NULL);
		// @todo? force reload of ".config/gtk*/gtk.css"

		gchar *text = g_strdup_printf(_app("Theme %s reloaded."), current_theme);
		update_statusbar(text);
		g_free(text);

		gtk_window_set_default_size(GTK_WINDOW(window), 50, 50);
		if (opt_screenshot)
			g_timeout_add_seconds(1, take_screenshot, NULL);
	}
	else if (strcmp((gchar*) new_theme, "auto") == 0) {
		g_object_get(gtk_settings_get_default(), "gtk-theme-name", &current_theme, NULL);
		gtk_window_set_default_size(GTK_WINDOW(window), 50, 50);
	}
	else if (strcmp((gchar*) current_theme, (gchar*) new_theme) != 0) {

		g_object_set(gtk_settings_get_default(), "gtk-theme-name", new_theme,  NULL);
		g_object_get(gtk_settings_get_default(), "gtk-theme-name", &current_theme, NULL);

		gchar *text = g_strdup_printf(_app("Theme %s loaded."), current_theme);
		update_statusbar(text);
		g_free(text);

		gtk_window_set_default_size(GTK_WINDOW(window), 50, 50);
	}
}

static void update_statusbar(gchar *message) { // ok

	if (window && statusbar) {

		char buffer[12];
		time_t rawtime;

		time(&rawtime);
		strftime(buffer, sizeof buffer, "%T", localtime(&rawtime));

		gchar *text = g_strdup_printf("%s - %s", buffer, message);
		G_GNUC_BEGIN_IGNORE_DEPRECATIONS // GTK 4.10+
		gtk_statusbar_push(GTK_STATUSBAR(statusbar), gtk_statusbar_get_context_id(GTK_STATUSBAR(statusbar), "gné"), text);
		G_GNUC_END_IGNORE_DEPRECATIONS
		g_free(text);
	}
}

static void update_values(GtkRange *range) { // ok

	double value = gtk_range_get_value(range);

	// range(0..1)
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar1), value / 100.0);
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar2), value / 100.0);
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar3), value / 100.0);
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar4), value / 100.0);
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar8), value / 100.0);
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar9), value / 100.0);

	// range(0..1)
	gtk_level_bar_set_value(GTK_LEVEL_BAR(levelbar1), value / 100.0);
	gtk_level_bar_set_value(GTK_LEVEL_BAR(levelbar2), value / 100.0);
	gtk_level_bar_set_value(GTK_LEVEL_BAR(levelbar5), value / 100.0);
	gtk_level_bar_set_value(GTK_LEVEL_BAR(levelbar6), value / 100.0);
	// range(0..5)
	gtk_level_bar_set_value(GTK_LEVEL_BAR(levelbar3), value / 100.0 * gtk_level_bar_get_max_value(GTK_LEVEL_BAR(levelbar3)));
	gtk_level_bar_set_value(GTK_LEVEL_BAR(levelbar4), value / 100.0 * gtk_level_bar_get_max_value(GTK_LEVEL_BAR(levelbar4)));
	gtk_level_bar_set_value(GTK_LEVEL_BAR(levelbar7), value / 100.0 * gtk_level_bar_get_max_value(GTK_LEVEL_BAR(levelbar7)));
	gtk_level_bar_set_value(GTK_LEVEL_BAR(levelbar8), value / 100.0 * gtk_level_bar_get_max_value(GTK_LEVEL_BAR(levelbar8)));

	// range(0..1)
	gtk_scale_button_set_value(GTK_SCALE_BUTTON(button15), value / 100.0);

	// range(0..100)
	if (scale1 != (GtkWidget*) range) gtk_range_set_value(GTK_RANGE(scale1), value);
	if (scale2 != (GtkWidget*) range) gtk_range_set_value(GTK_RANGE(scale2), value);
	if (scale3 != (GtkWidget*) range) gtk_range_set_value(GTK_RANGE(scale3), value);
	if (scale4 != (GtkWidget*) range) gtk_range_set_value(GTK_RANGE(scale4), value);
	if (scale5 != (GtkWidget*) range) gtk_range_set_value(GTK_RANGE(scale5), value);
	if (scale6 != (GtkWidget*) range) gtk_range_set_value(GTK_RANGE(scale6), value);

	// text
	gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(progressbar8), value > 50);
	gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(progressbar9), value > 50);
}

static void update_widgets() { // ok

	// function called when user click on [+] toolbar button
	// when toggle = true, the [+] toolbar button is NOT checked
	gboolean toggle = gtk_notebook_get_scrollable(GTK_NOTEBOOK(notebook1));

	// via add_progressbar_and_entrybar
	// show progressbar in toolbar and statusbar when [+] toolbar button is NOT checked
	if (toggle) {
		gtk_widget_set_visible(progressbar8, FALSE);
		gtk_widget_set_visible(progressbar9, FALSE);
		gtk_widget_set_visible(toolbarentry, FALSE);
	}
	else {
		gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar8), 0.0);
		gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar9), 0.0);
		gtk_widget_set_visible(progressbar8, TRUE);
		gtk_widget_set_visible(progressbar9, TRUE);
		gtk_widget_set_visible(toolbarentry, TRUE);
	}

	// enabled or not
	gtk_widget_set_sensitive(scale2, toggle);
	gtk_widget_set_sensitive(scale4, toggle);
	gtk_widget_set_sensitive(scale6, toggle);
	gtk_widget_set_sensitive(progressbar2, toggle);
	gtk_widget_set_sensitive(progressbar4, toggle);
	gtk_widget_set_sensitive(levelbar2, toggle);
	gtk_widget_set_sensitive(levelbar4, toggle);
	gtk_widget_set_sensitive(levelbar6, toggle);
	gtk_widget_set_sensitive(levelbar8, toggle);

	// text or not
	gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(progressbar1), !toggle);
	gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(progressbar2), !toggle);
	gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(progressbar3), !toggle);
	gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(progressbar4), !toggle);
	gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(progressbar8), FALSE);
	gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(progressbar9), FALSE);

	// marks
	gtk_scale_clear_marks(GTK_SCALE(scale5));
	update_marks(GTK_SCALE(scale5), !toggle, GTK_POS_LEFT);

	gtk_scale_clear_marks(GTK_SCALE(scale6));
	update_marks(GTK_SCALE(scale6), !toggle, GTK_POS_RIGHT);

	// scrollable or not
	gtk_notebook_set_scrollable(GTK_NOTEBOOK(notebook1), !toggle);
	gtk_notebook_set_scrollable(GTK_NOTEBOOK(notebook2), !toggle);
	gtk_notebook_set_scrollable(GTK_NOTEBOOK(notebook3), !toggle);
	gtk_notebook_set_scrollable(GTK_NOTEBOOK(notebook4), !toggle);

	gtk_window_set_default_size(GTK_WINDOW(window), 50, 50);
}

static void update_marks(GtkScale *scale, gboolean value, int position) {

	if (value) {
		gtk_scale_add_mark(scale,   0, position, NULL);
		gtk_scale_add_mark(scale,  25, position, "25");
		gtk_scale_add_mark(scale,  50, position, "50");
		gtk_scale_add_mark(scale,  75, position, "75");
		gtk_scale_add_mark(scale, 100, position, NULL);
	}
	else {
		gtk_scale_add_mark(scale,   0, position, NULL);
		gtk_scale_add_mark(scale,  25, position, NULL);
		gtk_scale_add_mark(scale,  50, position, NULL);
		gtk_scale_add_mark(scale,  75, position, NULL);
		gtk_scale_add_mark(scale, 100, position, NULL);
	}
}

static void display_notification() { // ok

	if (notify_init(GETTEXT_PACKAGE)) {
		// Ubuntu 11.04 with libnotify-dev 0.5.x, so you must use libnotify-dev 0.7.x from Ubuntu 11.10
		NotifyNotification *notif = notify_notification_new(GETTEXT_PACKAGE, _app("A widget factory is a theme preview application for GTK and Qt. It displays the various widget types in a single window allowing to see the visual effect of the applied theme."), "dialog-information");
		notify_notification_add_action(notif, "nothing", _gtk("Close"), NOTIFY_ACTION_CALLBACK(on_notification_action), NULL, NULL);
		notify_notification_add_action(notif, "close", _gtk("Close"), NOTIFY_ACTION_CALLBACK(on_notification_action), NULL, NULL);
		notify_notification_set_timeout(notif, 50000);
		notify_notification_show(notif, NULL);
		g_object_unref(G_OBJECT(notif));
		notify_uninit();
	}
}

static void find_and_update_labels(GtkWidget *widget, gboolean special) {

	// with ChatGPT
	if (GTK_IS_LABEL(widget)) {
		gtk_label_set_ellipsize(GTK_LABEL(widget), PANGO_ELLIPSIZE_END);
	}
	else if (GTK_IS_WIDGET(widget)) {
		GtkWidget *child = gtk_widget_get_first_child(widget);
		while (child) {
			find_and_update_labels(child, FALSE);
			child = gtk_widget_get_next_sibling(child);
		}
	}
}

static gboolean find_and_check_menuradio(GMenuModel *model, gchar *search) {

	int n = g_menu_model_get_n_items(model);
	GVariant *info;
	const gchar *value;

	for (int idx = 0; idx < n; idx++) {

		GMenuModel *submenu = g_menu_model_get_item_link(model, idx, G_MENU_LINK_SECTION);
		if (!submenu)
			submenu = g_menu_model_get_item_link(model, idx, G_MENU_LINK_SUBMENU);

		if (submenu) {
			// process submenu
			gboolean found = find_and_check_menuradio(submenu, search);
			g_object_unref(submenu);
			if (found)
				return TRUE;
		}
		else {
			// app.set-theme::theme_name(.[action]::[target])
			// check menuitem label/target
			info = g_menu_model_get_item_attribute_value(model, idx, "target", NULL); // target or label = theme_name
			if (info) {
				value = g_variant_get_string(info, NULL);
				g_variant_unref(info);
				if (value && (g_strcmp0(value, search) == 0)) {
					// menuitem found by label/target
					// check menuitem action
					info = g_menu_model_get_item_attribute_value(model, idx, "action", NULL); // action = disabled or set-theme
					if (info) {
						value = g_variant_get_string(info, NULL);
						g_variant_unref(info);
						if (value && g_strcmp0(value, "disabled") != 0) {
							// menuitem found by label/target + action not disabled
							// set state checked
							g_action_group_change_action_state(G_ACTION_GROUP(g_application_get_default()), "set-theme", g_variant_new_string(search));
							return TRUE;
						}
					}
				}
			}
		}
	}

	return FALSE;
}

static gboolean on_notification_action(void *data) {
	return FALSE;
}

static gboolean on_sighup(void *data) { // ok

	update_theme("refresh");

	#if defined(G_SOURCE_CONTINUE)
		return G_SOURCE_CONTINUE;
	#else
		return TRUE; // glib < 2.32
	#endif
}

static gboolean take_screenshot(void *data) { // ok (without window borders)

	GdkPaintable *paintable = gtk_widget_paintable_new(window);
	int width = gdk_paintable_get_intrinsic_width(paintable);
	int height = gdk_paintable_get_intrinsic_height(paintable);

	GtkSnapshot *snapshot = gtk_snapshot_new();
	gdk_paintable_snapshot(paintable, snapshot, width, height);
	GskRenderNode *node = gtk_snapshot_free_to_node(snapshot);
	cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
	cairo_t *cr = cairo_create(surface);
	gsk_render_node_draw(node, cr);

	G_GNUC_BEGIN_IGNORE_DEPRECATIONS // GTK 4.12+
	GdkPixbuf *image = gdk_pixbuf_get_from_surface(surface, 0, 0, width, height);
	G_GNUC_END_IGNORE_DEPRECATIONS

	if (image) {
		gdk_pixbuf_save(image, opt_screenshot, "png", NULL, "compression", "9", NULL);
		g_object_unref(image);
 		gchar *text = g_strdup_printf(_app("Theme reloaded, then screenshot saved (%s)."), opt_screenshot);
		update_statusbar(text);
		g_free(text);
	}

	cairo_destroy(cr);
	cairo_surface_destroy(surface);
	gsk_render_node_unref(node);
	g_object_unref(paintable);

	return FALSE;
}


// layout and widgets

static void create_window(gpointer app) {

	GtkWidget *vbox_window, *widgets;
	gboolean closeLeft = FALSE, closeRight = FALSE;
	gchar *text, *value;

	// window
	window = gtk_application_window_new(GTK_APPLICATION(app));
	gtk_widget_set_name(GTK_WIDGET(window), "AwfMainWindow");
	gtk_window_set_icon_name(GTK_WINDOW(window), GETTEXT_PACKAGE);

	text = g_strdup_printf(_app("A widget factory - GTK %d.%d"), GTK_MAJOR_VERSION, GTK_MINOR_VERSION);
	gtk_window_set_title(GTK_WINDOW(window), text);
	g_free(text);

	// theme auto or from command line
	if (strcmp((gchar*) current_theme, (gchar*) opt_theme) != 0)
		update_theme(opt_theme);
	else
		update_theme(current_theme);

	allow_update_theme = FALSE;
	if (current_direction == 0)
		current_direction = (gtk_widget_get_default_direction() == GTK_TEXT_DIR_LTR) ? 1 : 2;

	// layout
	vbox_window = BOXV;
	gtk_window_set_child(GTK_WINDOW(window), vbox_window);

		GMenu *gmm = g_menu_new();
		create_traditional_menubar(app, gmm);
		gtk_application_set_menubar(app, G_MENU_MODEL(gmm));
		gtk_application_window_set_show_menubar(GTK_APPLICATION_WINDOW(window), TRUE);

		const gchar *config = g_getenv("GTK_CSD");
		if (config && (strcmp(config, "1") == 0)) {

			// enable CSD for dialogs
			// except for custom dialogs
			g_object_set(gtk_settings_get_default(), "gtk-dialogs-use-header", TRUE, NULL);

			gtk_window_set_decorated(GTK_WINDOW(window), TRUE);

			GtkWidget *button;
			GtkWidget *headerbar = gtk_header_bar_new();
			gtk_header_bar_set_show_title_buttons(GTK_HEADER_BAR(headerbar), TRUE);

			gchar *tokens; // minimize, maximize, close, icon, menu
			g_object_get(gtk_widget_get_settings(headerbar), "gtk-decoration-layout", &tokens, NULL);
			if (g_str_has_prefix(tokens, "icon") || g_str_has_prefix(tokens, "menu"))
				closeLeft = TRUE;
			else if (g_str_has_suffix(tokens, "icon") || g_str_has_suffix(tokens, "menu"))
				closeRight = TRUE;
			if (g_getenv("AWF_DEBUG") != NULL)
				g_printf("headerbar tokens: %s %d %d\n", tokens, closeLeft, closeRight);
			g_free(tokens);

			// left
			headbarCloseLeft = gtk_image_new_from_icon_name(GETTEXT_PACKAGE);
			gtk_widget_add_css_class(headbarCloseLeft, "app-icon");
			gtk_widget_set_visible(headbarCloseLeft, closeLeft);
			gtk_header_bar_pack_start(GTK_HEADER_BAR(headerbar), headbarCloseLeft);

			button = gtk_menu_button_new();
			gtk_menu_button_set_menu_model(GTK_MENU_BUTTON(button), G_MENU_MODEL(gmm));
			gtk_menu_button_set_icon_name(GTK_MENU_BUTTON(button), "open-menu-symbolic");
			gtk_header_bar_pack_start(GTK_HEADER_BAR(headerbar), button);

			button = gtk_toggle_button_new_with_label("Btn1");
			gtk_header_bar_pack_start(GTK_HEADER_BAR(headerbar), button);

			button = gtk_toggle_button_new_with_label("Btn2");
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(button), TRUE);
			gtk_header_bar_pack_start(GTK_HEADER_BAR(headerbar), button);

			button = gtk_toggle_button_new_with_label("Btn3");
			gtk_header_bar_pack_start(GTK_HEADER_BAR(headerbar), button);

			// right
			headbarCloseRight = gtk_image_new_from_icon_name(GETTEXT_PACKAGE);
			gtk_widget_add_css_class(headbarCloseRight, "app-icon");
			gtk_widget_set_visible(headbarCloseRight, closeRight);
			gtk_header_bar_pack_end(GTK_HEADER_BAR(headerbar), headbarCloseRight);

			button = gtk_menu_button_new();
			gtk_menu_button_set_menu_model(GTK_MENU_BUTTON(button), G_MENU_MODEL(gmm));
			gtk_menu_button_set_icon_name(GTK_MENU_BUTTON(button), "open-menu-symbolic");
			gtk_header_bar_pack_end(GTK_HEADER_BAR(headerbar), button);

			button = gtk_toggle_button_new_with_label("Btn6");
			gtk_header_bar_pack_end(GTK_HEADER_BAR(headerbar), button);

			button = gtk_toggle_button_new_with_label("Btn5");
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(button), TRUE);
			gtk_header_bar_pack_end(GTK_HEADER_BAR(headerbar), button);

			button = gtk_toggle_button_new_with_label("Btn4");
			gtk_header_bar_pack_end(GTK_HEADER_BAR(headerbar), button);

			gtk_window_set_titlebar(GTK_WINDOW(window), headerbar);
		}

		toolbar = BOXH;
		gtk_widget_add_css_class(toolbar, "primary-toolbar");
		add_to(GTK_BOX(vbox_window), toolbar, FALSE, FALSE, 0, 0);
		create_toolbar(toolbar);

		widgets = BOXV;
		add_to(GTK_BOX(vbox_window), widgets, TRUE, TRUE, 0, 0);
			create_widgets(widgets);

		G_GNUC_BEGIN_IGNORE_DEPRECATIONS // GTK 4.10+
		statusbar = gtk_statusbar_new();
		G_GNUC_END_IGNORE_DEPRECATIONS
		// via add_progressbar_and_entrybar
		// for the progressbar of the statusbar, before adding statusbar
		gtk_widget_set_halign(gtk_widget_get_first_child(statusbar), GTK_ALIGN_FILL); // statusbar > box
		gtk_widget_set_hexpand(gtk_widget_get_first_child(statusbar), TRUE);          // statusbar > box
		gtk_widget_set_hexpand(gtk_widget_get_first_child(gtk_widget_get_first_child(statusbar)), TRUE); // statusbar > box > label
		add_to(GTK_BOX(vbox_window), statusbar, FALSE, FALSE, 0, 0);

		text = g_strdup_printf(_app("Theme %s loaded."), current_theme);
		update_statusbar(text);
		g_free(text);

	// go go go
	allow_update_theme = TRUE;
	update_text_direction(current_direction);
	g_signal_connect(window, "destroy", G_CALLBACK(quit), NULL);

	if (g_settings_schema_source_lookup(g_settings_schema_source_get_default(), value = "org.gnome.desktop.interface", FALSE))
		g_signal_connect(g_settings_new(value), "changed::gtk-theme", G_CALLBACK(notify_updated_gtktheme), "gtk-theme");
	if (g_settings_schema_source_lookup(g_settings_schema_source_get_default(), value = "org.mate.interface", FALSE))
		g_signal_connect(g_settings_new(value), "changed::gtk-theme", G_CALLBACK(notify_updated_gtktheme), "gtk-theme");

	if (g_settings_schema_source_lookup(g_settings_schema_source_get_default(), value = "org.gnome.desktop.wm.preferences", FALSE))
		g_signal_connect(g_settings_new(value), "changed::button-layout", G_CALLBACK(notify_updated_gtktheme), "button-layout");
	if (g_settings_schema_source_lookup(g_settings_schema_source_get_default(), value = "org.cinnamon.desktop.wm.preferences", FALSE))
		g_signal_connect(g_settings_new(value), "changed::button-layout", G_CALLBACK(notify_updated_gtktheme), "button-layout");
	if (g_settings_schema_source_lookup(g_settings_schema_source_get_default(), value = "org.mate.Marco.general", FALSE))
		g_signal_connect(g_settings_new(value), "changed::button-layout", G_CALLBACK(notify_updated_gtktheme), "button-layout");
	if (g_settings_schema_source_lookup(g_settings_schema_source_get_default(), value = "org.mate.interface", FALSE))
		g_signal_connect(g_settings_new(value), "changed::gtk-decoration-layout", G_CALLBACK(notify_updated_gtktheme), "gtk-decoration-layout");

	// gtk-can-change-accels for GTK 4.x | so same GTK 2.24 3.x 4.x & Qt 5.15 6.x
	accels_load(app);
	//GtkEventController *event = gtk_event_controller_key_new();
	//g_signal_connect(event, "key-released", G_CALLBACK(accels_change), window);
	//gtk_widget_add_controller(window, event);

	gtk_widget_set_visible(window, TRUE);
	if (headbarCloseLeft && headbarCloseRight) { // @todo not working here
		gtk_widget_set_visible(headbarCloseLeft, closeLeft);
		gtk_widget_set_visible(headbarCloseRight, closeRight);
	}
	add_progressbar_and_entrybar();
}

static void create_widgets(GtkWidget *root) { // ok

	GtkWidget *hbox_columns = BOXH;
	GtkWidget *vbox_column1 = BOXV, *vbox_combo_entry = BOXV, *hbox_spin = BOXH, *hbox_check_radio = BOXH, *vbox_check = BOXV, *vbox_radio = BOXV;
	GtkWidget *vbox_column2 = BOXV, *vbox_buttons = BOXV, *hbox_btns1 = BOXH, *hbox_btns2 = BOXH, *hbox_btns3 = BOXH, *hbox_btns4 = BOXH;
	GtkWidget *vbox_column3 = BOXV, *vbox_progressbar1 = BOXV, *vbox_progressbar2 = BOXV, *hbox_progressbar1 = BOXH, *hbox_progressbar2 = BOXH;
	GtkWidget *vbox_column4 = BOXV, *vbox_others = BOXV, *hbox_label = BOXH, *hbox_spinner = BOXH;
	GtkWidget *vpane = PANEV, *hpane1 = PANEH, *hpane2 = PANEH;
	GtkWidget *hbox_frame1 = BOXH, *hbox_frame2 = BOXH, *hbox_notebook1 = BOXH, *hbox_notebook2 = BOXH;

	// columns layout
	add_to(GTK_BOX(root), hbox_columns, TRUE, TRUE, 0, 0);

		// column 1
		add_to(GTK_BOX(hbox_columns), vbox_column1, TRUE, TRUE, 5, 0);
			add_to(GTK_BOX(vbox_column1), vbox_combo_entry, FALSE, TRUE, 5, 3);
				create_combos_entries(vbox_combo_entry);
			add_to(GTK_BOX(vbox_column1), hbox_spin, FALSE, FALSE, 5, 0);
				create_spinbuttons(hbox_spin);
			add_to(GTK_BOX(vbox_column1), hbox_check_radio, FALSE, TRUE, 5, 0);
				add_to(GTK_BOX(hbox_check_radio), vbox_check, TRUE, TRUE, 0, 0);
					create_checkbuttons(vbox_check);
				add_to(GTK_BOX(hbox_check_radio), vbox_radio, TRUE, TRUE, 0, 0);
					create_radiobuttons(vbox_radio);
		add_to(GTK_BOX(hbox_columns), SEPV, FALSE, FALSE, 0, 0);

		// column 2
		add_to(GTK_BOX(hbox_columns), vbox_column2, TRUE, TRUE, 5, 0);
			add_to(GTK_BOX(vbox_column2), vbox_buttons, FALSE, TRUE, 5, 3);
			add_to(GTK_BOX(vbox_column2), hbox_btns1, FALSE, FALSE, 5, 3);
			add_to(GTK_BOX(vbox_column2), hbox_btns2, FALSE, FALSE, 5, 3);
			add_to(GTK_BOX(vbox_column2), hbox_btns3, FALSE, FALSE, 5, 3);
			add_to(GTK_BOX(vbox_column2), hbox_btns4, FALSE, FALSE, 5, 3);
				create_otherbuttons(vbox_buttons, hbox_btns1, hbox_btns2, hbox_btns3, hbox_btns4);
		add_to(GTK_BOX(hbox_columns), SEPV, FALSE, FALSE, 0, 0);

		// column 3
		add_to(GTK_BOX(hbox_columns), vbox_column3, TRUE, TRUE, 5, 0);
			add_to(GTK_BOX(vbox_column3), vbox_progressbar1, FALSE, TRUE, 6, 10);
			add_to(GTK_BOX(vbox_column3), hbox_progressbar1, FALSE, FALSE, 5, 10);
			add_to(GTK_BOX(vbox_column3), hbox_progressbar2, FALSE, FALSE, 5, 10);
			add_to(GTK_BOX(vbox_column3), vbox_progressbar2, FALSE, TRUE, 5, 10);
				create_progressbars(vbox_progressbar1, hbox_progressbar1, hbox_progressbar2, vbox_progressbar2);
		add_to(GTK_BOX(hbox_columns), SEPV, FALSE, FALSE, 0, 0);

		// column 4
		add_to(GTK_BOX(hbox_columns), vbox_column4, TRUE, TRUE, 5, 0);
			add_to(GTK_BOX(vbox_column4), vbox_others, FALSE, TRUE, 5, 3);
				create_treview(vbox_others);
				add_to(GTK_BOX(vbox_others), hbox_label, FALSE, TRUE, 5, 0);
					create_labels(hbox_label);
				add_to(GTK_BOX(vbox_others), hbox_spinner, FALSE, TRUE, 5, 0);
					create_spinners(hbox_spinner);
				create_expander(vbox_others);

	add_to(GTK_BOX(root), SEPH, FALSE, FALSE, 0, 0);

	// paned layout
	add_to(GTK_BOX(root), vpane, TRUE, TRUE, 0, 0);

		gtk_paned_set_start_child(GTK_PANED(vpane), hpane1);
		gtk_paned_set_shrink_start_child(GTK_PANED(vpane), FALSE);
		gtk_widget_set_size_request(hpane1, -1, 70); // The 70

			gtk_box_set_homogeneous(GTK_BOX(hbox_frame1), TRUE);
			gtk_box_set_spacing(GTK_BOX(hbox_frame1), 3);
			gtk_widget_set_margin_start(hbox_frame1, 10);
			gtk_widget_set_margin_end(hbox_frame1, 10);
			gtk_widget_set_margin_top(hbox_frame1, 10);
			gtk_widget_set_margin_bottom(hbox_frame1, 10);
			gtk_paned_set_start_child(GTK_PANED(hpane1), hbox_frame1);
			gtk_paned_set_resize_start_child(GTK_PANED(hpane1), FALSE);
			gtk_paned_set_shrink_start_child(GTK_PANED(hpane1), FALSE);

			gtk_box_set_homogeneous(GTK_BOX(hbox_frame2), TRUE);
			gtk_box_set_spacing(GTK_BOX(hbox_frame2), 3);
			gtk_widget_set_margin_start(hbox_frame2, 10);
			gtk_widget_set_margin_end(hbox_frame2, 10);
			gtk_widget_set_margin_top(hbox_frame2, 10);
			gtk_widget_set_margin_bottom(hbox_frame2, 10);
			gtk_paned_set_end_child(GTK_PANED(hpane1), hbox_frame2);

			create_frames(hbox_frame1, hbox_frame2);

		gtk_paned_set_end_child(GTK_PANED(vpane), hpane2);
		gtk_paned_set_shrink_end_child(GTK_PANED(vpane), FALSE);
		//gtk_widget_set_size_request(hpane2, -1, 120); // The 120

			gtk_box_set_homogeneous(GTK_BOX(hbox_notebook1), TRUE);
			gtk_box_set_spacing(GTK_BOX(hbox_notebook1), 3);
			gtk_widget_set_margin_start(hbox_notebook1, 10);
			gtk_widget_set_margin_end(hbox_notebook1, 10);
			gtk_widget_set_margin_top(hbox_notebook1, 10);
			gtk_widget_set_margin_bottom(hbox_notebook1, 10);
			gtk_paned_set_start_child(GTK_PANED(hpane2), hbox_notebook1);
			gtk_paned_set_resize_start_child(GTK_PANED(hpane2), FALSE);
			gtk_paned_set_shrink_start_child(GTK_PANED(hpane2), FALSE);

			gtk_box_set_homogeneous(GTK_BOX(hbox_notebook2), TRUE);
			gtk_box_set_spacing(GTK_BOX(hbox_notebook2), 3);
			gtk_widget_set_margin_start(hbox_notebook2, 10);
			gtk_widget_set_margin_end(hbox_notebook2, 10);
			gtk_widget_set_margin_top(hbox_notebook2, 10);
			gtk_widget_set_margin_bottom(hbox_notebook2, 10);
			gtk_paned_set_end_child(GTK_PANED(hpane2), hbox_notebook2);

			create_notebooks(hbox_notebook1, hbox_notebook2);
}

static void add_progressbar_and_entrybar() {

	// entry toolbar
	toolbarentry = gtk_entry_new();
	gtk_entry_set_placeholder_text(GTK_ENTRY(toolbarentry), "...");
	gtk_widget_set_visible(toolbarentry, FALSE);
	gtk_widget_set_valign(toolbarentry, GTK_ALIGN_CENTER);
	gtk_widget_set_vexpand(toolbarentry, FALSE);
	gtk_widget_insert_after(toolbarentry, toolbar, toolbarend); // end left

	// progressbar toolbar
	progressbar8 = gtk_progress_bar_new();
	gtk_widget_set_size_request(progressbar8, 140, 1);
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar8), 0);
	gtk_orientable_set_orientation(GTK_ORIENTABLE(progressbar8), GTK_ORIENTATION_HORIZONTAL);
	gtk_widget_set_visible(progressbar8, FALSE);
	gtk_widget_set_valign(progressbar8, GTK_ALIGN_CENTER);
	gtk_widget_set_halign(progressbar8, GTK_ALIGN_END);
	gtk_widget_set_hexpand(progressbar8, TRUE);
	gtk_widget_insert_after(progressbar8, toolbar, gtk_widget_get_last_child(toolbar)); // end right

	// progressbar statusbar
	progressbar9 = gtk_progress_bar_new();
	gtk_widget_set_size_request(progressbar9, 140, 1);
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar9), 0);
	gtk_orientable_set_orientation(GTK_ORIENTABLE(progressbar9), GTK_ORIENTATION_HORIZONTAL);
	gtk_widget_set_visible(progressbar9, FALSE);
	gtk_widget_set_valign(progressbar9, GTK_ALIGN_CENTER);
	gtk_widget_set_halign(progressbar9, GTK_ALIGN_END);
	gtk_widget_set_hexpand(progressbar9, TRUE);
	gtk_widget_insert_after(progressbar9, gtk_widget_get_first_child(statusbar), gtk_widget_get_first_child(gtk_widget_get_first_child(statusbar))); // statusbar > box > label, statusbar > box > progressbar
}

static void add_to(GtkBox *box, GtkWidget *widget, gboolean fill, gboolean expand, guint padding, guint spacing) { // ok

	if (fill && expand) {
		gtk_widget_set_halign(widget, GTK_ALIGN_FILL);
		gtk_widget_set_valign(widget, GTK_ALIGN_FILL);
		gtk_widget_set_hexpand(widget, TRUE);
		gtk_widget_set_vexpand(widget, TRUE);
	}
	else if (fill) {
		gtk_widget_set_halign(widget, GTK_ALIGN_FILL);
		gtk_widget_set_valign(widget, GTK_ALIGN_START);
		gtk_widget_set_hexpand(widget, FALSE);
		gtk_widget_set_vexpand(widget, FALSE);
	}
	else {
		gtk_widget_set_hexpand(widget, FALSE);
		gtk_widget_set_vexpand(widget, FALSE);
	}

	if (GTK_IS_BOX(widget) && (padding > 0)) {
		gtk_widget_set_margin_start(widget, padding);
		gtk_widget_set_margin_end(widget, padding);
		gtk_widget_set_margin_top(widget, padding);
		gtk_widget_set_margin_bottom(widget, padding);
	}

	if (GTK_IS_BOX(widget) && (spacing > 0)) {
		gtk_box_set_spacing(GTK_BOX(widget), spacing);
	}

	gtk_box_append(box, widget);

	if (!GTK_IS_BOX(widget)) {
		G_GNUC_BEGIN_IGNORE_DEPRECATIONS // GTK 4.10+
		GtkStyleContext *style = gtk_widget_get_style_context(widget);
		gchar *text = gtk_style_context_to_string(style, GTK_STYLE_CONTEXT_PRINT_RECURSE);
		G_GNUC_END_IGNORE_DEPRECATIONS
		// @todo remove [ ]
		g_strstrip(text);
		gtk_widget_set_tooltip_text(widget, text);
		g_free(text);
	}
}

static void create_toolbar(GtkWidget *root) { // ok

	GtkWidget *icon1, *icon2, *icon3, *icon4, *icon5, *icon6, *icon7, *icon8, *icon9;

	// GTK_BUTTON
	icon1 = gtk_button_new_from_icon_name("gtk-open");
	gtk_widget_add_css_class(icon1, "flat");
	g_signal_connect(icon1, "clicked", G_CALLBACK(dialog_open), NULL);

	icon2 = gtk_button_new_from_icon_name("gtk-open");
	gtk_widget_set_sensitive(icon2, FALSE);

	icon3 = gtk_button_new_from_icon_name("gtk-save");
	g_signal_connect(icon3, "clicked", G_CALLBACK(dialog_save), NULL);

	icon4 = gtk_button_new_from_icon_name("gtk-refresh");
	g_signal_connect_swapped(icon4, "clicked", G_CALLBACK(update_theme), "refresh");

	icon5 = gtk_button_new_from_icon_name("camera-photo");
	gtk_widget_set_sensitive(icon5, opt_screenshot ? TRUE : FALSE);
	g_signal_connect(icon5, "clicked", G_CALLBACK(take_screenshot), NULL);

	icon6 = gtk_button_new_from_icon_name("gtk-dialog-info");
	g_signal_connect(icon6, "clicked", G_CALLBACK(display_notification), NULL);

	// GTK_TOGGLE_BUTTON
	icon7 = gtk_toggle_button_new();
	gtk_button_set_icon_name(GTK_BUTTON(icon7), "gtk-add");
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(icon7), TRUE);
	g_signal_connect(icon7, "clicked", G_CALLBACK(update_widgets), NULL);

	icon8 = gtk_toggle_button_new();
	gtk_button_set_icon_name(GTK_BUTTON(icon8), "gtk-remove");
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(icon8), FALSE);
	g_signal_connect(icon8, "clicked", G_CALLBACK(update_widgets), NULL);

	icon9 = gtk_toggle_button_new();
	gtk_button_set_icon_name(GTK_BUTTON(icon9), "gtk-close");
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(icon9), FALSE);
	gtk_widget_set_sensitive(icon9, FALSE);
	toolbarend = icon9;

	// layout
	add_to(GTK_BOX(root), icon1, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), icon2, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), icon3, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), SEPV, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), icon4, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), icon5, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), icon6, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), SEPV, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), icon7, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), icon8, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), icon9, FALSE, FALSE, 0, 0);
}

static void create_combos_entries(GtkWidget *root) { // ok

	GtkWidget *combo1, *combo2, *combo3, *combo4, *entry1, *entry2, *entry3, *entry4;

	// GTK_COMBO_BOX
	G_GNUC_BEGIN_IGNORE_DEPRECATIONS // GTK 4.10+

	//if GTK_CHECK_VERSION (4,10,0)
	//	combo1 = gtk_drop_down_new_from_strings((const char * const[]) { "Combo box entry 1", "Combo box entry 2", NULL });
	//	//gtk_drop_down_set_enable_search(GTK_DROP_DOWN(combo1), TRUE);
	//	gtk_drop_down_set_selected(GTK_DROP_DOWN(combo1), 0);
	//else
		combo1 = gtk_combo_box_text_new_with_entry();
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo1), "Combo box entry 1");
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo1), "Combo box entry 2");
		gtk_combo_box_set_active(GTK_COMBO_BOX(combo1), 0);
	//endif

	//if GTK_CHECK_VERSION (4,10,0)
	//	combo2 = gtk_drop_down_new_from_strings((const char * const[]) { "Combo box entry 1", "Combo box entry 2", NULL });
	//	gtk_drop_down_set_selected(GTK_DROP_DOWN(combo2), 0);
	//else
		combo2 = gtk_combo_box_text_new_with_entry();
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo2), "Combo box entry 1");
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo2), "Combo box entry 2");
		gtk_combo_box_set_active(GTK_COMBO_BOX(combo2), 0);
	//endif
	gtk_widget_set_sensitive(combo2, FALSE);

	//if GTK_CHECK_VERSION (4,10,0)
	//	combo3 = gtk_drop_down_new_from_strings((const char * const[]) { "Combo box 1", "Combo box 2", NULL });
	//	gtk_drop_down_set_selected(GTK_DROP_DOWN(combo3), 0);
	//else
		combo3 = gtk_combo_box_text_new();
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo3), "Combo box 1");
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo3), "Combo box 2");
		gtk_combo_box_set_active(GTK_COMBO_BOX(combo3), 0);
	//endif

	//if GTK_CHECK_VERSION (4,10,0)
	//	combo4 = gtk_drop_down_new_from_strings((const char * const[]) { "Combo box 1", "Combo box 2", NULL });
	//	gtk_drop_down_set_selected(GTK_DROP_DOWN(combo4), 0);
	//else
		combo4 = gtk_combo_box_text_new();
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo4), "Combo box 1");
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo4), "Combo box 2");
		gtk_combo_box_set_active(GTK_COMBO_BOX(combo4), 0);
	//endif
	gtk_widget_set_sensitive(combo4, FALSE);

	G_GNUC_END_IGNORE_DEPRECATIONS

	// GTK_ENTRY
	entry1 = gtk_entry_new();
	gtk_editable_set_text(GTK_EDITABLE(entry1), "Entry");
	gtk_entry_set_placeholder_text(GTK_ENTRY(entry1), "Placeholder");

	entry2 = gtk_entry_new();
	gtk_editable_set_text(GTK_EDITABLE(entry2), "Entry");
	gtk_widget_set_sensitive(entry2, FALSE);

	entry3 = gtk_entry_new();
	gtk_editable_set_text(GTK_EDITABLE(entry3), "Entry");
	gtk_entry_set_icon_from_icon_name(GTK_ENTRY(entry3), GTK_ENTRY_ICON_PRIMARY, "gtk-clear");
	gtk_entry_set_icon_from_icon_name(GTK_ENTRY(entry3), GTK_ENTRY_ICON_SECONDARY, "gtk-find");
	gtk_entry_set_placeholder_text(GTK_ENTRY(entry3), "Placeholder");

	entry4 = gtk_entry_new();
	gtk_editable_set_text(GTK_EDITABLE(entry4), "Entry");
	gtk_entry_set_icon_from_icon_name(GTK_ENTRY(entry4), GTK_ENTRY_ICON_PRIMARY, "gtk-clear");
	gtk_entry_set_icon_from_icon_name(GTK_ENTRY(entry4), GTK_ENTRY_ICON_SECONDARY, "gtk-find");
	gtk_widget_set_sensitive(entry4, FALSE);

	// layout
	add_to(GTK_BOX(root), combo1, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), combo2, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), combo3, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), combo4, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), entry1, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), entry2, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), entry3, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), entry4, FALSE, FALSE, 0, 0);
}

static void create_spinbuttons(GtkWidget *root) { // ok

	GtkWidget *spinbutton1, *spinbutton2;

	// GTK_SPIN_BUTTON
	spinbutton1 = gtk_spin_button_new_with_range(-100, 100, 1);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton1), 1);

	spinbutton2 = gtk_spin_button_new_with_range(-100, 100, 1);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton2), 1);
	gtk_widget_set_sensitive(spinbutton2, FALSE);

	// layout
	add_to(GTK_BOX(root), spinbutton1, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), BOXH, TRUE, TRUE, 0, 0); // empty space
	add_to(GTK_BOX(root), spinbutton2, FALSE, FALSE, 0, 0);
}

static void create_checkbuttons(GtkWidget *root) { // ok

	GtkWidget *checkbutton1, *checkbutton2, *checkbutton3, *checkbutton4, *checkbutton5, *checkbutton6;

	// GTK_CHECK_BUTTON
	checkbutton1 = gtk_check_button_new_with_label("Check btn 1");

	checkbutton2 = gtk_check_button_new_with_label("Check btn 2");
	gtk_check_button_set_active(GTK_CHECK_BUTTON(checkbutton2), TRUE);

	checkbutton3 = gtk_check_button_new_with_label("Check btn 3");
	gtk_check_button_set_inconsistent(GTK_CHECK_BUTTON(checkbutton3), TRUE);

	checkbutton4 = gtk_check_button_new_with_label("Check btn 4");
	gtk_widget_set_sensitive(checkbutton4, FALSE);

	checkbutton5 = gtk_check_button_new_with_label("Check btn 5");
	gtk_check_button_set_active(GTK_CHECK_BUTTON(checkbutton5), TRUE);
	gtk_widget_set_sensitive(checkbutton5, FALSE);

	checkbutton6 = gtk_check_button_new_with_label("Check btn 6");
	gtk_check_button_set_inconsistent(GTK_CHECK_BUTTON(checkbutton6), TRUE);
	gtk_widget_set_sensitive(checkbutton6, FALSE);

	// layout
	add_to(GTK_BOX(root), checkbutton1, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), checkbutton2, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), checkbutton3, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), checkbutton4, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), checkbutton5, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), checkbutton6, FALSE, FALSE, 0, 0);
}

static void create_radiobuttons(GtkWidget *root) { // ok

	GtkWidget *radiobutton1, *radiobutton2, *radiobutton3, *radiobutton4, *radiobutton5, *radiobutton6;

	// GTK_RADIO_BUTTON
	radiobutton1 = gtk_check_button_new_with_label("Radio btn 1");
	gtk_check_button_set_group(GTK_CHECK_BUTTON(radiobutton1), NULL);

	radiobutton2 = gtk_check_button_new_with_label("Radio btn 2");
	gtk_check_button_set_group(GTK_CHECK_BUTTON(radiobutton2), GTK_CHECK_BUTTON(radiobutton1));
	gtk_check_button_set_active(GTK_CHECK_BUTTON(radiobutton2), TRUE);

	radiobutton3 = gtk_check_button_new_with_label("Radio btn 3");
	gtk_check_button_set_group(GTK_CHECK_BUTTON(radiobutton3), GTK_CHECK_BUTTON(radiobutton1));
	gtk_check_button_set_inconsistent(GTK_CHECK_BUTTON(radiobutton3), TRUE);

	radiobutton4 = gtk_check_button_new_with_label("Radio btn 4");
	gtk_check_button_set_group(GTK_CHECK_BUTTON(radiobutton4), NULL);
	gtk_widget_set_sensitive(radiobutton4, FALSE);

	radiobutton5 = gtk_check_button_new_with_label("Radio btn 5");
	gtk_check_button_set_group(GTK_CHECK_BUTTON(radiobutton5), GTK_CHECK_BUTTON(radiobutton4));
	gtk_check_button_set_active(GTK_CHECK_BUTTON(radiobutton5), TRUE);
	gtk_widget_set_sensitive(radiobutton5, FALSE);

	radiobutton6 = gtk_check_button_new_with_label("Radio btn 6");
	gtk_check_button_set_group(GTK_CHECK_BUTTON(radiobutton6), GTK_CHECK_BUTTON(radiobutton4));
	gtk_check_button_set_inconsistent(GTK_CHECK_BUTTON(radiobutton6), TRUE);
	gtk_widget_set_sensitive(radiobutton6, FALSE);

	// layout
	add_to(GTK_BOX(root), radiobutton1, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), radiobutton2, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), radiobutton3, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), radiobutton4, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), radiobutton5, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), radiobutton6, FALSE, FALSE, 0, 0);
}

static void create_otherbuttons(GtkWidget *root1, GtkWidget *root2, GtkWidget *root3, GtkWidget *root4, GtkWidget *root5) { // ok

	GtkWidget *button1, *button2, *button3, *button4, *button5, *button6, *button7, *button8, *button9;
	GtkWidget *button10, *button11, *button12, *button13, *button14, *button17;

	// GTK_BUTTON
	button1 = gtk_button_new_with_label("Button 1");

	button2 = gtk_button_new_with_label("Button 2");
	gtk_widget_set_sensitive(button2, FALSE);

	button3 = gtk_toggle_button_new_with_label("Button 3");

	button4 = gtk_toggle_button_new_with_label("Button 4");
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(button3), TRUE);
	gtk_widget_set_sensitive(button4, FALSE);

	// GTK_COLOR_DIALOG_BUTTON or GTK_COLOR_BUTTON
	#if GTK_CHECK_VERSION (4,10,0)
		GdkRGBA color;
		gdk_rgba_parse(&color, "#7796ba");
		button5 = gtk_color_dialog_button_new(gtk_color_dialog_new());
		gtk_color_dialog_button_set_rgba(GTK_COLOR_DIALOG_BUTTON(button5), &color);
		gtk_widget_set_tooltip_text(button5, _app("Choose a color"));
	#else
		GdkRGBA color;
		gdk_rgba_parse(&color, "#7796ba");
		button5 = gtk_color_button_new_with_rgba(&color);
		gtk_widget_set_tooltip_text(button5, _app("Choose a color"));
	#endif

	// GTK_FONT_DIALOG_BUTTON or GTK_FONT_BUTTON
	#if GTK_CHECK_VERSION (4,10,0)
		button6 = gtk_font_dialog_button_new(gtk_font_dialog_new());
		find_and_update_labels(button6, FALSE);
		gtk_widget_set_size_request(button6, 186, -1); // The 186
		gtk_widget_set_tooltip_text(button6, _app("Choose a font"));
	#else
		button6 = gtk_font_button_new();
		find_and_update_labels(button6, FALSE);
		gtk_widget_set_size_request(button6, 186, -1); // The 186
		gtk_widget_set_tooltip_text(button6, _app("Choose a font"));
	#endif

	// GTK_BUTTON
	button7 = gtk_button_new_with_label(_app("Choose a file"));
	gtk_widget_add_css_class(button7, "awf-cheatcode-filebtn");
	g_signal_connect(button7, "clicked", G_CALLBACK(dialog_open), NULL);

	button8 = gtk_button_new_with_label(_app("Choose a folder"));
	gtk_widget_add_css_class(button8, "awf-cheatcode-folderbtn");
	g_signal_connect(button8, "clicked", G_CALLBACK(dialog_open), NULL);

	// GTK_SWITCH (for GTK_OPTION_MENU)
	button9 = gtk_switch_new();
	gtk_switch_set_active(GTK_SWITCH(button9), TRUE);

	button10 = gtk_switch_new();
	gtk_switch_set_active(GTK_SWITCH(button10), TRUE);
	gtk_widget_set_sensitive(button10, FALSE);

	button11 = gtk_switch_new();
	gtk_switch_set_active(GTK_SWITCH(button11), FALSE);

	button12 = gtk_switch_new();
	gtk_switch_set_active(GTK_SWITCH(button12), FALSE);
	gtk_widget_set_sensitive(button12, FALSE);

	// GTK_LINK_BUTTON
	button13 = gtk_link_button_new_with_label("https://github.com/luigifab/awf-extended", "Link button");

	button14 = gtk_link_button_new_with_label("https://github.com/luigifab/awf-extended", "Link button");
	gtk_widget_set_sensitive(button14, FALSE);

	// GTK_VOLUME_BUTTON
	G_GNUC_BEGIN_IGNORE_DEPRECATIONS // GTK 4.10+

	button15 = gtk_volume_button_new();
	gtk_scale_button_set_value(GTK_SCALE_BUTTON(button15), 0.5);

	button16 = gtk_volume_button_new();
	gtk_scale_button_set_value(GTK_SCALE_BUTTON(button16), 0);
	gtk_widget_set_sensitive(button16, FALSE);

	G_GNUC_END_IGNORE_DEPRECATIONS

	// GTK_MENU_BUTTON
	button17 = gtk_menu_button_new();
	gtk_menu_button_set_icon_name(GTK_MENU_BUTTON(button17), "open-menu-symbolic");
	GMenu *menu = g_menu_new();
	g_menu_append_item(menu, g_menu_item_new("Popover item 1", NULL));
	g_menu_append_item(menu, g_menu_item_new("Popover item 2", NULL));
	g_menu_append_item(menu, g_menu_item_new("Popover item 3", NULL));
	gtk_menu_button_set_menu_model(GTK_MENU_BUTTON(button17), G_MENU_MODEL(menu));

	// layout
	add_to(GTK_BOX(root1), button1, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root1), button2, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root1), button3, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root1), button4, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root1), button5, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root1), button6, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root1), button7, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root1), button8, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root2), button9, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root2), BOXH, TRUE, TRUE, 0, 0); // empty space
	add_to(GTK_BOX(root2), button10, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root3), button11, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root3), BOXH, TRUE, TRUE, 0, 0); // empty space
	add_to(GTK_BOX(root3), button12, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root4), button13, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root4), BOXH, TRUE, TRUE, 0, 0); // empty space
	add_to(GTK_BOX(root4), button14, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root5), button15, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root5), button16, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root5), button17, FALSE, FALSE, 0, 0);
}

static void create_progressbars(GtkWidget *root1, GtkWidget *root2, GtkWidget *root3, GtkWidget *root4) { // ok

	// GTK_PROGRESS_BAR
	progressbar1 = gtk_progress_bar_new();
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar1), 0.5);
	gtk_orientable_set_orientation(GTK_ORIENTABLE(progressbar1), GTK_ORIENTATION_HORIZONTAL);

	progressbar2 = gtk_progress_bar_new();
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar2), 0.5);
	gtk_orientable_set_orientation(GTK_ORIENTABLE(progressbar2), GTK_ORIENTATION_HORIZONTAL);
	gtk_progress_bar_set_inverted(GTK_PROGRESS_BAR(progressbar2), TRUE);
	gtk_widget_add_css_class(progressbar2, "awf-cheatcode-prbr2");

	progressbar3 = gtk_progress_bar_new();
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar3), 0.5);
	gtk_orientable_set_orientation(GTK_ORIENTABLE(progressbar3), GTK_ORIENTATION_VERTICAL);
	gtk_widget_set_size_request(progressbar3, -1, 100); // The 100

	progressbar4 = gtk_progress_bar_new();
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar4), 0.5);
	gtk_orientable_set_orientation(GTK_ORIENTABLE(progressbar4), GTK_ORIENTATION_VERTICAL);
	gtk_progress_bar_set_inverted(GTK_PROGRESS_BAR(progressbar4), TRUE);

	// GTK_SCALE
	scale1 = create_horizontal_scale(50, FALSE, FALSE, GTK_POS_TOP);
	g_signal_connect(scale1, "value_changed", G_CALLBACK(update_values), NULL);

	scale2 = create_horizontal_scale(50, FALSE, TRUE, GTK_POS_TOP);
	g_signal_connect(scale2, "value_changed", G_CALLBACK(update_values), NULL);

	scale3 = create_vertical_scale(50, FALSE, FALSE, GTK_POS_TOP);
	g_signal_connect(scale3, "value_changed", G_CALLBACK(update_values), NULL);

	scale4 = create_vertical_scale(50, FALSE, TRUE, GTK_POS_TOP);
	g_signal_connect(scale4, "value_changed", G_CALLBACK(update_values), NULL);

	scale5 = create_vertical_scale(50, FALSE, FALSE, GTK_POS_TOP);
	update_marks(GTK_SCALE(scale5), FALSE, GTK_POS_LEFT);
	g_signal_connect(scale5, "value_changed", G_CALLBACK(update_values), NULL);

	scale6 = create_vertical_scale(50, FALSE, TRUE, GTK_POS_TOP);
	update_marks(GTK_SCALE(scale6), FALSE, GTK_POS_RIGHT);
	g_signal_connect(scale6, "value_changed", G_CALLBACK(update_values), NULL);

	// GTK_LEVEL_BAR
	levelbar1 = gtk_level_bar_new();
	gtk_level_bar_set_mode(GTK_LEVEL_BAR(levelbar1), GTK_LEVEL_BAR_MODE_CONTINUOUS);
	gtk_level_bar_set_value(GTK_LEVEL_BAR(levelbar1), 0.5);
	gtk_orientable_set_orientation(GTK_ORIENTABLE(levelbar1), GTK_ORIENTATION_VERTICAL);

	levelbar2 = gtk_level_bar_new();
	gtk_level_bar_set_mode(GTK_LEVEL_BAR(levelbar2), GTK_LEVEL_BAR_MODE_CONTINUOUS);
	gtk_level_bar_set_value(GTK_LEVEL_BAR(levelbar2), 0.5);
	gtk_orientable_set_orientation(GTK_ORIENTABLE(levelbar2), GTK_ORIENTATION_VERTICAL);
	gtk_level_bar_set_inverted(GTK_LEVEL_BAR(levelbar2), TRUE);

	levelbar3 = gtk_level_bar_new_for_interval(0, 5);
	gtk_level_bar_set_mode(GTK_LEVEL_BAR(levelbar3), GTK_LEVEL_BAR_MODE_DISCRETE);
	gtk_level_bar_set_value(GTK_LEVEL_BAR(levelbar3), 2);
	gtk_orientable_set_orientation(GTK_ORIENTABLE(levelbar3), GTK_ORIENTATION_VERTICAL);

	levelbar4 = gtk_level_bar_new_for_interval(0, 5);
	gtk_level_bar_set_mode(GTK_LEVEL_BAR(levelbar4), GTK_LEVEL_BAR_MODE_DISCRETE);
	gtk_level_bar_set_value(GTK_LEVEL_BAR(levelbar4), 2);
	gtk_orientable_set_orientation(GTK_ORIENTABLE(levelbar4), GTK_ORIENTATION_VERTICAL);
	gtk_level_bar_set_inverted(GTK_LEVEL_BAR(levelbar4), TRUE);

	levelbar5 = gtk_level_bar_new();
	gtk_level_bar_set_mode(GTK_LEVEL_BAR(levelbar5), GTK_LEVEL_BAR_MODE_CONTINUOUS);
	gtk_level_bar_set_value(GTK_LEVEL_BAR(levelbar5), 0.5);

	levelbar6 = gtk_level_bar_new();
	gtk_level_bar_set_mode(GTK_LEVEL_BAR(levelbar6), GTK_LEVEL_BAR_MODE_CONTINUOUS);
	gtk_level_bar_set_value(GTK_LEVEL_BAR(levelbar6), 0.5);
	gtk_level_bar_set_inverted(GTK_LEVEL_BAR(levelbar6), TRUE);

	levelbar7 = gtk_level_bar_new_for_interval(0, 5);
	gtk_level_bar_set_mode(GTK_LEVEL_BAR(levelbar7), GTK_LEVEL_BAR_MODE_DISCRETE);
	gtk_level_bar_set_value(GTK_LEVEL_BAR(levelbar7), 2);

	levelbar8 = gtk_level_bar_new_for_interval(0, 5);
	gtk_level_bar_set_mode(GTK_LEVEL_BAR(levelbar8), GTK_LEVEL_BAR_MODE_DISCRETE);
	gtk_level_bar_set_value(GTK_LEVEL_BAR(levelbar8), 2);
	gtk_level_bar_set_inverted(GTK_LEVEL_BAR(levelbar8), TRUE);

	// layout
	add_to(GTK_BOX(root1), progressbar1, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root1), progressbar2, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root1), scale1, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root1), scale2, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root2), progressbar3, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root2), progressbar4, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root2), levelbar1, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root2), levelbar2, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root2), levelbar3, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root2), levelbar4, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root3), scale3, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root3), scale5, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root3), scale6, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root3), scale4, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root4), levelbar5, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root4), levelbar6, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root4), levelbar7, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root4), levelbar8, FALSE, FALSE, 0, 0);
}

static void create_labels(GtkWidget *root) { // ok

	GtkWidget *label1, *label2;

	// GTK_LABEL
	label1 = gtk_label_new("Label 1");

	label2 = gtk_label_new("Label 2");
	gtk_widget_set_sensitive(label2, FALSE);

	// layout
	add_to(GTK_BOX(root), label1, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), BOXH, TRUE, TRUE, 0, 0); // empty space
	add_to(GTK_BOX(root), label2, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), BOXH, TRUE, TRUE, 0, 0); // empty space
}

static void create_spinners(GtkWidget *root) { // ok

	GtkWidget *spinner1, *spinner2;

	// GTK_SPINNER
	spinner1 = gtk_spinner_new();
	gtk_widget_set_size_request(spinner1, 20, 20);

	spinner2 = gtk_spinner_new();
	gtk_widget_set_size_request(spinner2, 20, 20);
	gtk_widget_set_sensitive(spinner2, FALSE);
	//gtk_spinner_start(GTK_SPINNER(spinner2));

	// layout
	add_to(GTK_BOX(root), spinner1, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), BOXH, TRUE, TRUE, 0, 0); // empty space
	add_to(GTK_BOX(root), spinner2, FALSE, FALSE, 0, 0);
	add_to(GTK_BOX(root), BOXH, TRUE, TRUE, 0, 0); // empty space
}

static void create_expander(GtkWidget *root) { // ok

	GtkWidget *expander, *scrolled_window, *tv;
	GtkTextBuffer *buffer;
	gchar *text;

	// GTK_EXPANDER
	expander = gtk_expander_new(_app("More..."));
	gtk_expander_set_expanded(GTK_EXPANDER(expander), TRUE);

	// GTK_SCROLLED_WINDOW
	scrolled_window = gtk_scrolled_window_new();
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
	gtk_widget_set_size_request(scrolled_window, -1, 120);

	const gchar *config = g_getenv("GTK_OVERLAY_SCROLLING");
	if (config && (strcmp(config, "0") == 0)) {
		gtk_scrolled_window_set_overlay_scrolling(GTK_SCROLLED_WINDOW(scrolled_window), FALSE);
		gtk_widget_add_css_class(gtk_scrolled_window_get_hscrollbar(GTK_SCROLLED_WINDOW(scrolled_window)), "discrete");
		gtk_widget_add_css_class(gtk_scrolled_window_get_vscrollbar(GTK_SCROLLED_WINDOW(scrolled_window)), "discrete");
	}

	// GTK_TEXT_VIEW
	tv = gtk_text_view_new();
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(tv), GTK_WRAP_WORD);
	text = g_strdup_printf("%s %s", _app("A widget factory is a theme preview application for GTK and Qt. It displays the various widget types in a single window allowing to see the visual effect of the applied theme."), _app("A widget factory is a theme preview application for GTK and Qt. It displays the various widget types in a single window allowing to see the visual effect of the applied theme."));
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(tv));
	gtk_text_buffer_set_text(GTK_TEXT_BUFFER(buffer), text, -1);
	g_free(text);

	// layout
	gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolled_window), tv);
	gtk_expander_set_child(GTK_EXPANDER(expander), scrolled_window);
	add_to(GTK_BOX(root), expander, FALSE, FALSE, 0, 0);
}

static void create_frames(GtkWidget *root1, GtkWidget *root2) { // ok

	GtkWidget *frame1, *frame2, *frame3, *frame4;

	// GTK_FRAME
	frame1 = gtk_frame_new("Frame (shadow in)");
	gtk_widget_add_css_class(frame1, "border-inset");

	frame2 = gtk_frame_new("Frame (shadow out)");
	gtk_widget_add_css_class(frame2, "border-outset");

	frame3 = gtk_frame_new("Frame (shadow etched in)");
	gtk_widget_add_css_class(frame3, "border-groove");

	frame4 = gtk_frame_new("Frame (shadow etched out)");
	gtk_widget_add_css_class(frame4, "border-ridge");
	gtk_widget_set_sensitive(frame4, FALSE);

	// layout
	add_to(GTK_BOX(root1), frame1, TRUE, TRUE, 0, 0);
	add_to(GTK_BOX(root1), frame2, TRUE, TRUE, 0, 0);
	add_to(GTK_BOX(root2), frame3, TRUE, TRUE, 0, 0);
	add_to(GTK_BOX(root2), frame4, TRUE, TRUE, 0, 0);
}

static void create_notebooks(GtkWidget *root1, GtkWidget *root2) { // ok

	// GTK_NOTEBOOK
	notebook1 = gtk_notebook_new();
	gtk_notebook_popup_enable(GTK_NOTEBOOK(notebook1));
	gtk_notebook_set_scrollable(GTK_NOTEBOOK(notebook1), FALSE);
	gtk_notebook_set_tab_pos(GTK_NOTEBOOK(notebook1), GTK_POS_TOP);
		create_notebook_tab(notebook1, "Tab1", NULL, FALSE);
		create_notebook_tab(notebook1, "Tab2", NULL, FALSE);
		create_notebook_tab(notebook1, "Tab3", NULL, TRUE);
		create_notebook_tab(notebook1, "Tab4", NULL, TRUE);

	notebook2 = gtk_notebook_new();
	gtk_notebook_popup_enable(GTK_NOTEBOOK(notebook2));
	gtk_notebook_set_scrollable(GTK_NOTEBOOK(notebook2), FALSE);
	gtk_notebook_set_tab_pos(GTK_NOTEBOOK(notebook2), GTK_POS_BOTTOM);
		create_notebook_tab(notebook2, "Tab1", NULL, FALSE);
		create_notebook_tab(notebook2, "Tab2", NULL, FALSE);
		create_notebook_tab(notebook2, "Tab3", NULL, TRUE);
		create_notebook_tab(notebook2, "Tab4", NULL, TRUE);

	notebook3 = gtk_notebook_new();
	gtk_notebook_popup_enable(GTK_NOTEBOOK(notebook3));
	gtk_notebook_set_scrollable(GTK_NOTEBOOK(notebook3), FALSE);
	gtk_notebook_set_tab_pos(GTK_NOTEBOOK(notebook3), GTK_POS_LEFT);
		create_notebook_tab(notebook3, "T1",   NULL, FALSE);
		create_notebook_tab(notebook3, "Tab2", NULL, FALSE);
		create_notebook_tab(notebook3, "T3b",  NULL, TRUE);
		create_notebook_tab(notebook3, "T4",   NULL, TRUE);

	notebook4 = gtk_notebook_new();
	gtk_notebook_popup_enable(GTK_NOTEBOOK(notebook4));
	gtk_notebook_set_scrollable(GTK_NOTEBOOK(notebook4), FALSE);
	gtk_notebook_set_tab_pos(GTK_NOTEBOOK(notebook4), GTK_POS_RIGHT);
		create_notebook_tab(notebook4, "T1",   NULL, FALSE);
		create_notebook_tab(notebook4, "Tab2", NULL, FALSE);
		create_notebook_tab(notebook4, "T3b",  NULL, TRUE);
		create_notebook_tab(notebook4, "T4",   NULL, TRUE);

	// layout
	add_to(GTK_BOX(root1), notebook1, TRUE, TRUE, 0, 0);
	add_to(GTK_BOX(root1), notebook2, TRUE, TRUE, 0, 0);
	add_to(GTK_BOX(root2), notebook3, TRUE, TRUE, 0, 0);
	add_to(GTK_BOX(root2), notebook4, TRUE, TRUE, 0, 0);
}

static void create_notebook_tab(GtkWidget *notebook, gchar *text, GtkWidget *content, gboolean close) { // ok

	GtkWidget *headbtn = BOXH, *btn;
	gtk_widget_set_hexpand(headbtn, FALSE);
	gtk_widget_set_vexpand(headbtn, FALSE);
	add_to(GTK_BOX(headbtn), gtk_label_new(text), TRUE, TRUE, 0, 0);

	// GTK_BUTTON
	if (close) {
		btn = gtk_button_new_from_icon_name("gtk-close");
		gtk_button_set_has_frame(GTK_BUTTON(btn), FALSE);
		gtk_widget_set_focus_on_click(btn, FALSE);
		add_to(GTK_BOX(headbtn), btn, FALSE, FALSE, 0, 0);
	}

	if (!content)
		content = BOXV;

	gtk_notebook_append_page(GTK_NOTEBOOK(notebook), content, headbtn);
	gtk_notebook_set_tab_reorderable(GTK_NOTEBOOK(notebook), content, TRUE);

	// gtk-scroll-tabs for GTK 4.x | so same GTK 2.24 3.x 4.x & Qt 5.15 6.x
	GtkEventController *event;
	event = gtk_event_controller_scroll_new(GTK_EVENT_CONTROLLER_SCROLL_BOTH_AXES | GTK_EVENT_CONTROLLER_SCROLL_DISCRETE);
	g_signal_connect(event, "scroll", G_CALLBACK(on_scrolltabs), notebook);
	gtk_widget_add_controller(gtk_widget_get_parent(headbtn), event);
}

static void create_treview(GtkWidget *root) { // ok

	GtkWidget *scrolled_window, *view;
	GtkCellRenderer *renderer;
	GtkTreeStore *store;
	GtkTreeIter iter;
	int idx = 0;

	G_GNUC_BEGIN_IGNORE_DEPRECATIONS // GTK 4.10+

	// data
	store = gtk_tree_store_new(11,
		G_TYPE_INT,
		G_TYPE_BOOLEAN,
		G_TYPE_BOOLEAN,
		G_TYPE_STRING,
		G_TYPE_DOUBLE,
		G_TYPE_DOUBLE,
		G_TYPE_STRING,
		G_TYPE_STRING,
		G_TYPE_STRING,
		G_TYPE_BOOLEAN,
		G_TYPE_BOOLEAN);
	gtk_tree_store_append(store, &iter, NULL);
	gtk_tree_store_set(store, &iter,
		0, 1,
		1, FALSE,
		2, FALSE,
		3, "Text 1.1",
		4, 0.0,
		5, 0.0,
		6, "Text 1.2",
		7, "gtk-open",
		8, "gtk-open",
		9, FALSE,
		10, FALSE,
		-1);
	gtk_tree_store_append(store, &iter, NULL);
	gtk_tree_store_set(store, &iter,
		0, 2,
		1, TRUE,
		2, TRUE,
		3, "Text 2.1",
		4, 10.0,
		5, 10.0,
		6, "Text 2.2",
		7, "gtk-save",
		8, "gtk-save",
		9, TRUE,
		10, TRUE,
		-1);
	gtk_tree_store_append(store, &iter, NULL);
	gtk_tree_store_set(store, &iter,
		0, 3,
		1, FALSE,
		2, FALSE,
		3, "Text 3.1",
		4, 20.0,
		5, 20.0,
		6, "Text 3.2",
		7, "gtk-save-as",
		8, "gtk-save-as",
		9, FALSE,
		10, FALSE,
		-1);
	gtk_tree_store_append(store, &iter, NULL);
	gtk_tree_store_set(store, &iter,
		0, 4,
		1, TRUE,
		2, TRUE,
		3, "Text 4.1",
		4, 30.0,
		5, 30.0,
		6, "Text 4.2",
		7, "gtk-refresh",
		8, "gtk-refresh",
		9, TRUE,
		10, TRUE,
		-1);
	gtk_tree_store_append(store, &iter, NULL);
	gtk_tree_store_set(store, &iter,
		0, 5,
		1, FALSE,
		2, FALSE,
		3, "Text 5.1",
		4, 40.0,
		5, 40.0,
		6, "Text 5.2",
		7, "gtk-cut",
		8, "gtk-cut",
		9, FALSE,
		10, FALSE,
		-1);
	gtk_tree_store_append(store, &iter, NULL);
	gtk_tree_store_set(store, &iter,
		0, 6,
		1, TRUE,
		2, TRUE,
		3, "Text 6.1",
		4, 50.0,
		5, 50.0,
		6, "Text 6.2",
		7, "gtk-help",
		8, "gtk-help",
		9, TRUE,
		10, TRUE,
		-1);
	gtk_tree_store_append(store, &iter, NULL);
	gtk_tree_store_set(store, &iter,
		0, 7,
		1, FALSE,
		2, FALSE,
		3, "Text 7.1",
		4, 60.0,
		5, 60.0,
		6, "Text 7.2",
		7, "gtk-open",
		8, "gtk-open",
		9, FALSE,
		10, FALSE,
		-1);
	gtk_tree_store_append(store, &iter, NULL);
	gtk_tree_store_set(store, &iter,
		0, 8,
		1, TRUE,
		2, TRUE,
		3, "Text 8.1",
		4, 70.0,
		5, 70.0,
		6, "Text 8.2",
		7, "gtk-save",
		8, "gtk-save",
		9, TRUE,
		10, TRUE,
		-1);
	gtk_tree_store_append(store, &iter, NULL);
	gtk_tree_store_set(store, &iter,
		0, 9,
		1, FALSE,
		2, FALSE,
		3, "Text 9.1",
		4, 80.0,
		5, 80.0,
		6, "Text 9.2",
		7, "gtk-save-as",
		8, "gtk-save-as",
		9, FALSE,
		10, FALSE,
		-1);
	gtk_tree_store_append(store, &iter, NULL);
	gtk_tree_store_set(store, &iter,
		0, 10,
		1, TRUE,
		2, TRUE,
		3, "Text 10.1",
		4, 90.0,
		5, 90.0,
		6, "Text 10.2",
		7, "gtk-refresh",
		8, "gtk-refresh",
		9, TRUE,
		10, TRUE,
		-1);
	gtk_tree_store_append(store, &iter, NULL);
	gtk_tree_store_set(store, &iter,
		0, 11,
		1, FALSE,
		2, FALSE,
		3, "Text 11.1",
		4, 100.0,
		5, 100.0,
		6, "Text 11.2",
		7, "gtk-cut",
		8, "gtk-cut",
		9, FALSE,
		10, FALSE,
		-1);

	// columns
	view = gtk_tree_view_new_with_model(GTK_TREE_MODEL(store));
	gtk_tree_view_set_reorderable(GTK_TREE_VIEW(view), FALSE); // rows
	gtk_tree_view_set_show_expanders(GTK_TREE_VIEW(view), FALSE);
	gtk_tree_view_set_headers_clickable(GTK_TREE_VIEW(view), TRUE);
	gtk_tree_sortable_set_sort_column_id(GTK_TREE_SORTABLE(store), 0, GTK_SORT_ASCENDING);
	g_object_unref(G_OBJECT(store));

	idx = 0;
	renderer = gtk_cell_renderer_text_new();
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view), idx, "i", renderer, "text", idx, NULL);
	gtk_tree_view_column_set_sort_column_id(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), idx);
	gtk_tree_view_column_set_reorderable(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), TRUE);
	gtk_tree_view_column_set_resizable(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), TRUE);
	g_object_set(renderer, "editable", TRUE, NULL);

	idx = 1;
	renderer = gtk_cell_renderer_toggle_new();
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view), idx, "c", renderer, "active", idx, NULL);
	gtk_tree_view_column_set_reorderable(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), TRUE);
	gtk_tree_view_column_set_resizable(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), TRUE);
	gtk_tree_view_column_set_min_width(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), 20);

	idx = 2;
	renderer = gtk_cell_renderer_toggle_new();
	gtk_cell_renderer_toggle_set_radio(GTK_CELL_RENDERER_TOGGLE(renderer), TRUE);
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view), idx, "r", renderer, "active", idx, NULL);
	gtk_tree_view_column_set_reorderable(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), TRUE);
	gtk_tree_view_column_set_resizable(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), TRUE);
	gtk_tree_view_column_set_min_width(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), 20);

	idx = 3;
	renderer = gtk_cell_renderer_text_new();
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view), idx, "Text", renderer, "text", idx, NULL);
	gtk_tree_view_column_set_sort_column_id(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), idx);
	gtk_tree_view_column_set_reorderable(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), TRUE);
	gtk_tree_view_column_set_resizable(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), TRUE);
	g_object_set(renderer, "editable", TRUE, NULL);

	idx = 4;
	renderer = gtk_cell_renderer_progress_new();
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view), idx, "Progress", renderer, "value", idx, NULL);
	gtk_tree_view_column_set_sort_column_id(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), idx);
	gtk_tree_view_column_set_reorderable(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), TRUE);
	gtk_tree_view_column_set_resizable(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), TRUE);

	idx = 5;
	renderer = gtk_cell_renderer_progress_new();
	gtk_cell_renderer_set_sensitive(renderer, FALSE);
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view), idx, "Progress", renderer, "value", idx, NULL);
	gtk_tree_view_column_set_sort_column_id(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), idx);
	gtk_tree_view_column_set_reorderable(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), TRUE);
	gtk_tree_view_column_set_resizable(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), TRUE);

	idx = 6;
	renderer = gtk_cell_renderer_text_new();
	gtk_cell_renderer_set_sensitive(renderer, FALSE);
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view), idx, "Text", renderer, "text", idx, NULL);
	gtk_tree_view_column_set_sort_column_id(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), idx);
	gtk_tree_view_column_set_reorderable(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), TRUE);
	gtk_tree_view_column_set_resizable(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), TRUE);

	idx = 7;
	renderer = gtk_cell_renderer_pixbuf_new();
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view), idx, "Icon", renderer, "icon-name", idx, NULL);
	gtk_tree_view_column_set_reorderable(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), TRUE);
	gtk_tree_view_column_set_resizable(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), TRUE);

	idx = 8;
	renderer = gtk_cell_renderer_pixbuf_new();
	gtk_cell_renderer_set_sensitive(renderer, FALSE);
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view), idx, "Icon", renderer, "icon-name", idx, NULL);
	gtk_tree_view_column_set_reorderable(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), TRUE);
	gtk_tree_view_column_set_resizable(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), TRUE);

	idx = 9;
	renderer = gtk_cell_renderer_toggle_new();
	gtk_cell_renderer_set_sensitive(renderer, FALSE);
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view), idx, "c", renderer, "active", idx, NULL);
	gtk_tree_view_column_set_reorderable(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), TRUE);
	gtk_tree_view_column_set_resizable(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), TRUE);
	gtk_tree_view_column_set_min_width(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), 20);

	idx = 10;
	renderer = gtk_cell_renderer_toggle_new();
	gtk_cell_renderer_set_sensitive(renderer, FALSE);
	gtk_cell_renderer_toggle_set_radio(GTK_CELL_RENDERER_TOGGLE(renderer), TRUE);
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view), idx, "r", renderer, "active", idx, NULL);
	gtk_tree_view_column_set_reorderable(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), TRUE);
	gtk_tree_view_column_set_resizable(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), TRUE);
	gtk_tree_view_column_set_min_width(gtk_tree_view_get_column(GTK_TREE_VIEW(view), idx), 20);

	// colors for lines: with gtk4-classic

	G_GNUC_END_IGNORE_DEPRECATIONS

	// scrolled window
	scrolled_window = gtk_scrolled_window_new();
	const gchar *config = g_getenv("GTK_OVERLAY_SCROLLING");
	if (config && (strcmp(config, "0") == 0))
		gtk_scrolled_window_set_overlay_scrolling(GTK_SCROLLED_WINDOW(scrolled_window), FALSE);

	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_ALWAYS, GTK_POLICY_ALWAYS);
	gtk_widget_set_size_request(scrolled_window, 200, 200); // The 200
	gtk_widget_set_size_request(view, 200, 200); // The 200

	gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolled_window), view);
	add_to(GTK_BOX(root), scrolled_window, FALSE, FALSE, 0, 0);
}

static void create_scales(GtkWidget *notebook, gchar *text, int position) {

	GtkWidget *hbox = BOXH;
	GtkWidget *vbox1 = BOXV, *vbox2 = BOXV, *vbox3 = BOXV, *hboxa = BOXH, *hboxb = BOXH;
	GtkWidget *scale1v, *scale2v, *scale3v, *scale4v, *scale5v, *scale6v, *scale7v, *scale8v, *scale9v, *scale10v, *scale11v, *scale12v;
	GtkWidget *scale1h, *scale2h, *scale3h, *scale4h, *scale5h, *scale6h, *scale7h, *scale8h, *scale9h, *scale10h, *scale11h, *scale12h;
	gdouble value = gtk_range_get_value(GTK_RANGE(scale1));

	gtk_widget_set_margin_top(hbox, 12);
	gtk_widget_set_margin_bottom(hbox, 12);
	gtk_widget_set_margin_start(hbox, 12);
	gtk_widget_set_margin_end(hbox, 12);

	// vertical scales
	scale1v = create_vertical_scale(value, FALSE, FALSE, position);
	if (gtk_widget_get_direction(window) == GTK_TEXT_DIR_RTL) // @todo highlight bottom instead of top, why?
		gtk_widget_add_css_class(scale1v, "top");

	scale2v = create_vertical_scale(value, FALSE, FALSE, position);
	update_marks(GTK_SCALE(scale2v), FALSE, GTK_POS_LEFT);
	if (gtk_widget_get_direction(window) == GTK_TEXT_DIR_RTL) // @todo highlight bottom instead of top, why?
		gtk_widget_add_css_class(scale2v, "top");

	scale3v = create_vertical_scale(value, FALSE, FALSE, position);
	update_marks(GTK_SCALE(scale3v), TRUE, GTK_POS_LEFT);
	if (gtk_widget_get_direction(window) == GTK_TEXT_DIR_RTL) // @todo highlight bottom instead of top, why?
		gtk_widget_add_css_class(scale3v, "top");

	scale4v = create_vertical_scale(value, TRUE, FALSE, position);
	if (gtk_widget_get_direction(window) == GTK_TEXT_DIR_RTL) // @todo highlight bottom instead of top, why?
		gtk_widget_add_css_class(scale4v, "top");

	scale5v = create_vertical_scale(value, TRUE, FALSE, position);
	update_marks(GTK_SCALE(scale5v), FALSE, GTK_POS_LEFT);
	if (gtk_widget_get_direction(window) == GTK_TEXT_DIR_RTL) // @todo highlight bottom instead of top, why?
		gtk_widget_add_css_class(scale5v, "top");

	scale6v = create_vertical_scale(value, TRUE, FALSE, position);
	update_marks(GTK_SCALE(scale6v), TRUE, GTK_POS_LEFT);
	if (gtk_widget_get_direction(window) == GTK_TEXT_DIR_RTL) // @todo highlight bottom instead of top, why?
		gtk_widget_add_css_class(scale6v, "top");

	scale7v = create_vertical_scale(value, FALSE, TRUE, position);

	scale8v = create_vertical_scale(value, FALSE, TRUE, position);
	update_marks(GTK_SCALE(scale8v), FALSE, GTK_POS_RIGHT);

	scale9v = create_vertical_scale(value, FALSE, TRUE, position);
	update_marks(GTK_SCALE(scale9v), TRUE, GTK_POS_RIGHT);

	scale10v = create_vertical_scale(value, TRUE, TRUE, position);

	scale11v = create_vertical_scale(value, TRUE, TRUE, position);
	update_marks(GTK_SCALE(scale11v), FALSE, GTK_POS_RIGHT);

	scale12v = create_vertical_scale(value, TRUE, TRUE, position);
	update_marks(GTK_SCALE(scale12v), TRUE, GTK_POS_RIGHT);

	// horizontal scales
	scale1h = create_horizontal_scale(value, FALSE, FALSE, position);

	scale2h = create_horizontal_scale(value, FALSE, FALSE, position);
	update_marks(GTK_SCALE(scale2h), FALSE, GTK_POS_TOP);

	scale3h = create_horizontal_scale(value, FALSE, FALSE, position);
	update_marks(GTK_SCALE(scale3h), TRUE, GTK_POS_TOP);

	scale4h = create_horizontal_scale(value, TRUE, FALSE, position);

	scale5h = create_horizontal_scale(value, TRUE, FALSE, position);
	update_marks(GTK_SCALE(scale5h), FALSE, GTK_POS_TOP);

	scale6h = create_horizontal_scale(value, TRUE, FALSE, position);
	update_marks(GTK_SCALE(scale6h), TRUE, GTK_POS_TOP);

	scale7h = create_horizontal_scale(value, FALSE, TRUE, position);

	scale8h = create_horizontal_scale(value, FALSE, TRUE, position);
	update_marks(GTK_SCALE(scale8h), FALSE, GTK_POS_BOTTOM);

	scale9h = create_horizontal_scale(value, FALSE, TRUE, position);
	update_marks(GTK_SCALE(scale9h), TRUE, GTK_POS_BOTTOM);

	scale10h = create_horizontal_scale(value, TRUE, TRUE, position);

	scale11h = create_horizontal_scale(value, TRUE, TRUE, position);
	update_marks(GTK_SCALE(scale11h), FALSE, GTK_POS_BOTTOM);

	scale12h = create_horizontal_scale(value, TRUE, TRUE, position);
	update_marks(GTK_SCALE(scale12h), TRUE, GTK_POS_BOTTOM);

	// layout
	add_to(GTK_BOX(hbox), vbox1, TRUE, TRUE, 5, 5);
		add_to(GTK_BOX(vbox1), scale1h, FALSE, FALSE, 5, 5);
		add_to(GTK_BOX(vbox1), scale2h, FALSE, FALSE, 5, 5);
		add_to(GTK_BOX(vbox1), scale3h, FALSE, FALSE, 5, 5);
		add_to(GTK_BOX(vbox1), scale4h, FALSE, FALSE, 5, 5);
		add_to(GTK_BOX(vbox1), scale5h, FALSE, FALSE, 5, 5);
		add_to(GTK_BOX(vbox1), scale6h, FALSE, FALSE, 5, 5);
	add_to(GTK_BOX(hbox), vbox2, TRUE, TRUE, 5, 5);
		add_to(GTK_BOX(vbox2), hboxa, TRUE, TRUE, 0, 0);
			add_to(GTK_BOX(hboxa), scale1v, FALSE, FALSE, 5, 5);
			add_to(GTK_BOX(hboxa), scale2v, FALSE, FALSE, 5, 5);
			add_to(GTK_BOX(hboxa), scale3v, FALSE, FALSE, 5, 5);
			add_to(GTK_BOX(hboxa), scale7v, FALSE, FALSE, 5, 5);
			add_to(GTK_BOX(hboxa), scale8v, FALSE, FALSE, 5, 5);
			add_to(GTK_BOX(hboxa), scale9v, FALSE, FALSE, 5, 5);
		add_to(GTK_BOX(vbox2), hboxb, TRUE, TRUE, 0, 0);
			add_to(GTK_BOX(hboxb), scale4v, FALSE, FALSE, 5, 5);
			add_to(GTK_BOX(hboxb), scale5v, FALSE, FALSE, 5, 5);
			add_to(GTK_BOX(hboxb), scale6v, FALSE, FALSE, 5, 5);
			add_to(GTK_BOX(hboxb), scale10v, FALSE, FALSE, 5, 5);
			add_to(GTK_BOX(hboxb), scale11v, FALSE, FALSE, 5, 5);
			add_to(GTK_BOX(hboxb), scale12v, FALSE, FALSE, 5, 5);
	add_to(GTK_BOX(hbox), vbox3, TRUE, TRUE, 5, 5);
		add_to(GTK_BOX(vbox3), scale7h, FALSE, FALSE, 5, 5);
		add_to(GTK_BOX(vbox3), scale8h, FALSE, FALSE, 5, 5);
		add_to(GTK_BOX(vbox3), scale9h, FALSE, FALSE, 5, 5);
		add_to(GTK_BOX(vbox3), scale10h, FALSE, FALSE, 5, 5);
		add_to(GTK_BOX(vbox3), scale11h, FALSE, FALSE, 5, 5);
		add_to(GTK_BOX(vbox3), scale12h, FALSE, FALSE, 5, 5);

	create_notebook_tab(notebook, text, hbox, FALSE);
}

static GtkWidget* create_horizontal_scale(gdouble value, gboolean draw, gboolean inverted, int position) { // ok

	GtkWidget *scale;

	scale = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 100, 1);
	gtk_range_set_value(GTK_RANGE(scale), value);
	gtk_scale_set_draw_value(GTK_SCALE(scale), draw);
	gtk_scale_set_value_pos(GTK_SCALE(scale), position);
	gtk_range_set_inverted(GTK_RANGE(scale), inverted);
	gtk_widget_set_size_request(scale, 186, -1); // The 186

	return scale;
}

static GtkWidget* create_vertical_scale(gdouble value, gboolean draw, gboolean inverted, int position) { // ok

	GtkWidget *scale;

	scale = gtk_scale_new_with_range(GTK_ORIENTATION_VERTICAL, 0, 100, 1);
	gtk_scale_set_value_pos(GTK_SCALE(scale), position);
	gtk_range_set_inverted(GTK_RANGE(scale), inverted);
	gtk_scale_set_draw_value(GTK_SCALE(scale), draw);
	gtk_range_set_value(GTK_RANGE(scale), value);
	gtk_widget_set_size_request(scale, -1, 100); // The 100

	return scale;
}


// traditional menu

static void create_traditional_menubar(GtkApplication *app, GMenu *root) {

	GMenu *menu, *submenu, *section, *base;
	GSimpleAction *action;
	GList *iterator;
	gboolean ok = FALSE;

	// options
	menu = g_menu_new();
	g_menu_append_submenu(root, _app("_Options"), G_MENU_MODEL(menu));

		create_menuitem(app, menu, _gtk("_Open"), AWF_ACCEL_OPEN, AWF_OPEN, "gtk-open", dialog_open);
		create_menuitem(app, menu, _app("Open recent file"), AWF_ACCEL_RECE, NULL, NULL, NULL);
		create_menuitem(app, menu, _gtk("_Save"), AWF_ACCEL_SAVE, AWF_SAVE, "gtk-save", dialog_save);
		create_menuitem(app, menu, _app("_Refresh"), AWF_ACCEL_REFR, AWF_REFR, "gtk-refresh", G_CALLBACK(on_sighup)); //(update_theme)
		create_menuitem(app, menu, _app("Calendar"), AWF_ACCEL_CALE, AWF_CALE, NULL, dialog_calendar);
		create_menuitem(app, menu, "GtkScales", AWF_ACCEL_SCAL, AWF_SCAL, NULL, dialog_scales);
		create_menuitem(app, menu, _gtk("_Properties"), AWF_ACCEL_PROP, AWF_PROP, "gtk-properties", dialog_message);
		create_menuitem(app, menu, _gtk("Page Set_up"), AWF_ACCEL_PRSE, AWF_PRSE, NULL, dialog_page_setup); // gtk-page-setup removed
		create_menuitem(app, menu, _gtk("_Print"), AWF_ACCEL_PRIN, AWF_PRIN, "gtk-print", dialog_print);

		submenu = g_menu_new();
		g_menu_append_submenu(menu, _app("More..."), G_MENU_MODEL(submenu));

			create_menuitem(app, submenu, _gtk("Cu_t"), AWF_ACCEL_MCUT, AWF_MCUT, "gtk-cut", NULL);
			create_menuitem(app, submenu, _gtk("_Copy"), AWF_ACCEL_MCOP, AWF_MCOP, "gtk-copy", NULL);
			create_menuitem(app, submenu, _gtk("_Paste"), AWF_ACCEL_MPAS, AWF_MPAS, "gtk-paste", NULL);

		section = g_menu_new();
		g_menu_append_section(menu, NULL, G_MENU_MODEL(section));

			action = g_simple_action_new_stateful("set-check-grp11", NULL, g_variant_new_boolean(FALSE));
			g_signal_connect(action, "activate", G_CALLBACK(activate_action), NULL);
			g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(action));
			create_menuitem_radio(section, g_strdup_printf("Check 1 %s", _app("(unchecked)")), TRUE, "app.set-check-grp11", FALSE);

			action = g_simple_action_new_stateful("set-check-grp12", NULL, g_variant_new_boolean(TRUE));
			g_signal_connect(action, "activate", G_CALLBACK(activate_action), NULL);
			g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(action));
			create_menuitem_radio(section, g_strdup_printf("Check 2 %s", _app("(checked)")), TRUE, "app.set-check-grp12", FALSE);

			create_menuitem_radio(section, g_strdup_printf("Check 3 %s", _app("(inconsistent)")), TRUE, NULL, FALSE); // @todo

			action = g_simple_action_new_stateful("set-check-grp21", NULL, g_variant_new_boolean(FALSE));
			g_simple_action_set_enabled(action, FALSE);
			g_signal_connect(action, "activate", G_CALLBACK(activate_action), NULL);
			g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(action));
			create_menuitem_radio(section, g_strdup_printf("Check 1 %s", _app("(unchecked)")), TRUE, "app.set-check-grp21", FALSE);

			action = g_simple_action_new_stateful("set-check-grp22", NULL, g_variant_new_boolean(TRUE));
			g_simple_action_set_enabled(action, FALSE);
			g_signal_connect(action, "activate", G_CALLBACK(activate_action), NULL);
			g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(action));
			create_menuitem_radio(section, g_strdup_printf("Check 2 %s", _app("(checked)")), TRUE, "app.set-check-grp22", FALSE);

			action = g_simple_action_new_stateful("set-check-grp23", NULL, g_variant_new_boolean(TRUE));
			g_simple_action_set_enabled(action, FALSE);
			create_menuitem_radio(section, g_strdup_printf("Check 3 %s", _app("(inconsistent)")), TRUE, "set-check-grp23", FALSE); // @todo

		section = g_menu_new();
		g_menu_append_section(menu, NULL, G_MENU_MODEL(section));

			action = g_simple_action_new_stateful("set-radio-grp1", G_VARIANT_TYPE_STRING, g_variant_new_string("checked"));
			g_signal_connect(action, "activate", G_CALLBACK(activate_action), NULL);
			g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(action));

			create_menuitem_radio(section, g_strdup_printf("Radio 1 %s", _app("(unchecked)")), TRUE, "app.set-radio-grp1::unchecked", FALSE);
			create_menuitem_radio(section, g_strdup_printf("Radio 2 %s", _app("(checked)")), TRUE, "app.set-radio-grp1::checked", FALSE);
			create_menuitem_radio(section, g_strdup_printf("Radio 3 %s", _app("(inconsistent)")), TRUE, NULL, FALSE); // @todo

			action = g_simple_action_new_stateful("set-radio-grp2", G_VARIANT_TYPE_STRING, g_variant_new_string("checked"));
			g_simple_action_set_enabled(action, FALSE);
			g_signal_connect(action, "activate", G_CALLBACK(activate_action), NULL);
			g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(action));

			create_menuitem_radio(section, g_strdup_printf("Radio 1 %s", _app("(unchecked)")), TRUE, "app.set-radio-grp2::unchecked", FALSE);
			create_menuitem_radio(section, g_strdup_printf("Radio 2 %s", _app("(checked)")), TRUE, "app.set-radio-grp2::checked", FALSE);
			create_menuitem_radio(section, g_strdup_printf("Radio 3 %s", _app("(inconsistent)")), TRUE, "disabled", FALSE); // @todo

		section = g_menu_new();
		g_menu_append_section(menu, NULL, G_MENU_MODEL(section));

			create_menuitem(app, section, _gtk("_Close"), AWF_ACCEL_CLOS, AWF_CLOS, "gtk-close", NULL);
			create_menuitem(app, section, _gtk("_Quit"), AWF_ACCEL_QUIT, AWF_QUIT, "gtk-quit", quit);

	// themes
	action = g_simple_action_new_stateful("set-theme", G_VARIANT_TYPE_STRING, g_variant_new_string(current_theme));
	g_signal_connect(action, "activate", G_CALLBACK(activate_action), NULL);
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(action));

	// system themes
	menu = g_menu_new();
	g_menu_append_submenu(root, _app("_System themes"), G_MENU_MODEL(menu));
	for (iterator = list_system_theme; iterator; iterator = iterator->next) {

		if (
			(strcmp((gchar*) iterator->data, "Mint-L") == 0) ||
			(strcmp((gchar*) iterator->data, "Mint-X") == 0) ||
			(strcmp((gchar*) iterator->data, "Mint-Y") == 0) ||
			(strcmp((gchar*) iterator->data, "Yaru") == 0) ||
			(strcmp((gchar*) iterator->data, "Sucharu") == 0)
		) {
			submenu = g_menu_new();
			g_menu_append_submenu(menu, iterator->data, G_MENU_MODEL(submenu));
			base = submenu;
			ok = TRUE;
		}
		else if (ok && (
			g_str_has_prefix((gchar*) iterator->data, "Mint-L") ||
			g_str_has_prefix((gchar*) iterator->data, "Mint-X") ||
			g_str_has_prefix((gchar*) iterator->data, "Mint-Y") ||
			g_str_has_prefix((gchar*) iterator->data, "Yaru") ||
			g_str_has_prefix((gchar*) iterator->data, "Sucharu")
		)) {
			base = submenu;
		}
		else {
			base = menu;
			ok = FALSE;
		}

		if (g_hash_table_lookup(hash_user_theme, iterator->data))
			create_menuitem_radio(base, iterator->data, FALSE, "disabled", FALSE); // @todo
		else
			create_menuitem_radio(base, iterator->data, FALSE, g_strdup_printf("app.set-theme::%s", (gchar*) iterator->data), TRUE);
	}

	if (!list_system_theme)
		g_menu_append(menu, _app("No themes found"), "disabled"); // @todo

	// user themes
	menu = g_menu_new();
	g_menu_append_submenu(root, _app("_User themes"), G_MENU_MODEL(menu));
	for (iterator = list_user_theme; iterator; iterator = iterator->next) {

		if (
			(strcmp((gchar*) iterator->data, "Mint-L") == 0) ||
			(strcmp((gchar*) iterator->data, "Mint-X") == 0) ||
			(strcmp((gchar*) iterator->data, "Mint-Y") == 0) ||
			(strcmp((gchar*) iterator->data, "Yaru") == 0) ||
			(strcmp((gchar*) iterator->data, "Sucharu") == 0)
		) {
			submenu = g_menu_new();
			g_menu_append_submenu(menu, iterator->data, G_MENU_MODEL(submenu));
			base = submenu;
			ok = TRUE;
		}
		else if (ok && (
			g_str_has_prefix((gchar*) iterator->data, "Mint-L") ||
			g_str_has_prefix((gchar*) iterator->data, "Mint-X") ||
			g_str_has_prefix((gchar*) iterator->data, "Mint-Y") ||
			g_str_has_prefix((gchar*) iterator->data, "Yaru") ||
			g_str_has_prefix((gchar*) iterator->data, "Sucharu")
		)) {
			base = submenu;
		}
		else {
			base = menu;
			ok = FALSE;
		}

		create_menuitem_radio(base, iterator->data, FALSE, g_strdup_printf("app.set-theme::%s", (gchar*) iterator->data), TRUE);
	}

	if (!list_user_theme)
		g_menu_append(menu, _app("No themes found"), "disabled"); // @todo

	// text direction
	action = g_simple_action_new_stateful("set-direction", G_VARIANT_TYPE_STRING, g_variant_new_string(current_direction ? "1" : "2"));
	g_signal_connect(action, "activate", G_CALLBACK(activate_action), NULL);
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(action));

	menu = g_menu_new();
	g_menu_append_submenu(root, _app("_Text direction"), G_MENU_MODEL(menu));
		create_menuitem_radio(menu, _app("Left to Right (LTR)"), FALSE, g_strdup_printf("app.set-direction::%d", GTK_TEXT_DIR_LTR), TRUE);
		create_menuitem_radio(menu, _app("Right to Left (RTL)"), FALSE, g_strdup_printf("app.set-direction::%d", GTK_TEXT_DIR_RTL), TRUE);

	// help
	menu = g_menu_new();
	g_menu_append_submenu(root, _app("_Help"), G_MENU_MODEL(menu));

		create_menuitem(app, menu, "GtkInspector", AWF_ACCEL_INSP, AWF_INSP, NULL, dialog_inspector);
		create_menuitem(app, menu, _gtk("_About"), AWF_ACCEL_ABOU, AWF_ABOU, "gtk-about", dialog_about);
}

static GMenuItem* create_menuitem_radio(GMenu *menu, gchar *text, gboolean free1, gchar *group, gboolean free2) {

	GMenuItem *menuitem = g_menu_item_new(text, group);
	g_menu_append_item(menu, menuitem);

	if (free1)
		g_free(text);
	if (free2)
		g_free(group);

	return menuitem;
}

static GMenuItem* create_menuitem(GtkApplication *app, GMenu *menu, gchar *text, gchar *acl, gchar *kmp, gchar *icon, GCallback function) {

	GMenuItem *menuitem;
	GSimpleAction *action;
	gchar *acckey[2] = { acl, NULL };
	gchar *appkey = "disabled";

	if (kmp && function) {
		appkey = g_strdup_printf("app.%s", kmp);
		action = g_simple_action_new(kmp, NULL);
		g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(action));
		gtk_application_set_accels_for_action(app, appkey, (const char**) acckey);
	}

	menuitem = g_menu_item_new(text, appkey);

	if (kmp && function)
		g_signal_connect(action, "activate", function, NULL);
	if (acl)
		g_menu_item_set_attribute(menuitem, "accel", "s", acl, NULL);
	if (icon)
		g_menu_item_set_attribute_value(menuitem, "icon", g_variant_new_string(icon)); // gtk4-classic, without, icon is hidden

	g_menu_append_item(menu, menuitem);
	if (kmp && function)
		g_free(appkey);

	return menuitem;
}

static void activate_action(GSimpleAction *action, GVariant *parameter, gpointer data) {

	GVariant *action_state;

	// radio
	if (parameter) {
		g_simple_action_set_state(action, parameter);
		if (strcmp((gchar*) g_action_get_name(G_ACTION(action)), "set-theme") == 0)
			update_theme((gchar*) g_variant_get_string(parameter, NULL));
		else if (strcmp((gchar*) g_action_get_name(G_ACTION(action)), "set-direction") == 0)
			update_text_direction((strcmp(g_variant_get_string(parameter, NULL), "1") == 0) ? 1 : 2);
	}
	// checkbox
	else {
		action_state = g_action_get_state(G_ACTION(action));
		if (g_variant_get_boolean(action_state) == FALSE)
			g_simple_action_set_state(action, g_variant_new_boolean(TRUE));
		else
			g_simple_action_set_state(action, g_variant_new_boolean(FALSE));
	}
}

static void accels_load(GtkApplication *app) { // todo

	gchar *old_path = g_build_filename(g_get_home_dir(), ".awf-gtk-accels", NULL);
	if (g_file_test(old_path, G_FILE_TEST_EXISTS)) {
		gchar *new_path = g_build_filename(g_get_home_dir(), ".awf-accels", NULL);
		g_rename(old_path, new_path);
		g_free(new_path);
	}
	g_free(old_path);

	// gtk-can-change-accels for GTK 4.x | so same GTK 2.24 3.x 4.x & Qt 5.15 6.x
	gchar *path = g_build_filename(g_get_home_dir(), ".awf-accels", NULL);

	if (g_file_test(path, G_FILE_TEST_IS_REGULAR)) {

		gsize len = 0;
		gchar *content = NULL;

		if (g_file_get_contents(path, &content, &len, NULL)) {

			GActionMap *map = G_ACTION_MAP(app);
			gchar **lines = g_strsplit(content, "\n", -1);

			for (int i = 0; lines[i] != NULL; i++) {

				//; (gtk_accel_path "<AWF>/Test/Print" "<Primary>p")
				gchar *l = g_strstrip(lines[i]);
				if (l[0] == '\0' || l[0] == ';')
					continue;

				gchar *a = strchr(l, '"');
				if (!a)
					continue;

				gchar *b = strchr(a + 1, '"');
				if (!b)
					continue;

				gchar *c = strchr(b + 1, '"');
				if (!c)
					continue;

				gchar *d = strchr(c + 1, '"');
				if (!d)
					continue;

				gchar *kmp = g_strndup(a + 1, b - a - 1);
				gchar *acl = g_strndup(c + 1, d - c - 1);

				// find action by name
				if (kmp[0] != '\0') {

					if (g_getenv("AWF_DEBUG"))
						g_printf("accels foundInFile: %s %s\n", kmp, acl);

					GAction *action = g_action_map_lookup_action(map, kmp);
					if (action != NULL) {

						gchar *full = g_strdup_printf("app.%s", kmp);
						const gchar *accels[2];
						accels[0] = acl;
						accels[1] = NULL;

						if (g_getenv("AWF_DEBUG"))
							g_printf("accels foundInMenu: %s %s %s\n", kmp, full, acl);

						gtk_application_set_accels_for_action(app, full, accels); // @todo does not update menubar
						g_free(full);
					}
				}

				g_free(kmp);
				g_free(acl);
			}

			g_strfreev(lines);
			g_free(content);
		}
	}

	g_free(path);
}

static void accels_change(GtkEventControllerKey *controller, guint keyval, guint keycode, GdkModifierType state) {
	// @todo not triggered when menu is open
}

static void accels_save() {
	// @todo
}


// dialogs

static void dialog_close(GtkWidget *widget, GtkDialog *dialog) { // ok

	if (GTK_IS_WINDOW(widget))
		gtk_window_destroy(GTK_WINDOW(widget));
	else if (GTK_IS_WINDOW(dialog))
		gtk_window_destroy(GTK_WINDOW(dialog));
}

static void dialog_open() { // ok

	#if GTK_CHECK_VERSION (4,10,0)
		GtkFileDialog *dialog = gtk_file_dialog_new();
		gtk_file_dialog_set_title(dialog, "GtkFileDialog:Open");
		gtk_file_dialog_open_multiple(dialog, GTK_WINDOW(window), NULL, NULL, NULL);
	#else
		GtkWidget *dialog = gtk_file_chooser_dialog_new(
			"GtkFileChooserDialog:Open",
			GTK_WINDOW(window),
			GTK_FILE_CHOOSER_ACTION_OPEN,
			_gtk("_Cancel"),
			GTK_RESPONSE_CANCEL,
			_gtk("_Open"),
			GTK_RESPONSE_ACCEPT,
			NULL);
		gtk_file_chooser_set_select_multiple(GTK_FILE_CHOOSER(dialog), TRUE);
		gtk_widget_set_visible(dialog, TRUE);
		g_signal_connect(dialog, "response", G_CALLBACK(dialog_close), NULL);
	#endif
}

static void dialog_save() { // ok

	#if GTK_CHECK_VERSION (4,10,0)
		GtkFileDialog *dialog = gtk_file_dialog_new();
		gtk_file_dialog_set_title(dialog, "GtkFileDialog:Save");
		gtk_file_dialog_save(dialog, GTK_WINDOW(window), NULL, NULL, NULL);
	#else
		GtkWidget *dialog = gtk_file_chooser_dialog_new(
			"GtkFileChooserDialog:Save",
			GTK_WINDOW(window),
			GTK_FILE_CHOOSER_ACTION_SAVE,
			_gtk("_Cancel"),
			GTK_RESPONSE_CANCEL,
			_gtk("_Save"),
			GTK_RESPONSE_ACCEPT,
			NULL);
		gtk_widget_set_visible(dialog, TRUE);
		g_signal_connect(dialog, "response", G_CALLBACK(dialog_close), NULL);
	#endif
}

static void dialog_message() { // todo

	GtkWidget *dialog = gtk_message_dialog_new(
		GTK_WINDOW(window),
		GTK_DIALOG_DESTROY_WITH_PARENT,
		GTK_MESSAGE_INFO,
		GTK_BUTTONS_YES_NO,
		"GtkMessageDialog");

	gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(dialog), _app("A widget factory is a theme preview application for GTK and Qt. It displays the various widget types in a single window allowing to see the visual effect of the applied theme."));
	gtk_window_set_title(GTK_WINDOW(dialog), "GtkMessageDialog");

	#if GTK_CHECK_VERSION (4,10,0)
		gtk_window_set_modal(GTK_WINDOW(dialog), TRUE);
		gtk_window_set_transient_for (GTK_WINDOW(dialog), GTK_WINDOW(window));
		gtk_widget_set_visible(dialog, TRUE);
	#else
		gtk_widget_set_visible(dialog, TRUE);
		g_signal_connect(dialog, "response", G_CALLBACK(dialog_close), NULL);
	#endif
}

static void dialog_page_setup() { // ok

	GtkWidget *dialog = gtk_page_setup_unix_dialog_new("GtkPageSetupUnixDialog", GTK_WINDOW(window));

	#if GTK_CHECK_VERSION (4,10,0)
		gtk_window_set_modal(GTK_WINDOW(dialog), TRUE);
		gtk_window_set_transient_for (GTK_WINDOW(dialog), GTK_WINDOW(window));
		gtk_widget_set_visible(dialog, TRUE);
		g_signal_connect(dialog, "response", G_CALLBACK(dialog_close), NULL);
	#else
		gtk_widget_set_visible(dialog, TRUE);
		g_signal_connect(dialog, "response", G_CALLBACK(dialog_close), NULL);
	#endif
}

static void dialog_print() { // ok

	GtkWidget *dialog = gtk_print_unix_dialog_new("GtkPrintUnixDialog", GTK_WINDOW(window));

	#if GTK_CHECK_VERSION (4,10,0)
		gtk_window_set_modal(GTK_WINDOW(dialog), TRUE);
		gtk_window_set_transient_for (GTK_WINDOW(dialog), GTK_WINDOW(window));
		gtk_widget_set_visible(dialog, TRUE);
	#else
		gtk_widget_set_visible(dialog, TRUE);
		g_signal_connect(dialog, "response", G_CALLBACK(dialog_close), NULL);
	#endif
}

static void dialog_about() { // ok

	gchar *t1, *t2, *t3, *t4;
	gtk_show_about_dialog(GTK_WINDOW(window),
		"version", VERSION,
		"comments", t1 = g_strdup_printf("%s\n\n%s\n%s\n\n%s\n%s",
			_app("A widget factory is a theme preview application for GTK and Qt. It displays the various widget types in a single window allowing to see the visual effect of the applied theme."),
			t2 = g_strdup_printf(_app("Remove %s file"), "~/.awf-accels"),
			_app("to reset keyboard shortcuts."),
			t3 = g_strdup_printf(_app("compiled with gtk %d.%d.%d and glib %d.%d.%d and pango %s"),
				GTK_MAJOR_VERSION, GTK_MINOR_VERSION, GTK_MICRO_VERSION,
				GLIB_MAJOR_VERSION, GLIB_MINOR_VERSION, GLIB_MICRO_VERSION,
				PANGO_VERSION_STRING),
			t4 = g_strdup_printf(_app(" started with gtk %d.%d.%d and glib %d.%d.%d and pango %s"),
				gtk_get_major_version(), gtk_get_minor_version(), gtk_get_micro_version(),
				glib_major_version, glib_minor_version, glib_micro_version,
				pango_version_string())
		),
		"website", "https://github.com/luigifab/awf-extended",
		"copyright", "Copyright © 2020-2026 Fabrice Creuzot (luigifab)\nCopyright © 2011-2017 Valère Monseur (valr)",
		"icon-name", GETTEXT_PACKAGE,
		"logo-icon-name", GETTEXT_PACKAGE,
		"license", "A widget factory is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.",
		"wrap-license", TRUE,
		NULL);

	g_free(t1);
	g_free(t2);
	g_free(t3);
	g_free(t4);
}

static void dialog_inspector() { // ok
	gtk_window_set_interactive_debugging(TRUE);
}

static void dialog_calendar() {

	GtkWidget *dialog, *infobar, *label, *calendar, *area, *btn, *vbox = BOXV, *hbox;

	#if GTK_CHECK_VERSION (4,10,0)
		dialog = gtk_window_new();
		gtk_widget_add_css_class(dialog, "dialog");
		gtk_window_set_title(GTK_WINDOW(dialog), "GtkWindow:Modal");
	#else
		dialog = gtk_dialog_new_with_buttons(NULL, GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, NULL, NULL);
		gtk_window_set_title(GTK_WINDOW(dialog), "GtkDialog");
	#endif

	// info bars and calendar
	G_GNUC_BEGIN_IGNORE_DEPRECATIONS // GTK 4.10+

	infobar = gtk_info_bar_new_with_buttons(_gtk("_OK"), GTK_RESPONSE_OK, NULL);
	gtk_info_bar_set_message_type(GTK_INFO_BAR(infobar), GTK_MESSAGE_INFO);
	label = gtk_label_new(_app("This is an info bar."));
	gtk_info_bar_add_child(GTK_INFO_BAR(infobar), label);
	add_to(GTK_BOX(vbox), infobar, FALSE, FALSE, 0, 0);

	infobar = gtk_info_bar_new_with_buttons(_app("Ok"), GTK_RESPONSE_OK, NULL);
	gtk_info_bar_set_message_type(GTK_INFO_BAR(infobar), GTK_MESSAGE_QUESTION);
	label = gtk_label_new(_app("This is a question bar."));
	gtk_info_bar_add_child(GTK_INFO_BAR(infobar), label);
	add_to(GTK_BOX(vbox), infobar, FALSE, FALSE, 0, 0);

	infobar = gtk_info_bar_new();
	gtk_info_bar_set_message_type(GTK_INFO_BAR(infobar), GTK_MESSAGE_WARNING);
	label = gtk_label_new(_app("This is a warning bar."));
	gtk_info_bar_add_child(GTK_INFO_BAR(infobar), label);
	add_to(GTK_BOX(vbox), infobar, FALSE, FALSE, 0, 0);

	infobar = gtk_info_bar_new();
	gtk_info_bar_set_message_type(GTK_INFO_BAR(infobar), GTK_MESSAGE_ERROR);
	label = gtk_label_new(_app("This is an error bar."));
	gtk_info_bar_add_child(GTK_INFO_BAR(infobar), label);
	add_to(GTK_BOX(vbox), infobar, FALSE, FALSE, 0, 0);

	calendar = gtk_calendar_new();
	gtk_calendar_set_show_day_names(GTK_CALENDAR(calendar), TRUE);
	gtk_calendar_set_show_week_numbers(GTK_CALENDAR(calendar), TRUE);
	add_to(GTK_BOX(vbox), calendar, FALSE, FALSE, 0, 0);

	G_GNUC_END_IGNORE_DEPRECATIONS

	// dialog
	#if GTK_CHECK_VERSION (4,10,0)
		// encore une idée de génie de GTK
		area = BOXV;
		gtk_widget_add_css_class(area, "dialog-vbox");
		gtk_window_set_child(GTK_WINDOW(dialog), area);
		add_to(GTK_BOX(area), vbox, TRUE, TRUE, 0, 5); // no padding

		// encore une idée de génie de GTK
		hbox = BOXH;
		gtk_widget_add_css_class(hbox, "dialog-action-area");
		btn = gtk_button_new_with_mnemonic(_gtk("_Cancel"));
		g_signal_connect(btn, "clicked", G_CALLBACK(dialog_close), dialog);
		gtk_box_append(GTK_BOX(hbox), btn);
		btn = gtk_button_new_with_mnemonic(_gtk("_OK"));
		g_signal_connect(btn, "clicked", G_CALLBACK(dialog_close), dialog);
		gtk_box_append(GTK_BOX(hbox), btn);
		add_to(GTK_BOX(area), hbox, TRUE, TRUE, 0, 0);
		gtk_widget_set_halign(hbox, GTK_ALIGN_END);
	#else
		area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
		add_to(GTK_BOX(area), vbox, TRUE, TRUE, 5, 5);
		gtk_dialog_add_button(GTK_DIALOG(dialog), _gtk("_Cancel"), 0);
		btn = gtk_dialog_add_button(GTK_DIALOG(dialog), _gtk("_OK"), 0);
	#endif

	const gchar *config = g_getenv("GTK_CSD");
	if (config && (strcmp(config, "1") == 0)) {
		gtk_window_set_decorated(GTK_WINDOW(dialog), TRUE);
		GtkWidget *headerbardialog = gtk_header_bar_new();
		gtk_header_bar_set_show_title_buttons(GTK_HEADER_BAR(headerbardialog), TRUE);
		gtk_window_set_titlebar(GTK_WINDOW(dialog), headerbardialog);
	}

	gtk_window_set_resizable(GTK_WINDOW(dialog), FALSE);
	gtk_widget_set_size_request(dialog, 350, -1);

	#if GTK_CHECK_VERSION (4,10,0)
		gtk_window_set_modal(GTK_WINDOW(dialog), TRUE);
		gtk_window_set_transient_for (GTK_WINDOW(dialog), GTK_WINDOW(window));
		gtk_widget_set_visible(dialog, TRUE);
	#else
		gtk_widget_set_visible(dialog, TRUE);
		g_signal_connect(dialog, "response", G_CALLBACK(dialog_close), NULL);
	#endif
	gtk_widget_grab_focus(GTK_WIDGET(btn));
}

static void dialog_scales() {

	GtkWidget *dialog, *notebook, *area, *btn, *hbox;

	#if GTK_CHECK_VERSION (4,10,0)
		dialog = gtk_window_new();
		gtk_widget_add_css_class(dialog, "dialog");
		gtk_window_set_title(GTK_WINDOW(dialog), "GtkWindow:Modal");

		notebook = gtk_notebook_new();
		gtk_notebook_set_scrollable(GTK_NOTEBOOK(notebook), FALSE);
		gtk_notebook_set_tab_pos(GTK_NOTEBOOK(notebook), GTK_POS_TOP);
			create_scales(notebook, "Top", GTK_POS_TOP);
			create_scales(notebook, "Right", GTK_POS_RIGHT);
			create_scales(notebook, "Bottom", GTK_POS_BOTTOM);
			create_scales(notebook, "Left", GTK_POS_LEFT);

		// encore une idée de génie de GTK
		area = BOXV;
		gtk_widget_add_css_class(area, "dialog-vbox");
		gtk_window_set_child(GTK_WINDOW(dialog), area);
		add_to(GTK_BOX(area), notebook, TRUE, TRUE, 0, 5); // no padding

		// encore une idée de génie de GTK
		hbox = BOXH;
		gtk_widget_add_css_class(hbox, "dialog-action-area");
		btn = gtk_button_new_with_mnemonic(_gtk("_Cancel"));
		g_signal_connect(btn, "clicked", G_CALLBACK(dialog_close), dialog);
		gtk_box_append(GTK_BOX(hbox), btn);
		btn = gtk_button_new_with_mnemonic(_gtk("_OK"));
		g_signal_connect(btn, "clicked", G_CALLBACK(dialog_close), dialog);
		gtk_box_append(GTK_BOX(hbox), btn);
		add_to(GTK_BOX(area), hbox, TRUE, TRUE, 0, 0);
		gtk_widget_set_halign(hbox, GTK_ALIGN_END);
	#else
		dialog = gtk_dialog_new_with_buttons(NULL, GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, NULL, NULL);
		gtk_window_set_title(GTK_WINDOW(dialog), "GtkDialog");

		notebook = gtk_notebook_new();
		gtk_notebook_set_scrollable(GTK_NOTEBOOK(notebook), FALSE);
		gtk_notebook_set_tab_pos(GTK_NOTEBOOK(notebook), GTK_POS_TOP);
			create_scales(notebook, "Top", GTK_POS_TOP);
			create_scales(notebook, "Right", GTK_POS_RIGHT);
			create_scales(notebook, "Bottom", GTK_POS_BOTTOM);
			create_scales(notebook, "Left", GTK_POS_LEFT);

		area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
		add_to(GTK_BOX(area), notebook, TRUE, TRUE, 5, 5);

		gtk_dialog_add_button(GTK_DIALOG(dialog), _gtk("_Cancel"), 0);
		gtk_dialog_add_button(GTK_DIALOG(dialog), _gtk("_OK"), 0);
	#endif

	const gchar *config = g_getenv("GTK_CSD");
	if (config && (strcmp(config, "1") == 0)) {
		gtk_window_set_decorated(GTK_WINDOW(dialog), TRUE);
		GtkWidget *headerbardialog = gtk_header_bar_new();
		gtk_header_bar_set_show_title_buttons(GTK_HEADER_BAR(headerbardialog), TRUE);
		gtk_window_set_titlebar(GTK_WINDOW(dialog), headerbardialog);
	}

	gtk_window_set_resizable(GTK_WINDOW(dialog), FALSE);
	#if GTK_CHECK_VERSION (4,10,0)
		gtk_window_set_modal(GTK_WINDOW(dialog), TRUE);
		gtk_window_set_transient_for (GTK_WINDOW(dialog), GTK_WINDOW(window));
		gtk_widget_set_visible(dialog, TRUE);
	#else
		gtk_widget_set_visible(dialog, TRUE);
		g_signal_connect(dialog, "response", G_CALLBACK(dialog_close), NULL);
	#endif
}


// gtk-scroll-tabs for GTK 4.x | so same GTK 2.24 3.x 4.x & Qt 5.15 6.x
// @see https://github.com/mate-desktop/mate-control-center/blob/master/capplets/common/capplet-util.c
// for on_scrolltabs source function is capplet_dialog_page_scroll_event_cb
//  of mate-appearance-properties from mate-control-center, GNU GPL 2.0+

static gboolean on_scrolltabs(GtkEventControllerScroll *event, double dx, double dy, GtkWidget *widget) {

	// gtk-scroll-tabs for GTK 4.x | so same GTK 2.24 3.x 4.x & Qt 5.15 6.x
	GtkWidget *child, *event_widget, *action_widget;
	GtkNotebook *notebook;

	while (!GTK_IS_NOTEBOOK(widget))
		widget = gtk_widget_get_parent(widget);

	notebook = GTK_NOTEBOOK(widget);

	child = gtk_notebook_get_nth_page(notebook, gtk_notebook_get_current_page(notebook));
	if (child == NULL)
		return FALSE;

	// ignore scroll events from the content of the page
	event_widget = gtk_event_controller_get_widget(GTK_EVENT_CONTROLLER(event));
	if (event_widget == NULL || event_widget == child || gtk_widget_is_ancestor(event_widget, child))
		return FALSE;

	// and also from the action widgets
	action_widget = gtk_notebook_get_action_widget(notebook, GTK_PACK_START);
	if (event_widget == action_widget || (action_widget != NULL && gtk_widget_is_ancestor(event_widget, action_widget)))
		return FALSE;
	action_widget = gtk_notebook_get_action_widget(notebook, GTK_PACK_END);
	if (event_widget == action_widget || (action_widget != NULL && gtk_widget_is_ancestor(event_widget, action_widget)))
		return FALSE;

	if ((dy > 0) || (dx > 0))
		gtk_notebook_next_page(notebook);
	else if ((dy < 0) || (dx < 0))
		gtk_notebook_prev_page(notebook);

	return TRUE;
}


// yolo