#include <pebble.h>

static Window *window;
static GBitmap *greyTexture;
			 
#define CX 72
#define CY 84
#define W 144
#define H 168
			 
#define DETAIL_BOX_PADDING 10
			 
const GPoint radialPoints[] = {
	{72, 0},
	{73, 0},
	{75, 0},
	{76, 0},
	{78, 0},
	{79, 0},
	{81, 0},
	{82, 0},
	{84, 0},
	{85, 0},
	{87, 0},
	{88, 0},
	{90, 0},
	{91, 0},
	{93, 0},
	{95, 0},
	{96, 0},
	{98, 0},
	{99, 0},
	{101, 0},
	{103, 0},
	{104, 0},
	{106, 0},
	{108, 0},
	{109, 0},
	{111, 0},
	{113, 0},
	{115, 0},
	{117, 0},
	{119, 0},
	{120, 0},
	{122, 0},
	{124, 0},
	{127, 0},
	{129, 0},
	{131, 0},
	{133, 0},
	{135, 0},
	{138, 0},
	{140, 0},
	{142, 0},
	{144, 1},
	{144, 4},
	{144, 7},
	{144, 9},
	{144, 12},
	{144, 14},
	{144, 17},
	{144, 19},
	{144, 21},
	{144, 24},
	{144, 26},
	{144, 28},
	{144, 30},
	{144, 32},
	{144, 34},
	{144, 35},
	{144, 37},
	{144, 39},
	{144, 41},
	{144, 42},
	{144, 44},
	{144, 46},
	{144, 47},
	{144, 49},
	{144, 50},
	{144, 52},
	{144, 53},
	{144, 55},
	{144, 56},
	{144, 58},
	{144, 59},
	{144, 61},
	{144, 62},
	{144, 63},
	{144, 65},
	{144, 66},
	{144, 67},
	{144, 69},
	{144, 70},
	{144, 71},
	{144, 73},
	{144, 74},
	{144, 75},
	{144, 76},
	{144, 78},
	{144, 79},
	{144, 80},
	{144, 81},
	{144, 83},
	{144, 84},
	{144, 85},
	{144, 87},
	{144, 88},
	{144, 89},
	{144, 90},
	{144, 92},
	{144, 93},
	{144, 94},
	{144, 95},
	{144, 97},
	{144, 98},
	{144, 99},
	{144, 101},
	{144, 102},
	{144, 103},
	{144, 105},
	{144, 106},
	{144, 107},
	{144, 109},
	{144, 110},
	{144, 112},
	{144, 113},
	{144, 115},
	{144, 116},
	{144, 118},
	{144, 119},
	{144, 121},
	{144, 122},
	{144, 124},
	{144, 126},
	{144, 127},
	{144, 129},
	{144, 131},
	{144, 133},
	{144, 134},
	{144, 136},
	{144, 138},
	{144, 140},
	{144, 142},
	{144, 144},
	{144, 147},
	{144, 149},
	{144, 151},
	{144, 154},
	{144, 156},
	{144, 159},
	{144, 161},
	{144, 164},
	{144, 167},
	{142, 168},
	{140, 168},
	{138, 168},
	{135, 168},
	{133, 168},
	{131, 168},
	{129, 168},
	{127, 168},
	{124, 168},
	{122, 168},
	{120, 168},
	{119, 168},
	{117, 168},
	{115, 168},
	{113, 168},
	{111, 168},
	{109, 168},
	{108, 168},
	{106, 168},
	{104, 168},
	{103, 168},
	{101, 168},
	{99, 168},
	{98, 168},
	{96, 168},
	{95, 168},
	{93, 168},
	{91, 168},
	{90, 168},
	{88, 168},
	{87, 168},
	{85, 168},
	{84, 168},
	{82, 168},
	{81, 168},
	{79, 168},
	{78, 168},
	{76, 168},
	{75, 168},
	{73, 168},
	{72, 168},
	{71, 168},
	{69, 168},
	{68, 168},
	{66, 168},
	{65, 168},
	{63, 168},
	{62, 168},
	{60, 168},
	{59, 168},
	{57, 168},
	{56, 168},
	{54, 168},
	{53, 168},
	{51, 168},
	{49, 168},
	{48, 168},
	{46, 168},
	{45, 168},
	{43, 168},
	{41, 168},
	{40, 168},
	{38, 168},
	{36, 168},
	{35, 168},
	{33, 168},
	{31, 168},
	{29, 168},
	{27, 168},
	{25, 168},
	{24, 168},
	{22, 168},
	{20, 168},
	{17, 168},
	{15, 168},
	{13, 168},
	{11, 168},
	{9, 168},
	{6, 168},
	{4, 168},
	{2, 168},
	{0, 167},
	{0, 164},
	{0, 161},
	{0, 159},
	{0, 156},
	{0, 154},
	{0, 151},
	{0, 149},
	{0, 147},
	{0, 144},
	{0, 142},
	{0, 140},
	{0, 138},
	{0, 136},
	{0, 134},
	{0, 133},
	{0, 131},
	{0, 129},
	{0, 127},
	{0, 126},
	{0, 124},
	{0, 122},
	{0, 121},
	{0, 119},
	{0, 118},
	{0, 116},
	{0, 115},
	{0, 113},
	{0, 112},
	{0, 110},
	{0, 109},
	{0, 107},
	{0, 106},
	{0, 105},
	{0, 103},
	{0, 102},
	{0, 101},
	{0, 99},
	{0, 98},
	{0, 97},
	{0, 95},
	{0, 94},
	{0, 93},
	{0, 92},
	{0, 90},
	{0, 89},
	{0, 88},
	{0, 87},
	{0, 85},
	{0, 84},
	{0, 83},
	{0, 81},
	{0, 80},
	{0, 79},
	{0, 78},
	{0, 76},
	{0, 75},
	{0, 74},
	{0, 73},
	{0, 71},
	{0, 70},
	{0, 69},
	{0, 67},
	{0, 66},
	{0, 65},
	{0, 63},
	{0, 62},
	{0, 61},
	{0, 59},
	{0, 58},
	{0, 56},
	{0, 55},
	{0, 53},
	{0, 52},
	{0, 50},
	{0, 49},
	{0, 47},
	{0, 46},
	{0, 44},
	{0, 42},
	{0, 41},
	{0, 39},
	{0, 37},
	{0, 35},
	{0, 34},
	{0, 32},
	{0, 30},
	{0, 28},
	{0, 26},
	{0, 24},
	{0, 21},
	{0, 19},
	{0, 17},
	{0, 14},
	{0, 12},
	{0, 9},
	{0, 7},
	{0, 4},
	{0, 1},
	{2, 0},
	{4, 0},
	{6, 0},
	{9, 0},
	{11, 0},
	{13, 0},
	{15, 0},
	{17, 0},
	{20, 0},
	{22, 0},
	{24, 0},
	{25, 0},
	{27, 0},
	{29, 0},
	{31, 0},
	{33, 0},
	{35, 0},
	{36, 0},
	{38, 0},
	{40, 0},
	{41, 0},
	{43, 0},
	{45, 0},
	{46, 0},
	{48, 0},
	{49, 0},
	{51, 0},
	{53, 0},
	{54, 0},
	{56, 0},
	{57, 0},
	{59, 0},
	{60, 0},
	{62, 0},
	{63, 0},
	{65, 0},
	{66, 0},
	{68, 0},
	{69, 0},
	{71, 0}
};

