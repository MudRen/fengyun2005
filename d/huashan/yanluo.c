
inherit ROOM;

void create()
{
        set("short", "雁落峰");
        set("long", @LONG
此为华山最高峰，站在峰顶四处观望，只见山峦起伏，苍苍茫茫。传说由于这
里山太高，大雁到这里也飞不过去，必须在这里歇息，故取名雁落峰。峰顶更有金
天宫，大殿全为大片铁瓦，内塑有神像，院前大门边还建有钟鼓楼。
LONG
        );
    set("exits", ([ 
  		"eastdown" : __DIR__"shanlu",
	    "north" : __DIR__"yangtian",
	    "westdown" : __DIR__"shanlu1",
	]));

   	set("fall_down", 0);
    set("outdoors", "huashan");

	set("coor/x",-45);
	set("coor/y",-60);
	set("coor/z",40);
	setup();
}


int girl(object me){
	object yu, fang;
	
/*	if(me->query("marks/方少璧完毕")){
		return 0;
	}*/
	if(!interactive(me) || environment(me) != this_object()) {
		if(yu = present("yu yifei", this_object())) {
			message_vision("$N自语道：“我也该走了。”\n", yu, me);
			message_vision("$N转身快步离去。\n", yu);
			destruct(yu);
		}
		return 0;
	}
	if(!present("yu yifei", this_object()) || present("fang girl", this_object())) {
		return 0;
	}
	fang = new(__DIR__"npc/fang");
	if(objectp(fang)){
		fang->move(this_object());
		fang->set("target", me);
	}
	fang->fall(me);
}

