// ashui.c

inherit NPC;

#include <ansi.h>
void create()
{
		set_name("天无水", ({ "tianwu shui","shui" }) );
		set("gender", "男性" );
		set("age", 26);
    	set("title","天宗"+HIR" 铁血刺客"NOR);
		set("long","一个平凡的人，是否也有一个不平凡的故事？\n" );
    	set("chat_chance", 1);
    	set("chat_msg", ({
            "天水嘿然道：天宗还是山流，生存还是死亡？\n",
            }) );
	
		set("combat_exp", 2000000);
		set("attitude", "friendly");
		set("per",100);
		set("str", 40);
		set("force",2000);
		set("max_force",2000);
		set("force_factor",50);
		set_skill("dodge",300);
        set_skill("unarmed",200);
        set_skill("sword",200);
        set_skill("fall-steps",200);
        set_skill("xiaohun-sword",200);
        set_skill("meihua-shou",200);
        set_skill("parry", 200);
        map_skill("parry","xiaohun-sword");
        map_skill("dodge","hawk-steps");
        map_skill("unarmed", "meihua-shou");
        map_skill("sword", "xiaohun-sword");
        setup();
	carry_object("/obj/armor/cloth")->wear();
    carry_object("/obj/weapon/sword")->wield();
}


void die()
{
	object ob;
	
	message_vision("\n$N哼了一声，咬牙切齿道：大哥会替俺报仇的！\n", this_object());
	message_vision("$N说完，化作一缕清风而去。\n", this_object());
	destruct(this_object());
}