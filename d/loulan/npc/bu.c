#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
#include <dbase.h>

void create()
{
        set_name("卜公直", ({ "bu gongzhi","bu" }) );
        set("gender", "男性" );
        set("title", "蓝田盗玉");
        set("long","
他发亮的眼睛是凹下去的，颧骨却高高耸起，他的头发黑中带黄，而且有些卷
曲，眼睛却有些发绿。他衣着极是华丽，但短袍束发，耳悬金环，看来却又显
得甚为诡秘，但他面上的笑容，却是和善的。\n"  
                );
        set("attitude", "friendly");
	set("chat_chance_combat",20);
	set("chat_msg_combat",({
		(:perform_action,"unarmed.mukuha":),
              }));
	set("age", 45);
        
        set("combat_exp", 2700000);

        set("chat_chance", 1);
        set("chat_msg", ({
		"卜公直碧眼中闪动诡秘的光芒看着你。\n",
                }) );

        set_skill("unarmed", 200);
        set_skill("enmeiryu", 150);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("move", 200);
        set_skill("ghosty-steps", 100);
        map_skill("dodge", "ghosty-steps");
        map_skill("unarmed", "enmeiryu");
        
        set("vendor_goods", ([
		"/obj/medicine/herb_a1" : 50,
		"/obj/medicine/herb_a2" : 50,
		"/obj/medicine/herb_a3" : 50,
		"/obj/medicine/herb_a4" : 50,
		"/obj/medicine/herb_a5" : 50,
		"/obj/medicine/herb_b1" : 50,
		"/obj/medicine/herb_b2" : 50,
		"/obj/medicine/herb_b3" : 50,
		"/obj/medicine/herb_d09" : 50,
		"/obj/medicine/herb_d1" : 50,
		"/obj/medicine/herb_d10" : 50,
		"/obj/medicine/herb_d11" : 50,
		"/obj/medicine/herb_d12" : 50,
		"/obj/medicine/herb_d2" : 50,
		"/obj/medicine/herb_d19" : 50,
		"/obj/medicine/herb_d20" : 50,
		"/obj/medicine/herb_d21" : 50,
		"/obj/medicine/herb_d22" : 50,
		"/obj/medicine/herb_d29" : 50,
		"/obj/medicine/herb_d30" : 50,
		"/obj/medicine/herb_d3" : 50,
		"/obj/medicine/herb_d31" : 50,
		"/obj/medicine/herb_d32" : 50,
//		"/obj/medicine/herb_r"	: 50,
		
  
	]) );
        
                
        setup();
	carry_object("obj/armor/cloth")->wear();

}

void init()
{	
	object ob;
	::init();
	add_action("do_vendor_list", "list");
}

void reset(){
        set("vendor_goods", ([
		"/obj/medicine/herb_a1" : 50,
		"/obj/medicine/herb_a2" : 50,
		"/obj/medicine/herb_a3" : 50,
		"/obj/medicine/herb_a4" : 50,
		"/obj/medicine/herb_a5" : 50,
		"/obj/medicine/herb_b1" : 50,
		"/obj/medicine/herb_b2" : 50,
		"/obj/medicine/herb_b3" : 50,
		"/obj/medicine/herb_d09" : 50,
		"/obj/medicine/herb_d1" : 50,
		"/obj/medicine/herb_d10" : 50,
		"/obj/medicine/herb_d11" : 50,
		"/obj/medicine/herb_d12" : 50,
		"/obj/medicine/herb_d2" : 50,
		"/obj/medicine/herb_d19" : 50,
		"/obj/medicine/herb_d20" : 50,
		"/obj/medicine/herb_d21" : 50,
		"/obj/medicine/herb_d22" : 50,
		"/obj/medicine/herb_d29" : 50,
		"/obj/medicine/herb_d30" : 50,
		"/obj/medicine/herb_d3" : 50,
		"/obj/medicine/herb_d31" : 50,
		"/obj/medicine/herb_d32" : 50,
//		"/obj/medicine/herb_r"	: 50,
		
  
	]) );
	
}


int legit_buyer(){
	if (this_player()->query("class")!= "knight") {
		ccommand("say 小店只做快活林顾客的生意。");
		return 0;
	}
	return 1;
}