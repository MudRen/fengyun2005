#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("麦老广", ({ "mai laoguang", "mai" }) );
        set("nickname","烤鸭王");
        set("long",
"麦老广是吉祥镇的大活宝，几乎没几个人见了他做的烤鸭不掉口水的，
所以即使他浑身都是油，就好像刚在猪油堆里打过滚，也没人在乎。\n");
    	set("chat_chance",2);
		set("chat_msg",	({
			"麦老广道：“我地呢的整日系油里打滚，系命苦得狠！但钱系不怕多，越多就越系好。”\n",
			"麥老廣咧嘴笑道﹕“後面又污糟又系油﹐您都系唔好去哪。”\n", 

		})  );

        set("age", 50);
        set("combat_exp", 1000000);
        set("no_arrest",1);
        
		set_temp("apply/attack",50);
		set_temp("apply/damage",50);
		set_temp("apply/armor", 50);
		set_temp("apply/dodge", 50);
		set_temp("apply/parry",50);
		
		set_skill("unarmed",150);
		set_skill("dodge",150);
		set_skill("parry",150);
		set_skill("changquan",150);
		map_skill("unarmed", "changquan");
        
        set("vendor_goods", ([
				__DIR__"obj/kaoya":10,
                __DIR__"obj/sausage":15,
				__DIR__"obj/tongue":5,
        ]) );
		setup();
        carry_object("/obj/armor/cloth")->wear();
}


void init()
{
	::init();
       add_action("do_vendor_list", "list");
}

void die()
{
	object ob;
	object feng;
//	object *enemy;
	feng = this_object();
	ob = query_temp("last_damage_from");
	
	if(ob)
	if(userp(ob)) {
		if(feng->query("name") == "凤栖梧") {
			ob->set_temp("marks/fugui_killed_feng",1);
		}
		else {
			ob->set_temp("marks/fugui_killed_mai",1);
		}
	}
	::die();
}

void reset ()
{
	set("vendor_goods", ([
			__DIR__"obj/kaoya":10,
            __DIR__"obj/sausage":15,
			__DIR__"obj/tongue":5,
        ]) );
}
