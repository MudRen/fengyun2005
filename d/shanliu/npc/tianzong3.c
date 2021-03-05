// ashui.c

inherit NPC;

#include <ansi.h>
void create()
{
		set_name("天无言", ({ "tianwu yan","yan" }) );
		set("gender", "男性" );
		set("age", 31);
        set("title","天宗"+HIC" 无情刺客"NOR);
		set("long","苍老、憔悴，似乎是上个世纪的人了。\n" );
        set("chat_chance", 1);
        set("chat_msg", ({
            "阿言懒懒道：又要杀人了？\n",
            "阿言嘿嘿冷笑道：谁敢再唧唧歪歪？我一刀剁了他！\n",
            "阿言叹了口气道：杀人于无形，才是至高境界啊！\n",    
        }) );
		set("combat_exp", 2000000);
		set("attitude", "friendly");
	
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
	//command("cry");
	message_vision("\n$N仰天啸道：我竟死于你之手.,我死不瞑目啊!我还会再回来的.\n", this_object());
	message_vision("说完，化作一缕清风而去。\n", this_object());
	//this_object()->move("/d/fy/church");
	//create();
	destruct(this_object());
}