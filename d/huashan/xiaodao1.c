
inherit ROOM;

void create()
{
        set("short", "山间小道");
        set("long", @LONG
路依然在山间谷地盘环而行，只是路随山势渐渐向上，一条小溪伴随在小路的
一侧向东流去，溪水不宽，哗啦啦的水声伴随着虫鸣鸟叫充盈于耳。一棵巨大的银
杏树，长在小溪另一侧，树粗有数合抱，树冠硕大，树叶茂盛，又有古藤如龙似蛇
盘树身。
LONG
        );
    set("exits", ([ 
  		"westdown" : __DIR__"xiaodao",
	    "southeast" : __DIR__"chaoyang",
	]));
	set("resource/water", 1);
	set("liquid/container", "小溪");
	set("liquid/name","小溪水");
	
	set("objects", ([
		__DIR__"npc/yellowbird" : 1,
	]));
	set("item_desc", ([
		"小溪" : "小溪不宽，河水清澈。你可以跃过去。（ｄａｓｈ）。\n",
		"stream" : "小溪不宽，河水清澈。你可以跃过去。（ｄａｓｈ）。\n",
	]));
   
    set("outdoors", "huashan");

	set("coor/x",-7);
	set("coor/y",-50);
	set("coor/z",33);
	setup();
}

void init(){
	add_action("do_dash", "dash");
}

int do_dash(){
	object me, room;
	
	me = this_player();
	message_vision("$N退后两步，猛然加快脚步一个纵身轻盈的越过了小溪。\n", me);
	room = find_object(__DIR__"yinxing");
	if(!objectp(room)){
		room = load_object(__DIR__"yinxing");
	}
	me->move(room);
	message("vision", me->name() + "从小溪的另外一边跃了过来。\n", environment(me), me);
	return 1;
}