static Layer *graphicLayer;

static Layer *dateLayer;
static TextLayer *dateTextLayer;

static Layer *timeLayer;
static TextLayer *timeTextLayer;

static int day_phase = 0;
static unsigned int angle;

static char time_text[] = "00:00:00";
static char date_text[] = "Sat 16 Jun";

static AppTimer *hideDetailsTimer;
static bool detailsAreVisible = false; 

static GPath* create_path_with_angle(int a)
{
	GPathInfo info;
	if(a<=90){
		info.num_points = 4;
		info.points = (GPoint []) {{CX,0}, {CX, CY}, radialPoints[a], {W, 0}};
	}else if(a<=180){
		info.num_points = 5;
		info.points = (GPoint []) {{CX,0}, {CX, CY}, radialPoints[a], {W, H}, {W, 0}};
	}else if(a<=270){
		info.num_points = 6;
		info.points = (GPoint []) {{CX,0}, {CX, CY}, radialPoints[a], {0, H}, {W, H}, {W, 0}};
	}else{
		info.num_points = 7;
		info.points = (GPoint []) {{CX,0}, {CX, CY}, radialPoints[a], {0, 0}, {0, H}, {W, H}, {W, 0}};
	}
	return (GPath*) gpath_create(&info);
}

static void update_graphic_layer(Layer *me, GContext* ctx)
{
	GPath *path = create_path_with_angle(angle);
	GRect destination = greyTexture->bounds;
	
	if(day_phase == 0){
		// midnght to 8am - black on grey
		graphics_draw_bitmap_in_rect(ctx, greyTexture, destination);
		graphics_context_set_fill_color(ctx, GColorBlack);
		gpath_draw_filled(ctx, path);
	}else if(day_phase == 1){
		// 8 am to 4pm - white on black
		graphics_context_set_fill_color(ctx, GColorBlack);
		graphics_fill_rect(ctx, destination, 0, GCornerNone);
		
		graphics_context_set_fill_color(ctx, GColorWhite);
		gpath_draw_filled(ctx, path);
		
	}else{
		// 4pm to midnight - grey on white
		graphics_context_set_fill_color(ctx, GColorBlack);
		gpath_draw_filled(ctx, path);
		
		graphics_context_set_compositing_mode(ctx, GCompOpOr);
		graphics_draw_bitmap_in_rect(ctx, greyTexture, destination);
		
	}
	gpath_destroy(path);
}

