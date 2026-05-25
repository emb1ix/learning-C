#include <stdlib.h>

int main(void) {
    system("rm -rf ./compiled/calculator");
    system("gcc source/main.c source/window.c source/calculator.c -o compiled/calculator -I/usr/include/gtk-3.0 -I/usr/include/pango-1.0 -I/usr/include/cloudproviders -I/usr/include/cairo -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/glycin-2 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/at-spi-2.0 -I/usr/include/atk-1.0 -I/usr/include/dbus-1.0 -I/usr/lib/dbus-1.0/include -I/usr/include/fribidi -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/gio-unix-2.0 -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include -DWITH_GZFILEOP -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/sysprof-6 -pthread -lgtk-3 -lgdk-3 -lpangocairo-1.0 -lcairo-gobject -lgdk_pixbuf-2.0 -latk-1.0 -lpango-1.0 -lcairo -lharfbuzz -lgio-2.0 -lgobject-2.0 -lglib-2.0 -lz");
    system("./compiled/calculator");
    return 0;
}
