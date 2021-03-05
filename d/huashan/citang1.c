#include <ansi.h>
inherit ROOM;
string tree();
string citang();
void create()
{
        set("short", "祠堂前院");
        set("long", @LONG
绕过断墙是一个祠堂，破烂的院门里，一扇门板碎裂在地，满目残墙断壁。院
中一棵古树上似乎有很多乌鸦的巢穴，不时传来乌鸦“呱呱”的叫声令人烦躁。荒
草没膝，在风中发出萧瑟的声音。院中是一个破烂的祠堂。
LONG
        );
    	set("exits", ([ 
		"west" : __DIR__"hpath2",
		"east" : __DIR__"citang2",
	]));
	set("objects", ([
		__DIR__"obj/huangcao" : 1,
		__DIR__"obj/door" : 1,
	]) );   
	set("item_desc", ([
		"tree" : (: tree :),
		"古树" : (: tree :),
		"树" : (: tree :),
		"祠堂" : (: citang :),
		"citang" : (: citang :),
	]) );
	set("have_spear", 1);
    	set("outdoors", "huashan");
	set("coor/x",-7);
	set("coor/y",15);
	set("coor/z",-10);

	setup();
}

string citang(){
	object me;
	string weather;
	int i;
	i = NATURE_D->get_season();
	me = this_player();
	if(i){
		weather = NATURE_D->get_weather();
	    if((weather == "雨" || weather == "大雨") && query("have_spear")) 
        {
			tell_object(me, "庙墙一角的柱子被雨水泡得有些剥落（ｓｅａｒｃｈ ｃｏｒｎｅｒ）。\n");
			add_action("do_search", "search");
			return "";
		} 
		if (!query("have_spear") && !present("corner", this_object())) {
			tell_object(me, "庙墙一角的柱子已经破开，里面似乎被人拿走了东西。\n");
		} else {
			tell_object(me, "庙墙一角的柱子被雨水泡得有些剥落。\n");
		}
		
	} else {
		tell_object(me, "一个破旧的几於倒塌的祠堂。\n");
	}
	return "";
}

int reset(){
	::reset();
	set("have_spear",1);
}


int do_search(string arg){
	object me, corner, spear;
	me = this_player();
	if(!arg || (arg != "corner" && arg != "角落")){
		return notify_fail("你要搜寻哪里。\n");
	}
	message_vision("$N用手拍拍柱子，“啪”的一声，一片朽木落了下来。\n", me); 
	if (!query("have_spear"))	return 1;		
	tell_object(me, "柱子里似乎有一条黑黝黝的东西。\n"); 
	corner = new(__DIR__"obj/corner");
	spear = new(__DIR__"obj/zhangspear");
	if(objectp(corner)){
		corner->move(this_object());
	}
	if(objectp(spear)){
		spear->move(corner);
	}
	set("have_spear", 0);
	remove_action("do_search","search");
	return 1;
}

string tree(){
	object me;
	int i, j, num = 1+random(10);
	me = this_player();
	i = NATURE_D->get_season();
	message("vision", me->name() + "举头往树上看了看。\n", environment(me), me);
	if(i == 4) {
		tell_object(me, "光秃秃的树干上有几个巨大的鸟窝。\n");
	} else {
		tell_object(me, "枝叶茂密，你很难看到上面的东西。\n");
		j = me->query("kar");
		if(random(j) > 15 && i != 3 && NATURE_D->is_day_time()){
			message_vision(YEL"忽然间一坨鸟粪落下刚好砸到$N的头上。\n"NOR, me);
			if (!me->query("宿命B/华山_鸟粪")) {
				me->set("宿命B/华山_鸟粪", num);
				log_file("riddle/FATE_LOG",
				sprintf("%s(%s) 得到宿命B/华山_鸟粪 "+num+"。 %s \n",
					me->name(1), geteuid(me), ctime(time()) ));
			}
		}
	}		
	return "";
}
