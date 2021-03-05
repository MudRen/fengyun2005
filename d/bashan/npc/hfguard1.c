// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("顾雷飞", ({ "gu leifei","gu","leifei" }) );
        set("title",CYN"巴山一剑"NOR);
        set("gender", "男性" );
		set("age",27);
        set("long","顾道人生平最为得意的事就是门下风云雷电四个弟子，\n如今雷电尚在，风云已不知去向何方。\n");

		set("chat_chance",1);
		set("chat_msg", ({
			"顾雷飞抿着唇，从从容容拔剑，剑在空中划过一个曲弧入鞘，竟没有一点寒芒。\n",
			"顾雷飞笑着说：师弟这一招长天落电，纵是谢晓峰也要赞上一个好字！\n",
		}) );
        set("inquiry",([
 		"顾云飞"  :"师父让二师兄去．．．等等，我为什么要告诉你？\n",
 		"顾风飞"  :"师父让大师兄去．．．等等，我为什么要告诉你？\n",
 		"顾道人"  :"我师父乃巴山剑客，打遍天下无敌，就连达摩老祖都要敬他三分。\n",
 		"顾剪秋"  :"我师父乃巴山剑客，打遍天下无敌，就连达摩老祖都要敬他三分。\n",
 		"落葭飞"  :"我师父谁都不怕，只怕师娘，可见还是师娘更胜一筹。\n",
 		"退隐"  :"退隐的意思么，就是封存自己，换个身份，重练新人。\n",
 		"封剑退隐"  :"退隐的意思么，就是封存自己，换个身份，重练新人。\n",
 		"九月初九"  :"action顾雷飞左右四顾无人，悄悄地说：\n九月初九那天，我看见阿水从天上飞过了耶。\n",
 		"阿水"  :"江湖人称「霹雳无敌之豆腐郎君」的师奶杀手阿水你都不知道？\n",
              ]) );

        set("combat_exp", 9500000);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: ccommand("perform luoxiang") :),
             }) );

        set_skill("sword", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("windsword", 175);
        set_skill("13-sword", 150);

        map_skill("sword", "windsword");
        map_skill("parry", "windsword");
        map_skill("dodge", "13-sword");

		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(HIC"狂雷剑"NOR, ({ "thunder sword","sword" }) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("飞雷衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}
