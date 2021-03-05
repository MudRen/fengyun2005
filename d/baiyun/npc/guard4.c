// XXDER@FY3
inherit SMART_NPC;

void create()
{
    set_name("叶徵" , ({ "swords man","man" }) );
    set("long", "一个白衣飘飘，英气勃发的白云城剑士。。\n");
	set("attitude", "friendly");
    set("age", 19);
        set("gender", "男性" );
        create_family("白云城", 2, "剑士");
    set("combat_exp", 200000);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     }) ); 		

	auto_npc_setup("wang",80,60,1,"/obj/weapon/","fighter_w","feixian-sword",1);
	setup();
    carry_object("/obj/armor/cloth")->wear();
}
