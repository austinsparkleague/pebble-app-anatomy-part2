//This project is meant to give you the basic idea of the anatomy of a pebble app.
//There is more to it for more complicated apps, but this will most of that added complexity
//will be additional functions that do different things within the flow of the app.



//first we are going to include the standard pebble libraries.  If you have ever worked with an arduino project, then this should be
//pretty familiar to you.  If not, just know that we are using this #include statement to import lots of pre made code that we can use
//for our pebble app.
#include <pebble.h>
  
//it is also a C convention to define all or most of your variables at the top.  We can talk about that later, but if you are interested now
//check out this article on "scope" => http://www.tutorialspoint.com/cprogramming/c_scope_rules.htm
Window *my_window;
TextLayer *text_layer;
int some_integer = 0;  
char output_string[200] = "";

static void custom_function(){
  some_integer = 1+2;
}

static void main_window_load(Window *window){

 
  
  custom_function();
  
  snprintf(output_string, sizeof(output_string), "The result is: %d", some_integer);
  
  Layer *window_layer = window_get_root_layer(window);
  text_layer = text_layer_create(GRect(0, 0, 144, 60));
  
  
  text_layer_set_text(text_layer, output_string );
  text_layer_set_text_color(text_layer, GColorBlack);
  
  layer_add_child(window_layer, text_layer_get_layer(text_layer));
  
  

}

static void main_window_unload(){
   text_layer_destroy(text_layer);
}

void handle_init(void) {
  my_window = window_create();
 
  
  window_set_window_handlers(my_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload,
  });
  
  window_stack_push(my_window, true);
}

void handle_deinit(void) {
 window_destroy(my_window);
}


int main(void) {
  handle_init();
  app_event_loop();
  handle_deinit();
}