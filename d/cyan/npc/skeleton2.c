// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int leave();

void create()
{
	object weapon;
        set_name("骷髅士兵", ({ "skeletal soldier","soldier" }) );
        set("gender", "男性" );
		set("class","huashan");

		set("age",355);

        set("long","一具看起来十分骇人的骨骼。\n");

        set("combat_exp", 4000000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
             }) );


		auto_npc_setup("waiter",200,180,0,"/obj/weapon/","fighter_w","dagou-stick1",2);
		setup();

        weapon=carry_object("/obj/weapon/staff");
        weapon->set_name("锈铁戟", ({ "halberd" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("残破军衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();



}


void init(){
	::init();
	add_action("do_look", "look");
}


int do_look(string arg) {
if (!arg)
	return 0;
	if(present(arg,environment()) == this_object()){
	


		write("一具看起来十分骇人的骨骼。
它看起来约三百五十多岁。
它浑身上下所剩的仅仅是骨骼而已。
它身穿残破军衣(Cloth)
  右手提着锈铁戟(Halberd)"NOR"\n");
		return 1;
	}
	return 0;
}