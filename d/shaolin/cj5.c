// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
#include <ansi.h>

void create()
{
	object book,corpse;
        set("short", "藏经楼");
        set("long", @LONG
并无柜子，也不见书籍，只有一名老僧，看上去正在坐禅，根据僧
衣颜色，应该便是藏经楼首座--一铁，相传此僧脾气古怪，数十年来未
下藏经楼一步。
LONG
        );
        set("exits", ([ 
  		"up" : __DIR__"cj6",
  		"down": __DIR__"cj4",
	]));
        set("objects", ([
	        __DIR__"obj/slayedyi" : 1,
	        __DIR__"obj/slayedman2" : 2,
       ]) );  
       
	set("coor/x",0);
	set("coor/y",100);
	set("coor/z",60);
	set("no_fly",1);
	set("no_lu_letter",1);
	setup();
	book = new(__DIR__"obj/xisuihe");   
        corpse = present("yitie's corpse", this_object());
        book->move(corpse);
        book = new(__DIR__"obj/xisuihe");   
        corpse = present("corpse", this_object());
        book->move(corpse);
}

/*
int valid_leave(object me,string dir)
{
        object ob;
       	if (me->query_skill("daode",1)>200) return 1; 
	if(userp(me) && dir == "up" && ob=present("master yi",this_object()))
	{
	message_vision("$N对$n道：你怎么可以上楼呢？\n",ob,me);
	return notify_fail("");
	}
	return 1;
}
*/

int valid_leave(object me,string dir)
{
        object ob;
        if (userp(me) && dir == "up" ){
       	if (me->query("combat_exp")<6000000 && !me->query_temp("marks/warn")) {
		me->set_temp("marks/warn",1);
		return notify_fail(HIW"一铁都死了，你这点功夫，上去连收尸的人都没有，千万不要再往上走了。\n"NOR);
	}
	if (me->query("combat_exp")<6000000 && me->query_temp("marks/warn")<2) {
		me->set_temp("marks/warn",2);
		return notify_fail(HIW"你真的要上楼？？\n"NOR);
	}
	}
	return 1;
}


void reset()
{	
	object book, corpse, *inv, next_room;
	int i;
	
	::reset();
	
	inv = all_inventory(this_object());
	
	for(i=0; i<sizeof(inv); i++) {
		if( userp( inv[i]) ) return;
	}
	
	next_room = find_object(__DIR__"cj4");
        if(!objectp(next_room))
	       	next_room = load_object(__DIR__"cj4");
	inv=all_inventory(next_room);
	
	for (i=0;i<sizeof(inv);i++) {
		if (userp(inv[i])) return;
	}       		
	
	
	add("refresh_counter", 1);
	
	if ( (int) query("refresh_counter") > 100 ) {
	        set("objects", ([
		        __DIR__"obj/slayedyi" : 1,
	        	__DIR__"obj/slayedman2" : 2,
       		]) );  

		corpse = present("yitie's corpse", this_object());
		if (!present("xisuihe", corpse) ) {
			book = new(__DIR__"obj/xisuihe");   
        		book->move(corpse);
        	}

        	corpse = present("corpse", this_object());        	
		if (!present("xisuihe", corpse) ) {
			book = new(__DIR__"obj/xisuihe");   
        		book->move(corpse);
        	}
        	set("refresh_counter", 0);
        }
}


