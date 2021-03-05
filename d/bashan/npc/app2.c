// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("落葭飞", ({ "luo jiafei","luo","jiafei" }) );
        set("title",CYN"巴山剑尊"NOR);
        set("nickname",CYN"细剪一夜秋"NOR);
        set("gender", "女性" );

    set("reward_npc", 1);
	set("difficulty",5);

		set("age",47);

        set("long","落葭飞与顾道人虽无名分，情意深切却胜夫妻，江湖中传\n说顾道人的回风拂柳剑倒有七八分真髓得自落葭飞。\n");

	set("chat_chance",6);
	set("chat_msg", ({
		"落葭飞微笑看着顾剪秋，脉脉心意尽于言语之外。\n",
	}) );

            set("inquiry",([
 		"九月初九"  :"action落葭飞柔柔道：九月初九，那是我和剪秋相识的日子．．．\n",
  		"顾云飞"  :"风飞与云飞负有重任在身啊。\n",
 		"顾风飞"  :"风飞与云飞负有重任在身啊。\n",
 		"顾雷飞"  :"疑？你方才来的时候没有见到他们两个？\n",
 		"顾电飞"  :"疑？你方才来的时候没有见到他们两个？\n",
 		"重任"  :"action落葭飞摇了摇头道：不可说，不可说。\n",
            ]) );

        set("combat_exp", 10000000);

		set_temp("busy_immune",2);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: ccommand("perform luoxiang") :),
             }) );


        set_skill("sword", 300);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("windsword", 220);
        set_skill("13-sword", 220);

        map_skill("sword", "windsword");
        map_skill("parry", "windsword");
        map_skill("dodge", "13-sword");

		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(YEL"疏影"NOR, ({ "sword"}) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("暮雨罗裙", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}