static void update_time_layer(Layer *layer, GContext *ctx) {
    GRect bounds = layer_get_bounds(layer);

    // Draw a black filled rectangle with sharp corners
    graphics_context_set_fill_color(ctx, GColorBlack);
    graphics_fill_rect(ctx, bounds, 0, GCornerNone);
	
    graphics_context_set_fill_color(ctx, GColorWhite);
    graphics_fill_rect(ctx, GRect(1,1,bounds.size.w-2, bounds.size.h-2), 0, GCornerNone);
}

// Called once per second
static void display_time(struct tm *tick_time)
{
	APP_LOG(APP_LOG_LEVEL_DEBUG, "Display time");
	int hours = tick_time->tm_hour;
	
	if(hours<8){
		day_phase = 0;
	}else if(hours<16){
		day_phase = 1;
	}else{
		day_phase = 2;
	}
	
	angle = (hours % 8)*45; // add minutes
	angle += (tick_time->tm_min*45)/60;

	layer_mark_dirty(graphicLayer);
	APP_LOG(APP_LOG_LEVEL_DEBUG, "Layer made dirty");
}

static void update_time_text(struct tm *tick_time)
{
	strftime(time_text, sizeof(time_text), "%T", tick_time);
	text_layer_set_text(timeTextLayer, time_text);
}

static void handle_minute_tick(struct tm *tick_time, TimeUnits units_changed) {
  display_time(tick_time);
}

static void handle_seconds_tick(struct tm *tick_time, TimeUnits units_changed) {
  update_time_text(tick_time);
}

