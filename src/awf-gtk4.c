/**
 * Forked  M/10/03/2020
 * Updated D/06/09/2026
 *
 * Copyright 2020-2027 | Fabrice Creuzot (luigifab) <code~luigifab~fr>
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
 *  Debian Testing 64                  (1536 MB) GTK 2.24/3.24/4.22 + GLIB 2.88 + Pango 1.58
 *  Fedora Rawhide 64                  (1536 MB) GTK 2.24/3.24/4.23 + GLIB 2.89 + Pango 1.57
 *  Ubuntu 26.04 Resolute Raccoon 64   (4096 MB) GTK 2.24/3.24/4.22 + GLIB 2.87 + Pango 1.56
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
 *  Windows XP SP3 MinGW/msys          (2048 MB) GTK 2.24 + GLIB 2.28 + Pango 1.29  &  GTK 3.6 + GLIB 2.34 + Pango 1.30
 */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#include <gdk/gdk.h>
#include <getopt.h>
#include <glib/gi18n.h>
#include <glib/gprintf.h>
#include <glib/gstdio.h>
#include <gtk/gtk.h>
#include <locale.h>
#if defined (G_OS_WIN32)
	#include <gdk/win32/gdkwin32.h>
#elif defined (G_OS_UNIX)
	#include <libnotify/notify.h>
#endif
#if defined (G_OS_UNIX) && GLIB_CHECK_VERSION (2,30,0)
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
static gboolean awf_debug = FALSE;
static gboolean awf_trace = FALSE;
static gboolean awf_csd = FALSE;
static GHashTable *hash_system_theme = NULL;
static GHashTable *hash_user_theme = NULL;
static GList *list_system_theme = NULL;
static GList *list_user_theme = NULL;
static GtkWidget *window = NULL, *toolbar = NULL, *toolbarentry = NULL, *toolbarend = NULL, *statusbar = NULL;
static GtkWidget *headbarCloseLeft = NULL, *headbarCloseRight = NULL, *button15 = NULL, *button16 = NULL;
static GtkWidget *progress1 = NULL, *progress2 = NULL, *progress3 = NULL, *progress4 = NULL, *progress8 = NULL, *progress9 = NULL;
static GtkWidget *scale1 = NULL, *scale2 = NULL, *scale3 = NULL, *scale4 = NULL, *scale5 = NULL, *scale6 = NULL;
static GtkWidget *levelbar1 = NULL, *levelbar2 = NULL, *levelbar3 = NULL, *levelbar4 = NULL;
static GtkWidget *levelbar5 = NULL, *levelbar6 = NULL, *levelbar7 = NULL, *levelbar8 = NULL;
static GtkWidget *notebook1 = NULL, *notebook2 = NULL, *notebook3 = NULL, *notebook4 = NULL;
static int current_direction        = 0; // GTK_TEXT_DIR_NONE
static gchar *current_theme         = NULL;
static gchar *opt_theme             = NULL;
static gchar *opt_screenshot        = NULL;
static gboolean allow_update_values = TRUE;
static gboolean must_save_accels    = FALSE;

// global functions
static void awf_load_theme(GHashTable* hashtable, gchar *directory);
static inline int awf_compare_theme(gconstpointer a, gconstpointer b);
static void notify_updated_gtktheme(GSettings *settings, gchar *key);
static void update_text_direction(int direction);
static void update_theme(gchar *newTheme);
static void update_statusbar(gchar *message);
static void update_values(GtkRange *range);
static void update_widgets();
static void update_marks(GtkScale *scale, gboolean value, int position);
static void clear_entry(GtkEntry *entry);
static void display_notification();
static void find_and_update_labels(GtkWidget *widget);
static gboolean find_and_check_menuradio(GMenuModel *model, gchar *search);
static gboolean on_sighup(void *data);
static gboolean take_screenshot();
static void create_window(gpointer app);
static void create_widgets(GtkWidget *root);
static void add_to(GtkWidget *root, GtkWidget *widget, gboolean expand, gboolean fill, guint padding, guint spacing);
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
static void create_treeview(GtkWidget *root);
static void create_scales(GtkWidget *notebook, gchar *text, int position);
static GtkWidget* create_horizontal_scale(gdouble value, gboolean draw, gboolean inverted, int position);
static GtkWidget* create_vertical_scale(gdouble value, gboolean draw, gboolean inverted, int position);
static void create_traditional_menubar(GtkApplication *app, GMenu *root);
static void create_menuitem_radio(GMenu *menu, gchar *text, gboolean free1, gchar *group, gboolean free2);
static void create_menuitem(GtkApplication *app, GMenu *menu, gchar *text, gboolean dsb, gchar *acl, gchar *kmp, gchar *icon, GCallback function);
static void activate_action(GSimpleAction *action, GVariant *parameter, gpointer data);
static void accels_load(GtkApplication *app);
static gboolean accels_change(GtkEventControllerKey *controller, guint keyval, guint keycode, GdkModifierType state);
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

	awf_debug = g_getenv("AWF_DEBUG") != NULL;
	awf_trace = g_getenv("AWF_TRACE") != NULL;

	const gchar *config = g_getenv("GTK_CSD");
	if (config && (strcmp(config, "1") == 0))
		awf_csd = TRUE;

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m main()\n");

	current_theme = g_strdup("auto");
	opt_theme     = g_strdup("auto");

	int opt = 0, status = 0;
	hash_system_theme = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
	hash_user_theme   = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
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
	#if defined (G_OS_WIN32)
		directory = g_build_filename("share", "locale", NULL);
		bindtextdomain(GETTEXT_PACKAGE, directory);
		g_free(directory);
	#endif
	bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
	textdomain(GETTEXT_PACKAGE);

	// init
	static struct option options[] = {
		{"help",        no_argument, NULL, 'x'},
		{"version",     no_argument, NULL, 'v'},
		{"list",        no_argument, NULL, 'l'},
		{"theme",       required_argument, NULL, 't'},
		{"screenshot",  required_argument, NULL, 's'},
		{"ltr",         no_argument, NULL, 'y'},
		{"rtl",         no_argument, NULL, 'z'},
		{NULL, 0, NULL, 0}
	};

	gchar *cVersion, *t1, *t2, *t3, *t4;
	while ((opt = getopt_long(argc, argv, "hvlt:s:xyz", options, NULL)) != -1) {
		switch (opt) {
			// --version -v
			case 'v':
				g_printf("%s\n", VERSION);
				return status;
			// --list -l
			case 'l':
				for (iterator = list_system_theme; iterator; iterator = iterator->next)
					g_printf("%s\n", (gchar*) iterator->data);
				for (iterator = list_user_theme; iterator; iterator = iterator->next)
					g_printf("%s\n", (gchar*) iterator->data);
				return status;
			// --theme <theme> -t <theme>
			case 't':
				if (g_hash_table_lookup(hash_system_theme, optarg) || g_hash_table_lookup(hash_user_theme, optarg)) {
					g_free(opt_theme);
					opt_theme = g_strdup(optarg);
				}
				break;
			// --screenshot <filename> -s <filename>
			case 's':
				opt_screenshot = g_strdup(optarg);
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
			// --help/x supported by GTK 4.x
			case 'x':
			case 'h':
			default:
				if (opt == 'x')
					break;
				#ifdef __STDC_VERSION__
					if      (__STDC_VERSION__ >= 202311L) cVersion = "C23";
					else if (__STDC_VERSION__ >= 201710L) cVersion = "C17";
					else if (__STDC_VERSION__ >= 201112L) cVersion = "C11";
					else if (__STDC_VERSION__ >= 199901L) cVersion = "C99";
					else if (__STDC_VERSION__ >= 199409L) cVersion = "C95";
					else                                  cVersion = "C (unknown)";
				#else
					cVersion = "C89/C90";
				#endif
				g_printf("%s\n\n  %s %s\n  %s %s\n  %s %s\n  %s %s\n  %s %s\n  %s %s\n\n%s\n%s\n",
					t1 = g_strdup_printf(_app("A widget factory - GTK %d.%d"), GTK_MAJOR_VERSION, GTK_MINOR_VERSION),
					"-v            ", _app("Show version number."),
					"-l            ", _app("List available themes."),
					"-t <theme>    ", _app("Run with the specified theme."),
					"-s <filename> ", t2 = g_strdup_printf(_app("Run and save a screenshot on %s (PNG)."), "SIGHUP"),
					"--ltr         ", _app("Run with text from left to right (Left-To-Right)."),
					"--rtl         ", _app("Run with text from right to left (Right-To-Left)."),
					t3 = g_strdup_printf(_app("compiled in %s with gtk %d.%d.%d and glib %d.%d.%d and pango %s"),
						cVersion,
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
	#if defined (G_OS_WIN32)
		g_setenv("GSETTINGS_SCHEMA_DIR", ".", TRUE);
	#endif

	GtkApplication *app = gtk_application_new("org.gtk.awf", G_APPLICATION_NON_UNIQUE);
	g_signal_connect(app, "activate", G_CALLBACK(create_window), NULL);

	// --version -v
	g_application_add_main_option(G_APPLICATION(app), "version", 'v', G_OPTION_FLAG_IN_MAIN, G_OPTION_ARG_NONE,
		_app("Show version number."), NULL);

	// --list -l
	g_application_add_main_option(G_APPLICATION(app), "list", 'l', G_OPTION_FLAG_IN_MAIN, G_OPTION_ARG_NONE,
		_app("List available themes."), NULL);

	// --theme <theme> -t <theme>
	g_application_add_main_option(G_APPLICATION(app), "theme", 't', G_OPTION_FLAG_IN_MAIN, G_OPTION_ARG_STRING,
		_app("Run with the specified theme."), "<theme>");

	// --screenshot <filename> -s <filename>
	gchar *text = g_strdup_printf(_app("Run and save a screenshot on %s (PNG)."), "SIGHUP");
	g_application_add_main_option(G_APPLICATION(app), "screenshot", 's', G_OPTION_FLAG_IN_MAIN, G_OPTION_ARG_STRING,
		text, "<filename>");
	g_free(text);

	// --ltr
	g_application_add_main_option(G_APPLICATION(app), "ltr", 'y', G_OPTION_FLAG_IN_MAIN, G_OPTION_ARG_NONE,
		_app("Run with text from left to right (Left-To-Right)."), NULL);

	// --rtl
	g_application_add_main_option(G_APPLICATION(app), "rtl", 'z', G_OPTION_FLAG_IN_MAIN, G_OPTION_ARG_NONE,
		_app("Run with text from right to left (Right-To-Left)."), NULL);

	g_application_register(G_APPLICATION(app), NULL, NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}

static void quit() {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m quit()\n");

	g_list_free(list_system_theme);
	g_list_free(list_user_theme);
	list_system_theme = NULL;
	list_user_theme   = NULL;

	g_hash_table_destroy(hash_system_theme);
	g_hash_table_destroy(hash_user_theme);
	hash_system_theme = NULL;
	hash_user_theme   = NULL;

	accels_save();
	g_application_quit(g_application_get_default());
}

static void awf_load_theme(GHashTable* hashtable, gchar *directory) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m awf_load_theme(%s)\n", directory);

	if (g_file_test(directory, G_FILE_TEST_IS_DIR)) {

		if (awf_debug)
			g_printf("\033[33m[debug]\033[00m themes_dir: %s\n", directory);

		GDir *dir = g_dir_open(directory, 0, NULL);
		if (dir) {
			const gchar *theme;
			while ((theme = g_dir_read_name(dir)) != NULL) {
				gchar *themePath = g_build_filename(directory, theme, GTK_DIRNAME, NULL);
				if (g_file_test(themePath, G_FILE_TEST_IS_DIR))
					g_hash_table_replace(hashtable, g_strdup(theme), g_strdup(theme));
				g_free(themePath);
			}
			g_dir_close(dir);
		}
	}
}

static inline int awf_compare_theme(gconstpointer a, gconstpointer b) {
	return g_ascii_strcasecmp((gchar*) a, (gchar*) b); //g_strcmp0((gchar*) a, (gchar*) b);
}

static void notify_updated_gtktheme(GSettings *settings, gchar *key) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m notify_updated_gtktheme(%s)\n", key);

	if (g_strcmp0("gtk-theme", key) == 0) {

		gchar *newTheme = g_settings_get_string(settings, key);
		if (awf_debug)
			g_printf("\033[33m[debug]\033[00m SIGNAL_theme_update: %s\n", newTheme);

		find_and_check_menuradio(gtk_application_get_menubar(GTK_APPLICATION(g_application_get_default())), newTheme);
		g_free(newTheme);
	}
	else if (headbarCloseLeft && headbarCloseRight) {

		gboolean closeLeft = FALSE, closeRight = FALSE; // minimize, maximize, close, icon, menu
		gchar *tokens = g_settings_get_string(settings, key);

		if (tokens) {
			if (g_str_has_prefix(tokens, "icon") || g_str_has_prefix(tokens, "menu"))
				closeLeft = TRUE;
			else if (g_str_has_suffix(tokens, "icon") || g_str_has_suffix(tokens, "menu"))
				closeRight = TRUE;
			if (awf_debug)
				g_printf("\033[33m[debug]\033[00m headerbar_tokens: %s %d %d\n", tokens, closeLeft, closeRight);
			g_free(tokens);
		}

		gtk_widget_set_visible(headbarCloseLeft, closeLeft);
		gtk_widget_set_visible(headbarCloseRight, closeRight);
	}
}

static void update_text_direction(int direction) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m update_text_direction()\n");

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

static void update_theme(gchar *newTheme) {

	if (!newTheme)
		return;

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m update_theme(%s)\n", newTheme);
	if (awf_debug)
		g_printf("\033[33m[debug]\033[00m update_theme_before: %s » %s\n", current_theme, newTheme);

	if (strcmp(newTheme, "refresh") == 0) {

		g_object_set(gtk_settings_get_default(), "gtk-theme-name", "Default", NULL);
		g_usleep(G_USEC_PER_SEC / 2);
		g_object_set(gtk_settings_get_default(), "gtk-theme-name", current_theme, NULL);
		gtk_window_set_default_size(GTK_WINDOW(window), 50, 50);

		if (opt_screenshot) {
			if (take_screenshot()) {
				gchar *text = g_strdup_printf(_app("Theme %s reloaded, then screenshot saved (%s)."), current_theme, opt_screenshot);
				update_statusbar(text);
				g_free(text);
			}
			else {
				gchar *text = g_strdup_printf(_app("Theme %s reloaded (error saving screenshot)."), current_theme);
				update_statusbar(text);
				g_free(text);
			}
		}
		else {
			gchar *text = g_strdup_printf(_app("Theme %s reloaded."), current_theme);
			update_statusbar(text);
			g_free(text);
		}

		if (awf_debug)
			g_printf("\033[33m[debug]\033[00m update_theme_after1: %s\n", current_theme);
	}
	else if (strcmp(newTheme, "auto") == 0) {

		g_free(current_theme);
		g_object_get(gtk_settings_get_default(), "gtk-theme-name", &current_theme, NULL);
		gtk_window_set_default_size(GTK_WINDOW(window), 50, 50);

		if (awf_debug)
			g_printf("\033[33m[debug]\033[00m update_theme_after2: %s\n", current_theme);
	}
	else if (strcmp(newTheme, current_theme) != 0) {

		g_free(current_theme);
		g_object_set(gtk_settings_get_default(), "gtk-theme-name", newTheme, NULL); // @todo? useless for notify_updated_gtktheme
		g_object_get(gtk_settings_get_default(), "gtk-theme-name", &current_theme, NULL);

		while (g_main_context_pending(NULL))
			g_main_context_iteration(NULL, FALSE);
		gtk_window_set_default_size(GTK_WINDOW(window), 50, 50);

		gchar *text = g_strdup_printf(_app("Theme %s loaded."), current_theme);
		update_statusbar(text);
		g_free(text);

		if (awf_debug)
			g_printf("\033[33m[debug]\033[00m update_theme_after3: %s\n", current_theme);
	}
}

static void update_statusbar(gchar *message) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m update_statusbar(%s)\n", message);

	if (window && statusbar) {

		GDateTime *now = g_date_time_new_now_local();
		gchar *buffer  = g_date_time_format(now, "%H:%M:%S");
		g_date_time_unref(now);

		gchar *text = g_strdup_printf("%s - %s", buffer, message);
		G_GNUC_BEGIN_IGNORE_DEPRECATIONS // GTK 4.10+
		guint ctid = gtk_statusbar_get_context_id(GTK_STATUSBAR(statusbar), "gné");
		gtk_statusbar_remove_all(GTK_STATUSBAR(statusbar), ctid);
		gtk_statusbar_push(GTK_STATUSBAR(statusbar), ctid, text);
		G_GNUC_END_IGNORE_DEPRECATIONS
		g_free(text);
		g_free(buffer);

		gtk_widget_remove_css_class(statusbar, "flash");
		gtk_widget_queue_draw(statusbar);
		while (g_main_context_pending(NULL))
			g_main_context_iteration(NULL, FALSE);
		gtk_widget_add_css_class(statusbar, "flash");
	}
}

static void update_values(GtkRange *range) {

	if (allow_update_values) {

		allow_update_values = FALSE;
		double value = gtk_range_get_value(range);
		//if (awf_trace)
		//	g_printf("\033[36m[trace]\033[00m update_values(%f)*\n", value);

		// range(0..1)
		gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress1), value / 100.0);
		gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress2), value / 100.0);
		gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress3), value / 100.0);
		gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress4), value / 100.0);
		gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress8), value / 100.0);
		gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress9), value / 100.0);

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
		gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(progress8), value > 50);
		gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(progress9), value > 50);

		allow_update_values = TRUE;
	}
}

