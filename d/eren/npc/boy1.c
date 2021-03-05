inherit NPC;
#include <ansi.h>
inherit INQUIRY_MSG;
int give_mission();

void create()
{
        set_name("发呆的小孩", ({ "kid"}) );
        set("gender", "男性");
        set("age", 12);
        set("long",	"一个十二三岁的小孩，呆呆地站着似乎吓呆了。\n"	);
		set("chat_chance", 1);
        set("chat_msg", ({
        }) );
		set("inquiry", ([
	        	"小烟" : (: give_mission :),
	        	"xiaoyan" : (: give_mission :),
	   	]));

		set("combat_exp",10000);
        setup();
		carry_object("/obj/armor/cloth")->wear();
}

int give_mission()	{
	message_vision("$N似乎想说什么，看了看四周，又不作声了。\n",this_object());
	return 1;
	
}	
			