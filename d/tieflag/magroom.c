#include <room.h>  
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short",MAG "紫室"NOR);
  set("long",@LONG
紫色是代表情人的颜色，而这整间屋子都是用紫缎裹起来的。它的主人更是一
位多情而且美丽的少女，双手轻托香腮，在傍晚的阳光中浑身上下都闪着神秘的光
泽。
LONG
  );
  	set("exits/center" ,__DIR__"shishi");
        set("objects", ([
                __DIR__"npc/maggirl" : 1,
       ]) );
  
	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
 }
 void init()
{
	add_action("do_love","tell");
}
void reset()
{
    ::reset();
 	delete_temp("mark/gived");
}  
int do_love(string arg)
{
	string  obname, things;
	object me;
	object ob;
	object hook;
	me=this_player();
        if(!arg || sscanf(arg, "%s %s", obname, things)!=2 )
                return notify_fail("tell <人> <事>\n");

	if (!(ob=present("mag girl",this_object()))) return 0;   
	if (!arg) return 1;
	if (query_temp("mark/gived")) return 1;
	if(obname == "girl") {
                if(things[0..13] == "天南地北双飞客") {
                        message_vision(MAG "\n$N对$n叹道：太感人了，多情环应归多情人，这个给你。\n", ob, this_player());
                        set_temp("mark/gived",1);
                        hook = new(__DIR__"obj/lovering.c");
                        hook->move(me);
                        return 1;
                }
        }
        return 0;
}