static void update_widgets() {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m update_widgets()\n");

	// function called when user click on [+] toolbar button
	// when toggle = true, the [+] toolbar button is NOT checked
	gboolean toggle = gtk_notebook_get_scrollable(GTK_NOTEBOOK(notebook1));

	// via add_progressbar_and_entrybar
	// show progressbar in toolbar and statusbar when [+] toolbar button is NOT checked
	if (toggle) {
		gtk_widget_set_visible(progress8, FALSE);
		gtk_widget_set_visible(progress9, FALSE);
		gtk_widget_set_visible(toolbarentry, FALSE);
	}
	else {
		gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress8), 0.0);
		gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress9), 0.0);
		gtk_widget_set_visible(progress8, TRUE);
		gtk_widget_set_visible(progress9, TRUE);
		gtk_widget_set_visible(toolbarentry, TRUE);
	}

	// enabled or not
	gtk_widget_set_sensitive(scale2, toggle);
	gtk_widget_set_sensitive(scale4, toggle);
	gtk_widget_set_sensitive(scale6, toggle);
	gtk_widget_set_sensitive(progress2, toggle);
	gtk_widget_set_sensitive(progress4, toggle);
	gtk_widget_set_sensitive(levelbar2, toggle);
	gtk_widget_set_sensitive(levelbar4, toggle);
	gtk_widget_set_sensitive(levelbar6, toggle);
	gtk_widget_set_sensitive(levelbar8, toggle);

	// text or not
	gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(progress1), !toggle);
	gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(progress2), !toggle);
	gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(progress3), !toggle);
	gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(progress4), !toggle);
	gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(progress8), FALSE);
	gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(progress9), FALSE);

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

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m update_marks(%d)\n", position);

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

static void clear_entry(GtkEntry *entry) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m clear_entry()\n");

	gtk_editable_set_text(GTK_EDITABLE(entry), "");
}

static void display_notification() {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m display_notification()\n");

	#if defined (G_OS_UNIX)
		if (notify_init(GETTEXT_PACKAGE)) {
			// Ubuntu 11.04 with libnotify-dev 0.5.x, so you must use libnotify-dev 0.7.x from Ubuntu 11.10
			NotifyNotification *notif = notify_notification_new(GETTEXT_PACKAGE, _app("A widget factory is a theme preview application for GTK and Qt. It displays the various widget types in a single window allowing to see the visual effect of the applied theme."), "dialog-information");
			notify_notification_add_action(notif, "nothing", _gtk("Close"), NOTIFY_ACTION_CALLBACK(notify_uninit), NULL, NULL);
			notify_notification_add_action(notif, "close", _gtk("Close"), NOTIFY_ACTION_CALLBACK(notify_uninit), NULL, NULL);
			notify_notification_set_timeout(notif, 50000);
			notify_notification_show(notif, NULL);
			g_object_unref(G_OBJECT(notif));
			notify_uninit();
		}
	#endif
}

static void find_and_update_labels(GtkWidget *widget) { // whynot

	if (GTK_IS_LABEL(widget)) {
		gtk_label_set_ellipsize(GTK_LABEL(widget), PANGO_ELLIPSIZE_END);
	}
	else if (GTK_IS_WIDGET(widget)) {
		GtkWidget *child = gtk_widget_get_first_child(widget);
		while (child) {
			find_and_update_labels(child);
			child = gtk_widget_get_next_sibling(child);
		}
	}
}

static gboolean find_and_check_menuradio(GMenuModel *model, gchar *search) { // whynot

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m find_and_check_menuradio(%s)\n", search);

	int n = g_menu_model_get_n_items(model);
	const gchar *value = NULL;
	GVariant *info;

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
			// check menuitem by label/target
			info = g_menu_model_get_item_attribute_value(model, idx, "target", NULL); // target or label = theme_name
			if (info) {
				value = g_variant_get_string(info, NULL);
				g_variant_unref(info);
				if (value && (g_strcmp0(value, search) == 0)) {
					// menuitem found by label/target
					// check menuitem by action
					info = g_menu_model_get_item_attribute_value(model, idx, "action", NULL); // action = disabled or set-theme
					if (info) {
						value = g_variant_get_string(info, NULL);
						g_variant_unref(info);
						if (value && (g_strcmp0(value, "disabled") != 0)) {
							// menuitem found by label/target + action not disabled
							g_action_group_activate_action(G_ACTION_GROUP(g_application_get_default()), "set-theme", g_variant_new_string(search)); // set state checked and activate action
							return TRUE;
						}
					}
				}
			}
		}
	}

	return FALSE;
}

static gboolean on_sighup(void *data) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m on_sighup()\n");

	update_theme("refresh");

	#if defined (G_SOURCE_CONTINUE)
		return G_SOURCE_CONTINUE;
	#else
		return TRUE; // glib < 2.32
	#endif
}

static gboolean take_screenshot() { // without window borders

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m take_screenshot()\n");

	gboolean result = FALSE;
	GdkPaintable *paintable = gtk_widget_paintable_new(window);
	int width = gdk_paintable_get_intrinsic_width(paintable), height = gdk_paintable_get_intrinsic_height(paintable);

	GtkSnapshot *snapshot = gtk_snapshot_new();
	G_GNUC_BEGIN_IGNORE_DEPRECATIONS // GTK 4.10+
	gtk_snapshot_render_background(snapshot, gtk_widget_get_style_context(GTK_WIDGET(window)), 0, 0, (double)width, (double)height);
	G_GNUC_END_IGNORE_DEPRECATIONS
	GTK_WIDGET_GET_CLASS(GTK_WIDGET(window))->snapshot(GTK_WIDGET(window), snapshot);
	GskRenderNode *node = gtk_snapshot_free_to_node(snapshot);

	if (node) {
		GskRenderer *renderer = gtk_native_get_renderer(GTK_NATIVE(window));
		graphene_rect_t bounds = GRAPHENE_RECT_INIT(0, 0, (float)width, (float)height);
		GdkTexture *texture = gsk_renderer_render_texture(renderer, node, &bounds);
		result = gdk_texture_save_to_png(texture, opt_screenshot);
		g_object_unref(texture);
		gsk_render_node_unref(node);
	}
	else {
		g_printf("\033[1;31m[error]\033[00m screenshot error: width=%d height=%d image=%p\n", width, height, node);
	}

	g_object_unref(paintable);

	return result;
}


// layout and widgets

