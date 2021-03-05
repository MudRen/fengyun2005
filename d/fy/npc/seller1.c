// annie 07.2003
// dancing_faery@hotmail.com

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	object weapon;
	set_name("卖面的中年人", ({ "carotic wrinkly","wrinkly" }) );
	set("gender", "男性" );
	set("age", 45);
	set("no_curse",1);
	set("no_arrest",1);
	set("no_kill",1);
	set("long",
		" ");
	set("attitude", "friendly");
	setup();
	carry_object("/obj/armor/cloth")->wear();
	weapon=carry_object("/obj/weapon/sword");
	weapon->set_name("挑面的大竹筷", ({ "sticks" }) );
	weapon->set("long"," \n");
	weapon->set("value",0);
	weapon->wield();


        set("combat_exp", 800000);
		set_skill("dodge",500);
		set_skill("parry",500);


        set("attitude", "friendly");
        set("vendor_goods", ([  
                "obj/specials/food/noodle2"					 : 10,
                "obj/specials/food/spiced2"					 : 10,
        ]) );
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}


void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
		
		// 偶不知道这种地方老板素怎样吆喝说>"<

        return;
}


void reset()
{
        set("vendor_goods", ([
                "obj/specials/food/noodle2"					 : 10,
                "obj/specials/food/spiced2"					 : 10,
        ]) );
}



// 凝輕·dancing_faery@hotmail.com

