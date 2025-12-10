
// file: main.c
#include <gtk/gtk.h>
#include <glib.h>
#include <stdio.h>
#include <unistd.h>

// Simple state machine for handling menu and MQTT topic entry
typedef enum {
    STATE_MENU = 0,
    STATE_WAIT_MQTT_TOPIC
} AppStateMode;

typedef struct {
    GtkLabel *label;
    AppStateMode mode;
} AppState;

static void show_menu(AppState *app) {
    const char *menu =
        "Select activity:\n"
        "1. Connect via MQTT\n"
        "2. Display CA7 processor\n"
        "3. Display name of app";
    gtk_label_set_text(app->label, menu);
    app->mode = STATE_MENU;
}

// Build configuration text to show when user selects option 2
static const char *build_config_text =
    "Build Configuration:\n"
    "BB_VERSION = \"2.0.0\"\n"
    "BUILD_SYS = \"x86_64-linux\"\n"
    "NATIVELSBSTRING = \"universal\"\n"
    "TARGET_SYS = \"arm-ostl-linux-gnueabi\"\n"
    "MACHINE = \"stm32mp15-disco\"\n"
    "DISTRO = \"openstlinux-weston\"\n"
    "DISTRO_VERSION = \"4.0.19-snapshot-20251202\"\n"
    "TUNE_FEATURES = \"arm vfp cortexa7 neon vfpv4 thumb callconvention-hard\"\n"
    "TARGET_FPU = \"hard\"\n"
    "DISTRO_CODENAME = \"kirkstone\"";

// Callback: triggered when there is input on stdin
static gboolean on_stdin_ready(GIOChannel *source, GIOCondition cond, gpointer user_data) {
    AppState *app = (AppState *)user_data;

    if (cond & (G_IO_HUP | G_IO_ERR)) {
        // Terminal closed or error; stop watching stdin
        gtk_label_set_text(app->label, "stdin closed");
        return FALSE; // stop watching
    }

    gchar *line = NULL;
    gsize len = 0;
    GError *err = NULL;

    GIOStatus st = g_io_channel_read_line(source, &line, &len, NULL, &err);
    if (st == G_IO_STATUS_NORMAL && line) {
        // Trim newline(s)
        gchar *trim = g_strchomp(line);

        if (app->mode == STATE_MENU) {
            if (g_strcmp0(trim, "1") == 0) {
                gtk_label_set_text(app->label, "MQTT selected.\nEnter MQTT topic:");
                app->mode = STATE_WAIT_MQTT_TOPIC;
            } else if (g_strcmp0(trim, "2") == 0) {
                // Show the requested Build Configuration
                gtk_label_set_text(app->label, build_config_text);
                // Optionally return to menu automatically:
                // show_menu(app);
            } else if (g_strcmp0(trim, "3") == 0) {
                gtk_label_set_text(app->label, "App name: connectivity");
                // Optionally return to menu:
                // show_menu(app);
            } else {
                // Invalid selection; re-show the menu
                gtk_label_set_text(app->label,
                    "Invalid selection. Please enter 1, 2, or 3.\n\n"
                    "Select activity:\n"
                    "1. Connect via MQTT\n"
                    "2. Display CA7 processor\n"
                    "3. Display name of app");
                app->mode = STATE_MENU;
            }
        } else if (app->mode == STATE_WAIT_MQTT_TOPIC) {
            // Whatever topic is entered, reply "No such topic" and go back to menu
            gchar *msg = g_strdup_printf("No such topic: %s\n\nReturning to menu...", trim);
            gtk_label_set_text(app->label, msg);
            g_free(msg);
            show_menu(app);
        }
    }

    if (err) {
        g_warning("stdin read error: %s", err->message);
        g_error_free(err);
    }
    g_free(line);
    return TRUE; // keep watching
}

int main(int argc, char **argv) {
    printf("NED_MENU_007\n");
    gtk_init(&argc, &argv);

    // Window & label
    GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(win), "Connectivity App");
    gtk_window_set_default_size(GTK_WINDOW(win), 480, 272);

    GtkWidget *label = gtk_label_new(NULL);
    gtk_container_add(GTK_CONTAINER(win), label);
    g_signal_connect(win, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // App state
    AppState app = { .label = GTK_LABEL(label), .mode = STATE_MENU };
    show_menu(&app);

    // Watch stdin
    GIOChannel *stdin_ch = g_io_channel_unix_new(fileno(stdin));
    // Make stdin non-blocking
    GError *err = NULL;
    g_io_channel_set_flags(stdin_ch, G_IO_FLAG_NONBLOCK, &err);
    if (err) { g_error_free(err); }
    g_io_add_watch(stdin_ch, G_IO_IN | G_IO_HUP | G_IO_ERR, on_stdin_ready, &app);

    gtk_widget_show_all(win);
    gtk_main();

    g_io_channel_unref(stdin_ch);
    return 0;
}


