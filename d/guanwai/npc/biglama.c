inherit SMART_NPC;
#include <ansi.h>

void create()
{
	object armor;
	set_name(RED"红教喇嘛"NOR, ({ "red lama"}) );
	set("gender", "男性" );
	set("age", 40+random(10));
	set("int", 30);
	set("long","红教高僧，受葛伦之托特来调查舍利子失踪之事。\n");
	set("class","lama");
        set("combat_exp", 2500000);
        set("score", 900);

	set("class","lama");        
    set("chat_chance", 1);
    set("chat_msg", ({
    	"红教喇嘛肃然说：舍利子一日不归布达拉宫，我们就一日不能安睡！\n",
        (: random_move :),
    }) );
    	
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     }) ); 		

	auto_npc_setup("wang",180,160,0,"/obj/weapon/","fighter_w","kwan-yin-spells",1);
	
	setup();
    armor=new(__DIR__"obj/redclothh");
	armor->set_name(RED"镶金滚边红袍"NOR,({"cloth"}) );
	armor->move(this_object());
	armor->wear();
        carry_object(__DIR__"obj/7staff")->wield();
}

