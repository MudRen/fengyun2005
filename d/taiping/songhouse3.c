#include <ansi.h>
inherit ROOM;

string view(string room_name);

void create()
{
        set("short", "二楼");
        set("long", @LONG
这件屋子没有窗，一扇也没有，和楼下一样，四壁漆黑，只在西壁上，赫然有
半尺正方的一片灰白。那灰白的墙上赫然的画着一只鸟。燕子的剪尾，蜜蜂的毒针，
半边翅蝙蝠，半边翅兀鹰，半边羽毛孔雀，半边羽毛凤凰。这，难道就是传说中的
血奴？
LONG
        );
        set("exits", ([ 
		"down": __DIR__"songhouse",
	]));
        set("objects", ([
        	__DIR__"npc/brick": 1,
        ]));
        
        set("item_desc", ([
		"墙": "灰白的墙上赫然的画着一只鸟。仔细看去，约莫有三寸长短突出在漆黑的墙壁之外。\n",
		"鸟":"灰白的墙上赫然的画着一只鸟。仔细看去，约莫有三寸长短突出在漆黑的墙壁之外。\n",
		"wall":"灰白的墙上赫然的画着一只鸟。仔细看去，约莫有三寸长短突出在漆黑的墙壁之外。\n",
		"bird":"灰白的墙上赫然的画着一只鸟。仔细看去，约莫有三寸长短突出在漆黑的墙壁之外。\n",
		"血奴":"灰白的墙上赫然的画着一只鸟。仔细看去，约莫有三寸长短突出在漆黑的墙壁之外。\n",
	 ]));
	set("brick_out",0);
	set("coor/x",-60);
	set("coor/y",-60);
	set("coor/z",10);
	set("map","taiping");
	setup();
}


void init () {
	add_action("do_pull","pull");
	add_action("do_peep","peep");
}

int do_pull(string arg){
	object me;
	me=this_player();
	if ( arg == "墙" || arg =="wall" || arg =="鸟" || arg =="bird"
		|| arg =="brick" || arg =="砖") {
		message_vision("$N抓着砖摇了摇，竞将它从墙壁之上拔了出来。三寸之后还有甚大的一截，
尽头却是半尺见方一片雪白，散发着清新的白粉气味，显然才刷过白粉不久。\n",me);
		message_vision("那方活壁拔出了之后，漆黑的墙壁之上便开了一个方洞，透着微弱的灯光。
你忍不住想凑过去看上一眼（ｐｅｅｐ）。\n",me);
		set("brick_out",1);
		return 1;
	}
	tell_object(me,"你要拉/拔什么？\n");
	return 1;
}

int do_peep(string arg){
	object me;
	me=this_player();
	if ( !arg || arg == "方洞" || arg =="洞" || arg =="hole") {
		if (!query("brick_out")) {
			tell_object(me,"你想看什么？\n");
			return 1;
		}
		tell_object(me,CYN"原来这儿与鹦鹉楼血奴的屋子是连着的！！！\n"NOR);
		tell_object(me, view(__DIR__"birdhouse2"));
		me->set("marks/parrot/宋妈妈的秘密",1);
		return 1;
	}
	return 0;
}


string view(string room) {
	int i;
	object *inv,env;
	mapping exits;
	string roomdesc, str, *dirs;
	
	env = find_object(room);

	if(!env) env=load_object(room);	
	
	str = "你可以清楚地看到。。。\n\n";
	
	// room descriptions.
	str += sprintf( "%s\n    %s \n    %s",
			env->query("short"),
			env->query("long"),
			env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

	// all things in the room.
	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]->query("no_shown") ) {
			continue;
		}
		str += "  " + inv[i]->short() + "\n";
	}
	return str;
}


void reset()
{

	::reset();
	set("brick_out",0);
	
} 