// waiter.c
inherit SMART_NPC;
inherit F_VENDOR;

void create()
{
	set_name("大食堂跑堂", ({ "waiter" }) );
	set("gender", "男性" );
	set("age", 42);
	set("long","这位大食堂跑堂正皮笑肉不笑地看着你，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("attitude", "friendly");
	
	set("combat_exp", 1500000);
    set("attitude", "friendly");
    set("class","bat");
                
    set_skill("unarmed", 150);
    set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("blade",150);
	set_skill("bat-blade",140);
	set_skill("meng-steps",150);
	set_skill("move",200);
	set_skill("blade",150);
	set_skill("luoriquan",150);
	
	map_skill("dodge","meng-steps");
	map_skill("move","meng-steps");
	map_skill("blade","bat-blade");
	map_skill("parry","bat-blade");
	map_skill("unarmed","luoriquan");
	
		set("perform_busy_d", "bat/dodge/meng-steps/huanyinqianchong");
		set("perform_weapon_attack","bat/blade/bat-blade/shiwanshenmo");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(30) :),
        }) );

	set("rank_info/respect", "大师傅");
	set("vendor_goods", ([
		__DIR__"obj/wineskin" : 10,
		__DIR__"obj/dumpling" : 30,
		__DIR__"obj/chicken_leg" : 40,
	]) );
	setup();
	
	carry_object("/obj/armor/cloth")->wear();
    carry_object("/obj/weapon/blade")->wield();
}

void init()
{	
	object ob;
	::init();
	add_action("do_vendor_list", "list");
}