static void create_window(gpointer app) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m create_window()\n");

	if (window) {
		gtk_window_present(GTK_WINDOW(window));
		return;
	}

	GtkWidget *vboxWindow, *widgets;
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
	if (strcmp(current_theme, opt_theme) != 0)
		update_theme(opt_theme);
	else
		update_theme(current_theme);

	if (current_direction == 0)
		current_direction = (gtk_widget_get_default_direction() == GTK_TEXT_DIR_LTR) ? 1 : 2;

	// layout
	vboxWindow = BOXV;
	gtk_window_set_child(GTK_WINDOW(window), vboxWindow);

		GMenu *gmm = g_menu_new();
		create_traditional_menubar(app, gmm);
		gtk_application_set_menubar(app, G_MENU_MODEL(gmm));
		gtk_application_window_set_show_menubar(GTK_APPLICATION_WINDOW(window), TRUE);

		if (awf_csd) {
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
			if (awf_debug)
				g_printf("\033[33m[debug]\033[00m headerbar_tokens: %s %d %d\n", tokens, closeLeft, closeRight);
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

		g_object_unref(gmm);

		toolbar = BOXH;
		gtk_widget_add_css_class(toolbar, "primary-toolbar");
		create_toolbar(toolbar);
		//add_to(vboxWindow, toolbar, FALSE, FALSE, 0, 0);
		gtk_box_append(GTK_BOX(vboxWindow), toolbar);

		widgets = BOXV;
		add_to(vboxWindow, widgets, TRUE, TRUE, 0, 0);
			create_widgets(widgets);

		G_GNUC_BEGIN_IGNORE_DEPRECATIONS // GTK 4.10+
		statusbar = gtk_statusbar_new();
		GtkCssProvider *provider = gtk_css_provider_new();
		gtk_css_provider_load_from_data(provider,
			"@keyframes statusbarflash {"
			"  0%   { background-color: yellow; }"
			"  100% { background-color: transparent; }"
			"}"
			"#AwfMainWindow statusbar.flash {"
			"  animation: statusbarflash 1s ease-out forwards;"
			"}"
		, -1);
		gtk_style_context_add_provider_for_display(gdk_display_get_default(), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_FALLBACK);
		g_object_unref(provider);
		G_GNUC_END_IGNORE_DEPRECATIONS
		// via add_progressbar_and_entrybar
		// for the progressbar of the statusbar, before adding statusbar
		gtk_widget_set_halign(gtk_widget_get_first_child(statusbar), GTK_ALIGN_FILL); // statusbar > box
		gtk_widget_set_hexpand(gtk_widget_get_first_child(statusbar), TRUE);          // statusbar > box
		gtk_widget_set_hexpand(gtk_widget_get_first_child(gtk_widget_get_first_child(statusbar)), TRUE); // statusbar > box > label
		add_to(vboxWindow, statusbar, FALSE, FALSE, 0, 0);

		text = g_strdup_printf(_app("Theme %s loaded."), current_theme);
		update_statusbar(text);
		g_free(text);

	// go go go
	update_text_direction(current_direction);
	g_signal_connect(window, "destroy", G_CALLBACK(quit), NULL);

	#if defined (G_OS_UNIX) && GLIB_CHECK_VERSION (2,30,0)
		g_unix_signal_add(SIGHUP, on_sighup, NULL);
	#endif

	#if defined (G_OS_UNIX) && GLIB_CHECK_VERSION (2,32,0)
		if (g_settings_schema_source_lookup(g_settings_schema_source_get_default(), value = "org.gnome.desktop.interface", FALSE))
			g_signal_connect(g_settings_new(value), "changed::gtk-theme", G_CALLBACK(notify_updated_gtktheme), NULL);
		if (g_settings_schema_source_lookup(g_settings_schema_source_get_default(), value = "org.mate.interface", FALSE))
			g_signal_connect(g_settings_new(value), "changed::gtk-theme", G_CALLBACK(notify_updated_gtktheme), NULL);

		if (g_settings_schema_source_lookup(g_settings_schema_source_get_default(), value = "org.gnome.desktop.wm.preferences", FALSE))
			g_signal_connect(g_settings_new(value), "changed::button-layout", G_CALLBACK(notify_updated_gtktheme), NULL);
		if (g_settings_schema_source_lookup(g_settings_schema_source_get_default(), value = "org.cinnamon.desktop.wm.preferences", FALSE))
			g_signal_connect(g_settings_new(value), "changed::button-layout", G_CALLBACK(notify_updated_gtktheme), NULL);
		if (g_settings_schema_source_lookup(g_settings_schema_source_get_default(), value = "org.mate.Marco.general", FALSE))
			g_signal_connect(g_settings_new(value), "changed::button-layout", G_CALLBACK(notify_updated_gtktheme), NULL);
		if (g_settings_schema_source_lookup(g_settings_schema_source_get_default(), value = "org.mate.interface", FALSE))
			g_signal_connect(g_settings_new(value), "changed::gtk-decoration-layout", G_CALLBACK(notify_updated_gtktheme), NULL);
	#endif

	// gtk-can-change-accels for GTK 4.x | so same GTK 2.24 3.x 4.x & Qt 5.x 6.x
	accels_load(app);
	//GtkEventController *event = gtk_event_controller_key_new();
	//g_signal_connect(event, "key-released", G_CALLBACK(accels_change), window);
	//gtk_widget_add_controller(window, event);

	gtk_window_present(GTK_WINDOW(window));
	gtk_widget_grab_focus(gtk_widget_get_first_child(toolbar)); // focus on the first toolbar button
	if (headbarCloseLeft && headbarCloseRight) { // @todo not working here
		gtk_widget_set_visible(headbarCloseLeft, closeLeft);
		gtk_widget_set_visible(headbarCloseRight, closeRight);
	}
	add_progressbar_and_entrybar();
}

static void create_widgets(GtkWidget *root) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m create_widgets()\n");

	GtkWidget *hboxColumns = BOXH;
	GtkWidget *vboxColumn1 = BOXV, *vboxComboEntry = BOXV, *hboxSpin = BOXH, *hboxCheckRadio = BOXH, *vboxCheck = BOXV, *vboxRadio = BOXV;
	GtkWidget *vboxColumn2 = BOXV, *vboxButtons = BOXV, *hboxBtns1 = BOXH, *hboxBtns2 = BOXH, *hboxBtns3 = BOXH, *hboxBtns4 = BOXH;
	GtkWidget *vboxColumn3 = BOXV, *vboxProgress1 = BOXV, *vboxProgress2 = BOXV, *hboxProgress1 = BOXH, *hboxProgress2 = BOXH;
	GtkWidget *vboxColumn4 = BOXV, *vboxOthers = BOXV, *hboxLabel = BOXH, *hboxSpinner = BOXH;
	GtkWidget *vpane = PANEV, *hpane1 = PANEH, *hpane2 = PANEH;
	GtkWidget *hboxFrame1 = BOXH, *hboxFrame2 = BOXH, *hboxNotebook1 = BOXH, *hboxNotebook2 = BOXH;

	// columns layout
	add_to(root, hboxColumns, TRUE, TRUE, 0, 0);

		// column 1
		add_to(hboxColumns, vboxColumn1, TRUE, TRUE, 5, 0);
			add_to(vboxColumn1, vboxComboEntry, FALSE, TRUE, 5, 3);
				create_combos_entries(vboxComboEntry);
			add_to(vboxColumn1, hboxSpin, FALSE, FALSE, 5, 0);
				create_spinbuttons(hboxSpin);
			add_to(vboxColumn1, hboxCheckRadio, FALSE, TRUE, 5, 0);
				add_to(hboxCheckRadio, vboxCheck, TRUE, TRUE, 0, 0);
					create_checkbuttons(vboxCheck);
				add_to(hboxCheckRadio, vboxRadio, TRUE, TRUE, 0, 0);
					create_radiobuttons(vboxRadio);
		add_to(hboxColumns, SEPV, FALSE, FALSE, 0, 0);

		// column 2
		add_to(hboxColumns, vboxColumn2, TRUE, TRUE, 5, 0);
			add_to(vboxColumn2, vboxButtons, FALSE, TRUE, 5, 3);
			add_to(vboxColumn2, hboxBtns1, FALSE, FALSE, 5, 3);
			add_to(vboxColumn2, hboxBtns2, FALSE, FALSE, 5, 3);
			add_to(vboxColumn2, hboxBtns3, FALSE, FALSE, 5, 3);
			add_to(vboxColumn2, hboxBtns4, FALSE, FALSE, 5, 3);
				create_otherbuttons(vboxButtons, hboxBtns1, hboxBtns2, hboxBtns3, hboxBtns4);
		add_to(hboxColumns, SEPV, FALSE, FALSE, 0, 0);

		// column 3
		add_to(hboxColumns, vboxColumn3, TRUE, TRUE, 5, 0);
			add_to(vboxColumn3, vboxProgress1, FALSE, TRUE, 6, 10);
			add_to(vboxColumn3, hboxProgress1, FALSE, FALSE, 5, 10);
			add_to(vboxColumn3, hboxProgress2, FALSE, FALSE, 5, 10);
			add_to(vboxColumn3, vboxProgress2, FALSE, TRUE, 5, 10);
				create_progressbars(vboxProgress1, hboxProgress1, hboxProgress2, vboxProgress2);
		add_to(hboxColumns, SEPV, FALSE, FALSE, 0, 0);

		// column 4
		add_to(hboxColumns, vboxColumn4, TRUE, TRUE, 5, 0);
			add_to(vboxColumn4, vboxOthers, FALSE, TRUE, 5, 3);
				create_treeview(vboxOthers);
				add_to(vboxOthers, hboxLabel, FALSE, TRUE, 5, 0);
					create_labels(hboxLabel);
				add_to(vboxOthers, hboxSpinner, FALSE, TRUE, 5, 0);
					create_spinners(hboxSpinner);
				create_expander(vboxOthers);

	add_to(root, SEPH, FALSE, FALSE, 0, 0);

	// paned layout
	add_to(root, vpane, TRUE, TRUE, 0, 0);

		gtk_paned_set_start_child(GTK_PANED(vpane), hpane1);
		gtk_paned_set_shrink_start_child(GTK_PANED(vpane), FALSE);
		gtk_widget_set_size_request(hpane1, -1, 70); // The 70

			gtk_box_set_homogeneous(GTK_BOX(hboxFrame1), TRUE);
			gtk_box_set_spacing(GTK_BOX(hboxFrame1), 3);
			gtk_widget_set_margin_start(hboxFrame1, 10);
			gtk_widget_set_margin_end(hboxFrame1, 10);
			gtk_widget_set_margin_top(hboxFrame1, 10);
			gtk_widget_set_margin_bottom(hboxFrame1, 10);
			gtk_paned_set_start_child(GTK_PANED(hpane1), hboxFrame1);
			gtk_paned_set_resize_start_child(GTK_PANED(hpane1), FALSE);
			gtk_paned_set_shrink_start_child(GTK_PANED(hpane1), FALSE);

			gtk_box_set_homogeneous(GTK_BOX(hboxFrame2), TRUE);
			gtk_box_set_spacing(GTK_BOX(hboxFrame2), 3);
			gtk_widget_set_margin_start(hboxFrame2, 10);
			gtk_widget_set_margin_end(hboxFrame2, 10);
			gtk_widget_set_margin_top(hboxFrame2, 10);
			gtk_widget_set_margin_bottom(hboxFrame2, 10);
			gtk_paned_set_end_child(GTK_PANED(hpane1), hboxFrame2);

			create_frames(hboxFrame1, hboxFrame2);

		gtk_paned_set_end_child(GTK_PANED(vpane), hpane2);
		gtk_paned_set_shrink_end_child(GTK_PANED(vpane), FALSE);
		//gtk_widget_set_size_request(hpane2, -1, 120); // The 120

			gtk_box_set_homogeneous(GTK_BOX(hboxNotebook1), TRUE);
			gtk_box_set_spacing(GTK_BOX(hboxNotebook1), 3);
			gtk_widget_set_margin_start(hboxNotebook1, 10);
			gtk_widget_set_margin_end(hboxNotebook1, 10);
			gtk_widget_set_margin_top(hboxNotebook1, 10);
			gtk_widget_set_margin_bottom(hboxNotebook1, 10);
			gtk_paned_set_start_child(GTK_PANED(hpane2), hboxNotebook1);
			gtk_paned_set_resize_start_child(GTK_PANED(hpane2), FALSE);
			gtk_paned_set_shrink_start_child(GTK_PANED(hpane2), FALSE);

			gtk_box_set_homogeneous(GTK_BOX(hboxNotebook2), TRUE);
			gtk_box_set_spacing(GTK_BOX(hboxNotebook2), 3);
			gtk_widget_set_margin_start(hboxNotebook2, 10);
			gtk_widget_set_margin_end(hboxNotebook2, 10);
			gtk_widget_set_margin_top(hboxNotebook2, 10);
			gtk_widget_set_margin_bottom(hboxNotebook2, 10);
			gtk_paned_set_end_child(GTK_PANED(hpane2), hboxNotebook2);

			create_notebooks(hboxNotebook1, hboxNotebook2);
}

