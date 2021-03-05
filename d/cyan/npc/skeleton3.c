// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int leave();

void create()
{
	object weapon;
        set_name("骷髅将军", ({ "skeletal captain","captain" }) );
        set("title",BLU"故人长绝"NOR);
        set("gender", "男性" );
		set("class","huashan");

		set("age",365);

        set("long","一位前朝战功赫赫的将军，如今已是一具尸骨……\n");

        set("combat_exp", 7000000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
             }) );



		setup();

        weapon=carry_object("/obj/weapon/hammer");
        weapon->set_name("锈铜冬瓜锤", ({ "hammer" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("破损战衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

		auto_npc_setup("waiter",200,220,0,"/obj/weapon/","fighter_w","longfenghuan2",3);

}


void init(){
	::init();
	add_action("do_look", "look");
}


int do_look(string arg) {
if (!arg)
	return 0;
	if(present(arg,environment()) == this_object()){
	


		write("一位前朝战功赫赫的将军，如今已是一具尸骨……
它看起来约三百六十多岁。
它浑身上下所剩的仅仅是骨骼而已。
它身穿破损战衣(Cloth)
  右手提着锈铜冬瓜锤(Hammer)"NOR"\n");
		return 1;
	}
	return 0;
}