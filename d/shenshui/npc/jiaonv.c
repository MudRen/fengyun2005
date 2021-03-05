// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("鲛女" , ({ "jiao nu"}) );
	set("long", "一个如轻纱般缥缈，如星星般美丽的女子,正在水里畅游。\n");
	set("attitude", "friendly");
	set("age", 14);
  	set("gender", "女性" );
    	set("per", 30);
	set("combat_exp", 50000);
	
	set("inquiry", ([
	]) );

	set("chat_chance", 1);
    	set("chat_msg", ({
	     "鲛女在水里欢快地游来游去。\n",
        }) );
	
    	set_skill("parry", 180);
    	set_skill("charm", 180);
		    	    		
	setup();

}