static void add_progressbar_and_entrybar() {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m add_progressbar_and_entrybar()\n");

	// entry toolbar
	toolbarentry = gtk_entry_new();
	gtk_entry_set_placeholder_text(GTK_ENTRY(toolbarentry), "...");
	gtk_widget_set_visible(toolbarentry, FALSE);
	gtk_widget_set_valign(toolbarentry, GTK_ALIGN_CENTER);
	gtk_widget_set_vexpand(toolbarentry, FALSE);
	gtk_widget_insert_after(toolbarentry, toolbar, toolbarend); // end left

	// progressbar toolbar
	progress8 = gtk_progress_bar_new();
	gtk_widget_set_size_request(progress8, 140, 1);
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress8), 0);
	gtk_orientable_set_orientation(GTK_ORIENTABLE(progress8), GTK_ORIENTATION_HORIZONTAL);
	gtk_widget_set_visible(progress8, FALSE);
	gtk_widget_set_valign(progress8, GTK_ALIGN_CENTER);
	gtk_widget_set_halign(progress8, GTK_ALIGN_END);
	gtk_widget_set_hexpand(progress8, TRUE);
	gtk_widget_insert_after(progress8, toolbar, gtk_widget_get_last_child(toolbar)); // end right

	// progressbar statusbar
	progress9 = gtk_progress_bar_new();
	gtk_widget_set_size_request(progress9, 140, 1);
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress9), 0);
	gtk_orientable_set_orientation(GTK_ORIENTABLE(progress9), GTK_ORIENTATION_HORIZONTAL);
	gtk_widget_set_visible(progress9, FALSE);
	gtk_widget_set_valign(progress9, GTK_ALIGN_CENTER);
	gtk_widget_set_halign(progress9, GTK_ALIGN_END);
	gtk_widget_set_hexpand(progress9, TRUE);
	gtk_widget_insert_after(progress9, gtk_widget_get_first_child(statusbar), gtk_widget_get_first_child(gtk_widget_get_first_child(statusbar))); // statusbar > box > label, statusbar > box > progressbar
}

static void add_to(GtkWidget *root, GtkWidget *widget, gboolean expand, gboolean fill, guint padding, guint spacing) {

	if (expand && fill) {
		gtk_widget_set_halign(widget, GTK_ALIGN_FILL);
		gtk_widget_set_valign(widget, GTK_ALIGN_FILL);
		gtk_widget_set_hexpand(widget, TRUE);
		gtk_widget_set_vexpand(widget, TRUE);
	}
	else if (expand) {
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

	gtk_box_append(GTK_BOX(root), widget);

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

static void create_toolbar(GtkWidget *root) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m create_toolbar()\n");

	GtkWidget *icon1, *icon2, *icon3, *icon4, *icon5, *icon6, *icon7, *icon8, *icon9;

	// GTK_BUTTON
	icon1 = gtk_button_new_from_icon_name("document-open");
	gtk_widget_add_css_class(icon1, "flat");
	g_signal_connect(icon1, "clicked", G_CALLBACK(dialog_open), NULL);

	icon2 = gtk_button_new_from_icon_name("document-open");
	gtk_widget_set_sensitive(icon2, FALSE);

	icon3 = gtk_button_new_from_icon_name("document-save");
	g_signal_connect(icon3, "clicked", G_CALLBACK(dialog_save), NULL);

	icon4 = gtk_button_new_from_icon_name("view-refresh");
	g_signal_connect_swapped(icon4, "clicked", G_CALLBACK(on_sighup), NULL);

	icon5 = gtk_button_new_from_icon_name("camera-photo");
	gtk_widget_set_sensitive(icon5, opt_screenshot ? TRUE : FALSE);
	g_signal_connect(icon5, "clicked", G_CALLBACK(take_screenshot), NULL);

	icon6 = gtk_button_new_from_icon_name("dialog-information");
	g_signal_connect(icon6, "clicked", G_CALLBACK(display_notification), NULL);
	#if defined (G_OS_WIN32)
		gtk_widget_set_sensitive(icon6, FALSE);
	#endif

	// GTK_TOGGLE_BUTTON
	icon7 = gtk_toggle_button_new();
	gtk_button_set_icon_name(GTK_BUTTON(icon7), "list-add");
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(icon7), TRUE);
	g_signal_connect(icon7, "clicked", G_CALLBACK(update_widgets), NULL);

	icon8 = gtk_toggle_button_new();
	gtk_button_set_icon_name(GTK_BUTTON(icon8), "list-remove");
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(icon8), FALSE);
	g_signal_connect(icon8, "clicked", G_CALLBACK(update_widgets), NULL);

	icon9 = gtk_toggle_button_new();
	gtk_button_set_icon_name(GTK_BUTTON(icon9), "window-close");
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(icon9), FALSE);
	gtk_widget_set_sensitive(icon9, FALSE);
	toolbarend = icon9;

	// layout
	add_to(root, icon1, FALSE, FALSE, 0, 0);
	add_to(root, icon2, FALSE, FALSE, 0, 0);
	add_to(root, icon3, FALSE, FALSE, 0, 0);
	add_to(root, SEPV, FALSE, FALSE, 0, 0);
	add_to(root, icon4, FALSE, FALSE, 0, 0);
	add_to(root, icon5, FALSE, FALSE, 0, 0);
	add_to(root, icon6, FALSE, FALSE, 0, 0);
	add_to(root, SEPV, FALSE, FALSE, 0, 0);
	add_to(root, icon7, FALSE, FALSE, 0, 0);
	add_to(root, icon8, FALSE, FALSE, 0, 0);
	add_to(root, icon9, FALSE, FALSE, 0, 0);
}

static void create_combos_entries(GtkWidget *root) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m create_combos_entries()\n");

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
	gtk_entry_set_icon_from_icon_name(GTK_ENTRY(entry3), GTK_ENTRY_ICON_PRIMARY, "edit-clear");
	gtk_entry_set_icon_from_icon_name(GTK_ENTRY(entry3), GTK_ENTRY_ICON_SECONDARY, "edit-find");
	gtk_entry_set_placeholder_text(GTK_ENTRY(entry3), "Placeholder");
	g_signal_connect(entry3, "icon-press", G_CALLBACK(clear_entry), NULL);

	entry4 = gtk_entry_new();
	gtk_editable_set_text(GTK_EDITABLE(entry4), "Entry");
	gtk_entry_set_icon_from_icon_name(GTK_ENTRY(entry4), GTK_ENTRY_ICON_PRIMARY, "edit-clear");
	gtk_entry_set_icon_from_icon_name(GTK_ENTRY(entry4), GTK_ENTRY_ICON_SECONDARY, "edit-find");
	gtk_widget_set_sensitive(entry4, FALSE);

	// layout
	add_to(root, combo1, FALSE, FALSE, 0, 0);
	add_to(root, combo2, FALSE, FALSE, 0, 0);
	add_to(root, combo3, FALSE, FALSE, 0, 0);
	add_to(root, combo4, FALSE, FALSE, 0, 0);
	add_to(root, entry1, FALSE, FALSE, 0, 0);
	add_to(root, entry2, FALSE, FALSE, 0, 0);
	add_to(root, entry3, FALSE, FALSE, 0, 0);
	add_to(root, entry4, FALSE, FALSE, 0, 0);
}

static void create_spinbuttons(GtkWidget *root) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m create_spinbuttons()\n");

	GtkWidget *spinbutton1, *spinbutton2;

	// GTK_SPIN_BUTTON
	spinbutton1 = gtk_spin_button_new_with_range(-100, 100, 1);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton1), 1);

	spinbutton2 = gtk_spin_button_new_with_range(-100, 100, 1);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton2), 1);
	gtk_widget_set_sensitive(spinbutton2, FALSE);

	// layout
	add_to(root, spinbutton1, FALSE, FALSE, 0, 0);
	add_to(root, BOXH, TRUE, TRUE, 0, 0); // empty space
	add_to(root, spinbutton2, FALSE, FALSE, 0, 0);
}

static void create_checkbuttons(GtkWidget *root) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m create_checkbuttons()\n");

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
	add_to(root, checkbutton1, FALSE, FALSE, 0, 0);
	add_to(root, checkbutton2, FALSE, FALSE, 0, 0);
	add_to(root, checkbutton3, FALSE, FALSE, 0, 0);
	add_to(root, checkbutton4, FALSE, FALSE, 0, 0);
	add_to(root, checkbutton5, FALSE, FALSE, 0, 0);
	add_to(root, checkbutton6, FALSE, FALSE, 0, 0);
}

static void create_radiobuttons(GtkWidget *root) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m create_radiobuttons()\n");

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
	add_to(root, radiobutton1, FALSE, FALSE, 0, 0);
	add_to(root, radiobutton2, FALSE, FALSE, 0, 0);
	add_to(root, radiobutton3, FALSE, FALSE, 0, 0);
	add_to(root, radiobutton4, FALSE, FALSE, 0, 0);
	add_to(root, radiobutton5, FALSE, FALSE, 0, 0);
	add_to(root, radiobutton6, FALSE, FALSE, 0, 0);
}

static void create_otherbuttons(GtkWidget *root1, GtkWidget *root2, GtkWidget *root3, GtkWidget *root4, GtkWidget *root5) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m create_otherbuttons()\n");

	GtkWidget *button1, *button2, *button3, *button4, *button5, *button6, *button7, *button8, *button9;
	GtkWidget *button10, *button11, *button12, *button13, *button14, *button17;

	// GTK_BUTTON
	button1 = gtk_button_new_with_label("Button 1");

	button2 = gtk_button_new_with_label("Button 2");
	gtk_widget_set_sensitive(button2, FALSE);

	button3 = gtk_toggle_button_new_with_label("Button 3");
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(button3), TRUE);

	button4 = gtk_toggle_button_new_with_label("Button 4");
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
		find_and_update_labels(button6);
		gtk_widget_set_size_request(button6, 186, -1); // The 186
		gtk_widget_set_tooltip_text(button6, _app("Choose a font"));
	#else
		button6 = gtk_font_button_new();
		find_and_update_labels(button6);
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
	GMenuItem *menuitem;
	GMenu *menu = g_menu_new();
	g_menu_append_item(menu, menuitem = g_menu_item_new("Popover item 1", NULL));
	g_object_unref(menuitem);
	g_menu_append_item(menu, menuitem = g_menu_item_new("Popover item 2", NULL));
	g_object_unref(menuitem);
	g_menu_append_item(menu, menuitem = g_menu_item_new("Popover item 3", NULL));
	g_object_unref(menuitem);
	gtk_menu_button_set_menu_model(GTK_MENU_BUTTON(button17), G_MENU_MODEL(menu));
	g_object_unref(menu);

	// layout
	add_to(root1, button1, FALSE, FALSE, 0, 0);
	add_to(root1, button2, FALSE, FALSE, 0, 0);
	add_to(root1, button3, FALSE, FALSE, 0, 0);
	add_to(root1, button4, FALSE, FALSE, 0, 0);
	add_to(root1, button5, FALSE, FALSE, 0, 0);
	add_to(root1, button6, FALSE, FALSE, 0, 0);
	add_to(root1, button7, FALSE, FALSE, 0, 0);
	add_to(root1, button8, FALSE, FALSE, 0, 0);
	add_to(root2, button9, FALSE, FALSE, 0, 0);
	add_to(root2, BOXH, TRUE, TRUE, 0, 0); // empty space
	add_to(root2, button10, FALSE, FALSE, 0, 0);
	add_to(root3, button11, FALSE, FALSE, 0, 0);
	add_to(root3, BOXH, TRUE, TRUE, 0, 0); // empty space
	add_to(root3, button12, FALSE, FALSE, 0, 0);
	add_to(root4, button13, FALSE, FALSE, 0, 0);
	add_to(root4, BOXH, TRUE, TRUE, 0, 0); // empty space
	add_to(root4, button14, FALSE, FALSE, 0, 0);
	add_to(root5, button15, FALSE, FALSE, 0, 0);
	add_to(root5, button16, FALSE, FALSE, 0, 0);
	add_to(root5, button17, FALSE, FALSE, 0, 0);
}