static void window_load(Window *window)
{
	APP_LOG(APP_LOG_LEVEL_DEBUG, "Window loaded");
	
	graphicLayer = layer_create(GRect(0,0, layer_get_frame(window_get_root_layer(window)).size.w, layer_get_frame(window_get_root_layer(window)).size.h));
	layer_set_update_proc(graphicLayer, update_graphic_layer);
	layer_add_child(window_get_root_layer(window), graphicLayer);
	
	timeLayer = layer_create(GRect(26, 168, 92, 26));
    layer_set_update_proc(timeLayer, update_time_layer);
	layer_add_child(window_get_root_layer(window), timeLayer);
	
	timeTextLayer = text_layer_create((GRect) { {0,-6}, {92,30} });
	text_layer_set_font(timeTextLayer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
	text_layer_set_text_alignment(timeTextLayer, GTextAlignmentCenter);
	text_layer_set_background_color(timeTextLayer, GColorClear);
	layer_add_child(timeLayer, text_layer_get_layer(timeTextLayer));
	
	dateLayer = layer_create(GRect(16, -26, 112, 26));
	layer_set_update_proc(dateLayer, update_time_layer);
	layer_add_child(window_get_root_layer(window), dateLayer);
	
	dateTextLayer = text_layer_create((GRect) { {0,-6}, {112,30} });
	text_layer_set_font(dateTextLayer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
	text_layer_set_text_alignment(dateTextLayer, GTextAlignmentCenter);
	text_layer_set_background_color(dateTextLayer, GColorClear);
	layer_add_child(dateLayer, text_layer_get_layer(dateTextLayer));
	
    time_t now = time(NULL);
    struct tm *tick_time = localtime(&now);
    display_time(tick_time);
}

static void window_unload(Window *window)
{
	// destroy objects
	animation_unschedule_all();
	
	layer_destroy(graphicLayer);
	text_layer_destroy(dateTextLayer);
	layer_destroy(dateLayer);
	text_layer_destroy(timeTextLayer);
	layer_destroy(timeLayer);
}

static void show_details()
{
	GRect from_frame = layer_get_frame(timeLayer);
	GRect to_frame = GRect(26, H-DETAIL_BOX_PADDING-26, 92, 26);
	PropertyAnimation *timeAnimation = property_animation_create_layer_frame(timeLayer, &from_frame, &to_frame);
	animation_set_duration((Animation*) timeAnimation, 300);
	animation_set_curve((Animation*) timeAnimation, AnimationCurveEaseOut);
	animation_schedule((Animation*) timeAnimation);
	
	from_frame = layer_get_frame(dateLayer);
	to_frame = GRect(16, DETAIL_BOX_PADDING, 112, 26);
	timeAnimation = property_animation_create_layer_frame(dateLayer, &from_frame, &to_frame);
	animation_set_duration((Animation*) timeAnimation, 300);
	animation_set_curve((Animation*) timeAnimation, AnimationCurveEaseOut);
	animation_schedule((Animation*) timeAnimation);
}

static void details_hidden(struct Animation *animation, bool finished, void *context)
{
	if(finished){
		detailsAreVisible = false;
	}
}


static void hide_details(void *data)
{
	GRect from_frame = layer_get_frame(timeLayer);
	GRect to_frame = GRect(26, 168, 92, 26);
	PropertyAnimation *timeAnimation = property_animation_create_layer_frame(timeLayer, &from_frame, &to_frame);
	animation_set_duration((Animation*) timeAnimation, 500);
	animation_set_curve((Animation*) timeAnimation, AnimationCurveEaseIn);
	animation_schedule((Animation*) timeAnimation);
	
	from_frame = layer_get_frame(dateLayer);
	to_frame = GRect(16, -26, 112, 26);
	timeAnimation = property_animation_create_layer_frame(dateLayer, &from_frame, &to_frame);
	animation_set_duration((Animation*) timeAnimation, 500);
	animation_set_curve((Animation*) timeAnimation, AnimationCurveEaseIn);
	animation_set_handlers((Animation*) timeAnimation, (AnimationHandlers) {
        .stopped = (AnimationStoppedHandler) details_hidden,
      }, NULL);
	animation_schedule((Animation*) timeAnimation);
}

static void accel_tap_handler(AccelAxisType axis, int32_t direction)
{
	APP_LOG(APP_LOG_LEVEL_DEBUG, "Tapped!");
	
	if(detailsAreVisible){
		app_timer_reschedule(hideDetailsTimer, 5000);
	}else{
	    time_t now = time(NULL);
	    struct tm *tick_time = localtime(&now);
	    update_time_text(tick_time);
		
		strftime(date_text, sizeof(date_text), "%a %e %b", tick_time);
		text_layer_set_text(dateTextLayer, date_text);
	
		show_details();
	
		tick_timer_service_subscribe(SECOND_UNIT, handle_seconds_tick);
		hideDetailsTimer = app_timer_register(5000, hide_details, NULL);
		detailsAreVisible = true;
	}
}




static void init(void)
{
	APP_LOG(APP_LOG_LEVEL_DEBUG, "Init");
	//init_shapes();
	APP_LOG(APP_LOG_LEVEL_DEBUG, "Shapes inited");
	
	//resource_init_current_app(&APP_RESOURCES);
	greyTexture = gbitmap_create_with_resource(RESOURCE_ID_GREY_PATTERN);
	
	window = window_create();
	window_set_window_handlers(window, (WindowHandlers) {
		.load = window_load,
		.unload = window_unload,
	});
	APP_LOG(APP_LOG_LEVEL_DEBUG, "Window created: %p", window);
	window_set_background_color(window, GColorWhite);

	const bool animated = true;
	window_stack_push(window, animated);
	
	tick_timer_service_subscribe(MINUTE_UNIT, handle_minute_tick);
	accel_tap_service_subscribe(&accel_tap_handler);
	
	APP_LOG(APP_LOG_LEVEL_DEBUG, "Subscribed to updates");
}

static void deinit(void)
{
	tick_timer_service_unsubscribe();
	accel_tap_service_unsubscribe();
	
	gbitmap_destroy(greyTexture);
	window_destroy(window);
}

int main(void) {
  init();

  APP_LOG(APP_LOG_LEVEL_DEBUG, "Done initializing, pushed window: %p", window);

  app_event_loop();
  deinit();
}

