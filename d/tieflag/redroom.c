#include <room.h>  
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short",HIR "红室"NOR);
  set("long",@LONG
红烛，红地毯，红窗帘，这里处处是红色的，但红的可爱，并不刺眼。墙上刻
着一首诗：
                  昔有佳人公孙氏，一舞剑器动四方，
                  观者如山色沮丧，天地为之久低昂。
                  □如羿射九日落，矫如群帝骖龙翔，
                  来如雷霆收震怒，罢如江海凝清光。
LONG
  );
  	set("exits/center" ,__DIR__"shishi");
    set("objects", ([
                __DIR__"npc/redgirl" : 1,
       ]) );
  
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}
 
void init()
{
	add_action("do_prac","practice");
}

void reset()
{
    ::reset();
 	delete("gived");
}  

int do_prac(string arg)
{
	object me;
	object ob;
	object sword;
	me=this_player();
	if (!(ob=present("red girl",this_object()))) return 0;   
    if (query("gived")) return 0;
    if (!random(20))
    { 
    	set("gived",1);
        tell_object(me,ob->name()+"用崇拜的目光看着你：“哇...练得太棒了”\n");
        tell_object(me,ob->name()+"悄悄塞给你一件东西...\n");
        sword=new(__DIR__"obj/csword");
        sword->move(me);
	return 1;
    }
}	
