#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "洞道");

	set("long", @LONG
在悬崖峭壁上竟然有这么一条深邃而不见底的洞道，石壁上虽然已经爬满了蔓
藤，但也明显看得出斧凿的痕迹，洞道曲折晦暗，而地势愈来愈开阔平坦，人行其
中，一开始还得匍匐爬行，到得后来，却已是方圆数丈距离。
LONG);

	set("indoors","wolfmount");
	set("exits",([
        "out":__DIR__"cliffroad3",
	]) );
	setup();
}

void init(){
    int i;
    
    string *rooms = ({"chiyoudao0", "chiyoudao1", "chiyoudao2", "chiyoudao3",
    "chiyoudao4", "chiyoudao5", "chiyoudao6", "chiyoudao7", "chiyoudao8"});
    i = random(9);
    set("exits/south", __DIR__ + rooms[i]);
}

int valid_leave(object ob, string dir){
	if(dir == "south") {
		tell_object(ob, HIY"洞道曲折几个转弯下来，眼前的道路已难辨认。\n\n"NOR);
	}
	return 1;
}
