#include <stdio.h>
#include <gtk/gtk.h>
#include <adwaita.h>

struct Data
{
	GtkWindow *finestra;
};

void set_style_class(GtkWidget *w, char c[])
{
	gtk_widget_add_css_class(w, c);
}

/*
   void calc(GtkWidget *button, gpointer user_data)
   {
   struct Data *d = user_data;
   GtkEntryBuffer *buffer;
   buffer = gtk_entry_get_buffer(GTK_ENTRY(d->entry));
   const char *text = gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(buffer));
   char res[100];
   snprintf(res, sizeof res, "%s = %.2f", text, calcolo(text));
   gtk_label_set_text(GTK_LABEL(d->label), res);
   }
   */

/* void seleziona_file(GtkWidget *button, gpointer user_data)
{
	GtkWidget *dialog;
	GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;

	struct Data *d = user_data;

	dialog = gtk_file_chooser_dialog_new ("Scegli File",
			d->finestra,
			action,
			"Annulla",
			GTK_RESPONSE_CANCEL,
			"Apri",
			GTK_RESPONSE_ACCEPT,
			NULL);

	gtk_widget_show (dialog);
} */

static void activate(GtkApplication* app, gpointer user_data)
{
	GtkBuilder *builder = gtk_builder_new_from_resource("/text-editor/text-editor.ui");

	GtkWidget *finestra = GTK_WIDGET(gtk_builder_get_object(builder, "finestra"));
	// GtkWidget *testo = GTK_WIDGET(gtk_builder_get_object(builder, "testo"));
	// GtkWidget *apri = GTK_WIDGET(gtk_builder_get_object(builder, "open"));
	// GtkWidget *salva = GTK_WIDGET(gtk_builder_get_object(builder, "salva"));
	// GtkTextBuffer *buffertesto = gtk_text_view_get_buffer(GTK_TEXT_VIEW(testo));

	// gtk_text_buffer_set_text(buffertesto, "Inserisci testo", 100);
	// char *t = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(buffertesto),gtk_text_buffer_get_start, gtk_text_buffer_get_end_iter, true);
	gtk_window_set_application(GTK_WINDOW(finestra), app);

	/*
	   struct Data *data;
	   data = g_new0(struct Data, 1);
	   data->entry = input;
	   data->label = result;
	   */

	// g_signal_connect(apri, "clicked", G_CALLBACK(seleziona_file), NULL);

	gtk_widget_show(finestra);
	// g_signal_connect(text_input, "changed", G_CALLBACK(update_entry), label);
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
