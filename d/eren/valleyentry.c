inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "山道");
        set("long", @LONG
群山似在远处，又似在近处，孤寂的山谷，像哀伤的笛韵，流露出人间侧腓的
哀息。山路更见崎岖，乱石丛中几棵野草顽强地伸出头来。一盏青灯制成的孔明灯，
巧妙地嵌在山石间避风处，碧磷磷的看来有如鬼火一般，细看，山石上竟刻着两行
字：入谷如登天，来人走这边。
LONG
);
        set("exits", ([ 
	"southdown" : __DIR__"road2",
	"westup" : __DIR__"road2a",
	]));
        set("objects", ([
        
	]) );
	set("outdoors", "eren");
    set("coor/x",0);
    set("coor/y",10);
    set("coor/z",50);
	set("map","eren");
	setup();
}


void init ()
{

   add_action("do_look", "look");
   add_action("do_northdown", "go");
}

int do_northdown(string arg)
{
   	object me, room;
   	me = this_player();

   	if (arg =="northdown") {
	   	if(me->query_temp("marks/eren/look")) {
	   		tell_object(me, "你沿着小路，向北坡下走去。\n\n");
	   		message("vision", me->name(me)+"沿着蜿蜒的山路转了几转就失去了踪影。\n", environment(me),me );
	   		room = find_object(__DIR__"road3");
	   		if(!objectp(room)) room=load_object(__DIR__"road3");
	      	me->move(room);
	      	me->delete_temp("marks/eren/look");
	      	return 1;
	   	}
	}
   return 0;
}

int do_look(string arg)
{
   object me/*, room*/;
   me = this_player();
   
   if (arg!="rock" && arg!="山石" && arg!="stone" && arg!="字" )
   	return 0;

   tell_object(me,"两行字下，有只箭头，指着条曲折蜿蜒的山路，用尽目力，便可瞧出这条路正是通
向北坡下（northdown）四山合抱的山谷。\n");
   message("vision",me->name(me)+"仔细地看着山石上的字。\n", environment(me),me);
   me->set_temp("marks/eren/look", 1);	
   return 1;
}
