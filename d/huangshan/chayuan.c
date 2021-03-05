#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "黄山茶园");
        set("long", @LONG
半山腰是一个茶园，一片修剪整齐的茶树排列成行，半人多高的茶树上长着新
发的嫩绿叶片，这里终年处在云雾之中，所以大家叫从这个茶园采的茶“云雾茶”。
一条小溪从茶园穿过向东流去，路边是一个供采茶女休息的小亭子。
LONG
        );
  	set("exits", ([ 
 		"eastdown" : __DIR__"renzi",
	]));
	
	set("resource/water", 1);
    set("liquid/container","云雾溪");
    set("liquid/name","云雾溪水");
    set("outdoors", "huangshan");
    set("no_lu_letter",1);
	set("coor/x",-35);
	set("coor/y",-5);
	set("coor/z",20);
	setup();
}

void init(){
	object me;
	me = this_player();
	call_out("girl_come", random(30), me);
}

int girl_come(object me) {
	int i;
	object obj, girl;
	i = NATURE_D->get_season();
	if(!me || environment(me) != this_object()) {
		return 0;
	}
	girl = present("caicha girl", this_object());
	if( i!= 4 && NATURE_D->is_day_time() && !objectp(girl)) {
		message_vision(HIG"一阵悠扬的歌声传过来，采茶女从茶树后转了出来。\n"NOR, me);
		girl = new(__DIR__"npc/tgirl");
		if(objectp(girl)){
			girl->move(this_object());
		}
	}	
	return 1;
}



