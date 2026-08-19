#include <tgui/tgui.h>
#include <stdio.h>
#include <time.h>

tgui_label_t *label;
tgui_timer_t *timer;

void close_window(void) {
	tgui_quit();
}

void update_label(void) {
	char buf[256];
	time_t t = time(NULL);
	struct tm *tm = localtime(&t);
	strftime(buf, sizeof(buf), "%T", tm);
	tgui_label_set_text(label, buf);
	tgui_timer_reset(timer);
}

int main() {
	if (tgui_init() < 0) {
		puts("fail to init tgui");
		return 1;
	}

	tgui_window_t *window = tgui_window_new("tgui clock", 300, 300);
	tgui_widget_connect_signal(TGUI_WIDGET_CAST(window), "destroy", TCALLBACK_CAST(close_window), NULL);

	label = tgui_label_new("placeholder");
	tgui_widget_set_hexpand(TGUI_WIDGET_CAST(label), TGUI_TRUE);
	tgui_widget_set_vexpand(TGUI_WIDGET_CAST(label), TGUI_TRUE);
	tgui_widget_set_halign(TGUI_WIDGET_CAST(label), TGUI_ALIGN_CENTER);
	tgui_widget_set_valign(TGUI_WIDGET_CAST(label), TGUI_ALIGN_CENTER);
	tgui_window_set_child(window, TGUI_WIDGET_CAST(label));

	timer = tgui_timer_new(1000);
	tgui_timer_connect_signal(timer, "trigger", TCALLBACK_CAST(update_label), NULL);
	update_label();

	tgui_main();
	tgui_fini();
	return 0;
}