static void create_progressbars(GtkWidget *root1, GtkWidget *root2, GtkWidget *root3, GtkWidget *root4) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m create_progressbars()\n");

	// GTK_PROGRESS_BAR
	progress1 = gtk_progress_bar_new();
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress1), 0.5);
	gtk_orientable_set_orientation(GTK_ORIENTABLE(progress1), GTK_ORIENTATION_HORIZONTAL);

	progress2 = gtk_progress_bar_new();
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress2), 0.5);
	gtk_orientable_set_orientation(GTK_ORIENTABLE(progress2), GTK_ORIENTATION_HORIZONTAL);
	gtk_progress_bar_set_inverted(GTK_PROGRESS_BAR(progress2), TRUE);

	progress3 = gtk_progress_bar_new();
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress3), 0.5);
	gtk_orientable_set_orientation(GTK_ORIENTABLE(progress3), GTK_ORIENTATION_VERTICAL);
	gtk_widget_set_size_request(progress3, -1, 100); // The 100

	progress4 = gtk_progress_bar_new();
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress4), 0.5);
	gtk_orientable_set_orientation(GTK_ORIENTABLE(progress4), GTK_ORIENTATION_VERTICAL);
	gtk_progress_bar_set_inverted(GTK_PROGRESS_BAR(progress4), TRUE);

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
	add_to(root1, progress1, FALSE, FALSE, 0, 0);
	add_to(root1, progress2, FALSE, FALSE, 0, 0);
	add_to(root1, scale1, FALSE, FALSE, 0, 0);
	add_to(root1, scale2, FALSE, FALSE, 0, 0);
	add_to(root2, progress3, FALSE, FALSE, 0, 0);
	add_to(root2, progress4, FALSE, FALSE, 0, 0);
	add_to(root2, levelbar1, FALSE, FALSE, 0, 0);
	add_to(root2, levelbar2, FALSE, FALSE, 0, 0);
	add_to(root2, levelbar3, FALSE, FALSE, 0, 0);
	add_to(root2, levelbar4, FALSE, FALSE, 0, 0);
	add_to(root3, scale3, FALSE, FALSE, 0, 0);
	add_to(root3, scale5, FALSE, FALSE, 0, 0);
	add_to(root3, scale6, FALSE, FALSE, 0, 0);
	add_to(root3, scale4, FALSE, FALSE, 0, 0);
	add_to(root4, levelbar5, FALSE, FALSE, 0, 0);
	add_to(root4, levelbar6, FALSE, FALSE, 0, 0);
	add_to(root4, levelbar7, FALSE, FALSE, 0, 0);
	add_to(root4, levelbar8, FALSE, FALSE, 0, 0);
}

static void create_labels(GtkWidget *root) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m create_labels()\n");

	GtkWidget *label1, *label2;

	// GTK_LABEL
	label1 = gtk_label_new("Label 1");

	label2 = gtk_label_new("Label 2");
	gtk_widget_set_sensitive(label2, FALSE);

	// layout
	add_to(root, label1, FALSE, FALSE, 0, 0);
	add_to(root, BOXH, TRUE, TRUE, 0, 0); // empty space
	add_to(root, label2, FALSE, FALSE, 0, 0);
	add_to(root, BOXH, TRUE, TRUE, 0, 0); // empty space
}

static void create_spinners(GtkWidget *root) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m create_spinners()\n");

	GtkWidget *spinner1, *spinner2;

	// GTK_SPINNER
	spinner1 = gtk_spinner_new();
	gtk_widget_set_size_request(spinner1, 20, 20);

	spinner2 = gtk_spinner_new();
	gtk_widget_set_size_request(spinner2, 20, 20);
	gtk_widget_set_sensitive(spinner2, FALSE);
	//gtk_spinner_start(GTK_SPINNER(spinner2));

	// layout
	add_to(root, spinner1, FALSE, FALSE, 0, 0);
	add_to(root, BOXH, TRUE, TRUE, 0, 0); // empty space
	add_to(root, spinner2, FALSE, FALSE, 0, 0);
	add_to(root, BOXH, TRUE, TRUE, 0, 0); // empty space
}

static void create_expander(GtkWidget *root) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m create_expander()\n");

	GtkWidget *expander, *scrolledWindow, *tv;
	GtkTextBuffer *buffer;
	gchar *text;

	// GTK_EXPANDER
	expander = gtk_expander_new(_app("More..."));
	gtk_expander_set_expanded(GTK_EXPANDER(expander), TRUE);

	// GTK_SCROLLED_WINDOW
	scrolledWindow = gtk_scrolled_window_new();
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolledWindow), GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
	gtk_widget_set_size_request(scrolledWindow, -1, 120);

	const gchar *config = g_getenv("GTK_OVERLAY_SCROLLING");
	if (config && (strcmp(config, "0") == 0)) {
		gtk_scrolled_window_set_overlay_scrolling(GTK_SCROLLED_WINDOW(scrolledWindow), FALSE);
		gtk_widget_add_css_class(gtk_scrolled_window_get_hscrollbar(GTK_SCROLLED_WINDOW(scrolledWindow)), "discrete");
		gtk_widget_add_css_class(gtk_scrolled_window_get_vscrollbar(GTK_SCROLLED_WINDOW(scrolledWindow)), "discrete");
	}

	// GTK_TEXT_VIEW
	tv = gtk_text_view_new();
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(tv), GTK_WRAP_WORD);
	text = g_strdup_printf("%s %s", _app("A widget factory is a theme preview application for GTK and Qt. It displays the various widget types in a single window allowing to see the visual effect of the applied theme."), _app("A widget factory is a theme preview application for GTK and Qt. It displays the various widget types in a single window allowing to see the visual effect of the applied theme."));
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(tv));
	gtk_text_buffer_set_text(GTK_TEXT_BUFFER(buffer), text, -1);
	g_free(text);

	// layout
	gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolledWindow), tv);
	gtk_expander_set_child(GTK_EXPANDER(expander), scrolledWindow);
	add_to(root, expander, FALSE, FALSE, 0, 0);
}

static void create_frames(GtkWidget *root1, GtkWidget *root2) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m create_frames()\n");

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
	add_to(root1, frame1, TRUE, TRUE, 0, 0);
	add_to(root1, frame2, TRUE, TRUE, 0, 0);
	add_to(root2, frame3, TRUE, TRUE, 0, 0);
	add_to(root2, frame4, TRUE, TRUE, 0, 0);
}

static void create_notebooks(GtkWidget *root1, GtkWidget *root2) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m create_notebooks()\n");

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
	add_to(root1, notebook1, TRUE, TRUE, 0, 0);
	add_to(root1, notebook2, TRUE, TRUE, 0, 0);
	add_to(root2, notebook3, TRUE, TRUE, 0, 0);
	add_to(root2, notebook4, TRUE, TRUE, 0, 0);
}

static void create_notebook_tab(GtkWidget *notebook, gchar *text, GtkWidget *content, gboolean close) {

	GtkWidget *headbtn = BOXH, *btn;
	gtk_widget_set_hexpand(headbtn, FALSE);
	gtk_widget_set_vexpand(headbtn, FALSE);
	add_to(headbtn, gtk_label_new(text), TRUE, TRUE, 0, 0);

	// GTK_BUTTON
	if (close) {
		btn = gtk_button_new_from_icon_name("window-close");
		gtk_button_set_has_frame(GTK_BUTTON(btn), FALSE);
		gtk_widget_set_focus_on_click(btn, FALSE);
		add_to(headbtn, btn, FALSE, FALSE, 0, 0);
	}

	if (!content)
		content = BOXV;

	gtk_notebook_append_page(GTK_NOTEBOOK(notebook), content, headbtn);
	gtk_notebook_set_tab_reorderable(GTK_NOTEBOOK(notebook), content, TRUE);

	// gtk-scroll-tabs for GTK 4.x | so same GTK 2.24 3.x 4.x & Qt 5.x 6.x
	GtkEventController *event;
	event = gtk_event_controller_scroll_new(GTK_EVENT_CONTROLLER_SCROLL_BOTH_AXES | GTK_EVENT_CONTROLLER_SCROLL_DISCRETE);
	g_signal_connect(event, "scroll", G_CALLBACK(on_scrolltabs), notebook);
	gtk_widget_add_controller(gtk_widget_get_parent(headbtn), event);
}

static void create_treeview(GtkWidget *root) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m create_treeview()\n");

	GtkWidget *scrolledWindow, *view;
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
		7, "document-open",
		8, "document-open",
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
		7, "document-save",
		8, "document-save",
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
		7, "document-save-as",
		8, "document-save-as",
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
		7, "view-refresh",
		8, "view-refresh",
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
		7, "edit-cut",
		8, "edit-cut",
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
		7, "help-contents",
		8, "help-contents",
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
		7, "document-open",
		8, "document-open",
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
		7, "document-save",
		8, "document-save",
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
		7, "document-save-as",
		8, "document-save-as",
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
		7, "view-refresh",
		8, "view-refresh",
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
		7, "edit-cut",
		8, "edit-cut",
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
	scrolledWindow = gtk_scrolled_window_new();
	const gchar *config = g_getenv("GTK_OVERLAY_SCROLLING");
	if (config && (strcmp(config, "0") == 0))
		gtk_scrolled_window_set_overlay_scrolling(GTK_SCROLLED_WINDOW(scrolledWindow), FALSE);

	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolledWindow), GTK_POLICY_ALWAYS, GTK_POLICY_ALWAYS);
	gtk_widget_set_size_request(scrolledWindow, 200, 200); // The 200
	gtk_widget_set_size_request(view, 200, 200); // The 200

	gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolledWindow), view);
	add_to(root, scrolledWindow, FALSE, FALSE, 0, 0);
}

static void create_scales(GtkWidget *notebook, gchar *text, int position) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m create_scales()\n");

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
	if (gtk_widget_get_direction(window) == GTK_TEXT_DIR_RTL) // @todo bottom instead of top
		gtk_widget_add_css_class(scale1v, "top");

	scale2v = create_vertical_scale(value, FALSE, FALSE, position);
	update_marks(GTK_SCALE(scale2v), FALSE, GTK_POS_LEFT);
	if (gtk_widget_get_direction(window) == GTK_TEXT_DIR_RTL) // @todo bottom instead of top
		gtk_widget_add_css_class(scale2v, "top");

	scale3v = create_vertical_scale(value, FALSE, FALSE, position);
	update_marks(GTK_SCALE(scale3v), TRUE, GTK_POS_LEFT);
	if (gtk_widget_get_direction(window) == GTK_TEXT_DIR_RTL) // @todo bottom instead of top
		gtk_widget_add_css_class(scale3v, "top");

	scale4v = create_vertical_scale(value, TRUE, FALSE, position);
	if (gtk_widget_get_direction(window) == GTK_TEXT_DIR_RTL) // @todo bottom instead of top
		gtk_widget_add_css_class(scale4v, "top");

	scale5v = create_vertical_scale(value, TRUE, FALSE, position);
	update_marks(GTK_SCALE(scale5v), FALSE, GTK_POS_LEFT);
	if (gtk_widget_get_direction(window) == GTK_TEXT_DIR_RTL) // @todo bottom instead of top
		gtk_widget_add_css_class(scale5v, "top");

	scale6v = create_vertical_scale(value, TRUE, FALSE, position);
	update_marks(GTK_SCALE(scale6v), TRUE, GTK_POS_LEFT);
	if (gtk_widget_get_direction(window) == GTK_TEXT_DIR_RTL) // @todo bottom instead of top
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
	add_to(hbox, vbox1, TRUE, TRUE, 5, 5);
		add_to(vbox1, scale1h, FALSE, FALSE, 5, 5);
		add_to(vbox1, scale2h, FALSE, FALSE, 5, 5);
		add_to(vbox1, scale3h, FALSE, FALSE, 5, 5);
		add_to(vbox1, scale4h, FALSE, FALSE, 5, 5);
		add_to(vbox1, scale5h, FALSE, FALSE, 5, 5);
		add_to(vbox1, scale6h, FALSE, FALSE, 5, 5);
	add_to(hbox, vbox2, TRUE, TRUE, 5, 5);
		add_to(vbox2, hboxa, TRUE, TRUE, 0, 0);
			add_to(hboxa, scale1v, FALSE, FALSE, 5, 5);
			add_to(hboxa, scale2v, FALSE, FALSE, 5, 5);
			add_to(hboxa, scale3v, FALSE, FALSE, 5, 5);
			add_to(hboxa, scale7v, FALSE, FALSE, 5, 5);
			add_to(hboxa, scale8v, FALSE, FALSE, 5, 5);
			add_to(hboxa, scale9v, FALSE, FALSE, 5, 5);
		add_to(vbox2, hboxb, TRUE, TRUE, 0, 0);
			add_to(hboxb, scale4v, FALSE, FALSE, 5, 5);
			add_to(hboxb, scale5v, FALSE, FALSE, 5, 5);
			add_to(hboxb, scale6v, FALSE, FALSE, 5, 5);
			add_to(hboxb, scale10v, FALSE, FALSE, 5, 5);
			add_to(hboxb, scale11v, FALSE, FALSE, 5, 5);
			add_to(hboxb, scale12v, FALSE, FALSE, 5, 5);
	add_to(hbox, vbox3, TRUE, TRUE, 5, 5);
		add_to(vbox3, scale7h, FALSE, FALSE, 5, 5);
		add_to(vbox3, scale8h, FALSE, FALSE, 5, 5);
		add_to(vbox3, scale9h, FALSE, FALSE, 5, 5);
		add_to(vbox3, scale10h, FALSE, FALSE, 5, 5);
		add_to(vbox3, scale11h, FALSE, FALSE, 5, 5);
		add_to(vbox3, scale12h, FALSE, FALSE, 5, 5);

	create_notebook_tab(notebook, text, hbox, FALSE);
}

