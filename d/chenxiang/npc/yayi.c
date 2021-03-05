// garrison.c

#include <ansi.h>

inherit SMART_NPC;

void create()
{
        set_name("沉香衙役", ({ "yayi", "ya" }) );
        set("long",
                "正在上堂的衙役，千万不要惹他们\n");

        set("attitude", "heroism");
	set("vendetta_mark", "authority");
	set("group","officer");       
        set("combat_exp", 5000000);
        
        set("chat_chance", 1);
        set("chat_msg", ({
"沉香衙役低声宣道：威～～～～武～～～～\n"
        }) );

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	
    	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","fumostaff",1);
        setup();
        carry_object(AREA_JINAN"npc/obj/yafu")->wear();
        carry_object(AREA_JINAN"npc/obj/sawei")->wield();
}

