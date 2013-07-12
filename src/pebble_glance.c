#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"

#include "resource_ids.auto.h"


#define MY_UUID { 0x43, 0xA1, 0xE7, 0x39, 0xC3, 0xE4, 0x4D, 0xBC, 0xAC, 0x9C, 0x00, 0x9A, 0x23, 0x5E, 0x76, 0x33 }
PBL_APP_INFO(MY_UUID,
             "Glance", "Nuthinking",
             1, 0, /* App version */
             RESOURCE_ID_IMAGE_MENU_ICON,
             APP_INFO_WATCH_FACE);
			 
#define CX 72
#define CY 84
#define W 144
#define H 168
			 
#define NUM_SHAPES 360
			 
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

GPath shapes[NUM_SHAPES];
GPathInfo pathInfos[NUM_SHAPES];
GPoint points[NUM_SHAPES][7];

Window window;

Layer graphicLayer;

HeapBitmap greyTexture;

int day_phase = 0;
unsigned int angle;


PblTm currentTime;

void init_shapes()
{
	for(int i=0; i<NUM_SHAPES; i++){
		GPathInfo info = pathInfos[i];
		GPoint *pts = points[i];
		
		if(i<=90){
			info.num_points = 4;
			pts[0] = GPoint(CX,0);
			pts[1] = GPoint(CX, CY);
			pts[2] = radialPoints[i];
			pts[3] = GPoint(W, 0);
		}else if(i<=180){
			info.num_points = 5;
			pts[0] = GPoint(CX,0);
			pts[1] = GPoint(CX, CY);
			pts[2] = radialPoints[i];
			pts[3] = GPoint(W, H);
			pts[4] = GPoint(W, 0);
		}else if(i<=270){
			info.num_points = 6;
			pts[0] = GPoint(CX,0);
			pts[1] = GPoint(CX, CY);
			pts[2] = radialPoints[i];
			pts[3] = GPoint(0, H);
			pts[4] = GPoint(W, H);
			pts[5] = GPoint(W, 0);
		}else{
			info.num_points = 7;
			pts[0] = GPoint(CX,0);
			pts[1] = GPoint(CX, CY);
			pts[2] = radialPoints[i];
			pts[3] = GPoint(0, 0);
			pts[4] = GPoint(0, H);
			pts[5] = GPoint(W, H);
			pts[6] = GPoint(W, 0);
		}
		info.points = pts;
		gpath_init(&shapes[i], &info);
	}
}

void update_graphic_layer(Layer *me, GContext* ctx)
{
	GPath path = shapes[angle];
	GRect destination = greyTexture.bmp.bounds;
	
	if(day_phase == 0){
		// midnght to 8am - black on grey
		graphics_draw_bitmap_in_rect(ctx, &greyTexture.bmp, destination);
		graphics_context_set_fill_color(ctx, GColorBlack);
		gpath_draw_filled(ctx, &path);
	}else if(day_phase == 1){
		// 8 am to 4pm - white on black
		graphics_context_set_fill_color(ctx, GColorBlack);
		graphics_fill_rect(ctx, destination, 0, GCornerNone);
		
		graphics_context_set_fill_color(ctx, GColorWhite);
		gpath_draw_filled(ctx, &path);
		
	}else{
		// 4pm to midnight - grey on white
		graphics_context_set_fill_color(ctx, GColorBlack);
		gpath_draw_filled(ctx, &path);
		
		graphics_context_set_compositing_mode(ctx, GCompOpOr);
		graphics_draw_bitmap_in_rect(ctx, &greyTexture.bmp, destination);
		
	}
}

// Called once per second
void handle_second_tick(AppContextRef ctx, PebbleTickEvent *t)
{
	get_time(&currentTime);
	
	int hours = currentTime.tm_hour;
	
	if(hours<8){
		day_phase = 0;
	}else if(hours<16){
		day_phase = 1;
	}else{
		day_phase = 2;
	}
	
	angle = (hours % 8)*45; // add minutes
	angle += (currentTime.tm_min*45)/60;

	layer_mark_dirty(&graphicLayer);
}

void handle_init(AppContextRef ctx)
{
	init_shapes();
	
	resource_init_current_app(&APP_RESOURCES);
	heap_bitmap_init(&greyTexture, RESOURCE_ID_GREY_PATTERN);

	window_init(&window, "Glance watch");
	window_stack_push(&window, true /* Animated */);

	window_set_background_color(&window, GColorWhite);

	layer_init(&graphicLayer, GRect(0,0, window.layer.frame.size.w, window.layer.frame.size.h));
	graphicLayer.update_proc = update_graphic_layer;
	layer_add_child(&window.layer, &graphicLayer);

	handle_second_tick(ctx, NULL);
}

void handle_deinit(AppContextRef ctx)
{
  heap_bitmap_deinit(&greyTexture);
}


void pbl_main(void *params) {
  PebbleAppHandlers handlers = {
    .init_handler = &handle_init,
	.deinit_handler = &handle_deinit,
    .tick_info = {
      .tick_handler = &handle_second_tick,
      .tick_units = MINUTE_UNIT
    }
  };
  app_event_loop(params, &handlers);
}
