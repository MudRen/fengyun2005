// annie 07.2003
// dancing_faery@hotmail.com

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	object weapon;
	set_name("洛桑尼玛", ({ "old lama","lama" }) );
	set("gender", "男性" );
	set("age", 65);
	set("combat_exp", 2000);
	set("attitude", "friendly");
	setup();

		carry_object("/obj/armor/cloth")->wear();

	weapon=carry_object("/obj/weapon/staff");
	weapon->set_name("转经筒", ({ "ton" }) );
	weapon->set("long"," \n");
	weapon->set("value",0);
	weapon->wield();

        set("combat_exp", 150000);
        set("attitude", "friendly");
        set("vendor_goods", ([  
                "obj/generate/common/adv_cloth_male"		  : 30,
                "obj/generate/common/adv_cloth_female"		  : 30,
                "obj/generate/common/adv_boots_male"		  : 30,
                "obj/generate/common/adv_boots_female"		  : 30,
                "obj/generate/common/adv_surcoat_male"		  : 30,
                "obj/generate/common/adv_surcoat_female"		  : 30,
                "obj/generate/common/adv_neck_male"		  : 30,
                "obj/generate/common/adv_neck_female"		  : 30,
                "obj/generate/common/adv_head_male"		  : 30,
                "obj/generate/common/adv_head_female"		  : 30,
                "obj/generate/common/adv_wrists"		  : 30,
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
                "obj/generate/common/adv_cloth_male"		  : 30,
                "obj/generate/common/adv_cloth_female"		  : 30,
                "obj/generate/common/adv_boots_male"		  : 30,
                "obj/generate/common/adv_boots_female"		  : 30,
                "obj/generate/common/adv_surcoat_male"		  : 30,
                "obj/generate/common/adv_surcoat_female"		  : 30,
                "obj/generate/common/adv_neck_male"		  : 30,
                "obj/generate/common/adv_neck_female"		  : 30,
                "obj/generate/common/adv_head_male"		  : 30,
                "obj/generate/common/adv_head_female"		  : 30,
                "obj/generate/common/adv_wrists"		  : 30,
        ]) );}


// 凝輕·dancing_faery@hotmail.com