static GtkWidget* create_horizontal_scale(gdouble value, gboolean draw, gboolean inverted, int position) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m create_horizontal_scale()\n");

	GtkWidget *scale;

	scale = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 100, 1);
	gtk_range_set_value(GTK_RANGE(scale), value);
	gtk_scale_set_draw_value(GTK_SCALE(scale), draw);
	gtk_scale_set_value_pos(GTK_SCALE(scale), position);
	gtk_range_set_inverted(GTK_RANGE(scale), inverted);
	gtk_widget_set_size_request(scale, 186, -1); // The 186

	return scale;
}

static GtkWidget* create_vertical_scale(gdouble value, gboolean draw, gboolean inverted, int position) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m create_vertical_scale()\n");

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

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m create_traditional_menubar()\n");

	GMenu *menu, *submenu, *section, *base;
	GSimpleAction *action;
	GList *iterator, *look;
	gboolean mini;
	int total, count;

	// options
	menu = g_menu_new();
	g_menu_append_submenu(root, _app("_Options"), G_MENU_MODEL(menu));

		create_menuitem(app, menu, _gtk("_Open"), FALSE, AWF_ACCEL_OPEN, AWF_OPEN, "gtk-open", dialog_open);
		create_menuitem(app, menu, _app("Open recent file"), TRUE, AWF_ACCEL_RECE, AWF_RECE, NULL, NULL);
		create_menuitem(app, menu, _gtk("_Save"), FALSE, AWF_ACCEL_SAVE, AWF_SAVE, "gtk-save", dialog_save);
		create_menuitem(app, menu, _app("_Refresh"), FALSE, AWF_ACCEL_REFR, AWF_REFR, "gtk-refresh", G_CALLBACK(on_sighup)); // (update_theme)
		create_menuitem(app, menu, _app("Calendar"), FALSE, AWF_ACCEL_CALE, AWF_CALE, NULL, dialog_calendar);
		create_menuitem(app, menu, "Scales", FALSE, AWF_ACCEL_SCAL, AWF_SCAL, NULL, dialog_scales);
		create_menuitem(app, menu, _gtk("_Properties"), FALSE, AWF_ACCEL_PROP, AWF_PROP, "gtk-properties", dialog_message);
		create_menuitem(app, menu, _gtk("Page Set_up"), FALSE, AWF_ACCEL_PRSE, AWF_PRSE, NULL, dialog_page_setup); // gtk-page-setup removed
		create_menuitem(app, menu, _gtk("_Print"), FALSE, AWF_ACCEL_PRIN, AWF_PRIN, "gtk-print", dialog_print);

		submenu = g_menu_new();
		g_menu_append_submenu(menu, _app("More..."), G_MENU_MODEL(submenu));

			create_menuitem(app, submenu, _gtk("Cu_t"), FALSE, AWF_ACCEL_MCUT, AWF_MCUT, "gtk-cut", NULL);
			create_menuitem(app, submenu, _gtk("_Copy"), FALSE, AWF_ACCEL_MCOP, AWF_MCOP, "gtk-copy", NULL);
			create_menuitem(app, submenu, _gtk("_Paste"), FALSE, AWF_ACCEL_MPAS, AWF_MPAS, "gtk-paste", NULL);

		g_object_unref(submenu);

		submenu = g_menu_new();
		//g_menu_append_submenu(menu, _app("Less..."), G_MENU_MODEL(submenu));
		GMenuItem *less = g_menu_item_new_submenu(_app("Less..."), G_MENU_MODEL(submenu));
		g_menu_item_set_attribute(less, "submenu-action", "s", "disabled");
		g_menu_item_set_detailed_action(less, "disabled");
		g_menu_append_item(menu, less);
		g_object_unref(less);
		g_object_unref(submenu);

		section = g_menu_new();
		g_menu_append_section(menu, NULL, G_MENU_MODEL(section));

			action = g_simple_action_new_stateful("set-check-grp11", NULL, g_variant_new_boolean(FALSE));
			g_signal_connect(action, "activate", G_CALLBACK(activate_action), NULL);
			g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(action));
			g_object_unref(action);
			create_menuitem_radio(section, g_strdup_printf("Check 1 %s", _app("(unchecked)")), TRUE, "app.set-check-grp11", FALSE);

			action = g_simple_action_new_stateful("set-check-grp12", NULL, g_variant_new_boolean(TRUE));
			g_signal_connect(action, "activate", G_CALLBACK(activate_action), NULL);
			g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(action));
			g_object_unref(action);
			create_menuitem_radio(section, g_strdup_printf("Check 2 %s", _app("(checked)")), TRUE, "app.set-check-grp12", FALSE);

			create_menuitem_radio(section, g_strdup_printf("Check 3 %s", _app("(inconsistent)")), TRUE, NULL, FALSE); // @todo

			action = g_simple_action_new_stateful("set-check-grp21", NULL, g_variant_new_boolean(FALSE));
			g_simple_action_set_enabled(action, FALSE);
			g_signal_connect(action, "activate", G_CALLBACK(activate_action), NULL);
			g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(action));
			g_object_unref(action);
			create_menuitem_radio(section, g_strdup_printf("Check 1 %s", _app("(unchecked)")), TRUE, "app.set-check-grp21", FALSE);

			action = g_simple_action_new_stateful("set-check-grp22", NULL, g_variant_new_boolean(TRUE));
			g_simple_action_set_enabled(action, FALSE);
			g_signal_connect(action, "activate", G_CALLBACK(activate_action), NULL);
			g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(action));
			g_object_unref(action);
			create_menuitem_radio(section, g_strdup_printf("Check 2 %s", _app("(checked)")), TRUE, "app.set-check-grp22", FALSE);

			create_menuitem_radio(section, g_strdup_printf("Check 3 %s", _app("(inconsistent)")), TRUE, "set-check-grp23", FALSE); // @todo

		g_object_unref(section);

		section = g_menu_new();
		g_menu_append_section(menu, NULL, G_MENU_MODEL(section));

			action = g_simple_action_new_stateful("set-radio-grp1", G_VARIANT_TYPE_STRING, g_variant_new_string("checked"));
			g_signal_connect(action, "activate", G_CALLBACK(activate_action), NULL);
			g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(action));
			g_object_unref(action);

			create_menuitem_radio(section, g_strdup_printf("Radio 1 %s", _app("(unchecked)")), TRUE, "app.set-radio-grp1::unchecked", FALSE);
			create_menuitem_radio(section, g_strdup_printf("Radio 2 %s", _app("(checked)")), TRUE, "app.set-radio-grp1::checked", FALSE);
			create_menuitem_radio(section, g_strdup_printf("Radio 3 %s", _app("(inconsistent)")), TRUE, NULL, FALSE); // @todo

			action = g_simple_action_new_stateful("set-radio-grp2", G_VARIANT_TYPE_STRING, g_variant_new_string("checked"));
			g_simple_action_set_enabled(action, FALSE);
			g_signal_connect(action, "activate", G_CALLBACK(activate_action), NULL);
			g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(action));
			g_object_unref(action);

			create_menuitem_radio(section, g_strdup_printf("Radio 1 %s", _app("(unchecked)")), TRUE, "app.set-radio-grp2::unchecked", FALSE);
			create_menuitem_radio(section, g_strdup_printf("Radio 2 %s", _app("(checked)")), TRUE, "app.set-radio-grp2::checked", FALSE);
			create_menuitem_radio(section, g_strdup_printf("Radio 3 %s", _app("(inconsistent)")), TRUE, "disabled", FALSE); // @todo

		g_object_unref(section);

		section = g_menu_new();
		g_menu_append_section(menu, NULL, G_MENU_MODEL(section));

			create_menuitem(app, section, _gtk("_Close"), TRUE, AWF_ACCEL_CLOS, AWF_CLOS, "gtk-close", NULL);
			create_menuitem(app, section, _gtk("_Quit"), FALSE, AWF_ACCEL_QUIT, AWF_QUIT, "gtk-quit", quit);

		g_object_unref(section);

	g_object_unref(menu);

	// themes
	action = g_simple_action_new_stateful("set-theme", G_VARIANT_TYPE_STRING, g_variant_new_string(current_theme));
	g_signal_connect(action, "activate", G_CALLBACK(activate_action), NULL);
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(action));
	g_object_unref(action);

	// system themes
	menu = g_menu_new();
	g_menu_append_submenu(root, _app("_System themes"), G_MENU_MODEL(menu));
	total = g_list_length(list_system_theme);
	mini  = total > 15;
	for (iterator = list_system_theme; iterator; ) {

		// count how many following contiguous elements have iterator->data as prefix
		// avoids having a fixed list of themes
		if (mini) {
			count = 1;
			look  = iterator->next;
			while (look && g_str_has_prefix((gchar*) look->data, (gchar*) iterator->data)) {
				count++;
				look = look->next;
			}
		}
		else {
			count = 1;
		}

		// main menu or sub menu
		if (mini && (count > 2) && (count != total)) {
			submenu = g_menu_new();
			g_menu_append_submenu(menu, iterator->data, G_MENU_MODEL(submenu));
			g_object_unref(submenu); // @todo use-after-unref
			base = submenu;
		}
		else {
			base = menu;
		}

		// create the menuitems for all themes in the group (or the single theme if count == 1)
		while (count--) {

			if (g_hash_table_lookup(hash_user_theme, iterator->data)) // is_user
				create_menuitem_radio(base, iterator->data, FALSE, "disabled", FALSE); // @todo
			else
				create_menuitem_radio(base, iterator->data, FALSE, g_strdup_printf("app.set-theme::%s", (gchar*) iterator->data), TRUE);

			iterator = iterator->next;
		}
	}

	if (!list_system_theme)
		g_menu_append(menu, _app("No themes found"), "disabled"); // @todo

	g_object_unref(menu);

	// user themes
	menu = g_menu_new();
	g_menu_append_submenu(root, _app("_User themes"), G_MENU_MODEL(menu));
	total = g_list_length(list_user_theme);
	mini  = total > 15;
	for (iterator = list_user_theme; iterator; ) {

		// count how many following contiguous elements have iterator->data as prefix
		// avoids having a fixed list of themes
		if (mini) {
			count = 1;
			look  = iterator->next;
			while (look && g_str_has_prefix((gchar*) look->data, (gchar*) iterator->data)) {
				count++;
				look = look->next;
			}
		}
		else {
			count = 1;
		}

		// main menu or sub menu
		if (mini && (count > 2) && (count != total)) {
			submenu = g_menu_new();
			g_menu_append_submenu(menu, iterator->data, G_MENU_MODEL(submenu));
			g_object_unref(submenu); // @todo use-after-unref
			base = submenu;
		}
		else {
			base = menu;
		}

		// create the menuitems for all themes in the group (or the single theme if count == 1)
		while (count--) {
			create_menuitem_radio(base, iterator->data, FALSE, g_strdup_printf("app.set-theme::%s", (gchar*) iterator->data), TRUE);
			iterator = iterator->next;
		}
	}

	if (!list_user_theme)
		g_menu_append(menu, _app("No themes found"), "disabled"); // @todo

	g_object_unref(menu);

	// text direction
	action = g_simple_action_new_stateful("set-direction", G_VARIANT_TYPE_STRING, g_variant_new_string((current_direction == 1) ? "1" : "2"));
	g_signal_connect(action, "activate", G_CALLBACK(activate_action), NULL);
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(action));
	g_object_unref(action);

	menu = g_menu_new();
	g_menu_append_submenu(root, _app("_Text direction"), G_MENU_MODEL(menu));
		create_menuitem_radio(menu, _app("Left to Right (LTR)"), FALSE, g_strdup_printf("app.set-direction::%d", GTK_TEXT_DIR_LTR), TRUE);
		create_menuitem_radio(menu, _app("Right to Left (RTL)"), FALSE, g_strdup_printf("app.set-direction::%d", GTK_TEXT_DIR_RTL), TRUE);

	g_object_unref(menu);

	// help
	menu = g_menu_new();
	g_menu_append_submenu(root, _app("_Help"), G_MENU_MODEL(menu));

		create_menuitem(app, menu, "GtkInspector", FALSE, AWF_ACCEL_INSP, AWF_INSP, NULL, dialog_inspector);
		create_menuitem(app, menu, _gtk("_About"), FALSE, AWF_ACCEL_ABOU, AWF_ABOU, "gtk-about", dialog_about);

	g_object_unref(menu);
}

