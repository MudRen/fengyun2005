// explorer.c
#include <ansi.h>
inherit SMART_NPC;

void create()
{
        object weapon,armor;
        
        set_name("登山的勇者", ({"mountain climber","climber"}) );
        set("gender", "男性" );
        set("age", 36);

        set("class","beggar");
         set("long",
		"“自古华山一条路”，能在这十八盘上攀登的，自然是具有
强壮身躯的，大多还身怀武功。\n"
		);
        set("combat_exp", 2200000);
        
      	set("chat_chance", 1);
	set("chat_msg", ({
	 	"登山者笑道：“这华山之险，也不过尔尔而已！”\n",
	 	"登山者指着峭壁上的鹰巢说：“戴上护臂，就可以试试上去把小鹰捉下来！”\n",
	}) );
        
		set("chat_chance_combat", 100);
	    set("chat_msg_combat", ({
		     (: auto_smart_fight(40) :),
	     }) ); 		

		auto_npc_setup("wang",150,150,0,"/obj/weapon/","fighter_w","dagou-stick",1);	
	    setup();
	    carry_object(__DIR__"obj/shoe")->wear();
	
	    armor=new("/obj/armor/cloth");
	    armor->set_name(WHT"登山服"NOR,({"cloth"}) );
	    armor->move(this_object());
	    armor->wear(); 
	
	    weapon=new("/obj/weapon/staff");
	    weapon->set_name(WHT"登山杖"NOR,({"staff"}) );
	    weapon->set("value",0);
	    weapon->move(this_object());
	    weapon->wield(); 
	    carry_object(__DIR__"obj/leathersleeves.c")->wear();
}
