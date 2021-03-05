#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "探花诗台");
    set("long",  
"风云中的老老少少大都有吟诗对词的雅好。只要稍有灵感，就会带着笔墨到这
里来酝酿，等到灵光乍现那霎那，奋笔急书，以求千古名句。诗台正中朱笔入木狂
草：" + YEL" 

                       今日有酒今朝醉，
                       哪管它日剑割头！
                                       阿铁狂舞于酒后失意时。
"NOR
        );
        set("exits", ([ /* sizeof() == 4 */
	      "south" : __DIR__"fengdoor",
		  "up": __DIR__"poemp2",
		]));
        set("objects", ([
        	__DIR__"npc/yaren" : 1,
			__DIR__"npc/prince" : 1,
			__DIR__"npc/sandbag" : 1,
        ]) );
	set("no_death_penalty",1);
	set("no_study",1);
	set("no_fly", 1);
	set("coor/x",-40);
  	set("coor/y",20);
	set("coor/z",0);
	set("map","fywest");
	set("PK_FREE", 1);
	setup();
    call_other( "/obj/board/poem_b", "???" );
}


int valid_leave(object who, string dir){
	
	// Don't die outside.
	if (who->query("kee")< 0 || who->query("sen")<0 || who->query("gin")<0)
		return 0;

	if (dir == "south")
	{
		tell_object(who, HIW"你正离开比武地区，将会有２秒的停滞以清除所有战斗状态。\n\n"NOR);	
		who->remove_all_killer();
		who->perform_busy(1);
	}
	return ::valid_leave();
}