static void create_menuitem_radio(GMenu *menu, gchar *text, gboolean free1, gchar *group, gboolean free2) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m create_menuitem_radio(%s)\n", text);

	GMenuItem *menuitem = g_menu_item_new(text, group);
	g_menu_append_item(menu, menuitem);
	g_object_unref(menuitem);

	if (free1)
		g_free(text);
	if (free2)
		g_free(group);
}

static void create_menuitem(GtkApplication *app, GMenu *menu, gchar *text, gboolean dsb, gchar *acl, gchar *kmp, gchar *icon, GCallback function) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m create_menuitem(%s)\n", text);

	GMenuItem *menuitem;
	GSimpleAction *action = NULL;
	gchar *appkey = "disabled";

	if (!dsb) {
		appkey = g_strdup_printf("app.%s", kmp);
		action = g_simple_action_new(kmp, NULL);
		g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(action));

		const char *acckey[2] = { acl, NULL };
		gtk_application_set_accels_for_action(app, appkey, acckey);
	}

	menuitem = g_menu_item_new(text, appkey);

	if (action && function)
		g_signal_connect(action, "activate", function, NULL);
	if (icon)
		g_menu_item_set_attribute_value(menuitem, "icon", g_variant_new_string(icon)); // with gtk4-classic, without the icon is hidden

	// @see maybe https://github.com/GNOME/gtk/commit/7344a03aa33e334e034a6542b391f9649ffe38f5
	// display menuitem shortcuts with GTK 4.0
	#if !GTK_CHECK_VERSION (4,3,2)
		if (acl)
			g_menu_item_set_attribute(menuitem, "accel", "s", acl, NULL);
	#endif

	g_menu_append_item(menu, menuitem);
	g_object_unref(menuitem);

	if (!dsb) {
		g_object_unref(action);
		g_free(appkey);
	}
}

static void activate_action(GSimpleAction *action, GVariant *parameter, gpointer data) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m activate_action()\n");

	// radio
	if (parameter) {
		g_simple_action_set_state(action, parameter);
		if (strcmp(g_action_get_name(G_ACTION(action)), "set-theme") == 0)
			update_theme((gchar*) g_variant_get_string(parameter, NULL));
		else if (strcmp(g_action_get_name(G_ACTION(action)), "set-direction") == 0)
			update_text_direction((strcmp(g_variant_get_string(parameter, NULL), "1") == 0) ? 1 : 2);
	}
	// checkbox
	else {
		GVariant *actionState = g_action_get_state(G_ACTION(action));
		if (g_variant_get_boolean(actionState) == FALSE)
			g_simple_action_set_state(action, g_variant_new_boolean(TRUE));
		else
			g_simple_action_set_state(action, g_variant_new_boolean(FALSE));
		g_variant_unref(actionState);
	}
}

static void accels_load(GtkApplication *app) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m accels_load()\n");

	gchar *oldPath = g_build_filename(g_get_home_dir(), ".awf-gtk-accels", NULL);
	if (g_file_test(oldPath, G_FILE_TEST_EXISTS)) {
		gchar *newPath = g_build_filename(g_get_home_dir(), ".awf-accels", NULL);
		g_rename(oldPath, newPath);
		g_free(newPath);
	}
	g_free(oldPath);

	// gtk-can-change-accels for GTK 4.x | so same GTK 2.24 3.x 4.x & Qt 5.x 6.x
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

					if (awf_debug)
						g_printf("\033[33m[debug]\033[00m accels_foundInFile: %s %s\n", kmp, acl);

					GAction *action = g_action_map_lookup_action(map, kmp);
					if (action != NULL) {

						gchar *full = g_strdup_printf("app.%s", kmp);
						if (awf_debug)
							g_printf("\033[33m[debug]\033[00m accels_foundInMenu: %s %s %s\n", kmp, full, acl);

						const char *acckey[2] = { acl, NULL };
						gtk_application_set_accels_for_action(app, full, acckey);
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

static gboolean accels_change(GtkEventControllerKey *controller, guint keyval, guint keycode, GdkModifierType state) { // todo

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m accels_change()\n");

	// @todo not triggered when menu is open
	return FALSE;
}

static void accels_save() { // todo

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m accels_save()\n");

	// gtk-can-change-accels for GTK 3.x | so same GTK 2.24 3.x 4.x & Qt 5.x 6.x
	if (must_save_accels) {
		// @todo
	}
}


// dialogs

static void dialog_close(GtkWidget *widget, GtkDialog *dialog) {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m dialog_close()\n");

	if (GTK_IS_WINDOW(widget))
		gtk_window_destroy(GTK_WINDOW(widget));
	else if (GTK_IS_WINDOW(dialog))
		gtk_window_destroy(GTK_WINDOW(dialog));
}

static void dialog_open() {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m dialog_open()\n");

	#if GTK_CHECK_VERSION (4,10,0)
		GtkFileDialog *dialog = gtk_file_dialog_new();

		gchar *text = g_strdup_printf("%s - GTK %d.%d", "GtkFileDialog:Open", GTK_MAJOR_VERSION, GTK_MINOR_VERSION);
		gtk_file_dialog_set_title(dialog, text);
		g_free(text);

		GFile *home = g_file_new_for_path(g_get_home_dir());
		gtk_file_dialog_set_initial_folder(dialog, home);
		g_object_unref(home);

		gtk_file_dialog_open_multiple(dialog, GTK_WINDOW(window), NULL, NULL, NULL);
		g_object_unref(dialog);
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

		gchar *text = g_strdup_printf("%s - GTK %d.%d", "GtkFileChooserDialog:Open", GTK_MAJOR_VERSION, GTK_MINOR_VERSION);
		gtk_window_set_title(GTK_WINDOW(dialog), text);
		g_free(text);

		GFile *home = g_file_new_for_path(g_get_home_dir());
		gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(dialog), home, NULL);
		g_object_unref(home);

		gtk_file_chooser_set_select_multiple(GTK_FILE_CHOOSER(dialog), TRUE);
		gtk_window_present(GTK_WINDOW(dialog));
		g_signal_connect(dialog, "response", G_CALLBACK(dialog_close), NULL);
	#endif
}

static void dialog_save() {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m dialog_save()\n");

	#if GTK_CHECK_VERSION (4,10,0)
		GtkFileDialog *dialog = gtk_file_dialog_new();

		gchar *text = g_strdup_printf("%s - GTK %d.%d", "GtkFileDialog:Save", GTK_MAJOR_VERSION, GTK_MINOR_VERSION);
		gtk_file_dialog_set_title(dialog, text);
		g_free(text);

		GFile *home = g_file_new_for_path(g_get_home_dir());
		gtk_file_dialog_set_initial_folder(dialog, home);
		g_object_unref(home);

		gtk_file_dialog_save(dialog, GTK_WINDOW(window), NULL, NULL, NULL);
		g_object_unref(dialog);
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

		gchar *text = g_strdup_printf("%s - GTK %d.%d", "GtkFileChooserDialog:Save", GTK_MAJOR_VERSION, GTK_MINOR_VERSION);
		gtk_window_set_title(GTK_WINDOW(dialog), text);
		g_free(text);

		GFile *home = g_file_new_for_path(g_get_home_dir());
		gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(dialog), home, NULL);
		g_object_unref(home);

		gtk_window_present(GTK_WINDOW(dialog));
		g_signal_connect(dialog, "response", G_CALLBACK(dialog_close), NULL);
	#endif
}

static void dialog_message() {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m dialog_message()\n");

	GtkWidget *dialog = gtk_message_dialog_new(
		GTK_WINDOW(window),
		GTK_DIALOG_DESTROY_WITH_PARENT,
		GTK_MESSAGE_INFO,
		GTK_BUTTONS_YES_NO,
		"GtkMessageDialog");

	gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(dialog), _app("A widget factory is a theme preview application for GTK and Qt. It displays the various widget types in a single window allowing to see the visual effect of the applied theme."));

	gchar *text = g_strdup_printf("%s - GTK %d.%d", "GtkMessageDialog", GTK_MAJOR_VERSION, GTK_MINOR_VERSION);
	gtk_window_set_title(GTK_WINDOW(dialog), text);
	g_free(text);

	// dialog window
	#if GTK_CHECK_VERSION (4,10,0)
		gtk_window_set_modal(GTK_WINDOW(dialog), TRUE);
		gtk_window_set_transient_for(GTK_WINDOW(dialog), GTK_WINDOW(window));
	#endif

	g_signal_connect(dialog, "response", G_CALLBACK(dialog_close), NULL);
	gtk_window_present(GTK_WINDOW(dialog));
}

static void dialog_page_setup() {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m dialog_page_setup()\n");

	//GtkWidget *dialog = gtk_page_setup_unix_dialog_new("GtkPageSetupUnixDialog", GTK_WINDOW(window));
	//
	// dialog window
	//~if GTK_CHECK_VERSION (4,10,0)
	//	gtk_window_set_modal(GTK_WINDOW(dialog), TRUE);
	//	gtk_window_set_transient_for(GTK_WINDOW(dialog), GTK_WINDOW(window));
	//~endif
	//
	//g_signal_connect(dialog, "response", G_CALLBACK(dialog_close), NULL);
	//gtk_window_present(GTK_WINDOW(dialog));

	GtkPageSetup *setup = gtk_print_run_page_setup_dialog(GTK_WINDOW(window), NULL, NULL); // @todo 4.12 segfault on close
	g_object_unref(setup);
}

static void dialog_print() {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m dialog_print()\n");

	//GtkWidget *dialog = gtk_print_unix_dialog_new("GtkPrintUnixDialog", GTK_WINDOW(window));
	//
	// dialog window
	//~if GTK_CHECK_VERSION (4,10,0)
	//	gtk_window_set_modal(GTK_WINDOW(dialog), TRUE);
	//	gtk_window_set_transient_for(GTK_WINDOW(dialog), GTK_WINDOW(window));
	//~endif
	//
	//g_signal_connect(dialog, "response", G_CALLBACK(dialog_close), NULL);
	//gtk_window_present(GTK_WINDOW(dialog));

	GtkPrintOperation *op = gtk_print_operation_new();
	gtk_print_operation_run(op, GTK_PRINT_OPERATION_ACTION_PRINT_DIALOG, GTK_WINDOW(window), NULL); // @todo 4.12 segfault on close
	g_object_unref(op);
}

static void dialog_about() {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m dialog_about()\n");

	GdkPixbuf *pixbuf = NULL;
	#if defined (G_OS_WIN32)
		//extern GdkPixbuf *gdk_win32_icon_to_pixbuf_libgtk_only(HICON hicon);
		HICON hIcon = (HICON) LoadImage(GetModuleHandle(NULL), "IDI_ICON1", IMAGE_ICON, 64, 64, LR_DEFAULTSIZE);
		//if (hIcon)
		//	pixbuf = gdk_win32_icon_to_pixbuf_libgtk_only(hIcon);
	#endif

	gchar *cVersion;
	#ifdef __STDC_VERSION__
		if      (__STDC_VERSION__ >= 202311L) cVersion = "C23";
		else if (__STDC_VERSION__ >= 201710L) cVersion = "C17";
		else if (__STDC_VERSION__ >= 201112L) cVersion = "C11";
		else if (__STDC_VERSION__ >= 199901L) cVersion = "C99";
		else if (__STDC_VERSION__ >= 199409L) cVersion = "C95";
		else                                  cVersion = "C (unknown)";
	#else
		cVersion = "C89/C90";
	#endif

	gchar *t1, *t2, *t3, *t4;
	gtk_show_about_dialog(GTK_WINDOW(window),
		"version", VERSION,
		"comments", t1 = g_strdup_printf("%s\n\n%s\n%s\n\n%s\n%s",
			_app("A widget factory is a theme preview application for GTK and Qt. It displays the various widget types in a single window allowing to see the visual effect of the applied theme."),
			t2 = g_strdup_printf(_app("Remove %s file"), "~/.awf-accels"),
			_app("to reset keyboard shortcuts."),
			t3 = g_strdup_printf(_app("compiled in %s with gtk %d.%d.%d and glib %d.%d.%d and pango %s"),
				cVersion,
				GTK_MAJOR_VERSION, GTK_MINOR_VERSION, GTK_MICRO_VERSION,
				GLIB_MAJOR_VERSION, GLIB_MINOR_VERSION, GLIB_MICRO_VERSION,
				PANGO_VERSION_STRING),
			t4 = g_strdup_printf(_app(" started with gtk %d.%d.%d and glib %d.%d.%d and pango %s"),
				gtk_get_major_version(), gtk_get_minor_version(), gtk_get_micro_version(),
				glib_major_version, glib_minor_version, glib_micro_version,
				pango_version_string())
		),
		"website", "https://github.com/luigifab/awf-extended",
		"copyright", "Copyright © 2020-2027 Fabrice Creuzot (luigifab)\nCopyright © 2011-2017 Valère Monseur (valr)",
		"logo", pixbuf,
		"icon-name", pixbuf ? NULL : GETTEXT_PACKAGE,
		"logo-icon-name", pixbuf ? NULL : GETTEXT_PACKAGE,
		"license", _app("A widget factory is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the free software foundation, either version 3 of the license, or (at your option) any later version."),
		"wrap-license", TRUE,
		NULL);

	g_free(t1);
	g_free(t2);
	g_free(t3);
	g_free(t4);

	#if defined (G_OS_WIN32)
		if (hIcon) {
			if (pixbuf)
				g_object_unref(pixbuf);
			DestroyIcon(hIcon);
		}
	#endif
}

