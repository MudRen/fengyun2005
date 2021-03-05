#include <ansi.h>
inherit NPC;

void create()
{
        set_name("发子鬼母", ({ "guimu","发子鬼母","鬼母","ghost" }) );
    	set("long","獠牙裂目的鬼母站立在九个形状各异，面目狰狞的鬼子之间。\n");
        set("gender", "女性" );
        set("age",2200);
    	set("no_arrest",1);

    	set("combat_exp",7000000);  
    	set("attitude", "friendly");
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({

    	}) );
    	setup();    
    	carry_object(__DIR__"obj/ghostcloth")->wear();
}

int is_ghost() { return 1; }

