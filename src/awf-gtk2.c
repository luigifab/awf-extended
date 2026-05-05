/**
 * Forked  M/10/03/2020
 * Updated V/01/05/2026
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
 *  Debian Testing 64                  (1536 MB) GTK 2.24/3.24/4.22 + GLIB 2.88 + Pango 1.57
 *  Fedora Rawhide 64                  (1536 MB) GTK 2.24/3.24/4.23 + GLIB 2.88 + Pango 1.57
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
	#include <gdk/gdkwin32.h>
#elif defined (G_OS_UNIX)
	#include <libnotify/notify.h>
#endif
#if defined (G_OS_UNIX) && GLIB_CHECK_VERSION (2,30,0)
	#include <glib-unix.h>
#endif
#pragma GCC diagnostic pop

#define GTK_DIRNAME "gtk-2.0"
#define GETTEXT_PACKAGE "awf-gtk2"
#define BOXH (gtk_hbox_new (FALSE, 0))
#define BOXV (gtk_vbox_new (FALSE, 0))
#define SEPH (gtk_hseparator_new ())
#define SEPV (gtk_vseparator_new ())
#define PANEH (gtk_hpaned_new ())
#define PANEV (gtk_vpaned_new ())
#define GDK_KEY_F1 0xffbe
#define GDK_KEY_F2 0xffbf
#define GDK_KEY_F3 0xffc0
#define GDK_KEY_F4 0xffc1
#define GDK_KEY_F5 0xffc2
#define GDK_KEY_F6 0xffc3
#define GDK_KEY_F7 0xffc4
#define GDK_KEY_F8 0xffc5
#define GDK_KEY_F9 0xffc6
#define GDK_KEY_F10 0xffc7
#define GDK_KEY_F11 0xffc8
#define GDK_KEY_F12 0xffc9
#define GDK_KEY_Delete 0xffff
#define GDK_KEY_KP_Delete 0xff9f
#define GDK_KEY_BackSpace 0xff08

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
#define _gtk(x) dgettext("gtk20", x)

// global variables
static gboolean awf_debug = FALSE;
static gboolean awf_trace = FALSE;
static GHashTable *hash_system_theme = NULL;
static GHashTable *hash_user_theme = NULL;
static GList *list_system_theme = NULL;
static GList *list_user_theme = NULL;
static GtkWidget *window = NULL, *menubar = NULL, *toolbar = NULL, *toolbarentry = NULL, *statusbar = NULL;
static GtkWidget *button15 = NULL, *button16 = NULL;
static GtkWidget *progress1 = NULL, *progress2 = NULL, *progress3 = NULL, *progress4 = NULL, *progress8 = NULL, *progress9 = NULL;
static GtkWidget *scale1 = NULL, *scale2 = NULL, *scale3 = NULL, *scale4 = NULL, *scale5 = NULL, *scale6 = NULL;
static GtkWidget *notebook1 = NULL, *notebook2 = NULL, *notebook3 = NULL, *notebook4 = NULL;
static GtkWidget *current_menuitem  = NULL;
static int current_direction        = 0; // GTK_TEXT_DIR_NONE
static gchar *current_theme         = NULL;
static gchar *opt_theme             = NULL;
static gchar *opt_screenshot        = NULL;
static gboolean allow_update_theme  = TRUE;
static gboolean allow_update_values = TRUE;
static gboolean must_save_accels    = FALSE;

// global functions
static void awf_load_theme(GHashTable* hashtable, gchar *directory);
static inline int awf_compare_theme(gconstpointer a, gconstpointer b);
static void notify_updated_gtktheme(GSettings *settings, gchar *key);
static void update_text_direction(int direction);
static void update_theme(gchar *new_theme);
static void update_statusbar(gchar *message);
static void update_values(GtkRange *range);
static void update_widgets();
static void update_marks(GtkScale *scale, gboolean value, int position);
static void display_notification();
static void find_and_update_labels(GtkWidget *widget);
static gboolean find_and_check_menuradio(GtkWidget *menu, gchar *search);
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
static void create_treview(GtkWidget *root);
static void create_scales(GtkWidget *notebook, gchar *text, int position);
static GtkWidget* create_horizontal_scale(gdouble value, gboolean draw, gboolean inverted, int position);
static GtkWidget* create_vertical_scale(gdouble value, gboolean draw, gboolean inverted, int position);
static void create_traditional_menubar(GtkWidget *root);
static GtkWidget* create_menu(GtkWidget *root, gchar *text, gboolean cca);
static GtkWidget* create_menuitem_tearoff(GtkWidget *menu);
static GtkWidget* create_menuitem_check(GtkWidget *menu, gchar *text, gboolean free, gboolean chk, gboolean ist, gboolean dsb);
static GtkWidget* create_menuitem_radio(GtkWidget *menu, gchar *text, gboolean free, gboolean chk, gboolean ist, gboolean dsb, GSList *group);
static GtkWidget* create_menuitem(GtkWidget *menu, gchar *text, gboolean dsb, gchar *accel, gchar *kmp, GCallback function);
static void accels_load();
static void accels_select(GtkWidget *widget);
static void accels_deselect(GtkWidget *widget);
static void accels_change(GtkWidget *widget, GdkEventKey *event);
static void accels_save();
static void dialog_open();
static void dialog_recent();
static void dialog_save();
static void dialog_message();
static void dialog_page_setup();
static void dialog_print();
static void dialog_about();
static void dialog_calendar();
static void dialog_scales();


// run run run

int main(int argc, gchar **argv) {

	awf_debug = (g_getenv("AWF_DEBUG") != NULL);
	awf_trace = (g_getenv("AWF_TRACE") != NULL);
	if (awf_trace)
		g_printf("» main()\n");

	current_theme = g_strdup("auto");
	opt_theme     = g_strdup("auto");

	int opt = 0, status = 0;
	hash_system_theme = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
	hash_user_theme = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
	GList *iterator = NULL;
	gchar *directory;

	// load available system themes (/usr/share/themes)
	directory = gtk_rc_get_theme_dir();
	awf_load_theme(hash_system_theme, directory);
	g_free(directory);

	g_hash_table_remove(hash_system_theme, "Default");
	g_hash_table_remove(hash_system_theme, "Emacs");
	list_system_theme = g_list_sort(g_hash_table_get_keys(hash_system_theme), (GCompareFunc) awf_compare_theme);

	// load available user themes (HOME/.themes)
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
		{"list-themes", no_argument, NULL, 'l'},
		{"theme",       required_argument, NULL, 't'},
		{"screenshot",  required_argument, NULL, 's'},
		{"ltr",         no_argument, NULL, 'y'},
		{"rtl",         no_argument, NULL, 'z'},
		{NULL, 0, NULL, 0}
	};

	gchar *c_version, *t1, *t2, *t3, *t4;
	while ((opt = getopt_long(argc, argv, "hvlt:s:xyz", options, NULL)) != -1) {
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
			// --help/x not supported by GTK 2.x
			case 'x':
			case 'h':
			default:
				#ifdef __STDC_VERSION__
					if      (__STDC_VERSION__ >= 202311L) c_version = "C23";
					else if (__STDC_VERSION__ >= 201710L) c_version = "C17";
					else if (__STDC_VERSION__ >= 201112L) c_version = "C11";
					else if (__STDC_VERSION__ >= 199901L) c_version = "C99";
					else if (__STDC_VERSION__ >= 199409L) c_version = "C95";
					else                                  c_version = "C (unknown)";
				#else
					c_version = "C89/C90";
				#endif
				g_printf("%s\n\n  %s %s\n  %s %s\n  %s %s\n  %s %s\n  %s %s\n  %s %s\n\n%s\n%s\n",
					t1 = g_strdup_printf(_app("A widget factory - GTK %d.%d"), GTK_MAJOR_VERSION, GTK_MINOR_VERSION),
					"-v            ", _app("Show version number."),
					"-l            ", _app("List available themes."),
					"-t <theme>    ", _app("Run with the specified theme."),
					"-s <filename> ", t2 = g_strdup_printf(_app("Run and save a png screenshot on %s."), "SIGHUP"),
					"--ltr         ", _app("Run with text from left to right (Left-To-Right)."),
					"--rtl         ", _app("Run with text from right to left (Right-To-Left)."),
					t3 = g_strdup_printf(_app("compiled in %s with gtk %d.%d.%d and glib %d.%d.%d and pango %s"),
						c_version,
						GTK_MAJOR_VERSION, GTK_MINOR_VERSION, GTK_MICRO_VERSION,
						GLIB_MAJOR_VERSION, GLIB_MINOR_VERSION, GLIB_MICRO_VERSION,
						PANGO_VERSION_STRING),
					t4 = g_strdup_printf(_app(" started with gtk %d.%d.%d and glib %d.%d.%d and pango %s"),
						gtk_major_version, gtk_minor_version, gtk_micro_version,
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
	gtk_init(&argc, &argv);
	create_window(NULL);

	return status;
}

static void quit() {

	if (awf_trace)
		g_printf("» quit()\n");

	g_list_free(list_system_theme);
	g_list_free(list_user_theme);
	list_system_theme = NULL;
	list_user_theme   = NULL;

	g_hash_table_destroy(hash_system_theme);
	g_hash_table_destroy(hash_user_theme);
	hash_system_theme = NULL;
	hash_user_theme   = NULL;

	accels_save();
	gtk_main_quit();
}

static void awf_load_theme(GHashTable* hashtable, gchar *directory) {

	if (awf_trace)
		g_printf("» awf_load_theme(%s)\n", directory);

	if (g_file_test(directory, G_FILE_TEST_IS_DIR)) {

		if (awf_debug)
			g_printf("themes_dir: %s\n", directory);

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

static inline int awf_compare_theme(gconstpointer a, gconstpointer b) {
	return g_ascii_strcasecmp((gchar*) a, (gchar*) b); //g_strcmp0((gchar*) a, (gchar*) b);
}

static void notify_updated_gtktheme(GSettings *settings, gchar *key) { // ok

	if (awf_trace)
		g_printf("» notify_updated_gtktheme(%s)\n", key);

	gchar *new_theme = g_settings_get_string(settings, key);
	if (awf_debug)
		g_printf("SIGNAL_theme_update: %s\n", new_theme);

	find_and_check_menuradio(menubar, new_theme);
	g_free(new_theme);
}

static void update_text_direction(int direction) { // ok

	// we must ignore the activate signal when menubar is created
	if (!allow_update_theme)
		return;

	if (awf_trace)
		g_printf("» update_text_direction()*\n");

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

static void update_theme(gchar *new_theme) { // ok

	// we must ignore the activate signal when menubar is created
	if (!allow_update_theme || !new_theme)
		return;
	// we can ignore the signal when the menuitem is deselected
	// @todo
	//	return;

	if (awf_trace)
		g_printf("» update_theme(%s)*\n", new_theme);
	if (awf_debug)
		g_printf("update_theme_before: %s » %s\n", current_theme, new_theme);

	if (strcmp(new_theme, "refresh") == 0) {

		g_object_set(gtk_settings_get_default(), "gtk-theme-name", "Default", NULL);
		g_usleep(G_USEC_PER_SEC / 2);
		g_object_set(gtk_settings_get_default(), "gtk-theme-name", current_theme, NULL);
		gtk_window_resize(GTK_WINDOW(window), 50, 50);

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
			g_printf("update_theme_after1: %s\n", current_theme);
	}
	else if (strcmp(new_theme, "auto") == 0) {

		g_free(current_theme);
		g_object_get(gtk_settings_get_default(), "gtk-theme-name", &current_theme, NULL);
		gtk_window_resize(GTK_WINDOW(window), 50, 50);

		if (awf_debug)
			g_printf("update_theme_after2: %s\n", current_theme);
	}
	else if (strcmp(new_theme, current_theme) != 0) {

		g_free(current_theme);
		g_object_set(gtk_settings_get_default(), "gtk-theme-name", new_theme, NULL); // @todo? useless for notify_updated_gtktheme
		g_object_get(gtk_settings_get_default(), "gtk-theme-name", &current_theme, NULL);

		while (gtk_events_pending())
			gtk_main_iteration();
		gtk_window_resize(GTK_WINDOW(window), 50, 50);

		gchar *text = g_strdup_printf(_app("Theme %s loaded."), current_theme);
		update_statusbar(text);
		g_free(text);

		if (awf_debug)
			g_printf("update_theme_after3: %s\n", current_theme);
	}
}

static void update_statusbar(gchar *message) { // ok

	if (awf_trace)
		g_printf("» update_statusbar(%s)\n", message);

	if (window && statusbar) {

		GDateTime *now = g_date_time_new_now_local();
		gchar *buffer  = g_date_time_format(now, "%H:%M:%S");
		g_date_time_unref(now);

		gchar *text = g_strdup_printf("%s - %s", buffer, message);
		guint ctid = gtk_statusbar_get_context_id(GTK_STATUSBAR(statusbar), "gné");
		gtk_statusbar_remove_all(GTK_STATUSBAR(statusbar), ctid);
		gtk_statusbar_push(GTK_STATUSBAR(statusbar), ctid, text);
		g_free(text);
		g_free(buffer);
	}
}

static void update_values(GtkRange *range) { // ok

	if (allow_update_values) {

		allow_update_values = FALSE;
		double value = gtk_range_get_value(range);
		//if (awf_trace)
		//	g_printf("» update_values(%f)*\n", value);

		// range(0..1)
		gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress1), value / 100.0);
		gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress2), value / 100.0);
		gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress3), value / 100.0);
		gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress4), value / 100.0);
		gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress8), value / 100.0);
		gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress9), value / 100.0);

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
		if (gtk_progress_bar_get_text(GTK_PROGRESS_BAR(progress1))) {
			gchar *text = g_strdup_printf("%i %%", (int) value);
			gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress1), text);
			gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress2), text);
			gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress3), text);
			gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress4), text);
			gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress8), (value > 50) ? text : NULL);
			gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress9), (value > 50) ? text : NULL);
			g_free(text);
		}

		allow_update_values = TRUE;
	}
}

static void update_widgets() { // ok

	if (awf_trace)
		g_printf("» update_widgets()\n");

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

	// text or not
	if (toggle) {
		gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress1), NULL);
		gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress2), NULL);
		gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress3), NULL);
		gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress4), NULL);
	}
	else {
		gchar *text = g_strdup_printf("%i %%", (int) gtk_range_get_value(GTK_RANGE(scale1)));
		gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress1), text);
		gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress2), text);
		gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress3), text);
		gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress4), text);
		g_free(text);
	}
	gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress8), NULL);
	gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress9), NULL);

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

	gtk_window_resize(GTK_WINDOW(window), 50, 50);
}

static void update_marks(GtkScale *scale, gboolean value, int position) {

	if (awf_trace)
		g_printf("» update_marks(%d)\n", position);

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

	if (awf_trace)
		g_printf("» display_notification()\n");

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
	else if (GTK_IS_CONTAINER(widget)) {
		GList *children = gtk_container_get_children(GTK_CONTAINER(widget));
		GList *iter;
		for (iter = children; iter != NULL; iter = iter->next)
			find_and_update_labels(GTK_WIDGET(iter->data));
		g_list_free(children);
	}
}

static gboolean find_and_check_menuradio(GtkWidget *menu, gchar *search) { // whynot

	if (awf_trace)
		g_printf("» find_and_check_menuradio(%s)\n", search);

	GList *children = gtk_container_get_children(GTK_CONTAINER(menu)), *iter;
	GtkWidget *item;

	for (iter = children; iter != NULL; iter = g_list_next(iter)) {

		item = GTK_WIDGET(iter->data);
		if (GTK_IS_MENU_ITEM(item)) {

			GtkWidget *submenu = gtk_menu_item_get_submenu(GTK_MENU_ITEM(item));
			if (submenu) {
				// process submenu
				if (find_and_check_menuradio(submenu, search)) {
					g_list_free(children);
					return TRUE;
				}
			}
			else if (gtk_widget_get_sensitive(item)) {
				// check menuitem by label
				const gchar *value = gtk_menu_item_get_label(GTK_MENU_ITEM(item));
				if (value && (g_strcmp0(value, search) == 0)) {
					gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(item), TRUE); // set state checked and activate action
					g_list_free(children);
					return TRUE;
				}
			}
		}
	}

	g_list_free(children);
	return FALSE;
}

static gboolean on_sighup(void *data) { // ok

	if (awf_trace)
		g_printf("» on_sighup()\n");

	update_theme("refresh");

	#if defined (G_SOURCE_CONTINUE)
		return G_SOURCE_CONTINUE;
	#else
		return TRUE; // glib < 2.32
	#endif
}

static gboolean take_screenshot() { // ok (without window borders)

	if (awf_trace)
		g_printf("» take_screenshot()\n");

	gboolean result = FALSE;
	int width = 0, height = 0;
	GdkWindow *root = gtk_widget_get_window(window);
	gtk_window_get_size(GTK_WINDOW(window), &width, &height);
	GdkPixbuf *image = gdk_pixbuf_get_from_drawable(NULL, root, gdk_colormap_get_system(), 0, 0, 0, 0, width, height);

	if (image) {
		result = gdk_pixbuf_save(image, opt_screenshot, "png", NULL, "compression", "9", NULL);
		g_object_unref(image);
	}

	return result;
}


// layout and widgets

static void create_window(gpointer app) {

	if (awf_trace)
		g_printf("» create_window()\n");

	GtkWidget *vbox_window, *widgets;
	gchar *text, *value;

	// window
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
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
	vbox_window = BOXV;
	gtk_container_add(GTK_CONTAINER(window), vbox_window);

		menubar = gtk_menu_bar_new();
		allow_update_theme = FALSE;
		create_traditional_menubar(menubar);
		add_to(vbox_window, menubar, FALSE, FALSE, 0, 0);
		allow_update_theme = TRUE;

		toolbar = gtk_toolbar_new();
		create_toolbar(toolbar);
		add_to(vbox_window, toolbar, FALSE, FALSE, 0, 0);

		widgets = BOXV;
		add_to(vbox_window, widgets, TRUE, TRUE, 0, 0);
			create_widgets(widgets);

		statusbar = gtk_statusbar_new();
		add_to(vbox_window, statusbar, FALSE, FALSE, 0, 0);

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
	#endif

	#if defined (G_OS_WIN32)
		gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	#endif

	gtk_widget_show_all(window);
	add_progressbar_and_entrybar();
	gtk_main();
}

static void create_widgets(GtkWidget *root) { // ok

	if (awf_trace)
		g_printf("» create_widgets()\n");

	GtkWidget *hbox_columns = BOXH;
	GtkWidget *vbox_column1 = BOXV, *vbox_combo_entry = BOXV, *hbox_spin = BOXH, *hbox_check_radio = BOXH, *vbox_check = BOXV, *vbox_radio = BOXV;
	GtkWidget *vbox_column2 = BOXV, *vbox_buttons = BOXV, *hbox_btns1 = BOXH, *hbox_btns2 = BOXH, *hbox_btns3 = BOXH, *hbox_btns4 = BOXH;
	GtkWidget *vbox_column3 = BOXV, *vbox_progress1 = BOXV, *vbox_progress2 = BOXV, *hbox_progress1 = BOXH, *hbox_progress2 = BOXH;
	GtkWidget *vbox_column4 = BOXV, *vbox_others = BOXV, *hbox_label = BOXH, *hbox_spinner = BOXH;
	GtkWidget *vpane = PANEV, *hpane1 = PANEH, *hpane2 = PANEH;
	GtkWidget *hbox_frame1 = BOXH, *hbox_frame2 = BOXH, *hbox_notebook1 = BOXH, *hbox_notebook2 = BOXH;

	// columns layout
	add_to(root, hbox_columns, TRUE, TRUE, 0, 0);

		// column 1
		add_to(hbox_columns, vbox_column1, TRUE, TRUE, 5, 0);
			add_to(vbox_column1, vbox_combo_entry, FALSE, TRUE, 5, 3);
				create_combos_entries(vbox_combo_entry);
			add_to(vbox_column1, hbox_spin, FALSE, FALSE, 5, 0);
				create_spinbuttons(hbox_spin);
			add_to(vbox_column1, hbox_check_radio, FALSE, TRUE, 5, 0);
				add_to(hbox_check_radio, vbox_check, TRUE, TRUE, 0, 0);
					create_checkbuttons(vbox_check);
				add_to(hbox_check_radio, vbox_radio, TRUE, TRUE, 0, 0);
					create_radiobuttons(vbox_radio);
		add_to(hbox_columns, SEPV, FALSE, FALSE, 0, 0);

		// column 2
		add_to(hbox_columns, vbox_column2, TRUE, TRUE, 5, 0);
			add_to(vbox_column2, vbox_buttons, FALSE, TRUE, 5, 3);
			add_to(vbox_column2, hbox_btns1, FALSE, FALSE, 5, 3);
			add_to(vbox_column2, hbox_btns2, FALSE, FALSE, 5, 3);
			add_to(vbox_column2, hbox_btns3, FALSE, FALSE, 5, 3);
			add_to(vbox_column2, hbox_btns4, FALSE, FALSE, 5, 3);
				create_otherbuttons(vbox_buttons, hbox_btns1, hbox_btns2, hbox_btns3, hbox_btns4);
		add_to(hbox_columns, SEPV, FALSE, FALSE, 0, 0);

		// column 3
		add_to(hbox_columns, vbox_column3, TRUE, TRUE, 5, 0);
			add_to(vbox_column3, vbox_progress1, FALSE, TRUE, 6, 10);
			add_to(vbox_column3, hbox_progress1, FALSE, FALSE, 5, 10);
			add_to(vbox_column3, hbox_progress2, FALSE, FALSE, 5, 10);
			add_to(vbox_column3, vbox_progress2, FALSE, TRUE, 5, 10);
				create_progressbars(vbox_progress1, hbox_progress1, hbox_progress2, vbox_progress2);
		add_to(hbox_columns, SEPV, FALSE, FALSE, 0, 0);

		// column 4
		add_to(hbox_columns, vbox_column4, TRUE, TRUE, 5, 0);
			add_to(vbox_column4, vbox_others, FALSE, TRUE, 5, 3);
				create_treview(vbox_others);
				add_to(vbox_others, hbox_label, FALSE, TRUE, 5, 0);
					create_labels(hbox_label);
				add_to(vbox_others, hbox_spinner, FALSE, TRUE, 5, 0);
					create_spinners(hbox_spinner);
				create_expander(vbox_others);

	add_to(root, SEPH, FALSE, FALSE, 0, 0);

	// paned layout
	add_to(root, vpane, TRUE, TRUE, 0, 0);

		gtk_paned_pack1(GTK_PANED(vpane), hpane1, TRUE, FALSE);
		gtk_widget_set_size_request(hpane1, -1, 70); // The 70

			gtk_box_set_homogeneous(GTK_BOX(hbox_frame1), TRUE);
			gtk_box_set_spacing(GTK_BOX(hbox_frame1), 3);
			gtk_container_set_border_width(GTK_CONTAINER(hbox_frame1), 10);
			gtk_paned_add1(GTK_PANED(hpane1), hbox_frame1);

			gtk_box_set_homogeneous(GTK_BOX(hbox_frame2), TRUE);
			gtk_box_set_spacing(GTK_BOX(hbox_frame2), 3);
			gtk_container_set_border_width(GTK_CONTAINER(hbox_frame2), 10);
			gtk_paned_add2(GTK_PANED(hpane1), hbox_frame2);

			create_frames(hbox_frame1, hbox_frame2);

		gtk_paned_pack2(GTK_PANED(vpane), hpane2, TRUE, FALSE);
		//gtk_widget_set_size_request(hpane2, -1, 119); // The 120

			gtk_box_set_homogeneous(GTK_BOX(hbox_notebook1), TRUE);
			gtk_box_set_spacing(GTK_BOX(hbox_notebook1), 3);
			gtk_container_set_border_width(GTK_CONTAINER(hbox_notebook1), 10);
			gtk_paned_add1(GTK_PANED(hpane2), hbox_notebook1);

			gtk_box_set_homogeneous(GTK_BOX(hbox_notebook2), TRUE);
			gtk_box_set_spacing(GTK_BOX(hbox_notebook2), 3);
			gtk_container_set_border_width(GTK_CONTAINER(hbox_notebook2), 10);
			gtk_paned_add2(GTK_PANED(hpane2), hbox_notebook2);

			create_notebooks(hbox_notebook1, hbox_notebook2);
}

static void add_progressbar_and_entrybar() {

	if (awf_trace)
		g_printf("» add_progressbar_and_entrybar()\n");

	// entry toolbar (= 11)
	toolbarentry = gtk_entry_new();
	gtk_widget_set_visible(toolbarentry, FALSE);
	gtk_container_add(GTK_CONTAINER(gtk_toolbar_get_nth_item(GTK_TOOLBAR(toolbar), 11)), toolbarentry); // end left

	// progressbar toolbar (= 13)
	progress8 = gtk_progress_bar_new();
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress8), 0);
	gtk_progress_bar_set_orientation(GTK_PROGRESS_BAR(progress8), GTK_PROGRESS_LEFT_TO_RIGHT);
	gtk_widget_set_visible(progress8, FALSE);

	GtkWidget *alignment = gtk_alignment_new(0, 0.5, 0, 0);
	gtk_widget_set_size_request(alignment, -1, 20);
	gtk_container_add(GTK_CONTAINER(alignment), progress8);
	gtk_widget_set_visible(alignment, TRUE);
	gtk_container_add(GTK_CONTAINER(gtk_toolbar_get_nth_item(GTK_TOOLBAR(toolbar), 13)), alignment); // end right

	// progressbar statusbar
	progress9 = gtk_progress_bar_new();
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress9), 0);
	gtk_progress_bar_set_orientation(GTK_PROGRESS_BAR(progress9), GTK_PROGRESS_LEFT_TO_RIGHT);
	gtk_widget_set_visible(progress9, FALSE);

	GtkStyle *style = gtk_widget_get_style(progress9);
	PangoFontDescription *desc = pango_font_description_copy(style->font_desc);
	pango_font_description_set_size(desc, 7.5 * PANGO_SCALE);
	gtk_widget_modify_font(progress9, desc);
	pango_font_description_free(desc);
	alignment = gtk_fixed_new();
	gtk_widget_set_name(progress9, "progress9");
	gtk_rc_parse_string("style \"progress9\"\n"
		"{\n"
			"GtkProgressBar::min-horizontal-bar-height = 15\n"
			"GtkProgressBar::yspacing = 0\n"
		"}\n"
		"widget \"*.progress9\" style \"progress9\"");
	gtk_fixed_put(GTK_FIXED(alignment), progress9, 0, 2);
	gtk_widget_set_visible(alignment, TRUE);
	gtk_box_pack_end(GTK_BOX(gtk_statusbar_get_message_area(GTK_STATUSBAR(statusbar))), alignment, FALSE, FALSE, 0);
}

static void add_to(GtkWidget *root, GtkWidget *widget, gboolean expand, gboolean fill, guint padding, guint spacing) { // ok

	if (GTK_IS_INFO_BAR(root))
		root = gtk_info_bar_get_content_area(GTK_INFO_BAR(root));
	if (GTK_IS_CONTAINER(widget) && (padding > 0))
		gtk_container_set_border_width(GTK_CONTAINER(widget), padding);
	if (GTK_IS_BOX(widget) && (spacing > 0))
		gtk_box_set_spacing(GTK_BOX(widget), spacing);

	gtk_box_pack_start(GTK_BOX(root), widget, expand, fill, 0);
}

static void create_toolbar(GtkWidget *root) { // ok

	if (awf_trace)
		g_printf("» create_toolbar()\n");

	GtkWidget *tool1, *menu, *tool2, *tool3, *tool4, *tool5, *tool6, *tool7, *tool8, *tool9, *tool11, *tool12, *tool13;
	// @todo option command line?
	gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);

	// GTK_MENU_TOOL_BUTTON
	tool1 = GTK_WIDGET(gtk_menu_tool_button_new(NULL, NULL));
	gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON(tool1), "document-open");
	g_signal_connect(tool1, "clicked", G_CALLBACK(dialog_open), NULL);
	menu = gtk_menu_new();
	create_menuitem(menu, "Menu item 1", FALSE, NULL, NULL, NULL);
	create_menuitem(menu, "Menu item 2", FALSE, NULL, NULL, NULL);
	create_menuitem(menu, "Menu item 3", FALSE, NULL, NULL, NULL);
	gtk_widget_show_all(menu);
	gtk_menu_tool_button_set_menu(GTK_MENU_TOOL_BUTTON(tool1), menu);

	tool2 = GTK_WIDGET(gtk_menu_tool_button_new(NULL, NULL));
	gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON(tool2), "document-open");
	gtk_widget_set_sensitive(tool2, FALSE);

	// GTK_TOOL_BUTTON
	tool3 = GTK_WIDGET(gtk_tool_button_new(NULL, NULL));
	gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON(tool3), "document-save");
	g_signal_connect(tool3, "clicked", G_CALLBACK(dialog_save), NULL);

	tool4 = GTK_WIDGET(gtk_tool_button_new(NULL, NULL));
	gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON(tool4), "view-refresh");
	g_signal_connect_swapped(tool4, "clicked", G_CALLBACK(on_sighup), NULL);

	tool5 = GTK_WIDGET(gtk_tool_button_new(NULL, NULL));
	gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON(tool5), "camera-photo");
	gtk_widget_set_sensitive(tool5, opt_screenshot ? TRUE : FALSE);
	g_signal_connect(tool5, "clicked", G_CALLBACK(take_screenshot), NULL);

	tool6 = GTK_WIDGET(gtk_tool_button_new(NULL, NULL));
	gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON(tool6), "dialog-information");
	g_signal_connect(tool6, "clicked", G_CALLBACK(display_notification), NULL);
	#if defined (G_OS_WIN32)
		gtk_widget_set_sensitive(tool6, FALSE);
	#endif

	// GTK_TOGGLE_TOOL_BUTTON
	tool7 = GTK_WIDGET(gtk_toggle_tool_button_new());
	gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON(tool7), "list-add");
	gtk_toggle_tool_button_set_active(GTK_TOGGLE_TOOL_BUTTON(tool7), TRUE);
	g_signal_connect(tool7, "clicked", G_CALLBACK(update_widgets), NULL);

	tool8 = GTK_WIDGET(gtk_toggle_tool_button_new());
	gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON(tool8), "list-remove");
	gtk_toggle_tool_button_set_active(GTK_TOGGLE_TOOL_BUTTON(tool8), FALSE);
	g_signal_connect(tool8, "clicked", G_CALLBACK(update_widgets), NULL);

	tool9 = GTK_WIDGET(gtk_toggle_tool_button_new());
	gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON(tool9), "window-close");
	gtk_toggle_tool_button_set_active(GTK_TOGGLE_TOOL_BUTTON(tool9), FALSE);
	gtk_widget_set_sensitive(tool9, FALSE);

	// placeholder & separators
	tool11 = GTK_WIDGET(gtk_tool_item_new());

	tool12 = GTK_WIDGET(gtk_tool_item_new());
	gtk_tool_item_set_expand(GTK_TOOL_ITEM(tool12), TRUE);

	tool13 = GTK_WIDGET(gtk_tool_item_new());

	// layout
	gtk_toolbar_insert(GTK_TOOLBAR(root), GTK_TOOL_ITEM(tool1), -1);
	gtk_toolbar_insert(GTK_TOOLBAR(root), GTK_TOOL_ITEM(tool2), -1);
	gtk_toolbar_insert(GTK_TOOLBAR(root), GTK_TOOL_ITEM(tool3), -1);
	gtk_toolbar_insert(GTK_TOOLBAR(root), gtk_separator_tool_item_new(), -1);
	gtk_toolbar_insert(GTK_TOOLBAR(root), GTK_TOOL_ITEM(tool4), -1);
	gtk_toolbar_insert(GTK_TOOLBAR(root), GTK_TOOL_ITEM(tool5), -1);
	gtk_toolbar_insert(GTK_TOOLBAR(root), GTK_TOOL_ITEM(tool6), -1);
	gtk_toolbar_insert(GTK_TOOLBAR(root), gtk_separator_tool_item_new(), -1);
	gtk_toolbar_insert(GTK_TOOLBAR(root), GTK_TOOL_ITEM(tool7), -1);
	gtk_toolbar_insert(GTK_TOOLBAR(root), GTK_TOOL_ITEM(tool8), -1);
	gtk_toolbar_insert(GTK_TOOLBAR(root), GTK_TOOL_ITEM(tool9), -1);
	gtk_toolbar_insert(GTK_TOOLBAR(root), GTK_TOOL_ITEM(tool11), -1); // = 11
	gtk_toolbar_insert(GTK_TOOLBAR(root), GTK_TOOL_ITEM(tool12), -1);
	gtk_toolbar_insert(GTK_TOOLBAR(root), GTK_TOOL_ITEM(tool13), -1); // = 13
}

static void create_combos_entries(GtkWidget *root) { // ok

	if (awf_trace)
		g_printf("» create_combos_entries()\n");

	GtkWidget *combo1, *combo2, *combo3, *combo4, *entry1, *entry2, *entry3, *entry4;

	// GTK_COMBO_BOX
	combo1 = gtk_combo_box_text_new_with_entry();
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo1), "Combo box entry 1");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo1), "Combo box entry 2");
	gtk_combo_box_set_active(GTK_COMBO_BOX(combo1), 0);

	combo2 = gtk_combo_box_text_new_with_entry();
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo2), "Combo box entry 1");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo2), "Combo box entry 2");
	gtk_combo_box_set_active(GTK_COMBO_BOX(combo2), 0);
	gtk_widget_set_sensitive(combo2, FALSE);

	combo3 = gtk_combo_box_text_new();
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo3), "Combo box 1");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo3), "Combo box 2");
	gtk_combo_box_set_active(GTK_COMBO_BOX(combo3), 0);

	combo4 = gtk_combo_box_text_new();
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo4), "Combo box 1");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo4), "Combo box 2");
	gtk_combo_box_set_active(GTK_COMBO_BOX(combo4), 0);
	gtk_widget_set_sensitive(combo4, FALSE);

	// GTK_ENTRY
	entry1 = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(entry1), "Entry");

	entry2 = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(entry2), "Entry");
	gtk_widget_set_sensitive(entry2, FALSE);

	entry3 = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(entry3), "Entry");
	gtk_entry_set_icon_from_icon_name(GTK_ENTRY(entry3), GTK_ENTRY_ICON_PRIMARY, "edit-clear");
	gtk_entry_set_icon_from_icon_name(GTK_ENTRY(entry3), GTK_ENTRY_ICON_SECONDARY, "edit-find");

	entry4 = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(entry4), "Entry");
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

static void create_spinbuttons(GtkWidget *root) { // ok

	if (awf_trace)
		g_printf("» create_spinbuttons()\n");

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

static void create_checkbuttons(GtkWidget *root) { // ok

	if (awf_trace)
		g_printf("» create_checkbuttons()\n");

	GtkWidget *checkbutton1, *checkbutton2, *checkbutton3, *checkbutton4, *checkbutton5, *checkbutton6;

	// GTK_CHECK_BUTTON
	checkbutton1 = gtk_check_button_new_with_label("Check btn 1");

	checkbutton2 = gtk_check_button_new_with_label("Check btn 2");
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbutton2), TRUE);

	checkbutton3 = gtk_check_button_new_with_label("Check btn 3");
	gtk_toggle_button_set_inconsistent(GTK_TOGGLE_BUTTON(checkbutton3), TRUE);

	checkbutton4 = gtk_check_button_new_with_label("Check btn 4");
	gtk_widget_set_sensitive(checkbutton4, FALSE);

	checkbutton5 = gtk_check_button_new_with_label("Check btn 5");
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbutton5), TRUE);
	gtk_widget_set_sensitive(checkbutton5, FALSE);

	checkbutton6 = gtk_check_button_new_with_label("Check btn 6");
	gtk_toggle_button_set_inconsistent(GTK_TOGGLE_BUTTON(checkbutton6), TRUE);
	gtk_widget_set_sensitive(checkbutton6, FALSE);

	// layout
	add_to(root, checkbutton1, FALSE, FALSE, 0, 0);
	add_to(root, checkbutton2, FALSE, FALSE, 0, 0);
	add_to(root, checkbutton3, FALSE, FALSE, 0, 0);
	add_to(root, checkbutton4, FALSE, FALSE, 0, 0);
	add_to(root, checkbutton5, FALSE, FALSE, 0, 0);
	add_to(root, checkbutton6, FALSE, FALSE, 0, 0);
}

static void create_radiobuttons(GtkWidget *root) { // ok

	if (awf_trace)
		g_printf("» create_radiobuttons()\n");

	GtkWidget *radiobutton1, *radiobutton2, *radiobutton3, *radiobutton4, *radiobutton5, *radiobutton6;

	// GTK_RADIO_BUTTON
	radiobutton1 = gtk_radio_button_new_with_label(NULL, "Radio btn 1");

	radiobutton2 = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(radiobutton1)), "Radio btn 2");
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton2), TRUE);

	radiobutton3 = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(radiobutton1)), "Radio btn 3");
	gtk_toggle_button_set_inconsistent(GTK_TOGGLE_BUTTON(radiobutton3), TRUE);

	radiobutton4 = gtk_radio_button_new_with_label(NULL, "Radio btn 4");
	gtk_widget_set_sensitive(radiobutton4, FALSE);

	radiobutton5 = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(radiobutton4)), "Radio btn 5");
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton5), TRUE);
	gtk_widget_set_sensitive(radiobutton5, FALSE);

	radiobutton6 = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(radiobutton4)), "Radio btn 6");
	gtk_toggle_button_set_inconsistent(GTK_TOGGLE_BUTTON(radiobutton6), TRUE);
	gtk_widget_set_sensitive(radiobutton6, FALSE);

	// layout
	add_to(root, radiobutton1, FALSE, FALSE, 0, 0);
	add_to(root, radiobutton2, FALSE, FALSE, 0, 0);
	add_to(root, radiobutton3, FALSE, FALSE, 0, 0);
	add_to(root, radiobutton4, FALSE, FALSE, 0, 0);
	add_to(root, radiobutton5, FALSE, FALSE, 0, 0);
	add_to(root, radiobutton6, FALSE, FALSE, 0, 0);
}

static void create_otherbuttons(GtkWidget *root1, GtkWidget *root2, GtkWidget *root3, GtkWidget *root4, GtkWidget *root5) { // ok

	if (awf_trace)
		g_printf("» create_otherbuttons()\n");

	GtkWidget *button1, *button2, *button3, *button4, *button5, *button6, *button7, *button8, *button9;
	GtkWidget *button10, *button11, *button12, *button13, *button14;
	GtkWidget *combomenu1, *combomenu2, *combomenu3, *combomenu4;

	// GTK_BUTTON
	button1 = gtk_button_new_with_label("Button 1");

	button2 = gtk_button_new_with_label("Button 2");
	gtk_widget_set_sensitive(button2, FALSE);

	button3 = gtk_toggle_button_new_with_label("Button 3");
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(button3), TRUE);

	button4 = gtk_toggle_button_new_with_label("Button 4");
	gtk_widget_set_sensitive(button4, FALSE);

	// GTK_COLOR_BUTTON
	GdkColor color;
	gdk_color_parse("#7796ba", &color);
	button5 = gtk_color_button_new_with_color(&color);
	gtk_widget_set_tooltip_text(button5, _app("Choose a color"));

	// GTK_FONT_BUTTON
	button6 = gtk_font_button_new();
	find_and_update_labels(button6);
	gtk_widget_set_size_request(button6, 186, -1); // The 186
	gtk_widget_set_tooltip_text(button6, _app("Choose a font"));

	// GTK_FILE_CHOOSER_BUTTON
	button7 = gtk_file_chooser_button_new("GtkFileChooserDialog:Open", GTK_FILE_CHOOSER_ACTION_OPEN);
	find_and_update_labels(button7);
	gtk_widget_set_size_request(button7, 180, -1); // The 186
	gtk_widget_set_tooltip_text(button7, _app("Choose a file"));

	button8 = gtk_file_chooser_button_new("GtkFileChooserDialog:Open", GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER);
	find_and_update_labels(button8);
	gtk_widget_set_size_request(button8, 180, -1); // The 186
	gtk_widget_set_tooltip_text(button8, _app("Choose a folder"));
	// @todo < 3.8 not null

	// GTK_OPTION_MENU
	combomenu1 = gtk_menu_new();
	gtk_menu_shell_append(GTK_MENU_SHELL(combomenu1), gtk_menu_item_new_with_label("Option 1"));
	gtk_menu_shell_append(GTK_MENU_SHELL(combomenu1), gtk_menu_item_new_with_label("Option 2"));
	gtk_menu_shell_append(GTK_MENU_SHELL(combomenu1), gtk_menu_item_new_with_label("Option 3"));
	button9 = gtk_option_menu_new();
	gtk_option_menu_set_menu(GTK_OPTION_MENU(button9), combomenu1);

	combomenu2 = gtk_menu_new();
	gtk_menu_shell_append(GTK_MENU_SHELL(combomenu2), gtk_menu_item_new_with_label("Option 1"));
	gtk_menu_shell_append(GTK_MENU_SHELL(combomenu2), gtk_menu_item_new_with_label("Option 2"));
	gtk_menu_shell_append(GTK_MENU_SHELL(combomenu2), gtk_menu_item_new_with_label("Option 3"));
	button10 = gtk_option_menu_new();
	gtk_option_menu_set_menu(GTK_OPTION_MENU(button10), combomenu2);
	gtk_widget_set_sensitive(button10, FALSE);

	combomenu3 = gtk_menu_new();
	gtk_menu_shell_append(GTK_MENU_SHELL(combomenu3), gtk_menu_item_new_with_label("Option 1"));
	gtk_menu_shell_append(GTK_MENU_SHELL(combomenu3), gtk_menu_item_new_with_label("Option 2"));
	gtk_menu_shell_append(GTK_MENU_SHELL(combomenu3), gtk_menu_item_new_with_label("Option 3"));
	button11 = gtk_option_menu_new();
	gtk_option_menu_set_menu(GTK_OPTION_MENU(button11), combomenu3);

	combomenu4 = gtk_menu_new();
	gtk_menu_shell_append(GTK_MENU_SHELL(combomenu4), gtk_menu_item_new_with_label("Option 1"));
	gtk_menu_shell_append(GTK_MENU_SHELL(combomenu4), gtk_menu_item_new_with_label("Option 2"));
	gtk_menu_shell_append(GTK_MENU_SHELL(combomenu4), gtk_menu_item_new_with_label("Option 3"));
	button12 = gtk_option_menu_new();
	gtk_option_menu_set_menu(GTK_OPTION_MENU(button12), combomenu4);
	gtk_widget_set_sensitive(button12, FALSE);

	// GTK_LINK_BUTTON
	button13 = gtk_link_button_new_with_label("https://github.com/luigifab/awf-extended", "Link button");

	button14 = gtk_link_button_new_with_label("https://github.com/luigifab/awf-extended", "Link button");
	gtk_widget_set_sensitive(button14, FALSE);

	// GTK_VOLUME_BUTTON
	button15 = gtk_volume_button_new();
	gtk_scale_button_set_value(GTK_SCALE_BUTTON(button15), 0.5);
	g_object_set((GObject*) button15, "size", GTK_ICON_SIZE_BUTTON, NULL); // @todo not working with Ubuntu

	button16 = gtk_volume_button_new();
	gtk_scale_button_set_value(GTK_SCALE_BUTTON(button16), 0);
	gtk_widget_set_sensitive(button16, FALSE);
	g_object_set((GObject*) button16, "size", GTK_ICON_SIZE_BUTTON, NULL); // @todo not working with Ubuntu

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
}

static void create_progressbars(GtkWidget *root1, GtkWidget *root2, GtkWidget *root3, GtkWidget *root4) { // ok

	if (awf_trace)
		g_printf("» create_progressbars()\n");

	// GTK_PROGRESS_BAR
	progress1 = gtk_progress_bar_new();
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress1), 0.5);
	gtk_progress_bar_set_orientation(GTK_PROGRESS_BAR(progress1), GTK_PROGRESS_LEFT_TO_RIGHT);

	progress2 = gtk_progress_bar_new();
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress2), 0.5);
	gtk_progress_bar_set_orientation(GTK_PROGRESS_BAR(progress2), GTK_PROGRESS_RIGHT_TO_LEFT);

	progress3 = gtk_progress_bar_new();
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress3), 0.5);
	gtk_progress_bar_set_orientation(GTK_PROGRESS_BAR(progress3), GTK_PROGRESS_TOP_TO_BOTTOM);
	gtk_widget_set_size_request(progress3, -1, 100); // The 100

	progress4 = gtk_progress_bar_new();
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress4), 0.5);
	gtk_progress_bar_set_orientation(GTK_PROGRESS_BAR(progress4), GTK_PROGRESS_BOTTOM_TO_TOP);

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

	// layout
	add_to(root1, progress1, FALSE, FALSE, 0, 0);
	add_to(root1, progress2, FALSE, FALSE, 0, 0);
	add_to(root1, scale1, FALSE, FALSE, 0, 0);
	add_to(root1, scale2, FALSE, FALSE, 0, 0);
	add_to(root2, progress3, FALSE, FALSE, 0, 0);
	add_to(root2, progress4, FALSE, FALSE, 0, 0);
	add_to(root3, scale3, FALSE, FALSE, 0, 0);
	add_to(root3, scale5, FALSE, FALSE, 0, 0);
	add_to(root3, scale6, FALSE, FALSE, 0, 0);
	add_to(root3, scale4, FALSE, FALSE, 0, 0);
}

static void create_labels(GtkWidget *root) { // ok

	if (awf_trace)
		g_printf("» create_labels()\n");

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

static void create_spinners(GtkWidget *root) { // ok

	if (awf_trace)
		g_printf("» create_spinners()\n");

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

static void create_expander(GtkWidget *root) { // ok

	if (awf_trace)
		g_printf("» create_expander()\n");

	GtkWidget *expander, *scrolled_window, *tv;
	GtkTextBuffer *buffer;
	gchar *text;

	// GTK_EXPANDER
	expander = gtk_expander_new(_app("More..."));
	gtk_expander_set_expanded(GTK_EXPANDER(expander), TRUE);

	// GTK_SCROLLED_WINDOW
	scrolled_window = gtk_scrolled_window_new(NULL, NULL);
	gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scrolled_window), GTK_SHADOW_IN);
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
	gtk_widget_set_size_request(scrolled_window, -1, 120);

	tv = gtk_text_view_new();
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(tv), GTK_WRAP_WORD);
	text = g_strdup_printf("%s %s", _app("A widget factory is a theme preview application for GTK and Qt. It displays the various widget types in a single window allowing to see the visual effect of the applied theme."), _app("A widget factory is a theme preview application for GTK and Qt. It displays the various widget types in a single window allowing to see the visual effect of the applied theme."));
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(tv));
	gtk_text_buffer_set_text(GTK_TEXT_BUFFER(buffer), text, -1);
	g_free(text);

	// layout
	gtk_container_add(GTK_CONTAINER(scrolled_window), tv);
	gtk_container_add(GTK_CONTAINER(expander), scrolled_window);
	add_to(root, expander, FALSE, FALSE, 0, 0);
}

static void create_frames(GtkWidget *root1, GtkWidget *root2) { // ok

	if (awf_trace)
		g_printf("» create_frames()\n");

	GtkWidget *frame1, *frame2, *frame3, *frame4;

	// GTK_FRAME
	frame1 = gtk_frame_new("Frame (shadow in)");
	gtk_frame_set_shadow_type(GTK_FRAME(frame1), GTK_SHADOW_IN);

	frame2 = gtk_frame_new("Frame (shadow out)");
	gtk_frame_set_shadow_type(GTK_FRAME(frame2), GTK_SHADOW_OUT);

	frame3 = gtk_frame_new("Frame (shadow etched in)");
	gtk_frame_set_shadow_type(GTK_FRAME(frame3), GTK_SHADOW_ETCHED_IN);

	frame4 = gtk_frame_new("Frame (shadow etched out)");
	gtk_frame_set_shadow_type(GTK_FRAME(frame4), GTK_SHADOW_ETCHED_OUT);
	gtk_widget_set_sensitive(frame4, FALSE);

	// layout
	add_to(root1, frame1, TRUE, TRUE, 0, 0);
	add_to(root1, frame2, TRUE, TRUE, 0, 0);
	add_to(root2, frame3, TRUE, TRUE, 0, 0);
	add_to(root2, frame4, TRUE, TRUE, 0, 0);
}

static void create_notebooks(GtkWidget *root1, GtkWidget *root2) { // ok

	if (awf_trace)
		g_printf("» create_notebooks()\n");

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

static void create_notebook_tab(GtkWidget *notebook, gchar *text, GtkWidget *content, gboolean close) { // ok

	GtkWidget *headbtn = BOXH, *btn;
	add_to(headbtn, gtk_label_new(text), TRUE, TRUE, 0, 0);

	// GTK_BUTTON
	if (close) {
		btn = gtk_button_new();
		gtk_button_set_image(GTK_BUTTON(btn), gtk_image_new_from_icon_name("window-close", GTK_ICON_SIZE_MENU));
		gtk_button_set_relief(GTK_BUTTON(btn), GTK_RELIEF_NONE);
		gtk_widget_set_name(btn, "close-button");
		gtk_rc_parse_string("style \"close-button\"\n"
			"{\n"
				"GtkWidget::focus-padding = 0\n"
				"GtkWidget::focus-line-width = 0\n"
				"xthickness = 0\n"
				"ythickness = 0\n"
			"}\n"
			"widget \"*.close-button\" style \"close-button\"");
		gtk_button_set_focus_on_click(GTK_BUTTON(btn), FALSE);
		add_to(headbtn, btn, FALSE, FALSE, 0, 0);
	}

	if (!content)
		content = BOXV;

	gtk_widget_show_all(headbtn);
	gtk_notebook_append_page(GTK_NOTEBOOK(notebook), content, headbtn);
	gtk_notebook_set_tab_reorderable(GTK_NOTEBOOK(notebook), content, TRUE);
}

static void create_treview(GtkWidget *root) { // ok

	if (awf_trace)
		g_printf("» create_treview()\n");

	GtkWidget *scrolled_window, *view;
	GtkCellRenderer *renderer;
	GtkTreeStore *store;
	GtkTreeIter iter;
	int idx = 0;

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

	// colors for lines
	gtk_tree_view_set_rules_hint(GTK_TREE_VIEW(view), TRUE);

	// scrolled window
	scrolled_window = gtk_scrolled_window_new(NULL, NULL);
	gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scrolled_window), GTK_SHADOW_IN);

	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_ALWAYS, GTK_POLICY_ALWAYS);
	gtk_widget_set_size_request(scrolled_window, 200, 200); // The 200
	gtk_widget_set_size_request(view, 200, 200); // The 200

	gtk_container_add(GTK_CONTAINER(scrolled_window), view);
	add_to(root, scrolled_window, FALSE, FALSE, 0, 0);
}

static void create_scales(GtkWidget *notebook, gchar *text, int position) {

	if (awf_trace)
		g_printf("» create_scales()\n");

	GtkWidget *hbox = BOXH;
	GtkWidget *vbox1 = BOXV, *vbox2 = BOXV, *vbox3 = BOXV, *hboxa = BOXH, *hboxb = BOXH;
	GtkWidget *scale1v, *scale2v, *scale3v, *scale4v, *scale5v, *scale6v, *scale7v, *scale8v, *scale9v, *scale10v, *scale11v, *scale12v;
	GtkWidget *scale1h, *scale2h, *scale3h, *scale4h, *scale5h, *scale6h, *scale7h, *scale8h, *scale9h, *scale10h, *scale11h, *scale12h;
	gdouble value = gtk_range_get_value(GTK_RANGE(scale1));

	gtk_container_set_border_width(GTK_CONTAINER(hbox), 12);

	// vertical scales
	scale1v = create_vertical_scale(value, FALSE, FALSE, position);

	scale2v = create_vertical_scale(value, FALSE, FALSE, position);
	update_marks(GTK_SCALE(scale2v), FALSE, GTK_POS_LEFT);

	scale3v = create_vertical_scale(value, FALSE, FALSE, position);
	update_marks(GTK_SCALE(scale3v), TRUE, GTK_POS_LEFT);

	scale4v = create_vertical_scale(value, TRUE, FALSE, position);

	scale5v = create_vertical_scale(value, TRUE, FALSE, position);
	update_marks(GTK_SCALE(scale5v), FALSE, GTK_POS_LEFT);

	scale6v = create_vertical_scale(value, TRUE, FALSE, position);
	update_marks(GTK_SCALE(scale6v), TRUE, GTK_POS_LEFT);

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

static GtkWidget* create_horizontal_scale(gdouble value, gboolean draw, gboolean inverted, int position) { // ok

	if (awf_trace)
		g_printf("» create_horizontal_scale()\n");

	GtkWidget *scale;

	scale = gtk_hscale_new_with_range(0, 100, 1);
	gtk_range_set_value(GTK_RANGE(scale), value);
	gtk_scale_set_draw_value(GTK_SCALE(scale), draw);
	gtk_scale_set_value_pos(GTK_SCALE(scale), position);
	gtk_range_set_inverted(GTK_RANGE(scale), inverted);
	gtk_widget_set_size_request(scale, 186, -1); // The 186

	return scale;
}

static GtkWidget* create_vertical_scale(gdouble value, gboolean draw, gboolean inverted, int position) { // ok

	if (awf_trace)
		g_printf("» create_vertical_scale()\n");

	GtkWidget *scale;

	scale = gtk_vscale_new_with_range(0, 100, 1);
	gtk_scale_set_value_pos(GTK_SCALE(scale), position);
	gtk_range_set_inverted(GTK_RANGE(scale), inverted);
	gtk_scale_set_draw_value(GTK_SCALE(scale), draw);
	gtk_range_set_value(GTK_RANGE(scale), value);
	gtk_widget_set_size_request(scale, -1, 100); // The 100

	return scale;
}


// traditional menu - common gtk2/3 except one line

static void create_traditional_menubar(GtkWidget *root) {

	if (awf_trace)
		g_printf("» create_traditional_menubar()\n");

	GtkWidget *menu, *submenu, *menuitem, *base;
	GtkAccelGroup *accels = gtk_accel_group_new();
	GSList *group = NULL;
	GList *iterator;
	gboolean ok = FALSE;

	gtk_window_add_accel_group(GTK_WINDOW(window), accels);

	// options
	menu = create_menu(root, _app("_Options"), TRUE);
	gtk_menu_set_accel_group(GTK_MENU(menu), accels); // very important

		// @todo option command line?
		if (g_getenv("AWF_TEAROFF") != NULL)
			create_menuitem_tearoff(menu);

		create_menuitem(menu, "gtk-open", FALSE, AWF_ACCEL_OPEN, AWF_OPEN, dialog_open);
		create_menuitem(menu, _app("Open recent file"), FALSE, AWF_ACCEL_RECE, AWF_RECE, dialog_recent);
		create_menuitem(menu, "gtk-save", FALSE, AWF_ACCEL_SAVE, AWF_SAVE, dialog_save);
		create_menuitem(menu, "gtk-refresh", FALSE, AWF_ACCEL_REFR, AWF_REFR, G_CALLBACK(on_sighup)); // G_CALLBACK(update_theme)
		create_menuitem(menu, _app("Calendar"), FALSE, AWF_ACCEL_CALE, AWF_CALE, dialog_calendar);
		create_menuitem(menu, "GtkScales", FALSE, AWF_ACCEL_SCAL, AWF_SCAL, dialog_scales);
		create_menuitem(menu, "gtk-properties", FALSE, AWF_ACCEL_PROP, AWF_PROP, dialog_message);
		create_menuitem(menu, "gtk-page-setup", FALSE, AWF_ACCEL_PRSE, AWF_PRSE, dialog_page_setup);
		create_menuitem(menu, "gtk-print", FALSE, AWF_ACCEL_PRIN, AWF_PRIN, dialog_print);

		submenu = create_menu(menu, _app("More..."), TRUE);
		gtk_menu_set_accel_group(GTK_MENU(submenu), accels); // very important

			create_menuitem(submenu, "gtk-cut", FALSE, AWF_ACCEL_MCUT, AWF_MCUT, NULL);
			create_menuitem(submenu, "gtk-copy", FALSE, AWF_ACCEL_MCOP, AWF_MCOP, NULL);
			create_menuitem(submenu, "gtk-paste", FALSE, AWF_ACCEL_MPAS, AWF_MPAS, NULL);

		menuitem = gtk_separator_menu_item_new();
		gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);

			create_menuitem_check(menu, g_strdup_printf("Check 1 %s", _app("(unchecked)")), TRUE, FALSE, FALSE, FALSE);
			create_menuitem_check(menu, g_strdup_printf("Check 2 %s", _app("(checked)")), TRUE, TRUE, FALSE, FALSE);
			create_menuitem_check(menu, g_strdup_printf("Check 3 %s", _app("(inconsistent)")), TRUE, FALSE, TRUE, FALSE);

			create_menuitem_check(menu, g_strdup_printf("Check 1 %s", _app("(unchecked)")), TRUE, FALSE, FALSE, TRUE);
			create_menuitem_check(menu, g_strdup_printf("Check 2 %s", _app("(checked)")), TRUE, TRUE, FALSE, TRUE);
			create_menuitem_check(menu, g_strdup_printf("Check 3 %s", _app("(inconsistent)")), TRUE, FALSE, TRUE, TRUE);

		menuitem = gtk_separator_menu_item_new();
		gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);

			menuitem = create_menuitem_radio(menu, g_strdup_printf("Radio 1 %s", _app("(unchecked)")), TRUE, FALSE, FALSE, FALSE, NULL);
			group = gtk_radio_menu_item_get_group(GTK_RADIO_MENU_ITEM(menuitem));
				create_menuitem_radio(menu, g_strdup_printf("Radio 2 %s", _app("(checked)")), TRUE, TRUE, FALSE, FALSE, group);
				create_menuitem_radio(menu, g_strdup_printf("Radio 3 %s", _app("(inconsistent)")), TRUE, FALSE, TRUE, FALSE, NULL);

			menuitem = create_menuitem_radio(menu, g_strdup_printf("Radio 1 %s", _app("(unchecked)")), TRUE, FALSE, FALSE, TRUE, NULL);
			group = gtk_radio_menu_item_get_group(GTK_RADIO_MENU_ITEM(menuitem));
				create_menuitem_radio(menu, g_strdup_printf("Radio 2 %s", _app("(checked)")), TRUE, TRUE, FALSE, TRUE, group);
				create_menuitem_radio(menu, g_strdup_printf("Radio 3 %s", _app("(inconsistent)")), TRUE, FALSE, TRUE, TRUE, NULL);

		menuitem = gtk_separator_menu_item_new();
		gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);

			create_menuitem(menu, "gtk-close", TRUE, AWF_ACCEL_CLOS, AWF_CLOS, NULL);
			create_menuitem(menu, "gtk-quit", FALSE, AWF_ACCEL_QUIT, AWF_QUIT, quit);

	// system themes
	group = NULL;
	menu  = create_menu(root, _app("_System themes"), FALSE);
	for (iterator = list_system_theme; iterator; iterator = iterator->next) {

		if (
			(strcmp((gchar*) iterator->data, "Mint-L") == 0) ||
			(strcmp((gchar*) iterator->data, "Mint-X") == 0) ||
			(strcmp((gchar*) iterator->data, "Mint-Y") == 0) ||
			(strcmp((gchar*) iterator->data, "Yaru") == 0) ||
			(strcmp((gchar*) iterator->data, "Sucharu") == 0)
		) {
			submenu = create_menu(menu, iterator->data, FALSE);
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

		if (g_hash_table_lookup(hash_user_theme, iterator->data)) {
			menuitem = create_menuitem_radio(base, iterator->data, FALSE, FALSE, FALSE, TRUE, group);
			group = gtk_radio_menu_item_get_group(GTK_RADIO_MENU_ITEM(menuitem));
			if (strcmp(current_theme, (gchar*) iterator->data) == 0)
				gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menuitem), TRUE);
			g_signal_connect_swapped(menuitem, "activate", G_CALLBACK(update_theme), iterator->data);
		}
		else {
			menuitem = create_menuitem_radio(base, iterator->data, FALSE, FALSE, FALSE, FALSE, group);
			group = gtk_radio_menu_item_get_group(GTK_RADIO_MENU_ITEM(menuitem));
			if (strcmp(current_theme, (gchar*) iterator->data) == 0)
				gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menuitem), TRUE);
			g_signal_connect_swapped(menuitem, "activate", G_CALLBACK(update_theme), iterator->data);
		}
	}

	if (!list_system_theme)
		create_menuitem(menu, _app("No themes found"), TRUE, NULL, NULL, NULL);

	// user themes
	menu = create_menu(root, _app("_User themes"), FALSE);
	for (iterator = list_user_theme; iterator; iterator = iterator->next) {

		if (
			(strcmp((gchar*) iterator->data, "Mint-L") == 0) ||
			(strcmp((gchar*) iterator->data, "Mint-X") == 0) ||
			(strcmp((gchar*) iterator->data, "Mint-Y") == 0) ||
			(strcmp((gchar*) iterator->data, "Yaru") == 0) ||
			(strcmp((gchar*) iterator->data, "Sucharu") == 0)
		) {
			submenu = create_menu(menu, iterator->data, FALSE);
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

		menuitem = create_menuitem_radio(base, iterator->data, FALSE, FALSE, FALSE, FALSE, group);
		group = gtk_radio_menu_item_get_group(GTK_RADIO_MENU_ITEM(menuitem));
		if (strcmp(current_theme, (gchar*) iterator->data) == 0)
			gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menuitem), TRUE);
		g_signal_connect_swapped(menuitem, "activate", G_CALLBACK(update_theme), iterator->data);
	}

	if (!list_user_theme)
		create_menuitem(menu, _app("No themes found"), TRUE, NULL, NULL, NULL);

	// text direction
	group = NULL;
	menu  = create_menu(root, _app("_Text direction"), FALSE);

		menuitem = create_menuitem_radio(menu, _app("Left to Right (LTR)"), FALSE, FALSE, FALSE, FALSE, group);
		if (current_direction == 1)
			gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menuitem), TRUE);
		g_signal_connect_swapped(menuitem, "activate", G_CALLBACK(update_text_direction), GINT_TO_POINTER(GTK_TEXT_DIR_LTR));
		group = gtk_radio_menu_item_get_group(GTK_RADIO_MENU_ITEM(menuitem));

		menuitem = create_menuitem_radio(menu, _app("Right to Left (RTL)"), FALSE, FALSE, FALSE, FALSE, group);
		if (current_direction == 2)
			gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menuitem), TRUE);
		g_signal_connect_swapped(menuitem, "activate", G_CALLBACK(update_text_direction), GINT_TO_POINTER(GTK_TEXT_DIR_RTL));

	// help
	menu = create_menu(root, _app("_Help"), TRUE);
	gtk_menu_set_accel_group(GTK_MENU(menu), accels); // very important

		gtk_widget_set_sensitive(create_menuitem(menu, "GtkInspector", FALSE, AWF_ACCEL_INSP, AWF_INSP, NULL), FALSE);
		create_menuitem(menu, "gtk-about", FALSE, AWF_ACCEL_ABOU, AWF_ABOU, dialog_about);

	// gtk-can-change-accels for GTK 2.24 | so same GTK 2.24 3.x 4.x & Qt 5.x 6.x
	accels_load();
	g_object_set(gtk_settings_get_default(), "gtk-can-change-accels", FALSE, NULL);
	g_object_unref(accels);
}

static GtkWidget* create_menu(GtkWidget *root, gchar *text, gboolean cca) {

	if (awf_trace)
		g_printf("» create_menu(%s)\n", text);

	GtkWidget *menu, *menuitem;

	menu = gtk_menu_new();
	menuitem = gtk_menu_item_new_with_mnemonic(text);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuitem), menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(root), menuitem);

	if (cca) {
		// gtk-can-change-accels for GTK 2.24 | so same GTK 2.24 3.x 4.x & Qt 5.x 6.x
		gtk_widget_set_events(menu, GDK_KEY_RELEASE_MASK);
		g_signal_connect(menu, "key-release-event", G_CALLBACK(accels_change), NULL);
	}

	return menu;
}

static GtkWidget* create_menuitem_tearoff(GtkWidget *menu) {

	if (awf_trace)
		g_printf("» create_menuitem_tearoff()\n");

	GtkWidget *menuitem;

	menuitem = gtk_tearoff_menu_item_new();
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);

	return menuitem;
}

static GtkWidget* create_menuitem_check(GtkWidget *menu, gchar *text, gboolean free, gboolean chk, gboolean ist, gboolean dsb) {

	if (awf_trace)
		g_printf("» create_menuitem_check(%s)\n", text);

	GtkWidget *menuitem;

	menuitem = gtk_check_menu_item_new_with_mnemonic(text);
	gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menuitem), chk);
	gtk_check_menu_item_set_inconsistent(GTK_CHECK_MENU_ITEM(menuitem), ist);
	gtk_widget_set_sensitive(menuitem, !dsb);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);

	if (free)
		g_free(text);

	return menuitem;
}

static GtkWidget* create_menuitem_radio(GtkWidget *menu, gchar *text, gboolean free, gboolean chk, gboolean ist, gboolean dsb, GSList *group) {

	if (awf_trace)
		g_printf("» create_menuitem_radio(%s)\n", text);

	GtkWidget *menuitem;

	menuitem = gtk_radio_menu_item_new_with_mnemonic(group, text);
	gtk_check_menu_item_set_inconsistent(GTK_CHECK_MENU_ITEM(menuitem), ist);
	gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menuitem), chk);
	gtk_widget_set_sensitive(menuitem, !dsb);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);

	if (free)
		g_free(text);

	return menuitem;
}

static GtkWidget* create_menuitem(GtkWidget *menu, gchar *text, gboolean dsb, gchar *accel, gchar *kmp, GCallback function) {

	if (awf_trace)
		g_printf("» create_menuitem(%s)\n", text);

	GtkWidget *menuitem;
	GdkModifierType mods;
	guint key;

	if (g_str_has_prefix(text, "gtk-"))
		menuitem = gtk_image_menu_item_new_from_stock(text, NULL);
	else
		menuitem = gtk_image_menu_item_new_with_mnemonic(text);

	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);
	gtk_widget_set_sensitive(menuitem, !dsb);

	if (accel && kmp) {
		gtk_accelerator_parse(accel, &key, &mods);
		gtk_accel_map_add_entry(kmp, key, mods);
	}

	if (kmp) {
		gtk_menu_item_set_accel_path(GTK_MENU_ITEM(menuitem), kmp);
		// gtk-can-change-accels for GTK 2.24 | so same GTK 2.24 3.x 4.x & Qt 5.x 6.x
		g_signal_connect(menuitem, "select", G_CALLBACK(accels_select), NULL);
		g_signal_connect(menuitem, "deselect", G_CALLBACK(accels_deselect), NULL);
	}

	if (function)
		g_signal_connect(menuitem, "activate", function, NULL);

	return menuitem;
}

static void accels_load() { // ok

	if (awf_trace)
		g_printf("» accels_load()\n");

	gchar *old_path = g_build_filename(g_get_home_dir(), ".awf-gtk-accels", NULL);
	if (g_file_test(old_path, G_FILE_TEST_EXISTS)) {
		gchar *new_path = g_build_filename(g_get_home_dir(), ".awf-accels", NULL);
		g_rename(old_path, new_path);
		g_free(new_path);
	}
	g_free(old_path);

	// gtk-can-change-accels for GTK 2.24 | so same GTK 2.24 3.x 4.x & Qt 5.x 6.x
	gchar *path = g_build_filename(g_get_home_dir(), ".awf-accels", NULL);
	if (g_file_test(path, G_FILE_TEST_IS_REGULAR))
		gtk_accel_map_load(path);
	g_free(path);
}

static void accels_select(GtkWidget *widget) { // ok

	// gtk-can-change-accels for GTK 2.24 | so same GTK 2.24 3.x 4.x & Qt 5.x 6.x
	current_menuitem = widget;
}

static void accels_deselect(GtkWidget *widget) { // ok

	// gtk-can-change-accels for GTK 2.24 | so same GTK 2.24 3.x 4.x & Qt 5.x 6.x
	if (current_menuitem == widget)
		current_menuitem = NULL;
}

static void accels_change(GtkWidget *widget, GdkEventKey *event) { // ok

	if (awf_trace)
		g_printf("» accels_change()\n");

	// gtk-can-change-accels for GTK 2.24 | so same GTK 2.24 3.x 4.x & Qt 5.x 6.x
	// @see https://gitlab.gnome.org/GNOME/gtk/-/commit/2d79334bb069224966b3dcd8456967c9800e8fd0
	if (current_menuitem) {

		GtkMenuItem *menuitem = GTK_MENU_ITEM(current_menuitem);
		gchar *key = gdk_keyval_name(event->keyval);
		const gchar *acl = gtk_menu_item_get_accel_path(menuitem);

		if (
			key &&
			acl &&
			(strcmp(key, "Control_L") != 0) && (strcmp(key, "Control_R") != 0) &&
			(strcmp(key, "Shift_L") != 0) && (strcmp(key, "Shift_R") != 0) &&
			(strcmp(key, "Super_L") != 0) && (strcmp(key, "Super_R") != 0) &&
			(strcmp(key, "Meta_L") != 0) && (strcmp(key, "Meta_R") != 0) &&
			(strcmp(key, "Alt_L") != 0) && (strcmp(key, "Alt_R") != 0)
		) {
			gboolean del = (event->keyval == GDK_KEY_Delete) || (event->keyval == GDK_KEY_KP_Delete) || (event->keyval == GDK_KEY_BackSpace);
			if (
				del ||
				// f1..12
				((event->keyval >= GDK_KEY_F1) && (event->keyval <= GDK_KEY_F12)) ||
				// crtl/shift/super/alt + ?
				(event->state & GDK_CONTROL_MASK) || (event->state & GDK_SHIFT_MASK) ||
				(event->state & GDK_SUPER_MASK) || (event->state & GDK_META_MASK)
			) {
				must_save_accels = TRUE;
				gtk_accel_map_change_entry(
					acl,
					del ? 0 : gdk_keyval_to_lower(event->keyval),
					del ? 0 : event->state & gtk_accelerator_get_default_mod_mask(),
					TRUE);
			}
		}
	}
}

static void accels_save() { // ok

	if (awf_trace)
		g_printf("» accels_save()\n");

	// gtk-can-change-accels for GTK 2.24 | so same GTK 2.24 3.x 4.x & Qt 5.x 6.x
	if (must_save_accels) {
		gchar *path = g_build_filename(g_get_home_dir(), ".awf-accels", NULL);
		gtk_accel_map_save(path);
		g_free(path);
	}
}


// dialogs

static void dialog_open() { // ok

	if (awf_trace)
		g_printf("» dialog_open()\n");

	GtkWidget *dialog = gtk_file_chooser_dialog_new(
		"GtkFileChooserDialog:Open",
		GTK_WINDOW(window),
		GTK_FILE_CHOOSER_ACTION_OPEN,
		"gtk-cancel",
		GTK_RESPONSE_CANCEL,
		"gtk-open",
		GTK_RESPONSE_ACCEPT,
		NULL);

	gtk_file_chooser_set_select_multiple(GTK_FILE_CHOOSER(dialog), TRUE);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}

static void dialog_recent() { // ok

	if (awf_trace)
		g_printf("» dialog_recent()\n");

	GtkWidget *dialog = gtk_recent_chooser_dialog_new(
		"GtkRecentChooserDialog",
		GTK_WINDOW(window),
		"gtk-cancel",
		GTK_RESPONSE_CANCEL,
		"gtk-open",
		GTK_RESPONSE_ACCEPT,
		NULL);

	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}

static void dialog_save() { // ok

	if (awf_trace)
		g_printf("» dialog_save()\n");

	GtkWidget *dialog = gtk_file_chooser_dialog_new(
		"GtkFileChooserDialog:Save",
		GTK_WINDOW(window),
		GTK_FILE_CHOOSER_ACTION_SAVE,
		"gtk-cancel",
		GTK_RESPONSE_CANCEL,
		"gtk-save",
		GTK_RESPONSE_ACCEPT,
		NULL);

	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}

static void dialog_message() { // ok

	if (awf_trace)
		g_printf("» dialog_message()\n");

	GtkWidget *dialog = gtk_message_dialog_new(
		GTK_WINDOW(window),
		GTK_DIALOG_DESTROY_WITH_PARENT,
		GTK_MESSAGE_INFO,
		GTK_BUTTONS_YES_NO,
		"GtkMessageDialog");

	gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(dialog), _app("A widget factory is a theme preview application for GTK and Qt. It displays the various widget types in a single window allowing to see the visual effect of the applied theme."));

	gtk_window_set_title(GTK_WINDOW(dialog), "GtkMessageDialog");
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}

static void dialog_page_setup() { // ok

	if (awf_trace)
		g_printf("» dialog_page_setup()\n");

	//GtkWidget *dialog = gtk_page_setup_unix_dialog_new("GtkPageSetupUnixDialog", GTK_WINDOW(window));
	//gtk_dialog_run(GTK_DIALOG(dialog));
	//gtk_widget_destroy(dialog);

	GtkPageSetup *setup = gtk_print_run_page_setup_dialog(GTK_WINDOW(window), NULL, NULL);
	g_object_unref(setup);
}

static void dialog_print() { // ok

	if (awf_trace)
		g_printf("» dialog_print()\n");

	//GtkWidget *dialog = gtk_print_unix_dialog_new("GtkPrintUnixDialog", GTK_WINDOW(window));
	//gtk_dialog_run(GTK_DIALOG(dialog));
	//gtk_widget_destroy(dialog);

	GtkPrintOperation *op = gtk_print_operation_new();
	gtk_print_operation_run(op, GTK_PRINT_OPERATION_ACTION_PRINT_DIALOG, GTK_WINDOW(window), NULL);
	g_object_unref(op);
}

static void dialog_about() { // ok

	if (awf_trace)
		g_printf("» dialog_about()\n");

	GdkPixbuf *pixbuf = NULL;
	#if defined (G_OS_WIN32)
		HICON hIcon = (HICON) LoadImage(GetModuleHandle(NULL), "IDI_ICON1", IMAGE_ICON, 48, 48, LR_DEFAULTSIZE);
		if (hIcon)
			pixbuf = gdk_win32_icon_to_pixbuf_libgtk_only(hIcon);
	#endif

	gchar *c_version;
	#ifdef __STDC_VERSION__
		if      (__STDC_VERSION__ >= 202311L) c_version = "C23";
		else if (__STDC_VERSION__ >= 201710L) c_version = "C17";
		else if (__STDC_VERSION__ >= 201112L) c_version = "C11";
		else if (__STDC_VERSION__ >= 199901L) c_version = "C99";
		else if (__STDC_VERSION__ >= 199409L) c_version = "C95";
		else                                  c_version = "C (unknown)";
	#else
		c_version = "C89/C90";
	#endif

	gchar *t1, *t2, *t3, *t4;
	gtk_show_about_dialog(GTK_WINDOW(window),
		"version", VERSION,
		"comments", t1 = g_strdup_printf("%s\n\n%s\n%s\n\n%s\n%s",
			_app("A widget factory is a theme preview application for GTK and Qt. It displays the various widget types in a single window allowing to see the visual effect of the applied theme."),
			t2 = g_strdup_printf(_app("Remove %s file"), "~/.awf-accels"),
			_app("to reset keyboard shortcuts."),
			t3 = g_strdup_printf(_app("compiled in %s with gtk %d.%d.%d and glib %d.%d.%d and pango %s"),
				c_version,
				GTK_MAJOR_VERSION, GTK_MINOR_VERSION, GTK_MICRO_VERSION,
				GLIB_MAJOR_VERSION, GLIB_MINOR_VERSION, GLIB_MICRO_VERSION,
				PANGO_VERSION_STRING),
			t4 = g_strdup_printf(_app(" started with gtk %d.%d.%d and glib %d.%d.%d and pango %s"),
				gtk_major_version, gtk_minor_version, gtk_micro_version,
				glib_major_version, glib_minor_version, glib_micro_version,
				pango_version_string())
		),
		"website", "https://github.com/luigifab/awf-extended",
		"copyright", "Copyright © 2020-2026 Fabrice Creuzot (luigifab)\nCopyright © 2011-2017 Valère Monseur (valr)",
		"icon-name", pixbuf ? NULL : GETTEXT_PACKAGE,
		"logo-icon-name", pixbuf ? NULL : GETTEXT_PACKAGE,
		"logo", pixbuf,
		"license", _app("A widget factory is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version."),
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



static void dialog_calendar() {

	if (awf_trace)
		g_printf("» dialog_calendar()\n");

	GtkWidget *dialog, *infobar, *label, *calendar, *area, *btn, *vbox = BOXV;
	dialog = gtk_dialog_new_with_buttons(NULL, GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, NULL, NULL);

	// info bars and calendar
	infobar = gtk_info_bar_new_with_buttons("gtk-ok", GTK_RESPONSE_OK, NULL);
	gtk_info_bar_set_message_type(GTK_INFO_BAR(infobar), GTK_MESSAGE_INFO);
	label = gtk_label_new(_app("This is an info bar."));
	add_to(infobar, label, FALSE, FALSE, 0, 0);
	add_to(vbox, infobar, FALSE, FALSE, 0, 0);

	infobar = gtk_info_bar_new_with_buttons(_app("Ok"), GTK_RESPONSE_OK, NULL);
	gtk_info_bar_set_message_type(GTK_INFO_BAR(infobar), GTK_MESSAGE_QUESTION);
	label = gtk_label_new(_app("This is a question bar."));
	add_to(infobar, label, FALSE, FALSE, 0, 0);
	add_to(vbox, infobar, FALSE, FALSE, 0, 0);

	infobar = gtk_info_bar_new();
	gtk_info_bar_set_message_type(GTK_INFO_BAR(infobar), GTK_MESSAGE_WARNING);
	label = gtk_label_new(_app("This is a warning bar."));
	add_to(infobar, label, FALSE, FALSE, 0, 0);
	add_to(vbox, infobar, FALSE, FALSE, 0, 0);

	infobar = gtk_info_bar_new();
	gtk_info_bar_set_message_type(GTK_INFO_BAR(infobar), GTK_MESSAGE_ERROR);
	label = gtk_label_new(_app("This is an error bar."));
	add_to(infobar, label, FALSE, FALSE, 0, 0);
	add_to(vbox, infobar, FALSE, FALSE, 0, 0);

	calendar = gtk_calendar_new();
	gtk_calendar_set_display_options(GTK_CALENDAR(calendar), GTK_CALENDAR_SHOW_HEADING |
		GTK_CALENDAR_SHOW_DAY_NAMES | GTK_CALENDAR_SHOW_WEEK_NUMBERS);
	add_to(vbox, calendar, FALSE, FALSE, 0, 0);

	// dialog
	gtk_container_set_border_width(GTK_CONTAINER(dialog), 5);
	area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
	add_to(area, vbox, TRUE, TRUE, 5, 5);
	gtk_dialog_add_button(GTK_DIALOG(dialog), "gtk-cancel", GTK_RESPONSE_CANCEL);
	btn = gtk_dialog_add_button(GTK_DIALOG(dialog), "gtk-ok", GTK_RESPONSE_OK);

	gtk_widget_set_name(dialog, "AwfDialogWindow");
	gtk_widget_grab_focus(GTK_WIDGET(btn));
	gtk_window_set_resizable(GTK_WINDOW(dialog), FALSE);
	gtk_widget_set_size_request(dialog, 350, -1);
	gtk_window_set_title(GTK_WINDOW(dialog), "GtkDialog");
	gtk_widget_show_all(dialog);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}

static void dialog_scales() {

	if (awf_trace)
		g_printf("» dialog_scales()\n");

	GtkWidget *dialog, *notebook, *area;
	dialog = gtk_dialog_new_with_buttons(NULL, GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, NULL, NULL);

	notebook = gtk_notebook_new();
	gtk_notebook_set_scrollable(GTK_NOTEBOOK(notebook), FALSE);
	gtk_notebook_set_tab_pos(GTK_NOTEBOOK(notebook), GTK_POS_TOP);
		create_scales(notebook, "Top", GTK_POS_TOP);
		create_scales(notebook, "Right", GTK_POS_RIGHT);
		create_scales(notebook, "Bottom", GTK_POS_BOTTOM);
		create_scales(notebook, "Left", GTK_POS_LEFT);

	area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
	add_to(area, notebook, TRUE, TRUE, 5, 5);

	gtk_dialog_add_button(GTK_DIALOG(dialog), "gtk-cancel", 0);
	gtk_dialog_add_button(GTK_DIALOG(dialog), "gtk-ok", 0);

	gtk_widget_set_name(dialog, "AwfDialogWindow");
	gtk_window_set_resizable(GTK_WINDOW(dialog), FALSE);
	gtk_window_set_title(GTK_WINDOW(dialog), "GtkDialog");
	gtk_widget_show_all(dialog);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}










// yolo