static void dialog_inspector() {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m dialog_inspector()\n");

	gtk_window_set_interactive_debugging(TRUE);
}

static void dialog_calendar() {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m dialog_calendar()\n");

	GtkWidget *dialog, *infobar, *label, *calendar, *area, *btn, *vbox = BOXV, *hbox;
	gchar *text;

	// info bars and calendar
	G_GNUC_BEGIN_IGNORE_DEPRECATIONS // GTK 4.10+

	infobar = gtk_info_bar_new_with_buttons(_gtk("_OK"), GTK_RESPONSE_OK, NULL);
	gtk_info_bar_set_message_type(GTK_INFO_BAR(infobar), GTK_MESSAGE_INFO);
	label = gtk_label_new(_app("This is an info bar."));
	gtk_info_bar_add_child(GTK_INFO_BAR(infobar), label);
	add_to(vbox, infobar, FALSE, FALSE, 0, 0);

	infobar = gtk_info_bar_new_with_buttons(_app("Ok"), GTK_RESPONSE_OK, NULL);
	gtk_info_bar_set_message_type(GTK_INFO_BAR(infobar), GTK_MESSAGE_QUESTION);
	label = gtk_label_new(_app("This is a question bar."));
	gtk_info_bar_add_child(GTK_INFO_BAR(infobar), label);
	add_to(vbox, infobar, FALSE, FALSE, 0, 0);

	infobar = gtk_info_bar_new();
	gtk_info_bar_set_message_type(GTK_INFO_BAR(infobar), GTK_MESSAGE_WARNING);
	label = gtk_label_new(_app("This is a warning bar."));
	gtk_info_bar_add_child(GTK_INFO_BAR(infobar), label);
	add_to(vbox, infobar, FALSE, FALSE, 0, 0);

	infobar = gtk_info_bar_new();
	gtk_info_bar_set_message_type(GTK_INFO_BAR(infobar), GTK_MESSAGE_ERROR);
	label = gtk_label_new(_app("This is an error bar."));
	gtk_info_bar_add_child(GTK_INFO_BAR(infobar), label);
	add_to(vbox, infobar, FALSE, FALSE, 0, 0);

	calendar = gtk_calendar_new();
	gtk_calendar_set_show_day_names(GTK_CALENDAR(calendar), TRUE);
	gtk_calendar_set_show_week_numbers(GTK_CALENDAR(calendar), TRUE);
	add_to(vbox, calendar, FALSE, FALSE, 0, 0);

	G_GNUC_END_IGNORE_DEPRECATIONS

	// GtkWindow:Modal or GtkDialog
	#if GTK_CHECK_VERSION (4,10,0)
		dialog = gtk_window_new();
		gtk_widget_add_css_class(dialog, "dialog");

		text = g_strdup_printf("%s - GTK %d.%d", "GtkWindow:Modal", GTK_MAJOR_VERSION, GTK_MINOR_VERSION);
		gtk_window_set_title(GTK_WINDOW(dialog), text);
		g_free(text);

		// encore une idée de génie de GTK
		area = BOXV;
		gtk_widget_add_css_class(area, "dialog-vbox");
		gtk_window_set_child(GTK_WINDOW(dialog), area);
		add_to(area, vbox, TRUE, TRUE, 0, 5); // no padding

		// encore une idée de génie de GTK
		hbox = BOXH;
		gtk_widget_add_css_class(hbox, "dialog-action-area");
		btn = gtk_button_new_with_mnemonic(_gtk("_Close"));
		g_signal_connect(btn, "clicked", G_CALLBACK(dialog_close), dialog);
		gtk_box_append(GTK_BOX(hbox), btn);
		add_to(area, hbox, TRUE, TRUE, 0, 0);
		gtk_widget_set_halign(hbox, GTK_ALIGN_END);
	#else
		dialog = gtk_dialog_new_with_buttons(NULL, GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, NULL, NULL);

		text = g_strdup_printf("%s - GTK %d.%d", "GtkDialog", GTK_MAJOR_VERSION, GTK_MINOR_VERSION);
		gtk_window_set_title(GTK_WINDOW(dialog), text);
		g_free(text);

		area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
		add_to(area, vbox, TRUE, TRUE, 5, 5);
		btn = gtk_dialog_add_button(GTK_DIALOG(dialog), _gtk("_Close"), GTK_RESPONSE_OK);
	#endif

	if (awf_csd) {
		gtk_window_set_decorated(GTK_WINDOW(dialog), TRUE);
		GtkWidget *headerbardialog = gtk_header_bar_new();
		gtk_header_bar_set_show_title_buttons(GTK_HEADER_BAR(headerbardialog), TRUE);
		gtk_window_set_titlebar(GTK_WINDOW(dialog), headerbardialog);
	}

	// dialog window
	#if GTK_CHECK_VERSION (4,10,0)
		gtk_window_set_modal(GTK_WINDOW(dialog), TRUE);
		gtk_window_set_transient_for(GTK_WINDOW(dialog), GTK_WINDOW(window));
	#else
		g_signal_connect(dialog, "response", G_CALLBACK(dialog_close), NULL);
	#endif

	gtk_widget_set_name(dialog, "AwfDialogWindow");
	gtk_window_set_resizable(GTK_WINDOW(dialog), FALSE);
	gtk_widget_set_size_request(dialog, 350, -1);
	gtk_window_present(GTK_WINDOW(dialog));
	gtk_widget_grab_focus(GTK_WIDGET(btn));
}

static void dialog_scales() {

	if (awf_trace)
		g_printf("\033[36m[trace]\033[00m dialog_scales()\n");

	GtkWidget *dialog, *notebook, *area, *btn, *hbox;
	gchar *text;

	// notebook and scales
	notebook = gtk_notebook_new();
	gtk_notebook_set_scrollable(GTK_NOTEBOOK(notebook), FALSE);
	gtk_notebook_set_tab_pos(GTK_NOTEBOOK(notebook), GTK_POS_TOP);
		create_scales(notebook, "value top", GTK_POS_TOP);
		create_scales(notebook, "value right", GTK_POS_RIGHT);
		create_scales(notebook, "value bottom", GTK_POS_BOTTOM);
		create_scales(notebook, "value left", GTK_POS_LEFT);

	// GtkWindow:Modal or GtkDialog
	#if GTK_CHECK_VERSION (4,10,0)
		dialog = gtk_window_new();
		gtk_widget_add_css_class(dialog, "dialog");

		text = g_strdup_printf("%s - GTK %d.%d", "GtkWindow:Modal", GTK_MAJOR_VERSION, GTK_MINOR_VERSION);
		gtk_window_set_title(GTK_WINDOW(dialog), text);
		g_free(text);

		// encore une idée de génie de GTK
		area = BOXV;
		gtk_widget_add_css_class(area, "dialog-vbox");
		gtk_window_set_child(GTK_WINDOW(dialog), area);
		add_to(area, notebook, TRUE, TRUE, 0, 5); // no padding

		// encore une idée de génie de GTK
		hbox = BOXH;
		gtk_widget_add_css_class(hbox, "dialog-action-area");
		btn = gtk_button_new_with_mnemonic(_gtk("_Close"));
		g_signal_connect(btn, "clicked", G_CALLBACK(dialog_close), dialog);
		gtk_box_append(GTK_BOX(hbox), btn);
		add_to(area, hbox, TRUE, TRUE, 0, 0);
		gtk_widget_set_halign(hbox, GTK_ALIGN_END);
	#else
		dialog = gtk_dialog_new_with_buttons(NULL, GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, NULL, NULL);

		text = g_strdup_printf("%s - GTK %d.%d", "GtkDialog", GTK_MAJOR_VERSION, GTK_MINOR_VERSION);
		gtk_window_set_title(GTK_WINDOW(dialog), text);
		g_free(text);

		area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
		add_to(area, notebook, TRUE, TRUE, 5, 5);
		btn = gtk_dialog_add_button(GTK_DIALOG(dialog), _gtk("_Close"), GTK_RESPONSE_OK);
	#endif

	if (awf_csd) {
		gtk_window_set_decorated(GTK_WINDOW(dialog), TRUE);
		GtkWidget *headerbardialog = gtk_header_bar_new();
		gtk_header_bar_set_show_title_buttons(GTK_HEADER_BAR(headerbardialog), TRUE);
		gtk_window_set_titlebar(GTK_WINDOW(dialog), headerbardialog);
	}

	// dialog window
	#if GTK_CHECK_VERSION (4,10,0)
		gtk_window_set_modal(GTK_WINDOW(dialog), TRUE);
		gtk_window_set_transient_for(GTK_WINDOW(dialog), GTK_WINDOW(window));
	#else
		g_signal_connect(dialog, "response", G_CALLBACK(dialog_close), NULL);
	#endif

	gtk_widget_set_name(dialog, "AwfDialogWindow");
	gtk_window_set_resizable(GTK_WINDOW(dialog), FALSE);
	gtk_window_present(GTK_WINDOW(dialog));
	gtk_widget_grab_focus(GTK_WIDGET(btn));
}


// gtk-scroll-tabs for GTK 4.x | so same GTK 2.24 3.x 4.x & Qt 5.x 6.x
// @see https://github.com/mate-desktop/mate-control-center/blob/master/capplets/common/capplet-util.c
// for on_scrolltabs source function is capplet_dialog_page_scroll_event_cb
//  of mate-appearance-properties from mate-control-center, GNU GPL 2.0+

static gboolean on_scrolltabs(GtkEventControllerScroll *event, double dx, double dy, GtkWidget *widget) {

	// gtk-scroll-tabs for GTK 4.x | so same GTK 2.24 3.x 4.x & Qt 5.x 6.x
	GtkWidget *child, *eventWidget, *actionWidget;
	GtkNotebook *notebook;

	while (!GTK_IS_NOTEBOOK(widget))
		widget = gtk_widget_get_parent(widget);

	notebook = GTK_NOTEBOOK(widget);

	child = gtk_notebook_get_nth_page(notebook, gtk_notebook_get_current_page(notebook));
	if (child == NULL)
		return FALSE;

	// ignore scroll events from the content of the page
	eventWidget = gtk_event_controller_get_widget(GTK_EVENT_CONTROLLER(event));
	if (eventWidget == NULL || eventWidget == child || gtk_widget_is_ancestor(eventWidget, child))
		return FALSE;

	// and also from the action widgets
	actionWidget = gtk_notebook_get_action_widget(notebook, GTK_PACK_START);
	if (eventWidget == actionWidget || (actionWidget != NULL && gtk_widget_is_ancestor(eventWidget, actionWidget)))
		return FALSE;
	actionWidget = gtk_notebook_get_action_widget(notebook, GTK_PACK_END);
	if (eventWidget == actionWidget || (actionWidget != NULL && gtk_widget_is_ancestor(eventWidget, actionWidget)))
		return FALSE;

	if ((dy > 0) || (dx > 0))
		gtk_notebook_next_page(notebook);
	else if ((dy < 0) || (dx < 0))
		gtk_notebook_prev_page(notebook);

	return TRUE;
}


// yolo