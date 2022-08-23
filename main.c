#include <stdio.h>
#include <gtk/gtk.h>
#include <adwaita.h>

struct Data
{
	GtkWidget *finestra;
};

void set_style_class(GtkWidget *w, char c[])
{
	gtk_widget_add_css_class(w, c);
}

void seleziona_file(GtkWidget *button, gpointer user_data)
{
   struct Data *d = user_data;
	GtkWidget *dialog;
	GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;

	dialog = gtk_file_chooser_dialog_new ("Scegli File",
			GTK_WINDOW(d->finestra),
			action,
			"Annulla",
			GTK_RESPONSE_CANCEL,
			"Apri",
			GTK_RESPONSE_ACCEPT,
			NULL);

	gtk_widget_show (dialog);
}

static void activate(GtkApplication* app, gpointer user_data)
{
	GtkBuilder *builder = gtk_builder_new_from_resource("/text-editor/text-editor.ui");

	GtkWidget *finestra = GTK_WIDGET(gtk_builder_get_object(builder, "finestra"));
	// GtkWidget *testo = GTK_WIDGET(gtk_builder_get_object(builder, "testo"));
	GtkWidget *apri = GTK_WIDGET(gtk_builder_get_object(builder, "open"));
	// GtkWidget *salva = GTK_WIDGET(gtk_builder_get_object(builder, "salva"));
	// GtkTextBuffer *buffertesto = gtk_text_view_get_buffer(GTK_TEXT_VIEW(testo));

	// gtk_text_buffer_set_text(buffertesto, "Inserisci testo", 100);
	gtk_window_set_application(GTK_WINDOW(finestra), app);

	struct Data *data;
	data = g_new0(struct Data, 1);
	data->finestra = finestra;

	g_signal_connect(apri, "clicked", G_CALLBACK(seleziona_file), finestra);

	gtk_widget_show(finestra);
}

int main(int argc, char **argv)
{
	AdwApplication *app;
	int status;

	app = adw_application_new(NULL, G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}
