// 小小少林寺
//QC by TIE

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "茅屋内");
        set("long", @LONG
这里当中一间屋子倒也甚是宽大。但屋里零零乱乱，百物杂呈，上至书剑琴棋，
下至锅碗杓筷，什么都有，零乱的堆满一屋。少林寺所有殿堂，这里完全都有，只
是非但具体而微，而且简直令人啼笑皆非。左边屋角木架，放着几本书册，但架上
却写着“藏经阁”三字，书架旁堆着几柄刀剑，便算做罗汉堂。当中一张破桌设着
残烛香案，写的是“大雄宝殿”四字，右边屋角小小火炉上，烧着只热气腾腾的锅
子，锅里面香气四溢，自然便算是香积厨了。左面一扇小门，关得严严实实。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"outroom",
]));

        set("item_desc", ([
                "door": "一扇木制的小门，关的严严密密，你很想知道里面到底是什么\n",
		        ]) );
        set("objects",([
                       AREA_TIEFLAG"npc/drinkmonk" : 1,
                       AREA_TIEFLAG"obj/kaolu" : 1,
                      ])  );
           
 
	set("coor/x",90);
	set("coor/y",-90);
	set("coor/z",0);
	setup();

}

void init()
{
   add_action("do_open","open");
}


int do_open(string arg)
{
    object ob;
    if (arg!="door") return notify_fail("你要开什么？\n");
    if(query("exits/south")) return notify_fail("门已经是开的了。");
    if( arg == "door" && ob=present("drink monk", this_object()))
    {
    	message_vision(HIB "那和尚沉声道：洒家这小小少林寺，到处都可走得，但只有这扇门户却是万万碰不得！\n"NOR,this_player());
       	return 1;
	 }
     message_vision("$N将小门打开。\n",this_player());
     set("exits/south",__DIR__"maoroom1");
     call_out("closedoor",4);
     return 1;
}


int closedoor()
{  
    if( !query("exits/south") ) return 1;
    message("vision","小门自己关上了。\n", this_object());
    delete("exits/south");
	return 1;                
}

void reset(){
	object obj;
	::reset();
	if(!present("kaolu", this_object())) {
		obj = new(AREA_TIEFLAG"obj/kaolu");
		obj->move(this_object());
	}
}