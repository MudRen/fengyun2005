// annie 07.2003
// dancing_faery@hotmail.com

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("老裁缝", ({ "old dressmaker","dressmaker" }) );
	set("gender", "男性" );
	set("title",HIR"风云第一针"NOR);
	set("age", 65);
	set("long",
		"这位老裁缝正笑咪咪地忙著，还不时的擦一擦自己的老花眼。\n");
	set("combat_exp", 2000);
	set("attitude", "friendly");
	setup();
        carry_object("/obj/armor/cloth")->wear();


        set("combat_exp", 150000);
        set("attitude", "friendly");
        set("vendor_goods", ([  
                "obj/generate/common/basic_cloth_male"		  : 30,
                "obj/generate/common/basic_cloth_female"		  : 30,
                "obj/generate/common/basic_boots_male"		  : 30,
                "obj/generate/common/basic_boots_female"		  : 30,
                "obj/generate/common/basic_surcoat_male"		  : 30,
                "obj/generate/common/basic_surcoat_female"		  : 30,
                "obj/generate/common/basic_neck_male"		  : 30,
                "obj/generate/common/basic_neck_female"		  : 30,
                "obj/generate/common/basic_head_male"		  : 30,
                "obj/generate/common/basic_head_female"		  : 30,
                "obj/generate/common/basic_wrists"		  : 30,
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
                "obj/generate/common/basic_cloth_male"		  : 30,
                "obj/generate/common/basic_cloth_female"		  : 30,
                "obj/generate/common/basic_boots_male"		  : 30,
                "obj/generate/common/basic_boots_female"		  : 30,
                "obj/generate/common/basic_surcoat_male"		  : 30,
                "obj/generate/common/basic_surcoat_female"		  : 30,
                "obj/generate/common/basic_neck_male"		  : 30,
                "obj/generate/common/basic_neck_female"		  : 30,
                "obj/generate/common/basic_head_male"		  : 30,
                "obj/generate/common/basic_head_female"		  : 30,
                "obj/generate/common/basic_wrists"		  : 30,
        ]) );
}


// 凝輕·dancing_faery@hotmail.com
